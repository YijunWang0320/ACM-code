//
//  main.cpp
//  la 2031
//
//  Created by wangyijun on 14-2-5.
//  Copyright (c) 2014年 wangyijun. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
using namespace std;
int dp[30][2];
void swap(int &x,int &y)
{
    int temp;
    temp=x;
    x=y;
    y=temp;
}
int getpoint(int x,int y)
{
    if(x==0)
    {
        return 2;
    }
    else if (abs(x-y)%4==0) {
        return 1;
    }else if(abs(x-y)%4==2){
        return 4;
    }else{
        return 3;
    }
}
int main(int argc, const char * argv[])
{
    int k;
    while (~scanf("%d",&k)) {
        if (k==0)
            break;
        for (int i=0; i<25; i++)
            dp[i][0]=inf;
        dp[k][0]=2;
        int t=1,x,y;
        while (scanf("%d",&k)) {
            if (k==0) {
                break;
            }
            for (int i=0; i<25; i++) {
                dp[i][t]=inf;
            }
            for (int i=0; i<5; i++) {
                for (int j=i+1;j<5 ; j++) {
                    if(dp[i*5+j][t^1]==inf)
                        continue;
                    if (k==i || k==j) {
                        dp[i*5+j][t]=min(dp[i*5+j][t],dp[i*5+j][t^1]+1);
                        continue;
                    }
                    int temp;
                    temp=getpoint(i, k);
                    x=j,y=k;
                    if (x>y) {
                        swap(x, y);
                    }
                    dp[x*5+y][t]=min(dp[x*5+y][t], dp[i*5+j][t^1]+temp);
                    temp=getpoint(j, k);
                    x=i,y=k;
                    if (x>y) {
                        swap(x, y);
                    }
                    dp[x*5+y][t]=min(dp[x*5+y][t], dp[i*5+j][t^1]+temp);
                }
            }
            t=t^1;
        }
        int ans=inf;
        for (int i=0; i<25; i++) {
            ans=min( ans, dp[i][t^1]);
        }
        cout<<ans<<endl;
    }
    return 0;
    
}

