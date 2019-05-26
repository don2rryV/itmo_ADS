#include <bits/stdc++.h>

using namespace std;

struct Node{
    int flag = 0; // 0 - nothing, 1 - set, 2 - add
    long long set_value;
    long long ans;
    long long add_value;
};
vector <Node> tree;
const long long cnst = pow(10,18);

void treeBuild(vector <Node> a){
    for (int i = 0; i < a.size(); i++){
        tree[tree.size()/2 + i].ans = a[i].ans;
    }
    for (int i = a.size()-2; i >= 0; i--){
        tree[i].ans = min(tree[2 * i + 1].ans, tree[2 * i + 2].ans);
    }
}

void push(int vertex) {
	if (tree[vertex].flag == 1 && (2*vertex + 1) < tree.size()) {
		tree[2*vertex + 1].set_value = tree[vertex].set_value;
		tree[2*vertex + 1].ans = tree[vertex].set_value;
		tree[2*vertex + 1].flag = 1;
		tree[2*vertex + 2].set_value = tree[vertex].set_value;
		tree[2*vertex + 2].ans = tree[vertex].set_value;
		tree[2*vertex + 2].flag = 1;
		tree[vertex].flag = 0;
	} else if (tree[vertex].flag == 2 && (2*vertex + 1) < tree.size()){
        tree[2*vertex + 1].ans += tree[vertex].add_value;
        tree[2*vertex + 2].ans += tree[vertex].add_value;
        push(2*vertex + 1);
        tree[2*vertex + 1].add_value = tree[vertex].add_value;
        push(2*vertex + 2);
        tree[2*vertex + 2].add_value = tree[vertex].add_value;
        tree[2*vertex + 1].flag = 2;
        tree[2*vertex + 2].flag = 2;
        tree[vertex].flag = 0;
	}

}

void updateMIN(int vertex){
    if (vertex == 0){
        return;
    }
    //tree[(vertex - 1)/2].ans = min(tree[vertex].ans, tree[((vertex - 1)/2)*2]);
    if (vertex == (vertex-1)/2 * 2 + 1) {
        tree[(vertex-1)/2].ans = min(tree[vertex].ans, tree[((vertex-1)/2)*2+ 2].ans);
    } else {
        tree[(vertex-1)/2].ans = min(tree[vertex].ans, tree[((vertex-1)/2)*2+ 1].ans);
    }
    updateMIN((vertex-1)/2);
}

void updateAdd(int vertex, int left, int right, int a, int b, long long addValue){
    if (a > b)
        return;
	if (a == left && right == b){
        if (tree[vertex].flag == 2){
            tree[vertex].ans += addValue;
            updateMIN(vertex);
            tree[vertex].add_value += addValue;
        } else if (tree[vertex].flag == 1){
            push(vertex);
            tree[vertex].ans += addValue;
            updateMIN(vertex);
            tree[vertex].flag = 2;
            tree[vertex].add_value = addValue;
        } else {
            tree[vertex].ans += addValue;
            updateMIN(vertex);
            tree[vertex].flag = 2;
            tree[vertex].add_value = addValue;
        }

	} else {
	    push(vertex);
		int tm = (left + right) / 2;
		updateAdd (vertex*2 + 1, left, tm, a, min(b,tm), addValue);
		updateAdd (vertex*2 + 2, tm+1, right, max(a,tm+1), b, addValue);
	}

}

void updateSet(int vertex, int left, int right, int a, int b, long long setValue){
    if (a > b)
		return;
	if (a == left && right == b){
		tree[vertex].ans = setValue;
		tree[vertex].set_value = setValue;
		tree[vertex].flag = 1;
		updateMIN(vertex);
	}
	else {
		push (vertex);
		int tm = (left + right) / 2;
		updateSet (vertex*2 + 1, left, tm, a, min(b,tm), setValue);
		updateSet (vertex*2+2, tm+1, right, max(a,tm+1), b, setValue);
	}
}

long long getMin (int vertex, int left, int right, int a, int b){
   //cout << vertex << " " << left << " " << right << " " << a << " " << b << endl;
    if (a > b) return cnst;
    if (a == left && b == right) {
        if (tree[vertex].flag == 2 && (2*vertex+1 < tree.size()))
            return tree[vertex].ans;
        else return tree[vertex].ans;
    }
    push(vertex);
    int m = (left + right)/2;
    return min(getMin(2*vertex + 1, left, m , a, min(b, m)),
        getMin(2*vertex + 2, m+1, right, max(a,m + 1), b));

}


int main()
{
    freopen("rmq2.in","r",stdin);
    freopen("rmq2.out","w",stdout);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    long long p = 1;
    while (p < n) p *= 2;
    p *= 2;
    vector <Node> a;
    a.resize(p/2);
    for (int i = 0; i < n; i++){
        cin >> a[i].ans;
    }
    for (int i = n; i < a.size(); i++){
        //a[i].ans = pow(10,18);
        a[i].ans = cnst;
    }
    tree.resize(p-1);
    if (n == 1) {
        tree = a;
    } else {
        treeBuild(a);
    }
    /*for (int i = 0; i < tree.size(); i++){
        cout << tree[i].ans << " ";
    }*/

    string buf;
    while (cin >> buf){
        if (buf == "min"){
               /* for (int i = 0; i < tree.size(); i++){
                cout << tree[i].flag  << " " << tree[i].ans  << endl;
            }*/

            int i, j;
            cin >> i >> j;
            cout << getMin(0, 0 , a.size()-1, --i, --j) << endl;


        } else if (buf == "set"){
            int i, j, x;
            cin >> i >> j >> x;
            updateSet(0, 0, a.size()-1, --i, --j, x);

           /* for (int i = 0; i < tree.size(); i++){
                cout << tree[i].flag  << " " << tree[i].ans  << endl;
            }*/

        } else if (buf == "add"){
            int i, j, x;
            cin >> i >> j >> x;
            updateAdd(0, 0 , a.size()-1, --i, --j, x);

            /*for (int i = 0; i < tree.size(); i++){
                cout << tree[i].flag  << " " << tree[i].ans  <<" "<< tree[i].add_value<< endl;
            }*/
        }
    }


}
