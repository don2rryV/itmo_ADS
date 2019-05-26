#include <bits/stdc++.h>

using namespace std;
int n;
int main()
{
    fstream in("hospital.in");
    ofstream out("hospital.out");
    vector <int> a;

    in >> n;
    int m = 0;
    char buf;
    for (int i = 0; i < n; i++){
        in >> buf;
        if (buf == '+'){
            int r;
            in >> r;
            a.push_back(r);
        } else if (buf == '-'){
            out << a[m] << endl;
            m++;
        } else if (buf == '*'){
            int r;
            in >> r;
            if (a.size() != 0){
            int k = a.size()-m;
            for (int j = 0 ; j < (k/2) + (k%2); j++){
                a.push_back((a[m]));
                m++;
            }
            a.push_back(r);
            for (int j = (k/2) + (k%2); j < k; j++){
                a.push_back(a[m]);
                m++;
            }
            } else {
                a.push_back(r);
            }
            /*int p = a.size();
                for (int y = 0; y < p; y++){
                    vout << a.front() << " ";
                }*/
        }



    }
}
