class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        if(n == 1)
            return 0;
        int final_mask = (1 << n) - 1;  //for n = 4, 10000 - 00001 = 1111
        vector<vector<bool>> visited(n, vector<bool> (final_mask, false));
        queue<pair<int, int>> q;
        for(int i=0; i<n; i++) {
            visited[i][1 << i] = true;
            q.push({i, 1 << i});
        }
        //so we have stored the initial states of every node
        //0001 means we started at node 1, our target = 1111, to visit all 4 nodes(e.x. 1)
        //0010 means we are at node 1, and so on
        //so we start from any position and try to reach in min steps
        //for that we will use BFS
        int steps = 0;
        while(!q.empty()) {
            int sz = q.size();
            queue<pair<int, int>> nxt_queue;
            for(int i=0; i<sz; i++) {
                auto front = q.front();
                q.pop();
                int curr_node = front.first;
                int curr_mask = front.second;
                // if(curr_mask == final_mask)
                //     return steps;
                //so where we go from here, what node we visit, that is given in graph matrix
                //or by adjacency matrix we can get the next mask
                for(int i: graph[curr_node]) {
                    int nxt_mask = curr_mask | (1 << i);
                    if(nxt_mask == final_mask)
                        return steps+1;
                    //say we are at node 0 (curr mask = 0001)
                    //and we will visit 1(because we can visit 1)
                    //so our next mask will be 0011 (i.e. curr_mask | (1 << i))
                    if(!visited[i][nxt_mask]) {
                        visited[i][nxt_mask] = true;
                        nxt_queue.push({i, nxt_mask});
                    }
                    //so we at node(= 1) now or any node reacheable through curr_node
                }
            }
            //from this state we will try to reach final state
            q = nxt_queue;
            steps++;
        }
        return -1;
    }
};