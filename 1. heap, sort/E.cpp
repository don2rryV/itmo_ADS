#include <bits/stdc++.h>

using namespace std;
int n, shag = 1;

pair <int, int> a[100000];

void qsort(int left, int right){
    a[(left+right)/2].first = n - shag + 1;
    shag++;
    int key = a[(left+right)/2].first;
    int i = left;
    int j = right;
    while (i <= j){
        while(a[i].first < key){
            i++;
        }
        while(a[j].first > key){
            j--;
        }
        if(i <= j){
            swap(a[i], a[j]);
            i++;
            j--;
        }

    }
    if (left < j){
        qsort(left,j);
    }
    if (i < right){
        qsort(i,right);
    }

}

int main()
{
freopen("antiqs.in","r",stdin);
freopen("antiqs.out","w",stdout);
ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i< n; i++){
        a[i].first = 0;
        a[i].second = i+1;
    }
qsort(0, n-1);
a[0].first = 1;
    vector <pair<int,int> > buf;
    buf.resize(n);
    for(int i = 0; i < n; i++){
        buf[i].first = a[i].second;
        buf[i].second = a[i].first;
    }
    sort(buf.begin(),buf.end());

    for (int i = 0; i < n; i++){
      if(i != n-1) {
            cout << buf[i].second << " ";
      } else cout << buf[i].second;
    }

}
