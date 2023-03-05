// Problem link: https://www.spoj.com/problems/KOICOST/
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
#define pipii pair<int, pair<int, int>, int>
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
#define si stack<int>
#define sll stack<ll>
#define qi queue<int>
#define qll queue<ll>
#define pb push_back
#define pf push_front
#define ff first
#define ss second

const ll mod = 1e9;
const int maxN = 5e6+5;
const int sz = 1e6+2;
const double pi = acos(-1.0);
const double PI = 3.1415926535897;

vll wt, cwt;
vplpii edges;
vi size, parent;

void initialize(int n){
    size.resize(n+1, 1);
    parent.resize(n+1, 0);
    for(int i=1; i<=n; i++) parent[i] = i;
}

int findParent(int u){
    if(u == parent[u])
        return u;
    return parent[u] = findParent(parent[u]);
}

void unionBySize(int u, int v){
    int upu = findParent(u);
    int upv = findParent(v);
    if(upu == upv) return;
    else{
        if(size[upu] < size[upv]){
            parent[upu] = upv;
            int tmp = size[upv];
            size[upv] += size[upu];
            size[upu] += tmp;
        }
        else{
            parent[upv] = upu;
            int tmp = size[upu];
            size[upu] += size[upv];
            size[upv] += tmp;
        }
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

    ll ans = 0;
    int n, m; cin>>n>>m;
    wt.resize(m); cwt.resize(m);
    initialize(n);
    for(int i=0; i<m; i++){
        int u, v; ll w;
        cin>>u>>v>>w;
        edges.pb({w, {u, v}});
        wt[i] = w;
        cwt[i] = w;
    }
    sort(wt.begin(), wt.end());
    sort(cwt.begin(), cwt.end());
    sort(edges.begin(), edges.end());
    reverse(edges.begin(), edges.end());
    for(int i=1; i<m; i++) cwt[i] += cwt[i - 1];
    for(int i=0; i<m; i++){
        auto it = edges[i];
        ll w = it.ff;
        int u = it.ss.ff, v = it.ss.ss;
        int upu = findParent(u), upv = findParent(v);
        if(upu != upv){
            ll szu = size[upu], szv = size[upv];
            int ind = lower_bound(wt.begin(), wt.end(), w) - wt.begin();
            ans += (((szu * szv) % mod) * cwt[ind]) % mod;
            ans %= mod;
            unionBySize(u, v);
        }
    }
    cout<< ans << '\n';
}
