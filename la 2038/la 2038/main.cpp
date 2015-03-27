//
//  main.cpp
//  la 2038
//
//  Created by wangyijun on 14-2-2.
//  Copyright (c) 2014年 wangyijun. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
using namespace std;
#define N 1501
int dp[N][2];
vector<int> map[N];
char stream[30000];
int n;
int min(int a,int b)
{
    return a<b?a:b;
}
void dfs(int w,int k)
{
    dp[w][0]=0,dp[w][1]=1;
    for (int i=0; i<map[w].size(); i++) {
        int v=map[w][i];
        if (v==k) {
            continue;
        }
        dfs(v, w);
        dp[w][0]+=dp[v][1];
        dp[w][1]+=min(dp[v][1],dp[v][0]);
    }

}
int main(int argc, const char * argv[])
{
    int u,m,v;
    while(cin>>n)
    {
        for (int i=0; i<=n; i++) {
            map[i].clear();
        }
        for (int i=0; i<n; i++) {
            scanf("%d:(%d)",&u,&m);
            for (int j=0; j<m;j++) {
                scanf("%d",&v);
                map[u].push_back(v);
                map[v].push_back(u);
            }
        }
        dfs(0, -1);
        cout<<min(dp[0][1], dp[0][0])<<endl;
    }
    return 0;
   
}

