#include <sp.h>
#include <stdio.h>
#include <signal.h>
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

    signal(SIGINT, &on_sigint);
    signal(SIGSEGV, &on_sigint);

    discord_add_intents(client,
        DISCORD_GATEWAY_MESSAGE_CONTENT |
        DISCORD_GATEWAY_DIRECT_MESSAGE_REACTIONS |
        DISCORD_GATEWAY_DIRECT_MESSAGE_TYPING |
        DISCORD_AUDIT_LOG_MESSAGE_DELETE |
        DISCORD_GATEWAY_DIRECT_MESSAGES |
        DISCORD_GATEWAY_GUILD_MESSAGES |
        DISCORD_GATEWAY_GUILD_BANS |
        DISCORD_GATEWAY_GUILD_MESSAGE_REACTIONS |
        DISCORD_GATEWAY_GUILD_INTEGRATIONS |
        DISCORD_GATEWAY_GUILD_MEMBERS |
        DISCORD_GATEWAY_GUILD_PRESENCES |
        DISCORD_GATEWAY_GUILD_WEBHOOKS |
        DISCORD_GATEWAY_GUILD_INVITES |
        DISCORD_GATEWAY_GUILD_SCHEDULED_EVENTS |
        DISCORD_GATEWAY_GUILD_VOICE_STATES);

    discord_set_on_ready(client, &on_ready);
    discord_run(client);

    return 0;
}