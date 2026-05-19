class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

    vector<vector<pair<int, int>>> adj(n+1);
    for(const auto& time : times){
        int u = time[0];
        int v = time[1];
        int w = time[2];
        adj[u].push_back({v,w});
    }

    vector<int> distance(n + 1, INT_MAX);
    distance[k] = 0;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>,      
            greater<pair<int, int>>> pq; 
    
    pq.push({0, k});

    while (!pq.empty()){
        pair<int,int> current = pq.top();
        pq.pop();

        int currTime = current.first;
        int u = current.second;

        if(currTime > distance[u]){
            continue;
        }

        for (const auto& neighbor : adj[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;

                if (distance[u] + weight < distance[v]) {
                    distance[v] = distance[u] + weight;
                    pq.push({distance[v], v});
                }
        }

    }

        int maxTime = 0;
        for(int i = 1; i <= n; i++){
            if(distance[i] == INT_MAX){
                return -1;
            }
            maxTime = max(maxTime, distance[i]);
        }
        return maxTime;
    }
};