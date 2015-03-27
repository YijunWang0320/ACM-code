//
//  main.cpp
//  la 4643
//
//  Created by wangyijun on 14-2-5.
//  Copyright (c) 2014年 wangyijun. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#define maxn 1<<12
#define N 130
using namespace std;
int dp[maxn][maxn];
int q[N];
char s[20];
int m,n;
int min( int a, int b )
{
    return a < b ? a : b;
}

int max( int a, int b )
{
    return a > b ? a : b;
}

int DP( int state, int quest )    //state表示选择了哪几个问题，quest表示对每个问题的答案
{
    if ( dp[state][quest] != -1 ) return dp[state][quest];
    
    int cnt = 0;
    for ( int i = 0; i < n; i++ )
        if ( ( q[i] & state ) == quest )
            ++cnt;
    
    if ( cnt <= 1 ) return dp[state][quest] = 0;  //如果没有两个人答案是重复的
    
    int ans = (1 << 30);
    for ( int i = 0; i < m; i++ )
    {
        if ( state & ( 1 << i ) ) continue;    //如果问题 i 已经在状态state中, 跳过
        dp[state|(1 << i)][quest] = DP( state|(1 << i), quest ); //选择问题i, 对问题i的回答为"否"
        dp[state|(1 << i)][quest|(1 << i)] = DP( state|(1 << i), quest|(1 << i) ); //选择问题i, 对问题i的回答为"是"
        ans = min( ans, max( dp[state|(1 << i)][quest], dp[state|(1 << i)][quest|(1 << i)] ) + 1 );
    }
    return dp[state][quest] = ans;
}

int main(int argc, const char * argv[])
{
    while (scanf("%d%d",&m,&n),m||n) {
        memset(q, 0, sizeof(q));
        memset(dp, -1,sizeof(dp));
        for (int i=0; i<n; i++) {
            cin>>s;
            for (int j=0; j<m; j++) {
                if (s[j]=='1')
                    q[i]=q[i]+(1<<j);
            }
        }
        cout<<DP(0,0)<<endl;
    }
    return 0;
}
/*
 int main()
 {
 while ( scanf("%d%d", &Q, &n), Q || n )
 {
 memset( question, 0, sizeof(question) );
 for ( int i = 0; i < n; i++ )
 {
 scanf("%s", str);
 for ( int j = 0; j < Q; j++ )
 {
 if ( str[j] == '1' )
 question[i] += (1 << j);   //用二进制表示对问题的回答
 }
 }
 
 memset( dp, -1, sizeof(dp) );
 printf( "%d\n", DP(0, 0) );
 }
 return 0;
 }
*/

