// Problem statement
// You are given an '0' indexed array 'A' of 'N' integers containing positive
// and negative integers.

// You want the sum of some subarray of the array 'A' to be maximum. For that,
// you can rearrange the elements of the array. Note that an empty subarray is
// considered to be a subarray with sum equal to '0'.

// Return the maximum possible subarray sum after rearranging the elements of
// the array 'A'.

// Example:
// N = 5
// A = [1, -5, 1, 1, -4]
// We can rearrange the elements as follows: ['1', '1', '1', '-4', '-5']. The
// maximum subarray sum is '3' for the subarray of the first three elements. It
// can be proved that we can not get the subarray sum greater than '3'. So the
// answer for this case is '3'. Detailed explanation ( Input/output format,
// Notes, Images ) Constraints: 1 <= 'N' <= 10^5 -10^3 <= 'A[i]' <= 10^3

// Time limit: 1 sec

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
#ifdef JAI PARSHURAM🙏
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

int maximumSubarraySum(int n, vector<int> &a) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > 0) {
            sum += a[i];
        }
    }
    return sum;
}
void solve() {
    int n;
    cin >> n;

    vi a(n);
    read1(a, n);
    cout << maximumSubarraySum(n, a) << endl;
}

signed main() {
    fastio();

#ifdef JAI PARSHURAM🙏
    freopen("Error.txt", "w", stderr);
#endif
    int t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }
}
