// Problem link: https://cses.fi/problemset/task/1639/
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>

string a, b; 
vvi dp(5e3+5, vi(5e3+5, -1));

int depression(int i, int j){
    if(i == 0) return j;
    if(j == 0) return i;
    if(dp[i][j] != -1) return dp[i][j];
    int res = min(depression(i, j - 1) + 1, depression(i - 1, j) + 1);
    if(a[i] == b[j]){
        res = min(res, depression(i - 1, j - 1));
    }
    else{
        res = min(res, depression(i - 1, j - 1) + 1);
    }
    return dp[i][j] = res;
}

void zahid(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){

    zahid();

    cin >> a >> b;
    a = " " + a; b = " " + b;
    int n = a.size(), m = b.size();
    int ans = depression(n - 1, m - 1);
    cout<< ans << '\n';
}
