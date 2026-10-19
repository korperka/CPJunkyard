#include <bits/stdc++.h>

using ll = long long;
using namespace std;

unsigned int a, b;
unsigned int cur;

unsigned int nextRand() {
    cur = cur * a + b;
    return cur >> 8;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, q, n = 1 << 24;
    cin >> m >> q >> a >> b;
    unsigned int ans = 0;
    vector<int> v(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int add = nextRand(), l = nextRand(), r = nextRand();
        if (l > r) swap(l, r);

        v[l] += add;
        v[r + 1] -= add;
    }

    vector<int> p1(n, v[0]);
    for (int i = 1; i < n; i++) {
        p1[i] = p1[i - 1] + v[i];
    }

    vector<int> p(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        p[i] = p[i - 1] + p1[i - 1];
    }

    for (int i = 0; i < q; i++) {
        int l = nextRand(), r = nextRand();
        if (l > r) swap(l, r);

        ans += p[r + 1] - p[l];
    }

    cout << ans << "\n";
}

// 10 12 9
//
