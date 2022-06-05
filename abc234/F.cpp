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
const ll mod = 998244353;
const ll N = 5e3+10;

ll fac[N], invfac[N];

ll inv(ll x){
    ll res = 1;
    ll b = mod-2;
    while(b){
        if(b&1) res = res*x%mod;
        x = x*x%mod;
        b >>= 1;
    }
    return res;
}

void init(){
    fac[0] = invfac[0] = 1;
    for(ll i=1;i<N;++i) fac[i] = (fac[i-1]*i)%mod;
    for(ll i=1;i<N;++i) invfac[i] = inv(fac[i]);
}

ll C(ll n,ll m){
    return fac[n]*invfac[m]%mod*invfac[n-m]%mod;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    string s;
    cin>>s;
    ll n = s.size();
    vector<vector<ll>> dp(26,vector<ll>(n+1));
    vector<ll> freq(26);
    for(auto ch: s) freq[ch-'a']++;
    for(ll i=0;i<=min(n,freq[0]);++i) dp[0][i] = 1;
    for(ll i=1;i<26;++i){
        dp[i][0] = 1;
        for(ll j=1;j<=n;++j){
            // dp[i][j] = dp[i-1][j-k] * C(j,k) (0 <= k <= min(freq[i],j))
            for(ll k=0;k<=min(freq[i],j);++k){
                dp[i][j] = (dp[i][j] + dp[i-1][j-k]*C(j,k)%mod)%mod;
            }
        }
    }
    ll ans = 0;
    fore(i,1,n) ans = (ans+dp[25][i])%mod;
    cout<<ans<<endl;
    // fore(i,0,3){
    //     fore(j,1,3){
    //         cout<<dp[i][j]<<" \n"[j==3];
    //     }
    // }

    return 0;
}