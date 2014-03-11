#include <stdio.h>
#include <stdlib.h>

#define MAX_Q_SIZE 7
typedef int element;
typedef struct {
	element queue[MAX_Q_SIZE];
	int front;
	int rear;
} queue_t;

void init(queue_t *q);
void enqueue(queue_t *q, element item);
element dequeue(queue_t *q);
int isEmpty(queue_t *q);
int isFull(queue_t *q);
void queueFull(queue_t *q);

int main()
{
	queue_t q;
	init(&q);
	enqueue(&q,1);
	enqueue(&q,2);
	enqueue(&q,3);
	enqueue(&q,4);
	enqueue(&q,5);
	enqueue(&q,6);
	printf("is full? %d\n", isFull(&q));
	printf("dequeue %d\n", dequeue(&q));
	printf("is full? %d\n", isFull(&q));
	enqueue(&q,7);
	printf("is full? %d\n", isFull(&q));
	printf("dequeue %d\n", dequeue(&q));
	printf("dequeue %d\n", dequeue(&q));
	printf("dequeue %d\n", dequeue(&q));
	printf("dequeue %d\n", dequeue(&q));
	printf("dequeue %d\n", dequeue(&q));
	printf("dequeue %d\n", dequeue(&q));
	printf("dequeue %d\n", dequeue(&q));
	printf("never reach this code\n");
    
	return 0;
}

void init(queue_t *q)
{
	q->front = q-> rear =0;
}

int isFull(queue_t *q)
{
	return (q->front == ( (q->rear+1) % MAX_Q_SIZE));
}

//채울 부분
int isEmpty(queue_t *q)
{
	return (q->front == q->rear);
}

void enqueue(queue_t *q, element item)
{
	if(isFull(q))
		queueFull(q);
    
	q->rear= (q->rear+1)% MAX_Q_SIZE;
	q->queue[q->rear] = item;
}

void queueFull(queue_t *q)
{
	fprintf(stderr,"queue full error\n");
	exit(EXIT_FAILURE);
}

//채울 부분
element dequeue(queue_t *q)
{
    element item;
    
    if (isEmpty(q))
    {
        printf("queue empty error");
        exit(EXIT_FAILURE);
    }
	else
    {
        //q->front+1을 먼저 하는 이유
        //      : front는 항상 비어있기 때문에
        q->front = (q->front+1)%MAX_Q_SIZE;
        item = q->queue[q->front];
        return item;
    }
}
