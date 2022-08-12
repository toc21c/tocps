#include <stdio.h>
#include <stdlib.h>

#include "net.h"
#include "loopback.h"

int main(int argc, char *argv[])
{
    struct net_device *dev;

    dev = loopback_net_init();
    if (!dev) {
        fprintf(stderr, "loopback_net_init() failed\n");
        exit(EXIT_FAILURE);
    }

    netdev_start_xmit(dev);

    unregister_netdev(dev);
    free_netdev(dev);

    return 0;
}
