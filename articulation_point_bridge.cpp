// find the articulation point and bridge O(m+n)
//  input  
/*9 10
0 1
0 2
1 2
2 5
2 3
3 4
5 8
5 6
6 7
7 8*/
// output
//   
//  
/*2 3 4 5 
2 5 3 4 2 3 */
//
//
//
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define w(x) int x; cin>>x; while(x--)
#define fr(i,n)   for(int i=0;i<n;i++)
#define frr(i,n)  for(int i=1;i<=n;i++)
#define vi vector<int>
#define mod 1000000007
#define pi pair<int,int>
#define f first
#define s second
#define pb push_back
#define mk make_pair
#define all(x) x.begin(),x.end() 
#define i32 int32_t
#define i16 int16_t
#define endl "\n"
#define fastio   ios_base::sync _with_stdio(false);cin.tie(NULL);
const int MAX =100001;
void pls()
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
}
// O(v+e)
int id=-1;
vector<int> g[MAX];
vector<int> visi(MAX),low(MAX),ids(MAX);
vector<pi> bridge;
set<int>ap;
void dfs(int i,int p){
  visi[i]=1;
  ++id;
  low[i]=id;
  ids[i]=id;
  
  for(auto x: g[i]){
  
   if(p==x)
    continue;

    if(!visi[x])
     {  dfs(x,i);
        low[i]=min(low[i],low[x]);
       if(low[x]>ids[i])            
       {     
           ap.insert(i);
           ap.insert(x);
          bridge.pb({i,x});
        }
    }
    else
      low[i]=min(low[i],ids[x]);   
   }

}
i32 main(){pls();
   int n; cin>>n;
   int e; cin>>e;
   for(int i=0,u,v;i<e;i++)
   {
     cin>>u>>v;
     g[u].pb(v);
     g[v].pb(u);
   }

   // for(int i=0;i<n;i++)
   //  {for(int j=0;j<g[i].size();j++)
   //    cout<<g[i][j]<<" ";
   //    cout<<endl;}

 visi.resize(n);
  low.resize(n);
  ids.resize(n);

  for(int i=0;i<n;i++)
    visi[i]=0;

 for(int i=0;i<n;i++)
  if(visi[i]==0)
    dfs(i,-1);
 cout<<endl;
for(auto x: ap)
  cout<<x<<" ";
cout<<endl;
for(int i=0;i<bridge.size();i++)
cout<<bridge[i].f<<" "<<bridge[i].s<<" ";
cout<<endl;
return 0;}
     
