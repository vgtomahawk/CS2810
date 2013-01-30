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
		void copy(Dlist* dest);
		void print();
		int compare(Dlist* b);
/*1 if b is greater than a return 1 if equal return 0 else return -1*/
        	Dlist* add(Dlist* b);
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
void Dlist::copy(Dlist* dest)
{
	Node* curr=this->head;
	while(curr!=NULL)
	{
		dest->push(curr->data);
		curr=curr->next;
	}
	return;
}
int Dlist::compare(Dlist* b)
{
	int la=this->length();
	int lb=b->length();
	if(la<lb)
	{
		return 1;
	}
	else if(la>lb)
	{
		return -1;
	}
	else
	{
		int first=this->head->data;
		int second=b->head->data;
		if(first>second)
		{
			return -1;
		}
		else if(second<first)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
}
Dlist* Dlist::add(Dlist* b)
{
	Dlist* sum=new Dlist();
	if(this->head==NULL)
	{
		b->copy(sum);
		return sum;
	}
	else if(b->head==NULL)
	{
		 this->copy(sum);
		 return sum;
	}
	else
	{
		Dlist* small;
		Dlist* big;
		int sign=this->compare(b);
		if(sign>0)
		{
			big=b;
			small=this;
		}
		else
		{
			small=b;
			big=this;
		}
		Node* last_big=big->getlast();
		Node* last_small=small->getlast();
		int carry=0;
		int remainder;
		int summation;
		while(last_small!=NULL)
		{
			summation=(last_small->data)+(last_big->data)+carry;
			carry=summation/10000;
			remainder=summation%10000;
			sum->pushback(remainder);
			last_small=last_small->prev;
			last_big=last_big->prev;
		}
		while(last_big!=NULL)
		{
			summation=(last_big->data)+carry;
			carry=summation/10000;
			remainder=summation%10000;
			sum->pushback(remainder);
			last_big=last_big->prev;
		}
		if(carry>0)
		{
			sum->pushback(carry);
		}
		return sum;
	}
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
	Dlist* newlist3;
	newlist3=newlist->add(newlist2);
	newlist3->print();
	return 0;
}
