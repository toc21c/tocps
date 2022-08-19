#include <stdio.h>
#include <stdlib.h>

#include "if_ether.h"
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
netdev_start_xmit(struct net_device *dev, struct sk_buff *skb)
{
    if (!dev->ops->ndo_xmit)
        return -1;
    return dev->ops->ndo_xmit(dev, skb);
}

int
netif_rx(struct net_device *dev, struct sk_buff *skb)
{
    fprintf(stderr, "%s: device=%s, type=0x%04x\n", __func__, dev->name, skb->proto);
    return 0;
}

int
net_stack_init(void)
{
    return 0;
}
