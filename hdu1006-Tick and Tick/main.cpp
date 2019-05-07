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
    double vh = 1.0/120, vm = 0.1, vs = 6; // ʱ�룬���룬������ٶ�
    double re_hm = 360/(vm-vh), re_hs = 360/(vs-vh), re_ms = 360/(vs-vm); // �ٴ��غ�����ʱ��
    while(scanf("%d",&n) && n!=-1)
    {
        double ans = 0;
        double n_hm = n/(vm-vh), n_hs = n/(vs-vh), n_ms = n/(vs-vm); // ����n������ʱ��
        double n_hm_2 = (360-n)/(vm-vh), n_hs_2 = (360-n)/(vs-vh), n_ms_2 = (360-n)/(vs-vm); //��С��n������ʱ��
        for(double s_hm=0;s_hm<43200;s_hm+=re_hm)
        {
            for(double s_ms=0;s_ms<43200;s_ms+=re_ms)
            {
                if(s_hm+n_hm_2 < s_ms+n_ms) break; // ������Ϸ�������ʱ������֮���˳��˲�ѭ��
                if(s_hm+n_hm > s_ms+n_ms_2) continue; // ������Ϸ�������ʱ������֮ǰ��������²�ѭ��
                for(double s_hs=0;s_hs<43200;s_hs+=re_hs)
                {
                    if(s_hm+n_hm_2 < s_hs+n_hs || s_ms+n_ms_2 < s_hs+n_hs) break;
                    if(s_hm+n_hm > s_hs+n_hs_2 || s_ms+n_ms > s_hs+n_hs_2) continue;
                    double from = max(s_hm+n_hm, s_ms+n_ms, s_hs+n_hs); // �������俪ʼ�����ֵ
                    double to = min(s_hm+n_hm_2, s_ms+n_ms_2, s_hs+n_hs_2); // ���������������Сֵ
                    if(from < to)   ans += to-from;
                }
            }
        }
        printf("%.3lf\n", ans/43200*100);
    }
    return 0;
}
