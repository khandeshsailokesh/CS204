#include<bits/stdc++.h> 
using namespace std;

int noofstrline(string expr){
    int count=0;
    for(int i=0;i<expr.length(); i++)
    {
        if(expr[i]=='|')
        count++;
    }
    return count;
}

// function to check if paranthesis are balanced 
bool areParanthesisBalanced(string expr) 
{ 
	stack<char> s; 
	char x;
	int count=noofstrline(expr);
	if(count%2==1)
	return false;
	int t=0;

	// Traversing the Expression 
	for (int i=0; i<expr.length(); i++) 
	{ 
	    if(expr[i]=='|'){
	        t++;
	    }
		if (expr[i]=='('||expr[i]=='['||expr[i]=='{'||expr[i]=='<'||(expr[i]=='|'&&t<=count/2)) 
		{ 
			// Push the element in the stack 
			s.push(expr[i]); 
			continue; 
		}

		// IF current current character is not opening 
		// bracket, then it must be closing. So stack 
		// cannot be empty at this point. 
		if (s.empty()) 
		return false; 

		switch (expr[i]) 
		{ 
		case ')': 

			// Store the top element in a 
			x = s.top(); 
			s.pop(); 
			if (x=='{' || x=='['||x=='|'||x=='<') 
				return false; 
			break; 

		case '}': 
// Store the top element in b 
			x = s.top(); 
			s.pop(); 
			if (x=='(' || x=='['||x=='|'||x=='<') 
				return false; 
			break; 

		case ']': 

			// Store the top element in c 
			x = s.top(); 
			s.pop(); 
			if (x =='(' || x == '{'||x=='|'||x=='<') 
				return false;
				break;
				
	
	    	case '>': 

			// Store the top element in b 
			x = s.top(); 
			s.pop(); 
			if (x=='(' || x=='['||x == '{'||x=='|') 
				return false; 
			break;  
				case '|': 

			// Store the top element in b 
			x = s.top(); 
			s.pop(); 
			if (x=='(' || x=='['||x == '{'||x=='<') 
				return false; 
			break;  
	
		} 
	} 

	// Check Empty Stack 
	return (s.empty()); 
} 

// Driver program to test above function 
int main() 
{
	int t;
	cin>>t; 
	string expr[t];
	for(int j=0;j<t;j++)
	{
	    cin>>expr[j];
	}
	for(int i=0;i<t;i++)
{
	if (areParanthesisBalanced(expr[i])) 
		cout << "YES"; 
	else
		cout << "NO"; 
}
	return 0; 
} 
