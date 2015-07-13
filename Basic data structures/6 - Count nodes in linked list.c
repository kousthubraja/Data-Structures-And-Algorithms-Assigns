#include <stdio.h>
#include <stdlib.h>

struct Node{
	int element;
	struct Node *next;
};

struct Node *CreateNode(int element){
	struct Node *tmp;
	tmp = (struct Node*) malloc(sizeof(struct Node));
	tmp -> element = element;
	tmp -> next = NULL;

	return tmp;
}

void push(struct Node **stk, int element){
	struct Node *tmp;

	tmp = CreateNode(element);

	if(*stk == NULL)
		*stk = tmp;
	else{
		tmp -> next = *stk;
		*stk = tmp;
	}
}

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

int count(struct Node *stk){
    int c=0;

	if(stk == NULL){
		return -1;
	}

	while(stk != NULL){
        if(stk->element > 10)
            c++;
		stk = stk-> next;
	}
	return c;
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

    cnt = count(stack);

    if(cnt != -1){
        printf("%d\n", cnt);
    }
    else
        printf("EMPTY\n");

	return 0;
}
