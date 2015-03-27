//
//  main.cpp
//  火星采矿 la3530
//
//  Created by wangyijun on 14-1-25.
//  Copyright (c) 2014年 wangyijun. All rights reserved.
//

#include <iostream>
using namespace std;
#define N 500
int a[N][N];
int b[N][N];
int dp[N][N];
int max(int a,int b)
{
    return a>b?a:b;
}
int dps(int n,int m)
{
    if (n==0 || m==0) {
        return 0;
    }
    if(dp[n][m]>=0){
        return dp[n][m];
    }
    return dp[n][m]=max(dps(n-1,m)+a[n][m],dps(n,m-1)+b[n][m]);
}
int main(int argc, const char * argv[])
{
    memset(dp, -1, sizeof(dp));
    memset(a,0, sizeof(a));
    memset(b, 0, sizeof(b));
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m;j++) {
            cin>>a[i][j];
            a[i][j]+=a[i][j-1];
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin>>b[i][j];
            b[i][j]+=b[i-1][j];
        }
    }
    cout<<dps(n, m);
    return 0;
}

