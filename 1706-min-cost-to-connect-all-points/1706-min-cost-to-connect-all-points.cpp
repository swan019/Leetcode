class Solution {
public:
    // Union-Find
    vector<int> parent,rankOf;

    int find(int node){
        if(parent[node] == node)  return node;
        return parent[node] = find(parent[node]);
    }

    void unionByRank(int u,int v){
        int parentU=find(u);
        int parentV=find(v);
        if(parentU == parentV)  return;

        if(rankOf[parentU] < rankOf[parentV]){
            parent[parentU] = parentV;
        }
        else if(rankOf[parentV]<rankOf[parentU]){
            parent[parentV] = parentU;
        }
        else{
            parent[parentV] = parentU;
            ++rankOf[parentU];
        }
    }
    int dist(int a,int b,int x,int y){
        return abs(a-x) + abs(b-y);
        // return manhattan distance
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        // dist : x,y
        vector<pair<int,pair<int,int>>> arr;
        for(int i=0;i<n;i++){
            int a = points[i][0];
            int b = points[i][1];
            for(int j=i+1;j<n;j++){
                int x = points[j][0];
                int y = points[j][1];
                arr.push_back({dist(a,b,x,y),{i,j}});
            }
        }
        // Sort according to distance
        sort(arr.begin(),arr.end());

        parent.resize(n),rankOf.resize(n,0);
        for(int i=0;i<n;i++)    parent[i]=i;

        int cost = 0;
        for(auto &it:arr){
            int dist = it.first;
            int f = it.second.first;
            int s = it.second.second;
            if(find(f) != find(s)){
                unionByRank(f,s);
                cost += dist;
            }
        }

        return cost; 
    }
};
