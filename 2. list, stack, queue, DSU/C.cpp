#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("postfix.in ","r",stdin);
    freopen("postfix.out","w",stdout);
    char buf; int f;
    stack <int> a;
    while (cin >> buf){
      //  if (buf == 'm') break;
        if (int(buf) - 48 >= 0 && int(buf) - 48 <= 9){
            a.push(int(buf) - 48);
        } else {

        if (buf == '+'){
                    //cout << " find + "<< endl;
                    f = a.top();
                    a.pop();
                    f += a.top();
                    a.pop();
                    a.push(f);
                }
                if (buf == '-'){
                    f = a.top();
                    a.pop();
                    f = a.top() - f;
                    a.pop();
                    a.push(f);
                }
                if (buf == '*'){
                    f = a.top();
                    a.pop();
                    f *= a.top();
                    a.pop();
                    a.push(f);
                }

        }


    }
    cout << a.top();
}
