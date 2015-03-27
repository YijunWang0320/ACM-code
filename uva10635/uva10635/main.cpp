//
//  main.cpp
//  uva10635
//
//  Created by wangyijun on 14-1-2.
//  Copyright (c) 2014年 wangyijun. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
using namespace std;
#define INF 10000000
int a[10000];
int b[10000];
int d[10000],g[10000];
int s[10000];

int main(int argc, const char * argv[])
{
    int n,p,q;
    cin>>n>>p>>q;
    memset(a, -1, sizeof(a));
    memset(b, 0, sizeof(b));
    for (int i=1; i<=p+1;i++ ) {
        int temp;
        cin>>temp;
        a[temp]=i;
    }
    int k=0;
    for (int i=1; i<=q+1; i++) {
        int temp;
        cin>>temp;
        if(a[temp]!=-1)
            b[k++]=a[temp];
    }
    for (int i=1; i<=k; i++) {
        g[i]=INF;
    }
    for (int i=0; i<k; i++) {
        int s=lower_bound(g+1, g+k+1, b[i])-g;
        d[i]=s;
        g[s]=b[i];
    }
    int max=0;
    for (int i=0; i<k; i++) {
        max=max>d[i]?max:d[i];
    }
    cout<<max<<endl;
}

