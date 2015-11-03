#include <stdio.h>
#include <stdlib.h>


struct Node{
	int element;
	struct Node *next;
};

struct Queue{
	struct Node *front;
	struct Node *rear;
};

struct Node *CreateNode(int element){
	struct Node *ptr;
	ptr = (struct Node*) malloc(sizeof(struct Node));

	ptr -> element = element;
	ptr -> next = NULL;
	return ptr;
}

void InitQueue(struct Queue *q){
	q -> front = NULL;
	q -> rear = NULL;
}

void enqueue(struct Queue *q,int element){
	struct Node *newptr;

	if(q -> rear == NULL){
		newptr = CreateNode(element);
		q -> front = newptr;
		q -> rear = newptr;
	}
	else{
		newptr = CreateNode(element);
		q->rear->next = newptr;
		q -> rear = newptr;
	}
}

int dequeue(struct Queue *q){
	int element;
	struct Node *tmp;

	if(q->front == NULL){
		return -1;
	}

    element = q->front->element;
    tmp = q->front;
    q->front = q->front->next;
    free(tmp);
	return element;
}

int peek(struct Queue q){
//	printf("%d", stk->element);
	if(q.front == NULL)
		return -1;
	else
		return q.front->element;
}

void show(struct Queue q){
	if(q.front == NULL){
		printf("EMPTY\n");
		return;
	}

	while(q.front != NULL){
		printf("%d ", q.front->element);
		q.front = q.front -> next;
	}
}

void error(){
    printf("*** Error ***");
    exit(0);
}

int main(){
	struct Queue q;
    int cmd, element;

    InitQueue(&q);

	while(1){
		scanf("%d", &cmd);
		switch(cmd){
			case 0:
				exit(0);
			case 1:
				scanf("%d", &element);
				if(element >= 0)
					enqueue(&q, element);
				else
                    error();
				break;
			case 2:
				element = dequeue(&q);
				if(element == -1){
					printf("EMPTY\n");
				}
				else
					printf("%d\n", element);
				break;
			case 3:
				element = peek(q);
				if(element == -1){
					printf("EMPTY\n");
				}
				else
					printf("%d\n", element);
				break;
			case 4:
				show(q);
		}
	}

    return 0;
}
