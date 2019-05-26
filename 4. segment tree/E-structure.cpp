#include <bits/stdc++.h>

using namespace std;

int r;
struct Node{
    long long a;
    long long b;
    long long c;
    long long d;
};

Node edin;
vector <Node> tree;

Node multi(Node buf1, Node buf2){
    if (buf1.a == buf1.d && buf1.a == 1 && buf1.b == buf1.c && buf1.b == 0){
        return buf2;
    }
    if (buf2.a == buf2.d && buf2.a == 1 && buf2.b == buf2.c && buf2.b == 0){
        return buf1;
    }
    Node ans;
    ans.a = (buf1.a * buf2.a + buf1.b * buf2.c) % r;
    ans.b = (buf1.a * buf2.b + buf1.b * buf2.d) % r;
    ans.c = (buf1.c * buf2.a + buf1.d * buf2.c) % r;
    ans.d = (buf1.c * buf2.b + buf1.d * buf2.d) % r;
    return ans;
}

void treeBuild(vector <Node> g){

    for (int i = 0; i < g.size(); i++){
        tree[tree.size()/2 + i] = g[i];
    }

    for (int i = g.size()-2; i >= 0; i--){
        tree[i] = multi(tree[2 * i + 1], tree[2 * i + 2]);
    }
}

Node answer (int vertex, int left, int right, int a, int b){
    if (left > right) {
        return edin;
    }
    if (left == right && left >= a && left <= b) {
        return tree[vertex];
    }
    if (left == right) {
        return edin;
    }
    if (left > b || right < a) {
        return edin;
    }
    if (a == left && b == right) {
        return tree[vertex];
    }
    int m = (left+right)/2;
    return (multi(answer(2*vertex + 1, left, m , a, min(b, m)), answer(2*vertex + 2, m+1, right, max(a,m + 1), b)));
}

int main()
{
    freopen("crypto.in","r",stdin);
    freopen("crypto.out","w",stdout);
    ios_base::sync_with_stdio(false);
    edin.a = 1; edin.d = 1; edin.b = 0; edin.c = 0;

    int n, m;
    vector <Node> g;
    cin >> r >> n >> m;
    int p = 1;
    while (p < n) p *= 2;
    p *= 2;
    g.resize(p/2);
    tree.resize(p-1);

    for (int i = 0; i < n; i++){
        cin >> g[i].a >> g[i].b >> g[i].c >> g[i].d;
    }

    if (n == 1) {
        tree = g;
    } else {
        treeBuild(g);
    }

    int z1, z2;
    for (int i = 0; i < m; i++){
        cin >> z1 >> z2;
        Node answ = answer(0, 0, g.size()-1, z1-1, z2-1);
        cout << answ.a << " " << answ.b << '\n';
        cout << answ.c << " " << answ.d << '\n';
    }


}
