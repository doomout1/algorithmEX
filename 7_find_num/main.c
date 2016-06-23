//7을 발견 하고 갯수를 표시하자

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[] = {1,2,5,4,7,9,5,4,2,4,6,4,4,6,7,11,6,1,7,7,4,1};
    int n = 0;
    int i;
    for(i = 0; i < 23; i++){
        if(a[i] == 7){
            printf("7 발견!! %d 번째에 숨어 있었다!\n", i+1);
            n = 1; //7 발견 못한다면.....
        }
    }
    if(n != 1)
        printf("7을 발견 못함\n");

}
