#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "discord.h"
#include "log.h"

void
on_ready(struct discord *client, const struct discord_ready *event){
	log_info("Ennibot, connected to discord through %s#%s!",
			 event->user->username, event->user->discriminator);
}

void on_message_create(struct discord *client, const struct discord_message *event){
	if (event->author->bot) return;

}

main(int argc, char *argv[]){
	const char *config_file;
	if (argc > 1)
		config_file = argv[1];
	else
		config_file = "../config.json";

	ccord_global_init();
	struct discord *client = discord_config_init(config_file);
	assert(NULL != client && "Couldn't initialize client");

	discord_add_intents(client, DISCORD_GATEWAY_MESSAGE_CONTENT);

	discord_set_on_ready(client, &on_ready);
	discord_set_on_message_create(client, &on_message_create);
	//discord_set_on_message_update(client, &on_message_update);
	//discord_set_on_message_delete(client, &on_message_delete);
	//discord_set_on_message_reaction_add(client, &on_reaction_add);
	//discord_set_on_message_delete_bulk(client, &on_message_delete_bulk);

	fgetc(stdin); // wait for input

	discord_run(client);

	discord_cleanup(client);
	ccord_global_cleanup();
}
