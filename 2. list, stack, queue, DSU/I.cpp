#include <bits/stdc++.h>

using namespace std;
int n;
int main()
{
   fstream in("hemoglobin.in");
   ofstream out("hemoglobin.out");
   //freopen("hemoglobin.in ","r",stdin);
   //freopen("hemoglobin.out","w",stdout);
    vector <int> a;
    vector <int> b;

    in >> n;
    int m = 0;
    char buf;
    a.push_back(0);
    b.push_back(0);
    for (int i = 0; i < n; i++){
        in >> buf;

        if (buf == '+'){
            int r;
            in >> r;
            a.push_back(r);
            if (a.size() == 2) b.push_back(a[a.size()-1]);
                else b.push_back(b[b.size()-1] + a[a.size()-1]);
        } else if (buf == '-'){
            out << a[a.size()-1] << endl;
            a.resize(a.size()-1);
            b.resize(b.size()-1);
        } else if (buf == '?'){
            int r;
            in >> r;
            out << b[b.size()-1] - b[b.size()-1-r] << endl;

        }



    }
}
