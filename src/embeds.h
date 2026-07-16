#include "utils_ennibot.h"

#ifndef ENNIBOT_EMBEDS
#define ENNIBOT_EMBEDS
 
void simple_image_embed(struct discord *client, const struct discord_message *event, char *title, char *image, int color);

char parse_embed(struct discord *client, const struct discord_message *event, char *cmd);

#endif
