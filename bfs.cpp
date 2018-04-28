#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct node {
    int val;
};

void add_edge(vector<int> adj[], int n1, int n2) {
    adj[n1].push_back(n2);
    adj[n2].push_back(n1);
}

void bfs(int root, vector<int> adj[], vector<node> nodes) {

    int visited[nodes.size()];
    for(int i=0; i<nodes.size(); i++) {
        visited[i] = 0;
    }

    queue<int> q;
    q.push(root);
    visited[root] = 1;

    while(q.size()>0) {
        int current = q.front();
        cout<<"Node:"<<current<<" Value:"<<nodes[current].val<<endl;
        q.pop();
        vector<int> children = adj[current];
        for(vector<int>::iterator p=children.begin(); p!=children.end(); p++) {
            if (visited[*p]==0) {
                q.push(*p);
                visited[*p] = 1;
            }
        }
    }

}

int main() {
    vector<int> adj[10];
    vector<node> nodes(10);
    int i = 0;
    for(vector<node>::iterator p=nodes.begin(); p!=nodes.end(); p++) {
        p->val = 10-i;
        i += 1;
    }
    add_edge(adj, 1, 3);
    add_edge(adj, 2, 5);
    add_edge(adj, 1, 6);
    add_edge(adj, 5, 7);
    add_edge(adj, 4, 6);
    add_edge(adj, 4, 2);
    add_edge(adj, 1, 4);
    add_edge(adj, 2, 8);
    bfs(1, adj, nodes);
    return 0;
}