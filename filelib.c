#include "filelib.h"

char *WriteSingleLines(char *path, int lineNumber){
	int fd;
	fd = open(path, O_WRONLY | O_CREAT, 0600);
	if (fd == -1){
		printf("write error!");
		exit(1);
    	}
	while (lineNumber != 0){
		write(fd,"Hello World!\n",13);
		lineNumber--;
	}
	close(fd);
}

char **ReadFileToArray(char *path){
	int fd;
	char str[50][50];
	char buf[50];
	fd = open(path, O_RDONLY);
	if (fd == -1){
		printf("read error!");
		exit(1);
	}
	read(fd, buf, 50);
	int n = strlen(buf);
	int i, j = 0, k = 0;
	for(i=0; i<n; i++){
		if(buf[i] != ' '){
			str[j][k] = buf[i];
			k++;
			str[j][k] = '\0';
		}
		else{
			j++;
			k=0;
			str[j][k] = buf[i];
		}
	}
	for(i=0; i<=j; i++){
		printf("A[%d][] = %s\n", i, str[i]);
	}
	close(fd);
}

void CountNumber(char *path){
	int fd = open(path, O_RDONLY);
	char buf[50];
	ssize_t nr;
	nr = read (fd, buf, 50);
	if (nr == -1){
		printf("read error!");
		exit(1);
	}
	int n = strlen(buf);
	int countwords=0, i;
	if(buf[0] != ' ')
		countwords = 1;
	for(i=0; i<n-1; i++){
		if(buf[i] == ' ' && buf[i+1] != ' ')
			countwords++;
	}
	printf("Number of words: %d\n",countwords);
	printf("number of characters: %ld", nr-countwords);
	close(fd);
}

void DeleteLine(char *path, int lineNumber){
	int fd,fd1;
	char buf[50], temp[50];
	char str[50][50];
	fd = open(path, O_RDONLY);
	if (fd == -1){
		printf("read error!");
		exit(1);
	}
	read(fd, buf, 50);
	int n = strlen(buf);
	int i, j = 0, k = 0;
	for(i=0; i<n; i++){
		if(buf[i] != ' '){
			str[j][k] = buf[i];
			k++;
			str[j][k] = '\0';
		}
		else{
			j++;
			k=0;
			str[j][k] = buf[i];
		}
	}
	printf("\nBefore delete\n");
	for(i=0; i<=j; i++){
		printf("Row %i: %s\n", i+1, str[i]);
	}
	printf("After delete\n");
	for(i=0; i<=j; i++){
		if(i != lineNumber-1){
			strcat(temp,str[i]);
			strcat(temp, " ");
			printf("Row %i: %s\n", i+1, str[i]);
		}
		else{
			for(int m=0; m<=k; m++)
				str[i][m] = '\0';
		}
	}
	close(fd);
	fd1 = open(path, O_WRONLY);
	write(fd1,temp,50);
	close(fd1);
}

void MergeFile(char *pathOne, char *pathTwo, char *outFile){
	int fd1,fd2, fd3;
	ssize_t nr1, nr2;
	char buf1[100];
	char buf2[50];
	fd1 = open(pathOne, O_RDONLY);
	fd2 = open(pathTwo, O_RDONLY);
	fd3 = open(outFile, O_WRONLY | O_CREAT, 0600);
	if (fd1 == -1 || fd2 == -1 || fd3 == -1){
		printf("open error!");
		exit(1);
	}
	nr1 = read(fd1, buf1, 50);
	nr2 = read(fd2, buf2, 50);
	strcat(buf1,buf2);
	buf1[nr1+nr2] = '\0';
	write(fd3,buf1,nr1+nr2);
	close(fd1);
	close(fd2);
	close(fd3);
}

void EnCrypt(char *path, char *outFile, int n){
	int fd1,fd2;
	char buf[50], temp[50];
	fd1 = open(path, O_RDONLY);
	fd2 = open(outFile, O_WRONLY | O_CREAT, 0600);
	if (fd1 == -1 || fd2 == -1){
		printf("open error!");
	    	exit(1);
	}
	read(fd1, buf, 50);
	int nlen = strlen(buf);
	printf("Befor encrypt\n%s", buf);
	printf("After encrypt\n");
	for(int i=0; i<nlen-1; i++){
		buf[i] = buf[i] + n;
		temp[i] = buf[i];
		printf("%c", buf[i]);
	}
	write(fd2,temp,nlen-1);
	close(fd1);
	close(fd2);
}

void DeCrypt(char *path, int n){
	int fd1;
	char buf[50];
	fd1 = open(path, O_RDONLY);
	if (fd1 == -1){
		printf("open error!");
	    	exit(1);
	}
	read(fd1, buf, 50);
	int nlen = strlen(buf);
	printf("Befor decrypt\n%s", buf);
	printf("After decrypt\n");
	for(int i=0; i<nlen-1; i++){
		buf[i] = buf[i] - n;
		printf("%c", buf[i]);
	}
	close(fd1);
}


