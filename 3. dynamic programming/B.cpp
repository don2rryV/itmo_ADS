#include <bits/stdc++.h>

using namespace std;
int n;
vector <int> a, b, way,ans;

int main()
{
    cin >> n; b.resize(n); way.push_back(-1);
    a.resize(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    b[0] = 1;
    for (int i = 1; i < n; i++) b[i] = 0;

    for (int i = 1; i < n; i++){
        int buf = -1000000003; int max_buf = 0; int ind = 0;
        for (int j = 0; j < i; j++){
            if (a[j] < a[i] && b[j] > max_buf) {
                buf = a[j];
                max_buf = b[j];
                ind = j;
            }
        }
        b[i] = max_buf + 1;
        way.push_back(ind);
    }

    int max_bu2`1``f = b[0]; int ind = 0;
    for (int i = 1; i < n; i++){
        if (b[i] > max_buf){
            max_buf = b[i];
            ind = i;
        }
    }

    cout << max_buf << endl;
    //cout << "ind = " << ind << endl;

    /*for (int i = 0; i < way.size(); i++){
        cout << way[i] << " ";
    }
    cout << endl;*/
    int i = ind;
    ans.push_back(a[i]);

    while (way[i] != -1){
        if (a[way[i]] < a[i]) ans.push_back(a[way[i]]);
        i = way[i];
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
}
