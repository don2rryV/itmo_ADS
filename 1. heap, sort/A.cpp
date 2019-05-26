#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("isheap.in","r",stdin);
    freopen("isheap.out","w",stdout);
    //ios_base::sync_with_stdio(false);

    int n; bool flag = false;

    cin >> n;
    vector <int> a;
    a.resize(n);

    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    for (int i = 0; i < n/2; i++){
        if (2*i+1 < n && a[i] > a[2*i+1]){
            flag = true;
        }
        if (2*i+2 < n && a[i] > a[2*i+2]){
            flag = true;
        }
    }
    if(flag){
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }

}
