#ifndef LIST_H_
#define LIST_H_
#include<stdio.h>
#include<stdlib.h>

struct LinkedList{
    int data;
    struct LinkedList *next;
 };

typedef struct LinkedList *node;

node CreateNode(int value);
node AddTail(node head, int value);
void Traverser(node head);
node InitHead();
node Input();
int SumAllValues(node head);
int LargestValue(node head);
void LargestSubset(node head);
int SearchValue(node head, int value);

#endif /* LIST_H_ */  
