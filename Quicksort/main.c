/*
    퀵정렬 - 기준 값을 정하고 그것보다 큰 수와 작은 수의 그룹으로 나눈다.
    그리고 각 그룹들에 대해서도 똑같은 작업을 반복해간다.
    1. 기준값을 정한다.
    2. 앞에서 부터는 기준값보다 큰 수를, 뒤에서 부터는 기준보다 작은 수를 찾는다. 발견하면 서로 바꾼다.
    3. 충돌한 곳을 경계로 작은 그룹과 큰 그룹으로 나누고, 1~2번을 반복한다.
*/

#include <stdio.h>

void qs(int *, int, int);
void swap(int *, int *);
void printData(int *);

int main()
{
    int a[] = {4,8,6,5,2,1,3,9,7};
    printData(a);
    qs(a, 0, 8);
    return 0;
}

void qs(int *a, int first, int last)
{
    int i, j, x;

    i = first;
    j = last;
    x = (a[i]+a[j]) / 2; //기준값 = 처음과 끝 값의 평균으로 정한다.
    while(1)
    {
        while(a[i] < x) //처음부터 시작
            i++;
        while(a[j] > x) //끝부터 시작
            j--;
        if(i >= j) //서로 만나면 정지
            break;
        swap(a+i, a+j);
        printf("범위 : %d-%d 기준값 : %d [%d]와 [%d]를 바꿈 \n", first, last, x, i, j);
        printData(a);
        i++;
        j--;
    }
    if(first < i-1)
        qs(a, first, i-1);
    if(j+1 < last)
        qs(a, j+1, last);
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
    for(i=0; i<9; i++)
        printf("%2d ", a[i]);
    printf("\n");
}
