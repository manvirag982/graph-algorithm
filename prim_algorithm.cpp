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
vector<pi> g[MAX];
vector<int> visi(MAX);
multiset<pi> pq;  // <weight,vertice>
int mst=0;
void prim(int i){

    pq.insert({0,i});

    while(!pq.empty()){
      pi temp=*(pq.begin());
      pq.erase(pq.begin());
      int x=temp.s;
      if(visi[x]) continue;
      mst+=temp.f;
      visi[x]=1;
      for(auto j:g[x]){
        if(!visi[j.s])
        {
           pq.insert({j.s,j.f});
        }
      } 

    }
}
i32 main(){    pls();
 cin>>n>>e;
 for(int i=0,u,v,w;i<e;i++){
    cin>>u>>v>>w; u--; v--;
    g[u].pb(mk(v,w));
 }

 for(int i=0;i<n;i++)
  visi[i]=0;

 prim(0);

 cout<<mst;
   

return 0;}
     
