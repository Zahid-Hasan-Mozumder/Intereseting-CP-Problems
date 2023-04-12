// Problem link: https://www.codechef.com/problems/TRPTSTIC
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vll vector<ll>
#define vvll vector<vector<ll>>

vvll generate(vvll &a, ll n, ll m){
    vvll pre(n + 1, vll(m + 1, 0));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + a[i][j];
        }
    }
    return pre;
}

bool check(vvll &a, vvll &pre, ll x, ll n, ll m, ll k){
    for(ll i = 1; i <= n; i++){
        for(ll j = 1; j <= m; j++){
            if(a[i][j] != 0){
                ll curr = pre[min(n, i + x)][min(m, j + x)] 
                - pre[max(0LL, i - x - 1)][min(m, j + x)] 
                - pre[min(n, i + x)][max(0LL, j - x - 1LL)] 
                + pre[max(0LL, i - x - 1LL)][max(0LL, j - x - 1LL)];
                if(curr >= k + 1) return true;
            }
        }
    }
    return false;
}

void zahid(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){

    zahid();

    int t; cin>>t;
    while(t--){
        ll n, m, k; cin >> n >> m >> k;
        vvll a(n + 1, vll(m + 1, 0));
        ll tot = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                cin >> a[i][j];
                tot += a[i][j];
            }
        }
        if(tot < k + 1) cout<< -1 << '\n';
        else{
            vvll pre = generate(a, n, m);
            ll ans = -1;
            ll l = 0, r = 1e6 + 5;
            while(l <= r){
                ll mid = (l + r) / 2;
                if(check(a, pre, mid, n, m, k)){
                    ans = mid;
                    r = mid - 1;
                }
                else{
                    l = mid + 1;
                }
            }
            cout << ans << '\n';
        }
    }
}
