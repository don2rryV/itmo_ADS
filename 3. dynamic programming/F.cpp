#include <bits/stdc++.h>

using namespace std;
vector <vector <int> > a, ans;
string s;

int func(int left, int right){
    if (left > right) return 0; else{


    //cout << left << " " << right << endl;
    if (a[left][right] == 0){
      //      cout << left << " " << right << " in 0 " << endl;
        int y = right - left;
        for (int i = left; i <= right; i++){
            cout << s[i];
        }
        return 0;
    }
    if (a[left][right] == right - left +1){
        return 1;
    }//} else
    if (ans[left][right] == -1) {
        cout << s[left];
        func(left + 1, right - 1);
        cout << s[right];
        return 0;
    }
    func(left, ans[left][right]);
    func(ans[left][right]+1, right);

}
}

int main()
{
    cin >> s;
    a.resize(s.length()); ans.resize(s.length());
    for (int i = 0; i < s.length(); i++){
        for (int j = 0; j < s.length(); j++){
            a[i].resize(s.length());
            ans[i].resize(s.length());
        }
    }



   /* for (int i = 0; i < s.length(); i++){
        for (int j = 0; j < s.length(); j++){
            a[i][j] = 0;
            if (i == j) {a[i][j] = 1;}
            if (i == j-1){
                if (s[i] == '[' && s[j] == ']' ||
                    s[i] == '{' && s[j] == '}' ||
                    s[i] == '(' && s[j] == ')'){
                        a[i][j] = 0;
                        ans[i][j] = i;
                    }
                //else {a[i][j] = 2; ans[i][j] = 0;}
            }
        }
    }
/*for (int i = 0; i < s.length(); i++){
        for (int j = 0; j < s.length(); j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

*/
    for (int j = 0; j < s.length(); j++){
        for (int i = j; i >=0 ; i--){
        if (i != j){


            int buf = 1000000000;
            int ind = -1;
            //ans[i][j] = -1;

            if (s[i] == '[' && s[j] == ']' ||
                    s[i] == '{' && s[j] == '}' ||
                    s[i] == '(' && s[j] == ')'){
                ind = -1;
                buf = a[i+1][j-1];
            }

            int min_buf = a[i][i] + a[i+1][j]; //ind = i;

            for (int p = i; p < j; p++){
                if (a[i][p] + a[p+1][j] < buf) { buf = a[i][p] + a[p+1][j]; ind = p;}
            }
            //buf = min(buf, min_buf);

            a[i][j] = buf;
            ans[i][j] = ind;

        }else a[i][j] = 1;
        }
    }

   /* for (int i = 0; i < s.length(); i++){
        for (int j = 0; j < s.length(); j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    for (int i = 0; i < s.length(); i++){
        for (int j = 0; j < s.length(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }*/

    func(0, s.length()-1);
    //cout << s.length() - a[0][ s.length() - 1];
}
