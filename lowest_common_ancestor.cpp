// lowest common ancester log(n)
// binary lifter
//
// for intuition https://www.youtube.com/watch?v=w56Qe5wEr2I
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
const int MAX =10001;
void pls()
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
}
int n,e,q,clo; // vertices , edges , query,current log
const int lo=(ceil)(log2(MAX));
vector<int> g[MAX];
vector<int> lev(MAX);
int memo[MAX][lo+1];
void dfs(int i,int p){

    memo[i][0]=p;
    for(auto x:g[i]){
        if(x==p) continue;
        lev[x]=lev[i]+1;
        dfs(x,i);
    }

}
int lca(int u,int v){

   if(v>u)
    swap(u,v);
// finding difference in their level
   int d=lev[u]-lev[v];

 // making both level equal logn
   for(int i=clo;(i>=0) && d>0;i--){
    int p=pow(2,i);
    if((lev[u]-p)>=lev[v])
        u=memo[u][i] ,d=d-p;
   }

   // if they equal this is ancestor ( when both u,v in same branch)
  if(u==v)
    return u;

 // find lcs
 for(int i=lo;i>=0;i--){
    if(memo[u][i]!=memo[v][i])  
    u=memo[u][i],v=memo[v][i];

  }  

return memo[u][0];
}
i32 main(){    pls();
 cin>>n>>e>>q;
  clo= (ceil)(log2(n));                     // current log

 for(int i=0,u,v;i<e;i++)
 {
     cin>>u>>v; u--; v--;
     g[u].push_back(v);
     g[v].push_back(u);
 }
 dfs(0,-1);

 // conpleting memo
 for(int i=0;i<n;i++){
    for(int j=1;j<=clo;j++)
    {
        if(i==0 || memo[i][j-1]==-1)
            memo[i][j]=-1;
        else 
            memo[i][j]=memo[memo[i][j-1]][j-1];

    }
 }

//  for(int i=0;i<n;i++)
//     cout<<lev[i]<<" ";
// cout<<endl;


//  for(int i=0;i<n;i++){
//     for(int j=0;j<=clo;j++)
//  cout<<memo[i][j]<<" ";
// cout<<endl;}
  
  while(q--){
    int u,v; cin>>u>>v;
    u--; v--;

    cout<<(lca(u,v)+1)<<endl;

  }


return 0;}
     
// indexing 0
/* input
11 10 5
1 2
1 3
1 4
2 5
3 6
3 7
3 8
4 9
9 10
10 11
5 4
10 11
6 11
7 8
3 9
output
1
10
1
3
1   */
