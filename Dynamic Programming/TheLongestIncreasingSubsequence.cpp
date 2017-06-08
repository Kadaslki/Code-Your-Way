Author: Kadaslki

Problem Description: https://www.hackerrank.com/challenges/longest-increasing-subsequent

Problem Solution:

#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

int getindex(vector<int> &v, int l, int r, int key) {
    while (r-l > 1) {
    int m = l + (r-l)/2;
    if (v[m] >= key)
        r = m;
    else
        l = m;
    }
    return r;
}
 
int LCS(vector<int> &v) {
    if (v.size() == 0)
        return 0;
    vector<int> tail(v.size(), 0);
    int length = 1; 
    tail[0] = v[0];
    for (size_t i = 1; i < v.size(); i++) {
        if (v[i] < tail[0])
            tail[0] = v[i];
        else if (v[i] > tail[length-1])
            tail[length++] = v[i];
        else
            tail[getindex(tail, -1, length-1, v[i])] = v[i];
    }
    return length;
}

int main(){
    long n,i;
    cin>>n;
    vector<int> ar;
    while(n--){
        cin>>i;
        ar.push_back(i);
    }
    cout<<LCS(ar);
}
