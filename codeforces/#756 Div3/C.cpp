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
    ll n; cin >> n;
    vi v(n);
    for (auto &i: v) cin >> i;
    vi ans;
    if (v[0] > v[n-1]) {
        ans.pb(v[0]);
        looprev(i, n-1, 1) {
            ans.pb(v[i]);
            if (v[i] > v[0]) {cout << -1 << endl; return;}
        }
    } else {
        ans.pb(v[n-1]);
        looprev(i, n-2, 0) {
            ans.pb(v[i]);
            if (v[i] > v[n-1]) {cout << -1 << endl; return;}
        }
    }
    for (auto i: ans) cout << i << ' '; 
    cout << endl;
}

int main () {
    clock_t start = clock();
    file_i_o();
    ll T;
    cin >> T;
    while (T--) {
      solve();
    }
#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\nExecuted in: " << (double)(end - start) / double(CLOCKS_PER_SEC)
    << " sec";
#endif
    return 0;
}
