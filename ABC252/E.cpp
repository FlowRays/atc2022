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

struct edge{
    ll to,cost,idx;
};

// 显然生成树最小的ans是最短路，那么这个生成树可以通过dijkstra构造
// 因为dijkstra算法的执行过程实质上就是构造出了这么一个生成树

vector<ll> dijkstra(ll s,vector<vector<edge>> &g){
    vector<ll> dist(g.size(),1e18);
    vi idx(g.size());
    dist[s] = 0;
    priority_queue<pii,vector<pii>,greater<pii>> q;
    q.push({0,s});
    while(q.size()){
        auto [d,u] = q.top();
        q.pop();
        if(dist[u] != d) continue;
        for(auto [v,c,i]: g[u]){
            if(dist[v]>dist[u]+c){
                dist[v] = dist[u]+c;
                q.push({dist[v],v});
                idx[v] = i; // 通过第几条边在dijkstra树中最终到达node v
            }
        }
    }
    return idx;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n,m;
    cin>>n>>m;
    vector<vector<edge>> g(n);
    forn(i,m){
        ll a,b,c;
        cin>>a>>b>>c;
        g[a-1].pb({b-1,c,i});
        g[b-1].pb({a-1,c,i});
    }
    vi idx = dijkstra(0,g);
    fore(i,1,n-1) cout<<idx[i]+1<<" ";
    cout<<endl;

    return 0;
}