#include <stdio.h>
#include <stdlib.h>


struct Node{
	int element;
	struct Node *next;
};

struct Node *CreateNode(int element){
	struct Node *ptr;
	ptr = (struct Node*) malloc(sizeof(struct Node));

	ptr -> element = element;
	ptr -> next = NULL;
	return ptr;
}

void push(struct Node **stk,int element){
	struct Node *newptr;

	if(*stk == NULL){
		*stk = CreateNode(element);
	}
	else{
		newptr = CreateNode(element);
		newptr -> next = *stk;
		*stk = newptr;
		printf("--%d\n", newptr->element);
	}
}

int pop(struct Node **stk){
	int element;
	struct Node *ptr;

	if(*stk == NULL){
		return -1;
	}

	ptr = *stk;
	element = (*stk) -> element;
	*stk = (*stk) -> next;
	free(ptr);
	return element;
}

int peek(struct Node *stk){
//	printf("%d", stk->element);
	if(stk == NULL)
		return -1;
	else
		return stk->element;
}

void show(struct Node *stk){
	if(stk == NULL){
		printf("EMPTY\n");
		return;
	}

	while(stk != NULL){
		printf("%d ", stk->element);
		stk = stk-> next;
	}
}

void error(){
    printf("*** Error ***");
    exit(0);
}

int main(){
	struct Node *stk = NULL, *np;
	int cmd, element, capacity;
/*
	printf("%d\n", peek(stk));
	push(&stk, 1);
	push(&stk, 2);
	push(&stk, 3);
	push(&stk, 4);


	show(stk);
	printf("%d\n", pop(&stk));
	printf("%d\n", pop(&stk));
	show(stk);
*/
	while(1){
		scanf("%d", &cmd);
		switch(cmd){
			case 0:
				exit(0);
			case 1:
				scanf("%d", &element);
				if(element >= 0)
					push(&stk, element);
				else
					error();
				break;
			case 2:
				element = pop(&stk);
				if(element == -1){
					printf("EMPTY\n");
				}
				else
					printf("%d\n", element);
				break;
			case 3:
				element = peek(stk);
				if(element == -1){
					printf("EMPTY\n");
				}
				else
					printf("%d\n", element);
				break;
			case 4:
				show(stk);
		}
	}


	return 0;
}
