#include <bits/stdc++.h>


using namespace std;
struct Node{
    int flag = 0; // 0 - nothing, 1 - add
    long long ans;
    long long add_value;
};

int n;
vector <vector <int >> graf;
vector <bool> visited;
vector <int> vertexes;
vector <int> depth;
vector <int> index;
vector <bool> uze_v_ind;
vector <int> tree;
long long p;


void update(int vertex, int left, int right, int a, int b, long long addValue){
    if (a > b)
        return;
	if (a == left && right == b){
        tree[vertex] += addValue;
	} else {
		int tm = (left + right) / 2;
		update (vertex*2 + 1, left, tm, a, min(b,tm), addValue);
		update (vertex*2 + 2, tm+1, right, max(a,tm+1), b, addValue);
	}

}

int get(int vertex, int left, int right, int pos){
    if (left > right) return 0;
    if (left == right)
		return tree[vertex];
	int tm = (left + right) / 2;
	if (pos <= tm)
		return tree[vertex] + get (vertex*2 + 1, left, tm, pos);
	else
		return tree[vertex] + get (vertex*2 + 2, tm + 1, right, pos);
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
        }
        vertexes.push_back(vertex);
    }
}


int main()
{
    cin >> n;
    graf.resize(n);
    visited.resize(n);
    depth.resize(n);
    index.resize(n); index[0] = 0;
    uze_v_ind.resize(n); uze_v_ind[0] = true;

    int u, v;
    for (int i = 0 ; i < n - 1; i++){
        cin >> u >> v;
        u--; v--;
        if (u > v) swap(u,v);
        graf[u].push_back(v);
    }

    dfs(0,0);
    p = 1;
    while (p < vertexes.size()) p *= 2;
    p *= 2;

    tree.resize(p-1);

    for (int i = 0; i < tree.size(); i++){
            cout << tree[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < vertexes.size(); i++){
        cout << vertexes[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < depth.size(); i++){
        cout << depth[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < index.size(); i++){
        cout << index[i] << " ";
    }
    cout << endl;

    int m;
    cin >> m;
    for (int i = 0; i < m; i++){
        char buf; cin >> buf;
        if (buf == '+'){
            int add;
            cin >> u >> v >> add;
            u--; v--;
            if (index[u] > index[v]) swap(u,v);
            update(0, 0, p/2 - 1, index[u], index[v], add);
                    for (int i = 0; i < tree.size(); i++){
                    cout << tree[i] << " ";
                    }
                    cout << endl;

        } else {
            cin >> u;
            u--;
            cout << get(0, 0, p/2 - 1, index[u]) << endl;
        }


    }




}
