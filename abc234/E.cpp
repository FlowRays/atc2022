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
    string x;
    cin>>x;
    int len = x.size();
    auto check = [&](int a,int b,int len){
        int x = a+(b-a)*(len-1);
        return x>=0 && x<=9;
    };
    auto gen = [&](int a,int b,int len){
        string res;
        int d = b-a;
        forn(i,len){
            res.pb(a+'0');
            a += d;
        }
        return res;
    };
    if(len<=2) cout<<x<<endl;
    else{
        int a = x[0]-'0', b = x[1]-'0';
        for(int i=a;i<=9;++i){
            for(int j=(i==a ? b : 1);j<=9;++j){
                if(check(i,j,len) && gen(i,j,len)>=x){
                    cout<<gen(i,j,len)<<endl;
                    return 0;
                }
            }
        }
    }

    return 0;
}