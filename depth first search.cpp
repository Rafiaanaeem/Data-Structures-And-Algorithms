#include <iostream>
using namespace std;

const int MAX = 100; // Maximum number of vertices

class Graph {
private:
    int adj[MAX][MAX]; // Adjacency matrix
    bool visited[MAX]; // Visited array
    int stack[MAX];    // Manual stack
    int top;           // Stack top
    int nodes;         // Number of nodes

public:
    // Constructor
    Graph(int n) {
        nodes = n;
        top = -1;
        // Initialize adjacency matrix and visited array
        for (int i = 0; i < nodes; i++) {
            visited[i] = false;
            for (int j = 0; j < nodes; j++) {
                adj[i][j] = 0;
            }
        }
    }

    // Function to add a directed edge
    void addEdge(int from, int to) {
        adj[from][to] = 1;
    }

    // Push onto the stack
    void push(int value) {
        stack[++top] = value;
    }

    // Pop from the stack
    int pop() {
        return stack[top--];
    }

    // Check if the stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Non-recursive DFS function
    void DFS(int start) {
        push(start);

        while (!isEmpty()) {
            int current = pop();

            if (!visited[current]) {
                visited[current] = true;
                cout << current << " ";

                // Push neighbors in reverse order for correct DFS order
                for (int i = nodes - 1; i >= 0; i--) {
                    if (adj[current][i] == 1 && !visited[i]) {
                        push(i);
                    }
                }
            }
        }
    }
};

int main() {
    Graph g(6); // Create graph with 6 nodes (0 to 5)

    // Add directed edges
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(4, 5);

    /*
      Graph structure:
      0 → 1 → 3
      ↓
      2 → 4 → 5
    */

    cout << "Non-recursive DFS starting from node 0: ";
    g.DFS(0);

    return 0;
}
