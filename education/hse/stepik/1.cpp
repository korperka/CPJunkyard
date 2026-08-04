#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    bool f = n % 400 == 0 || (n % 4 == 0 && n % 100 != 0);
    
    cout << (f ? "YES\n" : "NO\n");
}