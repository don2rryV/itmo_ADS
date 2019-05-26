#include <bits/stdc++.h>

using namespace std;
vector <int> a;
int main()
{
    fstream in("bureaucracy.in");
    ofstream out("bureaucracy.out");
    int n,m;
    in >> n >> m;
    a.resize(n);
    int k, ind = 0, for_ans = 0;

    bool flag = true;
    long long buf = 0;
        int ans = 0;
        k = m/n;
        buf = m % n;

    while ((buf > 0 && ans > 0) || for_ans == 0) {
    if (m <= n) {
        for (int i = 0; i < n; i++){
            in >> a[i];
            if (m == 0){
                ind = i;
                m--;
                //ans++;
            } else if (m > 0){
                a[i]--;
                //if (a[i] != 0) ans++;
                m--;
            } else {
                //ans++;
            }
        }
        buf  = 0;
        ans = 0;
        for (int i = 0; i < n; i++){
            if (a[i] != 0) ans++;
        }
    for_ans++;

    }else {



        for (int i = 0; i < n; i++){
            //cout << "k = " << k  << " buf = " << buf << endl;
            in >> a[i];
            if (a[i] < k){
                buf = buf + (k - a[i]);
                a[i] = 0;
            } else if (a[i] == k){
                a[i] = 0;
            } else {
                if (a[i] == (k+buf)){
                    buf = 0;
                    a[i] = 0;
                } else if (a[i] < (k+buf)){
                    buf = (buf+k) - a[i];
                    a[i] = 0;
                } else {
                    a[i] = a[i] - k - buf;
                    if (a[i] != 0 && a[0] == 0 && i < ind) ind = i;
                    //if (a[i] != 0) ans++;
                    buf = 0;
                }
            }

        }
        ans = 0;
        for (int i = 0; i < n; i++){
            if (a[i] != 0) ans++;
        }

        for_ans++;
    }
    }


    ans = 0; ind = -1;
        for (int i = 0; i < n; i++){
            if (a[i] != 0) {
                ans++;
                if (ind == -1) ind = i;
            }
        }


    if (ans != 0) {
            out << ans << endl;

        for (int i = ind; i < n; i++){
            if (a[i] != 0) {
                out << a[i] <<" ";
                flag = false;
            }
        }

        for (int i = 0; i < ind; i++){
            if (a[i] != 0) {
                    out << a[i] <<" ";
                    flag = false;
            }
        }
    }

    if (flag) out << -1 << endl;


}
