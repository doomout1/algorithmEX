#include <stdio.h>
#include <stdlib.h>

int main()
{
   int i, n;
   char a[] = "DOG";
   char b[10];

   n = strlen(a);
   for(i = n-1; i >= 0; i--)
        b[n-1-i] = a[i];
    b[n] = '\0';
    printf("%s를 거꾸로 읽으면 %s",a,b);
}
