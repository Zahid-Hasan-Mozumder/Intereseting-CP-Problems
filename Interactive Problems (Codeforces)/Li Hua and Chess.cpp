// Problem link: https://codeforces.com/contest/1797/problem/C
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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

const int mod = 1e9+7;
//const int mod = 998244353;
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

    int t; cin>>t;
    while(t--){
        int n, m; cin >> n >> m;
        int dist, r = -1, c = -1; 

        // question 1
        cout<< "?" << " " << 1 << " " << 1 << '\n';
        cout.flush();
        cin >> dist;
        if(dist == 0){
            cout << "!" << " " << 1 << " " << 1 << '\n';
            cout.flush();
        }
        else r = min(n, 1 + dist); c = min(m, 1 + dist);
        
        if(r != -1 && c != -1){
            // question 2
            int x1, y1, x2, y2;
            cout<< "?" << " " << r << " " << c << '\n';
            cout.flush();
            cin >> dist;
            if(dist == 0){
                cout << "!" << " " << r << " " << c << '\n';
                cout.flush();    
            }
            else{
                // question 3
                x1 = r;
                y1 = max(1, c - dist);
                x2 = max(1, r - dist);
                y2 = c;

                cout<< "?" << " " << x1 << " " << y1 << '\n';
                cout.flush();
                cin >> dist;
                if(dist == 0){
                    cout << "!" << " " << x1 << " " << y1 << '\n';
                    cout.flush();    
                }
                else{
                    cout << "!" << " " << x2 << " " << y2 << '\n';
                    cout.flush();
                }
            }
        }
    }
}
