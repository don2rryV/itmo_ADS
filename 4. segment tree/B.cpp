#include <bits/stdc++.h>

using namespace std;

vector <long long> t;

void treeBuild(vector <long long> a){

    for (int i = 0; i < a.size(); i++){
        t[t.size()/2 + i] = a[i];
    }
    for (int i = a.size()-2; i >= 0; i--){
        t[i] = t[2 * i + 1] + t[2 * i + 2];
    }
}

long long sum (long long node, long long le, long long r, long long a, long long b){
    if (le > r) return 0;
    if (le == r && le >= a && le <= b) {
        return t[node];
    }
    if (le == r) return 0;
    if (le > b || r < a) return 0;
    if (a == le && b == r) {
        return t[node];
    }
        long long m = (le+r)/2;
    return sum (2*node + 1, le, m , a, min(b, m)) +
        sum (2*node + 2, m+1, r, max(a,m + 1), b);

}

void update(long long node, long long le, long long r, long long ind, long long x){
    if (le == r) {
        t[node] = x;
    }else {
        int m = (le + r) / 2;
        if (ind <= m) update(node * 2 + 1, le, m, ind, x);
            else update(2* node + 2, m + 1, r, ind, x);
        t[node] = t[2*node + 1] + t[2* node + 2];
    }
}

int main()
{
    freopen("rsq.in","r",stdin);
    freopen("rsq.out","w",stdout);
    long long n;
    vector <long long> a;
    cin >> n;
    long long p = 1;
    while (p < n) p *= 2;
    p *= 2;
    a.resize(p/2);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    t.resize(a.size()*2 - 1);
    treeBuild(a);

    /*for (int i = 0; i < t.size(); i++){
        cout << t[i] << " " ;
    }*/

    string buf = "";
    while(cin >> buf){
         if (buf == "sum"){
            long long left, right;
            cin >> left >> right;
            cout << sum(0, 0, a.size()-1, left-1, right-1) << endl;
        } else {
            long long ind;
            long long x;
            cin >> ind >> x;
            update(0, 0, a.size() - 1, ind-1, x);

        }
    }


}
