#include <iostream>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib") // Link with ws2_32.lib

int clientMain() {
    WSADATA wsaData;
    SOCKET clientSocket;
    struct sockaddr_in serverAddress;

    // Initialize Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "Failed to initialize Winsock." << std::endl;
        return 1;
    }

    // Create a socket
    if ((clientSocket = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
        std::cerr << "Failed to create socket." << std::endl;
        WSACleanup();
        return 1;
    }

    // Set up the server address
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8888);
    serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1"); // Server IP address

    // Connect to the server
    if (connect(clientSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0) {
        std::cerr << "Failed to connect to server." << std::endl;
        closesocket(clientSocket);
        WSACleanup();
        return 1;
    }

    // Send data to server
    const char* data = "Hello, server!";
    if (send(clientSocket, data, strlen(data), 0) < 0) {
        std::cerr << "Failed to send data to server." << std::endl;
        closesocket(clientSocket);
        WSACleanup();
        return 1;
    }

    // Receive response from server
    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));
    if (recv(clientSocket, buffer, sizeof(buffer), 0) < 0) {
        std::cerr << "Failed to receive data from server." << std::endl;
        closesocket(clientSocket);
        WSACleanup();
        return 1;
    }

    // Print server's response
    std::cout << "Server response: " << buffer << std::endl;

    // Close the socket and cleanup
    closesocket(clientSocket);
    WSACleanup();

    return 0;
}
