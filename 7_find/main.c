//무작위 배열에서 7찾는 알고리즘

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[] = {9,5,6,4,8,7,0,4,2};
    int i;
    for(i = 0; i < 9; i++)
        if(a[i] == 7)
            printf("7 발견!! %d 번째에 있었다.", i + 1);
}
