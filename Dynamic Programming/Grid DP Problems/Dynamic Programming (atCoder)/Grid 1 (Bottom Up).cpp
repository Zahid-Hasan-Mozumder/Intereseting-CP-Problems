// Problem link: https://atcoder.jp/contests/dp/tasks/dp_h
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>
#define vs vector<string>
#define pb push_back

const int mod = 1e9+7;

int n, m;
vs grid;
vvi dp(1e3+2, vi(1e3+2, 0));

void zahid(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){

    zahid();

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        grid.pb(s);
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(i == 0 && j == 0){
                dp[i][j] = 1;
                continue;
            }
            if(grid[i][j] == '#'){
                dp[i][j] = 0;
                continue;
            }
            if(i - 1 >= 0){
                dp[i][j] += dp[i - 1][j];
                dp[i][j] %= mod;
            }
            if(j - 1 >= 0){
                dp[i][j] += dp[i][j - 1];
                dp[i][j] %= mod;
            }
        }
    }
    cout << dp[n - 1][m - 1] << '\n';
}
