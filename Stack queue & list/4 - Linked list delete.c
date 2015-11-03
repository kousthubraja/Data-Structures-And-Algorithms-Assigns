#include <stdio.h>
#include <stdlib.h>

struct Node{
	int element;
	struct Node *next;
	struct Node *prev;
};

struct DoubleList{
    struct Node *first;
    struct Node *last;
};

struct Node *CreateNode(int element){
	struct Node *tmp;
	tmp = (struct Node*) malloc(sizeof(struct Node));
	tmp -> element = element;
	tmp -> next = NULL;
    tmp -> prev = NULL;
	return tmp;
}

void push(struct Node **stk, int element){
	struct Node *tmp;

	tmp = CreateNode(element);

	if(*stk == NULL)
		*stk = tmp;
	else{
		tmp -> next = *stk;
		(*stk) -> prev = tmp;
		*stk = tmp;
	}
}
/*
int pop(struct Node **stk){
	struct Node *tmp;

	if(*stk == NULL)
		return -1;

	tmp = *stk;
	*stk = (*stk) -> next;
	free(tmp);
}


int peek(struct Node *stk){
	if(stk == NULL)
		return -1;
	return stk->element;
}
*/
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

void show_rev(struct Node *stk){
	if(stk == NULL){
		printf("EMPTY\n");
		return;
	}

	while(stk != NULL){
		printf("%d ", stk->element);
		stk = stk-> next;
	}
}


void del_alt(struct Node **stk){
    struct Node *tmp;
    tmp = *stk;

	if(*stk == NULL){
		return;
	}

	while(*stk != NULL && (*stk)->next!=NULL){
        printf("* %d\n", (*stk)->element);
        (*stk)-> next = (*stk)->next->next;
        if((*stk)->next->next!=NULL)
            (*stk)->next->next->prev = *stk;
		*stk = (*stk)-> next;
	}
	*stk = tmp;
}

void error(){
    printf("*** Error ***");
    exit(0);
}

int main(){
	struct Node *stack = NULL;

	int n, cnt=0, element;

	scanf("%d", &n);

    while(n--){
        scanf("%d", &element);
        push(&stack, element);
    }

    del_alt(&stack);

    show(stack);

	return 0;
}
