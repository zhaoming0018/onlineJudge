#include <iostream>
#include <stdio.h>
#include <string.h>
#define MAX 1000001000
using namespace std;
int value[MAX], kind[200];

int main()
{
    int n,m;
    scanf("%d%d", &m, &n);
    memset(value, 0, sizeof(value));
    for(int i=0;i<n;i++)
        scanf("%d", &kind[i]);

    return 0;
}
