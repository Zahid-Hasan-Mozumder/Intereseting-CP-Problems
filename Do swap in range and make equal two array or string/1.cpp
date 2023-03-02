// Problem link: https://codeforces.com/contest/1800/problem/E1
// Problem link: https://codeforces.com/contest/1800/problem/E2
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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
        int n, k; cin>>n>>k;
        string a, b; cin>>a>>b;
        if(a == b) cout<< "YES" << '\n';
        else{
            bool flag = true;
            for(int i=0; i<n; i++){
                // This means we can't move these elements
                if(i - k < 0 && i + k > n-1){
                    // As we can't move them so they must be equal
                    if(a[i] != b[i]){
                        flag = false;
                        break;
                    }
                }
            }
            if(flag){
                // If the above conditions are perfect then now, only both string's element's frequency should be same 
                sort(a.begin(), a.end());
                sort(b.begin(), b.end());
                if(a == b) cout<< "YES" << '\n';
                else cout<< "NO" << '\n';
            }
            else{
                cout<< "NO" << '\n';
            }
        }
    }
}
