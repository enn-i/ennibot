#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "discord.h"
#include "log.h"
#include "utils_ennibot.h"
#include "wrappers.h"

#define PREFIX "?"

void on_ready(struct discord *client, const struct discord_ready *event){
	log_info("connected to discord through %s#%s!",
			 event->user->username, event->user->discriminator);
}


char parse_embed(struct discord *client, const struct discord_message *event, char *cmd){
	if(!strcmp(cmd, "enot")){
		enot_embed(client, event);
		return 1;
	}
	else if(!strcmp(cmd, "watcher")){
		watcher_embed(client, event);
		return 1;
	}
	else if(!strcmp(cmd, "qwerty")){
		qwerty_embed(client, event);
		return 1;
	}
	else if(!strcmp(cmd, "soulhunter")){
		soul_embed(client, event);
		return 1;
	}
	else if(!strcmp(cmd, "shin")){
		shin_embed(client, event);
		return 1;
	}
	else if(!strcmp(cmd, "ottomanempire")){
		ottomanempire_embed(client, event);
		return 1;
	}
	else if(!strcmp(cmd, "smightyguncat") || !strcmp(cmd, "gunguncat")){
		guncat_embed(client, event);
		return 1;
	}
	else if(!strcmp(cmd, "ronald") ){
		ronald_embed(client, event);
		return 1;
	}
	else if(!strcmp(cmd, "kalun") ){
		kalun_embed(client, event);
		return 1;
	}
	else if(!strcmp(cmd, "bee") ){
		bee_embed(client, event);
		return 1;
	}
	return 0;
}

char parser(struct discord *client, const struct discord_message *event, int argc, char **argv, char *message){
	char *cmd = argv[0] + 1;
	log_info("Start command: %s", message);

	if(!strcmp(cmd, "echo")){
		sm_reply_reply_delete(client, event, after_arg(message, 1, argv));
		return 1;
	}
	else if(!strcmp(cmd, "rotx")){
		rotx_send(client, event, argv[1], after_arg(message, 2, argv));
		return 1;
	}
	else if(!strcmp(cmd, "forcerot")){
		rot_bf(client, event, after_arg(message, 1, argv));
		return 1;
	}
	else if(!strcmp(cmd, "dice")){
		dice(client, event, argv[1], argv[2]);
		return 1;
	}
	else if(!strcmp(cmd, "enni")){
		reply_noping(client, event, "Hi, that's me");
		return 1;
	}
	else if(!strcmp(cmd, "pray")){
		pray_wrap(client, event);
		return 1;
	}
	else if(!strcmp(cmd, "time")){
		send_time(client, event);
		return 1;
	}
	
	if(parse_embed(client, event, cmd)) return 1;
	return 0;
}

void on_message_create(struct discord *client, const struct discord_message *event){
	if (event->author->bot) return;

	char *message = strdup(event->content);
	if(!(strstr(message, PREFIX) == message)) return; // detect prefix
	int argc;
	char **tokens = token_parser(message, &argc);

	
	if(!parser(client, event, argc, tokens, message))
	
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
