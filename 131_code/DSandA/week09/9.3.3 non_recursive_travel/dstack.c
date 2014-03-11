#include <stdio.h>
#include <stdlib.h>
#include "dstack.h"

void stack_full( dstack_t *s);
void memory_error();

//for debug
void print_stack(dstack_t *s);


//dstack의 초기화 
//동적 메모리를 사용하므로 실패할 경우도 있음
//메모리 할당에 실패하면 에러 표시후 프로그램 종료
dstack_t* init()
{
	dstack_t* s = calloc(CUR,sizeof(selement));
	if(!s)
		memory_error();
	s->stack = calloc(CUR, sizeof(selement));
	if(!s->stack)
		memory_error();
	s->capa = CUR;
	s->top = -1;
	return s;
}

//스택이 비어있으면 1, 아니면 0 리턴
int is_empty( dstack_t* s)
{
	return ( s->top==-1);
}
//스택이 가득차 있는지 검사함
int is_full( dstack_t* s)
{
	return (s->top == s->capa-1);
}
//스택의 현재 top의 위에 원소를 하나 집어넣는다. 
void push( dstack_t *s, selement item)
{
	if( is_full( s))
		stack_full( s);
	s->top++;
	s->stack[s->top] = item;
}
//스택의 top에서원소를 하나 빼움
selement pop( dstack_t *s)
{
	if(is_empty(s))
	{
		fprintf(stderr,"Stack empty error");
		exit(EXIT_FAILURE);
	}
	int top = s->top;
	s->top--;
	return s->stack[top];
}
//스택이 가득차 있을 경우 호출되는 함수
//현재 크기가 최대 크기를 넘지 않는 경우
//스택을 두배 확장함 
//최대 크기를 넘는 경우, 에러표시후 프로그램 종료
void stack_full( dstack_t *s)
{
	if(s->capa < MAX)
	{
		s->capa = 2 * s->capa;
		s->stack = realloc(s->stack,s->capa * sizeof (selement));
		if(!s->stack)
			memory_error();
	}
	else
	{
		fprintf(stderr,"MAX SIZE exceed error!\n");
		exit(EXIT_FAILURE);
	}
	//printf("now capacity becomes %d\n",s->capa);
}

void memory_error()
{
	fprintf(stderr,"memory alloc fail");
	exit(EXIT_FAILURE);
}
//여기부터 테스트 함수
//테스트를 위해 만듬 함수들이 들어감
//no need to see.

void pause()
{
	printf("Press enter to continue..");
	fgetc(stdin);
}

//스택안의 내용을 프린트 해줌
void print_stack(dstack_t *s)
{
	int i;
	printf("\n---  capa: %d ---\n", s->capa);
	for(i=s->capa-1; i >=0 ; i--)
	{
		if(i== s->top)
			printf("%p <-- top(%d)\n", s->stack[i],s->top);
		else
			printf("%p\n",s->stack[i]);
	}
	if(s->top == -1)
		printf("--- bottom <-top ---\n");
	else
		printf("--- bottom ---\n\n");
	pause();
}

void free_stack(dstack_t *s)
{
	free(s->stack);
	free(s);
}
