// 771A Bears and friendship condition ..codeforces
/*Bear Limak explores the social network. Its main functionality is that two users can become friends (in this case, they can exchange messages and funny pictures).

There are n users in the social network , they are numbered from 1 to n . Exactly m pairs of them are friends. Sure. no user can be a friend with himself.

Let the entry AB mean that users A and B are friends. Limak believes that a social network is justified if and only if the following condition is fulfilled: for any three different users ( X , Y , Z ) if XY and YZ , then also XZ .

For example, if Alan and Bob are friends, and Bob and Cyri are friends, then Alan and Cyri should also be friends.

Can you help Limak and check that the social network is justified? Print " YES " or " NO " without quotes according to the result.

Input data
The first line contains two integers n and m ( 3 ≤  n  ≤ 150 000 , ) - the number of network users and the number of user pairs that are friends.

The i- th of the following m lines contains two different integers a i and b i ( 1 ≤  a i ,  b i  ≤  n ,  a i  ≠  b i ), meaning that the a i- th and b i- th users are friends . All pairs of friends are different.

Output
If this social network is justified, print in a single line " YES " (without quotes).

Otherwise, print “ NO ” (without quotes) in a single line .

Examples
input dataCopy
4 3 
1 3 
3 4 
1 4
outputCopy
Yes
input dataCopy
4 4 
3 1 
2 3 
3 4 
1 2
outputCopy
NO
input dataCopy
10 4 
4 3 
5 10 
8 9 
1 2
outputCopy
Yes
input dataCopy
3 2 
1 2 
2 3
outputCopy
NO*/


//each connected component is a clique, you can run dfs and count vertices and edges in the connected component — it's a clique if and only if edge=vertice*(vertice-1)/2

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
int n,e;
vector<int> g[MAX];
vector<int> visi(MAX);
void dfs(int i,int &ce,int &cv){
   visi[i]=1;
   cv+=1;
   ce+=g[i].size();
   for(auto x: g[i])
    if(!visi[x])
      dfs(x,ce,cv);
}
i32 main(){pls();
   cin>>n>>e;
   for(int i=0,u,v;i<e;i++){
    cin>>u>>v;
    g[u].push_back(v);
    g[v].push_back(u);
   }

  int cnt_ver=0;
  int cnt_edg=0;
   bool ok=true;
   for(int i=1;i<=n;i++){
     
    if(visi[i]==0){
      cnt_ver=0,cnt_edg=0;
      dfs(i,cnt_edg,cnt_ver);
      if(cnt_edg!=cnt_ver * (cnt_ver-1))
      {  ok=false;
        cout<<"NO"<<endl;
        break;

      }
    }
   }
   if(ok)
    cout<<"YES"<<endl;

  return 0;}
     
