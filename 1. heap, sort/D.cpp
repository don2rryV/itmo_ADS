#include <bits/stdc++.h>

using namespace std;
vector <string> a;
vector <string> buf;



int main()
{
    freopen("radixsort.in","r",stdin);
    freopen("radixsort.out","w",stdout);
    int n, m, k;
    int buf_ind;
    cin >> n >> m >> k; //n - колво строк, m - длина строк, k - колво итераций
    a.resize(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    vector <int> ind; ind.resize(n);

    for (int i = 0; i < n; i++){
        ind[i] = -1;
    }

    map <char,int> first_ind;

    for(char i = 'a'; i <= 'z'; i++){
        first_ind[i] = -1;
    }


for(int i = 0; i < k; i++){

    int elem = m - 1 - i;

    for(int j = n-1; j > -1; j--){
        ind[j] = first_ind[a[j][elem]];
        first_ind[a[j][elem]] = j;
    }

    for (char j = 'a'; j <= 'z'; j++){
        if(first_ind[j] != -1){
            buf_ind = first_ind[j];
            buf.push_back(a[buf_ind]);
        }
        while(ind[buf_ind] != -1){
            buf.push_back(a[ind[buf_ind]]);
            buf_ind = ind[buf_ind];
        }
    }
    a = buf;
    buf.clear();
    for(char r = 'a'; r <= 'z'; r++){
        first_ind[r] = -1;
    }
    for (int r = 0; r < n; r++){
        ind[r] = -1;
    }

}


for (int i = 0; i < n; i++){
        cout << a[i] << endl;
    }



/*for(int i = 0; i < n; i++){
    cout << ind[i] << " ";
}
cout << endl;

for(char i = 'a'; i <= 'z'; i++){
    cout << first_ind[i] << " ";
}
*/
}
