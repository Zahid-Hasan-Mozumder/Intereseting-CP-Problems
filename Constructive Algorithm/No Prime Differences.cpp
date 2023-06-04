// Problem link: https://codeforces.com/contest/1838/problem/C
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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

bool isPrime(ll n){
    if(n == 1) return false;
    for(ll i=2; i*i<=n; i++){
        if(n%i == 0) return false;
    }
    return true;
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
        int n, m; cin >> n >> m;
        vvi a(n + 1, vi(m + 1, 0));
        bool flag = isPrime(m);
        if(flag){
            if(n == 3) cout << -1 << '\n';
            else{
                int mid = (n + 1) / 2;
                for(int i = mid; i >= 1; i--){
                    for(int j = 1; j <= m; j++){
                        if(i == mid){
                            a[i][j] = j;
                        }
                        else{
                            a[i][j] = (m * (2 * (mid - i))) + j;
                        }
                    }
                }
                for(int i = mid + 1; i <= n - 1; i++){
                    for(int j = 1; j <= m; j++){
                        a[i][j] = (m * (1 + (2 * (i - mid)))) + j;
                    }
                }
                for(int j = 1; j <= m; j++){
                    a[n][j] = m + j;
                }
            }
        }
        else{
            if(n == 2) cout << -1 << '\n';
            else{
                for(int i = 1; i <= n; i++){
                    for(int j = 1; j <= m; j++){
                        a[i][j] = j + (m * (i - 1));
                    }
                }
            }
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                cout << a[i][j] << " ";
            }
            cout << '\n';
        }
        cout << '\n';
    }
}
