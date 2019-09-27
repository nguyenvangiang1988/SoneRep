#include "list.h"

node CreateNode(int value){
    node temp;
    temp = (node)malloc(sizeof(struct LinkedList));
    temp->next = NULL;
    temp->data = value;
    return temp;
}

node AddTail(node head, int value){
    node temp,p;
    temp = CreateNode(value);
    if(head == NULL){
        head = temp;
    }
    else{
        p  = head;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = temp;
    }
    return head;
}

void Traverser(node head){
    for(node p = head; p != NULL; p = p->next){
        printf("%3d", p->data);
    }
}

node InitHead(){
    node head;
    head = NULL;
    return head;
}

node Input(){
    node head = InitHead();
    int n, value;
    do{
        printf("\nEnter the quantity: ");
        scanf("%d", &n);
    }while(n <= 0);

    for(int i = 0; i < n; ++i){
        printf("Enter value %d: ",i);
        scanf("%d", &value);
        head = AddTail(head, value);
    }
    return head;
}

int SumAllValues(node head){
	int sum=0;
    for(node p = head; p != NULL; p = p->next){
    	sum+=p->data;
    }
    return sum;
}

int LargestValue(node head){
	int max=0;
    for(node p = head; p != NULL; p = p->next){
    	max=((p->data)>max)?p->data:max;
    }
    return max;
}

void LargestSubset(node head){
	node i,j;
	for(i=head; i->next != NULL; i = i->next){
		j=i->next;
		if((i->data)<(j->data)){
			printf("%d ",i->data);
		}
		if(j->next == NULL){
			if((j->data)>(i->data)){
				printf("%d ",j->data);
			}
		}else {
			if((i->data)<(j->data) && (j->data)>(j->next->data)){
				printf("%d ",j->data);
			}
		}
	}
}

int SearchValue(node head, int value){
    int i=0;
    for(node p = head; p != NULL; p = p->next){
        if(i == value){
            return p->data;
        }
        ++i;
    }
    return -1;
}
