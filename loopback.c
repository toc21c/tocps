#include <stdio.h>

#include "net.h"
#include "loopback.h"

static int
loopback_xmit(struct net_device *dev, struct sk_buff *skb)
{
    fprintf(stderr, "%s: device=%s, type=0x%04x\n", __func__, dev->name, skb->proto);
    netif_rx(dev, skb);
    return 0;
}

static struct net_device_ops loopback_ops = {
    .ndo_xmit = loopback_xmit,
};

static void
loopback_setup(struct net_device *dev)
{
    dev->ops = &loopback_ops;
    return;
}

struct net_device *
loopback_net_init(void)
{
    struct net_device *dev;

    dev = alloc_netdev(loopback_setup);
    if (!dev) {
        fprintf(stderr, "%s: alloc_netdev() failed.\n", __func__);
        return NULL;
    }

    if (register_netdev(dev) != 0) {
        fprintf(stderr, "%s: register_netdev() failed.\n", __func__);
        return NULL;
    }

    return dev;
}
