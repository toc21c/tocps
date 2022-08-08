#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "loopback.h"

int main(int argc, char *argv[])
{
    struct net_device *dev;

    dev = loopback_net_init();
    if (!dev) {
        fprintf(stderr, "loopback_net_init() failed\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}
