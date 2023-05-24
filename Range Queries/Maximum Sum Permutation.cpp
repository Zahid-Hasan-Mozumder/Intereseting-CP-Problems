// Problem link: https://www.codechef.com/START91B/problems/MAXSUMPERM
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>
#include <climits>

using namespace std;

#define ll long long int

#define pii pair<int, int>
#define pli pair<ll, int>
#define pil pair<int, ll>
#define pll pair<ll, ll>
#define psi pair<string, int>
#define psl pair<string, ll>
#define piii pair<pair<int, int>, int>
#define pipii pair<int, pair<int, int>>
#define piipii pair<pair<int, int>, pair<int, int>>
#define vi vector<int>
#define vll vector<ll>
#define vb vector<bool>
#define vvi vector<vector<int>>
#define vvll vector<vector<ll>>
#define vvb vector<vector<bool>>
#define vs vector<string>
#define vpii vector<pair<int, int>>
#define vpll vector<pair<ll, ll>>
#define vpli vector<pair<ll, int>>
#define vpil vector<pair<int, ll>>
#define vpipii vector<pair<int, pair<int, int>>>
#define vvpii vector<vector<pair<int, int>>>
#define vvpll vector<vector<pair<ll, ll>>>
#define plpii pair<ll, pair<int, int>>
#define vplpii vector<pair<ll, pair<int, int>>>
#define vvpil vector<vector<pair<int, ll>>>
#define pb push_back
#define pf push_front
#define ff first
#define ss second

const ll mod = 1e9+7;
//const ll mod = 998244353;
const int maxN = 5e6+5;
const int sz = 1e6+2;
const double pi = acos(-1.0);
const double PI = 3.1415926535897;

void zahid(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("Error.txt", "w", stderr);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){

    zahid();

    int t; cin >> t;
    while(t--){
        ll n, q; cin >> n >> q;
        vll a(n), cnt(n, 0);
        for(int i = 0; i < n; i++) cin >> a[i];
        
        // Checking the most used cells 
        vpii que;
        for(int i = 0; i < q; i++){
            ll l, r; cin >> l >> r;
            l--; r--;
            cnt[l]++;
            if(r + 1 < n) cnt[r + 1]--;
            que.pb({l, r});
        }
        vpii cc;
        cc.pb({cnt[0], 0});
        for(int i = 1; i < n; i++){
            cnt[i] += cnt[i - 1];
            cc.pb({cnt[i], i});
        }
        sort(cc.rbegin(), cc.rend());
        sort(a.rbegin(), a.rend());
        
        // Creating new array by giving greater values in most used cells
        vll aa(n), cum(n, 0);
        for(int i = 0; i < cc.size(); i++){
            aa[cc[i].ss] = a[i];
        }
        
        // Making a cumulative sum array depending on the newly created array
        for(int i = 0; i < n; i++){
            cum[i] = aa[i];
            if(i) cum[i] += cum[i - 1];
        }
        
        // Calculating the final answer
        ll x = 0;
        for(int i = 0; i < q; i++){
            x += cum[que[i].ss];
            if(que[i].ff - 1 >= 0) x -= cum[que[i].ff - 1];
        }
        cout << x << '\n';
        for(int i = 0; i < n; i++) cout << aa[i] << " "; cout << '\n';
    }
}
