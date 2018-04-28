#include<iostream>
#include<vector>


using namespace std;

struct node {
    int val;
};

void add_edge(vector<int> adj[], int n1, int n2) {
    adj[n1].push_back(n2);
    adj[n2].push_back(n1);
}

void dfs(int root, vector<int> adj[], vector<node> &nodes, int* visited) {

    visited[root] = 1;
    cout<<"Node:"<<root<<" Value:"<<nodes[root].val<<endl;

    for(vector<int>::iterator p=adj[root].begin(); p!=adj[root].end(); p++) {
        if (visited[*p] == 0) {
            dfs(*p, adj, nodes, visited);
        }
    }
}

int* init_visited(int size) {
    int *visited = new int[size];
    for (int i=0; i<size; i++) {
        visited[i] = 0;
    }
    return visited;
}

int main() {
    vector<int> adj[10];
    vector<node> nodes(10);
    int i = 0;
    for(vector<node>::iterator p=nodes.begin(); p!=nodes.end(); p++) {
        p->val = 10-i;
        i += 1;
    }
    add_edge(adj, 0, 1);
    add_edge(adj, 1, 3);
    add_edge(adj, 2, 5);
    add_edge(adj, 1, 6);
    add_edge(adj, 5, 7);
    add_edge(adj, 4, 6);
    add_edge(adj, 4, 2);
    add_edge(adj, 1, 4);
    add_edge(adj, 2, 8);
    dfs(0, adj, nodes, init_visited(10));
    return 0;
}