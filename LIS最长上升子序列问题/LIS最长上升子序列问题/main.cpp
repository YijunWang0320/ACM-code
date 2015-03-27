//
//  main.cpp
//  LIS最长上升子序列问题
//
//  Created by wangyijun on 14-1-2.
//  Copyright (c) 2014年 wangyijun. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
#define INF 100000
int a[1000];
int g[1000];
int d[1000];
int main(int argc, const char * argv[])
{
    int n;
    memset(a, 0, sizeof(a));
    cin>>n;
    for (int i=0; i<n; i++) {
        cin>>a[i];
    }
    for (int i=1; i<=n; i++) {
        g[i]=INF;
    }
    for (int i=0; i<n; i++) {
        int k=lower_bound(g+1, g+n+1, a[i])-g;
        d[i]=k;
        g[k]=a[i];
    }
    int max=0;
    for (int i=0;i<n; i++) {
        max=max<d[i]?d[i]:max;
    }
    cout<<max<<endl;
    return 0;

}

