// Problem link: https://codeforces.com/problemset/problem/1750/C
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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

ll POW(ll a, ll b){
    if(b == 0)
        return 1;
    if(b == 1)
        return a;
    ll x = POW(a, b/2);
    if(b&1) return (x * x * a);
    else return (x * x);
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
        string a, b; cin >> a >> b;
        vi cng(n, 0);
        int seg = 0;
        for(int i = 1; i < n; i++){
            if(a[i] == '0' && a[i - 1] == '1') seg++;
            cng[i] += seg;
        }
        seg = 0;
        for(int i = n - 2; i >= 0; i--){
            if(a[i] == '0' && a[i + 1] == '1') seg++;
            cng[i] += seg;
        }
        set<char> s;;
        for(int i = 0; i < n; i++){
            if(cng[i] & 1){
                if(b[i] == '1') b[i] = '0';
                else b[i] = '1';
            }
            s.insert(b[i]);
        }
        if(s.size() == 2) cout << "NO" << '\n';
        else{
            cout << "YES" << '\n';
            vpii ans;
            int l = -1, r = -1;
            for(int i = 0; i < n; i++){
                if(a[i] == '1'){
                    if(l == -1) l = i, r = i;
                    else r++;
                }
                else{
                    if(l != -1 && r != -1){
                        ans.pb({l, r});
                        l = -1, r = -1;
                    }
                }
            }
            if(l != -1 && r != -1) ans.pb({l, r});
            if(*s.begin() == '1'){
                ans.pb({0, 0});
                ans.pb({1, n - 1});
                ans.pb({0, n - 1});
            }
            cout << ans.size() << '\n';
            for(int i = 0; i < ans.size(); i++){
                cout << ans[i].ff + 1 << " " << ans[i].ss + 1 << '\n';
            }
        }
        
    }
}
