#include <stdio.h>
#include <stdint.h>

#include "net.h"
#include "sock.h"

int main(int argc, char *argv[])
{
    int soc, acc;
    struct sockaddr_in local, foreign;
    int foreignlen;
    uint8_t buf[1024];
    ssize_t ret;

    if (net_init() != 0) {
        printf("net_init() failure");
        return -1;
    }

    if (net_run() != 0) {
        printf("net_run() failure");
        return -1;
    }

    soc = sock_open(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    local.sin_family = AF_INET;
    sock_bind(soc, (struct sockaddr *)&local, sizeof(local));
    sock_listen(soc, 1);
    foreignlen = sizeof(foreignlen);
    acc = sock_accept(soc, (struct sockaddr *)&foreign, &foreignlen);

    while(1) {
        ret = sock_recv(acc, buf, sizeof(buf));
        if (ret == -1) {
            break;
        }
        if (ret == 0) {
            break;
        }

        if (sock_send(acc, buf, ret) == -1) {
            break;
        }
    }

    sock_close(acc);
    sock_close(soc);

    net_shutdown();
    return 0;
}
