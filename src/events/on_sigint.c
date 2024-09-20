#include <sp.h>







void on_sigint(int sig_num) {
    (void)sig_num;

    discord_shutdown(client);
}