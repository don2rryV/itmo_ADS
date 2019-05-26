#include <bits/stdc++.h>

using namespace std;

int main()
{
   // freopen("stack-min.in ","r",stdin);
   // freopen("stack-min.out","w",stdout);
    fstream in("stack-min.in");
    ofstream out("stack-min.out");
    stack< pair<int,int> > a;
    int n, buf;
    in >> n;
    for (int i = 0; i < n; i++){
        in >> buf;
        if (buf == 1) {
            int r;
            in >> r;
            if (a.empty()) {
                a.push(make_pair(r,r));

            } else {
                a.push(make_pair(r, (min(r, a.top().second))));

            }

        } else if (buf == 2){
            a.pop();



        } else if (buf == 3){
            out << a.top().second << endl;
        }
    }
   /* int k = a.size();
    for (int i = 0; i < k; i++){
        cout << a.top().first << " " << a.top().second;
        a.pop();
    }*/
}
