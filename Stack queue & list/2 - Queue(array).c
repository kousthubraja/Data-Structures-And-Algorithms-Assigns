#include <stdio.h>
#include <stdlib.h>


struct Queue{
	int *data;
	int front;
	int rear;
	int capacity;
};

void enqueue(struct Queue *q,int element){
	if(q->front-q->rear == q-> capacity){
		printf("OVERFLOW\n");
		return;
	}

	q->data[q->rear] = element;
	q->rear ++;
}

int pop(struct Queue *q){
	int element;

	if(q->front == q->rear)
		return -1;
	else{
		element = q -> data[ q->front];
		q -> front++;
		return element;
	}
}

int peek(struct Queue q){
	if(q.front == q.rear)
		return -1;
	else
		return q.data[q.front];
}

void show(struct Queue q){
	int i;
	i=q.front;

	if(i == q.rear){
		printf("EMPTY\n");
		return;
	}

	while(i != q.rear){
		printf("%d ", q.data[i++]);
	}
}

void initq(struct Queue *q, int capacity){
	q->data = (int*) malloc(sizeof(int) * capacity);
	q->front = 0;
	q->rear = 0;
	q->capacity = capacity;
}

void error(){
    printf("*** Error ***");
    exit(0);
}

int main(){
	struct Queue q;
	int cmd, element, capacity;



	scanf("%d", &capacity);
	initq(&q, capacity);


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
				element = pop(&q);
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
