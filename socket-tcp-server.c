#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/un.h>
#include <unistd.h>
#include <arpa/inet.h>
#define MAX 80
#define PORT 8080
#define SA struct sockaddr

typedef struct student{
    int mssv;
    char name[80];
}student;

void sendStruct(int sockfd)
{
    student student;
    recv (sockfd, &student, sizeof(struct student), 0);
    printf("Client\n");
    printf("Name: %s, MSSV: %d\n", student.name, student.mssv);
    student.mssv = 456;
    strcpy(student.name, "Tran Thi B");
    send(sockfd, &student, sizeof(struct student), 0);
    close(sockfd);
}

int main()
{
    int sockfd, connfd, len;
    struct sockaddr_in servaddr, cli;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("socket creation failed...\n");
        exit(0);
    }
    else
        printf("Socket successfully created..\n");
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);
    if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) {
        printf("socket bind failed...\n");
        close(sockfd);
        exit(0);
    }
    else
        printf("Socket successfully binded..\n");
    if ((listen(sockfd, 5)) != 0) {
        printf("Listen failed...\n");
        close(sockfd);
        exit(0);
    }
    else
        printf("Server listening..\n");
    len = sizeof(cli);
    connfd = accept(sockfd, (SA*)&cli, &len);
    if (connfd < 0) {
        printf("server acccept failed...\n");
        close(sockfd);
        exit(0);
    }
    else
        printf("server acccept the client...\n");
    sendStruct(connfd);
    close(sockfd);
}

