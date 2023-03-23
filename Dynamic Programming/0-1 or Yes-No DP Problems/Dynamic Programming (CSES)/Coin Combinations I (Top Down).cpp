// Problem link: https://cses.fi/problemset/task/1635/
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>

const ll mod = 1e9+7;
const int sz = 1e6+2;

int n, x;
vi c(sz);
vi dp(sz, -1);

int depression(int x){
    if(x == 0) return 1;
    if(dp[x] != -1) return dp[x];
    int curr = 0;
    for(int i = 1; i <= n; i++){
        if(x - c[i] >= 0){
            curr += depression(x - c[i]);
            curr %= mod;
        }
    }
    return dp[x] = curr;
}

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
    cout << depression(x) << '\n';
}
