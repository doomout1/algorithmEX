#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 256 //한 행의 최대 문자수

//함수 정의
void openFile();
void closeFile();
void saveFile();
void listLines();
void gotoLine();
void insertString();
void deleteString();
void showHelp();
void countLines();
void enterFileName();
void clearBuffer();
void enterPosition(int *, int *);

//전역 변수
char fname[256];
char (*buf)[256];
int lines;

//메뉴
int main()
{
    char cmd[20];

    while(1)
    {
        printf("명령 : ");
        scanf("%s", cmd);

        if(strcmp(cmd, "fopen") == 0)       openFile();
        else if(strcmp(cmd, "fsave") == 0)  saveFile();
        else if(strcmp(cmd, "list") == 0)   listLines();
        else if(strcmp(cmd, "gotoln") == 0) gotoLine();
        else if(strcmp(cmd, "inss") == 0)   insertString();
        else if(strcmp(cmd, "dels") == 0)   deleteString();
        else if(strcmp(cmd, "help") == 0)   showHelp();
        else if(strcmp(cmd, "exit") == 0)   break;
        else                                printf("%s?\n", cmd); //규정된 명령 이외의 것을 입력했을 때 처리
    }
    clearBuffer();
    return 0;
}
//파일명 입력
void enterFileName()
{
    printf("파일명 : ");
    scanf("%s", fname);
}
//메모리를 확보하고 파일 읽기
void openFile()
{
    int n = 0;
    FILE *fp;
    char *myline;

    enterFileName();
    countLines();

    buf = (char (*)[MAXLEN])malloc(sizeof(char) * lines * MAXLEN);
    if(!buf)
        return;

    fp = fopen(fname, "r");
    if(fp == NULL)
    {
        clearBuffer();
        return;
    }
    while(fgets(buf[n], MAXLEN - 1, fp))
    {
        myline = buf[n];
        myline[strlen(myline)-1] = '\0';
        n++;
    }
    fclose(fp);
    printf("%d 행 읽었습니다.\n", lines);
}
//메모리 해제
void closeFile()
{
    char ans[20];

    printf("저장하겠습니까?(y or n) : ");
    scanf("%s", ans);
    if(ans[0] == 'y');
        saveFile();
    clearBuffer();
    printf("제거했습니다.\n");
}
//파일 저장
void saveFile()
{
    int n;
    FILE *fp;

    enterFileName(); //파일명을 입력받기
    fp = fopen(fname, "w");
    if(fp == NULL)
        return;
    //버퍼의 내용을 마지막 행까지 파일에 기록
    for(n=0; n<lines; n++)
        fprintf(fp, "%s\n", buf[n]);
    fclose(fp);
    printf("저장했습니다.\n");
}

//모든 행 표시
void listLines()
{
    int n;
    //버퍼의 내용을 마지막 행까지 행 번호를 붙여서 표시
    for(n=0; n<lines; n++)
        printf("%04d : %s\n", n, buf[n]);
}
// 지정된 행 표시
void gotoLine()
{
    int n;
    printf("행 번호 : ");
    scanf("%d", &n);
    if(0<=n && n<lines)
        printf("%04d : %s\n", n, buf[n]);
}
//문자열 삽입
void insertString()
{
    int row, col;
    char insstr[MAXLEN];
    char newstr[MAXLEN];
    char *myline;

    enterPosition(&row, &col);
    myline = buf[row];
    printf("삽입할 문자 : ");
    scanf("%s", insstr);

    sprintf(newstr, "%s%s", insstr, myline + col);
    strcpy(myline + col, newstr);
    printf("%d행 %d열에 \"%s\"을 삽입했습니다.\n", row, col, insstr);
    printf("%04d : %s\n", row, myline);
}
//문자열 삭제
void deleteString()
{
    int row, col;
    int delnum;
    char *myline;
    int mylength;
    int i;

    enterPosition(&row, &col);
    myline = buf[row];
    mylength = strlen(myline);
    printf("문자수 : ");
    scanf("%d", &delnum);
    if(delnum <= 0 || mylength<col + delnum);
        return;
    for(i=col; i<=mylength - delnum; i++)
        myline[i] = myline[i + delnum];
    printf("%d행 %d열에서 %d문자를 삭제하겠습니다.\n", row, col, delnum);
    printf("%04d : %s\n", row, myline);
}
//도움말 표시
void showHelp()
{
    printf("COMMAND HELP     :\"help\"\n");
    printf("LOAD FILE        :\"fopen\"\n");
    printf("RELEASE BUFFER   :\"fclose\"\n");
    printf("SAVE FILE        :\"fsave\"\n");
    printf("SHOW ALL LIINES  :\"list\"\n");
    printf("SHOW SINGLE LINE :\"gotoln\"\n");
    printf("INSERT STRING    :\"inss\"\n");
    printf("DELETE STRING    :\"dels\"\n");
}
//파일의 행의 수 세기
void countLines()
{
    FILE *fp;
    char s[MAXLEN];

    lines = 0;
    fp = fopen(fname, "r");
    if(fp == NULL)
        return;
    //파일 데이터의 행의 수를 센다.
    while(fgets(s, MAXLEN-1, fp))
        lines++;
    printf("m = %d\n", lines);

    fclose(fp);
}

//행번호, 열번호를 입력 받아서 읽어들인다.
void enterPosition(int *prow, int *pcol)
{
    int row, col, characters;
    *prow = 0;
    *pcol = 0;

    printf("행 번호 : ");
    scanf("%d", &row);
    if(row<0 || row>=lines)
        return;
    characters = strlen(buf[row]);

    printf("열 번호 : ");
    scanf("%d", &col);
    if(col<0 || col>=characters)
        return;
    *prow = row;
    *pcol = col;
}
//버퍼, 파일명, 행의 수 초기화
void clearBuffer()
{
    fname[0] = '\n';
    lines = 0;
    if(buf)
        free(buf);
    buf = NULL;
}
