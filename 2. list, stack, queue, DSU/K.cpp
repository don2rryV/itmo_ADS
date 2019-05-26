#include <bits/stdc++.h>

using namespace std;
vector <int> a;
int main()
{
    fstream in("kenobi.in");
    ofstream out("kenobi.out");
    int n, x;
    in >> n;
    string buf;
    a.resize(n);
    int i = -1;
    for (int x = 0; x < n; x++){
        in >> buf;
        if (buf == "add"){
            i++;
            in >> a[i];


        } else if(buf == "take"){
            if (i >= 0)
                i--;


        } else if (buf == "mum!" && i > 0){
            if (i%2 == 0) { //нечетное колво в массиве
                int t = a[i/2];
                for (int j = i/2; j > 0; j--){
                    a[j] = a[j-1];
                }
                a[0] = t;

                for (int j = 1; j <= i/2; j++){
                    swap(a[j], a[i/2+j]);
                }

            } else {
                for (int j = 0; j < i/2+1; j++){
                    swap(a[j], a[i/2+1+j]);
                }

            }
        }
    }

    out << i+1 << endl;
    for (int p = 0; p < i+1; p++){
        out << a[p] << " ";
    }


}
