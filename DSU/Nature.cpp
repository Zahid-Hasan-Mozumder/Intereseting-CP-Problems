// Problem link: https://vjudge.net/contest/570956#problem/F
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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
#define pipll pair<int, pair<ll, ll>>
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
#define vvvi vector<vector<vector<int>>>
#define vvvll vector<vector<vector<ll>>>
#define vvs vector<vector<string>>
#define vpii vector<pair<int, int>>
#define vpll vector<pair<ll, ll>>
#define vpli vector<pair<ll, int>>
#define vpil vector<pair<int, ll>>
#define vpipii vector<pair<int, pair<int, int>>>
#define vpipll vector<pair<int, pair<ll, ll>>>
#define vvpii vector<vector<pair<int, int>>>
#define vvpll vector<vector<pair<ll, ll>>>
#define vplpii vector<pair<ll, pair<int, int>>>
#define vplpll vector<pair<ll, pair<ll, ll>>>
#define vvpil vector<vector<pair<int, ll>>>
#define pb push_back
#define pf push_front
#define ff first
#define ss second

const ll mod = 1e9 + 7;
//const ll mod = 998244353;
const double pi = acos(-1.0);
const double PI = 3.1415926535897;
const double eps = 1e-6;

vi par, sz;

void init(int n){
    par.clear(); par.resize(n + 1);
    sz.clear(); sz.resize(n + 1, 1);
    for(int i = 1; i <= n; i++) par[i] = i;
}

int find(int v){
    if(par[v] == v)
        return v;
    return par[v] = find(par[v]);
}

void Union(int u, int v){
    int pu = find(u);
    int pv = find(v);
    if(pu != pv){
        if(sz[pu] < sz[pv])
            swap(pu, pv);
        par[pv] = pu;
        sz[pu] += sz[pv];
    }
}

void zahid(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){

    zahid();

    int n, m;
    while(cin >> n >> m){
        if(n == 0 && m == 0) break;
        init(n);
        unordered_map<string, int> mp;
        for(int i = 1; i <= n; i++){
            string s; cin >> s;
            mp[s] = i;
        }
        for(int i = 0; i < m; i++){
            string x, y; cin >> x >> y;
            int u = mp[x];
            int v = mp[y];
            if(find(u) != find(v))
                Union(u, v);
        }
        int mx = 0;
        for(int i = 1; i <= n; i++){
            if(par[i] == i){
                mx = max(mx, sz[i]);
            }
        }
        cout << mx << '\n';
    }
}
