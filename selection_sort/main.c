/*
    단순 정렬
    a[0]을 기준으로 잡고, 그 요소와 오른쪽의 요소와 비교해서 순서가 다르면 바꾼다.
    이 소스는 4개의 랜덤한 배열을 내림차순으로 정렬한다.
*/

#include <stdio.h>

void swap(int *, int *);
void printData(int *);

int main()
{
    int a[] = {2,4,3,5};
    int n = 4;
    int i, j;

    printData(a);

    for(j=0; j<=n-2; j++)
    {
        for(i=j+1; i<=n-1; i++)
        {
            if(a[j] < a[i])
            {
                swap(a+i, a+j);
                printf("[%d] 와 [%d]를 바꿈\n", i, j);
                printData(a);
            }
        }
    }
    return 0;
}

void swap(int *y, int *z)
{
    int tmp;
    tmp = *y;
    *y = *z;
    *z = tmp;
}

void printData(int *a)
{
    int i;
    for(i=0; i<4; i++)
        printf("%2d", a[i]);
    printf("\n");
}
