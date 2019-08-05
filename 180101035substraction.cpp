# include <bits/stdc++.h>

using namespace std;

 bool issmaller(string str1,string str2){
 	int n1=str1.length(),n2=str2.length();
 	if(n1<n2)
 		return true;
 	if(n2<n1)
 		return false;
 	for(int i=0;i<n1;i++){
 		if(str1[i]<str2[i])
 			return true;
 		else if(str1[i]>str2[i])
 			return false;
 	}
 	return false;
 }

 string substraction(string str1,string str2){
 	int count=0;
 	if(issmaller(str1,str2))
 	{
 		swap(str1,str2);
 		count++;
 	}
 	string str="";
 	int n1=str1.length(),n2=str2.length();
 	reverse(str1.begin(),str1.end());
 	reverse(str2.begin(),str2.end());
 	int carry=0;
 	for(int i=0;i<n2;i++){
 		int sub=((str1[i]-'0')-(str2[i]-'0')-carry);
 		if(sub<0)
 		{
 			sub=sub+10;
 			carry=1;
 		}
 		else
 			carry=0;
 		str.push_back(sub+'0');
 	}
 	for(int i=n2;i<n1;i++){
 		int sub=((str1[i]-'0')-carry);
 		if(sub<0)
 		{
 			sub=sub+10;
 			carry=1;
 		}
 		else
 			carry=0;
 		str.push_back(sub+'0');
 	}
 	reverse(str.begin(),str.end());
 	if(count==1)
 		str.insert(0,'-');
 	return str;
 }

 int main()
 {
 	int t;
 	cin>>t;
 	string a[t],b[t];
 	for(int i=0;i<t;i++){
 		cin>>a[i];
 		cin>>b[i];
 	}
 	for(int i=0;i<t;i++){
 		cout<<substraction(a[i],b[i])<<endl;
 	}
 }