//11725 트리의 부모 찾기
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n;
queue<int> q;
int parent[100001];
vector<int> children[100001];

int main() {
    cin >> n;
    parent[1] = 1;
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        children[a].push_back(b);
        children[b].push_back(a);
    }

    //1번을 루트로 bfs
    q.push(1);
    while (!q.empty()) {
        int front = q.front();
        for (int element : children[front]) {
            if (!parent[element]) {
                parent[element] = front;
                q.push(element);
            }
        }
        q.pop();
    }
    
    for (int i = 2; i <= n; ++i) {
        cout << parent[i] << '\n';
    }
}