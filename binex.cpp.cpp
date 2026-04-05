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
#define Tc ll t; cin>>t; while(t--)
const ll N = 1e6+10;
const ll M = 1e9 + 7;

ll binex(ll a, ll b, ll md)
{
    ll ans =1;
    while(b)
    {
        if(b&1)
        {
            ans = (a*ans)%md;
        }
        a = (a*a) % md;
        b >>= 1;
    }
    return ans;
}

ll bin_mltply(ll a, ll b)
{
    ll ans = 0;
    while(b)
    {
        if(b&1)
        {
            ans = (ans+a)%M;
        }
        a = (a+a)%M;
        b >>= 1;
    }
}
int main()
{
    TJ
    Tc
    {
        ll a, b, c;
        cin>>a>>b>>c;
        ll n = binex(b,c, M-1);
        ll m = binex(a,n, M);
        cout<<m<<nl;
    }
}

