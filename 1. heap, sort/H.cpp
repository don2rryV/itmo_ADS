#include <bits/stdc++.h>

using namespace std;
vector <int> a;
int n,k, x,y,z,nn;
vector <int> buf;

bool myFunc(int i, int j){return i < j;}
/*int opor(int left, int right){
    int s = left;
    n = right;
    while(s < n){
        if(s+5 <= n){
            sort(a.begin()+s, a.begin()+s+5, myFunc);
            buf.push_back(a[(s+s+5)/2]);
            s += 5;

        }else{
            sort(a.begin()+s, a.end(), myFunc);
            buf.push_back(a[(s+n)/2]);
                        s = n+1;
        }
    }

    sort(buf.begin(), buf.end());
    int rrr = buf[buf.size()/2];

    for(int i = 0; i < nn; i++){
        if (a[i] == rrr){
            return i;
            break;
        }
    }

}
*/

int main()
{
    cin >> n >> k;
    nn = n;
    a.resize(n);
    cin >> x >> y >> z >> a[0] >> a[1];
    for (int i = 2; i < n; i++){
        a[i] = x*a[i-2] + y*a[i-1] + z;
    }


 for(int i = 0; i < nn; i++){
        cout << a[i] << " ";
    }
    cout << endl;



    int le = 0, r = n;
    bool flag = true; int out;

    while(flag){
        int mid = opor(le,r);
        cout << "mid " << mid << endl;
        if (mid == k){
            out = a[mid];
            flag = false;
        }else if(k < mid){
            r = mid;
        } else{
        k -= mid+1;
        le = mid+1;
        }
    }

    cout << out << endl;









  /* for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl; */



/*for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }*/

    //cout << endl;
//cout << "buf.size() = " << buf.size()<< endl;
   /* for(int i = 0; i < buf.size(); i++){
        cout << buf[i] << " ";
    }*/

}
