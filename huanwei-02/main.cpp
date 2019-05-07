#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
    int n;
    int del[36];
    memset(del, 0, sizeof(del));
    int x[36],y[36];
    scanf("%d", &n);
    for(int i=0;i<n;i++)
        scanf("%d%d",&x[i], &y[i]);
    if(n == 0)
        printf("0\n");
    else
    {
        int maxt = 1, cnt = 0;
        for(int i=0;i<n;i++)
        {
            if(del[i])  continue;
            cnt ++;
            int cnt1 = 0;
            for(int j=0;j<n;j++)
            {
                if(del[j])  continue;
                if(x[i] == x[j])    cnt1++;
            }
            int cnt2 = 0;
            for(int j=0;j<n;j++)
            {
                if(del[j])  continue;
                if(y[i] == y[j])    cnt2++;
            }
            if(cnt2 > cnt1) maxt = 2;
            int cnt3 = 0;
            for(int j=0;j<n;j++)
            {
                if(del[j])  continue;
                if(x[i]-x[j] == y[i]-y[j])    cnt3++;
            }
            if(cnt3 > cnt1 && cnt3 > cnt2) maxt = 3;
            int cnt4= 0;
            for(int j=0;j<n;j++)
            {
                if(del[j])  continue;
                if(x[i]+y[i] == x[j]+y[j])    cnt4++;
            }
            if(cnt4 > cnt3 && cnt4>cnt3 && cnt4>cnt2 && cnt4 > cnt1)    maxt = 4;
            del[i] = 1;
            if(maxt == 1){
                for(int j=0;j<n;j++)
                {
                    if(del[j])  continue;
                    if(x[i] == x[j])    del[j] = 1;
                }
            }else if(maxt == 2){
                for(int j=0;j<n;j++)
                {
                    if(del[j])  continue;
                    if(y[i] == y[j])    del[j] = 1;
                }
            }else if(maxt == 3){
                for(int j=0;j<n;j++)
                {
                    if(del[j])  continue;
                    if(x[i]-x[j] == y[i]-y[j])    del[j] = 1;
                }
            }else if(maxt == 4){
                for(int j=0;j<n;j++)
                {
                    if(del[j])  continue;
                    if(x[i]+y[i] == x[j]+y[j])    del[j] = 1;
                }
            }
        }
         printf("%d\n",cnt);
    }

    return 0;
}
