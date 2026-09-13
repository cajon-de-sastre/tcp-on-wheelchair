#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8081

int main() {
  int sock;
  struct sockaddr_in serv_addr;
  char buffer[1024] = {0};
  const char *msg = "Hi!";

  sock = socket(AF_INET, SOCK_STREAM, 0);
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(PORT);
  inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);

  connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
  send(sock, msg, strlen(msg), 0);
  read(sock, buffer, 1024);
  printf("[/] Servr: %s\n", buffer);

  close(sock);
  return 0;
}
