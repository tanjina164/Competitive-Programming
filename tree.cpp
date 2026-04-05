
// Nahmaduhu Wa Nusallimu 'Ala Rasulihil Habib-il Kareem <3

#include <bits/stdc++.h>
using namespace std ;
#define tj ios::sync_with_stdio(false);cin.tie(0);
#define ll long long
#define vl vector<ll>
#define fr(i,a,b) for(ll i=a;i<=b;i++)
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define nl  cout<<endl;
#define tc ll t; cin>>t; while(t--)
const ll N = 1e5;


vl tree[100];
int depth[100];
int height[N];
void dfs(int ver, int par)
{
    for(auto child : ver)
    {
        depth[child] = depth[ver] + 1;
        if(child==par) continue;
        dfs(child, ver);
        //height[ver] = max(height[ver], height[child]+1);
    }
}


vector<ll> v[N];
ll tree(ll ver, ll par, ll ans)
{
   for(auto child : v[ver])
   {
       if(child == par) continue;

       ans++;
       tree(child, ver, ans);
   }
   return ans;
}

int main()
{
    tj
    tc
    {
        ll n;
        cin>>n;

        ll nd ; cin>>nd;

        while(nd--)
        {
           ll a1, a2;
           cin>>a1>>a2;
           v[a1].push_back(a2);
           v[a2].push_back(a1);
        }

        ll cnt = tree(1,0,0);
        cout<<cnt<<nl;
    }
}
