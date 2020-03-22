#include<bits/stdc++.h>
using namespace std;
const int MAX=100;
vector<int> g[MAX];
vector<bool> visi(MAX);
void bfs(int s){
    queue<int> q;
     q.push(s);
     visi[s]=1;
   while(!q.empty()){
     int temp=q.front();
     cout<<temp<<" ";
     q.pop(); 
    for(auto x:g[s])
    {
           if(!visi[x])
           {
                q.push(x);
                visi[x]=1;
           }
          
    }
   }
}
int main()
{    
     int n,q; cin>>n>>q;
     for(int i=0;i<q;i++)
     {
          int u,v; cin>>u>>v;
          g[u].push_back(v);
          g[v].push_back(u);
     }
     
     for(int i=0;i<n;i++){
          if(!visi[i])
          bfs(i);
     }

}