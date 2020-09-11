#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

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
    while(1) /* Boucle infinie. Exercice : améliorez ce code. */
    {
        int sinsize = sizeof(csin);
        if((csock = accept(sock, (SOCKADDR *)&csin, &sinsize)) != INVALID_SOCKET)
        {
            send(csock, "Hello world!\r\n", 14, 0);
            closesocket(csock);
        }
    }
    /* On devrait faire closesocket(sock); puis WSACleanup(); mais puisqu'on a entré une boucle infinie ... */
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

void clientSocketV1()
{
    WSADATA WSAData;
    SOCKET sock;
    SOCKET csock;
    SOCKADDR_IN sin;
    char buffer[255];
    WSAStartup(MAKEWORD(2,0), &WSAData);
    sock = socket(AF_INET, SOCK_STREAM, 0);
    sin.sin_addr.s_addr = inet_addr("127.0.0.1");
    sin.sin_family = AF_INET;
    sin.sin_port = htons(9100);
    connect(sock, (SOCKADDR *)&sin, sizeof(sin));
    recv(sock, buffer, sizeof(buffer), 0);
    std::cout << buffer;
    //send(sock, "Hello world!\r\n", 14, 0);
    strcat(buffer,"\r\n");
    send(sock, buffer, 14, 0);
    closesocket(sock);
    WSACleanup();
}
void clientSocketV2()
{
    WSADATA WSAData;
    SOCKET sock;
    SOCKET csock;
    SOCKADDR_IN sin;
    char buffer[255];
    std::string commande;
    WSAStartup(MAKEWORD(2,0), &WSAData);
    sock = socket(AF_INET, SOCK_STREAM, 0);
    sin.sin_addr.s_addr = inet_addr("127.0.0.1");
    sin.sin_family = AF_INET;
    sin.sin_port = htons(9100);
    connect(sock, (SOCKADDR *)&sin, sizeof(sin));
    while (commande != "quit")
    {
        //buffer[0] = '\0';
        memset (buffer, 0, sizeof (buffer));
        recv(sock, buffer, sizeof(buffer), 0);
        std::cout << buffer;
        commande = buffer;
        //send(sock, "Hello world!\r\n", 14, 0);
        strcat(buffer,"\r\n");
        send(sock, buffer, 14, 0);
    }
    closesocket(sock);
    WSACleanup();
}
int main()
{
    //sendSocket();
    //receiveSocket();
    //clientSocketV1();
    clientSocketV2();
    return 0;
}

