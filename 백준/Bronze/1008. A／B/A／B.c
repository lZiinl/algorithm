#include <stdio.h>

int main(void)
{
    int a,b;
    scanf("%d%d", &a, &b);
    
    double result = (double)a/(double)b;
    printf("%.12f", result);
    
    return 0;
}