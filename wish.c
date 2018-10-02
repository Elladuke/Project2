#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>



int main( int argc, char **argv ){
	char *buffer;
	size_t buffer_size = 32;
	ssize_t read;
	//allocating memory to the buffer
	buffer = (char *)malloc(buffer_size * sizeof(char));

	//if there are no arguments -- running in interactive mode
	if ( argc == 1 ) {

		printf("wish> ");
		getline( &buffer, &buffer_size, stdin);

		//strip buffer of the newline char
		if (buffer[strlen(buffer) -1 ] == '\n'){buffer[strlen(buffer) - 1] = '\0';}
		//while they are not the same
		while( strcmp( buffer, "exit") != 0 ){

			//creating a temp array to hold values that the user will enter
			char *temp_array[10] = {NULL};


			//split user cmd by spaces
			char *split_cmd = strtok(buffer, " ");

			int i = 0;

			while(split_cmd != NULL){
				temp_array[i] = split_cmd;
				i++;
				split_cmd = strtok(NULL, " ");
			}
//---beginning of latest comment


			//creating address variables for the possible addresses
			char * address_one = "/usr/bin/";
			char * address_two = "/bin/";

			//allocate space in memory for paths
			char *path_one = malloc( strlen(address_one) + strlen(temp_array[0]) + 1 );
			char *path_two = malloc( strlen(address_two) + strlen(temp_array[0]) + 1 );

			//create full path for path one
			strcat( path_one, address_one );
			strcat( path_one, temp_array[0] );

			//create full path for path two
			strcat (path_two, address_two );
			strcat (path_two, temp_array[0] );


			//check if we can access the path
			if ( access( path_one, X_OK) == 0 ){

				//fill param_array
				char* const param_array[10] = {path_one, temp_array[1], temp_array[2], temp_array[3], 
						temp_array[4], temp_array[5], temp_array[6], temp_array[7], temp_array[8], temp_array[9] };
				pid_t pid = fork();
				//error  -- fork didn't work

				if ( pid < 0){
				//	printf( "%ld",(long)getpid());
					fprintf(stderr, "\n usrbin folder fork failed\n");
					exit(1);
				}
				else if(pid == 0){

					execv( path_one, param_array);
					//error checking
					printf("since this prints then execv didn't work");
				}
				pid = wait(NULL); 
			}
			else if (access (path_two, X_OK) == 0){

					//fill param_array
				char* const param_array[10] = {path_two, temp_array[1], temp_array[2], temp_array[3], 
					temp_array[4], temp_array[5], temp_array[6], temp_array[7], temp_array[8], temp_array[9] };
				pid_t pid = fork();
				//error  -- fork didn't work
				if ( pid < 0){
				//	printf( "%ld",(long)getpid());
					fprintf(stderr, "\n bin folder-fork failed\n");
					exit(1);
				}
				else if(pid == 0){

					execv( path_two, param_array);
					//error checking
					printf("since this prints then execv didn't work");
				}
				pid = wait(NULL);


			}

			else{
				printf("command does not exist or file name does not exist\n");
			}


			//asking for user input again
			printf("wish> ");
			getline (&buffer, &buffer_size, stdin);
			if (buffer[strlen(buffer) -1 ] == '\n'){buffer[strlen(buffer) - 1] = '\0';}

		}
		exit(0);

	}
//////////////////////////////else if there is one argument -- running in batch mode

	else if( argc == 2 ){
		FILE *fp;
		fp = fopen( argv[1], "r");
		if( fp == NULL){
			printf("cannot open file\n");
			exit(0);
		}
		else{

			getline( &buffer, &buffer_size,fp );

			//strip buffer of the newline char
			if (buffer[strlen(buffer) -1 ] == '\n'){buffer[strlen(buffer) - 1] = '\0';}
			//while they are not the same
			while(( read = getline(&buffer, &buffer_size, fp)) != -1 ){
				if (buffer[strlen(buffer) -1 ] == '\n'){buffer[strlen(buffer) - 1] = '\0';}

				//creating a temp array to hold values that the user will enter
				char *temp_array[10] = {NULL};

//				printf("%s" , buffer);
				//split user cmd by spaces
				char *split_cmd = strtok(buffer, " ");

				int i = 0;

				while(split_cmd != NULL){
					temp_array[i] = split_cmd;
					i++;
					split_cmd = strtok(NULL, " ");
				}



				//creating address variables for the possible addresses
				char * address_one = "/usr/bin/";
				char * address_two = "/bin/";

				//allocate space in memory for paths
				char *path_one = malloc( strlen(address_one) + strlen(temp_array[0]) + 1 );
				char *path_two = malloc( strlen(address_two) + strlen(temp_array[0]) + 1 );

				//create full path for path one
				strcat( path_one, address_one );
				strcat( path_one, temp_array[0] );

				//create full path for path two
				strcat (path_two, address_two );
				strcat (path_two, temp_array[0] );


				//check if we can access the path
				if ( access( path_one, X_OK) == 0 ){

					//fill param_array
					char* const param_array[10] = {path_one, temp_array[1], temp_array[2], temp_array[3], 
							temp_array[4], temp_array[5], temp_array[6], temp_array[7], temp_array[8], temp_array[9] };
					pid_t pid = fork();
					//error  -- fork didn't work
					if ( pid < 0){
					//	printf( "%ld",(long)getpid());
						fprintf(stderr, "\n usrbin folder fork failed\n");
						exit(1);
					}
					else if(pid == 0){

						execv( path_one, param_array);
						//error checking
						printf("since this prints then execv didn't work");
					}
					pid = wait(NULL); 
				}
				else if (access (path_two, X_OK) == 0){

						//fill param_array
					char* const param_array[10] = {path_two, temp_array[1], temp_array[2], temp_array[3], 
						temp_array[4], temp_array[5], temp_array[6], temp_array[7], temp_array[8], temp_array[9] };
					pid_t pid = fork();
					//error  -- fork didn't work
					if ( pid < 0){
					//	printf( "%ld",(long)getpid());
						fprintf(stderr, "\n bin folder-fork failed\n");
						exit(1);
					}
					else if(pid == 0){

						execv( path_two, param_array);
						//error checking
						printf("since this prints then execv didn't work");
					}
					pid = wait(NULL);

				}

				else{
					printf("command does not exist or file name does not exist\n");
				}
			}

			exit(0);


	}//if the file exists


	}//end of else if for batch file

	//else  --  flag an error
	else{
		perror ("Too many arguments");
		exit(0);
	}

	return 0;
}


