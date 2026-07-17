#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, ans=0; cin >> n;

    while (n--) {
        int p = 0;
        for (int i = 0; i < 3; i++) {
            int a; cin >> a;
            if (a == 1) p++;
        }

        if (p >= 2) ans++;
    }

    cout << ans;
}