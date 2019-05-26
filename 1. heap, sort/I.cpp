#include <bits/stdc++.h>

using namespace std;

vector <int> a;
    int na;
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

int main()
{

    cin >> na; a.resize(na);
    for (int i = 0; i < na; i++){
        cin >> a[i];
    }
    int k;
    while(cin >> k){
         cout << bin_a(k, -1, na);
    }

}
