//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// BFS from given source s
vector<int> bfs(vector<vector<int>>& adj)  {
    int V = adj.size();
    
    int s = 0; // source node 
    // create an array to store the traversal
    vector<int> res;

    // Create a queue for BFS
    queue<int> q;  
    
    // Initially mark all the vertices as not visited
    vector<bool> visited(V, false);

    // Mark source node as visited and enqueue it
    visited[s] = true;
    q.push(s);

    // Iterate over the queue
    while (!q.empty()) {
      
        // Dequeue a vertex from queue and store it
        int curr = q.front();
        q.pop();
        res.push_back(curr);

        // Get all adjacent vertices of the dequeued 
        // vertex curr If an adjacent has not been 
        // visited, mark it visited and enqueue it
        for (int x : adj[curr]) {
            if (!visited[x]) {
                visited[x] = true;
                q.push(x);
            }
        }
    }

    return res;
}



// Recursive function for DFS traversal
void dfsRec(vector<vector<int>> &adj, vector<bool> &visited, int s, vector<int> &res)
{

    visited[s] = true;

    res.push_back(s);

    // Recursively visit all adjacent vertices
    // that are not visited yet
    for (int i : adj[s])
        if (visited[i] == false)
            dfsRec(adj, visited, i, res);
}

// Main DFS function that initializes the visited array
// and call DFSRec
vector<int> DFS(vector<vector<int>> &adj)
{
    vector<bool> visited(adj.size(), false);
    vector<int> res;
    dfsRec(adj, visited, 0, res);
    return res;
}

// To add an edge in an undirected graph
void addEdge(vector<vector<int>> &adj, int s, int t)
{
    adj[s].push_back(t);
    adj[t].push_back(s);
}

int main()
{
    int V = 0;
    vector<vector<int>> adj(V);

    // Add edges
    vector<vector<int>> edges = {{1,2}, {0,4}, {0,3,7}, {4,5,2}, {1,3}, {3,6},{5},{2}};
    for (auto &e : edges)
        addEdge(adj, e[0], e[1]);

    // Starting vertex for DFS
    vector<int> res = DFS(adj); // Perform DFS starting from the source verte 0;

    for (int i = 0; i < V; i++)
        cout << res[i] << " ";

    return 0; 
}


// int main()  {

//     vector<vector<int>> adj = {{1,2}, {0,4}, {0,3,7}, {4,5,2}, {1,3}, {3,6},{5},{2}};
//     vector<int> ans = bfs(adj);
//     for(auto i:ans) {
//         cout<<i<<" ";
//     }
//     return 0;
// }
