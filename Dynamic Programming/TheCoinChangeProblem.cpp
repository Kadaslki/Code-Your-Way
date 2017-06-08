Author: Kadaslki

Problem Description: https://www.hackerrank.com/challenges/coin-change

Problem Solution:

#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    int m,n,i,j;
    cin>>n>>m;
    
    int c[m];
    long long int t[n+1]={0};
    for(i=0;i<m;i++)
        cin>>c[i];
    t[0]=1;
    
    for(int i=0; i<m; i++)
        for(int j=c[i]; j<=n; j++)
            t[j] += t[j-c[i]];
    
    cout<<t[n];
}
