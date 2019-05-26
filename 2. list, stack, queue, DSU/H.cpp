#include <bits/stdc++.h>

using namespace std;

int main()
{
    fstream in("saloon.in");
    ofstream out("saloon.out");
    int n,m,k,p;
    vector <vector <int> > a;
    in >> n;
    a.resize(n);
    for (int i = 0 ; i < n; i++){
        a[i].resize(3);
        a[i][0] = 0;
        a[i][1] = 0;
        a[i][2] = 0;
    }
    int i = 0;
    for (int x = 0; x < n; x++){
        in >> m >> k >> p;
        a[i][0] = 60*m + k;
        if (i == 0) {
            a[i][1] = 1;
            a[i][2] = a[i][0] + 20;
            out << (a[i][2] / 60)%24 << " " << a[i][2] % 60 << endl;
            i++;

           /* cout << endl;
            for (int j = 0; j < n; j++){
                cout << a[j][0] << " " << a[j][1] << " " << a[j][2] << endl;
            }*/


        } else {

            //a[i][0] = 60*m + k;


            if ((60*m + k) < a[i-1][2]){
                int ind = 0;
                for (int j = i-1; j >= 0; j--){
                    if (a[j][2] > a[i][0]){
                        ind++;
                    }
                }
                if (p >= ind){
                    a[i][0] = 60*m+k;
                    a[i][2] = a[i-1][2] + 20;
                    out << (a[i][2] / 60)%24 << " " << a[i][2] % 60 << endl;
                    i++;
                }else {
                    out << m << " " << k << endl;
                }
            } else {
                a[i][0] = 60*m+k;
                a[i][2] = a[i][0] + 20;
                out << (a[i][2] / 60)%24 << " " << a[i][2] % 60 << endl;
                i++;
            }


        }
    }
}
