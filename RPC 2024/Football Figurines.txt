//solution for  Football Figurines from winter contest and RPC 2024 contest 08


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
constexpr int MAXN = 1e6+5;

typedef priority_queue<int,vector<int>,greater<int>> pqg; ///Min
typedef priority_queue<int> pq; ///Max

V<ll> fib(MAXN , 0);
V<ll> dp(MAXN , -1);

void fibonacci(int N) {   
    
    fib[0] = 0;
    fib[1] = 1;
    
    for (int i = 2; i < N ; i++){
        fib[i] = ( ( fib[i - 1] % MOD ) + ( fib[i - 2] % MOD ) ) % MOD;
    }
    
}

ll sol(ll k){
    
    if( k <= 1 ) return k;
    
    if( dp[k] != -1 ) return dp[k];

    return dp[k] = ( ( sol(k - 1) % MOD ) + ( sol(k - 2) % MOD ) + ( fib[ k + 1] ) )%MOD;

}

void solve() {
    
    int n , m;
    cin >> n >> m ;
    fibonacci(n + 7);
    for(int i = 0 ; i < m ; i++){
        ll a , b;
        cin >> a >> b;
        cout<<sol( b - a ) << endl;
    }
    
}

int main() {

    fastIO;
    solve();
}