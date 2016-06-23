#include <stdio.h>
#include <iostream>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

using namespace std;
int main(int argc, char *argv[])
{
   int sockfd, newsockfd, portno, clilen, n;
   struct sockaddr_in serv_addr, cli_addr;
   char buffer[256];
   sockfd = socket(AF_INET, SOCK_STREAM, 0);
   if (sockfd < 0) 
        cout <<"ERROR opening socket \n";
   
   serv_addr.sin_family = AF_INET;
   serv_addr.sin_addr.s_addr = INADDR_ANY;
   serv_addr.sin_port = htons(30002);
   if (bind(sockfd, (struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0)
      cout <<"ERROR on binding\n";
   listen(sockfd,5);
   clilen = sizeof(cli_addr);
   newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t*)&clilen);
   if (newsockfd < 0) 
      cout<<"ERROR on accept\n";
   n = read(newsockfd,buffer,255);
   if (n < 0) cout<<"ERROR reading from socket\n";
   printf("Here is the message: %s\n",buffer);
   
   return 0;
}