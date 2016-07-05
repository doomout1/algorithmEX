#include <stdio.h>
#define PRIME_MAX 10000 //미리 준비한 소수의 최대

int main()
{
    char num[PRIME_MAX + 1];
    int primelist[PRIME_MAX];
    int m, i, j, k;
    printf("소인수 분해할 수를 입력하세요 : ");
    scanf("%d", &m);

    //배열의 초기화
    for(i=0; i<=PRIME_MAX; i++)
        num[i] = 0;

    //소수를 구한다.
    //m 까지의 소수를 구하고 작은 수 부터 배열에 저장한다.
    k = 0;
    for(i=2; i<=PRIME_MAX; i++)
    {
        if(num[i] == 0)
        {
            primelist[k] = i;
            k++;
            for(j=2*i; j<=PRIME_MAX; j+=i)
                num[j] = 1;
        }
    }

    //소인수를 구한다.
    i=0;
    while(m != 1)
    {
        while(m % primelist[i] == 0)
        {
            printf(" %d", primelist[i]);
            m = m/primelist[i];
        }
        i++;
    }
    printf("\n");
    return 0;
}
