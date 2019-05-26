#include <bits/stdc++.h>

using namespace std;
long long const1 = 16714589;
long long const2 = 21563;

int main()
{
    freopen("sparse.in", "r", stdin);
    freopen("sparse.out", "w", stdout);
    int n, m;
    vector <vector <int> > table;
    vector <int> a;
    a.resize(2e5 + 1);
    table.resize(18);
    for (int i = 0; i < 18; i++){
            table[i].resize(2e5+1);
        }
    cin >> n >> m >> table[0][1];
    int u, v;
    cin >> u >> v;
    a[1] = 0;
    for (int i = 2; i <= n; i++){
        if (i % (1 << a[i - 1]) != 0){
            a[i] = a[i - 1];
        } else {
            a[i] = a[i - 1] + 1;
        }
    }
    for (int i = 2; i <= n; i++){
        table[0][i] = (23*table[0][i-1] + const2) % const1;
    }

    for (int j = 1; j < 18; j++){
        for (int i = 1; i <= (n - pow(2,j) + 1); i++){
            table[j][i] = min(table[j - 1][i],
                              table[j - 1][i + pow(2,(j-1))]);
        }
    }

    int ans;
    int uu = u;
    int vv = v;
    if (uu < vv){
        swap(uu, vv);
    }
    uu = uu+1;
    int d = abs(uu-vv);
    ans = min(table[a[d]][vv], table[a[d]][uu - pow(2,a[d])]);

    int i = 1;
    while(i < m)
    {
        u = ((17 * u + 751 + ans + 2 * i) % n) + 1;
        v = ((13 * v + 593 + ans + 5 * i) % n) + 1;
        int uu = u;
        vv = v;
        if (uu < vv){
            swap(uu, vv);
        }
        uu = uu+1;
        d = abs(uu-vv);
        ans = min(table[a[d]][vv], table[a[d]][uu - pow(2,a[d])]);
        i++;
    }
        cout << u << " " << v << " " << ans;

}
