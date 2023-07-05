#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define int long long


void bfs(int node, int n, vector<int> path[], vector<tuple<ll,ll,ll>> adj[],vector<int> &as)
{
    
    
    queue<pair<int, int> > qu;
    bool vis[n+1];
    
    qu.push({ node, -1 });
    vis[node] = true;
 
    while (!qu.empty()) {
        pair<int, int> p = qu.front();
 
        qu.pop();
        vis[p.first] = true;
 
        for (auto child : adj[p.first]) {
            if (!vis[get<0>(child)]) {
                qu.push({get<0>(child), p.first });

                path[get<0>(child)] = path[p.first];
                path[get<0>(child)].push_back(get<2>(child)+path[p.first][path[p.first].size()-1]);
                as[get<0>(child)] = as[p.first] + get<1>(child);
            }
        }
    }
}




void solve(){
    ll n;
    cin>>n;
    vector<tuple<ll,ll,ll>> adj[n+1]; 
    vector<int> as(n+1,0);
    as[1]=0;
    vector<int> path[n+1];
    path[1].push_back(0);
    for(int i=2; i<=n; i++){
        ll p,a,b;
        cin>>p>>a>>b;
        adj[p].push_back(make_tuple(i,a,b));
    }
    
    
    bfs(1, n, path, adj, as);
    
   
   for(int i=2; i<=n; i++){
    
    int x = as[i];
    cout<<x<<" ";
//     auto ans = lower_bound(path[i].begin(),path[i].end(),x);
//     if(*ans == x){
//         cout<<ans - path[i].begin()<<" ";
//     }else{
//         cout<<ans - path[i].begin() - 1<<" ";
//     }
//    }
   }
//    cout<<endl;
    
}

signed main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}