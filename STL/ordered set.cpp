// Problem link: https://www.spoj.com/problems/ORDERSET/en/
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>
#include <cmath>
#include <climits>
#include <sstream>
#include <string>

using namespace std;

// Header and driver files for ordered_set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

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

    ordered_set s;
    int q; cin>>q;
    while(q--){
        string qt; cin>>qt;
        if(qt == "I"){
            int x; cin>>x;
            s.insert(x);
        }
        else if(qt == "D"){
            int x; cin>>x;
            if(s.find(x) != s.end()){
                s.erase(x);
            }
        }
        else if(qt == "K"){
            int x; cin>>x;
            if(x > s.size()){
                cout<< "invalid" << '\n';
            }
            else{
                x--;
                cout<< *(s.find_by_order(x)) << '\n';
            }
        }
        else if(qt == "C"){
            int x; cin>>x;
            cout<< s.order_of_key(x) << '\n';
        }
    }
}
