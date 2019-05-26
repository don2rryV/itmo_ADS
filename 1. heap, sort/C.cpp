#include <bits/stdc++.h>

using namespace std;
  vector <int> a;


void mergeMain(int left, int mid, int right){
    int it1 = left; int it2 = mid + 1; int it3 = 0;
    //int buf[200000];
    vector <int> buf;
    while ((it1 <= mid) && (it2 <= right)){
        if (a[it1] < a[it2]){
            //buf[it3] = a[it1];
            buf.push_back(a[it1]);
            //it3++;
            it1++;
        }else{
            buf.push_back(a[it2]);
            //buf[it3] = a[it2];
            //it3++;
            it2++;
        }
    }

    while (it2 <= right){
        //buf[it3] = a[it2];
        //it3++;
        buf.push_back(a[it2]);
        it2++;
    }
    while (it1 <= mid){
        //buf[it3] = a[it1];
        //it3++;
        buf.push_back(a[it1]);
        it1++;
    }
    for (it3 = 0; it3 < right - left +1; it3++){
        a[left+it3] = buf[it3];
    }
buf.clear();
}


void MergeSort(int left, int right){
    int mid;
    if (left < right){
        mid = (left+right)/2;
        MergeSort(left,mid);
        MergeSort(mid+1,right);
        mergeMain(left,mid,right);
    }

}


int main()
{
    freopen("sort.in","r",stdin);
    freopen("sort.out","w",stdout);
    int n;
    cin >> n;
    a.resize(n);

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    if (n == 1) {
        cout  << a[n-1] << endl;
    } else{

        MergeSort(0, n-1);
    }

    for(int i = 0; i < n; i++){
        if(i != n-1){
        cout << a[i] << " ";
        } else cout << a[i];
    }
}
