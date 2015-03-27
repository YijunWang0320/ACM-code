//
//  main.cpp
//  la4731
//
//  Created by wangyijun on 14-1-19.
//  Copyright (c) 2014年 wangyijun. All rights reserved.
//

#include <iostream>
#include <algorithm>
#define INF 100000
#define MAX 101
using namespace std;
int c[MAX];
int p[MAX];
int dp[MAX][MAX];
int n,w;
int min(int a,int b)
{
    return a<b?a:b;
}
int dfs(int i,int j)
{
    if (w<0) {
        return INF;
    }
    if(dp[i][j]!=-1)
        return dp[i][j];
    int minn=INF;
    for (int k=0; k<i; k++) {
        minn=min(minn,dfs(k,w-1)+(p[i]-p[k])*i);
    }
    return dp[i][j]=minn;
}
int main(int argc, const char * argv[])
{
    cin>>n>>w;
    memset(dp, -1, sizeof(dp));
    dp[0][0]=0;
    int sum=0;
    
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
    }
    for (int i=1; i<=n; i++) {
        sum+=c[i];
    }
    sort(c+1, c+n+1);
    reverse(c+1, c+n+1);
    p[0]=0;
    for (int i=1; i<=n; i++) {
        p[i]=p[i-1]+c[i]/sum;
    }
    dp[0][0]=0;
    int number=dfs(n, w);
    cout<<number<<endl;
    return 0;
}

