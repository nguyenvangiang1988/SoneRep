#include <stdio.h>  
#include "list.h"

int main(){
	int n;
	printf("Create a linked link");
	node head = Input();
	Traverser(head);
	printf("\nSum all values: %d", SumAllValues(head));
	printf("\nLargest value: %d", LargestValue(head));
	printf("\nLargest increment subset: ");
	LargestSubset(head);
	printf("\nGiven an index: ");
	scanf("%d",&n);
	int index = SearchValue(head,n);
	printf("Value of that index: %d", index);
}
