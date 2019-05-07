#include <stdio.h>

double max(double x, double y, double z)
{
    double res = x;
    res = y>res?y:res;
    res = z>res?z:res;
    return res;
}

double min(double x, double y, double z)
{
    double res = x;
    res = y<res?y:res;
    res = z<res?z:res;
    return res;
}

int main()
{
    int n;
    double vh = 1.0/120, vm = 0.1, vs = 6; // 时针，分针，秒针的速度
    double re_hm = 360/(vm-vh), re_hs = 360/(vs-vh), re_ms = 360/(vs-vm); // 再次重合所需时间
    while(scanf("%d",&n) && n!=-1)
    {
        double ans = 0;
        double n_hm = n/(vm-vh), n_hs = n/(vs-vh), n_ms = n/(vs-vm); // 拉开n度所需时间
        double n_hm_2 = (360-n)/(vm-vh), n_hs_2 = (360-n)/(vs-vh), n_ms_2 = (360-n)/(vs-vm); //缩小到n度所需时间
        for(double s_hm=0;s_hm<43200;s_hm+=re_hm)
        {
            for(double s_ms=0;s_ms<43200;s_ms+=re_ms)
            {
                if(s_hm+n_hm_2 < s_ms+n_ms) break; // 若分秒合法区间在时分区间之后，退出此层循环
                if(s_hm+n_hm > s_ms+n_ms_2) continue; // 若分秒合法区间在时分区间之前，则进入下层循环
                for(double s_hs=0;s_hs<43200;s_hs+=re_hs)
                {
                    if(s_hm+n_hm_2 < s_hs+n_hs || s_ms+n_ms_2 < s_hs+n_hs) break;
                    if(s_hm+n_hm > s_hs+n_hs_2 || s_ms+n_ms > s_hs+n_hs_2) continue;
                    double from = max(s_hm+n_hm, s_ms+n_ms, s_hs+n_hs); // 三个区间开始的最大值
                    double to = min(s_hm+n_hm_2, s_ms+n_ms_2, s_hs+n_hs_2); // 三个区间结束的最小值
                    if(from < to)   ans += to-from;
                }
            }
        }
        printf("%.3lf\n", ans/43200*100);
    }
    return 0;
}
