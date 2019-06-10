#include <stdio.h>
#include <string.h>
#include <error.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/time.h>
#include <sys/mman.h>
#include <unistd.h>
#include <sys/ioctl.h>

#define PAGE_SIZE 4096
#define BUF_SIZE 512
#define MAP_SIZE PAGE_SIZE*100

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
	
	/*connect master*/
	if(ioctl(device_fd, 0x12345677, ip) == -1){
		perror("failed to create socket for slave\n");
		return 1;
	}

	/*Read input*/
	size_t ret;
	size_t offset = 0;
	size_t map_size;
	size_t file_size = 0;
	char buffer[BUF_SIZE];
	char *kernel_addr;
	char *file_addr;

	/*fcntl*/
	if(functions[0] == "f"){
		do{
			ret = read(device_fd, buffer, sizeof(buf));
			write(file_fd, buffer, ret);
			file_size += ret;
		}while(ret > 0);
		break;
	}/*mmap*/
	else if(functions[0] == "m"){
		while(1){
			ret = ioctl(device_fd, 0x12345678);
			if(ret == 0){
				file_size = offset;
				break;
			}
			posix_fallocate(file_fd, offset, ret);
			file_addr = mmap(NULL, ret, PROT_WRITE, MAP_SHARED, file_fd, offset);
			kernel_addr = mmap(NULL, ret, PROT_READ, MAP_SHARED, device_fd, offset);
			memcpy(file_addr, kernel_addr, ret);
			offset += ret;
		}
		break;
	}
	ioctl(device_fd, 6666);
	/*disconnect*/
	if(ioctl(device_fd, 0x12345679) == -1){
		perror("failed to disconnect");
		return 1;
	}
	gettimeofday(&tz, NULL);/*time end*/

	/*time calculation*/
	double transmission_time;
	transmission_time = (tz.tv_sec - tv.tv_sec)*1000 + (tz.tv_usec - tv.tv_usec)*0.0001;
	printf("Transmission time: %lf ms, File size: %d bytes\n", transmission_time, file_size / 8);

	/*close fd*/
	close(file_fd);
	close(device_fd);
	/*-------*/
	return 0;
}