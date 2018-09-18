#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
/*
 * Author: Immanuella Duke
 * Course: Operating Systems
 * Task: Implementing my version of the cat command in Linux systems
*/
int main( int argc, char **argv){
	char buffer[100];
	FILE *fp;
	int count = 1;
	while (count < argc){
		//opening the file
		fp = fopen(argv[count], "r");
		//error checking for if the file does not exist
		if (fp == NULL ){
			printf(" \ncannot open file \n");
			perror(argv[count]);
			exit(1);
		}
		//if the file exists, go through each line and print content
		else {

			while( fgets(buffer,sizeof(buffer),fp)){
				printf("%s", buffer);
			}

		}
		//closing the file
		fclose(fp);
		//print statement to notify user that the full file has been printed
		printf("--------------printed a full file-------------\n");
		//increment count for printing each file
		count++;
	}

	return (0);

}
