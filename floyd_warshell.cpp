#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define w(x) int x; cin>>x; while(x--)
#define fr(i,n)   for(int i=0;i<n;i++)
#define frr(i,n)  for(int i=1;i<=n;i++)
#define vi vector<int>
#define mod 100000000
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
const int MAX =10000;
void pls()
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
}
inline int madd(int x,int y)
{ 
   return (x%mod +y%mod)%mod;
}
inline int msub(int x,int y)
{
   return (mod+x%mod -y%mod)%mod;
}


#define V 4 
#define INF 99999 

void floydWarshall (int graph[][V]) 
{ 
	int dist[V][V], i, j, k; 

	for (i = 0; i < V; i++) 
		for (j = 0; j < V; j++) 
			dist[i][j] = graph[i][j]; 

	for (k = 0; k < V; k++) 
	{ 
		for (i = 0; i < V; i++) 
		{ 
			for (j = 0; j < V; j++) 
			{ 
				if (dist[i][k] + dist[k][j] < dist[i][j]) 
					dist[i][j] = dist[i][k] + dist[k][j]; 
			} 
		} 
	} 

	printSolution(dist); 
} 

void printSolution(int dist[][V]) 
{ 
	for (int i = 0; i < V; i++) 
	{ 
		for (int j = 0; j < V; j++) 
		{ 
			if (dist[i][j] == INF) 
				cout<<"INF"<<"	 "; 
			else
				cout<<dist[i][j]<<"	 "; 
		} 
		cout<<endl; 
	} 
} 

int main() 
{ pls();
	int graph[V][V] = { {0, 5, INF, 10}, 
						{INF, 0, 3, INF}, 
						{INF, INF, 0, 1}, 
						{INF, INF, INF, 0} 
					}; 

	floydWarshall(graph); 
	return 0; 
} 

