//
//  main.cpp
//  processor la4254
//
//  Created by wangyijun on 14-1-2.
//  Copyright (c) 2014年 wangyijun. All rights reserved.
//

#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

struct Mission{
    int r,d,w;
    bool operator <(struct Mission b) const
    {
        return d>b.d;
    }
}msn[10000];
int n;
bool check(int p)
{
    priority_queue<Mission> Q;
    int k=0;
    for (int i=1; i<20000; i++) {
        while (msn[k].r<i && k<n) {
            Q.push(msn[k++]);
        }
        int time=p;
        while (time && !Q.empty()) {
            Mission temp=Q.top();
            Q.pop();
            if (temp.d<i) {
                return 0;
            }
            if (time>=temp.w) {
                time=time-temp.w;
                temp.w=0;
            }
            else
            {
                temp.w=temp.w-time;
                time=0;
                Q.push(temp);
            }
        }
        if (k==n && Q.empty()) {
            return 1;
        }
        
    }
    return 0;
}
bool cmp(Mission a,Mission b)
{
    return a.r<b.r;
}
int main(int argc, const char * argv[])
{
    int i;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>msn[i].r>>msn[i].d>>msn[i].w;
    }
    sort(msn, msn+n, cmp);
    int sum=0;
    for (i=0; i<n; i++) {
        sum+=msn[i].w;
    }
    int l=0,r=sum;
    while (l<r) {
        int mid=l+(r-l)/2;
        if(check(mid))
            r=mid;
        else
            l=mid+1;
    }
    cout<<l<<endl;
    return 1;
      
    
}

