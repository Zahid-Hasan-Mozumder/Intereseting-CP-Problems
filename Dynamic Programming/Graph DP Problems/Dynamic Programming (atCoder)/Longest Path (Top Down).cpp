// Problem link: https://atcoder.jp/contests/dp/tasks/dp_g
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>
#define pb push_back

int n, m;
vvi al;
vi dp(1e5+2, -1);

int depression(int i){
    if(al[i].size() == 0) return dp[i] = 0;
    if(dp[i] != -1) return dp[i];
    int dist = 0;
    for(int j = 0; j < al[i].size(); j++){
        dist = max(dist, 1 + depression(al[i][j]));
    }
    return dp[i] = dist;
}

void zahid(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){

    zahid();

    
    cin >> n >> m;
    al.resize(n + 1);
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        al[u].pb(v);
    }
    int ans = INT_MIN;
    for(int i = 1; i <= n; i++){
        ans = max(ans, depression(i));
    }
    cout << ans << '\n';
}
