//
//  main.c
//  phoneAddress
//
//  Created by KIMJOOHWEE on 13. 5. 21..
//  Copyright (c) 2013년 KIMJOOHWEE. All rights reserved.
//
/*
• 전화번호부 만들기 (1)
- 다음형식으로 입력받은 데이터를 메모리에 저장 /
전체를 출력하는 프로그램 만들기
- (1) 데이터를 사용자로부터 반복적으로 입력받음
­– 입력데이터: (이름 / 전화번호 / 주소 형식) 정호영;010-1111-3333;삼평동 414 NEXT
- (2) 입력은 nobody를 이름으로 받으면 종료
- (3) 입력받은 데이터를 출력 • 제출내용
- source + readme.txt 함께 제출
- readme.txt 에는 자료구조 및 처리 알고리즘 설명
*/

typedef struct phone_data * phone_data_ptr;
struct phone_data{
    int name;
    int phone_number;
    int address;
    phone_data_ptr next_data_ptr;
};


#include <stdio.h>
#include <stdlib.h>

phone_data_ptr createHead();
void saveNewData(phone_data_ptr prev, char new_name, int new_phone_number, char new_address);
void addInfo(phone_data_ptr head_data, char new_name, int new_phone_number, char new_address);
phone_data_ptr searchLastPtr(phone_data_ptr head_data);

int main()
{
    char scaned_name, scaned_address;
    int scaned_phone_number;
    phone_data_ptr head = createHead();
    
    while(scaned_name != "nobody")
    {
        printf("name");
        scanf("%d",&scaned_name);
        if (scaned_name != 'nobody')
        {
            printf("phone number");
            scanf("%d",&scaned_phone_number);
            printf("address");
            scanf("%d",&scaned_address);
        }
        else
            break;
        addInfo(head, scaned_name,scaned_phone_number,scaned_address);
    }

}

void addInfo(phone_data_ptr head_data, char new_name, int new_phone_number, char new_address)
{
    phone_data_ptr prev_ptr = searchLastPtr(head_data);
    saveNewData(prev_ptr, new_name,new_phone_number,new_address);    
}

phone_data_ptr searchLastPtr(phone_data_ptr head_data)
{
    phone_data_ptr search = head_data->next_data_ptr;
    if (search == NULL)
    {
        return head_data;
    }
    else
    {
        while(search->next_data_ptr != NULL)
        {
            search = search->next_data_ptr;
        }
        return search;
    }
}

void saveNewData(phone_data_ptr prev, char new_name, int new_phone_number, char new_address)
{
    phone_data_ptr new_data = (phone_data_ptr)malloc(sizeof(phone_data_ptr));
    
    prev->next_data_ptr = new_data;
    new_data->name = new_name;
    new_data->address = new_address;
    new_data->phone_number = new_phone_number;
    new_data->next_data_ptr = NULL;
}

phone_data_ptr createHead()
{
    phone_data_ptr head = (phone_data_ptr) malloc(sizeof(phone_data_ptr));
    head->next_data_ptr = NULL;
    return head;
}