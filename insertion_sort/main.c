/*
    삽입정렬 - 삽입하고 싶은 수를 따로 저장한 뒤 하나하나 비교해서 크면 한칸씩 이동 시킨다.
               작은 수가 나오면 작은 수의 오른쪽에 삽입한다.(오름차순 기준)
*/

#include <stdio.h>

void printData(int *);

int main()
{
    int a[] = {9,6,5,1,2};
    int n = 5;
    int i,j,t;

    printData(a);
    for(i=1; i<n; i++)
    {
        t = a[i];
        for(j=i-1; j>=0; j--)
        {
            if(a[j] > t)
                a[j+1] = a[j];
            else
                break;
        }
        a[j+1] = t;
        if(j+1 != i)
        {
            printf("[%d] 의 위치에 [%d]을 삽입\n", j+1, i);
            printData(a);
        }
    }
    return 0;
}

void printData(int *a)
{
    int i;
    for(i=0; i<5; i++)
        printf("%2d ", a[i]);
    printf("\n");
}
