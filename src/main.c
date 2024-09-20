#include <sp.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>




struct discord *client = NULL;





int main(void) {
    struct stat st;

    if (stat("config", &st) < 0) {
        printf("SP config directory not found!\n");
        return -1;
    }

    if (stat("config/sp_config.json", &st) < 0) {
        printf("Failed to locate SP config!\n");
        return -1;
    }

    client = discord_config_init("config/sp_config.json");

    if (!client) {
        printf("Failed to initialize discord API config!\n");
        return -1;
    }

    discord_set_on_ready(client, &on_ready);
    discord_run(client);

    return 0;
}