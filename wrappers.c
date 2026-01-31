#include "wrappers.h"


void rotx_send(struct discord *client, const struct discord_message *event, char *rot, char *message){
	int x;
	sscanf(rot, "%d", &x);
	rotx(x, message);
	reply_noping(client, event, message);
}

void see_avatar(struct discord *client, const struct discord_message *event){
	char alink[256];
	char ustring[512];
	char *username;
	char *avatar;
	uint64_t uuid;
	int ac;
	if(event->mentions->array != NULL){
		avatar = event->mentions->array[0].avatar;
		username = event->mentions->array[0].username;
		uuid = event->mentions->array[0].id;
		ac = event->mentions->array[0].accent_color;
	}
	else{
		avatar = event->author->avatar;
		username = event->author->username;
		uuid = event->author->id;
		ac = event->author->accent_color;
	}
	sprintf(ustring, "%s's avatar", username);
	sprintf(alink, "https://cdn.discordapp.com/avatars/%lu/%s.png?size=4096", uuid, avatar); 
	
	simple_image_embed(client, event, ustring, alink, ac);
}

void print_uuid(struct discord *client, const struct discord_message *event){
	char send[2000];
	char *username;
	uint64_t uuid;

	if(event->mentions->array != NULL){
		username = event->mentions->array[0].username;
		uuid = event->mentions->array[0].id;
	}else{
		username = event->author->username;
		uuid = event->author->id;
	}
	sprintf(send, "%s's (<@%lu>'s) userid is `%lu` ", username, uuid, uuid);
	reply_noping(client, event, send);
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





