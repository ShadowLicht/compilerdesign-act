#include <iostream>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib") // Link with ws2_32.lib

int main() {
    WSADATA wsaData;
    SOCKET serverSocket, clientSocket;
    struct sockaddr_in serverAddress, clientAddress;
    int clientAddressSize;

    // Initialize Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "Failed to initialize Winsock." << std::endl;
        return 1;
    }

    // Create a socket
    if ((serverSocket = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
        std::cerr << "Failed to create socket." << std::endl;
        WSACleanup();
        return 1;
    }

    // Set up the server address
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8888);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    // Bind the socket to the server address
    if (bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == SOCKET_ERROR) {
        std::cerr << "Bind failed with error code: " << WSAGetLastError() << std::endl;
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    // Listen for incoming connections
    listen(serverSocket, SOMAXCONN);
    std::cout << "Server listening on port 8888..." << std::endl;

    while (true) {
        // Accept a client connection
        clientAddressSize = sizeof(clientAddress);
        if ((clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddress, &clientAddressSize)) == INVALID_SOCKET) {
            std::cerr << "Accept failed with error code: " << WSAGetLastError() << std::endl;
            closesocket(serverSocket);
            WSACleanup();
            return 1;
        }

        // Receive and send data
        char buffer[1024];
        int bytesRead;

        while (true) {
            // Receive data from client
            memset(buffer, 0, sizeof(buffer));
            bytesRead = recv(clientSocket, buffer, sizeof(buffer), 0);
                if (bytesRead == SOCKET_ERROR) {
                    std::cerr << "Error in receiving data from client: " << WSAGetLastError() << std::endl;
                    break;
                }
                else if (bytesRead == 0) {
                    std::cout << "Client disconnected." << std::endl;
                    break;
                }

            // Print received data
            std::cout << "Received: " << buffer << std::endl;

            // Send a response to client
            const char* response = "Server received the data.";
            send(clientSocket, response, strlen(response), 0);
        }

        // Close the client socket
        closesocket(clientSocket);
    }

    // Close the server socket and cleanup
    closesocket(serverSocket);
    WSACleanup();

    return 0;
}
