class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, map<string, int>> graph;
        vector<string> result;
        
        // Build a graph using adjacency lists
        for (const vector<string>& ticket : tickets) {
            graph[ticket[0]][ticket[1]]++;
        }
        
        // Perform DFS starting from "JFK"
        dfs(graph, "JFK", result, tickets.size() + 1);
        
        return result;
    }
    
    bool dfs(unordered_map<string, map<string, int>>& graph, const string& node, vector<string>& result, int target) {
        result.push_back(node);
    
        if (result.size() == target) {
            return true;  // Found a valid itinerary
        }
    
        if (graph.find(node) != graph.end()) {
            for (auto& neighbor : graph[node]) {
                if (neighbor.second > 0) {
                    neighbor.second--;  // Mark the ticket as used
                    if (dfs(graph, neighbor.first, result, target)) {
                        return true;
                }
                    neighbor.second++;  // Backtrack
                }
            }
        }
    
        result.pop_back();  // Remove the current node from the itinerary
        return false;
    }

};