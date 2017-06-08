Author: Kadaslki

Problem Description: https://www.hackerrank.com/challenges/dynamic-programming-classics-the-longest-common-subsequence

Problem Solution:

#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

void printlcs(vector<vector<int> > const& c, vector<int> x, vector<int> y, int i,int j){
	if(i==0||j==0)
		return;
	if(x[i-1]==y[j-1]){
			printlcs(c,x,y,i-1,j-1);
			cout<<x[i-1]<<" ";
	}
	else{
			if(c[i-1][j]>c[i][j-1])
				printlcs(c,x,y,i-1,j);
			else
				printlcs(c,x,y,i,j-1);	
	}
}

int main() {
    int m,n,i,j;
    cin>>m>>n;
    vector<int> x(m),y(n);
    vector<vector<int> > c(m+1, vector<int>(n+1));
    
    for(i=0;i<m;i++)
        cin>>x[i];     
    for(i=0;i<n;i++)
        cin>>y[i]; 
    
    for(i=1;i<m+1;i++)
        c[i][0]=0;
    for(j=0;j<n+1;j++)
        c[0][j]=0;
    
    for(i=1;i<m+1;i++)
        for(j=1;j<n+1;j++){
            if(x[i-1]==y[j-1])
                c[i][j]=1+c[i-1][j-1];
            else
                c[i][j]=max(c[i-1][j],c[i][j-1]);            
    }
		printlcs(c,x,y,m,n);
}
