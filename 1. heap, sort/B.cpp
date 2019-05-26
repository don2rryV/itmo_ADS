#include <bits/stdc++.h>

using namespace std;
    vector <int> a;

void siftUp(int k){
    if (k > 0){
    while (a[k] < a[(k-1)/2])    // i == 0 Ч мы в корне
        swap(a[k], a[(k-1)/2]);
        k = (k-1)/2;
    siftUp(k);

    } else{
           //     for (int i = 0; i < a.size(); i++){
           //      cout << a[i] << " ";
           //       }
    }
}

void siftDown(int k){
    int left, right, jj;
  //  if (2*k + 1 < a.size()){
    while (2*k + 1 < a.size()) {    // heapSize Ч количество элементов в куче
        left = 2 * k + 1;           // left Ч левый сын
        right = 2 * k + 2;            // right Ч правый сын
        jj = left;
        if ((right < a.size()) && (a[right] < a[left]))
            jj = right;
        if (a[k] <= a[jj]){break;}
        //if (a[k] > a[jj])
            //{
        //swap(a[k], a[jj]);
       // }
       swap(a[k], a[jj]);
        k = jj;
        siftDown(k);
    //}
    }
}

int extractMin(){

    int min = a[0];
    a[0] = a[a.size()-1];
    a.pop_back();
    //for (int i = 0; i < a.size(); i++){
    //             cout << a[i] << " ";
   //             }
    siftDown(0);
    return min;
}

void decrease(int a1,int a2){
    a[a1] = a2;

   // for (int i = 0; i < a.size(); i++){
   //              cout << a[i] << " ";
   //             }

    siftUp(a1);

}


int main()
{
//freopen("priorityqueue.in","r",stdin);
//freopen("priorityqueue.out","w",stdout);
//ios_base::sync_with_stdio(false);

    string comand; int arg, arg1, arg2;

while (cin >> comand){

    if (comand == "push"){
        cin >> arg;
        a.push_back(arg);
        siftUp(a.size()-1);
    } else if (comand == "extract-min"){
        if (a.size() == 0) cout << "*" << endl; else cout << extractMin() << endl;
    } else if (comand == "decrease-key"){
        cin >> arg1 >> arg2;
        decrease(arg1-1, arg2);

    } else if (comand == "w"){
                    for (int i = 0; i < a.size(); i++){
                 cout << a[i] << " ";
                }
    }
}
}
