#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "net.h"
#include "loopback.h"

int main(int argc, char *argv[])
{
    struct net_device *dev;
    struct sk_buff skb;

    if (net_stack_init() == -1) {
        fprintf(stderr,"net_stack_init() failed\n");
        exit(EXIT_FAILURE);
    }

    dev = loopback_net_init();
    if (!dev) {
        fprintf(stderr, "loopback_net_init() failed\n");
        exit(EXIT_FAILURE);
    }

    skb.proto = 0x0800;

    while (1) {
        netdev_start_xmit(dev, &skb);
        sleep(1);
    }

    unregister_netdev(dev);
    free_netdev(dev);

    return 0;
}
