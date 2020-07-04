#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int mxN =150000;
void kahn_algorithm()
{
    vector<int> top;
	// for this question assuming that graph is DAG it doesnot contain cycle
	queue<int> q;
	for(int i=0;i<n;i++) if(in[i]==0)q.push(i);
	while(!q.empty()){
		int node=q.front(); q.pop();
		topo.push_back(node+1);
		for(auto v:g[node]){
			in[v]--;
			if(in[v]==0)
			q.push(v);
		}
	}
	for(auto x: topo)
	cout<<x<<" ";
	cout<<endl;	 
}
int32_t main(){
  ios_base::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
 		
    int n,m; cin>>n>>m;
	vector<int> in(n); // indegree
	for(int i=0,u,v;i<m;i++){cin>>u>>v; u--; v--;
	g[u].push_back(v);
	in[v]++;
	}     
	kahn_algorithm(in,n,m);
return 0;}

