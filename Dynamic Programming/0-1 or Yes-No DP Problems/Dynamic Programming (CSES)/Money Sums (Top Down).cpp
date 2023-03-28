// Problem link: https://cses.fi/problemset/task/1745/
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>

int n;
vi a(1e2+2);
vvi dp(1e2+2, vi(1e5+2, -1));
set<int> s;

void depression(int i, int sum){
    if(i == n){
        s.insert(sum);
        return;
    }
    if(dp[i][sum] != -1) return;
    dp[i][sum] = 1;
    depression(i + 1, sum + a[i]);
    depression(i + 1, sum);
}

void zahid(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){

    zahid();

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    depression(0, 0);
    s.erase(s.begin());
    cout<< s.size() << '\n';
    while(!s.empty()){
        cout<< *s.begin() << " ";
        s.erase(s.begin());
    }
}
