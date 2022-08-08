#include <stdio.h>

#include "loopback.h"

static void
loopback_setup(struct net_device *dev)
{
    return;
}

struct net_device *
loopback_net_init(void)
{
    struct net_device *dev;

    /* TODO: alloc net_device */
    if (!dev) {
        fprintf(stderr, "alloc_netdev() failed\n");
        return NULL;
    }

    return dev;
}
