#include <stdio.h>
#include <stdlib.h>

#include "net.h"

static struct net_device *dev_base;

struct net_device *
alloc_netdev(void (*setup)(struct net_device *dev))
{
    struct net_device *dev;
    dev = calloc(1, sizeof(dev));
    if (!dev) {
        fprintf(stderr, "%s: calloc() failed.\n", __func__);
        return NULL;
    }

    if (setup) {
        setup(dev);
    }

    return dev;
}

int
register_netdev(struct net_device *dev)
{
    static unsigned int index = 0;

    dev->index = index++;
    snprintf(dev->name, sizeof(dev->name), "toc_net%d", dev->index);
    dev->next = dev_base;
    dev_base = dev;
    fprintf(stderr, "%s: device=%s\n", __func__, dev->name);

    return 0;
}

void
unregister_netdev(struct net_device *dev)
{
    return;
}

void
free_netdev(struct net_device *dev)
{
    if (dev) {
        free(dev);
    }

    return;
}

int
netdev_start_xmit(struct net_device *dev)
{
    if (!dev->ops->ndo_xmit)
        return -1;
    return dev->ops->ndo_xmit(dev);
}

int
netif_rx(struct net_device *dev)
{
    fprintf(stderr, "%s: device=%s\n", __func__, dev->name);
    return 0;
}
