#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double c, e = 1e-7;
    cin >> c;

    double l = 0, r = sqrt(c);
    while (r - l > e) {
        double m = l + (r - l) / 2.0;

        if (m * m + sqrt(m) < c)
            l = m;
        else
            r = m;
    }

    cout << fixed << setprecision(6);
    cout << r << "\n";
}
