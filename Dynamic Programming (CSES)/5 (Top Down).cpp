// Problem link: https://cses.fi/problemset/task/1637/
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pb push_back

const int sz = 1e6+2;
vi dp(sz, -1);

vi generateDigits(int x){
    vi digits;
    while(x){
        if(x % 10 != 0) digits.pb(x % 10);
        x /= 10;
    }
    return digits;
}

int depression(int n){
    if(n == 0) return 0;
    if(dp[n] != -1) return dp[n];
    vi digits = generateDigits(n);
    int curr = 1e9;
    for(int i = 0; i < digits.size(); i++){
        if(n - digits[i] >= 0){
            curr = min(curr, 1 + depression(n - digits[i]));
        }
    }
    return dp[n] = curr;
}

void zahid(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){

    zahid();

    int n; cin >> n;
    cout << depression(n) << '\n';
}
