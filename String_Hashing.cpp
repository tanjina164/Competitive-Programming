
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
#define nl "\n"
#define gcd(a,b) __gcd(a,b)
#define Tc ll t; cin>>t; while(t--)
const ll N = 1e6+10;
const ll M = 1e9 + 7;


int main()
{
    TJ
    //Tc
    {
        string s,t; cin>>s>>t;
        ll n = s.size(), m= t.size();
        vl arr(n+5); arr[0] = 0;
        ll prime = 911382323;

        //hashing of s
        for(ll i=0; i<n; i++)
        {
            arr[i+1] = (((arr[i]*prime)%M)+s[i])%M;
        }

        //hashing of t
        ll val = 0;
        for(ll i=0; i<m; i++)
        {
            val = (((val*prime)%M)+t[i])%M;
        }

        // power of prime (prime^m)
        ll powr = 1;
        for(ll i=0; i<m; i++)
        {
            powr = (powr*prime)%M;
        }

        //sliding window
        ll cnt = 0;
        for(ll i=m; i<=n; i++)
        {
            ll x = arr[i];
            ll y = arr[i-m];
            y = (y*powr)%M;
            ll z = x - y;
            if(z<0) z+=M;
            if(z==val) cnt++;
        }
        cout<<cnt<<nl;
    }
    return 0;
}
