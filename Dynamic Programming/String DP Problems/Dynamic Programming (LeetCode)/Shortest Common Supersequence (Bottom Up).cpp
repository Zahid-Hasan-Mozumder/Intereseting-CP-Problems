// Problem link: https://leetcode.com/problems/shortest-common-supersequence/
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>

void zahid(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){

    zahid();

    string s, t;
    cin >> s >> t;
    s = " " + s;
    t = " " + t;
    int n = s.size();
    int m = t.size();
    vvi dp(n, vi(m, 0));
    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
            if(s[i] == t[j]){
                dp[i][j] = max(dp[i][j], dp[i][j - 1]);
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            }
            else{
                dp[i][j] = max(dp[i][j], dp[i][j - 1]);
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            }
        }
    }
    string ans = "";
    int i = n - 1, j = m - 1;
    while(i > 0 && j > 0){
        if(dp[i][j] == dp[i][j - 1]){
            ans = t[j] + ans;
            j--;
        }
        else if(dp[i][j] == dp[i - 1][j]){
            ans = s[i] + ans;
            i--;
        }
        else{
            ans = s[i] + ans;
            i--; j--;
        }
    }
    while(i > 0){
        ans = s[i] + ans;
        i--;
    }
    while(j > 0){
        ans = t[j] + ans;
        j--;
    }
    cout << ans << '\n';
}
