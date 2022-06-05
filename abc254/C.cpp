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
    int n,k;
    cin>>n>>k;
    vi a(n);
    forn(i,n) cin>>a[i];
    auto b = a;
    sort(all(b));
    bool ok = true;
    forn(i,k){
        vi t;
        for(int j=i;j<n;j+=k){
            t.pb(a[j]);
        }
        sort(all(t));
        for(int j=i,p=0;j<n;j+=k,p++){
            if(t[p]!=b[j]){
                ok = false;
                break;
            }
        }
        if(!ok) break;
    }
    cout<<(ok ? "Yes" : "No")<<endl;

    return 0;
}