// Problem link: https://codeforces.com/contest/1886/problem/B
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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

//const ll mod = 1e9 + 7;
const ll mod = 998244353;
const double pi = acos(-1.0);
const double PI = 3.1415926535897;
const double eps = 1e-6;

double px, py, ax, ay, bx, by;

bool chk(double m){
    double a0 = sqrt(((ax - 0.0) * (ax - 0.0)) + ((ay - 0.0) * (ay - 0.0)));
    double b0 = sqrt(((bx - 0.0) * (bx - 0.0)) + ((by - 0.0) * (by - 0.0)));
    double ap = sqrt(((ax - px) * (ax - px)) + ((ay - py) * (ay - py)));
    double bp = sqrt(((bx - px) * (bx - px)) + ((by - py) * (by - py))); 
    double ab = sqrt(((bx - ax) * (bx - ax)) + ((by - ay) * (by - ay)));
  
    if(a0 <= m && ap <= m) return true;
    if(b0 <= m && bp <= m) return true;
    if((a0 <= m || b0 <= m) && (ap <= m || bp <= m) && (ab <= 2.0 * m)) return true;
    return false;
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
        cin >> px >> py >> ax >> ay >> bx >> by;
        double l = 0, r = 1e7;
        int count = 100;
        while(count--){
            double m = (l + r) / 2.0;
            if(chk(m)){
                r = m;
            }
            else{
                l = m;
            }
        }
        cout << fixed << setprecision(10) << r << '\n';
    }
}
