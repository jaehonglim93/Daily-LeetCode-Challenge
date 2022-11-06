class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        vector<vector<int>> adjMatrix;
        
        unordered_map<int, vector<int>> map;
        
        for (auto v : edges) {
            int v1 = v[0];
            int v2 = v[1];
            
            if (map.find(v1) == map.end()) {
                map[v1] = vector<int>(); 
            }
            map[v1].push_back(v2);
            
            if (map.find(v2) == map.end()) {
                map[v2] = vector<int>();
            }
            map[v2].push_back(v1);
            
            if (map[v1].size() == edges.size()) {
                return v1;
            }
            
            if (map[v2].size() == edges.size()) {
                return v2;
            }
        }
        
        return 0;
    }
};