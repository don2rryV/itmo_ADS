#include <bits/stdc++.h>

using namespace std;
vector <int> a,b,c,d;
int raz = 100000000;
    int na,nb,nc,nd;

int bin_a(int buf, int left, int right){
    int m;
    while (left < right-1){
        m = (left+right)/2;
        if (a[m] < buf){
            left = m;
        } else {
            right = m;
        }
    }
    if (right == na) right--; else
    if(right != 0 && abs(buf - a[right-1]) <= abs(buf - a[right])) right--;
    return right;
}

int bin_b(int buf, int left, int right){
    int m;
    while (left < right-1){
        m = (left+right)/2;
        if (b[m] < buf){
            left = m;
        } else {
            right = m;
        }
    }
    if (right == nb) right--; else
    if(right != 0 && abs(buf - b[right-1]) <= abs(buf - b[right])) right--;
    return right;
}

int bin_c(int buf, int left, int right){
    int m;
    while (left < right-1){
        m = (left+right)/2;
        if (c[m] < buf){
            left = m;
        } else {
            right = m;
        }
    }
    if (right == nc) right--; else
    if(right != 0 && abs(buf - c[right-1]) <= abs(buf - c[right])) right--;
    return right;
}

int bin_d(int buf, int left, int right){
    int m;
    while (left < right-1){
        m = (left+right)/2;
        if (d[m] < buf){
            left = m;
        } else {
            right = m;
        }
    }
    if (right == nd) right--; else
    if(right != 0 && abs(buf - d[right-1]) <= abs(buf - d[right])) right--;
    return right;
}



int main()
{
freopen("style.in","r",stdin);
freopen("style.out","w",stdout);
//ios_base::sync_with_stdio(false);
    cin >> na; a.resize(na);
    for (int i = 0; i < na; i++){
        cin >> a[i];
    }
    cin >> nb; b.resize(nb);
    for (int i = 0; i < nb; i++){
        cin >> b[i];
    }
    cin >> nc; c.resize(nc);
    for (int i = 0; i < nc; i++){
        cin >> c[i];
    }
    cin >> nd; d.resize(nd);
    for (int i = 0; i < nd; i++){
        cin >> d[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    sort(d.begin(), d.end());

    int w = 0;
    int x = 0;
    int y = 0;
    int z = 0;
    int out1, out2, out3, out4;
    int maxmax, minmin;
//    cout << bin_a(2, -1,na); //индекс приближенного левого числа
    for (int i = 0; i < na; i++){
        x = bin_b(a[i], -1, nb);
        y = bin_c(a[i], -1, nc);
        z = bin_d(a[i], -1, nd);
        maxmax = max(max(a[i],b[x]),max(c[y],d[z]));
        minmin = min(min(a[i],b[x]),min(c[y],d[z]));
        if (abs(maxmax - minmin) < raz) {
            out1 = i;
            out2 = x;
            out3 = y;
            out4 = z;
            raz = abs(maxmax - minmin);
        }
//        cout << "a[" << i << "] : " << b[x] << " " << c[y] << " " << d[z] << endl;
    }


    for (int i = 0; i < nb; i++){
        w = bin_a(b[i], -1, na);
        y = bin_c(b[i], -1, nc);
        z = bin_d(b[i], -1, nd);
        maxmax = max(max(a[w],b[i]), max(c[y],d[z]));
        minmin = min(min(a[w],b[i]), min(c[y],d[z]));
        if (abs(maxmax - minmin) < raz) {
            out1 = w;
            out2 = i;
            out3 = y;
            out4 = z;
            raz = abs(maxmax - minmin);
        }

    }

    for(int i = 0; i < nc; i++){
        w = bin_a(c[i], -1, na);
        x = bin_b(c[i], -1, nb);
        z = bin_d(c[i], -1, nd);
        maxmax = max(max(a[w],b[x]), max(c[i],d[z]));
        minmin = min(min(a[w],b[x]), min(c[i],d[z]));
        if (abs(maxmax - minmin) < raz) {
            out1 = w;
            out2 = x;
            out3 = i;
            out4 = z;
            raz = abs(maxmax - minmin);
        }
    }
    for(int i = 0; i < nd; i++){
        w = bin_a(d[i], -1, na);
        x = bin_b(d[i], -1, nb);
        y = bin_c(d[i], -1, nc);
        maxmax = max(max(a[w],b[x]), max(c[y],d[i]));
        minmin = min(min(a[w],b[x]), min(c[y],d[i]));
        if (abs(maxmax - minmin) < raz) {
            out1 = w;
            out2 = x;
            out3 = y;
            out4 = i;
            raz = abs(maxmax - minmin);
        }

    }
    cout << a[out1] << " " << b[out2] << " " << c[out3] << " " << d[out4] << endl;

}






