// Problem link: https://cses.fi/problemset/task/1145
// Disadvantage : TLE for big contraints like n > 10^4
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>

const int sz = 1e6+2;

vector<int> a(sz);
vector<int> dp(sz, -1);

int depression(int i){
    if(i == 0) return 1;
    if(dp[i] != -1) return dp[i];
    int ans = 1;
    for(int j = 0; j < i; j++){
        if(a[j] < a[i]){
            ans = max(ans, depression(j) + 1);
        }
    }
    return dp[i] = ans;
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
        cin >> a[i];
    }
    int ans = 1;
    for(int i = 0; i < n; i++){
        ans = max(ans, depression(i));
    }
    cout<< ans << '\n';
}
