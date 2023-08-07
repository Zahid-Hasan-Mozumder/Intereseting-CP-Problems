// Problem link: https://codeforces.com/contest/1857/problem/F

// Here, suppose, a + b = x and a * b = y
// It is obvious that a and b will be any divisor pairs of y
// And each divisor pairs provide different sum
// so there will be only one (a, b) pair for which, a + b = x and a * b = y

// Now, From (a + b) ^ 2 = a ^ 2 + 2ab + b ^ 2 we get, a ^ 2 + b ^ 2 = -----something
// By using, a ^ 2 + b ^ 2 in (a - b)^2 = a ^ 2 - 2ab + b ^ 2, we get a - b = sqrt((x * x) - (4 * y))
// Now, a + b = x and a - b = sqrt((x * x) - (4 * y)), so, from here we can find a and b
// And by using the count of a's and b's, we can calculate our answer

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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
        vll a(n);
        map<ll, ll> mp;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            mp[a[i]]++;
        }
        int q; cin >> q;
        while(q--){
            ll x, y; cin >> x >> y;
            ll ceil_x = (ll)ceil(sqrtl((x * x) - (4 * y)));
            ll floor_x = (ll)floor(sqrtl((x * x) - (4 * y)));
            if(ceil_x != floor_x){
                cout << 0 << " ";
                continue;
            }
            ll xx = ceil_x;
            ll a = (x + xx) / 2;
            ll b = x - a;
            ll ans = 0;
            if(mp.count(a) && mp.count(b)){
                if(a != b) ans = mp[a] * mp[b];
                else ans = (mp[a] * (mp[a] - 1)) / 2;
            }
            cout << ans << " ";
        }
        cout << '\n';
    }
}
