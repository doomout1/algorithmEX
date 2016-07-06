#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct _STRLIST
{
    int id;
    char name[128];
    struct _STRLIST *next;
} STRLIST;

void enterData(STRLIST *);
void listData(STRLIST *);
STRLIST *getData(STRLIST *, int);
STRLIST *getLastData(STRLIST *);
STRLIST *addData(STRLIST *, STRLIST*);
STRLIST *insertData(STRLIST *, int, STRLIST*);
STRLIST *deleteData(STRLIST *, int);
STRLIST *clearData(STRLIST *);

int main()
{
    STRLIST *listtop = NULL;
    STRLIST inputData;
    int index;
    char cmd[20] = "";
    //테스트 용으로 미리 요서를 입력해둔다.
    STRLIST testdata[3] = {{1,"kim"}, {2, "lee"}, {3, "jjang"}};
    listtop = addData(listtop, testdata);
    listtop = addData(listtop, testdata+1);
    listtop = addData(listtop, testdata+2);
    printf("[연결 리스트 테스트]\n");
    printf("명령 = list/add/insert/delete/clear/quit\n");
    //quit가 입력될 때까지 명령 처리를 계속 한다.
    while(strcmp(cmd, "quit") != 0)
    {
        printf("명령 : ");
        scanf("%s", cmd);

        //목록 표시
        if(strcmp(cmd, "list") == 0)
        {
            listData(listtop);
        }
        else if(strcmp(cmd, "add") == 0) //데이터 추가
        {
            enterData(&inputData);
            listtop = addData(listtop, &inputData);
        }
        else if(strcmp(cmd, "insert") == 0) //데이터 삽입
        {
            printf("몇 번째 데이터 다음에 삽입하겠습니까? ");
            scanf("%d", &index);
            enterData(&inputData);
            listtop = insertData(listtop, index, &inputData);
        }
        else if(strcmp(cmd, "delete") == 0) //데이터 삭제
        {
            printf("몇 번째 데이터를 삭제하겠습니까? ");
            scanf("%d", &index);
            listtop = deleteData(listtop, index);
        }
        else if(strcmp(cmd, "clear") == 0) //데이터 모두 삭제
        {
            listtop = clearData(listtop);
        }
    }
    listtop = clearData(listtop);
    return 0;
}
//데이터 입력
void enterData(STRLIST *p)
{
    printf("추가할 데이터를 입력하세요.\n");
    printf("ID : ");
    scanf("%d", &(p->id));
    printf("이름 : ");
    scanf("%s", &(p->name));
}
//목록 표시
void listData(STRLIST *p)
{
    int i = 1;
    printf("No. 데이터\n---- ---- \n");
    while(p != NULL)
    {
        printf("%04d id = %d 이름 = %s\n", i, p->id, p->name);
        p = p->next;
        i++;
    }
}
// index번째 요소를 취함
STRLIST *getData(STRLIST *p, int index)
{
    int i;
    if(index < 1)
        return NULL;
    for(i=1; i<index; i++)
    {
        p = p->next;
        if(p == NULL && i<index)
        return NULL;
    }
    return p;
}
//마지막 요소를 취함
STRLIST *getLastData(STRLIST *p)
{
    if(!p)
        return NULL;
    while(p->next != NULL)
        p = p->next;
    return p;
}
//요소의 끝에 추가
STRLIST *addData(STRLIST *listtop, STRLIST *newdata)
{
    STRLIST *newitem, *p;
    p = getLastData(listtop);

    newitem = (STRLIST *)malloc(sizeof(STRLIST));
    newitem->id = newdata->id;
    strcpy(newitem->name, newdata->name);
    newitem->next = NULL;
    if(p == NULL)
        return newitem;
    p->next = newitem;
    return listtop;
}
//index 번째에 요소를 삽입한다.
STRLIST *insertData(STRLIST *listtop, int index, STRLIST *newdata)
{
    STRLIST *p, *newitem;
    p = getData(listtop, index);

    newitem = (STRLIST *)malloc(sizeof(STRLIST));
    newitem -> id = newdata->id;
    strcpy(newitem->name, newdata->name);
    if(p == NULL)
    {
        newitem->next = listtop;
        return newitem;
    }
    newitem -> next = p->next;
    p->next = newitem;
    return listtop;
}
//index번째의 요소를 삭제한다.
STRLIST *deleteData(STRLIST *listtop, int index)
{
    STRLIST *previtem, *delitem, *nextitem;
    if(index<1 || listtop == NULL)
        return listtop;
    if(index == 1)
    {
        delitem = getData(listtop, index);
        nextitem = delitem->next;
        free(delitem);
        return nextitem;
    }
    previtem = getData(listtop, index-1);
    delitem = previtem -> next;
    nextitem = delitem -> next;
    free(delitem);
    previtem -> next = nextitem;
    return listtop;
}
//모든 요소를 삭제한다.
STRLIST *clearData(STRLIST *p)
{
    while(p)
        p = deleteData(p, 1);
    return p;
}
