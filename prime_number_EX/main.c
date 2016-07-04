//1~50 중 소수 구하기
#include <stdio.h>
#define PRIME_MAX 50 //소수 최대값

int main()
{
    char num[PRIME_MAX + 1];
    int i , j;

    //배열 초기화
    for(i=0; i<=PRIME_MAX; i++)
        num[i] = 0;

    //소수인지 판별
    for(i=2; i<=PRIME_MAX; i++)
    {
        if(num[i] == 0)
        {
            printf(" %d", i);
            //i의 배수는 1로 변경해서 지운다.
            for(j=2*i; j<=PRIME_MAX; j+=i)
                num[j] = 1;
        }
    }
    printf(" \n");
    return 0;
}
