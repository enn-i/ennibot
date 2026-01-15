#ifndef COMMAND_H
#define COMMAND_H

void reply_noping(struct discord *client, const struct discord_message *event, char *s);


void sm_reply_reply_delete(struct discord *client, const struct discord_message *event, char *s);


void simple_image_embed(struct discord *client, const struct discord_message *event, char *title, char *image, int color);


void watcher_embed(struct discord *client, const struct discord_message *event);


void enot_embed(struct discord *client, const struct discord_message *event);


void rotx(int x, char *string);


void generate_code(char *code);


void get_current_code(char *check)l


unsigned long long int ulld_rand(long long unsigned int max);


void dice(struct discord *client, const struct discord_message *event, long long unsigned int max, char *code);



#endif

