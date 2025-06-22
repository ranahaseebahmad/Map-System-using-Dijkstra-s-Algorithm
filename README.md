# Map-System-using-Dijkstra-s-Algorithm
Map System using Dijkstra's Algorithm

This is a "C++ implementation" of a basic map system that allows users to input cities and roads (with distances), then calculates the **shortest path** between two cities using "Dijkstra’s Algorithm".

---
Features

- Add bidirectional roads with distance (weighted edges).
- Calculate the shortest path between two cities.
- Handles user-defined inputs (city names, edges, and weights).
- Uses "Dijkstra's Algorithm" with a "priority queue" for efficient pathfinding.
- Displays the shortest path from source to destination, if one exists.

---

Algorithm Used

:Dijkstra’s Algorithm" is a greedy algorithm used to find the shortest path from a source node to all other nodes in a weighted graph.

- Time Complexity: `O((V + E) log V)` using a min-heap (priority queue).
- Works for graphs with non-negative edge weights.

---

 How to Run

1.Compile the program:
  
   g++ -o map_system map_system.cpp


2.Run the program:
   ./map_system
 

3. Sample Input:
   ```
   Enter the number of edges: 5
   Enter city1, city2 and weight (space-separated): A B 10
   Enter city1, city2 and weight (space-separated): A C 5
   Enter city1, city2 and weight (space-separated): B C 2
   Enter city1, city2 and weight (space-separated): B D 1
   Enter city1, city2 and weight (space-separated): C D 9
   Enter the starting city: A
   Enter the destination city: D
   ```

4.Expected Output:
   
   Shortest path from A to D: A C B D
   

---

Dependencies

- Standard C++ libraries: `iostream`, `vector`, `queue`, `unordered_map`, `limits`, `string`, `algorithm`.

---

Concepts Practiced

- Graph Data Structure
- Dijkstra’s Algorithm
- Priority Queue / Min Heap
- C++ STL (Standard Template Library)
- Path Reconstruction

---

Author
```Rana Haseeb Ahmad```

---
To-Do / Enhancements

- [ ] Add support for directed graphs.
- [ ] Visualize the graph and shortest path.
- [ ] Extend to support real geographic data (maps API integration).

