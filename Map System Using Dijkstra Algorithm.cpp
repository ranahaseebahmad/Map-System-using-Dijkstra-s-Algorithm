#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <unordered_map>
#include <string>
#include <algorithm> // Include this header for std::reverse

using namespace std;

const int INF = numeric_limits<int>::max();

class Graph {
public:
    unordered_map<string, vector<pair<string, int>>> adjList;

    void addEdge(const string& u, const string& v, int weight) {
        adjList[u].emplace_back(v, weight);
        adjList[v].emplace_back(u, weight); // Assuming undirected graph
    }

    vector<string> dijkstra(const string& start, const string& end) {
        unordered_map<string, int> distances;
        unordered_map<string, string> previous;
        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;

        for (const auto& pair : adjList) {
            distances[pair.first] = INF;
        }
        distances[start] = 0;
        pq.emplace(0, start);

        while (!pq.empty()) {
            auto [currentDistance, currentNode] = pq.top();
            pq.pop();

            if (currentNode == end) {
                break; // Found the shortest path to the destination
            }

            for (const auto& neighbor : adjList[currentNode]) {
                const auto& [nextNode, weight] = neighbor;
                int newDistance = currentDistance + weight;

                if (newDistance < distances[nextNode]) {
                    distances[nextNode] = newDistance;
                    previous[nextNode] = currentNode;
                    pq.emplace(newDistance, nextNode);
                }
            }
        }

        // Reconstruct the path
        vector<string> path;
        for (string at = end; at != ""; at = previous.count(at) ? previous[at] : "") {
            path.push_back(at);
        }
        reverse(path.begin(), path.end());

        // Check if the path is valid
        if (path.size() == 1 && path[0] != start) {
            path.clear(); // No valid path found
        }

        return path;
    }
};

int main() {
    Graph graph;
    int n;

    cout << "Enter the number of edges: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        string city1, city2;
        int weight;
        cout << "Enter city1, city2 and weight (space-separated): ";
        cin >> city1 >> city2 >> weight;
        graph.addEdge(city1, city2, weight);
    }

    string startCity, endCity;
    cout << "Enter the starting city: ";
    cin >> startCity;
    cout << "Enter the destination city: ";
    cin >> endCity;

    vector<string> shortestPath = graph.dijkstra(startCity, endCity);

    if (!shortestPath.empty()) {
        cout << "Shortest path from " << startCity << " to " << endCity << ": ";
        for (const auto& city : shortestPath) {
            cout << city << " ";
        }
        cout << endl;
    } else {
        cout << "No path found from " << startCity << " to " << endCity << "." << endl;
    }

    return 0;
}
