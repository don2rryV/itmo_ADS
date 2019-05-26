#include <bits/stdc++.h>

using namespace std;
vector <int> a,b;
vector <vector <int> > d;
int n;

int main()
{
    cin >> n;
    a.resize(n);
    d.resize(n+1);
    for (int i = 0; i < n; i++){
        cin >> a[i];
        d[i].resize(n+1);
    }
    d[n].resize(n+1);



    for (int i = 0; i < n+1; i++){
        d[0][i] = 40000;
        d[i][0] = 0;
    }
    for (int i = 1; i< n+1; i++){
        for (int j = 1; j < n+1; j++){
            if (j > i) d[i][j] = 40000;
        }
    }
    d[0][0] = 0;


    for (int i = 1; i < n+1; i++){
        for (int j = 0; j < i+1; j++){
            if (a[i-1] <= 100) d[i][j] = min (d[i-1][j] + a[i-1], d[i-1][j+1]);
            else if (j == 0) d[i][j] = min (40000+a[i-1], d[i-1][j+1]);
                else d[i][j] = min(d[i-1][j-1] + a[i-1],d[i-1][j+1]);
        }
    }


   for (int i = 0; i < n+1; i++){
        for (int j = 0; j < n+1; j++){
           cout << d[i][j] << " ";
        }
        cout << endl;
    }
cout << endl;

    int ans = d[n][0];
    int ind_ans = 0;
    for (int i = 1; i < n+1; i++){
        if (d[n][i] > 0 && d[n][i] <= ans) {
            ans = d[n][i];
            ind_ans = i;
        }
    }
    int nn = n;
    int ind = ind_ans;

    //if (ans == 0) ind_ans = 0;
    if (ans != 0)
    while (nn > 0){
        if ( a[nn - 1] <= 100 ){
            if (d[nn][ind] == d[nn-1][ind+1]) {b.push_back(nn); nn--; ind++;}
            else {
                nn--;
            }
        } else {
            /*if (ind == 0) {
                nn--;
                ind++;
            } else {*/
                if (d[nn][ind] == d[nn-1][ind+1]) {
                    b.push_back(nn);
                    nn--;
                    ind++;
                } else {
                    nn--;
                    ind--;
                }
            //}
        }
    }


    sort(b.begin(), b.end());

    cout << ans << endl;
    cout << ind_ans << " " << b.size() << endl;

    for (int i = 0; i < b.size(); i++){
        cout << b[i] << endl;
    }

}

