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
const ll N = 1e3+10;
const ll M = 5e3+10;

ll dp[N][M];
ll s[N][M];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n,m,k;
    cin>>n>>m>>k;
    fore(i,1,m) dp[1][i] = 1, s[1][i] = (s[1][i-1]+dp[1][i])%mod;
    fore(i,2,n){
        fore(j,1,m){
            ll l = 1, r = j-k;
            if(j-k>=1) dp[i][j] = s[i-1][r]%mod;
            if(j+k<=m){
                l = j+k, r = m;
                dp[i][j] = (dp[i][j] + (s[i-1][r]-s[i-1][l-1]+mod)%mod)%mod;
            }
            if(k == 0){
                dp[i][j] = (dp[i][j] - dp[i-1][j] + mod) % mod;
            }
            s[i][j] = (s[i][j-1]+dp[i][j])%mod;
        }
    }
    cout<<s[n][m]<<endl;

    return 0;
}