#include <bits/stdc++.h>
#define x first
#define y second
#define cute_prov0nce main
#define int long long
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int mod = 998244353;

void solve()
{   
    int xs, ys, xt, yt;
    cin >> xs >> ys >> xt >> yt;
    int n;
    cin >> n;
    vector<array<int, 3>> ve(n+2);
    vector<vector<double>> d(n+2, vector<double> (n+2, -1));
    for(int i = 1; i <= n; i ++){
        int x, y, r;
        cin >> x >> y >> r;
        ve[i] = {x, y, r};
    }
    ve[0] = {xs, ys, 0};
    ve[n+1] = {xt, yt, 0};
    auto dist = [&](auto i, auto j)->double{
        if(d[i][j] != -1)return d[i][j];
        else{
            d[i][j] = max(0.0, sqrt((ve[i][0]-ve[j][0]) * (ve[i][0]-ve[j][0]) + (ve[i][1]-ve[j][1])*(ve[i][1]-ve[j][1])) - ve[i][2]-ve[j][2]);
            d[j][i] = d[i][j];
            return d[i][j];
        }
    };
    vector<double> dis(n+2, 1e18), vis(n+2);
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
    pq.push({0.0, 0});
    dis[0] = 0;
    while(!pq.empty()){
        auto [_, u] = pq.top(); pq.pop();
        if(vis[u])continue;
        vis[u] = 1;
        for(int j = 1; j <= n+1; j ++){
            if(!vis[j] && dis[j] >= dis[u] + dist(u, j)){
                dis[j] = dis[u] + dist(u, j);
                pq.push({dis[j], j});
            }
        }
    }
    cout <<fixed << setprecision(15) << dis[n+1] << '\n';

}
signed cute_prov0nce()
{   
#ifdef ACM_LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}