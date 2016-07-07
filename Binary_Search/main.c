/*
    이진 검색 - 미리 정렬되어 있다는 가정에 특정 값을 찾는 알고르즘이다.
    또한 같은 수가 여러개 있는 경우는 적용할 수 없다.
    정렬된 데이터를 좌우 둘로 나눠서 목적하는 값의 검색 범위를 좁혀가는 방법이다.
*/

#include <stdio.h>

int main()
{
    int a[] = {1,4,13,44,52,55,67,88,93};
    int n = 9;
    int i,x,lo,hi,m;

    printf("a[] = {");
    for(i=0; i<9; i++)
        printf("%2d ", a[i]);
    printf("}\n");
    printf("찾고 싶은 데이터를 입력해주세요.");
    scanf("%d", &x);

    lo =0 ;
    hi = n-1;
    m = (lo+hi)/2;
    while(lo <= hi)
    {
        if(a[m] == x)
            break;
        else if(a[m] < x)
            lo = m+1;
        else
            hi = m-1;
        m = (lo+hi)/2;
    }
    if(a[m] == x)
        printf("%d는 [%d]에 있습니다. \n",x,m);
    else
        printf("%d는 없습니다.\n",x);
    return 0;
}
