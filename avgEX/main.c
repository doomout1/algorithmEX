#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[] = {80,60,70,90};
    int i, sum = 0;
    for(i = 0; i < 4; i++)
        sum += a[i];
    printf("평균은 %d입니다\n", sum/4);
    return 0;
}
