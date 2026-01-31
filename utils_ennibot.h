#ifndef UTILS_ENNIBOT
#define UITLS_ENNIBOT

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <ctype.h>

#include <time.h>
#include <stdint.h>

#include "discord.h"
#include "log.h"
#include "guild.h"

// Token handling
char **token_parser(char *message, int *args);
void free_tokens(char **tokens, int argc);
char *after_arg(char *message, int i, char **argv);


void reply_noping(struct discord *client, const struct discord_message *event, char *s);


void sm_reply_reply_delete(struct discord *client, const struct discord_message *event, char *s);


void rotx(int x, char *string);


void generate_code(char *code);


void get_current_code(char *check);


unsigned long long int ulld_rand(long long unsigned int max);


void d_timestamp(char *c, time_t t, char *mode);

void p_time(char *c, time_t *t);


void bw_detect(char *message, struct discord *client, const struct discord_message *event);


struct discord_user *find_mem(struct discord *client, const struct discord_message *msg, char *username, u64snowflake *uuid);

#endif

