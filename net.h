#ifndef NET_H_
#define NET_H_

#define IFNAMSIZ 16

struct net_device {
    struct net_device *next;
    unsigned int index;
    char name[IFNAMSIZ];
    struct net_device_ops *ops;
};

struct net_device_ops {
    /* TODO: sk_buff */
    int (*ndo_xmit)(struct net_device *dev);
};

extern struct net_device *
alloc_netdev(void (*setup)(struct net_device *dev));
extern int
register_netdev(struct net_device *dev);
extern void
unregister_netdev(struct net_device *dev);
extern void
free_netdev(struct net_device *dev);
extern int
netdev_start_xmit(struct net_device *dev);
extern int
netif_rx(struct net_device *dev);

#endif // NET_H_
