#include <stdio.h>
#include "filelib.h"

int main(){
	int n, m, k;
	printf("Line Number to write: ");
	scanf("%d", &n);
	WriteSingleLines("text-write2.txt",n);
	printf("\n");
	ReadFileToArray("text-read.txt");
	CountNumber("count.txt");
	printf("Line Number to delete: ");
	scanf("%d", &m);
	DeleteLine("text-detele.txt",m);
	MergeFile("text-read.txt","text-read.txt","text-write3.txt");
	printf("Enter n to encrypt: ");
	scanf("%d", &k);
	EnCrypt("decrypt.txt","encrypt.txt", k);
	printf("\n");
	DeCrypt("encrypt.txt", k);
}
