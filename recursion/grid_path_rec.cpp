#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second

const int MX = 1001;
const double ESP = 1e-6;
const double PI = acos(-1.0);

typedef long long ll;


int vis[MX][MX];


int numberOfPathsRec(int m, int n) {
    if(m == 1 || n == 1) {
        return 1;
    }

    if (vis[m][n] != 0) {
        return vis[m][n];
    }

    vis[m][n] = numberOfPathsRec(m - 1, n) + numberOfPathsRec(m, n - 1);

    return vis[m][n];
}


int numberOfPathsDiaRec(int n, int m) {
    if(m == 1 || n == 1) {
        return 1;
    }

    if (vis[m][n] != 0) {
        return vis[m][n];
    }

    vis[m][n] = numberOfPathsDiaRec(m - 1, n) + numberOfPathsDiaRec(m, n - 1) + numberOfPathsDiaRec(m - 1, n - 1);

    return vis[m][n];
}


int numberOfPaths(int m, int n) {
    int dp[m + 1] [n + 1];

    for (int i = 0; i < m; i++){
        dp[i][0] = 1;
    }

    for (int i = 0; i < n; i++) {
        dp[0][i] = 1;
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = dp[i - 1] [j] + dp[i] [j - 1];
        }
    }

    return dp[m - 1] [n - 1];
}


int numberOfPathsDia(int m, int n) {
    int dp[m + 1][n + 1];

    for(int i = 0; i < m; i++) {
        dp[i][0] = 1;
    }

    for(int i = 0; i < n; i++) {
        dp[0][i] = 1;
    }

    for(int i = 1; i < m; i++) {
        for(int j = 1; j < n; j++) {
            dp[i] [j] = dp[i - 1][j] + dp[i][j - 1] + dp[i - 1] [j - 1];
        }
    }
    return dp[m - 1][n - 1];
}


int getFactorial(int n) {
    if(n == 0) {
        return 1;
    }

    int factorial = 1;
    for (int i = 2; i <= n; i++)
        factorial = factorial * i;
    return factorial;
}

int getnCr(int n, int r) {
    return getFactorial(n) / (getFactorial(r) * getFactorial(n - r));
}

int numberOfPathsNcr(int m, int n) {
    return getnCr(m + n - 2, n - 1);
}


int numberOfPathsDiaNcr(int m, int n) {
    // not completed
    int totalDiagonal = (m - 1) * (n - 1);
    return totalDiagonal;
}



struct Node{
    vector<pair<int, int>> path;
    int r, c;
};



void printaPath(vector< pair< int, int> > path, int m, int n) {
    for (auto p: path) {
        cout<<"["<< p.fi << "," << p.se << "]";
        if (p.fi < m - 1 || p.se < n - 1) {
            cout<<" -> ";
        }
    } cout<<endl;
}


void bfsPath(int m, int n) {

    queue<Node> q;
    q.push({{{0,0}}, 0, 0});

    while(!q.empty()) {
        Node frontNode = q.front();
        q.pop();

        if ( frontNode.r == m - 1 && frontNode.c == n - 1) {
            printaPath(frontNode.path, m, n);
            continue;
        }

        if (frontNode.r == m - 1) {
            vector< pair<int, int> > path = frontNode.path;
            path.push_back({ frontNode.r, frontNode.c + 1});
            q.push({path, frontNode.r, frontNode.c + 1});
        } else if (frontNode.c == n - 1) {
            vector< pair<int, int> > path = frontNode.path;
            path.push_back({ frontNode.r + 1, frontNode.c});
            q.push({path, frontNode.r + 1, frontNode.c});
        } else {
            vector< pair<int, int> > path = frontNode.path;
            path.push_back({ frontNode.r, frontNode.c + 1});
            q.push({path, frontNode.r, frontNode.c + 1});

            // back to other way
            path.pop_back();

            path.push_back({ frontNode.r + 1, frontNode.c});
            q.push({path, frontNode.r + 1, frontNode.c});
        }
    }
}


void dfsPath(int m, int n, int r, int c, vector< pair< int, int> > path) {

    // base case
    if (r >= m || c >= n) {
        return;
    }

    if(r == m - 1 && c == n - 1) {
        printaPath(path, m, n);
        return;
    }
    if (r + 1 < m) {
        path.push_back({r + 1, c});
        dfsPath(m, n, r + 1, c, path);
        //  go to other way
        path.pop_back();
    }
    if (c + 1 < n) {

        path.push_back({r, c + 1});
        dfsPath(m, n, r, c + 1, path);
     //   path.pop_back();
    }
    return;
}


int main() {
    int m = 4, n = 6;
	memset(vis, 0 , sizeof(vis));

	cout << numberOfPathsRec(m, n) << endl;
    cout << numberOfPaths(m, n) << endl;
    cout << numberOfPathsNcr(m, n) << endl;

    memset(vis, 0 , sizeof(vis));

    cout << numberOfPathsDiaRec(m, n) << endl;
    cout << numberOfPathsDia(m, n) << endl;
    cout << numberOfPathsDiaNcr(m, n) << endl;

    cout<<"BFS path"<<endl;
    bfsPath(3, 3);

    cout<<"DFS path"<<endl;
    vector< pair < int, int > > path;
    path.push_back({0, 0});
    dfsPath(4, 3, 0, 0, path);

	return 0;
}

