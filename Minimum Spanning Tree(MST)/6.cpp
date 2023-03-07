// Problem link: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2833
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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
const int maxN = 5e6+5;
const int sz = 1e6+2;
const double pi = acos(-1.0);
const double PI = 3.1415926535897;

vpipii edges;
vi r, parent;
ll airport = 0;
ll ans = 0;
int n, m;
ll aircost;

void initialize(){
    r.resize(n + 1, 0);
    parent.resize(n + 1, 0);
    ans = 0, airport = 0;
    for(int i=1; i<=n; i++) parent[i] = i;
}

int findParent(int u){
    if(u == parent[u])
        return u;
    return parent[u] = findParent(parent[u]);
}

void unionByRank(int u, int v){
    int upu = findParent(u);
    int upv = findParent(v);
    if(upu != upv){
        if(r[upu] < r[upv]){
            parent[upu] = upv;
        }
        else if(r[upu] > r[upv]){
            parent[upv] = upu;
        }
        else{
            parent[upv] = upu;
            r[upu]++;
        }
    }
}

void krushkals(vpipii &edges){
    initialize();
    sort(edges.begin(), edges.end());
    for(auto it : edges){
        int upu = findParent(it.ss.ff);
        int upv = findParent(it.ss.ss);
        if(upu == upv) continue;
        ans += it.ff;
        if(it.ff >= aircost){
            ans -= it.ff;
            airport++;
        }
        unionByRank(it.ss.ff, it.ss.ss);
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

    int cs = 1;
    int t; cin>>t;
    while(t--){
        edges.clear();
        cin>>n>>m>>aircost;
        for(int i=0; i<m; i++){
            int u, v, w;
            cin>>u>>v>>w;
            edges.pb({w, {u, v}});
        }
        krushkals(edges);
        for(int i=1; i<=n; i++){
            if(findParent(i) == i)
                airport++;
        }
        ans += (airport * aircost);
        cout<< "Case #" << cs << ": " << ans << " " << airport << '\n';
        cs++;
    }
}
