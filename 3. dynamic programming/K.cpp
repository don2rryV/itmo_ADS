#include <bits/stdc++.h>

using namespace std;
int n,m;
vector <vector <int> > d, a;

bool fuck(int x, int y){
    vector <int> dx,dy;
    while(x>1){
        dx.push_back(x%2);
        x /= 2;
    }
    dx.push_back(x);

    while(y>1){
        dy.push_back(y%2);
        y /= 2;
    }
    dy.push_back(y);

        for (int i = dy.size(); i < n; i++){
            dy.push_back(0);
        }

        for (int i = dx.size(); i < n; i++){
            dx.push_back(0);
        }

    //dx.resize(m);
    //dy.resize(m);



    reverse(dx.begin(),dx.end());
    reverse(dy.begin(),dy.end());

   /* for (int i = 0; i < dx.size(); i++){
        cout << dx[i];
    }
    cout << endl;
    for (int i = 0; i < dy.size(); i++){
        cout << dy[i];
    }
    cout << endl;*/

    int p = dx.size();
    bool flag = true;
    for (int i = 0; i < p-1; i++){
        if (dx[i] == dx[i+1] && dx[i] == dy[i] && dy[i] == dy[i+1]){
            flag = false;
            break;
        }
    }

    return flag;

}

int main()
{
    freopen("nice.in","r",stdin);
    freopen("nice.out","w",stdout);
    cin >> n >> m;
    if (m < n) swap(n,m);
    //fuck(n,m);
    d.resize(pow(2,n));

    for (int i = 0 ;i < d.size(); i++) {
        d[i].resize(pow(2,n));
    }

    a.resize(m);
    for (int i = 0; i < m; i++){
        a[i].resize(pow(2,n));
    }

    int z = pow(2,n);

    for (int i = 0; i < z; i++){
        for (int j = 0; j < z; j++){
            if (fuck(i,j)){
                d[i][j] = 1;
            } else {
                d[i][j] = 0;
            }
        }
    }

    int ind = 0;
    while (ind < z){
        a[0][ind] = 1;
        ind++;
    }


    for (int k = 1; k < m; k++){
        for (int i = 0; i < z; i++){
            for (int j = 0; j < z; j++){
                a[k][i] += a[k-1][j]*d[j][i];
            }
        }
    }
  /*  for (int i = 0; i < m; i++){
        for (int j = 0; j < z; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }*/



    long long ans = 0;
    for (int i = 0; i < z; i++){
        ans += a[m-1][i];
    }
    cout << ans;
}
