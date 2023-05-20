// Problem link: https://codeforces.com/problemset/problem/1738/C
// Video tutorial: https://www.youtube.com/watch?v=81kGNltSBXA&t=765s
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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
        int even = 0, odd = 0;
        vi a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(a[i] & 1) odd++;
            else even++;
        }
        int aliceTurns = (n + 1) / 2;
        bool flag = false;
        for(int e = aliceTurns; e >= 0; e -= 2){
            int o = aliceTurns - e;
            if(e > 0 && even >= e + (e - 1) && odd >= o + o){
                flag = true;
                break;
            }
            else if(o > 0 && odd >= o + (o - 1) && even >= e + e){
                flag = true;
                break;
            }
        }
        if(flag) cout << "Alice" << '\n';
        else cout << "Bob" << '\n';
    }
}
