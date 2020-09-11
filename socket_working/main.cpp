#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <cstring>

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
SOCKET createAndConnectSocket (std::string ipAdress, int port)
{
    WSADATA WSAData;
    SOCKET sock;
    SOCKADDR_IN sin;
    WSAStartup(MAKEWORD(2,0), &WSAData);
    sock = socket(AF_INET, SOCK_STREAM, 0);
    sin.sin_addr.s_addr = inet_addr(ipAdress.c_str());
    sin.sin_family = AF_INET;
    sin.sin_port = htons(port);
    connect(sock, (SOCKADDR *)&sin, sizeof(sin));
    return sock;
}
void socketSend(SOCKET sock,std::string message)
{
    std::cout<<message;
    size_t size = message.size() + 1;
    char *buffer = new char[size];
    strncpy(buffer,message.c_str(),size);
    std::cout<<buffer;
    std::cout<<sizeof(buffer);
    send(sock, buffer, message.size() + 1, 0);
}
char transformStringToChar (std::string stringToConvert)
{
    size_t size = stringToConvert.size() + 1;
    char *buffer = new char[size];
    strncpy(buffer,stringToConvert.c_str(),size);
    return *buffer;
}
void clientSocketV3()
{
    char buffer[255];
    std::string commande;
    std::string message;
    SOCKET sock = createAndConnectSocket("127.0.0.1",9100);
    while (commande != "quit")
    {
        //buffer[0] = '\0';
        memset (buffer, 0, sizeof (buffer));
        recv(sock, buffer, sizeof(buffer), 0);
        //std::cout << buffer;
        commande = buffer;
        //send(sock, "Hello world!\r\n", 14, 0);
        strcat(buffer,"\r\n");
        message = buffer;
        socketSend(sock,message);
        //send(sock, buffer, sizeof(buffer), 0);
    }
    closesocket(sock);
    WSACleanup();
}

int main()
{
    //sendSocket();
    //receiveSocket();
    //clientSocketV1();
    //clientSocketV2();
    clientSocketV3();
    return 0;
}

