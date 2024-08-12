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

void solve() {
    
    int n;
    cin >> n;
    string str = "";
    int szm = 0;
    for(int i = 0 ; i < n ; i++){
        string x;
        cin >> x;
        str += ' ' + x ;  
        szm = max( szm , (int)x.size() );
    }    
    n = str.size();
    vi cnt( n + 1 , 0 );
    for(int i = 1 ; i < n ; i++){
        if(str[i] == ' ') continue;
        cnt[i] = cnt[i - 1] + 1;
    }
    int ans = INT_MAX;
    for(int i = szm ; i < n ; i++){
        int j = i + 1;
        int aux = 0;
        while( j < n ){
            if(cnt[j] == 0){
                aux++;
                j += i + 1;
            }else{
                aux++;
                j -= cnt[j] - 1;
                j += i; 
            }
            if( j >= n ) aux++;
        }
        if(!aux) aux++;
        ans = min(ans , aux + i);
    }
    cout<<ans<<endl;
}

int main() {

    fastIO;
    solve();
}