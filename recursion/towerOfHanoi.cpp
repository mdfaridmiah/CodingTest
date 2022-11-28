#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second

const int MX = 1001;
const double ESP = 1e-6;
const double PI = acos(-1.0);

typedef long long ll;

void solve ( int from, int to, int aux, int n ) {
    // A, C, B, N
    // base case
    if ( n == 0) {
        return;
    }
    // implement
    // a, c, b, n
    // a, b, c, n - 1
    // b, c, a, n - 1
    solve(from , aux, to, n - 1);
    printf("%d -> %d: %d\n", from, to, n);
    solve(aux , to, from, n - 1);
}

int main() {

    solve(1,3,2,3);
	return 0;

}

