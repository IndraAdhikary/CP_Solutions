#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // ordered_set pbds
#include <ext/pb_ds/tree_policy.hpp>     // ordered_set pbds
using namespace std;
using namespace __gnu_pbds;

#define boost                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)
#define ll long long
#define ull unsigned long long
#define dd double
#define lld long double
#define mkp make_pair
#define pi pair<ll, ll>
#define pii pair<ll, pi>
#define F first
#define S second
#define fi for (ll i = 0; i < n; i++)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define countsetbit __builtin_popcount
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

#ifndef ONLINE_JUDGE
#define debug(x)       \
    cerr << #x << " "; \
    _print(x);         \
    cerr << "\n";
#else
#define debug(x)
#endif

void _print(ll t)
{
    cerr << t;
}
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(dd t) { cerr << t; }
void _print(ull t) { cerr << t; }

template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p)
{
    cerr << "{";
    _print(p.F);
    cerr << ",";
    _print(p.S);
    cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(set<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

vector<ll> seive(ll x)
{
    vector<ll> prime(x + 1, 0);
    for (int i = 2; i * i <= x; i++)
    {
        if (prime[i] == 0)
        {
            for (int j = i * i; j <= x; j += i)
            {
                prime[j] = 1;
            }
        }
    }
    return prime;
}

int main()
{
    //system("color C");
    boost;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
#endif

    ll tc;
    cin >> tc;
    vector<ll> prime = seive(100000);

    while (tc--)
    {
        ll n;
        cin >> n;
        string s;
        cin >> s;
        ll count = 0;
        string ans = "";

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                count = 1;
                ans = "1";
                break;
            }
            else if (prime[s[i] - '0'])
            {
                count = 1;
                ans = s[i];
                break;
            }
        }
        if (count)
        {
            cout << count << "\n";
            cout << ans << "\n";
            continue;
        }

        // 2 wale
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                string temp;
                temp.push_back(s[i]);
                temp.push_back(s[j]);
                int val = stoi(temp);
                // cout << val << '\n';
                if (prime[val])
                {
                    count = 2;
                    ans = temp;
                    break;
                }
            }
            if (count == 2)
            {
                break;
            }
        }

        if (count == 2)
        {
            cout << count << "\n";
            cout << ans << "\n";
            continue;
        }

        // 3 wale
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    string temp;
                    temp.push_back(s[i]);
                    temp.push_back(s[j]);
                    temp.push_back(s[k]);

                    int val = stoi(temp);
                    // cout << val << '\n';
                    if (prime[val])
                    {
                        count = 3;
                        ans = temp;
                        break;
                    }
                }

                if (count == 3)
                {
                    break;
                }
            }
            if (count == 3)
            {
                break;
            }
        }

        if (count == 3)
        {
            cout << count << "\n";
            cout << ans << "\n";
            continue;
        }
    }

    return 0;
}
