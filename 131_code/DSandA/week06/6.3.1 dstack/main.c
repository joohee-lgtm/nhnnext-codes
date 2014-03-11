//
//  main.c
//  dstack
//
//  Created by KIMJOOHWEE on 13. 5. 7..
//  Copyright (c) 2013년 KIMJOOHWEE. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>

#define MAX 16
#define CUR 4
typedef int element;
//dynamic stack 구조체
typedef struct {
	element *stack;
	int top;
	int capa;
} dstack_t;

void init(dstack_t * s);
int is_empty ( dstack_t *s);
int is_full( dstack_t *s);
void push( dstack_t *s, element item);
element pop( dstack_t *s);
element peek( dstack_t *s);
void stack_full( dstack_t *s);
void memory_error();

//for debug
void print_stack(dstack_t *s);

//main function of dstack.c
//dstack.c 가 정상적으로 동작하는지 테스트한다.
int main( )
{
	//dynamic stack initialize
	int i;
	dstack_t stack;
	init( &stack);
	print_stack(&stack);
	printf( "after init, is stack empty? %d\n", is_empty(&stack));
	push( &stack,1);
	printf( "after push 1, is stack empty? %d\n", is_empty(&stack));
	push( &stack,2);
	push( &stack,3);
	push( &stack,4);
	printf( "after 4 pushes, is stack full? %d\n", is_full(&stack));
	push( &stack,5);
	print_stack(&stack);
	element x = pop( &stack);
	printf( "pop element= %d\n", x);
	print_stack(&stack);
	//flush stack
	while(!is_empty(&stack))
		pop(&stack);
	//generate error
	for(i=0; i <= MAX; i++)
	{
		push(&stack, i);
		print_stack(&stack);
	}
	free(stack.stack);
	return 0;
}

//dstack의 초기화
//동적 메모리를 사용하므로 실패할 경우도 있음
//메모리 할당에 실패하면 에러 표시후 프로그램 종료
void init(dstack_t* s)
{
	s->stack = calloc(CUR, sizeof(element));
	if(!s->stack)
		memory_error();
	s->capa = CUR;
	s->top = -1;
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
void push( dstack_t *s, element item)
{
	if( is_full( s))
		stack_full( s);
	s->top++;
	s->stack[s->top] = item;
}

//스택의 top에서원소를 하나 빼움
element pop( dstack_t *s)
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
//realloc 사용
//최대 크기를 넘는 경우, 에러표시후 프로그램 종료
void stack_full( dstack_t *s)
{
	//implement
}

//동적 메모리 할당에 실패할 경우 호출
void memory_error()
{
	fprintf(stderr,"memory alloc fail");
	exit(EXIT_FAILURE);
}

//테스트용 함수
//스택의 내용을 프린트함
void print_stack(dstack_t *s)
{
	int i;
	printf("\n---  capa: %d ---\n", s->capa);
	for(i=s->top; i >=0 ; i--)
	{
		if(i== s->top)
			printf("%d <-- top: %d\n", s->stack[i],s->top);
		else
			printf("%d\n",s->stack[i]);
	}
	if(s->top == -1)
		printf("-- bottom <-- top: %d --\n", s->top);
	else
		printf("-- bottom --\n");
}