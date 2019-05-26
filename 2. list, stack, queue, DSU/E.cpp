#include <bits/stdc++.h>

using namespace std;
vector <vector <int> > a;

int find_par(int x){
    if (x == a[x][0]){
        return x;
    }
    return a[x][0] = find_par(a[x][0]);

}

int main()
{
    fstream in("dsu.in");
    ofstream out("dsu.out");
    int n;
    in >> n;
    a.resize(n);
    for (int i = 0; i < n; i++){
        a[i].resize(5);
        a[i][0] = i;
        a[i][1] = i;
        a[i][2] = i;
        a[i][3] = 1;
    }

    string s; int k;

    while (in >> s >> k){
        if (s == "union"){
            int r;
            in >> r;
            k--; r--;
          
            k = find_par(k);
            r = find_par(r);
            if (a[k][0] != a[r][0]){
                if (a[k][3] < a[r][3]){
                    a[k][0] = a[r][0];
                    if (a[k][1] < a[r][1]) a[r][1] = a[k][1];
                    if (a[k][2] > a[r][2]) a[r][2] = a[k][2];
                } else {
                    a[r][0] = a[k][0];
                    if (a[r][1] < a[k][1]) a[k][1] = a[r][1];
                    if (a[r][2] > a[k][2]) a[k][2] = a[r][2];
                }
                int sum = a[k][3] + a[r][3];
                a[k][3] = sum; a[r][3] = sum;

            }

        }else {
            k--;
            k = find_par(k);
            out << a[k][1] + 1 << " " << a[k][2] + 1 << " " << a[k][3] << endl;
        }
    }
}
