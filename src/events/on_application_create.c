#include <sp.h>
#include <stdio.h>






void on_application_create(struct discord *client, const struct discord_ready *event) {
    struct discord_guild guild = {0};
    struct discord_ret_guild ret_guild = {
        .sync = &guild
    };

    struct discord_application_commands guild_cmds = {0};
    struct discord_ret_application_commands ret_guild_cmds = {
        .sync = &guild_cmds
    };





    if (!client || !event) {
        return;
    }

    for (int i = 0; i < event->guilds->size; i++) {
        discord_get_guild(client, event->guilds->array[i].id, &ret_guild);
    
        discord_get_guild_application_commands(client, event->application->id, guild.id, &ret_guild_cmds);

        for (int i = 0; i < guild_cmds.size; i++) {
            struct discord_application_command *cmd = (struct discord_application_command *)&guild_cmds.array[i];

            // Clear stale/unused application commands
            discord_delete_guild_application_command(client, event->application->id, guild.id, cmd->id, NULL);
        }
    }
}