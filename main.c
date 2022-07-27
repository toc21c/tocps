
int main(int argc, char *argv[])
{
    net_run();

    sock_open();
    sock_bind();
    sock_listen();
    sock_accept();

    while (1) {
        sock_recv();
    }

    sock_close();

    net_shutdown();

    return 0;
}
