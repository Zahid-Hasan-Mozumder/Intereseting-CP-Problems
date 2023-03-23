// Problem link: https://cses.fi/problemset/task/1638/
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define vvi vector<vector<int>>
#define vs vector<string>
#define pb push_back

const ll mod = 1e9+7;

vs grid;
vvi dp(1e3+1, vi(1e3+1, 0));

void zahid(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){

    zahid();

    int n; cin >> n;
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        grid.pb(s);
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] == '*') continue;
            if(i == 0 && j == 0){
                dp[i][j] = 1;
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
    cout<< dp[n - 1][n - 1] << '\n';
}
