#include <iostream>
using namespace std;
#define ENDL -1
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
    val=a;
    next=next_elem;
}
Elem::Elem(int a)
{
    val=a;
    next=NULL;
}
class List
{
    public:
        Elem* root;
        Elem* end_l;
        List(){root=NULL;end_l=NULL;}
        List(List*);
//        List(List l);
};
List::List(List* l)
{
    root=l->root;
    end_l=l->root;
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
    cout<<x->val<<endl<<y->val;
    return 0;
}

