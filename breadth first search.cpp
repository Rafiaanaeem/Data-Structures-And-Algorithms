#include <iostream>
using namespace std;

const int MAX = 100; // Maximum number of nodes

class Graph {
private:
    int adj[MAX][MAX];   // Adjacency matrix
    bool visited[MAX];   // Visited array
    int queue[MAX];      // Array to simulate a queue
    int front, rear;     // Front and rear for queue
    int nodes;           // Number of nodes in the graph

public:
    // Constructor
    Graph(int n) {
        nodes = n;
        front = 0;
        rear = 0;
        // Initialize adjacency matrix and visited array
        for (int i = 0; i < nodes; i++) {
            visited[i] = false;
            for (int j = 0; j < nodes; j++) {
                adj[i][j] = 0;
            }
        }
    }

    // Function to add an undirected edge
    void addEdge(int u, int v) {
        adj[u][v] = 1;
        adj[v][u] = 1; // Add reverse edge for undirected graph
    }

    // Enqueue function
    void enqueue(int value) {
        queue[rear++] = value;
    }

    // Dequeue function
    int dequeue() {
        return queue[front++];
    }

    // Check if queue is empty
    bool isQueueEmpty() {
        return front == rear;
    }

    // BFS function
    void BFS(int start) {
        enqueue(start);
        visited[start] = true;

        while (!isQueueEmpty()) {
            int current = dequeue();
            cout << current << " ";

            // Visit all unvisited neighbors
            for (int i = 0; i < nodes; i++) {
                if (adj[current][i] == 1 && !visited[i]) {
                    enqueue(i);
                    visited[i] = true;
                }
            }
        }
    }
};

int main() {
    Graph g(6); // Create a graph with 6 nodes (0 to 5)

    // Add undirected edges
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(4, 5);

    /*
      Undirected Graph:
      0 — 1 — 3
      |
      2 — 4 — 5
    */

    cout << "BFS starting from node 0: ";
    g.BFS(0);

    return 0;
}
