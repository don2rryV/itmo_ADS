#include <bits/stdc++.h>

using namespace std;
#define MOD1 (1ull << 16)
#define MOD2 (1ull << 30)
int main(){

    freopen("sum0.in","r",stdin);
    freopen("sum0.out","w",stdout);
    long long n,x,y,m,z, out;
    long long t;
    vector <long long> a,b,c,sum;

    cin >> n;
    a.resize(n); sum.resize(n);
    cin >> x >> y >> a[0];
    a[0] = a[0] % MOD1;
    sum[0] = a[0];
    cin >> m;
    b.resize(1); c.resize(1);
    cin >> z >> t >> b[0];
    if (m == 0) {
        cout << 0;
    } else {
        b.resize(2*m); c.resize(2*m);
    b[0] = b[0] % MOD2;


    for (int i = 1; i < n; i++){
        a[i] = (a[i-1] * x + y) % MOD1;
        sum[i] = sum[i-1] + a[i];
    }
    c[0] = b[0] % n;

    for (int i = 1 ; i < 2*m; i++){
        b[i] = (b[i-1] * z + t) % MOD2;
        c[i] = b[i] % n;
    }
    out = 0;
    long long left, right;
    for (int i = 0; i < m; i++){
        left = min(c[2*i], c[2*i+1]);
        right = max(c[2*i], c[2*i+1]);
        out += sum[right];
        if (left > 0) out -= sum[left - 1];
    }

    /*for (int i = 0; i < 2*m; i++){
        cout << b[i] << " ";
    }*/

    cout << out;

    }
}
