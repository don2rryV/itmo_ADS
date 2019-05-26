#include <bits/stdc++.h>

using namespace std;
string s1, s2;
vector <vector <int> > a;
int main()
{
    //freopen("input.txt ","r",stdin);
    //freopen("output.txt ","w",stdout);
    cin >> s1 >> s2;
    int n = s1.length();
    int m = s2.length();
    a.resize(n+1);
    for (int i = 0; i < a.size(); i++){
        a[i].resize(m+1);
    }

    for (int i = 0; i < a.size(); i++){
        for (int j = 0; j < a[i].size(); j++){
            if (i == 0){
                if (j == 0) a[i][j] = 0;
                else a[i][j] = j;
            } else {
                if (j == 0) a[i][j] = i;
                else {
                    if (s1[i-1] == s2[j-1]){
                        a[i][j] = a[i-1][j-1];
                    } else {
                        a[i][j] = min(min(a[i][j-1], a[i-1][j]), a[i-1][j-1]) + 1;
                    }
                }
            }
        }
    }

    for (int i = 0 ;i < a.size(); i++){
        for (int j = 0 ;j < a[i].size(); j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }


    cout << a[n][m];
}
