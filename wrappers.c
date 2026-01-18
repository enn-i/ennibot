#include "wrappers.h"


	//template
void sie_template(struct discord *client, const struct discord_message *event){
	//simple_image_embed(client, event, "name", "url", 0x);
}

void watcher_embed(struct discord *client, const struct discord_message *event){
	simple_image_embed(client, event, "wetcher", "https://i.redd.it/mxeffissfhuc1.png", 0x11002d);
}

void enot_embed(struct discord *client, const struct discord_message *event){
	simple_image_embed(client, event, "snot", "https://i.pinimg.com/736x/db/7e/9e/db7e9e8fc59d3b27e642466915fe441c.jpg", 0x00105a);
}

void ottomanempire_embed(struct discord *client, const struct discord_message *event){
	simple_image_embed(client, event, "ottoman", "http://d3d71ba2asa5oz.cloudfront.net/12030238/images/crmw2223be3.jpg", 0xf0feb6);
}

void qwerty_embed(struct discord *client, const struct discord_message *event){
	simple_image_embed(client, event, "denialishere?", "https://historyfacts.com/wp-content/uploads/sites/9/2025/01/FEATURE_HF_Where-did-QWERTY-Layout-come-from.jpg?resize=1024", 0xc9af00);
}

void soul_embed(struct discord *client, const struct discord_message *event){
	simple_image_embed(client, event, "Soul Hunter",
	"https://cdn.magzter.com/1422872401/1678955167/articles/TiHvcgM2b1680084856310/THE-MYSTERY-OF-THE-BIGGEST-BLACK-HOLE-IN-THE-UNIVERSE.jpg", 0x5f26d1);
}

void shin_embed(struct discord *client, const struct discord_message *event){
	simple_image_embed(client, event, "shin", "https://gcdnb.pbrd.co/images/F0gUIYU2gPFz.png", 0x4894ff);
}


void guncat_embed(struct discord *client, const struct discord_message *event){
	simple_image_embed(client, event, "gungungunguncat", "https://gcdnb.pbrd.co/images/5IBCxVDS830e.png?o=1", 0x00ffc4);
}


void ronald_embed(struct discord *client, const struct discord_message *event){
	simple_image_embed(client, event, "ronald", "https://static.wikia.nocookie.net/undertale/images/0/0f/Sans_battle_idle.gif/revision/latest?cb=20181110100333", 0x000000);
}

void kalun_embed(struct discord *client, const struct discord_message *event){
	simple_image_embed(client, event, "kalun", "https://gcdnb.pbrd.co/images/Jnr6dpaRqYpn.png?o=1", 0x0d59cf);
}


void bee_embed(struct discord *client, const struct discord_message *event){
	simple_image_embed(client, event, "bee", "https://gcdnb.pbrd.co/images/s7gl7hrNkKK4.png?o=1", 0xFFC34D);
}
void rotx_send(struct discord *client, const struct discord_message *event, char *rot, char *message){
	int x;
	sscanf(rot, "%d", &x);
	rotx(x, message);
	reply_noping(client, event, message);
}

void rot_bf(struct discord *client, const struct discord_message *event, char *message){
	char *r = malloc(2000);
	if(strlen(message) > 500){
		sprintf(r, "Surpassed 500 character forcerot limit!");
		reply_noping(client, event, r);
		free(r);
		return;
	}
	memset(r, 0, 2000);
	sprintf(r, "```");
	for(int i = 26; i; i--){
		if(strlen(r) + strlen(message) + 10 < 2000)
			sprintf(r + strlen(r), "%2d: %s\r\n", 26-i, message);
		else{
			sprintf(r + strlen(r), "```");
			reply_noping(client, event, r);
			memset(r, 0, 2000);
			sprintf(r + strlen(r), "```");
		}
		rotx(1, message);
	}
	sprintf(r + strlen(r), "```");
	reply_noping(client, event, r);
	free(r);
}

void pray_wrap(struct discord *client, const struct discord_message *event){
	char *s = malloc(16);
	generate_code(s);
	//log_info("pray, %s", s);
	char *r = malloc(32);
	sprintf(r, "`%s`", s);
	reply_noping(client, event, r);
	free(r);
	free(s);
}


void dice(struct discord *client, const struct discord_message *event, char *ms, char *code){
	char rval[32]; // string buffer for return;
	char check[16]; // string to check secret code

	if(ms == NULL || ms[0] != 'd') return;
	long long unsigned int max;
	sscanf(ms, "d%lld", &max);
	if(max == 0){ //the stupid-proof 0 case for dummies
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
	sprintf(rval, "You rolled a %llu!", ulld_rand(max));
	reply_noping(client, event, rval);
}

void send_time(struct discord *client, const struct discord_message *event){
	char rval[32];
	p_time(rval, NULL);
	reply_noping(client, event, rval);
}


