#include <bits/stdc++.h>

using namespace std;

vector <int> shirt;
vector <int> pant;
int main()
{
    freopen("style.in","r",stdin);
    freopen("style.out","w",stdout);
    int n,m;
    cin >> n;
    shirt.resize(n);
    for(int i = 0; i < n; i++){
        cin >> shirt[i];
    }

    cin >> m; pant.resize(m);
    for(int i = 0; i < m; i++){
        cin >> pant[i];
    }

    int it1 = 0, it2 = 0; bool flag = true;
   /* if (n <= m){
        min_ind = n;
    } else {
        min_ind = m;
        flag = false;
    }*/
    int out_s = shirt[0]; int out_p = pant[0];
    int out = abs(shirt[0]-pant[0]);
    while(it1 < n && it2 < m){
        if (shirt[it1] < pant[it2]){
            //buf[it3] = a[it1];
            if(pant[it2] - shirt[it1] < out){
                out = abs(pant[it2] - shirt[it1]);
                out_s = shirt[it1];
                out_p = pant[it2];
            }
            //it3++;
            it1++;
        }else{
            if(shirt[it1] - pant[it2] < out){
                out = abs(pant[it2] - shirt[it1]);
                out_s = shirt[it1];
                out_p = pant[it2];
            }
            //buf[it3] = a[it2];
            //it3++;
            it2++;
        }

    }
    while (it2 < m){
        //buf[it3] = a[it2];
        //it3++;
        if(abs(pant[it2] - shirt[it1]) < out){
                out = abs(pant[it2] - shirt[it1]);
                out_s = shirt[it1];
                out_p = pant[it2];
            }
        it2++;
    }
    while (it1 < n){
        //buf[it3] = a[it1];
        //it3++;
        if(abs(pant[it2] - shirt[it1]) < out){
                out = abs(pant[it2] - shirt[it1]);
                out_s = shirt[it1];
                out_p = pant[it2];
            }
        it1++;
    }




cout << out_s << " " << out_p << endl;



}
