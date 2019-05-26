#include <bits/stdc++.h>

using namespace std;

vector <vector <int> > a;
int main()
{
    fstream in("formation.in");
    ofstream out("formation.out");
    int n,m;
    in >> n >> m;
    a.resize(n+1);
    for (int i = 0; i < a.size(); i++){
        a[i].resize(2);
        a[i][0] = 0;
        a[i][1] = 0;
    }

    int k;
    string buf;

    for (int i = 0; i < m; i++){
        in >> buf >> k;
        if (buf == "right"){
            int p;
            in >> p;
            if (a[p][1] != 0){
                a[k][1] = a[p][1];
                a[a[p][1]][0] = k;
                a[p][1] = k;
                a[k][0] = p;
            }else{
                a[p][1] = k;
                a[k][0] = p;
            }

        } else if(buf == "left"){
            int p;
            in >> p;
            if (a[p][0] != 0){
                a[k][0] = a[p][0];
                a[a[p][0]][1] = k;
                a[p][0] = k;
                a[k][1] = p;
            } else {
                a[k][1] = p;
                a[p][0] = k;

            }
        }else if(buf == "leave"){
            a[a[k][0]][1] = a[k][1];
            a[a[k][1]][0] = a[k][0];
            a[k][0] = 0;
            a[k][1] = 0;
        }else if (buf == "name"){
            out << a[k][0] << " " << a[k][1]<< endl;
        }

    }
}
