#include <iostream>
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <thread>
#include <vector>
#include <sstream>
#pragma comment(lib, "ws2_32.lib") // Para compilar sockets

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

    // Create server socket
    server_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    //Bind
    bind(server_socket, (sockaddr*)&server_address, sizeof(server_address));

    //Listen
    listen(server_socket, SOMAXCONN);

    // Accept
    client_len_address = sizeof(client_address);
    accept(server_socket, (sockaddr*)&client_address, &client_len_address);

    closesocket(server_socket);

    do {
    // Recv
    recv(client_socket, input, sizeof(input),0);

    //Send
    send(client_socket,input,sizeof(input),0);
    } while(true);

    // Pause
    system("puase");
    closesocket(server_socket);
    WSACleanup();
}