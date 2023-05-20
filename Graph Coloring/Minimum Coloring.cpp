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

int n, m, a, b, c, d;

void dfs(vvi &ans, vvb &vis, int i, int j, int curr){
    if(i < 0 || i >= n || j < 0 || j >= m || vis[i][j] || ans[i][j] == 3)
        return;
    vis[i][j] = true;
    if(curr == 1){
        ans[i][j] = 2;
        dfs(ans, vis, i + 1, j, 2);
        dfs(ans, vis, i - 1, j, 2);
        dfs(ans, vis, i, j + 1, 2);
        dfs(ans, vis, i, j - 1, 2);
    }
    if(curr == 2){
        ans[i][j] = 1;
        dfs(ans, vis, i + 1, j, 1);
        dfs(ans, vis, i - 1, j, 1);
        dfs(ans, vis, i, j + 1, 1);
        dfs(ans, vis, i, j - 1, 1);
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
        cin >> n >> m;
        cin >> a >> b;
        cin >> c >> d;
        a--; b--; c--; d--;
        vvi ans(n, vi(m, -1));
        vvb vis(n, vb(m, false));
        dfs(ans, vis, a, b, 2);
        if((abs(a - c) + abs(b - d)) % 2 != 0){
          
            // If no collision then, put value normally
          
            dfs(ans, vis, a, b, 2);
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    cout << ans[i][j] << " ";
                }
                cout << '\n';
            }    
        }
        else{
          
            // If collision happens then, just do the below things
            //        3
            //      3 2 3
            //        3
            // Here, 2 is the color of (x2, y2) cell
          
            ans[c][d] = 2;
            if(c - 1 >= 0) ans[c - 1][d] = 3;
            if(c + 1 < n) ans[c + 1][d] = 3;
            if(d + 1 < m) ans[c][d + 1] = 3;
            if(d - 1 >= 0) ans[c][d - 1] = 3;
            dfs(ans, vis, a, b, 2);
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    cout << ans[i][j] << " ";
                }
                cout << '\n';
            }
        }
    }
}
