#include "wrappers.h"



void watcher_embed(struct discord *client, const struct discord_message *event){
	simple_image_embed(client, event, "wetcher", "https://i.redd.it/mxeffissfhuc1.png", 0x11002d);
}

void enot_embed(struct discord *client, const struct discord_message *event){
	simple_image_embed(client, event, "snot", "https://i.pinimg.com/736x/db/7e/9e/db7e9e8fc59d3b27e642466915fe441c.jpg", 0x00105a);
}

void ottomanempire_embed(struct discord *client, const struct discord_message *event){
	simple_image_embed(client, event, "ottoman", "http://d3d71ba2asa5oz.cloudfront.net/12030238/images/crmw2223be3.jpg", 0xf0feb6);
}

void rotx_send(struct discord *client, const struct discord_message *event, char *rot, char *message){
	int x;
	sscanf(rot, "%d", &x);
	rotx(x, message);
	reply_noping(client, event, message);
}


void pray_wrap(struct discord *client, const struct discord_message *event){
	char *s = malloc(16);
	get_current_code(s);
	char *r = malloc(32);
	sprintf(r, "`%s`", s);
	reply_noping(client, event, r);
	free(r);
	free(s);
}


void dice(struct discord *client, const struct discord_message *event, char *ms, char *code){
	char rval[32]; // string buffer for return;
	char check[16]; // string to check secret code

	if(ms == NULL) return;
	long long unsigned int max;
	sscanf(ms, "d%lld", &max);
	if(max == 0){
		reply_noping(client, event, "Qwerty's Easter Egg 0");
		return;
	}
	if(code != NULL){
		get_current_code(check);
		if(!strcmp(check, code)){
			sprintf(rval, "You rolled a %lld", max);
			reply_noping(client, event, rval);
			generate_code(check);
			return;
		}
	}
	sprintf(rval, "You rolled a %lld!", ulld_rand(max));
	reply_noping(client, event, rval);
}



