#ifndef ENNIBOT_WRAPPERS
#define ENNIBOT_WRAPPERS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "discord.h"
#include "log.h"
#include "utils_ennibot.h"
 
void watcher_embed(struct discord *client, const struct discord_message *event);


void enot_embed(struct discord *client, const struct discord_message *event);


void ottomanempire_embed(struct discord *client, const struct discord_message *event);


void qwerty_embed(struct discord *client, const struct discord_message *event);


void soul_embed(struct discord *client, const struct discord_message *event);


void shin_embed(struct discord *client, const struct discord_message *event);


void guncat_embed(struct discord *client, const struct discord_message *event);


void ronald_embed(struct discord *client, const struct discord_message *event);


void kalun_embed(struct discord *client, const struct discord_message *event);


void bee_embed(struct discord *client, const struct discord_message *event);


void rotx_send(struct discord *client, const struct discord_message *event, char *rot, char *message);


void rot_bf(struct discord *client, const struct discord_message *event, char *message);


void pray_wrap(struct discord *client, const struct discord_message *event);


void dice(struct discord *client, const struct discord_message *event, char *ms, char *code);

void send_time(struct discord *client, const struct discord_message *event);

#endif
