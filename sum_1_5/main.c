//1~5까지 더해보자.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i , n = 0;
    for(i = 1; i <= 5; i++)
        n += i;
    printf("%d\n", n);
}
