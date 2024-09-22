#ifndef SP_H
#define SP_H

#include <stdint.h>
#include <stddef.h>
#include <stdarg.h>
#include <stdbool.h>

#include <concord/log.h>
#include <concord/discord.h>

#include <events/on_ready.h>
#include <events/on_sigint.h>
#include <events/on_application_create.h>





extern struct discord *client;

#endif