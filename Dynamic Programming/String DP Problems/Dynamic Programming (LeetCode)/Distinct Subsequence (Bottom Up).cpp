// Problem link: https://leetcode.com/problems/distinct-subsequences/
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>

string s, t;
vvi dp(1e3+5, vi(1e3+5, 0));

void zahid(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){

    zahid();

    cin >> s >> t;
    s = " " + s;
    t = " " + t;
    int n = s.size();
    int m = t.size();
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(j == 0) dp[i][j] = 0;
            if(i == 0) dp[i][j] = 1;
            if(i > 0 && j > 0){
                if(t[i] == s[j]){
                    dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
                }
                else{
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }
    }
    cout << dp[m - 1][n - 1] << '\n';
}
