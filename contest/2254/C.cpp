#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) {
        ll n; cin >> n;
        string a, b; cin >> a >> b;

        ll p1 = 0, p2 = 0, q1 = 0, q2 = 0, k1 = 0, k2 = 0, t1 = 0, t2 = 0;
        for(int i = 0; i < n; i++) {
            if(i % 2 == 0) {
                p1 += (a[i] == '0' ? 1 : 0);
                q1 += (a[i] == '1' ? 1 : 0);
                k1 += (b[i] == '0' ? 1 : 0);
                t1 += (b[i] == '1' ? 1 : 0);
            }
            else {
                p2 += (a[i] == '0' ? 1 : 0);
                q2 += (a[i] == '1' ? 1 : 0);
                k2 += (b[i] == '0' ? 1 : 0);
                t2 += (b[i] == '1' ? 1 : 0);
            }
        }

        cout << (p1 == k1 && p2 == k2 && q1 == t1 && q2 == t2 ? "YES\n" : "NO\n");
    }
}