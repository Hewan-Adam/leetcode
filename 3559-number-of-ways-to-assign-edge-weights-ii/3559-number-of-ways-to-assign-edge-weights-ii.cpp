#define Mod 1000000007
class Solution {
    private:
    void dfs(int node , int par , unordered_map<int , vector<int>> &adj, vector<int> &parent , vector<int> &depth){
        parent[node] = par;

        for(auto x : adj[node]){
            if(x == par){
                continue;
            }
            depth[x] = depth[node] + 1;
            dfs(x , node , adj , parent , depth);
        }
    }

    void build(vector<vector<int>> &up , vector<int> &parent){
        int n = parent.size();
        for(int i= 1; i < n; i++){
            up[i][0] = parent[i];
        }

        for(int i = 1 ; i < LOG; i++){
            for(int node = 1; node < n; node++){
                int ancestor = up[node][i- 1];

                if(ancestor != -1){
                    up[node][i] = up[ancestor][i - 1];
                }
            }
        }
    }
    void getPower(vector<int> &powers){
        powers[0] = 1;

        for(int i = 1; i < powers.size(); i++){
            powers[i] = (1LL * powers[i - 1] * 2) % Mod;
        }
    }

    int LowestCommonAncestor(int u , int v , vector<int> &depth , vector<vector<int>> &up){
        if(depth[u] < depth[v]){
            swap(u , v);
        }

        int diff = depth[u] - depth[v];

        for(int j = 0; j < LOG; j++){
            if(diff & (1 << j)){
                u = up[u][j];
            }
        }
        if(u == v) return u;

        for(int i = LOG -1; i >= 0; i--){
            if(up[u][i] != up[v][i]){
                u = up[u][i];
                v = up[v][i];
            }
        }
        return up[u][0];
    }

public:
    const int LOG = 20;
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        unordered_map<int , vector<int>> adj;
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int n = edges.size() + 1;
        vector<int> parent(n + 1 , -1);
        vector<int> depth(n + 1 , 0);
        vector<int> powers(n + 1 , 1);
        vector<vector<int>> up(n + 1  , vector<int> (LOG , -1));
        dfs(1 , -1 , adj , parent , depth);
        build(up , parent);
        getPower(powers);
        vector<int> ans;
        for(auto x : queries){
            int u = x[0] , v = x[1];

            int lca = LowestCommonAncestor(u , v , depth , up);
            int diff = depth[u] + depth[v] - 2 * depth[lca];
            if(diff == 0){
                ans.push_back(0);
                continue;
            }
            int val = powers[diff -1];
            ans.push_back(val);
        }      
        return ans;
    }
};