#include <bits/stdc++.h>

using namespace std;

vector <vector <int> > child,gra;
int n, start;

vector <int> a;

int fuck(int w){
    if (a[w] != 0)
        return a[w];
    else if (child[w].size() == 0){
        a[w] = 1;
        return a[w];
    } else {
            int buf1 = 0;
            int buf2 = 0;
            for (int i = 0; i < child[w].size(); i++){
                buf1 += fuck(child[w][i]);
            }
            for (int j = 0; j < gra[w].size(); j++){
                buf2 += fuck(gra[w][j]);
            }
            a[w] = max(1+buf2, buf1);
            return max(1+buf2, buf1);
    }


}



int main()
{
    cin >> n;
    child.resize(n+1); gra.resize(n+1);
    a.resize(n+1);
    for (int i = 0; i < n+1; i++) a[i] = 0;

    int x;
    for (int i = 1; i <= n; i++){
        cin >> x;
        child[x].push_back(i);
        if (x == 0) start = i;
    }

   /* cout << endl;
    for (int i = 0; i < n + 1; i++){
        cout << i << "  ";
        for (int j = 0; j < child[i].size(); j++){
            cout << child[i][j] << " ";
        }
        cout << endl;
    }*/

    for (int i = 0; i <= n; i++){
        for (int j = 0; j < child[i].size(); j++){
            for (int p = 0 ; p < child[child[i][j]].size(); p++){
                gra[i].push_back(child[child[i][j]][p]);
            }
        }
    }

   /* cout << "vnuki "<<endl;
    for (int i = 0; i < n + 1; i++){
            cout << i << "  ";
        for (int j = 0; j < gra[i].size(); j++){
            cout << gra[i][j] << " ";
        }
        cout << endl;
    }*/

    cout << fuck(start);



}
