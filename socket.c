#include <sys/socket.h>

int main(){
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    
    struct sockaddr_in address = {
        AF_INET,
        htons(9999),
        0
    };
    

    bind(sockfd, )
}