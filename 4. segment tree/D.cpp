#include <bits/stdc++.h>

using namespace std;


struct Node{
    int sum;
    int cnt;
};

vector <Node> tree;

void treeBuild(vector <int> a){
    for (int i = 0; i < a.size(); i++){
        tree[tree.size()/2 + i].sum = a[i];
    }
    for (int i = a.size()-2; i >= 0; i--){
        tree[i].sum = tree[2 * i + 1].sum + tree[2 * i + 2].sum;
        tree[i].cnt =
    }
}


int main()
{
    int n;
    cin >> n;
    char buf;
    vector <vector<int> > a;
    a.resize(n);
    int minElem = 500001, maxElem = -500001;

    for (int i = 0; i < n; i++){
        a[i].resize(3);
        cin >> buf >> a[i][1] >> a[i][2];
        a[i][2] += a[i][1];
        a[i][1]--;
        a[i][2]--;
        if (buf == 'W') {
            a[i][0] = 0;
        } else {
            a[i][0] = 1;
        }
        if (a[i][1] > maxElem) maxElem = a[i][1];
        if (a[i][2] > maxElem) maxElem = a[i][2];
        if (a[i][1] < minElem) minElem = a[i][1];
        if (a[i][2] < minElem) minElem = a[i][2];
    }

    vector <int> picture;
    int bufN;
    if(minElem < 0) bufN = maxElem + 1 + abs(minElem);
        else bufN = maxElem + 1;

    long long p = 1;
    while (p < bufN) p *= 2;
    p *= 2;

    picture.resize(p/2);
    tree.resize(p-1);

    for (int i = 0; i < a.size(); i++){
        for (int j = a[i][1]; j < a[i][2]; j++){
            picture[j] = a[i][0];
        }
        treeBuild(picture);
            /*for (int i = 0; i < tree.size(); i++){
                cout << tree[i] << " ";
            }
            cout << endl;*/
    }


}
