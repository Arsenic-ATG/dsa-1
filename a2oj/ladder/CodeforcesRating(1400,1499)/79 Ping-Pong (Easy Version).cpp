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

map<int, pair<int, int>> m;
int node = 1;

vector<vector<int>> graph(101);

void add_interval() {
    int a, b; cin >> a >> b;
    m[node] = mp(a, b);
    loop(i, 1, node) {
        auto [x, y] = m[i];
        if ((a < x and b > x) or (b > y and a < y)) 
            graph[i].pb(node);
        if ((x < a and a < y) or (b < y and b > x))
            graph[node].pb(i);
    }
    ++node;
}

void dfs(int src, vector<bool> &vis) {
    for (auto i: graph[src]) {
        if (!vis[i]) {
            vis[i] = true;
            dfs(i, vis);
        }
    }
}

void solve() {
    int m; cin >> m; 
    while (m--) {
        int ch; cin >> ch;
        switch(ch) {
            case 1: add_interval();
                break;
            default:
                vector<bool> vis(101, false);
                int x, y; cin >> x >> y;
                dfs(x, vis);
                cout << (vis[y] ? "YES" : "NO") << endl;
        }
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
