// div 3 629 codeforces E. Tree Queries
// logic (  lca..)
// since at most one distance is possible
// if we repalace the given range elememnt except root and bottom most element(highest depth) with their parent
// so if they are in one branch from root then lca of bottom element and above will be above 
// for lca   this is famous by finding in out....for proper understanding
// go take given example print in out 
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
#define fastio   ios_base::sync_with_stdio(false);cin.tie(NULL);
const int MAX =200001;
void pls()
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
}
int n,q,temp;
vector<int> g[MAX];
vector<int> in(MAX),out(MAX),p(MAX),d(MAX);
void dfs(int i,int par,int depth=0)
{      
     p[i]=par;
     d[i]=depth;
     in[i]=temp++;
     for(auto x:g[i])
      if(x==par) continue;
      else dfs(x,i,depth+1);

     out[i]=++temp; 

}
bool ancester(int u,int v)
{
   return (in[u]<=in[v] && out[v]<=out[u]);
}
i32 main(){pls();  // time_t start,end;     // time(&start);// time(&end);
   cin>>n>>q;
   for(int i=0,u,v;i<n-1;i++){
    cin>>u>>v;
    u--;v--;
    g[u].push_back(v);
    g[v].push_back(u);
   }
   // calculate d,p,in,out
   dfs(0,-1);

   while(q--){
    // reset
    temp=0;

    int k; cin>>k;
    vector<int> v(k);
    
    for(int i=0;i<k;i++) cin>>v[i],v[i]--;
    
   //finding the bottom most point
    int bm=v[0];
    for(int i=1;i<k;i++)
      if(d[v[i]]>d[bm])
        bm=v[i];

// cout<<bm<<endl;
    // changing vertice to its parent except root and bm
   // for(auto x:v)
    // cout<<x<<" ";
   // cout<<endl;


     for(int i=0;i<k;i++){
      if(v[i]==0 || v[i]==bm) continue;
          v[i]=p[v[i]];
     }

     // for(auto x:v)
      // cout<<x<<" ";
     // cout<<endl;

     // checking for ancester
     bool res=true;

     for(auto x:v)
      res=res & ancester(x,bm); // return true if x is ancester of u 

     if(res) cout<<"YES"<<endl;
     else cout<<"NO"<<endl;

   }


          
  

 //   double time_taken = double(end - start);    // cout << "Time taken by program is : " << fixed  //      << time_taken << setprecision(5); // cout << " sec " << endl; 
 return 0;}
     
