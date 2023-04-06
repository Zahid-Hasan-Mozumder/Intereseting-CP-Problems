// Problem link: https://leetcode.com/problems/distinct-subsequences/
// Helpful video: https://www.youtube.com/watch?v=nVG7eTiD2bY&t=1287s
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>

string s, t;
vvi dp(1e3+5, vi(1e3+5, -1));

int depression(int i, int j){
    if(j < 0) return 1;
    if(i < 0) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    if(s[i] == t[j]) return dp[i][j] = depression(i - 1, j - 1) + depression(i - 1, j);
    else return dp[i][j] = depression(i - 1, j);
}

void zahid(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){

    zahid();

    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    cout << depression(n - 1, m - 1) << '\n';
}
