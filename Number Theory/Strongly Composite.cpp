// Problem link: https://codeforces.com/contest/1823/problem/C
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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
const int sz = 1e5+2;
const double pi = acos(-1.0);
const double PI = 3.1415926535897;

vector<bool> mark(sz, 0);
vector<int> primes;

void SEIVE(){
    mark[0] = 1;
    mark[1] = 1;
    for(int i=4; i<sz; i+=2)
        mark[i] = 1;
    for(int i=3; i*i<sz; i+=2){
        if(!mark[i]){
            for(int j=i*i; j<sz; j+=(i*2)){
                mark[j] = 1;
            }
        }
    }
    primes.pb(2);
    for(int i=3; i<sz; i+=2){
        if(!mark[i])
            primes.pb(i);
    }
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
    SEIVE();

    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vi a(n);
        map<int, int> mp;
        for(int i=0; i<n; i++){
            cin>>a[i];
            int tmp = a[i];
            for(int j=0; j<primes.size() && primes[j] * primes[j] <= tmp; j++){
                while(tmp % primes[j] == 0){
                    mp[primes[j]]++;
                    tmp /= primes[j];
                }
            }
            if(tmp > 1) mp[tmp]++;
        }
        int k = 0;
        int cnt = 0;
        for(auto it : mp){
            int curr = it.ss / 2;
            k += curr;
            if(it.ss & 1) cnt++;
        }
        k += (cnt / 3);
        cout<< k << '\n';
    }
}
