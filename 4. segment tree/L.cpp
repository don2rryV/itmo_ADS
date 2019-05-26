#include <bits/stdc++.h>

using namespace std;

vector <int> t;
int n;

void treeBuild(vector <int> a){
    for (int i = 0; i < a.size(); i++){
        t[t.size()/2 + i] = a[i];
    }
    for (int i = a.size()-2; i >= 0; i--){
        t[i] = min(t[2 * i + 1],t[2 * i + 2]);
    }
}


int minim(int node, int left, int right, int a, int b){
if (left > right) return n;
    if (left == right && left >= a && left <= b) {
        return t[node];
    }
    if (left == right) return n;
    if (left > b || right < a) return n;
    if (a == left && b == right) {
        return t[node];
    }
    int m = (left+right)/2;
    return min(minim(2*node + 1, left, m , a, min(b, m)),
        minim(2*node + 2, m+1, right, max(a,m + 1), b));

}


void update(int node, int left, int right, int ind, int x){
    if (left == right) {
        t[node] = x;
    } else {
        int m = (left + right) / 2;
        if (ind <= m) update(node * 2 + 1, left, m, ind, x);
            else update(2* node + 2, m + 1, right, ind, x);
        t[node] = min(t[2*node + 1],t[2* node + 2]);
    }
}

int main()
{
    freopen("parking.in","r",stdin);
    freopen("parking.out","w",stdout);
    int m;
    cin >> n >> m;
    string buf;
    int key;
    vector <int> a;

    int p = 1;
    while(p < n) p *= 2;
    p *= 2;

    a.resize(p/2);
    for (int i = 0; i < n; i++) a[i] = i;
    for (int i = n; i < a.size(); i++) a[i] = n;
    t.resize(a.size()*2 - 1);

    treeBuild(a);

    /*for (int i = 0; i < t.size(); i++){
        cout << t[i] << " ";
    }*/


    for (int i = 0; i < m; i++){
        cin >> buf >> key;
        if (buf == "enter"){
            int buf = minim(0, 0, a.size()-1, key-1, a.size()-1);
            if (buf >= n)
            buf = minim(0, 0, a.size()-1, 0, a.size()-1);
            cout << buf + 1 << endl;
            update(0, 0, a.size()-1, buf, n);
        } else {
            update(0, 0, a.size()-1, key-1, key-1);
        }
    }



}
