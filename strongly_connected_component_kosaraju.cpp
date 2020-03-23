// strongly connected component ....kosaraju's algorithm...O(v+e)..
// step 1...prepare stack (its actually topology of SSCs
// step 2.. tranpose the graph....reverse the direction
// step 3.. dfs with stack and coutn SSCs 
// take example try run
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
int n,e;
vector<int> g[MAX];
stack<int> st;
vector<int> visi(MAX);
vector<int>tg[MAX];
int SSCs=0;
void dfs1(int i)
{    visi[i]=1;
  for(auto x:g[i])
    if(visi[x]==0)
      dfs1(x);
    st.push(i);

}
void dfs2(int i)
{ 
    visi[i]=1;
    for(auto x:tg[i])
      if(visi[x]==0)
        dfs2(x);
          
}
int kosaraju(){
     visi.resize(n);
     for(int i=0;i<n;i++) visi[i]=0;

   // for filling stack
     for(int i=0;i<n;i++)
     if(visi[i]==0)
     dfs1(i);

   // reversing the direction of graph
     for(int i=0;i<n;i++)
     for(int j=0;j<g[i].size();j++)
     tg[g[i][j]].pb(i);  


   // empty the visited array
   for(int i=0;i<n;i++) visi[i]=0;

     // finding the ssc
    int i;
    while(!st.empty()){
       i=st.top();
       st.pop();
       if(!visi[i])
       { dfs2(i);
      SSCs++;}
      
    }
      
      return SSCs;
}

i32 main(){    pls();
 
   cin>>n>>e;
   for(int i=0,u,v;i<e;i++){
   cin>>u>>v; u--; v--;
   g[u].pb(v);
   } 

   cout<<kosaraju();

return 0;}
     
/*input
10 12
1 2
2 3
3 4
4 1
3 5
5 6
6 7
7 5
6 8
8 9
9 8
9 10
output
4*/
