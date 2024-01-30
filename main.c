#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
int fd, inode;

fd = open("./test.txt", O_RDONLY);
if (fd < 0){
    printf("Error opening file\n");
    exit(1);
}

struct stat file_stat;
int ret;

ret = fstat(fd, &file_stat);
if (ret < 0){
    printf("Error getting file stat\n");
    exit(1);
}

inode = file_stat.st_ino;

printf("File inode: %d\n", inode);
}
