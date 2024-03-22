#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
선언할 구조체
학생 / 충전 / 사용


학생 구조체 선언해봅시다.
저장할 정보는
=> 학번 / 이름 / 연락처 / 충전 횟수 / 사용횟수 / 현재 잔액

충전 구조체도 선언해봅시다.
=> no / 금액

사용 구조체도 선언해봅시다.
=> no / 금액

=====

점검차 실습 내용(3~4주차 천천히 만들어볼 프로그램)

1. 초기설정

1) 개요

C로 만들어보는 HGU페이

* HGU를 사용할 학생에 대한 정보 저장
* 각 학생의 입금 내역에 대해서 저장
* 각 학생의 사용 내역에 대해서 저장

2) 선언할 구조체

a. 학생
학번, 이름, 연락처,  충전 횟수, 사용횟수, 현재 잔액

b. 충전
학생배열의 순번, 금액

c. 사용
학생배열의 순번, 금액

[주의사항]
구조체 내용은 이후 확대기능에 따라 일부 변동 될 수도 있습니다.
각 구조체 배열은 파일에 각각 저장하고 / 불러올 수 있습니다.

바뀐 조건1
- 처음 프로그램을 시작했을때, 파일에 있는 모든 정보를 불러와서 배열에 저장해주세요.
- 배열에 변동사항이 생겼을때 파일에도 저장해주세요.

*/

// 학생 정보를 담아줄 구조체 선언
typedef struct _student {
    char snum[20]; // 학번
    char name[20]; // 이름
    char phone[20]; // 연락처
    int t_input; // 충전 횟수
    int t_spend; // 사용 횟수
    int balance // 잔액
} Student;

//a. 학생
//학번, 이름, 연락처,  충전 횟수, 사용횟수, 현재 잔액

int loadData(Student *s[]){
    int count = 0, i = 0;
    FILE *fp;
    fp = fopen("student2.txt", "rt");
    for(i=0; i < 100; i++){
        fscanf(fp, "%s", s[i]->snum);
        if(feof(fp)) break;
        fscanf(fp, "%s", s[i]->name);
        fscanf(fp, "%d", &s[i]->t_input);
        fscanf(fp, "%d", &s[i]->t_spend);
        fscanf(fp, "%d", &s[i]->balance);
    }
    fclose(fp);
    printf("=> 로딩 성공!\n");
    return i;
}

//b. 충전
//학생배열의 순번, 금액

int 


int main(void)
{
    Student s;
    Student *splist[100];
    


    return 0;
}