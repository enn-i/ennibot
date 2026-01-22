
#include "utils_ennibot.h"

char **token_parser(char *message, int *args){
	// setting up two passed pointers
	char **tokens = malloc(sizeof(char *) * 10);
	*args = 0;
	// Tokenising with strsep and copying memory to tokens array
	char *p = strdup(message);
	char *mp;
	for(int i = 0; i < 10; i++){
		if((mp = strsep(&p, " ")))
			tokens[i] = strdup(mp);
		else tokens[i] = NULL;
		(*args)++;
	}
	while(strsep(&p, " "));
	free(p);
	return tokens;
}
void free_tokens(char **tokens, int argc){
	for(int i = 0; i < argc; ++i) free(tokens[i]);
	free(tokens);
}
char *after_arg(char *message, int i, char **argv){
	while(i--) message += strlen(argv[i]);
	message++;
	return message;
}

void reply_noping(struct discord *client, const struct discord_message *event, char *s){
	struct discord_create_message params = { 
		 .content = s,
		 .allowed_mentions = &(struct discord_allowed_mention){
			.replied_user = 0,
		 },
		 .message_reference = &(struct discord_message_reference){
			.message_id = event->id,
			.channel_id = event->channel_id,
			.guild_id = event->guild_id,
		},
	};
	discord_create_message(client, event->channel_id, &params, NULL);
}

//replies to person who sent the message's reply and deletes the person's message
// (lets person send message as EnniBot)
void sm_reply_reply_delete(struct discord *client, const struct discord_message *event, char *s){
	struct discord_create_message params = { 
		 .content = s,
		 .message_reference = !event->referenced_message ? NULL : &(struct discord_message_reference){
					 .message_id = event->referenced_message->id,
					 .channel_id = event->channel_id,
					 .guild_id = event->guild_id,
				 },
		};
	discord_delete_message(client, event->channel_id, event->id,
	&(struct discord_delete_message){ .reason = "echo!" }, NULL);
	discord_create_message(client, event->channel_id, &params, NULL);

}

void simple_image_embed(struct discord *client, const struct discord_message *event, char *title, char *image, int color){
    struct discord_embed embeds[] = {
        {
            .title = title,
				.color = color,
            .image =
                &(struct discord_embed_image){
                    .url = image,
                },
        },
    };

    struct discord_create_message params = {
        .embeds =
            &(struct discord_embeds){
                .size = sizeof(embeds) / sizeof *embeds,
                .array = embeds,
            },
    };
    discord_create_message(client, event->channel_id, &params, NULL);
}


void rotx(int x, char *string){
	char *s = string;
	do{
		if(*s >= 'a' && *s <= 'z') *s = (*s - 'a' + x) % 26 + 'a';
		if(*s >= 'A' && *s <= 'Z') *s = (*s - 'A' +x) % 26 + 'A';
	}while(*++s);
}

void generate_code(char *code){
	int rData = open("/dev/urandom", O_RDONLY);
	ssize_t result;
	if((result = read(rData, code, 16)) < 0){
		fprintf(stderr, "Unable to read random number, code %ld", result);
		return;
	}
	close(rData);

	for(int i = 0; i <= 16; i++){
		if(code[i] < 0) code[i] *= -1;
		code[i] = (code[i] % ('~' - '!')) + 34;
		if(code[i] == '`') code[i] = '~';
	}
	FILE *f = fopen("current.code", "w"); 
	if (f == 0){
		fprintf(stderr, "Secret Code Writing Error");
		return;
	}
	code[15] = '\0';
	fputs(code, f);
	fprintf(f, "%s", code);
	fclose(f);

}


void get_current_code(char *check){
	FILE *f = fopen("current.code", "r"); 
	if (f <= 0){
		generate_code(check);
	}else{
		f = fopen("current.code", "r");
		fgets(check, 16, f);
	}
	//log_info("Current code: %s", check);
	fclose(f);
}

// ulld_rand : low level random number generator for ulld ints. 
// range: (0, max]
unsigned long long int ulld_rand(long long unsigned int max){
	if(max == 0){ // stupid-proofing for entering 0
		log_info("ulld_rand Error: maximum rand of 0");
		return 0; 
	}

	int rData = open("/dev/urandom", O_RDONLY);
	long long unsigned int result;
	ssize_t bytes_read; // the ammount of bytes read from rData
	
	if( (bytes_read = read(rData, &result, sizeof(result)) ) < 0){
		log_info("Read error:\n\tWhile generating uuld_rand on line %d \
		\n\tBytes read: %d", __LINE__, bytes_read);
		return 0;
	}
	close(rData);
	
	result %= max;
	return ++result;
}

void d_timestamp(char *c, time_t t, char *mode){
	char m;
	if(mode == NULL || !(mode = strpbrk(mode, "tTdDfFR"))) m = 'f';
	else m = mode[0];
	if(c != NULL) sprintf(c, "<t:%llu:%c>", t, m);
}

void p_time(char *c, time_t *t){
	if(t == NULL) *t = time(NULL);
	if(c != NULL) sprintf(c, "%jd", (intmax_t) (*t));
}



