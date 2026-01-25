#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

// A short script to write binary embed files. 

#define INPUT_SIZE 512
#define WB_SIZE 1024

int read_input(char *ibuff, int *ilen, int bytes){
	fgets(ibuff, bytes, stdin);
	char *ssp = ibuff;
	while(strsep(&ssp, "\n"));
	*ilen = strlen(ibuff);
	fflush(stdin);
	fflush(stdout);
}
char is_correct(){
	printf("\tIs this correct? Enter Y for yes, anything else for no: ");
	char ib[4];
	memset(ib, 0, 4);
	int il;
	read_input(ib, &il, 2);
	if(ib[0] == 'Y'){
		printf("Confirmed.\n");
		return 1 ;
	}
	return 0;
}

int main(){
	int embeds_written = 0;
	char input_buff[INPUT_SIZE];
	char write_buff[WB_SIZE];
	int input_len;

	while(1){
		do{
			memset(input_buff, 0, INPUT_SIZE);
			memset(write_buff, 0, WB_SIZE);
			printf("\nEnter name for embed command: ");
			read_input(input_buff, &input_len, 32);
			sprintf(write_buff, "%s.eemb", input_buff);
			printf("Embed saving as: %s\n", write_buff);
		} while(!is_correct());

		printf("\nEnter alternate for embed command: ");
		read_input(input_buff, &input_len, 512);
		sprintf(write_buff + strlen(write_buff)-5, ", %s", input_buff);
		printf("\nAlternate Names: %s\n", write_buff);

		embeds_written ++;

		printf("\nQ to quit, anything to continue: ");
		read_input(input_buff, &input_len, 2);
		if(input_buff[0] == 'Q'){
			printf("\nWrote %d embeds. Exiting.\n\n", embeds_written);
			break;
		}
	}
}
