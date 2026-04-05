
// Nahmaduhu Wa Nusallimu 'Ala Rasulihil Habib-il Kareem <3
//Allahumma Inni Aas Aaluka Al-Aafiyah

#include <bits/stdc++.h>
using namespace std ;
#define TJ ios::sync_with_stdio(false);cin.tie(0);
#define ll long long
#define vvl vector<vector<ll>>
#define vl vector<ll>
#define mpl map<ll,ll>
#define pb push_back
#define in(v) for (auto &it : v) cin >> it;
#define out(v) for (auto it : v) cout << it << " "; cout << endl;
#define F first
#define S second
#define fr(i,a,b) for(ll i=a; i<b; i++)
#define al(a) a.begin(), a.end()
#define srt(a) sort(a.begin(),a.end())
#define rsrt(a) sort(a.rbegin(), a.rend());
#define mx(a) max_element(a.begin(),a.end())
#define mn(a) min_element(a.begin(),a.end())
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define nl endl
#define gcd(a,b) __gcd(a,b)
#define INFX LLONG_MAX;
#define INFN LLONG_MIN;
#define Tc ll t; cin>>t; while(t--)
const ll N = 1e6+10;
const ll M = 1e9 + 7;
#define sz 200005
ll arr[sz];
ll tree[sz*4];

void init (ll node, ll b, ll e)
{
    if(b==e)
    {
        tree[node] = arr[b];
        return;
    }
    ll left = node*2;
    ll right = node*2 + 1;
    ll mid = (b+e)/2;
    init(left, b, mid);
    init(right, mid+1, e);
    // change
    tree[node] = min(tree[left], tree[right]);
}

ll query(ll node, ll b, ll e, ll i, ll j)
{
    if(i>e || j<b)
        // return 0;
        return INFX;
    if(b>=i && e<=j)
        return tree[node];
    ll left = node*2;
    ll right = node*2 + 1;
    ll mid = (b+e)/2;
    ll p1 = query(left, b, mid, i, j);
    ll p2 = query(right, mid+1, e, i, j);
    return min(p1, p2);
}

void update(ll node, ll b, ll e, ll i, ll newvalue)
{
    if(i>e || i<b)
        return;
    if(b >= i && e <= i)
    {
        tree[node] = newvalue;
        return;
    }
    ll left = node*2;
    ll right = node*2 + 1;
    ll mid = (b+e)/2;
    update(left, b, mid, i, newvalue);
    update(right, mid+1, e, i, newvalue);
    //changes
    tree[node] = min(tree[left],tree[right]);
}

int main()
{
    TJ
    Tc
    {
        ll n; cin>>n;
        fr(i,1,n+1) cin>>arr[i];
        init(1,1,n);

        // input range
        ll b,e; cin>>b>>e;
        cout<<query(1,1,n,b,e)<<nl;

    }
    return 0;
}
