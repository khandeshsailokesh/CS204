# include <bits/stdc++.h>

using namespace std;

class node 
{
    public:
	int x;
	int y;
	node * next;
};

void AddFirst(int a,int b,node ** head);
node * DelFirst(node * head);
void Del(int a,int b,node ** head);
void Search(float d,node * head);
bool Search(int a,int b,node * head);
int length(node * head);

void AddFirst(int a,int b,node ** head){
	node * new_node=(class node*) malloc(sizeof(class node));
	new_node->x=a;
	new_node->y=b;
	new_node->next=*head;
	*head=new_node;
}

node * DelFirst(node * head){
	if(head==NULL)
		return NULL;
	node * temp=head;
	head=head->next;
	delete temp;
	return head;
}

void Del(int a,int b,node ** head){
	node * temp=*head,*prev;
	if (temp != NULL && temp->x == a && temp->y == b) 
    { 
        *head= temp->next;   
        free(temp);               
        return; 
    } 
    while (temp != NULL && (temp->x == a && temp->y == b)) 
    { 
        prev = temp; 
        temp = temp->next; 
    } 
     if (temp == NULL) return; 
     prev->next = temp->next; 
  
    free(temp);  
}

void Search(float d,node * head){
	node * temp= (class node*) malloc(sizeof(class node));
	temp=head;
	if(temp->next == NULL)
	{
		if(d-(sqrt((temp->x)^2+(temp->y)^2)) >= 0)	
		{
			cout<<temp->x<<temp->y<<endl;
		}
	}
	if (temp == NULL) return;
	while(temp->next != NULL){
		if(d-(sqrt((temp->x)^2+(temp->y)^2)) >= 0)
		{
			cout<<temp->x<< temp->y<<endl;
		}
		temp=temp->next;
	}
}

bool Search(int a,int b,node * head){
	 node* current = (class node*) malloc(sizeof(class node));
	 current=head;   
    while (current != NULL)  
    {  
        if (current->x == a && current->y == b)  
            return true;  
        current = current->next;  
    }  
    return false;
}

int length(node * head){
	int count=0;
	node * temp=(class node*) malloc(sizeof(class node));
	temp=head;
	if(temp == NULL)return 0;
	if(temp->next == NULL)
		return 1;
	while(temp->next != NULL)
	{
		count++;
		temp=temp->next;
	}
	return count;
}

int main()
{
	class node * head;
	class node * one=NULL;
	one = (class node*) malloc(sizeof(class node));
	head=one;
        int t;
        cin>>t;
        int a[t],b[t],c[t];
        for(int i=0;i<t;i++)
{
        cin>>a[i];
	switch(a[i]){
		case 1: cin>>b[i];
		        cin>>c[i];
		        AddFirst(b[i],c[i],&head);
		        break;
                case 2: head=DelFirst(head);
                        break;
                case 3: cin>>b[i];
		        cin>>c[i];
                        Del(b[i],c[i],&head);
                        break;
                case 4: float d;
                        cin>>d;
                        Search(d,head);
                        break;
                case 5: cin>>b[i];
		        cin>>c[i];
                        cout<<Search(b[i],c[i],head);
                        break;
                case 6: cout<<length(head);
                        break;                                 
	}
}
return 0;
}
