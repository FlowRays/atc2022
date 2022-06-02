#include <bits/stdc++.h>

#define forn(i, n) for (ll i = 0; i < ll(n); i++)
#define fore(i, l, r) for (ll i = ll(l); i <= ll(r); ++i)
#define sz(a) ll((a).size())
#define endl "\n"
#define pii pair<ll,ll>
#define all(x) x.begin(),x.end()
#define pb push_back
#define vi vector<ll>

using namespace std;
using ll = long long;
using ull = unsigned long long;

const ll inf = 0x3f3f3f3f;
const ll mod = 1e9+7;
const ll N = 1e5+10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin>>n;
    vi a(n);
    map<ll,ll> mp;
    forn(i,n) cin>>a[i],mp[a[i]]++;
    ll ans = n*(n-1)*(n-2)/6;
    for(auto [x,y]: mp){
        if(y>=2) ans -= y*(y-1)/2*(n-y);
        if(y>=3) ans -= y*(y-1)*(y-2)/6;
    }
    cout<<ans<<endl;

    return 0;
}