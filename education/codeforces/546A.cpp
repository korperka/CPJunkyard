#include<bits/stdc++.h>

using namespace std;

int main() {
    long long k, n, w; cin >> k >> n >> w;
    int p = k*w*(w+1)/2;

    cout << (n > p ? 0 : p - n) << "\n";
}