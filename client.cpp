#include <iostream>
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <thread>
#include <vector>
#include <sstream>
#pragma comment(lib, "ws2_32.lib") // Para compilar sockets

using std::cout; using std::endl;

int main() {
    WSAData data;
    WSAStartup(MAKEWORD(2,2), &data);

    char input[1024] = {0};
    char serverIP[10] = "127.0.0.1";
    int port = 5050;
    SOCKET server_socket, client_socket;
    sockaddr_in server_address, client_address;
    int client_len_address = 0;

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    server_address.sin_addr.S_un.S_addr = inet_addr(serverIP);

    // Create client socket
    client_socket = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);

    // Connect
    connect(server_socket, (sockaddr*)&server_address, sizeof(server_address));

    do {
    // Send
    printf("\n");
    std::cout << "Enter something: " << endl;
    std::cin >> input;
    send(server_socket, input, sizeof(input),0);

    // Recv
    recv(server_socket, input, sizeof(input), 0);
    printf(input);
    } while(true);

    closesocket(client_socket);
    WSACleanup();
}