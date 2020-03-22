#include<bits/stdc++.h>
using namespace std;
const int MAX=100;
vector<int> g[MAX];
vector<int> visi(MAX);
void dfs(int i)
{
     visi[i]=1;
     for(auto x:g[i])
     if(!visi[x])
     dfs(x);
}
int main(){
 
   int n,q; cin>>n>>q;
   for(int i=0;i<q;i++) 
   {  
        int u,v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
   }

   for(int i=0;i<n;i++)
   if(!visi[i])
   dfs(i);

}