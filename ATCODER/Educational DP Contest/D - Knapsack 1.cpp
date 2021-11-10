/******************************************************/
#include <bits/stdc++.h>
using namespace std;
#define ll                long long
#define vi                vector<ll>
#define vvi               vector<vi>
#define pii               pair<ll, ll>
#define pb                push_back
#define mp                make_pair
#define mid(l, h)         ((l+h)/2)
#define loop(i, a, b)     for (auto i = a; i <= b; ++i)
#define looprev(i, a, b)  for (auto i = a; i >= b; --i)
#define mod               1'000'000'007
#define endl              '\n'
#define ff                first
#define ss                second
#define pinf              LLONG_MAX
#define ninf              LLONG_MIN
/******************************************************/

void file_i_o() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

void solve() {
    ll n, w; cin >> n >> w;
    vector<pii> p(n);
    loop(i, 0, n-1) cin >> p[i].ff >> p[i].ss;
    
    sort(p.begin(), p.end());

    vvi dp (n, vi(w+1, 0));
    
    loop(i, 1, w) 
        dp[0][i] = i < p[0].ff ? 0 : p[0].ss;


    loop(i, 1, n-1) {
        loop(j, 1, w) {
            // cannot buy
            if (j < p[i].ff) dp[i][j] = dp[i-1][j];

            // can buy
            else {
                dp[i][j] = max(dp[i-1][j], p[i].ss + dp[i-1][j-p[i].ff]);
            }            
        }
    }
    cout << dp[n-1][w];
}

int main () {
    clock_t start = clock();
    file_i_o();
    solve();
#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\nExecuted in: " << (double)(end - start) / double(CLOCKS_PER_SEC)
    << " sec";
#endif
    return 0;
}
