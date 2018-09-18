#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>


int main( int argc, char **argv){
	char buffer[100];
	FILE *fp;
	int count = 1;
	while (count < argc){

		fp = fopen(argv[count], "r");

		if (fp == NULL ){
			printf(" \ncannot open file \n");
			perror(argv[count]);
			exit(1);
		}
		else {

			while( fgets(buffer,sizeof(buffer),fp)){
				printf("%s", buffer);
			}

		}

		fclose(fp);

		printf("--------------printed a full file-------------\n");

		count++;
	}

	return (0);

}
