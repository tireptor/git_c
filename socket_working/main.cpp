#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

void sendSocket ()
{
    WSADATA WSAData;
    SOCKET sock;
    SOCKET csock;
    SOCKADDR_IN sin;
    SOCKADDR_IN csin;
    WSAStartup(MAKEWORD(2,0), &WSAData);
    sock = socket(AF_INET, SOCK_STREAM, 0);
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_family = AF_INET;
    sin.sin_port = htons(23);
    bind(sock, (SOCKADDR *)&sin, sizeof(sin));
    listen(sock, 0);
    while(1) /* Boucle infinie. Exercice : am�liorez ce code. */
    {
        int sinsize = sizeof(csin);
        if((csock = accept(sock, (SOCKADDR *)&csin, &sinsize)) != INVALID_SOCKET)
        {
            send(csock, "Hello world!\r\n", 14, 0);
            closesocket(csock);
        }
    }
    /* On devrait faire closesocket(sock); puis WSACleanup(); mais puisqu'on a entr� une boucle infinie ... */
}

void receiveSocket ()
{
    WSADATA WSAData;
    SOCKET sock;
    SOCKADDR_IN sin;
    char buffer[255];
    WSAStartup(MAKEWORD(2,0), &WSAData);
    sock = socket(AF_INET, SOCK_STREAM, 0);
    sin.sin_addr.s_addr = inet_addr("127.0.0.1");
    sin.sin_family = AF_INET;
    sin.sin_port = htons(23);
    connect(sock, (SOCKADDR *)&sin, sizeof(sin));
    recv(sock, buffer, sizeof(buffer), 0);
    closesocket(sock);
    std::cout << buffer;
    WSACleanup();
}

void receiveAndSendSocket()
{
     WSADATA WSAData;
    SOCKET sock;
    SOCKET csock;
    SOCKADDR_IN sin;
    SOCKADDR_IN csin;
    char buffer[255];
    WSAStartup(MAKEWORD(2,0), &WSAData);
    sock = socket(AF_INET, SOCK_STREAM, 0);
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_addr.s_addr = inet_addr("127.0.0.1");
    sin.sin_family = AF_INET;
    sin.sin_port = htons(23);
    bind(sock, (SOCKADDR *)&sin, sizeof(sin));
    listen(sock, 0);
    connect(sock, (SOCKADDR *)&sin, sizeof(sin));
    recv(sock, buffer, sizeof(buffer), 0);
    std::cout << buffer;
    if (buffer == "coucou")
    {
        int sinsize = sizeof(csin);
        send(csock, "Hello world!\r\n", 14, 0);
    }
}

int main()
{
    //sendSocket();
    //receiveSocket();
    receiveAndSendSocket();
    return 0;
}
