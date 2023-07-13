#include <bits/stdc++.h>
#define lcm(a,b) (a/__gcd(a,b))*b
#define jumanji ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define F first
#define S second
#define vi vector<int>
#define ll long long
using namespace std;
const int tam=200005;
int T[4*tam];
int n;
int query(int lo, int hi) {
	int ra = 0, rb = 0;
	for (lo += n, hi += n + 1; lo < hi; lo /= 2, hi /= 2) {
		if (lo & 1) ra = max(ra, T[lo++]);
		if (hi & 1) rb = max(rb, T[--hi]);
	}
	return max(ra, rb);
}
void update(int idx, int val) {
	T[idx += n] = val;
	for (idx /= 2; idx; idx /= 2) T[idx] = max(T[2 * idx], T[2 * idx + 1]);
}
int main()
{
    return 0;
}  