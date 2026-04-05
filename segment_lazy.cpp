
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


struct info
{
    ll prop, sum; //sum ছাড়াও নিচে অতিরিক্ত কত যোগ হচ্ছে সেটা রাখবো prop এ
} tree[sz*4];


// ------------------- Update Function -------------------
void update(ll node, ll b, ll e, ll i, ll j, ll x)
{
    if (i > e || j < b)
        return;
    if (b >= i && e <= j) //নোডের রেঞ্জ আপডেটের রেঞ্জের ভিতরে
    {
        tree[node].sum += ((e - b + 1) * x); //নিচে নোড আছে e-b+1 টি, তাই e-b+1 বার x যোগ হবে এই রেঞ্জে
        tree[node].prop += x; //নিচের নোডগুলোর সাথে x যোগ হবে
        return;
    }
    int Left = node << 1;
    int Right = (node << 1) + 1;
    int mid = (b + e) >> 1;
    update(Left, b, mid, i, j, x);
    update(Right, mid + 1, e, i, j, x);
    tree[node].sum = tree[Left].sum + tree[Right].sum + (e - b + 1) * tree[node].prop;
    //উপরে উঠার সময় পথের নোডগুলো আপডেট হবে
    //বাম আর ডান পাশের সাম ছাড়াও যোগ হবে নিচে অতিরিক্ত যোগ হওয়া মান
}


// ------------------- Query Function -------------------
ll query(ll node, ll b, ll e, ll i, ll j, ll carry = 0)
{
    if (i > e || j < b)
        return 0;

    if (b >= i and e <= j)
        return tree[node].sum + carry * (e - b + 1); //সাম এর সাথে যোগ হবে সেই রেঞ্জের সাথে অতিরিক্ত যত যোগ করতে বলেছে সেটা

    ll Left = node << 1;
    ll Right = (node << 1) + 1;
    ll mid = (b + e) >> 1;

    ll p1 = query(Left, b, mid, i, j, carry + tree[node].prop); //প্রপাগেট ভ্যালু বয়ে নিয়ে যাচ্ছে carry ভ্যারিয়েবল
    ll p2 = query(Right, mid + 1, e, i, j, carry + tree[node].prop);

    return p1 + p2;
}

// ------------------- Build Function -------------------
void init(ll node, ll b, ll e) {
    if (b == e) {
        tree[node].sum = arr[b];
        tree[node].prop = 0;
        return;
    }
    ll Left = node << 1;
    ll Right = (node << 1) + 1;
    ll mid = (b + e) >> 1;

    init(Left, b, mid);
    init(Right, mid + 1, e);

    tree[node].sum = tree[Left].sum + tree[Right].sum;
    tree[node].prop = 0; // lazy initialize
}


int main()
{
    TJ
    //Tc
    {
        ll n,q; cin>>n>>q;
        fr(i,1,n+1) cin>>arr[i];
        init(1,1,n);

        // input range
        ll b,e; cin>>b>>e;
        cout<<query(1,1,n,b,e)<<nl;

    }
    return 0;
}

