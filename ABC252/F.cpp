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
    ll n,l;
    cin>>n>>l;
    vi a(n);
    forn(i,n) cin>>a[i];
    ll s = accumulate(all(a),0ll);
    ll ans = 0;
    priority_queue<ll,vector<ll>,greater<ll>> q;
    if(l>s) q.push(l-s);
    forn(i,n) q.push(a[i]);
    while(q.size()>1){
        ll t1 = q.top(); q.pop();
        ll t2 = q.top(); q.pop();
        ans += t1+t2;
        q.push(t1+t2);
    }
    cout<<ans<<endl;

    return 0;
}