#include<bits/stdc++.h>
using namespace std;
void dfs(vector<int> g[],bool visi[], stack<int> &st ,int i){


    visi[i]=true;

    int count=0;

    for(int j=0;j<g[i].size();j++){
        if(!visi[g[i][j]]){
            // count++;
            dfs(g,visi,st,g[i][j]);
        }
    }

    // if(count==0)
        st.push(i);
}
int main(){

   
      vector<int> g[6];
      g[2]={3};
      g[3]={1};
      g[4]={0,1};
      g[5]={2,0};

      bool visi[6];
      memset(visi,0,sizeof(visi));
      stack<int> st;
      for(int i=0;i<6;i++){
        if(visi[i]==false)
            dfs(g,visi,st,i);
      }

      while(!st.empty()){
          cout<<st.top()<<" ";
          st.pop();
      }
      cout<<endl;
       return 0;

}