#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second

const int MX = 1001;
const double ESP = 1e-6;
const double PI = acos(-1.0);

typedef long long ll;

bool solve(string &s, int i, string &p, int j, vector< vector<int> > &dp) {

    // Base cases
    if ( i < 0 && j < 0) {
        return true;
    }

    if( j < 0) {
        return false;
    }

    if ( i < 0) {
        for ( int k = 0; k <= j; k++) {
            if (p[k] != '*') {
                return false;
            }
        }
        return true;
    }

    if( dp[i][j] != -1) {
        return dp[i][j];
    }

    // implementation

    if ( p[j] == '?' || p[j] == s[i] ) {
        return dp[i][j] = solve(s, i - 1, p, j - 1, dp);
    }

    if ( p[j] == '*') {
        return dp[i][j] = solve(s, i - 1, p, j, dp) || solve(s, i, p, j - 1, dp);
    }

    return dp[i][j] = false;
}


void wildcardMatching(string &s, string &p) {
    int sLen = s.size();
    int pLen = p.size();
    vector< vector<int> > dp(sLen, vector<int> (pLen, -1));
    cout<< solve(s, sLen - 1, p, pLen - 1, dp)<<endl;
}


int main() {

    string s = "aaaa";
    string p = "*aa";
    wildcardMatching(s, p);
	return 0;

}

