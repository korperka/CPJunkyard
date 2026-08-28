#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x, y, z; cin >> n >> x >> y >> z;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> sum(1 << n);
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) sum[i] += a[j];
        }
    }

    vector<int> p;
    for (int i = 1; i < (1 << n); i++) {
        for (int j = 1; j < (1 << n); j++) {
            for (int k = 1; k < (1 << n); k++) {
                if (i & j || i & k || j & k) continue;

                int x1 = 10*(__builtin_popcount(i)-1)+abs(sum[i]-x);
                int y1 = 10*(__builtin_popcount(j)-1)+abs(sum[j]-y);
                int z1 = 10*(__builtin_popcount(k)-1)+abs(sum[k]-z);
                p.push_back(x1+y1+z1);
            }
        }
    }

    sort(p.begin(), p.end());
    cout << p[0];
}