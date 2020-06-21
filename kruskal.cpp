#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int mxN =100001;
#define ppi pair<int ,pair<int,int>>
vector<ppi> edges;
int parent[mxN];
int root(int x)
{
	  while(parent[x]!=x)
	  x=parent[x];
	  return x;
	
}
void Union(int u,int v)
{
	 int parentu=root(u);
	 int parentv=root(v);
	 
	 parent[parentu]=parentv;
}
int kruskal()
{
	 int mstcost=0;
	 for(int i=0;i<edges.size();i++)
	 {
	 	 int u=edges[i].second.first;
	 	 int v=edges[i].second.second;
	 	 int w=edges[i].first;
	 	 
	 	 if(root(u)!=root(v)) // if already not connected
	 	 {
	 	      	mstcost+=w;
	 	      	Union(u,v);
		 }
	 }
	 return mstcost;
}
int32_t main(){
  ios_base::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);

     for(int i=1;i<mxN;i++)
     parent[i]=i;
     // logic find the minimum weight edges connect by disjoint sets do  untill all attach
     int n,e; cin>>n>>e; // number of notes , number of edges
	 for(int i=0;i<e;i++)
	 {
	 	 int u,v,w; cin>>u>>v>>w;
	 	 edges.push_back({w,{u,v}});
	 }
	 sort(edges.begin(),edges.end());
	 cout<<kruskal()<<endl;
	 
      



 return 0;}

