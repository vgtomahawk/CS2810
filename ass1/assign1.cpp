#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
class Node
{
	public:
		int data;
		Node* prev;
		Node* next;
		Node();
		Node(int a);
		Node(int a,Node* prev,Node* next);
};
Node::Node(int a)
{
	this->data=a;
	this->prev=NULL;
	this->next=NULL;
}
Node::Node()
{
	this->data=0;
	this->prev=this->next=NULL;
}
Node::Node(int a,Node* prev,Node* next)
{
	this->data=a;
	this->prev=prev;
	this->next=next;
}
class Dlist
{
	public:
		Node* head;
		Dlist(){head=NULL;};
		int length();
		void push(int a);
		void pushback(int a);
		int pop();
		int popback();
		Node* getlast();
		void print();
        void add(Dlist* list2,Dlist* list3);
};
Node* Dlist::getlast()
{
	
	Node* curr=this->head;
	while(curr->next!=NULL)
	{
		curr=curr->next;
	}
	return curr;
}
void Dlist::push(int a)
{
	
	Node* newnode=new Node(a);
	if(this->head==NULL)
	{
		this->head=newnode;
		newnode->prev=newnode->next=NULL;
		return;
	}
	
	else
	{
		Node* last=this->head;
		while(last->next!=NULL)
		{
			last=last->next;
		}
		newnode->prev=last;
		last->next=newnode;
		newnode->next=NULL;
	}
}
void Dlist::pushback(int a)
{
	if(this->head==NULL)
	{
		this->push(a);
	}
	else
	{
	//	cout<<"pback"<<endl;
		Node* newnode=new Node(a);
		newnode->next=this->head;
		this->head->prev=newnode;
		this->head=newnode;
		newnode->prev=NULL;
	}
}
void Dlist::print()
{
	Node* curr=this->head;
	while(curr!=NULL)
	{
		cout<<curr->data<<endl;
		curr=curr->next;
	}
	return;
	
}
int Dlist::length()
{
    Node* curr=this->head;
    int l=0;
    while(curr!=NULL)
    {
        l++;
        curr=curr->next;
    }
    return l;
}
void Dlist::add(Dlist* list2,Dlist* list3)
{
    if(this->head==NULL)
    {
        list3->copy(list2);
        return;
    }
    else if(list2->head==NULL)
    {
        list3->copy(this);
    }
    else
    {
        int l=this->length();
        int m=list2->length();
        if(l>=m)
        {
            /*add l+m empty nodes to list2*/
            int i=0;
            for(i=0;i<l-m;i++)
            {
                list2->pushback(0);
            }
            /*now both have length l*/
            int last_1=
void makelist(Dlist* newlist,string str)
{
	int l=str.length();
    int dump=0;
    string sub;
	while(l>=4)
	{
        sub=str.substr(l-4,4);
		dump=atoi(sub.c_str());
        newlist->pushback(dump);
		l-=4;
	}
    if(l%4!=0)
    {
	    dump=atoi((str.substr(0,l%4)).c_str());
        newlist->pushback(dump);
    }
    return;
}

int main()
{
	Dlist* newlist=new Dlist();
    Dlist* newlist2=new Dlist();
	string str;
	cin>>str;
    makelist(newlist,str);
    cin>>str;
    makelist(newlist2,str);
    newlist->print();
    newlist2->print();
    cout<<newlist->length();
    Dlist* newlist3=new Dlist();
    newlist->add(newlist2,newlist3);
    newlist3->print();	
	return 0;
}
