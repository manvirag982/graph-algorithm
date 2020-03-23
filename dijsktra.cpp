// dijkstra
// no negative weight 
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define fr(i,n)   for(int i=0;i<n;i++)
#define frr(i,n)  for(int i=1;i<=n;i++)
#define w(x) int x; cin>>x; while(x--)
#define vi vector<int>
#define mod 1000000007
#define fi first 
#define se second
#define pb push_back
#define mk make_pair
#define i32 int32_t
#define i16 int16_t 
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()
const int N=1e5+100;
vector<int> a[N];

int32_t main(){
  
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      
      int n=9;
      vector<pii> g[n]; // graph with weight

      g[0]={{1,4},{7,8}};
      g[1]={{0,4},{7,11},{2,8}};
      g[7]={{1,11},{0,8},{8,7},{6,1}};
      g[2]={{1,8},{3,7},{8,2},{5,4}};
      g[3]={{2,7},{4,9},{5,14}};
      g[4]={{3,9},{5,10}};
      g[5]={{2,4},{3,14},{4,10},{6,2}};
      g[6]={{5,2},{7,1},{8,6}};
      g[8]={{2,2},{6,6},{7,7}};

      int dis[n];   // distance for each vertices
      
      for(int i=0;i<n;i++)
        dis[i]=INT_MAX;

      dis[0]=0;

      priority_queue< pii ,vector<pii> , greater<pii> > pd;  // min-----max (opposite to priority queue)

      pair<int ,int> t;
      pd.push(mk(0,0));

      // algorithm
      //step 1...fill distance with inf....except o vertice
      //step 2.. push firsh vectice int priority queue ,, make it dis=0;
      //step 3.. remember priority queue is a/c to distance and min....max(like set)
     // step 4.. if distance of u + weight < distance v ...then update
      while(!pd.empty()){

        t=pd.top();
        pd.pop();
        for(int i=0;i<g[t.se].size();i++)
        {
              int u=t.se;
              int v=g[u][i].fi;
             if(dis[u]+g[u][i].se < dis[v]){

              dis[v]=dis[u]+g[u][i].se;

              pd.push(mk(dis[v],v));
             }
        }


      }

      fr(i,n) cout<<i<<"="<<dis[i]<<endl;
       return 0;}