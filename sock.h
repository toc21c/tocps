#ifndef SOCK_H_
#define SOCK_H_

#include <stddef.h>
#include <stdint.h>
#include <sys/types.h>

#define PF_INET 2

#define AF_INET PF_INET

#define SOCK_STREAM 1

#define IPPROTO_TCP 0

typedef uint32_t ip_addr_t;

struct sockaddr {
    unsigned short sa_family;
    char sa_data[14];
};

struct sockaddr_in {
    unsigned short sin_family;
    uint16_t sin_port;
    ip_addr_t sin_addr;
};

extern int sock_open(int domain, int type, int protocol);
extern int sock_close(int id);
extern int sock_bind(int id, const struct sockaddr *addr, int addrlen);
extern int sock_listen(int id, int backlog);
extern int sock_accept(int id, struct sockaddr *addr, int *addrlen);
extern int sock_connect(int id, const struct sockaddr *addr, int addrlen);
extern ssize_t sock_recv(int id, void *buf, size_t n);
extern ssize_t sock_send(int id, const void *buf, size_t n);

#endif // SOCK_H_
