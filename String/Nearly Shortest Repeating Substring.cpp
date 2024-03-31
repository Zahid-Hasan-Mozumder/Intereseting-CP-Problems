// Problem link: https://codeforces.com/contest/1950/problem/E
// Explanation video: https://www.youtube.com/watch?v=geI3Bmnq5fM&t=1280s
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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

bool isEqual(string a, string b){
    int mismatch = 0;
    for(int i = 0; i < a.size(); i++){
        if(a[i] != b[i])
            mismatch++;
    }
    if(mismatch <= 1) return true;
    else return false;
}

void zahid(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
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
        string s; cin >> s;
        vi d;
        for(int i = 1; i * i <= n; i++){
            if(n % i == 0){
                d.pb(i);
                if(n / i != i) d.pb(n / i);
            }
        }
        sort(d.begin(), d.end());
        for(int i = 0; i < d.size(); i++){
            string x = s.substr(0, d[i]);
            string y = s.substr(n - d[i]);

            string f = "", b = "";
            for(int j = 0; j < (n / d[i]); j++){
                f += x;
                b += y;
            }
            if(isEqual(f, s) || isEqual(b, s)){
                cout << d[i] << '\n';
                break;
            }
        }
    }
}
