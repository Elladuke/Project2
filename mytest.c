

#include <stdio.h>

int main (){

	FILE fp = fopen("hello.py", "r");
	char buffer[100];
	if (fp == NULL ){
		printf("cannot open file\n");
		perror(",my error:");
		exit(1);


	}
	else{
		fgets(buffer, 100, fp);
		printf("%s", buffer);
}
	fclose(fp);
}
