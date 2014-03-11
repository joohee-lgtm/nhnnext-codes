#include <stdio.h>
#include <stdlib.h>
#include "bin_tree.h"
#include "dqueue.h"

#define MAX 16
#define CUR 4

void queue_full( dqueue_t *q);
void shift_array( dqueue_t *q);
void memory_error();
void free_dqueue(dqueue_t *q);

//for debug
void printq(dqueue_t *q);

//dqueue의 초기화 
//동적 메모리를 사용하므로 실패할 경우도 있음
//메모리 할당에 실패하면 에러 표시후 프로그램 종료
dqueue_t *init()
{
	dqueue_t *q;
	q = (dqueue_t *) malloc(sizeof(dqueue_t));
	if(!q)
		memory_error();
	q->qlist = calloc(CUR, sizeof(qelement));
	if(!q->qlist)
		memory_error();
	q->capa = CUR;
	q->front = q->rear = 0;
	return q;
}

void free_dqueue(dqueue_t *q)
{
	free(q->qlist);
	free(q);
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
void enqueue( dqueue_t *q, qelement item)
{
	if( is_full( q))
		queue_full( q);
	q->rear = (q->rear+1)%q->capa;
	q->qlist[q->rear] = item;
}
//큐의 front에서원소를 하나 빼움
qelement dequeue( dqueue_t *q)
{
	if(is_empty(q))
	{
		fprintf(stderr,"Stack empty error");
		exit(EXIT_FAILURE);
	}
	q->front= (q->front+1)%(q->capa);
	return q->qlist[q->front];
}

//큐이 가득차 있을 경우 호출되는 함수
//현재 크기가 최대 크기를 넘지 않는 경우
//큐을 두배 확장함 
//확장 후에는 큐 안의 원소를 효율적으로 쉬프트해서 정리를 해야 함 
//최대 크기를 넘는 경우, 에러표시후 프로그램 종료
void queue_full( dqueue_t *q)
{
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
			printf("%p <-- f, q: %d\n", q->qlist[i],q->front);
		else if(i== q->front)
			printf("%p <-- front: %d\n", q->qlist[i],q->front);
		else if(i== q->rear)
			printf("%p <-- rear: %d\n", q->qlist[i],q->rear);
		else
			printf("%p\n",q->qlist[i]);
	}
		printf("-----------------\n\n");
	pause();
}
