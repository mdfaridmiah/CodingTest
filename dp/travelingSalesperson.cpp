#include<bits/stdc++.h>
using namespace std;

const int MX =  1234567;
const int INF = 0xfffffff;


int tsp(int mask, int last, vector<vector<int>> &cost, vector<vector<int>> &dp, int n, int pos) {
    // base cases
    int ret = dp[mask][last];
    if(ret != -1) return ret;
    if(mask == 0) return cost[last][pos];

    // find the minimum cost in current state

     for(int i = 0; i < n; i++) {
        if(mask & (1 << i)) {
            ret = min(ret, tsp(mask ^ (1 << i), i, cost, dp, n, pos) + cost[last][i]);
        }
    }
    return ret;
}

int main(){
    int node, edge;
    scanf("%d%d",&node, &edge);

    //vector<pair<int, int>> g[node + 1];
    vector<vector<int>> cost(node + 1, vector<int> (node + 1 , INF));

    for(int i = 0; i <= node; i++){
        cost[i][i] = 0;
    }

    for(int j = 0; j < edge; j++){
        int u, v, w;
        scanf("%d%d%d",&u,&v,&w);
        cost[u][v] = w;
        cost[v][u] = w;
    }
    vector<vector<int>> dp(1 << node, vector<int> (node + 1 , -1));

    // 1 << node = 1 * 2^node = 2^3 = 8 = (1000) - 1 = 111 - 1 = 110

    int res = tsp((1 << node) - 2, 0, cost, dp, edge, 0);
    cout<<res<<endl;

    return 0;
}
