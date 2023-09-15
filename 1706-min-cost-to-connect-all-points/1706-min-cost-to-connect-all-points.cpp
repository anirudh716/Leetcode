class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        
        // Create a vector to store edges and their costs.
        vector<vector<int>> edges;
        
        // Calculate the distance between all pairs of points and store them as edges.
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int cost = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({cost, i, j});
            }
        }
        
        // Sort edges by cost in ascending order.
        sort(edges.begin(), edges.end());
        
        // Create a parent array for Union-Find.
        vector<int> parent(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
        
        int minCost = 0;
        int edgeCount = 0;
        
        // Kruskal's algorithm to find the minimum spanning tree.
        for (const vector<int>& edge : edges) {
            int cost = edge[0];
            int u = edge[1];
            int v = edge[2];
            
            // Find parents of u and v using Union-Find.
            int pu = find(parent, u);
            int pv = find(parent, v);
            
            // If they have different parents, include this edge in the MST.
            if (pu != pv) {
                parent[pu] = pv;
                minCost += cost;
                edgeCount++;
            }
            
            // Stop when we have included enough edges to form a spanning tree.
            if (edgeCount == n - 1) {
                break;
            }
        }
        
        return minCost;
    }
    
    // Find operation for Union-Find with path compression.
    int find(vector<int>& parent, int x) {
        if (parent[x] != x) {
            parent[x] = find(parent, parent[x]);
        }
        return parent[x];
    }
};
