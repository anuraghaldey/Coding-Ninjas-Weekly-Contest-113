// Problem statement
// Given a positive integer 'N' and a string 'S' consisting only of letters ‘D’
// or ‘I’, you have to find the lexicographically smallest permutation of
// positive integers ('0' is excluded) that satisfy the given input string.
// Choose any starting number, and then if the character in the string is ‘D’,
// the next number is smaller, while ‘I’ means the next number is greater.

// An array/list P is lexicographically smaller than its permutation Q if and
// only if, for the earliest index at which P and Q differ, P's element at that
// index is smaller than Q's element at that index.

// Example, P = [1, 12, 4, 7, 8] is lexicographically smaller than Q = [1, 12,
// 8, 4, 7].

// The length of the given string 's' will always be equal to 'N' - 1.

// Example:
// ‘N’ = 3
// ‘S’ = “ID”

// Permutation can be [1, 3, 2]
// No other permutation exists that satisfies the string and is
// lexicographically smaller. Detailed explanation ( Input/output format, Notes,
// Images ) Constraints: 1 <= ‘T’ <= 10 1 <= ‘N’ <= 10^5 |S| = ‘N’-1 and S[i] is
// either ‘I’ or ‘D’

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

bool check(string &s, int mid) {
    int a = mid;

    for (int i = 0; i < s.length(); i++) {

        if (s[i] == 'D') {
            a--;
        } else {
            a++;
        }
        if (a <= 0) {
            return false;
        }
    }
    return true;
}
int bs(string &s, int l, int h, int &ans) {
    if (l > h) {
        return ans;
    }
    int mid = l + (h - l) / 2;

    if (check(s, mid)) {
        ans = mid;
        return bs(s, l, mid - 1, ans);
    }
    return bs(s, mid + 1, h, ans);
}
vector<int> solve1(int n, string &s) {
    int h = n, l = 1;
    int ans = -1;

    ans = bs(s, l, h, ans);
    vector<int> v;
    v.push_back(ans);
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'D') {
            ans--;
        } else {
            ans++;
        }
        v.push_back(ans);
    }
    return v;
}
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vi a = solve1(n, s);
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << endl;
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
