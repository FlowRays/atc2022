/*
    multiset:
        1.erase(x) 会删除所有的x
        2.count(x) O(k + logN) k=count(x)
            如果每次都count,那么极端情况下可能会有O(Q^2)
        3.find(x) O(logN) 比count好
*/

#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define fore(i, l, r) for (int i = int(l); i <= int(r); ++i)
#define sz(a) int((a).size())
#define endl "\n"
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define pb push_back
#define vi vector<int>

using namespace std;
using ll = long long;
using ull = unsigned long long;

const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;
const int N = 1e5+10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    multiset<int> s;
    int q;
    cin>>q;
    while(q--){
        int op;
        cin>>op;
        if(op == 1){
            int x;
            cin>>x;
            s.insert(x);
        }
        else if(op == 2){
            int x,c;
            cin>>x>>c;
            while(c-- && s.find(x)!=s.end()){
                s.erase(s.find(x));
            }
        }
        else{
            cout<<*s.rbegin()-*s.begin()<<endl;
        }
    }

    return 0;
}