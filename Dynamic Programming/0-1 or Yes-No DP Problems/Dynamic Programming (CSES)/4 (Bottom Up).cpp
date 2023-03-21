// Problem link: https://cses.fi/problemset/task/1636/
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>

const ll mod = 1e9+7;
const int sz = 1e6+2;

int n, x;
vi c(sz);
vi dp(sz, 0);

void zahid(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){

    zahid();

    cin >> n >> x;
    for(int i = 1; i <= n; i++){
        cin >> c[i];
    }
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= x; j++){
            if(j - c[i] >= 0){
                dp[j] = dp[j] + dp[j - c[i]];
                dp[j] %= mod;
            }
        }
    }
    cout<< dp[x] << '\n';
}
