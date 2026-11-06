
// Nahmaduhu Wa Nusallimu 'Ala Rasulihil Habib-il Kareem <3
//Allahumma Inni Aas Aaluka Al-Aafiyah

#include <bits/stdc++.h>
using namespace std ;
#define TJ ios::sync_with_stdio(false);cin.tie(0);
#define ll long long
#define ull unsigned long long
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
const ull M1 = 1000000007ULL, M2 = 998244353ULL;
const ull pr1 = 911382323ULL%M1, pr2 = 972663749ULL%M2;

int main()
{
    TJ
    //Tc
    {
        string s,t; cin>>s>>t;
        ll n = s.size(), m= t.size();
        vector<ull> ar1(n+1,0), ar2(n+1, 0);
        vector<ull> pw1(n+1,1), pw2(n+1,1);



        //hashing of s
        for(ll i=0; i<n; i++)
        {
            ar1[i+1] = (((ar1[i]*pr1)%M1)+s[i])%M1;
            ar2[i+1] = (((ar2[i]*pr2)%M2)+s[i])%M2;

            //power calculation
            pw1[i+1] = (pw1[i]*pr1)%M1;
            pw2[i+1] = (pw2[i]*pr2)%M2;
        }

        //hashing of t
        ll val1 = 0, val2=0;
        for(ll i=0; i<m; i++)
        {
            val1 = (((val1*pr1)%M1)+t[i])%M1;
            val2 = (((val2*pr2)%M2)+t[i])%M2;
        }

        // power of prime (prime^m)
        ll powr1 = pw1[m], powr2 = pw2[m];



        //sliding window
        ll cnt = 0;
        for(ll i=m; i<=n; i++)
        {
            ull x1 = (ar1[i]+M1 - (ar1[i-m]*powr1)%M1)%M1;
            ull x2 = (ar2[i]+M2 - (ar2[i-m]*powr2)%M2)%M2;

            if(x1==val1 && x2==val2) cnt++;
        }
        cout<<cnt<<nl;
    }
    return 0;
}
