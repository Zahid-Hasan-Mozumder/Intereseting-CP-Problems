// Problem link: https://codeforces.com/contest/1878/problem/E
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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

vvi a, len;

int chk(int l, int m){
    int cur = 0;
    for(int j = 0; j < 32; j++){
        int r = l + len[l][j] - 1;
        if(r >= m){
            cur += pow(2, j);
        }
    }
    return cur;
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
        a.clear(); len.clear();
        a.resize(n + 1, vi(32, 0)); len.resize(n + 1, vi(32, 0));
        
        for(int i = 1; i <= n; i++){
            int x; cin >> x;
            int j = 0;
            while(x){
                if(x & 1) a[i][j] = 1;
                x >>= 1;
                j++;
            }
        }
        
        for(int j = 0; j < 32; j++){
            int cur = 0;
            for(int i = n; i >= 1; i--){
                if(a[i][j]){
                    cur++;
                    len[i][j] = cur;
                }
                else cur = 0;
            }    
        }
        
        int q; cin >> q;
        while(q--){
            int l, k; cin >> l >> k;
            int ans = -1;
            int low = l, high = n;
            while(low <= high){
                int mid = (low + high) / 2;
                if(chk(l, mid) >= k){
                    ans = mid;
                    low = mid + 1;
                }
                else high = mid - 1;
            }
            cout << ans << " ";
        }
        cout << '\n';
    }
}
