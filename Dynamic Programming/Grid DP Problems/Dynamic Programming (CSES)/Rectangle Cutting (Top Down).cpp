
// Problem link: https://cses.fi/problemset/result/5744403/
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>

vvi dp(505, vi(505, -1));

int depression(int a, int b){
    if(a > b) swap(a, b);
    if(a == b) return dp[a][b] = 0;
    if(dp[a][b] != -1) return dp[a][b];
    int minWays = INT_MAX;
    for(int i = 1; i < a; i++){
        minWays = min(minWays, 1 + depression(i, b) + depression(a - i, b));
    }
    for(int i = 1; i < b; i++){
        minWays = min(minWays, 1 + depression(a, i) + depression(a, b - i));
    }
    return dp[a][b] = minWays;
}

void zahid(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){

    zahid();

    int a, b; cin>> a >> b;
    cout << depression(a, b) << '\n';
}
