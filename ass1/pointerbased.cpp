#include <iostream>
using namespace std;
#define ENDL -1
/*Authors : Gangal Varun,A.Raghavendra Kiran */
/*Adt defining a single node*//*Later modify the definition to any arbit DT*/
/*In order to make the flow of control clearer we have used return; in void functions*/
class Elem
{
    public:
        int val;
        Elem* next;
        Elem(){val=0;next=NULL;}
        Elem(int,Elem*);
        Elem(int);
};
Elem::Elem(int a,Elem* next_elem)
{
    this->val=a;
    this->next=next_elem;
}
Elem::Elem(int a)
{
    this->val=a;
    this->next=NULL;
}
class List
{
    public:
/*All functions are supposed to update the values of root as well as end_l*/
        Elem* root;
        Elem* end_l;
        List(){root=NULL;end_l=NULL;}
        List(List*);
        int length();
        void push(int a);/*Stack-like push function*/
        void push(int a,char c);/*-s for stack,-q for queue.Default Behaviour->stack*/
        int pop();/*Stack-like pop function*/
        int pop(char c);/*set flag='r' for reverse pop*/
        Elem* search(int x)/*Returns pointer-type position of x or NULL if not found*/
        Elem* search(int x,int occ)/*Returns pointer-position of occurence number <occ>(0-indexed) or NULL*/
        void print();
//        void print(string flag);
//        List(List l);
};
List::List(List* l)
{
    this->root=l->root;
    this->end_l=l->end_l;
}
/*This function goes on dereferencing the root pointer till it encounters null.This could also have been implemented using end_l*/
/*Will it be better to store the length and keep on updating it?This traversal may turn very expensive*/
int List::length()
{
    int l=0;/*Initialize length*/
    Elem* curr=this->root;
    while(curr!=NULL)
     {
         l++;
         curr=curr->next;
     }
     return l;
}
/*Issue:Should the newelem pointer be freed after the elem is inserted*/
void List::push(int a)
{
    /*First make an Elem*/
    Elem* newelem=new Elem(a);
    int l=this->length();
    if(l==0)
    {
        this->root=newelem;
        newelem->next=NULL;
        this->end_l=newelem;
        return;
    }
    else if(l==1)
    {
        (this->end_l)->next=newelem;
        newelem->next=NULL;
        this->end_l=newelem;
    }
    else if(l>1)
    {
        ((this->end_l)->next)=newelem;
        newelem->next=NULL;
        this->end_l=newelem;
        return;
    }
}
void List::push(int a,char c)
{
    if(c=='q')
    {
        int l=this->length();
        if(l==0)
        {
            this->push(a);/*No distinction between stack and queue when l=0*/
            return;
        }
        else
        {
            Elem* newelem=new Elem(a);
            newelem->next=this->root;
            this->root=newelem;
            return;
        }
    }
    else
    {
        this->push(a);
        return;
    }
}
/*In case there is nothing to pop(l=0) maybe throw some error*/
int List::pop()
{
        int l=this->length();
        int last;
        if(l==1)
        {
            Elem* curr=this->root;
            this->root=NULL;
            this->end_l=NULL;
            last=curr->val;
            delete curr;
            curr=NULL;
            return last;
        }
        else/*At l==0,this will cause seg faults*/
        {
            Elem* curr=this->root;
            while(((curr->next)->next)!=NULL)
            {
                curr=curr->next;
            }
            last=(this->end_l)->val;
            delete(this->end_l);
            this->end_l=curr;
            curr->next=NULL;
            
            
            return last;
        }
}
int List::pop(char c)
{
    int l=this->length();
    int last;
    if(c=='r')
    {
        if(l==1)
        {
            
            return this->pop();
        }
        else
        {
            Elem* curr=this->root->next;
            last=this->root->val;
            this->root->next=NULL;
            delete this->root;
            this->root=curr;
            return last;

           
        }
    }
    else
    {
        return this->pop();
    }
}
            
void List::print()
{
    Elem* curr=this->root;
    while(curr!=NULL)
    {
        cout<<curr->val<<endl;
        curr=curr->next;
    }
    return;
}

        

/*List::List(List l)
{ 
    root=l.root;
    end_l=l.end_l;
}*/
int main()
{

    Elem* x=new Elem(3);
    Elem* y=new Elem(5,x);
    cout<<x->val<<endl<<y->val<<endl;
    List* l=new List();
    cout<<l->length()<<endl;
    l->push(4,'q');
    l->push(5,'q');
    l->push(12,'q');
    l->push(13,'q');
    l->print();
    l->pop('r');
    l->pop('r');
    l->pop('r');
    l->pop();
    l->print();
    return 0;

}

