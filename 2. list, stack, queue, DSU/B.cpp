#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("brackets.in","r",stdin);
    freopen("brackets.out","w",stdout);
    string s; string ans= "YES"; char buf;
    stack <char> a;
    cin >> s;
    for (int i = 0; i < s.length(); i++){
        buf = s[i];
        if (!a.empty()){
            if (buf == '(' || buf == '[' || buf == '{'){
                a.push(buf);
            }else{
                if(buf == ')'){
                    if(a.top() != '(') ans = "NO";
                    else {
                        a.pop();
                    }
                }
                if(buf == '}'){
                    if(a.top() != '{') ans = "NO";
                    else {
                        a.pop();
                    }
                }
                if(buf == ']'){
                    if(a.top() != '[') ans = "NO";
                    else {
                        a.pop();
                    }
                }


            }

        }else{
            if (buf == '(' || buf == '[' || buf == '{' ){
                a.push(buf);
            }else{
            ans = "NO";
            }

        }


    }
    if (!a.empty()) ans = "NO";
    cout << ans;
}
