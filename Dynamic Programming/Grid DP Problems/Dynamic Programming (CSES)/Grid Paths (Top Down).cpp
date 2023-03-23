// Problem link: https://cses.fi/problemset/task/1638/
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define vvi vector<vector<int>>
#define vs vector<string>
#define pb push_back

const ll mod = 1e9+7;

vs grid;
vvi dp(1e3+1, vi(1e3+1, -1));

int depression(int i, int j){
    if(grid[i][j] == '*') return 0;
    if(i == 0 && j == 0) return 1;
    if(dp[i][j] != -1) return dp[i][j];
    int curr = 0;
    if(i - 1 >= 0){
        curr += depression(i - 1, j);
        curr %= mod;
    }
    if(j - 1 >= 0){
        curr += depression(i, j - 1);
        curr %= mod;
    }
    return dp[i][j] = curr;
}

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
    cout << depression(n - 1, n - 1) << '\n';
}
