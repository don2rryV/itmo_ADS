#include <bits/stdc++.h>

using namespace std;

struct Node{
    int flag = 0; // 0 - nothing, 1 - set
    long long set_value;
    long long ans;
    long long add_value;
};
vector <Node> tree;
const long long cnst = pow(10,7);
int index;
int minBuf;
int p = 1;

void push(int vertex) {
	if (tree[vertex].flag == 1 && (2*vertex + 1) < tree.size()) {
        if (tree[vertex].set_value > tree[2*vertex + 1].ans){
            tree[2*vertex + 1].set_value = tree[vertex].set_value;
            tree[2*vertex + 1].ans = tree[vertex].set_value;
            tree[2*vertex + 1].flag = 1;
            tree[vertex].flag = 0;
        }
        if (tree[vertex].set_value > tree[2*vertex + 2].ans){
            tree[2*vertex + 2].set_value = tree[vertex].set_value;
            tree[2*vertex + 2].ans = tree[vertex].set_value;
            tree[2*vertex + 2].flag = 1;
            tree[vertex].flag = 0;
        }
        tree[vertex].flag = 0;
	}
}

void updateMIN(int vertex){
    if (vertex == 0){
        return;
    }
    if (vertex == (vertex-1)/2 * 2 + 1) {
        tree[(vertex-1)/2].ans = min(tree[vertex].ans, tree[((vertex-1)/2)*2+ 2].ans);
    } else {
        tree[(vertex-1)/2].ans = min(tree[vertex].ans, tree[((vertex-1)/2)*2+ 1].ans);
    }
    updateMIN((vertex-1)/2);
}

void updateSet(int vertex, int left, int right, int a, int b, int setValue){
    if (a > b)
		return;
	if (a == left && right == b){
        if (setValue > tree[vertex].ans){
            tree[vertex].ans = setValue;
            tree[vertex].set_value = setValue;
            tree[vertex].flag = 1;
            updateMIN(vertex);
        }
	}
	else {
		push (vertex);
		int tm = (left + right) / 2;
		updateSet (vertex*2 + 1, left, tm, a, min(b,tm), setValue);
		updateSet (vertex*2+2, tm+1, right, max(a,tm+1), b, setValue);
	}
}

int getMin (int vertex, int left, int right, int a, int b){
   cout << vertex << " " << left << " " << right << " " << a << " " << b << endl;
    if (a > b) return cnst;
    if (a == left && b == right) {
            if (tree[vertex].ans == minBuf) index = vertex;
            //cout << "index = " << index << endl;
            return tree[vertex].ans;
    }

    push(vertex);
    int m = (left + right)/2;
    int s1 = getMin(2*vertex + 1, left, m , a, min(b, m));
    int s2 = getMin(2*vertex + 2, m+1, right, max(a,m + 1), b);
    if (s1 < s2) {
        //if (2 * vertex + 1<= index)
            if (tree[2*vertex+1].ans == minBuf)
                index = 2* vertex + 1;
            //cout << "index = " << index << endl;
        return s1;
    } else {
        //if (2 * vertex + 2<= index)
            if (tree[2*vertex + 2].ans == minBuf)
                index = 2*vertex + 2;
            //cout << "index = " << index << endl;
        return s2;
    }
}

int findInTree(int vertex, int value, int a, int b){
    /*int k = vertex;
    while (2*vertex + 1 < tree.size()){
        push(vertex);

        for (int i = 0; i < tree.size(); i++){
            cout << tree[i].ans << " ";
        }
        cout << endl;

        if (tree[2*vertex + 1].ans == value && (2*vertex + 1) >= (a + tree.size() - p/2) && (2*vertex + 1) >= (a + tree.size() - p/2)
            vertex = 2*vertex + 1;
        else vertex = 2*vertex + 2;

    }
    return vertex;*/
    //cout << "vertex = " << vertex << endl;
   /* push(vertex);
    if ( 2 * vertex + 1 >= tree.size())
        return vertex;
    if (tree[2*vertex + 1].ans == value){
        return findInTree(2*vertex + 1, value);
    } else {
        return findInTree(2*vertex + 2, value);
    }*/
    //if (tree[vertex].ans == value) return vertex;
    /*if (2 * vertex + 1 < tree.size()) {
            if ()
            return findInTree(2*vertex + 1, value);
    }
    if (2 * vertex + 2 < tree.size()) return findInTree(2*vertex + 2, value);*/
        push(vertex);


    if (2*vertex + 1 < tree.size()){
        if (tree[2*vertex + 1].ans == value)
             if ((2*vertex + 1) >= (a + tree.size() - p/2) && (2*vertex + 1) <= (b + tree.size() - p/2))
                return (2 * vertex + 1);
            else return findInTree(2*vertex + 1, value, a,b);
        else {
            return findInTree(2*vertex + 2, value, a,b);
        }
    }
    else {
        if (vertex >= (a + tree.size() - p/2) && vertex <= (b + tree.size() - p/2))
            return vertex;
        else return vertex + 1;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    while (p < n) p *= 2;
    p *= 2;
    tree.resize(p - 1);
    string buf;

    for (int i = 0; i < m; i++){
        cin >> buf;
        if (buf == "defend"){
            int a,b,c;
            cin >> a >> b >> c;
            updateSet(0,0, p/2-1, a-1, b-1, c);

        } else {
            int d,e;
            cin >> d >> e;
            minBuf = 0;
            minBuf = getMin(0,0, p/2 - 1, d-1, e-1);
            cout << "index = " << index << endl;
            int ind = tree.size();
            ind = findInTree(index, minBuf, d-1, e-1);
            cout << minBuf << " " << ind - (tree.size() - p/2 - 1) << endl;
        }
    }


}
