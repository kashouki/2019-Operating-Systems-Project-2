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
size_t get_filesize(const char* filename);

int main(int argc, char* argv[]){
	/*command*/
	char file_name[50];     /*argv[1]*/
	char function_name[50]; /*argv[2]*/

	strcpy(file_name, argv[1]);
	strcpy(function_name, argv[2]);

	/*open file*/
	int device_fd;
	int file_fd;
	struct timeval tv; struct timeval tz;
	size_t file_size = 0;
	if((device_fd = open("master_device", O_RDWR)) < 0){
		perror("failed to open master_device\n");
		return 1;
	}

	gettimeofday(&tv, NULL);/*time start*/
	
	if((file_fd = open(file_name, O_RDWR)) < 0){
		perror("failed to input\n");
		return 1;
	}

	if ((file_size = get_filesize(file_name)) < 0){
		perror("failed to get file size\n");
		return 1;
	}

	/*create socket and connect master device*/
	if(ioctl(device_fd, 0x12345677) == -1){
		perror("failed to create socket for master\n");
		return 1;
	}

	/*Read input*/
	size_t ret;
	size_t offset = 0;
	size_t map_size;
	char buffer[BUF_SIZE];
	char *kernel_addr;
	char *file_addr;

	/*fcntl*/
	if(function_name[0] == 'f'){
		do{
			ret = read(device_fd, buffer, sizeof(buffer));
			write(file_fd, buffer, ret);
		}while(ret > 0);
	}/*mmap*/
	else if(function_name[0] == 'm'){
		while(offset < file_size){
			map_size = MAP_SIZE;
			if((file_size - offset) < map_size){
				map_size = file_size - offset;
			}
			file_addr = mmap(NULL, map_size, PROT_READ, MAP_SHARED, file_fd, offset);
			kernel_addr = mmap(NULL, map_size, PROT_WRITE, MAP_SHARED, device_fd, offset);
			memcpy(kernel_addr, file_addr, map_size);
			offset += map_size;
			ioctl(device_fd, 0x12345678, map_size);
		}
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
	printf("Transmission time: %lf ms, File size: %zu bytes\n", transmission_time, file_size / 8);

	/*close fd*/
	close(file_fd);
	close(device_fd);
	/*-------*/
	return 0;
}

size_t get_filesize(const char* filename)
{
    struct stat st;
    stat(filename, &st);
    return st.st_size;
}