//
//  main.c
//  dqueue
//
//  Created by KIMJOOHWEE on 13. 5. 7..
//  Copyright (c) 2013년 KIMJOOHWEE. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>

#define MAX 16
#define CUR 4
#define debug

typedef int element;

//dynamic queue 구조체
typedef struct {
	element *qlist;
	int front;
	int rear;
	int capa;
} dqueue_t;

void init( dqueue_t * q);
int is_empty( dqueue_t *q);
int is_full( dqueue_t *q);
void enqueue( dqueue_t *q, element item);
element dequeue( dqueue_t *q);
void queue_full( dqueue_t *q);
void shift_array( dqueue_t *q);
void memory_error();

//for debug
void printq(dqueue_t *q);

//main function of dqueue.c
//dqueue.c 가 정상적으로 동작하는지 테스트한다.
int main()
{
	//dynamic queue initialize
	int i;
	dqueue_t queue;
	init( &queue);
	enqueue( &queue,1);
	enqueue( &queue,2);
	dequeue(&queue);
	enqueue( &queue,3);
	enqueue( &queue,4);
	dequeue(&queue);
	enqueue( &queue,5);
	enqueue( &queue,6);
	enqueue( &queue,7);
	enqueue( &queue,8);
	while(!is_empty(&queue))
		dequeue(&queue);
	for(i=0; i < MAX; i++)
		enqueue(&queue, i);
	free(queue.qlist);
	return 0;
}

//dqueue의 초기화
//동적 메모리를 사용하므로 실패할 경우도 있음
//메모리 할당에 실패하면 에러 표시후 프로그램 종료
void init(dqueue_t* q)
{
	q->qlist = calloc(CUR, sizeof(element));
	if(!q->qlist)
		memory_error();
	q->capa = CUR;
	q->front = q->rear = 0;
	printf("init\n");
	printq(q);
}

//큐가 비어있으면 1, 아니면 0 리턴
int is_empty( dqueue_t* q)
{
	return ( q->front== q->rear );
}

//큐가 가득차 있는지 검사함
int is_full( dqueue_t* q) {
	return ((q->rear +1)% q->capa == q->front);
}

//큐의 현재 front의 위에 원소를 하나 집어넣는다.
//가득차 있을 경우 확장함
void enqueue( dqueue_t *q, element item)
{
	if( is_full( q))
		queue_full( q);
	q->rear = (q->rear+1)%q->capa;
	q->qlist[q->rear] = item;
	printf("enqueue\n");
	printq(q);
}
//큐의 front에서원소를 하나 빼움
element dequeue( dqueue_t *q)
{
	if(is_empty(q))
	{
		fprintf(stderr,"Stack empty error");
		exit(EXIT_FAILURE);
	}
	q->front= (q->front+1)%(q->capa);
	printf("dqueue\n");
	printq(q);
	return q->qlist[q->front];
}

//큐이 가득차 있을 경우 호출되는 함수
//현재 크기가 최대 크기를 넘지 않는 경우
//큐을 두배 확장함
//확장 후에는 큐 안의 원소를 효율적으로 쉬프트해서 정리를 해야 함
//최대 크기를 넘는 경우, 에러표시후 프로그램 종료
void queue_full( dqueue_t *q)
{
	//implement
	//should call shift_array(q);
}

void memory_error()
{
	fprintf(stderr,"memory alloc fail");
	exit(EXIT_FAILURE);
}

/**
 @brief 큐를 확장한 후 원소들을 적절하게 정리함
 @see qu
 @param arr 정리할 배열
 @param front 큐의 front
 @param capa 늘어나기 전의 용량
 */

void shift_array(dqueue_t *q)
{
	//implement
}


//여기부터 테스트 함수
//테스트를 위해 만듬 함수들이 들어감
//no need to see.

void pause()
{
	printf("Press enter to continue..");
	fgetc(stdin);
}

//큐안의 내용을 프린트 해줌
void printq(dqueue_t *q)
{
	int i;
	printf("---  capa: %d ---\n", q->capa);
	for(i=q->capa-1; i >=0 ; i--)
	{
		if(i== q->front && i== q->rear)
			printf("%d <-- f, q: %d\n", q->qlist[i],q->front);
		else if(i== q->front)
			printf("%d <-- front: %d\n", q->qlist[i],q->front);
		else if(i== q->rear)
			printf("%d <-- rear: %d\n", q->qlist[i],q->rear);
		else
			printf("%d\n",q->qlist[i]);
	}
    printf("-----------------\n\n");
	pause();
}
