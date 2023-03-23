// Problem link: https://cses.fi/problemset/task/1158/
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>

vi price(1e3+2), page(1e3+2);
vi dp(1e5+2, INT_MIN);

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
    dp[0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = x; j >= 1; j--){
            if(j - price[i] >= 0){
                dp[j] = max(dp[j], dp[j - price[i]] + page[i]);
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= x; i++){
        ans = max(ans, dp[i]);
    }
    cout << ans << '\n';
}
