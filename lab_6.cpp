# include <bits/stdc++.h>

using namespace std;

int main()
{
  int n;
  cin>>n;
  int q;
  cin>>q;
  int a[n]={0};
  for(int i=0;i<q;i++)
  {
    int c;
    int u;
    int r;
    cin>>c;
    if(c==1)
    {
      cin>>u;
      if(u>=n){
        cout<<"NO data available";
        continue;
      }
      cin>>r;
      if(u<n)
      a[u]+=r;
    }
    if(c==2)
    {
      if(i!=0)
      cout<< (max_element(a,a+n)-a);
      if(i==0)
      cout<<"NO data available";
    }
  }
  return 0;
}
