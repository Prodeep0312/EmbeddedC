
#include<stdio.h>
#include<sys/stat.h>

int main()

{
	struct stat s;
	stat("file1",&s);
	printf("inode number::%ld\n",s.st_ino);
	printf("size of file::%ld\n",s.st_size);
	
	if(S_ISREG(s.st_mode))
		printf("It is a regular file\n");
	else if (S_ISDIR(s.st_mode))
		printf("It is a directory\n");
	else if (S_ISFIFO(s.st_mode))
		printf("It is a FIFO file\n");
	else if (S_ISLNK(s.st_mode))
		printf("It is a LINK file\n");
	else if (S_ISBLK(s.st_mode))
		printf("It is a block device file\n");
	else if (S_ISCHR(s.st_mode))
		printf("It is a character file\n");


}

