//년 월을 입력하면 그 월을 보여주는 프로그램

#include <stdio.h>
#include <stdlib.h>

void getYearMonth(int *, int *);
int getMonthDays(int, int);
int getWeekday(int, int, int);
void printCalendar(int, int);

int main()
{
    int year;
    int month;
    int days;
    int weekday;

    //1. 입력 데이터를 읽어들이는 함수
    getYearMonth(&year, &month);

    //2. 월의 일수를 결정하는 함수
    days = getMonthDays(year, month);

    //3. 첫째날의 요일을 결정하는 함수
    weekday = getWeekday(year, month, 1);

    printf("서기 %d년 %d월\n\n", year, month);
    //4. 달력을 표시하는 함수
    printCalendar(days, weekday);
}

//입력 데이터 읽기
void getYearMonth(int *py, int *pm)
{
    printf("달력을 표시합니다.\n");
    printf("연도와 월을 스페이스로 구분하여 입력해주세요.\n");
    scanf("%d %d", py, pm);
    return;
}

//월의 일수 구하기
int getMonthDays(int y, int m)
{
    int dm;

    switch(m)
    {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            dm = 31;
            break;
        case 4: case 6: case 9: case 11:
            dm = 30;
            break;
        case 2:
            if(y%4==0 && y%100!=0 || y%400==0)
                dm = 29;
            else
                dm = 28;
            break;
        default:
            dm = 0;
    }
    return dm;
}

//첫째 날의 요일 구하기
int getWeekday(int y, int m, int d)
{
    int w;  //요일 번호를 저장할 지역 변수

    //1월과 월의 경우 월(m)에 12를 더하고, 연도(y)에서 1을 뺍니다.
    if(m == 1 || m == 2)
    {
        y--;
        m += 12;
    }
    w = (y + y/4 - y/100 + y/400 +(13 * m + 8)/5 + d) % 7;

    return w;
}

void printCalendar(int dm, int dw)
{
    int n, d;
    printf("----------------------------\n");
    printf(" Sun Mon Tue Wed Thu Fri Sat\n");
    printf("----------------------------\n");

    for(n = 0; n < dw; n++)
    {
        printf("    ");
    }
    for(d = 1; d <= dm; d++)
    {
        printf("  %2d", d);
        if(n % 7 == 6 && d != dm)
            printf("\n");
        n++;
    }
    printf("\n----------------------------\n");
    return;
}
