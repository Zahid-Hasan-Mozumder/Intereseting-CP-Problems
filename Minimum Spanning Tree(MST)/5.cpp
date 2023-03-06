// Problem link: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1541
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

void initialize(int n){
    r.resize(n, 0);
    parent.resize(n, 0);
    for(int i=1; i<n; i++) parent[i] = i;
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

void zahid(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){

    zahid();

    int t; cin>>t;
    while(t--){
        int n, m; cin>>n>>m;
        edges.resize(m);
        for(int i=0; i<m; i++){
            cin>>edges[i].ss.ff>>edges[i].ss.ss>>edges[i].ff;
        }
        sort(edges.begin(), edges.end());
        int first_mst = 0, second_mst = INT_MAX;
        vi f_mst_edges;
        initialize(n+1);
        for(int i=0; i<edges.size(); i++){
            auto it = edges[i];
            int upu = findParent(it.ss.ff);
            int upv = findParent(it.ss.ss);
            if(upu != upv){
                first_mst += it.ff;
                f_mst_edges.pb(i);
                unionByRank(it.ss.ff, it.ss.ss);
            }
        }
        for(int j=0; j<f_mst_edges.size(); j++){
            initialize(n+1);
            int curr = 0;
            int taken = 0;
            for(int i=0; i<edges.size(); i++){
                if(i == f_mst_edges[j]) continue;
                auto it = edges[i];
                int upu = findParent(it.ss.ff);
                int upv = findParent(it.ss.ss);
                if(upu != upv){
                    curr += it.ff;
                    taken++;
                    unionByRank(it.ss.ff, it.ss.ss);
                }
            }
            if(taken == n-1){
                second_mst = min(second_mst, curr);
            }
        }
        cout<< first_mst << " " << second_mst << '\n';
    }
}
