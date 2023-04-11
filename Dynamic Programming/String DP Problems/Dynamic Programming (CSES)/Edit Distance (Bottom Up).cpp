// Problem link: https://cses.fi/problemset/task/1639/
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>

string a, b; 
vvi dp(5e3+5, vi(5e3+5, 0));

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
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(i == 0) dp[i][j] = j;
            if(j == 0) dp[i][j] = i;
            if(i == 0 || j == 0) continue;
            dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
            if(a[i] == b[j]) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
            else dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
        }
    }
    cout<< dp[n - 1][m - 1] << '\n';
}
