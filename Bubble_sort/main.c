/*
    버블정렬 - 서로 이웃하는 요소를 비교해서 오른쪽이 작으면 두 요소를 바꾸는 작업을
            왼쪽부터 순서대로 수행하고,큰 수를 오른쪽으로 몰아간다.
    배열 a[]의 요소를 오름차순으로 정렬한다.
*/

#include <stdio.h>

void swap(int *, int *);
void printData(int *);

int main()
{
    int a[] = {2,4,1,3};
    int n = 4;
    int i, j;

    printData(a);

    for(j=n-1; j>=0; j--)
    {
        for(i=0; i<j; i++)
        {
            if(a[i] > a[i+1])
            {
                swap(a+i, a+i+1);
                printf("[%d]와 [%d]를 바꿈\n",i, i+1);
                printData(a);
            }
        }
    }

    return 0;
}

void swap(int *y, int *z)
{
    int t;

    t = *y;
    *y = *z;
    *z = t;
}

void printData(int *a)
{
    int i;
    for(i=0; i<=3; i++)
        printf("%2d", a[i]);
    printf("\n");
}
