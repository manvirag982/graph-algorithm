/* motivation

  C. Checkposts
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Your city has n junctions. There are m one-way roads between the junctions. As a mayor of the city, you have to ensure the security of all the junctions.

To ensure the security, you have to build some police checkposts. Checkposts can only be built in a junction. A checkpost at junction i can protect junction j if either i = j or the police patrol car can go to j from i and then come back to i.

Building checkposts costs some money. As some areas of the city are more expensive than others, building checkpost at some junctions might cost more money than other junctions.

You have to determine the minimum possible money needed to ensure the security of all the junctions. Also you have to find the number of ways to ensure the security in minimum price and in addition in minimum number of checkposts. Two ways are different if any of the junctions contains a checkpost in one of them and do not contain in the other.

Input
In the first line, you will be given an integer n, number of junctions (1 ≤ n ≤ 105). In the next line, n space-separated integers will be given. The ith integer is the cost of building checkpost at the ith junction (costs will be non-negative and will not exceed 109).

The next line will contain an integer m (0 ≤ m ≤ 3·105). And each of the next m lines contains two integers ui and vi (1 ≤ ui, vi ≤ n; u ≠ v). A pair ui, vi means, that there is a one-way road which goes from ui to vi. There will not be more than one road between two nodes in the same direction.

Output
Print two integers separated by spaces. The first one is the minimum possible money needed to ensure the security of all the junctions. And the second one is the number of ways you can ensure the security modulo 1000000007 (109 + 7).

Examples
inputCopy
3
1 2 3
3
1 2
2 3
3 2
outputCopy
3 1
inputCopy
5
2 8 0 6 0
6
1 4
1 3
2 4
3 4
4 5
5 1
outputCopy
8 2
inputCopy
10
1 3 2 2 1 3 1 4 10 10
12
1 2
2 3
3 1
3 4
4 5
5 6
5 7
6 4
7 3
8 9
9 10
10 9
outputCopy
15 6
inputCopy
2
7 91
2
1 2
2 1
outputCopy
7 1
*/

//  this is only the algorithm not the solution of above question
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
