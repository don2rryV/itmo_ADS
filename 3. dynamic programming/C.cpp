#include <bits/stdc++.h>

using namespace std;
vector <long long> a,b;
int n;

int func(){
    a[1] = b[8] + b[6];
    a[2] = b[7] + b[9];
    a[3] = b[4] + b[8];
    a[4] = b[3] + b[9] + b[0];
    a[5] = 0;
    a[6] = b[1] + b[7] + b[0];
    a[7] = b[2] + b[6];
    a[8] = b[1] + b[3];
    a[9] = b[2] + b[4];
    a[0] = b[4] + b[6];
}

int main()
{
    cin >> n;
    a.resize(10); b.resize(10);
    for (int i = 0; i < 10; i++){
        a[i] = 1;
    }
    a[8] = 0;
    a[0] = 0;
    long long sum = 0;

    if (n == 1){
        sum = 8;
    }
    else {
        for (int i = 1; i < n; i++){
            for (int j = 0; j < 10; j++) b[j] = a[j];
            func();
        }
        for (int i = 0; i < 10; i++){
            sum = (sum + a[i]);
        }
    }
    cout << sum;
}
