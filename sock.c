#include "sock.h"


int sock_open(int domain, int type, int protocol)
{
  return 0;
}
int sock_close(int id)
{
  return 0;
}
int sock_bind(int id, const struct sockaddr *addr, int addrlen)
{
  return 0;
}
int sock_listen(int id, int backlog)
{
  return 0;
}
int sock_accept(int id, struct sockaddr *addr, int *addrlen)
{
  return 0;
}
int sock_connect(int id, const struct sockaddr *addr, int addrlen)
{
  return 0;
}
ssize_t sock_recv(int id, void *buf, size_t n)
{
  return 0;
}
ssize_t sock_send(int id, const void *buf, size_t n)
{
  return 0;
}
