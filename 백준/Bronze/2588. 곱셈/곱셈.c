#include <stdio.h>

int main (void)
{
    int a,b;
    scanf("%d%d", &a, &b);
    
    int b_1 = b%10;
    int b_10 = ((b-b%10)%100)/10;
    int b_100 = b/100;
    
    printf("%d\n", a*b_1);
    printf("%d\n", a*b_10);
    printf("%d\n", a*b_100);
    printf("%d\n", a*b);
    
    return 0;
}