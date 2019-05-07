#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    printf("n e\n");
    printf("- -----------\n");
    printf("0 1\n");
    printf("1 2\n");
    printf("2 2.5\n");
    double mul = 1.0*2;
    double e = 1.0 + 1.0 + 1.0/2;
    for(int i=3;i<=9;i++)
    {
        mul *= i;
        e += 1.0/mul;
        printf("%d %.9lf\n", i, e);
    }
    return 0;
}
