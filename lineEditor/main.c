#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_S 20 //한 행의 문자수

/*
test.txt 내용

abcde
fghijklmn
opqrstu
vwxyz

*/

int main()
{
    char (*buf)[MAX_S] = NULL;
    int lines = 5;
    FILE *fp;
    int i, n = 0;

    buf=(char(*)[MAX_S])malloc(sizeof(char) * lines * MAX_S); //20 * 5로 된 이차원 배열

    fp=fopen("test.txt", "r");
    if(fp == NULL)
        return 0;
    while(fgets(buf[n], MAX_S - 1, fp)) //파일 데이터를 버퍼에 저장
        n++;
    fclose(fp);

    for(i=0; i<n; i++)
        printf("%02d: %s", i, buf[i]); //fgets() 함수로 읽어들이 문자열에는 줄 바꿈 문자가  있으니 \n은 필요 없음

    free(buf);
    buf = NULL;

    return 0;
}
