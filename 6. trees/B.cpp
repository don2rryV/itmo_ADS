#include <bits/stdc++.h>

using namespace std;
vector <vector <int> > graf;
vector <vector <int> > dp;
vector <int> depth;
vector <bool> visited;
vector <int> parent;
vector <vector <int>> weight;
vector <int> power;
int lg, n;
void dfs(long long vertex, long long h){
    visited[vertex] = true;
    depth[vertex] = h;
    for (auto k : graf[vertex]){
        if (!visited[k]){
            dfs(k, h + 1);
        }
    }
}

void preprocess(){

    for (int i = 0; i < n; i++){
        dp[i][0] = parent[i];
    }
    for (int j = 1; j < lg; j++){
        for (int i = 0; i < n; i++)
            dp[i][j] = dp[dp[i][j - 1]][j - 1];
        for (int i = 0; i < n; i++)
            if (weight[i][j-1] < weight[dp[i][j-1]][j-1]) weight[i][j] = weight[i][j-1];
                else weight[i][j] = weight[dp[i][j-1]][j-1];
    }

}

int getMin(int v, int u){
    lg--; int out = 1000001;
    for (int i = lg; i >= 0; i--){
        if (depth[u] - depth[v] >= power[i]){
            out = (weight[u][i] <= out) ? weight[u][i] : out;
            u = dp[u][i];
        }
    }

    if (v == u) {
        lg++;
        return out;
    }
    for (int i = lg; i >= 0; i--){
        if (dp[v][i] != dp[u][i]){
            out = (weight[u][i] <= out) ? weight[u][i] : out;
            out = (weight[v][i] <= out) ? weight[v][i] : out;
            v = dp[v][i];
            u = dp[u][i];
        }
    }

    out = (weight[u][0] <= out) ? weight[u][0] : out;
    out = (weight[v][0] <= out) ? weight[v][0] : out;

    lg++;
    return out;

}


int main()
{
    freopen("minonpath.in","r",stdin);
    freopen("minonpath.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin >> n;
    lg = log(n)/log(2) + 1;

    graf.resize(n);
    visited.resize(n);
    depth.resize(n);
    weight.resize(n);
    parent.resize(n); parent[0] = 0;
    power.resize(lg + 1);

    dp.resize(n);
    for (int i = 0; i < n; i++){
        dp[i].resize(lg + 1);
        weight[i].resize(lg + 1);
    }
    weight[0][0] = 1000001;

    power[0] = 1;
    for (int i = 1; i < lg + 1; i++) {
        power[i] = power[i - 1] * 2;
    }

    for (int i = 0 ; i < n - 1; i++){
        int buf; cin >> buf; buf--;
        int wt; cin >> wt;
        graf[buf].push_back(i + 1);
        parent[i + 1] = buf;
        weight[i + 1][0] = wt;
    }

    dfs(0, 0);
    preprocess();

    int m;
    cin >> m; int u, v;
    for (int i = 0; i < m; i++){
        cin >> u >> v;
        u--; v--;
        if (depth[u] > depth[v]) swap(u,v);

        cout << getMin(u,v) << endl;


    }



}
