#include <stdio.h>
#include <iostream>
#define N 101
using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    int T;
    string milkName, cheapest;
    int cost, vol, day, cheapVol;
    double average, cheapCost;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        cheapest = "";
        for(int i=0;i<n;i++)
        {
            cin >> milkName >> cost >> vol;
            if(vol < 200)   continue;
            day = vol/200;
            if(day > 5) day = 5;
            average = cost*1.0/day;
            if(cheapest == "")
            {
                cheapest = milkName;
                cheapCost = average;
                cheapVol = vol;
            }else{
                if(average < cheapCost)
                {
                    cheapest = milkName;
                    cheapCost = average;
                    cheapVol = vol;
                }else if( average == cheapCost && vol > cheapVol)
                {
                    cheapest = milkName;
                    cheapCost = average;
                    cheapVol = vol;
                }
            }
        }
        cout << cheapest << endl;
    }
    return 0;
}