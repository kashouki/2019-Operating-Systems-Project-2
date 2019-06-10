#include <stdio.h>
#include <string.h>
#include <error.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/time.h>
int main(int argc, char* argv[]){
	/*command*/
	char file_name[50];     /*argv[1]*/
	char function_name[50]; /*argv[2]*/

	strcpy(file, argv[1]);
	strcpy(function, argv[2]);
	/*-------*/
	/*open file*/
	int device_fd;
	int file_fd;
	struct timeval tv; struct timeval tz;

	if((device_fd = open("master_device", O_RDWR)) < 0){
		perror("failed to open master_device\n");
		return 1;
	}

	gettimeofday(&tv, NULL);/*time start*/
	
	if((file_fd = open(file_name, O_RDWR)) < 0){
		perror("failed to input\n");
		return 1;
	}
	/*-------*/
}