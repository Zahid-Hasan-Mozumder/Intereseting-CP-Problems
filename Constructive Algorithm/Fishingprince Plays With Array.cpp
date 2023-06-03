// Problem link: https://codeforces.com/problemset/problem/1696/C

// Break both array's each elements until it is not divisible by m
// Then check if ith position's value of both newly created array is same or not
// For example,
// if m = 2 and
// a : 1 2 2 8 2 2
// b : 1 16
// Then after breaking a and b with m,
// a : 1  1 1  1 1  1 1 1 1 1 1 1 1  1 1  1 1
// b : 1  1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1


//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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
        ll n, m; cin >> n >> m;
        vll a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        ll k; cin >> k;
        vll b(k);
        for(int i = 0; i < k; i++) cin >> b[i];
        ll aa_size = 0, bb_size = 0;
        vpll aa, bb;
        for(int i = 0; i < n; i++){
            ll cnt = 1;
            while(a[i] % m == 0){
                cnt *= m;
                a[i] /= m;
            }
            aa.pb({a[i], cnt});
            aa_size += cnt;
        }
        for(int i = 0; i < k; i++){
            ll cnt = 1;
            while(b[i] % m == 0){
                cnt *= m;
                b[i] /= m;
            }
            bb.pb({b[i], cnt});
            bb_size += cnt;
        }
        if(aa_size != bb_size) cout << "No" << '\n';
        else{
            bool flag = true;
            int i = 0, j = 0;
            while(i < aa.size() && j < bb.size()){
                if(aa[i].ff != bb[j].ff){
                    flag = false;
                    break;
                }
                else{
                    ll mn = min(aa[i].ss, bb[j].ss);
                    aa[i].ss -= mn;
                    bb[j].ss -= mn;
                    if(aa[i].ss == 0) i++;
                    if(bb[j].ss == 0) j++;
                }
            }
            if(flag) cout << "Yes" << '\n';
            else cout << "No" << '\n';
        }
    }
}
