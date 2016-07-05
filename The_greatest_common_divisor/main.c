#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b; //최대 공약수를 구할 두 개의 자연수
    int r = 1; //나머지를 넣을 변수인데 그냥 냅두면 조건식이 안됨 그래서 1로 초기화
    int c;

    printf("두 개의 자연수의 최대 공약수를 구합니다.\n");
    printf("a = ");
    scanf("%d", &a);
    printf("b = ");
    scanf("%d", &b);

    //0 이하로 입력한 경우의 처리
    if(a<=0 || b<=0)
    {
        printf("자연수가 아닙니다.\n");
        exit(1);
    }

    printf("%d %d 의 최대 공약수는 ",a, b);

    // a<b의 경우 a와 b의 값을 바꿈
    if(a<b)
    {
        c = a;
        a = b;
        b = c;
    }

    //최대 공약수를 구한다.
    while(r != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    printf("%d 입니다.\n", a);
    return 0;
}
