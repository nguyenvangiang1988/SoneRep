 #ifndef FILE_H_  
 #define FILE_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *WriteSingleLines(char *path, int lineNumber);
char **ReadFileToArray(char *path);
void CountNumber(char *path);
void DeleteLine(char *path, int lineNumber);
void MergeFile(char *pathOne, char *pathTwo, char *outFile);

#endif /* FILE_H_ */
