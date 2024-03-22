#include <stdio.h>
/*2024-1-2
int main(void){
    //이름을 입력받고
    //분반을 입력받고
    //이름과 분반을 출력하는 코드

    char name[100];
    int apart = 0;

    scanf("%s",&name);
    scanf("%d",&apart);

    printf("name : %s \nclass part : %d \n", name, apart);
}
*/
/*
int main(void){
    int num = 0;

    scanf("%d", &num);

    for(int i = num; i != 0; i--){
        for(int j = 0; j <= num-i; j++){
            printf("* ");
        }
        printf("\n");
    }

    for(int i = num-1; i != 0; i--){
        for(int j = i; j != 0; j--){
            printf("* ");
        }
        printf("\n");
    }

    return 0;
}*/
/*
struct number{
    int kor;
    int math;
    int eng;
    char name[20];
    double avg;
    int sum;
} num;

int main (void){
    struct number num;

    //scanf("%s",num.name);
    scanf("%d %d %d", &num.kor, &num.math, &num.eng);
    num.sum = num.kor + num.math + num.eng;
    num.avg = num.sum / 3.0;

    printf("total : %d\naverage : %.1f",num.sum, num.avg);
}*/

/*
1. 성적을 입력하는 함수(createScore)만들기
파라미터는 student / 리턴은 int로(성공은 1 / 실패는 0)
메인함수에서 성적임렵함수 호출해서 입력해보기

2. 성적 조회하는 함수(readScore)

3. 성적을 수정하는 함수

4. 성적을 삭제하는 함수
*/

typedef struct Student{
    char id[20];
    char name[20];
    int Score[3];
} Student;

int createScore(Student *s){
    char title[3][20] = {"Kor", "Eng", "Math"};
    int i = 0;

    printf("Student Num : ");
    scanf("%s", s->id);

    printf("Student name : ");
    scanf("%s", s->name);

    for(int i=0; i<3; i++){
        printf("%s : ",title[i]);
        scanf("%d", s->Score[i]);

        if(s->Score[i] < 0 || s->Score[i] > 100){
            printf("오류\n");
            i--;
        }
    }
}

int readScore(Student *s){

}

int updateScore(Student *s){
    int result_val = 0;

    result_val = createScore(s);

    if(result_val > 0){

    }
    return 1;
}

int deletScore(Student *s){
    int i = 0;
    int t_answer;
    scanf("%d", &t_answer);

    if(t_answer == 1){

    }
}

int seletMenu(){
    int press = 0;

    scanf("%d",&press);

    if(press == 1) return 1;
    else if(press == 2) return 2;
    else if(press == 3) return 3;
    else if(press =- 4) return 4;
    else return 5;
} 

int main (void){
    Student score;
    int key = 0;

    while(key!=5){
        key = seletMenu();

        if(key == 1) createScore();
        else if()
    }
}
 
