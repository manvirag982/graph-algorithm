// shortest path on DAG O(v+e)
// for intuition visit gfg  https://www.geeksforgeeks.org/shortest-path-for-directed-acyclic-graphs/
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
const int MAX =1000001;
void pls()
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
}
int n,e,source;
vector<pi> g[MAX];
stack<int> st;
vector<int> dis(MAX),visi(MAX);
void topo(int i){
	
	visi[i]=1;
	
	for(int j=0;j<g[i].size();j++)
	{
		pi x=g[i][j] ;
		int u=x.f;
		int w=x.s;
	
		if(!visi[u])
			topo(u);
	}
		
    st.push(i);

    // cout<<i<<" ";
}
void sssp(){
	
	while(!st.empty()){

		int i=st.top();
		st.pop();
          if(dis[i]!=INT64_MAX){
		for(auto x:g[i]){
			if(dis[x.f]>dis[i]+x.s)
				dis[x.f]=dis[i]+x.s;
		}
	   }
	}

}
i32 main(){pls();
   // time_t start,end;     // time(&start);// time(&end);
     cin>>n>>e>>source;
     for(int i=0,u,v,w;i<e;i++){
       cin>>u>>v>>w;
       g[u].pb(mk(v,w));
     }
     
     
     for(int i=0;i<n;i++){
     	dis[i]=INT64_MAX;}

     	dis[source]=0;
     // visi =0
     for(int i=0;i<n;i++) visi[i]=0;

     // topological order
     for(int i=0;i<n;i++)
     	if(!visi[i])
     		topo(i);

     // sssp
     for(int i=0;i<n;i++) visi[i]=0;
     int i;
       while(!st.empty()){
     	
        i=st.top();
        st.pop(); 
     	if(visi[i]==0)
     		sssp();
      }
       
       for(int i=0;i<n;i++)
       	cout<<dis[i]<<" ";
   //   double time_taken = double(end - start);    // cout << "Time taken by program is : " << fixed  //      << time_taken << setprecision(5); // cout << " sec " << endl; 
return 0;}
/*
input     
  6 9 1
0 1 5 
0 2 3 
1 3 6 
1 2 2 
2 4 4 
2 5 2 
2 3 7 
3 4 -1 
4 5 -2 
output
9223372036854775807 0 2 6 5 3 */
