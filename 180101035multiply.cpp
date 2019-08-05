# include <bits/stdc++.h>

using namespace std;

void multiplication(string s1,string s2){
    int a[100],b[100];
    int ans[200]={0};
    int i,j,tmp;
    int l1 = s1.length();
    int l2 = s2.length();
    for(i = l1-1,j=0;i>=0;i--,j++)
    {
        a[j] = s1[i]-'0';
    }
    for(i = l2-1,j=0;i>=0;i--,j++)
    {
        b[j] = s2[i]-'0';
    }
    for(i = 0;i < l2;i++)
    {
        for(j = 0;j < l1;j++)
        {
            ans[i+j] += b[i]*a[j];
        }
    }
    for(i = 0;i < l1+l2;i++)
    {
        tmp = ans[i]/10;
        ans[i] = ans[i]%10;
        ans[i+1] = ans[i+1] + tmp;
    }
    for(i = l1+l2; i>= 0;i--)
    {
        if(ans[i] > 0)
            break;
    }
    cout<<"product :";
    for(;i >= 0;i--)
    {
    	cout<<ans[i];
    }

}

int main()
{
	int t;
	cin>>t;
	string str1[t],str2[t];
	for(int i=0;i<t;i++)
	{
		cin>>str1[i];
		cin>>str2[i];
	}
	for(i=0;i<t;i++)
	{
	multiplication(str1[i],str2[i]);
	}
	return 0;
}