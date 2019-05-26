#include <bits/stdc++.h>

using namespace std;
int r;
vector <vector <long long> > edin;
vector <vector <vector <long long> > > tree;

vector <vector <long long> > multi(vector <vector <long long> > buf1, vector <vector <long long> > buf2){
    if (buf1[0][0] == buf1[1][1] && buf1[0][0] == 1 && buf1[0][1] == buf1[1][0] && buf1[0][1] == 0){
        return buf2;
    }
    if (buf2[0][0] == buf2[1][1] && buf2[0][0] == 1 && buf2[0][1] == buf2[1][0] && buf2[0][1] == 0){
        return buf1;
    }

    vector <vector <long long> > ans; ans.resize(2); ans[0].resize(2); ans[1].resize(2);
    ans[0][0] = (buf1[0][0] * buf2[0][0] + buf1[0][1] * buf2[1][0]);
    ans[0][1] = (buf1[0][0] * buf2[0][1] + buf1[0][1] * buf2[1][1]);
    ans[1][0] = (buf1[1][0] * buf2[0][0] + buf1[1][1] * buf2[1][0]);
    ans[1][1] = (buf1[1][0] * buf2[0][1] + buf1[1][1] * buf2[1][1]);
    return ans;
}


void treeBuild(vector <vector <vector <long long> > > a){

    for (int i = 0; i < a.size(); i++){
        tree[tree.size()/2 + i] = a[i];
    }

    for (int i = a.size()-2; i >= 0; i--){
        tree[i] = multi(tree[2 * i + 1], tree[2 * i + 2]);
    }
}

vector <vector <long long> > answer (int node, int left, int right, int a, int b){ //left and right - текущие
    if (left > right) {
        return edin;
    }
    if (left == right && left >= a && left <= b) {
        return tree[node];
    }
    if (left == right) {
        return edin;
    }
    if (left > b || right < a) {
        return edin;
    }
    if (a == left && b == right) {
        return tree[node];
    }
    int m = (left+right)/2;
    return  (multi(answer(2*node + 1, left, m , a, min(b, m)), answer(2*node + 2, m+1, right, max(a,m + 1), b)));
}

int main()
{
    //freopen("crypto.in","r",stdin);
    //freopen("crypto.out","w",stdout);
    ios_base::sync_with_stdio(false);


    int n,m;
    vector <vector <vector <long long> > > a;
    cin >> r >> n >> m;

    edin.resize(2); edin[0].resize(2); edin[1].resize(2);
        edin[0][0] = 1;
        edin[1][1] = 1;
        edin[0][1] = 0;
        edin[1][0] = 0;


    int p = 1;
    while (p < n) p *= 2;
    p *= 2;

    a.resize(p/2);

    for (int k = 0; k < n; k++){
        a[k].resize(2);
        for (int i = 0; i < 2; i++){
            a[k][i].resize(2);
            for (int j = 0; j < 2; j++){
                cin >> a[k][i][j];
                //a[k][i][j] = a[k][i][j];
            }
        }
    }

    for (int k = n; k < a.size(); k++){
        a[k] = edin;
    }

    tree.resize(p - 1);

    for (int k = 0; k < tree.size(); k++){
        tree[k].resize(2);
        for (long long i = 0; i < 2; i++){
            tree[k][i].resize(2);
        }
    }

    if (n == 1) {
        tree = a;
    } else {
        treeBuild(a);
    }

    vector <vector <long long> > answ;
    answ.resize(2); answ[0].resize(2); answ[1].resize(2);

    int z1, z2;
    for (int i = 0; i < m; i++){
        cin >> z1 >> z2;
        answ = answer(0, 0, a.size()-1, z1-1, z2-1);
        cout << (answ[0][0] % r) << " " << (answ[0][1] % r) << '\n';
        cout << (answ[1][0] % r) << " " << (answ[1][1] % r) << '\n';
    }


}
