//숫자를 * 갯수로 표현
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[] = {5,4,3,6,1};
    int i, j;

    printf("현재 배열에 있는 값 5,4,3,6,1 \n\n");

    for(j = 0; j<5; j++)
    {
        printf("a[%d] = %d ", j, a[j]);
        for(i = 1; i <= a[j]; i++)
            printf("*");
        printf("\n");
    }

    return 0;
}
