// Problem statement
// You are given a square matrix of size ‘N * N’, where each cell contains a
// distinct integer from ‘1’ to ‘N * N’. The matrix is sorted diagonally from
// bottom left to top right.

// For example, a ‘3 * 3’ matrix looks like:

// [1, 3, 6]
// [2, 5, 8]
// [4, 7, 9]
// The diagonals in the matrix are numbered from ‘1’ to ‘2 * N - 1’. Let’s see
// the scenario for this case:
// - Diagonal ‘1’ looks like: [1]
// - Diagonal ‘2’ looks like: [2, 3]
// - Diagonal ‘3’ looks like: [4, 5, 6]
// - Diagonal ‘4’ looks like: [7, 8]
// - Diagonal ‘5’ looks like: [9]

// You will be given an integer ‘D’, denoting the diagonal number. You have to
// find the sum of all the numbers present in that diagonal.

// Your task is to tell the sum of all the numbers present in the diagonal ‘D’
// and return it.

// Example:
// ‘N’ = 4
// ‘D’ = 3
// Here, the matrix looks like:
// [1, 3, 6, 10]
// [2, 5, 9, 13]
// [4, 8, 12,15]
// [7, 11, 14, 16]

// The Diagonal ‘3’ looks like: [4, 5, 6].
// The sum of all these numbers is ‘15’.
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints:
// 1 <= ‘T’ <= 10
// 1 <= ‘N’ <= 10^5
// 1 <= ‘D’ <= ‘2 * N - 1’

// Time Limit: 1 sec

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
long double PI = acos(-1.0);
#define fastio()                                                               \
    ios_base::sync_with_stdio(false);                                          \
    cin.tie(NULL)
#define pb push_back
#define NL cout << endl;
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define all(x) (x).begin(), (x).end()
#define ff(i, l, r) for (int i = l; i < r; i++)
#define fr first
#define sc second
#define vii vector<vector<int>>
#define vi vector<int>
#define pii pair<int, int>
#define mem1(a) memset(a, -1, sizeof(a))
#define mem0(a) memset(a, 0, sizeof(a))
#define ppc __builtin_popcount
#define ppcll __builtin_popcountll
#define returnYes()                                                            \
    yes();                                                                     \
    return
#define returnNo()                                                             \
    no();                                                                      \
    return

const int MOD = (1e9 + 7);
/*1sec -10^7-10^8 OPS APPROX
int- (-10^-9 to 10^9)RANGE
long (-10^12 to 10^12)RANGE
long long(-10^18 to 10^18)RANGE
(a+b)%M=((a%M)+(b%M))%M
(a*b)%M=((a%M)*(b%M))%M
(a-b)%M=((a%M)-(b%M)+M)%M
(a/b)%M=((a%M)*(b^-1)%M)%M
*/
#ifdef ANURAG
#define debug(x)                                                               \
    cerr << #x << ": ";                                                        \
    _print(x);                                                                 \
    cerr << endl;
#else
#define debug(x) ;
#endif

void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(double t) { cerr << t; }

template <class T, class V> void _print(pair<T, V> p);
template <class T> void _print(vector<T> v);
template <class T> void _print(set<T> v);
template <class T, class V> void _print(map<T, V> v);
template <class T> void _print(multiset<T> v);
template <class T, class V> void _print(pair<T, V> p) {
    cerr << "{";
    _print(p.ff);
    cerr << ",";
    _print(p.ss);
    cerr << "}";
}
template <class T> void _print(vector<T> v) {
    cerr << "[ ";
    for (T i : v) {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T> void _print(set<T> v) {
    cerr << "[ ";
    for (T i : v) {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T> void _print(multiset<T> v) {
    cerr << "[ ";
    for (T i : v) {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V> void _print(map<T, V> v) {
    cerr << "[ ";
    for (auto i : v) {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

void yes() { cout << "Yes" << endl; }
void no() { cout << "No" << endl; }
void read(vector<int> &a) {
    for (int i = 0; i < a.size(); i++) {
        cin >> a[i];
    }
}
void read1(vector<int> &a, int n) {
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}
void read2dn(vii &a) {
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a[0].size(); j++) {
            cin >> a[i][j];
        }
    }
}
void read2dcustom(vii &a, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
}
void print(vector<int> a, int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}
int binpow(int a, int b, int m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

long long diagonalSum(int n, int d) {
    long long a = 1;
    if (d <= n) {
        for (int i = 1; i < d; i++) {
            a += i;
        }
    } else {
        for (int i = 1; i < n; i++) {
            a += i;
        }
    }
    if (d > n) {
        int u = n;
        int x = d - u;

        while (x--) {
            a += u--;
        }
    }
    long long sum = 0;
    if (d > n) {
        int y = d - n;
        for (int i = 0; i < n - y; i++) {
            sum += a;
            a++;
        }
    } else {
        for (int i = 0; i < d; i++) {
            sum += a;
            a++;
        }
    }

    return sum;
}

void solve() {
    int n, d;
    cin >> n >> d;

    cout << diagonalSum(n, d) << endl;
}

signed main() {
    fastio();

#ifdef Anurag5623
    freopen("Error.txt", "w", stderr);
#endif
    int t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }
}