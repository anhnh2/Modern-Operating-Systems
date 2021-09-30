#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
int main(int argc, char **argv) {
	struct stat statbuf;
	if (argc != 2) {
		printf("Usage: %s \e[4mFILENAME\n", argv[0]);
		return -1;
	}
	stat(argv[1], &statbuf);
	printf("Filename: %s\n", argv[1]);
	if (S_ISREG(statbuf.st_mode))
		printf("Type: regular file\n");
	else if (S_ISDIR(statbuf.st_mode))
		printf("Type: directory\n");
	else if (S_ISLNK(statbuf.st_mode))
		printf("Type: link\n");
	else if (S_ISFIFO(statbuf.st_mode))
		printf("Type: pipe\n");
	else if (S_ISSOCK(statbuf.st_mode))
		printf("Type: socket\n");
	else if (S_ISCHR(statbuf.st_mode))
		printf("Type: character device\n");
	else if (S_ISBLK(statbuf.st_mode))
		printf("Type: block device\n");
		printf("Inode: %lu\n", statbuf.st_ino);
		printf("Size: %ld\n", statbuf.st_size);
		printf("UID: %d\n", statbuf.st_uid);
		printf("Last Accessed at: %ld\n", statbuf.st_atim.tv_sec);
		printf("Permissions: %o\n", statbuf.st_mode & 0777);
	if (statbuf.st_mode & S_IRUSR)
		printf("File has user read permission\n");
	if (statbuf.st_mode & S_IWGRP)
		printf("File has group write permission\n");
	if (statbuf.st_mode & S_IXOTH)
		printf("File has others execution permission\n");
	return 0;
}
