#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> //BIBLIOTECA PARA MANIPULAR O SOCKET(SOCKET É UM RECURSO PADRAO DO SISTEMA OPERACIONAL)
//#include <arpa/inet.h> BIBLIOTECA PARA MANIPULAR HTTP EM LINUX
#include <winsock2.h> //BIBLIOTECA HTTP PARA WINDOWS
#include <ws2tcpip.h>

#define PORT 8080

#define BUFFER_LEN 1024

int main()
{

  //1-PASSO A SEGUIR PARA A CRIAÇÂO DO WEBSERVER

   //2-CRIAR VARIAVEIS

   //3-INICIALIZAR VARIAVEIS

   //4-ABRIR O SOCKET

   //5-BIND DO SOCKET COM INTERFACE DE REDE

   //6-RECEBER CONEXÕES EXTERNAS (OUVIR)

   //7-LOOP PARA CONEXÕES

    int server_fd, client_fd;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFFER_LEN] = { 0 };

    const char* html_body =
    "<html>"
    "<head>"
    "<title>webserver C</title>"
    "</head>"
    "<body>"
    "<h1>Hello World!</h1>"
    "<p>this is a page created with C.</p>"
    "</body>"
    "</html>";

    char html_response[BUFFER_LEN];

    snprintf(html_response,sizeof(html_response),
            "HTTP/1.1 200 OK\r\n"
            "Content-Type: text/html\r\n"
            "Content-Length: %d\r\n"
            "\r\n"
            "%s", strlen(html_body),html_body );

    //AFNET PARA IPV4
    //SOCK_STREAM PARA TCP
    //SE O SOCKET RETORNAR 0-> HOUVE ERRO
   if(server_fd = socket(AF_INET,SOCK_STREAM,0) == 0)
   {
       perror("Error trying to create a socket.");
       exit(EXIT_FAILURE);
   }

   int opt = 1;

   //FUNCAO ANTIGA PORTANTO PRECEISA DO PARAMETRO PASSADO EXCLUSIVAMENTE POR PONTEIRO
   setsockopt(server_fd,SOL_SOCKET,SO_REUSEADDR,(const char *)&opt, sizeof(opt));

   address.sin_family = AF_INET;
   address.sin_addr = INADDR_ANY;
   address.sin_port = htons(PORT);


    return 0;
}
