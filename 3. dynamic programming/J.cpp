#include <bits/stdc++.h>

using namespace std;
vector <vector <int> > a;
vector <vector <int> > d;
int inf = 1000000000;

int n;

bool fuck(int jj, int m){
    vector <int> buf;
    while(m>1){
        buf.push_back(m%2);
        m /= 2;
    }
    buf.push_back(m);
    buf.resize(n);
    reverse(buf.begin(),buf.end());

   // cout << jj << endl;
   // for (int i = 0; i < buf.size(); i++) cout << buf[i];
   // cout << endl;
    bool flag = true;
    if (jj >= buf.size() || buf[jj] == 0) flag = false;

   // if (flag) cout << "true" << endl; else cout << "false" << endl;
    return flag;
}

int findCheapest(int i, int mask){
    if (d[i][mask] != inf) return d[i][mask];

    for (int j = 0; j < n; j++){
        if (fuck(j,mask)){
            d[i][mask] = min(d[i][mask],
                             findCheapest(j, mask - pow(2,j)) + a[i][j]);
        }
    }

    return d[i][mask];

}



int main()
{
    cin >> n;
    n++;
    int p = pow(2,n);

    a.resize(n);
    for (int i = 0; i < n; i++) a[i].resize(n);

    d.resize(n);
    for (int i = 0; i < n ; i++){
        d[i].resize(p);
    }

    for (int i = 1; i < n; i++){
        for (int j = 1; j < n; j++){
            a[i][j] = 0;
        }
    }
    for (int i = 1; i < n; i++){
        for (int j = 1; j < n; j++){
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }



    for (int i = 0; i < n; i++){
        for (int mask = 0; mask < p; mask++){
            d[i][mask] = inf;
        }
    }

    d[0][0] = 0;
    cout << findCheapest(0, n-1);

  /*  for (int i = 0; i < n ; i++){
        for (int j = 0 ;j < p; j++){
            cout << d[i][j] << " ";
        }
        cout << endl;
    }*/


}
