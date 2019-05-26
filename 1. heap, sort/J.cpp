#include <bits/stdc++.h>

using namespace std;
vector <double> h;
int n;

bool prov(double buf){
    bool flag = true;
    for(int i = 2; i < n; i++){
        h[i] = 2*h[i-1] - h[i-2] +2;
        if (h[i] <= 0) {
                flag = false;
                break;
        }
    }

    return flag;
}


int main()
{
freopen("garland.in","r",stdin);
freopen("garland.out","w",stdout);
    double g;
    cin >> n;
    h.resize(n);

    cin >> g;
    h[0] = g;
    double left = 0;
    double right = h[0];

    while (left < right - 0.0000001){
        h[1] = (left+right)/2;

//        if (h[1] == right || h[1] == left) {break;}
        if ( prov(h[1])) {
            right = h[1];
            //h.clear();
            //h[0] = g;
        } else {
            left = h[1];
            //h.clear();
            //h[0] = g;
        }
    }

    h[0] = g;
    h[1] = right;
    for(int i = 2; i < n; i++){
            h[i] = 2*h[i-1] - h[i-2] +2;
    }

printf("%.2f\n", h[n-1]);
  //  cout << h[n-1];

}

