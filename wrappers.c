#include "wrappers.h"


	/*template
void sie_template(struct discord *client, const struct discord_message *event){
	simple_image_embed(client, event, "name", "url", 0x);
}
*/

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
	simple_image_embed(client, event, "Soul Hunter", "https://gcdnb.pbrd.co/images/VNGNeMX6nsFl.png?o=1", 0x5f26d1);
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


void luna_embed(struct discord *client, const struct discord_message *event){
	simple_image_embed(client, event, "ruffles!", "https://gcdnb.pbrd.co/images/MoiQzzNE2Tvw.png?o=1", 0x59E0FF);
}


void banana_embed(struct discord *client, const struct discord_message *event){
	simple_image_embed(client, event, "banananananananananex", "https://tenor.com/sIW4gtmtYp6.gif", 0x102f61);
}


void yfs_embed(struct discord *client, const struct discord_message *event){
	simple_image_embed(client, event, "yfs.", "https://gcdnb.pbrd.co/images/9et5VhVs8If3.png?o=1", 0x3e0752);
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

	if(ms == NULL || ms[0] != 'd') return;
	long long unsigned int max;
	sscanf(ms, "d%llu", &max);
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


time_t sec_convert(char *s){ // converts time (<y, M, w, d, h, m, s> + int) to seconds
	if(!strpbrk(s, "0123456789")) return 0;
	char unit; time_t value;
	sscanf(s, "%c%ld", &unit, &value);
	switch(unit){
		case 'y':
			value *= 365*24*60*60; break;
		case 'M':
			value *= 30*24*60*60; break;
		case 'w':
			value *= 7*24*60*60; break;
		case 'd':
			value *= 24*60*60; break;
		case 'h':
			value *= 60*60; break;
		case 'm':
			value *= 60; break;
		default: return 0;
	}
	return value;
}
time_t normalise_time(char *s, time_t t){
	if(s[0] != 'n' && s[0] != 'p') return t;
	time_t base;
	switch(s[1]){
		case 'y':
			base = 365*24*60*60; break;
		case 'M':
			base = 30*24*60*60; break;
		case 'w':
			base = 7*24*60*60; break;
		case 'd':
			base = 24*60*60; break;
		case 'h':
			base = 60*60; break;
		case 'm':
			base = 60; break;
		default: return t;
	}
	t -= t%base;
	if(s[0] == 'n') t += base;
	return t;
}
void send_time(char **args, struct discord *client, const struct discord_message *event){
	char rval[32];
	time_t t = time(NULL);
	time_t dtime = 0;
	for(int i = 1; i < 10; i++){
		if(args[i] == NULL) break;
		if(strlen(args[i]) > 1){
			dtime += sec_convert(args[i]);
			t = normalise_time(args[i], t);
		}
	}
	log_info("Time: %jd, add: %jd", (intmax_t) t, (intmax_t) dtime);
	t += dtime;
	char *mode;
	if(args[1] == NULL || strpbrk(args[1], "0123456789pn")) mode = strdup("f");
	else mode = strdup(args[1]);
	d_timestamp(rval, t, mode);
	free(mode);
	reply_noping(client, event, rval);
}

void express_hex(struct discord *client, const struct discord_message *event, char *num){
	char rval[32];
	long long int x;
	if(num != NULL) sscanf(num, "%lld", &x);
	else x = 0;
	sprintf(rval, "%llx", x);
	reply_noping(client, event, rval);
}


void express_unhex(struct discord *client, const struct discord_message *event, char *num){
	char rval[32];
	long long int x;
	if(num != NULL) sscanf(num, "%llx", &x);
	else x = 0;
	sprintf(rval, "%lld", x);
	reply_noping(client, event, rval);
}

void express_binary(struct discord *client, const struct discord_message *event, char *num){
	char rval[128];
	long long int x;
	if(num != NULL) sscanf(num, "%lld", &x);
	else x = 0;
	for(int i = 0; i < 64; i++)
		sprintf(rval+i, "%lld", (x >> (63-i)) & 1);
	char *rp = rval;
	while(*(++rp) == '0' && strlen(rp) > 1);
	reply_noping(client, event, rp);
}





