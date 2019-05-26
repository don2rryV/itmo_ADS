#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("decode.in","r",stdin);
    freopen("decode.out","w",stdout);
    string s;
    stack <char> a;
    cin >> s;
    for (int i = 0; i < s.length(); i++){
        if (!a.empty()){
            if (a.top() != s[i]){
                a.push(s[i]);
            }else{
                a.pop();
            }
        } else{
            a.push(s[i]);
        }

    }
    int buf = a.size();
    string ans;
    for(int i = 0; i < buf; i++){
        ans += a.top();
        a.pop();
    }
    for (int i = ans.length()-1; i >= 0; i--){
        cout << ans[i];
    }
}
