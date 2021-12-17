/******************************************************/
#include <bits/stdc++.h>
using namespace std;
#define ll                long long
#define vi                vector<ll>
#define vvi               vector<vi>
#define all(v)            v.begin(), v.end()
#define pii               pair<ll, ll>
#define pb                push_back
#define mp                make_pair
#define mid(l, h)         ((l+h)/2)
#define loop(i, a, b)     for (auto i = a; i < b; ++i)
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
 
bool cmp (pii a, pii b) {
    if (a.ff != b.ff) return a.ff > b.ff;
    return a.ss < b.ss;
}

void solve() {
    ll n, k; cin >> n >> k;

    vector<pii> v(n);
    for (auto &i: v) cin >> i.ff >> i.ss;

    sort(all(v), [] (pii a, pii b) {
        if (a.ff != b.ff) return a.ff > b.ff;
        return a.ss < b.ss;
        });

    vi ans(n, 1);

    ll cur = 0;

    loop(i, 1, n) {
        if (v[i].ff == v[i-1].ff and v[i].ss == v[i-1].ss)
            ans[cur]++;
        else cur++;
    }

    ll ctr = 0;

    loop(i, 0, n) {
        ctr += ans[i];
        if (k <= ctr) {cout << ans[i]; break;}
    }
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
