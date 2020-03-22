#include<bits/stdc++.h>
using namespace std;

bool m[10][10];
bool noattack(int i, int j ,int n){
  
       
   for(int k=0;k<n;k++){
    if(i==k) continue;
    if(m[k][j])
        return false;}


   for(int k=0;k<j;k++){
    // if(j==k) continue;
    if(m[i][k])
        return false;}
   int r=i-1;
   int c=j-1;
   while(r>=0&&c>=0)
   {   
       if(m[r][c])
        return false;
        r--; c--;
   }
   i=i+1;
   j=j-1;
 
   while(i<n&&j>=0)
   {   
       if(m[i][j])
        return false;

        i++; j--;
   }

   return true;

}
void printy(int n){

   cout<<"[";
    for(int i=0;i<n;i++)
       {   for(int j=0;j<n;j++ )
            {
                 if(m[j][i]==1)
                    cout<<(j+1)<<" ";
            }
           
            
        }

        cout<<"] ";

        // cout<<endl;

}
bool nqueen(int n,int i){

   if(i==n)
   {
        printy(n);
        return false;
   }

   for(int k=0;k<n;k++){
      
      if(noattack(k,i,n)){
        m[k][i]=1;
        if(!nqueen(n,i+1))
        { 
            m[k][i]=0; 
        }
        else
            return true;
      }
   }

   return false;




}
int main(){
    
     int t; cin>>t; while(t--){
     int n; cin>>n;
     memset(m,0,sizeof(m));
     bool b=nqueen(n,0);
    }
  cout<<endl;
  return 0;
}
