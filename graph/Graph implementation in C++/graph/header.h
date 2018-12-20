#include<iostream>
using namespace std;

struct node{
	int verticie;
	node* next;
};

class list
{
	node *head,*tail;
public:
	list();
	void addVerticie(int);
	void deleteVerticie(int);
	void print();
	int getSize();
	node * getHead();
};

class graph{
	list *graphList;
	int size;
	void DFS(int, bool visited[] );
public:
	graph(const int);
	void addEdge(int,int);
	void deleteEdge(int,int);
	void print();
	void depthFirstSearch(int start);

};

