#ifndef UTILS_ENNIBOT
#define UITLS_ENNIBOT

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>

#include <time.h>
#include <stdint.h>

#include "discord.h"
#include "log.h"

void reply_noping(struct discord *client, const struct discord_message *event, char *s);


void sm_reply_reply_delete(struct discord *client, const struct discord_message *event, char *s);


void simple_image_embed(struct discord *client, const struct discord_message *event, char *title, char *image, int color);



void rotx(int x, char *string);


void generate_code(char *code);


void get_current_code(char *check);


unsigned long long int ulld_rand(long long unsigned int max);

void p_time(char *c, time_t *t);




#endif

