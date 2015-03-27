//
//  main.cpp
//  la3363
//
//  Created by wangyijun on 14-2-2.
//  Copyright (c) 2014年 wangyijun. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 201
int dp[N][N];
char s[N];
inline int NOD(int x)
{
    if(x>=0&&x<=9) return 1;
    if(x>=10&&x<=99) return 2;
    return 3;
}
bool check(int l,int r,int k)
{
    if(r==k)
        return false;
    int p=k-l+1;
    if ((r-l+1)%p!=0) {
        return false;
    }
    int number=(r-l+1)/p;
    for (int i=0; i<p; i++) {
        for (int j=0; j<number; j++) {
            if (s[l+i]!=s[l+i+p*j]) {
                return false;
            }
        }
    }
    return true;
}
int main(int argc, const char * argv[])
{
    int t;
    cin>>t;
    while (t--) {
        cin>>s;
        int n=(int)strlen(s);
        for (int i=0; i<=n; i++) {
            dp[i][i]=1;
        }
        for (int len=2; len<=n; len++) {
            for (int i=0; i+len<=n; i++) {
                int j=i+len-1;
                dp[i][j]=0x3FFFFFF;
                for (int k=i; k<=j; k++) {
                    dp[i][j]=min(dp[i][j], dp[i][k]+dp[k+1][j]);
                    if (check(i,j,k)) {
                        dp[i][j]=min(dp[i][j], NOD((j-i+1)/(k-i+1))+2+dp[i][k]);
                    }
                }
            }
            
        }
        cout<<dp[0][n-1]<<endl;
    }
    return 0;
}
