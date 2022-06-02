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
        map<int,int> s;
        int q;
        cin>>q;
        while(q--){
            int op;
            cin>>op;
            if(op == 1){
                int x;
                cin>>x;
                s[x]++;
            }
            else if(op == 2){
                int x,c;
                cin>>x>>c;
                int cnt = s[x];
                c = min(cnt,c);
                s[x] -= c;
                if(s[x] == 0) s.erase(x);
            }
            else{
                cout<<(*s.rbegin()).first-(*s.begin()).first<<endl;
            }
        }

        return 0;
    }