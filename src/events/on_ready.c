#include <sp.h>







void on_ready(struct discord *client, const struct discord_ready *event) {
    if (!client || !event) {
        return;
    }

    on_application_create(client, event);
}