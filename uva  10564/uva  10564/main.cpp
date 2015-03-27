//
//  main.cpp
//  uva  10564
//
//  Created by wangyijun on 14-1-27.
//  Copyright (c) 2014年 wangyijun. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;
long long dp[41][41][501];
int n;
int S;
char direct[2]={'L','R'};
int number[41][41];
bool fun(int x,int y)
{
    if(x<=n-1)
        return y>=0 && y<n-x;
    else
        return y>=0 && y<x-n+2;
}
void print_ans(int x,int y,int k)
{
    if (x==0) {
        return;
    }
    if (x>n-1) {
        if (fun(x-1, y-1) && dp[x-1][y-1][k-number[x][y]]) {
            cout<<"L";
            print_ans(x-1, y-1, k-number[x][y]);
        }
        else if(dp[x-1][y][k-number[x][y]] )
        {
            cout<<"R";
            print_ans(x-1, y,k-number[x][y]);
        }
    }
    else
    {
        if(dp[x-1][y][k-number[x][y]])
        {
            cout<<"L";
            print_ans(x-1, y, k-number[x][y]);
        }
        else if (fun(x-1, y+1) && dp[x-1][y+1][k-number[x][y]])
        {
            cout<<"R";
            print_ans(x-1, y+1, k-number[x][y]);
        }
    }
}
/*void print_ans(int x,int y,int k)
{
    //printf("%d %d %d\n",x,y,k);
    if(x==0) return;
    if(x<=n-1)
    {
        if(fun(x-1,y)&&map[x-1][y][k-data[x][y]])
        {
            printf("L");
            print_ans(x-1,y,k-data[x][y]);
        }
        else if(fun(x-1,y+1)&&map[x-1][y+1][k-data[x][y]])
        {
            printf("R");
            print_ans(x-1,y+1,k-data[x][y]);
        }
    }
    else
    {
        if(fun(x-1,y-1)&&map[x-1][y-1][k-data[x][y]])
        {
            printf("L");
            print_ans(x-1,y-1,k-data[x][y]);
        }
        else if(fun(x-1,y)&&map[x-1][y][k-data[x][y]])
        {
            printf("R");
            print_ans(x-1,y,k-data[x][y]);
        }
    }
}*/

int main(int argc, const char * argv[])
{
    while (scanf("%d%d",&n,&S)!=EOF) {
        if(n==0 && S==0)
            break;
    memset(number, 0, sizeof(number));
    memset(dp, 0,sizeof(dp));
    //初始化
    for (int i=0; i<n; i++) {
        for (int j=0; j<n-i; j++) {
            cin>>number[2*n-i-2][j];
        }
    }
    for (int i=1; i<n; i++) {
        for (int j=0; j<=i; j++) {
            cin>>number[n-i-1][j];
        }
    }
    
    for (int i=0; i<n; i++) {
        dp[0][i][number[0][i]]=1;
    }
    for (int i=1; i<2*n-1; i++) {
        int imax=i<n-1?n-i:i-n+2;
        for (int j=0; j<imax; j++) {
            for (int k=number[i][j]; k<500; k++) {
                if (dp[i-1][j][k-number[i][j]])
                    dp[i][j][k]+=dp[i-1][j][k-number[i][j]];
                if (i<=n-1 && fun(i-1, j+1) && dp[i-1][j+1][k-number[i][j]])
                    dp[i][j][k]+=dp[i-1][j+1][k-number[i][j]];
                if (i>n-1 && fun(i-1, j-1) &&dp[i-1][j-1][k-number[i][j]])
                    dp[i][j][k]+=dp[i-1][j-1][k-number[i][j]];
            }
         
        }
    }
    long long cnt=0;
    int pos=10000;
    for (int i=0; i<n; i++)
    if (dp[2*n-2][i][S])
    {
        cnt+=dp[2*n-2][i][S];
        pos=min(pos,i);
    }
        printf("%lld\n",cnt);
        if(cnt) {printf("%d ",pos);print_ans(2*n-2,pos,S);}
        puts("");
 
    }
    
}

