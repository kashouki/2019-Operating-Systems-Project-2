#include <stdio.h>
#include <string.h>
#include <error.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/time.h>

int main(int argc, char* argv[]){
	/*command*/
	char file[50];     /*argv[1]*/
	char function[50]; /*argv[2]*/
	char ip[50];       /*argv[3]*/

	strcpy(file, argv[1]);
	strcpy(function, argv[2]);
	strcpy(ip, argv[3]);
	/*-------*/
	/*open file*/
	int device_fd;
	int file_fd;
	struct timeval tv; struct timeval tz;

	if((device_fd = open("slave_device", O_RDWR)) < 0){
		perror("failed to open slave device\n");
		return 1;
	}

	gettimeofday(&tv, NULL);/*time start*/
	
	if((file_fd = open(file_name, O_RDWR | O_CREAT | O_TRUNC)) < 0){
		perror("failed to open input\n");
		return 1;
	}
	/*-------*/
}