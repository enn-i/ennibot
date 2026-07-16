#ifndef ENNIBOT_WRAPPERS
#define ENNIBOT_WRAPPERS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "embeds.h"

#include "discord.h"
#include "log.h"
#include "utils_ennibot.h"


void rotx_send(struct discord *client, const struct discord_message *event, char *rot, char *message);


void see_avatar(struct discord *client, const struct discord_message *event, char **argv);


void print_uuid(struct discord *client, const struct discord_message *event);


void rot_bf(struct discord *client, const struct discord_message *event, char *message);


void pray_wrap(struct discord *client, const struct discord_message *event);


void dice(struct discord *client, const struct discord_message *event, char *ms, char *code);


void send_time(char **args, struct discord *client, const struct discord_message *event);


void express_hex(struct discord *client, const struct discord_message *event, char *num);

void express_unhex(struct discord *client, const struct discord_message *event, char *num);

void express_binary(struct discord *client, const struct discord_message *event, char *num);



#endif
