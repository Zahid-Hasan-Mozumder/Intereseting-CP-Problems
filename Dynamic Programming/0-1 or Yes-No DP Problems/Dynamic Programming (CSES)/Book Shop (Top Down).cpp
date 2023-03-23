// Problem link: https://cses.fi/problemset/task/1158/
// Status : TLE for big constraints
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>

vi price(1e3+2), page(1e3+2);
vvi dp(1e5+2, vi(1e3+2, -1));

int depression(int x, int i){
    if(i == 0) return 0;
    if(dp[x][i] != -1) return dp[x][i];
    int curr = 0;
    curr = depression(x, i - 1);
    if(x - price[i] >= 0){
        curr = max(curr, depression(x - price[i], i - 1) + page[i]);
    }
    return dp[x][i] = curr;
}

void zahid(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){

    zahid();

    int n, x; cin >> n >> x;
    for(int i = 1; i <= n; i++) cin >> price[i];
    for(int i = 1; i <= n; i++) cin >> page[i];
    cout << depression(x, n) << '\n';
}
