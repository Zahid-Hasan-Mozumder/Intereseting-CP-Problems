// Problem link: https://codeforces.com/problemset/problem/1627/C

// I must take 2 and another odd prime as an edge weight. Because other primes are odd and sum of two odd number 
// gives even number which can't be a prime number beacause 2 is the only even prime.
// 2 - 3 - 2 - 3 - 2 - 3 - 2 - 3 ...................................................

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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
const int N = 2e5 + 5;
const int sz = 1e6+2;
const double pi = acos(-1.0);
const double PI = 3.1415926535897;

map<pii, int> mp;
vi color;

void dfs(vvi &al, int p, int i, int wt){
    color[mp[{min(p, i), max(p, i)}]] = wt;
    for(auto v : al[i]){
        if(v == p) continue;
        if(wt == 2){
            dfs(al, i, v, 3);
        }
        else{
            dfs(al, i, v, 2);
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
  
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vvi al(n + 1);
        mp.clear(); color.clear();
        color.resize(n);
        for(int i = 0; i < n - 1; i++){
            int u, v; cin >> u >> v;
            al[u].pb(v);
            al[v].pb(u);
            if(u > v) swap(u, v);
            mp[{u, v}] = i;
        }
        bool flag = true;
        for(int i = 1; i <= n; i++){
            if(al[i].size() > 2){
                flag = false;
                break;
            }
        }
        if(flag){
            for(int i = 0; i < al[1].size(); i++){
                if(i & 1){
                    dfs(al, 1, al[1][i], 2);
                }
                else{
                    dfs(al, 1, al[1][i], 3);
                }
            }
            for(int i = 0; i < n - 1; i++){
                cout << color[i] << " ";
            }
            cout << '\n';
        }
        else cout << -1 << '\n';
    }
}
