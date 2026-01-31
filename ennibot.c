#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "discord.h"
#include "log.h"
#include "utils_ennibot.h"
#include "wrappers.h"
#include "embeds.h"

#define PREFIX "?"

void on_ready(struct discord *client, const struct discord_ready *event){
	log_info("connected to discord through %s#%s!",
			 event->user->username, event->user->discriminator);
}


char parser(struct discord *client, const struct discord_message *event, int argc, char **argv, char *message){
	char *cmd = argv[0] + 1;

	if(!strcmp(cmd, "echo"))
		sm_reply_reply_delete(client, event, after_arg(message, 1, argv));
	else if(!strcmp(cmd, "rotx"))
		rotx_send(client, event, argv[1], after_arg(message, 2, argv));
	else if(!strcmp(cmd, "forcerot"))
		rot_bf(client, event, after_arg(message, 1, argv));
	else if(!strcmp(cmd, "dice"))
		dice(client, event, argv[1], argv[2]);
	else if(!strcmp(cmd, "enni"))
		reply_noping(client, event, "Hi, that's me");
	else if(!strcmp(cmd, "pray"))
		pray_wrap(client, event);
	else if(!strcmp(cmd, "time"))
		send_time(argv, client, event);
	else if(!strcmp(cmd, "hex"))
		express_hex(client, event, argv[1]);
	else if(!strcmp(cmd, "unhex"))
		express_unhex(client, event, argv[1]);
	else if(!strcmp(cmd, "binary"))
		express_binary(client, event, argv[1]);
	else if(!strcmp(cmd, "seeuuid"))
		print_uuid(client, event);
	else if(!strcmp(cmd, "avatar"))
		see_avatar(client, event, argv);
	else if(!strcmp(cmd, "insert_new_command_name"))
		;
	else if(parse_embed(client, event, cmd));


	else return 0; // parse fail

	return 1; // parse pass
}

void on_message_create(struct discord *client, const struct discord_message *event){
	if (event->author->bot) return;

	char *message = strdup(event->content);
	if(!(strstr(message, PREFIX) == message)){// detect prefix

		bw_detect(message, client, event);
		return; 	
	}
	int argc;
	char **tokens = token_parser(message, &argc);

	
	if(parser(client, event, argc, tokens, message))
		log_info("Command success: %s", message);
	
	free_tokens(tokens, argc);
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
