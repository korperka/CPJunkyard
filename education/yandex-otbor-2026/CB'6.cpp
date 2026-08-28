#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, k; cin >> n >> k;

    if (k == 0) {
        cout << n;
        return 0;
    }

    if (n%10==1 || n%10==3 || n%10==7 || n%10 == 9) {
        n += n%10; k--;
    }
    if (k == 0 || n%10==0) {
        cout << n;
        return 0;
    }
    if (n%10 == 5) {
        cout << n+(n%10);
        return 0;
    }

    while (n%10 != 2 && k > 0) {
        n += n%10;
        k--;
    }

    if (k <= 0) {
        cout << n;
        return 0;
    }

    n += (k/4)*20;
    k %= 4;

    for (int i = 0; i < k; i++) {
        n += n%10;
    }

    cout << n;
}