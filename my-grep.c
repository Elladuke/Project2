#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
/*
 * Author: Immanuella Duke
 * Course: Operating Systems
 * Task  : Implementing my version of the grep command in Linux systems
*/
int main(int argc, char ** argv){
	char buffer[100];
	FILE *fp;
	int count = 2;
	fp = fopen(argv[count],"r");
	char *  line = NULL;
	size_t  len = 0;
	ssize_t read ;

	//special case for if there are no cmd arguments
	if  (argc == 1){
		printf("my-grep : searchterm [file...]\n");
		exit(1);
	}

	//special case for if just the search term is given but no files
	else if (argc == 2){
		printf("Enter a sentence: ");
		fgets(buffer, 100, stdin);
		if (strstr(buffer, argv[1]) != NULL){
			printf( "%s",buffer);
		}
		return (0);
	}

	//case for if there are files
	else{
		while(count < argc){
			fp = fopen(argv[count] ,"r");
			if (fp == NULL){
				printf("my-grep : cannot open file\n");
				exit(1);
			}

			//if the argv[count] == ""  then print none of the lines --check to make sure this actually works
			//else if ( strcmp(argv[1], "") ){
			else if  (argv[1] == NULL){
				printf("empty string given\n");
				exit(1);
			}

			else{
				while ((read =  getline(&line, &len, fp)) != -1 ){ //while we've not gone through every line in the file.
					if (strstr(line, argv[1]) != NULL){
						printf("%s",line );
					}

				}

			}
		//incrementing count so we can go through each file
		count++;
		}
	}

	return(0);
}
