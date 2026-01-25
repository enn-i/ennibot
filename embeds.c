#include "embeds.h"

//SIMPLE EMBEDS
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
	simple_image_embed(client, event, "banananananananananex", "https://veja.abril.com.br/wp-content/uploads/2017/12/homer-simpson-1-264a0.jpg", 0x102f61);
}
void yfs_embed(struct discord *client, const struct discord_message *event){
	simple_image_embed(client, event, "yfs.", "https://gcdnb.pbrd.co/images/9et5VhVs8If3.png?o=1", 0x3e0752);
}
void lolight_embed(struct discord *client, const struct discord_message *event){
	simple_image_embed(client, event, "lolight", "https://i.pinimg.com/originals/9e/d0/7e/9ed07e35185be586408836aa591052e1.jpg", 0xffa200);
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

char parse_embed(struct discord *client, const struct discord_message *event, char *cmd){
	if(!strcmp(cmd, "enot") || !strcmp(cmd, "sofanthiel") || !strcmp(cmd, "inv"))
		enot_embed(client, event);
	else if(!strcmp(cmd, "watcher"))
		watcher_embed(client, event);
	else if(!strcmp(cmd, "qwerty"))
		qwerty_embed(client, event);
	else if(!strcmp(cmd, "soulhunter"))
		soul_embed(client, event);
	else if(!strcmp(cmd, "shin"))
		shin_embed(client, event);
	else if(!strcmp(cmd, "ottomanempire"))
		ottomanempire_embed(client, event);
	else if(!strcmp(cmd, "smightyguncat") || !strcmp(cmd, "gunguncat"))
		guncat_embed(client, event);
	else if(!strcmp(cmd, "ronald") )
		ronald_embed(client, event);
	else if(!strcmp(cmd, "kalun") )
		kalun_embed(client, event);
	else if(!strcmp(cmd, "bee") )
		bee_embed(client, event);
	else if(!strcmp(cmd, "luna") )
		luna_embed(client, event);
	else if(!strcmp(cmd, "bananex") )
		banana_embed(client, event);
	else if(!strcmp(cmd, "yfs") || !strcmp(cmd, "yfs227"))
		yfs_embed(client, event);
	else if(!strcmp(cmd, "lolight") || !strcmp(cmd, "findsomeoneelse'shome"))
		lolight_embed(client, event);
	else return 0;
	return 1;
}

