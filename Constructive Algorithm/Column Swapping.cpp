// Problem link: https://codeforces.com/problemset/problem/1684/C
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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
        int n, m; cin >> n >> m;
        vvi a(n, vi(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> a[i][j];
            }
        }
        set<int> ind;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m - 1; j++){
                if(a[i][j] > a[i][j + 1]){
                    ind.insert(j);
                }
            }
        }
        if(ind.size() == 0) cout << 1 << " " << 1 << '\n';
        else if(ind.size() == 1){
            int k = *ind.begin();
            int l = k + 1;
            // 1 7
            // 1 2 4 3 3 3 5
            for(int j = l; j < m - 1; j++){
                bool flag = true;
                for(int i = 0; i < n; i++){
                    if(a[i][j] != a[i][j + 1]){
                        flag = false;
                        break;
                    }
                }
                if(flag) l++;
                else break;
            }
            // 1 10
            // 1 2 3 3 3 3 3 2 3 3 
            for(int j = k; j > 0; j--){
                bool flag = true;
                for(int i = 0; i < n; i++){
                    if(a[i][j] != a[i][j - 1]){
                        flag = false;
                        break;
                    }
                }
                if(flag) k--;
                else break;
            }
            for(int i = 0; i < n; i++){
                swap(a[i][k], a[i][l]);
            }
            ind.clear();
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m - 1; j++){
                    if(a[i][j] > a[i][j + 1]){
                        ind.insert(j);
                    }
                }
            }
            if(ind.size()) cout << -1 << '\n';
            else{
                cout << k + 1 << " " << l + 1 << '\n';
            }
        }
        else{
            // 6 3 1 or
            // 6 4 5 1 etc
            int k = *ind.begin();
            while(ind.size() > 1) ind.erase(*ind.begin());
            int l = *ind.begin() + 1;
            for(int i = 0; i < n; i++){
                swap(a[i][k], a[i][l]);
            }
            ind.clear();
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m - 1; j++){
                    if(a[i][j] > a[i][j + 1]){
                        ind.insert(j);
                    }
                }
            }
            if(ind.size()) cout << -1 << '\n';
            else{
                cout << k + 1 << " " << l + 1 << '\n';
            }
        }
    }
}
