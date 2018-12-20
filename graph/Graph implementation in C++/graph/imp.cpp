#include"header.h"

list::list()
{
	head=tail=NULL;
}
void list::addVerticie(int v){

	for( node* c=head ; c!=NULL ;c=c->next) // each nide once
		if(c->verticie == v )
			return;

		node *temp=new node;
		temp->next=NULL;
		temp->verticie = v;
		if (head == NULL)
		{
			head=tail=temp;
		}
		else 
		{
			tail->next = temp;
			tail=temp;
		}
	}
void list::print(){
 node*c=head;
 for(;c!=NULL;c=c->next)
 {
	 cout<<c->verticie<<",";
 }

}
void list::deleteVerticie(int v){
	    node *c=head,*c2;
	if(head!=NULL)
	{
		if( head->verticie == v)
			head=head->next;
		else
		{
			for( c2=head->next ; c!=tail ; c=c2 , c2=c2->next)
			{
				if(c2->verticie == v)
				{
					c->next = c2->next;
					c=c2;
					break;
				}
			}
		}
		delete c;
}
	}

graph::graph(const int v )
{
	graphList = new list[v];
	size =v;
}

void graph::addEdge(int from , int to )
{
	graphList[from].addVerticie(to);
}

void graph::deleteEdge(int from,int to)
{
	graphList[from].deleteVerticie(to);
}
void graph::print()
{
	for(int x=0 ; x<size ; x++)
	{
		cout<<x<<"is connected to ";
		graphList[x].print();
		cout<<endl;
	}
}
int list::getSize()
{
	int count =0;
	for( node*c = head ; c!=NULL ; c=c->next)
		count++;
	return count;
}

node* list::getHead(){

	return head;
}

void graph::depthFirstSearch(int start) // helper
{
	bool *visited = new bool[size];
	for( int i = 0 ; i < size ; i++)
		visited[i]=false;

	DFS( start , visited );
}

void graph::DFS(int start, bool visited[])
{
	visited[start]=true;
	cout<<start<<" ";
	for( node*i=graphList[start].getHead() ; i!=NULL  ; i=i->next)
	{
		
		if(!visited[i->verticie])
		DFS( i->verticie , visited );
	}

}