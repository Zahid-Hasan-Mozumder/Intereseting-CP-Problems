// Problem link: https://codeforces.com/contest/1791/problem/F
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>
#include <cmath>
#include <climits>
#include <sstream>
#include <string>

using namespace std;

#define ll long long int

#define pii pair<int, int>
#define pli pair<ll, int>
#define pil pair<int, ll>
#define pll pair<ll, ll>
#define psi pair<string, int>
#define psl pair<string, ll>
#define piii pair<pair<int, int>, int>
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
#define vvpii vector<vector<pair<int, int>>>
#define vvpll vector<vector<pair<ll, ll>>>
#define vvpli vector<vector<pair<ll, int>>>
#define vvpil vector<vector<pair<int, ll>>>
#define si stack<int>
#define sll stack<ll>
#define qi queue<int>
#define qll queue<ll>
#define pb push_back
#define pf push_front
#define ff first
#define ss second

const ll mod = 1e9+7;
const int maxN = 1e6;
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
        int n, q; cin>>n>>q;
        vi a(n);
        for(int i=0; i<n; i++) cin>>a[i];
        int len = ceil(sqrt(n));
        vi b(len, 0), mx(n, 0);
        while(q--){
            int qt; cin>>qt;
            if(qt == 1){
                int l, r; cin>>l>>r; 
                l--; r--;
                for(int i=l; i<=r;){
                    if(i%len==0 && i+len-1<=r){
                        b[i / len]++;
                        i += len;
                    }
                    else{
                        int val = 0;
                        while(a[i]){
                            val += (a[i] % 10);
                            a[i] /= 10;
                        }
                        a[i] = val;
                        i++;
                    }
                }
            }
            else if(qt == 2){
                int x; cin>>x;
                x--;
                if(b[x / len]){
                    if(mx[x] < 6){
                        int cng = b[x / len] - mx[x];
                        for(int i=1; i<=min(cng, 6); i++){
                            int curr = 0;
                            while(a[x]){
                                curr += a[x] % 10;
                                a[x] /= 10;
                            }
                            a[x] = curr;
                        }
                        mx[x] += cng;
                    }
                    cout<< a[x] << '\n';
                }
                else{
                    cout<< a[x] << '\n';
                }
            }
        }
    }
}
