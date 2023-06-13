// Problem link: https://www.hackerrank.com/contests/intra-department-programming-contestgreen-university-of-bangladesh/challenges/maximum-prefix-sum/problem
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>
#include <climits>

using namespace std;

#define ll long long int
#define vi vector<int>
#define vll vector<ll>

const int N = 2e5 + 5;
vll a(N), pre(N), mx(4 * N), lazy(4 * N);
int n, q;

void build(int ind, int l, int r){
    if(l == r){
        mx[ind] = pre[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * ind + 1, l, mid);
    build(2 * ind + 2, mid + 1, r);
    mx[ind] = max(mx[2 * ind + 1], mx[2 * ind + 2]);
}

void update(int ind, int l, int r, int i, ll val){
    if(lazy[ind]){
        mx[ind] += lazy[ind];
        if(l != r){
            lazy[2 * ind + 1] += lazy[ind];
            lazy[2 * ind + 2] += lazy[ind];
        }
        lazy[ind] = 0;
    }
    if(r < i || l > n - 1) return;
    if(l >= i && r <= n - 1){
        mx[ind] += val;
        if(l != r){
            lazy[2 * ind + 1] += val;
            lazy[2 * ind + 2] += val;
        }
        return;
    }
    int mid = (l + r) / 2;
    update(2 * ind + 1, l, mid, i, val);
    update(2 * ind + 2, mid + 1, r, i, val);
    mx[ind] = max(mx[2 * ind + 1], mx[2 * ind + 2]);
}

void zahid(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){

    zahid();

    cin >> n >> q;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        pre[i] = a[i];
        if(i) pre[i] += pre[i - 1];
    }
    build(0, 0, n - 1);
    while(q--){
        ll ind, val; cin >> ind >> val;
        ind--;
        ll cng = val - a[ind];
        a[ind] = val;
        update(0, 0, n - 1, ind, cng);
        cout << mx[0] << '\n';
    }
}
