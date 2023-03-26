// Problem link: https://atcoder.jp/contests/dp/tasks/dp_h
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>
#define vs vector<string>
#define pb push_back

const int mod = 1e9+7;

int n, m;
vs grid;
vvi dp(1e3+2, vi(1e3+2, -1));

int depression(int i, int j){
    if(i == 0 && j == 0) return dp[i][j] = 1;
    if(dp[i][j] != -1) return dp[i][j];
    if(grid[i][j] == '#') return dp[i][j] = 0;
    int ways = 0;
    if(i - 1 >= 0){
        ways += depression(i - 1, j);
        ways %= mod;
    }
    if(j - 1 >= 0){
        ways += depression(i, j - 1);
        ways %= mod;
    }
    return dp[i][j] = ways;
}

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
    cout << depression(n - 1, m - 1) << '\n';
}
