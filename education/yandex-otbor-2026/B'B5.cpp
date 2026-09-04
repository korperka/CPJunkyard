#include <bits/stdc++.h>

using ll = long long;
using namespace std;

ll e = 0, l = 0, ans = 1;

void dfs(int v, vector<bool> &used, vector<vector<int>> &g) {
    used[v] = true;
    l++;

    for (int c : g[v]) {
        e++;
        if (!used[c]) {
            dfs(c, used, g);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m; cin >> n >> m;
    vector<vector<int>> g(n+1);
    for (int i = 0; i < m; i++) {
        ll a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<bool> used(n+1);

    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            e = 0; l = 0;

            dfs(i, used, g);

            e /= 2;

            if (e != l) {
                cout << 0;
                return 0;
            }

            ans *= 2;
            ans %= 998244353;
        }
    }

    cout << ans;
}