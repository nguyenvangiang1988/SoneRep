
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/un.h>
#include <unistd.h>
#include <netinet/in.h>
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
    student.mssv = 123;
    strcpy(student.name, "Nguyen Van A");
    if( send(sockfd, &student, sizeof(struct student),0) < 0 ) {
        printf("send failed!\n");
    }
    recv (sockfd, &student, sizeof(struct student), 0);
    printf("Server\n");
    printf("Name: %s, MSSV: %d\n", student.name, student.mssv);
    close(sockfd);
}

int main()
{
    int sockfd, connfd;
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
    servaddr.sin_addr.s_addr = inet_addr("192.168.81.135");
    servaddr.sin_port = htons(PORT);
    if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) != 0) {
        printf("connection with the server failed...\n");
        close(sockfd);
        exit(0);
    }
    else
        printf("connected to the server..\n");
    sendStruct(sockfd);
    close(sockfd);
}

