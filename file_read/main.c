//파일 읽기
//한줄씩 읽어서 표시함
#include <stdio.h>

main()
{
    FILE *fp;
    char s[256];
    int i = 1;

    fp = fopen("abc.txt", "r");
    if(fp == NULL)
        return;
    while(feof(fp) == 0 )
    {
        fgets(s, 255, fp);
        printf("%04d : %s", i, s);
        i++;
    }
    fclose(fp);
}
