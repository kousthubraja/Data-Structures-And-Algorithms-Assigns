#include <stdio.h>
#include <stdlib.h>


struct Stack{
	int *stack;
	int size;
	int capacity;
};

void push(struct Stack *stk,int element){
	if(stk->size == stk-> capacity){
		printf("OVERFLOW\n");
		return 0;
	}
	realloc(stk->stack, sizeof(stk->stack) + sizeof(int));
	stk->stack[stk->size] = element;
	stk->size = stk->size + 1;
}

int pop(struct Stack *stk){
	int element;
	
	if(stk->size == 0)
		return NULL;
	else{
		element = stk -> stack[ stk->size - 1];
		realloc(stk->stack, sizeof(stk->stack) - sizeof(int));
		stk -> size--;
		return element;
	}
}

int peek(struct Stack stk){
	if(stk.size == 0)
		return NULL;
	else
		return stk.stack[stk.size - 1];
}

void show(struct Stack stk){
	int size = stk.size;
	if(size == 0){
		printf("Empty\n");
		exit(0);
	}
	
	while(size--){
		printf("%d ", stk.stack[size]);
	}
}

int main(){
	struct Stack stk;
	int cmd, element, capacity;
	
	stk.stack = (int*) malloc(sizeof(int));
	stk.stack[0] = 0;
	stk.size = 0;
	
	scanf("%d", &capacity);
	stk.capacity = capacity;
	
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
				if(element == NULL){
					printf("EMPTY\n");
				}
				else
					printf("%d\n", element);
				break;
			case 3:
				element = peek(stk);
				if(element == NULL){
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
