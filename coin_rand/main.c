//동전 던지기 게임

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

main()
{
    int you;
    int coin;
    char aspect[][10] = {"", "앞면", "뒷면"};
    srand(time(NULL));
    printf("앞면은 1, 뒷면은 2, 종료는 다른 값을 입력하세요.\n");
    while(1)
    {
        coin = rand() % 2 +1;
        printf("동전을 던졌습니다. 앞면? 뒷면? : ");
        scanf("%d", &you);
        if(you < 1 || you > 2)
            break;
        else
        {
            printf("사용자 : %s 동전 : %s\n", aspect[you], aspect[coin]);
            printf("%s\n", (you == coin)? "맞음!" : "꽝!");
        }
        printf("\n");
    }
}
