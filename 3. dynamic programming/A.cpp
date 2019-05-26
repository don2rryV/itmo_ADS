#include <bits/stdc++.h>

using namespace std;
int n, k;
vector <int> a, b, way, ans;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin >> n >> k;
    a.resize(n); b.resize(n); way.push_back(1);
    a[0] = 0; a[n-1] = 0;
    for (int i = 1; i < n-1; i++) cin >> a[i];

    for (int i = 1; i < n; i++){
        int max_buf = -10007;
        int ind  = 0;
        for (int j = i - k; j < i; j++){
            if (j > -1 && b[j] > max_buf) { max_buf = b[j]; ind = j; }
        }
        b[i] = a[i] + max_buf;
    way.push_back(ind+1);
    }
    cout << b[n-1] << endl;

    int i = way.size()-1;
    ans.push_back(n);

    while(way[i] != 1){
        ans.push_back(way[i]);
        i = way[i]-1;
    }
    ans.push_back(1);
    cout << ans.size()-1 << endl;

    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }

}
