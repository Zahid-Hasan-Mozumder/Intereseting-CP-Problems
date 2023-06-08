// Problem link: https://codeforces.com/contest/1670/problem/C
// Video editorial: https://www.youtube.com/watch?v=p5Z8SPn5Y6w
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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
#define plpii pair<ll, pair<int, int>>
#define plpll pair<ll, pair<ll, ll>>
#define piipii pair<pair<int, int>, pair<int, int>>
#define vi vector<int>
#define vll vector<ll>
#define vb vector<bool>
#define vvi vector<vector<int>>
#define vvll vector<vector<ll>>
#define vvb vector<vector<bool>>
#define vs vector<string>
#define vvvll vector<vector<vector<ll>>>
#define vvs vector<vector<string>>
#define vpii vector<pair<int, int>>
#define vpll vector<pair<ll, ll>>
#define vpli vector<pair<ll, int>>
#define vpil vector<pair<int, ll>>
#define vpipii vector<pair<int, pair<int, int>>>
#define vvpii vector<vector<pair<int, int>>>
#define vvpll vector<vector<pair<ll, ll>>>
#define vplpii vector<pair<ll, pair<int, int>>>
#define vplpll vector<pair<ll, pair<ll, ll>>>
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

int n;
vvi al;
vb vis;
vi a, b;
set<int> c;

ll POW_MOD(ll a, ll b){
    if(b == 0)
        return 1;
    if(b == 1)
        return a;
    ll x = POW_MOD(a, b/2);
    if(b&1) return ((((x % mod) * (x % mod)) % mod) * (a % mod)) % mod;
    else return ((x % mod) * (x % mod)) % mod;
}

void dfs(int i, bool &flag){
    vis[i] = true;
    if(c.count(i)) flag = true;
    for(auto v : al[i]){
        if(!vis[v]) dfs(v, flag);
    }
}

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
        al.clear(); vis.clear();
        a.clear(); b.clear(); c.clear();
        cin >> n;
        a.resize(n); b.resize(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];
        for(int i = 0; i < n; i++){
            int x; cin >> x;
            if(x) c.insert(x);
        }
        al.resize(n + 1);
        vis.resize(n + 1, false);
        for(int i = 0; i < n; i++){
            al[a[i]].pb(b[i]);
            al[b[i]].pb(a[i]);
        }
        int totalCycle = 0, fixedCycle = 0;
        for(int i = 1; i <= n; i++){
            if(!vis[i]){
                // For,
                // 4  or 6  etc
                // 4     6
                if(al[i].size() == 2 && al[i][0] == i && al[i][1] == i) continue;
                bool flag = false;
                dfs(i, flag);
                totalCycle++;
                if(flag) fixedCycle++;
            }
        }
        ll p = totalCycle - fixedCycle;
        ll ans = POW_MOD(2, p);
        cout << ans << '\n';
    }
}
