#include <bits/stdc++.h>
#include <math.h>
using namespace std;
vector <double> t;
vector <double> t_buf;
vector <double> v;
double buf, sum;
int n;


bool prov(double k){
    bool flag = true;

    int ind_1 = 0, ind_2 = n;
    double r1=0, r2=0, t1 = t[0], t2 = k;
    while(ind_1 < n){
    if (t1 < t2){
        r1 = r1 + t1*v[ind_1];
        r2 = r2 + t1*v[ind_2];
        t2 = t2-t1;
        ind_1++;
        t1 = t[ind_1];
        if (abs(r1-r2) < buf && ind_2 < n) {
                flag = false;
                break;
            }
    }else{
        r2 = r2+t2*v[ind_2];
        r1 = r1+t2*v[ind_1];
        t1 = t1-t2;
        ind_2 = (ind_2+1) % (n+1);
        t2 = t[ind_2];
        if (abs(r1-r2) < buf && ind_2 < n) {
                flag = false;
                break;
            }


    }
    }
    return flag;

}

int main()
{
    freopen("trains.in","r",stdin);
    freopen("trains.out","w",stdout);
    cin >> buf;
    cin >> n;
    t.resize(n); v.resize(n); t_buf.resize(n);
    sum = 0;
    for(int i = 0; i < n; i++){
        cin >> t[i] >> v[i];
        sum += t[i];
    }

    double left = 0.0f;
    double right = sum;
    double m;


    while (left < right - 0.0001){
        m = (left+right)/2;
        if (prov(m)){
            right = m;
        } else {
            left = m;
        }
    }

    printf("%.3f\n", right);

}
