#include <bits/stdc++.h>

using namespace std;

int n;
vector <vector <int >> graf;
vector <bool> visited;
vector <int> vertexes;
vector <int> depth;
vector <int> index;
vector <bool> uze_v_ind;
vector <int> tree;
long long p;
vector <int> sum;
vector <int> last;
vector <int> col;
bool flag_chto_tree_postroeno_suka;

void build_tree(){
    for (int i = 0; i < p/2; i++){
        tree[tree.size()/2 + i] = vertexes[i];
    }
    for (int i = p/2-2; i >= 0; i--){
        if (tree[2* i + 1] >= depth.size() && tree[2 * i + 2] >= depth.size()){
            tree[i] = 1000002;
        } else if (tree[2*i+1] >= depth.size()){
            tree[i] = tree[2*i+2];
        } else if (tree[2*i+2] >= depth.size()){
            tree[i] = tree[2*i+1];
        } else {
            if (depth[tree[2*i+1]] <= depth[tree[2*i+2]]) tree[i] = tree[2*i+1];
            else tree[i] = tree[2*i+2];
        }

    }
}

long long getMin (int vertex, int left, int right, int a, int b){

    if (a > b) return 1000002;
    if (a == left && b == right) {
        return tree[vertex];
    }
    int m = (left + right)/2;

    if (b <= m) return getMin(vertex * 2 + 1, left, m, a, min(b,m));
    if (a > m) return getMin (2*vertex + 2, m+1, right, max(a,m + 1), b);

    int ans1 = getMin (2*vertex + 1, left, m , a, min(b, m));
	int ans2 = getMin (2*vertex + 2, m+1, right, max(a,m + 1), b);

	return depth[ans1] < depth[ans2] ? ans1 : ans2;
}

int getLCA(int u, int v){
    if (!flag_chto_tree_postroeno_suka){
        p = 1;
        while (p < vertexes.size()) p *= 2;
        p *= 2;
        tree.resize(p-1);
        for (int i = vertexes.size(); i < p/2; i++){
            vertexes.push_back(1000002);
        }
        build_tree();
       // flag_chto_tree_postroeno_suka = true;

    }

    if (index[u] > index[v]) swap(u,v);
        return getMin(0, 0, p/2 - 1, index[u], index[v]);
}


void dfs(int vertex, int h){
    visited[vertex] = true;
    depth[vertex] = h;
    vertexes.push_back(vertex);
    if (!uze_v_ind[vertex]) {
        index[vertex] = vertexes.size()-1;
        uze_v_ind[vertex] = true;
    }
    for (int k = 0; k < graf[vertex].size(); k++){
        if (!visited[graf[vertex][k]]){
            dfs(graf[vertex][k], h+1);
            vertexes.push_back(graf[vertex][k]);
            sum[vertex] += sum[graf[vertex][k]];
        }
        vertexes.push_back(vertex);
    }
    if (last[col[vertex]] != -1){
        sum[getLCA(vertex, last[col[vertex]])]--;
    }
    last[col[vertex]] = vertex;
}

void printGraf(){
    for (int i = 0; i < n; i++){
        for (auto j : graf[i]){
            cout << j << " ";
        }
        cout << endl;
    }
}

int main(){

    cin >> n; n++;
    graf.resize(n);
    visited.resize(n);
    depth.resize(n);
    index.resize(n); index[0] = 0;
    uze_v_ind.resize(n); uze_v_ind[0] = true;
    sum.resize(n);
    last.resize(n);
    col.resize(n);

    for (int i = 0 ; i < n - 1; i++){
        int buf;
        cin >> buf;
        graf[buf].push_back(i+1);
        cin >> buf;
        col[i+1] = buf;
    }

    for (int i = 0 ; i < sum.size(); i++){
        sum[i] = 1;
        if (i != 0) last[i] = -1;
    }

    dfs(0,0);

    for (int i = 1; i < sum.size(); i++){
        cout << sum[i] << " ";
    }
}
