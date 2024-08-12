#include <bits/stdc++.h>
using namespace std;

#define fastIO ios_base::sync_with_stdio(0),cin.tie(NULL),cout.tie(NULL)

#define V vector
#define pb push_back
#define pf push_front
#define f first
#define s second
#define mp make_pair
#define mt make_tuple
#define all(v) v.begin(),v.end()
#define endl '\n'
#define SZ(x) (int)x.size()
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
using pi = pair<int, int>;

constexpr ull MOD2 = (1ULL<<32);
constexpr int MOD = 1e9+7;
constexpr int MAXN = 1e5+5;

typedef priority_queue<int,vector<int>,greater<int>> pqg; ///Min
typedef priority_queue<int> pq; ///Max
int n,m;
vector<int> dijkstra(int start, vector<vector<pair<int, int>>> &graph) {
    const int INF = INT_MAX;
    int n = graph.size();
    vector<int> dist(n + 1, INF);
    dist[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.emplace(0, start);
    while (!pq.empty()) {
        auto [du, u] = pq.top();
        pq.pop();

        if (du > dist[u])
            continue;

        for (auto &[v, dv] : graph[u]) {
            if (du + dv < dist[v]) {
                dist[v] = du + dv;
                pq.emplace(dist[v], v);
            }
        }
    }

    return dist;
}

int numero(int i,int j){
    return i*m+j;
}


void solve() {
    
    cin >> n >> m;
    V<V<pair<int,int>>>g(n*m+1);
    V<vi>l(n + 1 , vi(m + 1, 0) );

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            char x;
            cin >> x;
            l[i][j] = x - '0';
        }
    }
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            vi pos(10 , -1);
            vi pos2(10, -1);
            for(int x = j+1 ; x < m ; x++){
                
                double pendiente = (double)(l[i][x] - l[i][j])/(x - j);
                int aux = 0;
                for(auto d : pos){
                    if(d == -1) continue;
                    double np = (double)( l[i][d] - l[i][j] ) / (d - j);
                    if(np > pendiente) aux = 1;
                }

                for(auto d : pos2){
                    if(d == -1) continue;
                    double np = (double)( l[i][d] - l[i][j] ) / (d - j);
                    if(np > pendiente) aux = 1;
                }

                if( !aux ){
                    //cout<<i<<' '<<j<< " a " << i <<' ' << x << endl;
                    g[ numero(i , j) ].emplace_back( numero( i , x ) , 1);
                    g[ numero(i , x) ].emplace_back( numero( i , j ) , 1);
                }
                if(pos[l[i][x]] == -1)pos[l[i][x]] = x;
                pos2[l[i][x]] = x;
            }

        }
    }


    for(int j = 0 ; j < m ; j++){
        for(int i = 0 ; i < n ; i++){
            vi pos(10 , -1);
            vi pos2(10 , -1);
            for(int x = i+1 ; x < n ; x++){
                double pendiente = (double)(l[x][j] - l[i][j])/(x - i);
                int aux = 0;
                for(auto d : pos){
                    if(d == -1) continue;
                    double np = (double)( l[d][j] - l[i][j] ) / (d - i);
                    if(np > pendiente) aux = 1;
                }
                for(auto d : pos2){
                    if(d == -1) continue;
                    double np = (double)( l[d][j] - l[i][j] ) / (d - i);
                    if(np > pendiente) aux = 1;
                }
                if( !aux ){
                    //cout<<i<<' '<<j<< " a " << i <<' ' << x << endl;
                    g[ numero(i , j) ].emplace_back( numero( x , j ) , 1 );
                    g[ numero(x , j) ].emplace_back( numero( i , j ) , 1);
                }
                if(pos[l[x][j]] == -1) pos[l[x][j]] = x;
                pos2[l[x][j]] = x;
            }

        }
    }

    auto ans = dijkstra( 0 , g );
    cout<<ans[n*m -1] - 1  << endl;

}

int main() {

    fastIO;
    solve();
}