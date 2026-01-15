#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "discord.h"
#include "log.h"

void
on_ready(struct discord *client, const struct discord_ready *event){
	log_info("connected to discord through %s#%s!",
			 event->user->username, event->user->discriminator);
}

char **token_parser(char *message, int *args){
	// setting up two passed pointers
	char **tokens = malloc(sizeof(char *) * 50);
	*args = 0;
	// Tokenising with strsep and copying memory to tokens array
	char *p = message; 
	for(int i = 0; (tokens[i] = strdup(strsep(&p, " "))) && i < 50; i++)
		(*args)++;
	return tokens;
}
void free_tokens(char **tokens){
	for(int i = 0; i < 50; i++) free(tokens[i]);
	free(tokens);
}

void on_message_create(struct discord *client, const struct discord_message *event){
	char *message = strdup(event->content);
	int argc;
	char **tokens = token_parser(message, &argc);
	
	
	if (event->author->bot) return;
	
	
	free_tokens(tokens);
}


int main(int argc, char *argv[]){
	const char *config_file;
	if (argc > 1)
		config_file = argv[1];
	else
		config_file = "../config.json";

	ccord_global_init();
	struct discord *client = discord_config_init(config_file);
	assert(NULL != client && "Couldn't initialize client");

	discord_add_intents(client, DISCORD_GATEWAY_MESSAGE_CONTENT);
	log_info("Ennibot starting... waiting for connection...");

	discord_set_on_ready(client, &on_ready);
	discord_set_on_message_create(client, &on_message_create);

	discord_run(client);

	discord_cleanup(client);
	ccord_global_cleanup();

	return 0;
}
