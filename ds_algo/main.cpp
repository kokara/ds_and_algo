#include<iostream>
using namespace std;
class node
{
public:
    int d;
    node *next;
    node *prev;
};
node *h=NULL,*t=NULL,*temp=NULL,*ptr=NULL;
void create();
void print();
void insertbeg();
void insertend();
int count1();
int search1(node*);
void insertafter();
void insertbefore();
void deletebeg();
void deleteend();
void deletepos();
void deleteall ();
int main()
{
    int o;
    char ch='y';
    cout<<"Enter 1 to create linked list"<<endl;
    cout<<"Enter 2 to print the data of the linked list"<<endl;
    cout<<"Enter 3 to insert the data at the beginning"<<endl;
    cout<<"Enter 4 to insert the data at the end"<<endl;
    cout<<"Enter 5 to count the data"<<endl;
    cout<<"Enter 6 to insert the data after a given data"<<endl;
    cout<<"Enter 7 to insert the data before a given data"<<endl;
    cout<<"Enter 8 to delete the first node"<<endl;
    cout<<"Enter 9 to delete the last node"<<endl;
    cout<<"Enter 10 to delete the data of a given position"<<endl;
    cout<<"Enter 11 to delete all nodes"<<endl;
    while(ch=='y'||ch=='Y')
    {
        cout<<"Which operation do you wanna perform: ";
        cin>>o;
        switch(o)
        {
        case 1:
            create();
            break;
        case 2:
            print();
            break;
        case 3:
            insertbeg();
            break;
        case 4:
            insertend();
            break;
        case 5:
          cout<<"Number of nodes="<<count1()<<endl;
            break;
        case 6:
            insertafter();
            break;
        case 7:
            insertbefore();
            break;
        case 8:
            deletebeg();
            break;
        case 9:
            deleteend();
            break;
        case 10:
            deletepos();
            break;
        case 11:
            deleteall();
            break;

        }
        cout<<"Do you wanna perform more operation: ";
        cin>>ch;
    }
}
void create()
{   char ch='y';
     while(ch=='y'||ch=='Y')
     {
         node *n=new node;
         cout<<"Enter the data: ";
         cin>>n->d;
         if(h==NULL)
         {
             h=n;
             t=n;
             n->prev=n;
             n->next=n;
         }
         else
         {
             t->next=n;
             n->prev=t;
             n->next=h;
             h->prev=n;
             t=n;
         }
         cout<<"Do you wanna enter more data: ";
         cin>>ch;
     }
     print();



}
void print()
{
    if(h==NULL)
    {
        cout<<"Linked list is empty"<<endl;
        return ;
    }
    temp=h;
    do

    {
        cout<<temp->d<<" ";
        temp=temp->next;
    }
    while(temp!=h);
    cout<<endl;
}
void insertbeg()
{  node *n=new node;
   cout<<"Enter the data to be inserted: ";
   cin>>n->d;
    if(h==NULL)
    {
             h=n;
             t=n;
             n->prev=n;
             n->next=n;
    }
    else
    {
        h->prev=n;
        n->next=h;
        n->prev=t;
        t->next=n;
        h=n;
    }
    print();
}
void insertend()
{
    node *n=new node;
    cout<<"Enter the data to be inserted: ";
    cin>>n->d;
    if(h==NULL)
    {
             h=n;
             t=n;
             n->prev=n;
             n->next=n;
    }
    else
    {
        t->next=n;
        n->prev=t;
        n->next=h;
        h->prev=n;
        t=n;
    }
    print();
}
int count1()
{
    temp=h;
    int c=0;
    if(h==NULL)
        return 0;
    do
    {
        c++;
        temp=temp->next;
    }
    while(temp!=h);
    return c;
}
int search1(node *n)
{
    int f=0;
    temp=h;
    do
    {
        if(temp->d==n->d)
            f=1;
        temp=temp->next;

    }
    while(temp!=h);
    if(f==1)
        return 1;
    else
        return 0;
}
void insertafter()
{
    if(h==NULL)
    {
        cout<<"Linked list is empty"<<endl;
        return;
    }
    node *t1=new node;
     cout<<"Enter the data after which the has to inserted: ";
     cin>>t1->d;
     if(search1(t1))
     {
         if(t1->d==t->d)
         {
             insertend();
             return ;
         }
         node *n=new node;
         cout<<"Enter the data to be inserted: ";
         cin>>n->d;
         temp=h;
         while(temp->d!=t1->d)
            temp=temp->next;
         n->prev=temp;
         n->next=temp->next;
         temp->next->prev=n;
         temp->next=n;
         print();

     }
     else
        cout<<"Entered element is not found in the list"<<endl;
}
void insertbefore()
{
    if(h==NULL)
    {
        cout<<"Linked list is empty"<<endl;
        return ;
    }
    node *t1=new node;
    cout<<"Enter the data before which the data has to be inserted: ";
    cin>>t1->d;
    if(search1(t1))
    {
        if(t1->d==h->d)
        {
            insertbeg();
            return ;
        }
        node *n=new node;
         cout<<"Enter the data to be inserted: ";
         cin>>n->d;
        temp=h;
        while(temp->d!=t1->d)
            temp=temp->next;
        n->next=temp;
        n->prev=temp->prev;
        temp->prev->next=n;
        temp->prev=n;
        print();
    }
    else
        cout<<"Entered data is not found in the list"<<endl;

}
void deletebeg()
{
    if(h==NULL)
    {
        cout<<"Linked list is empty"<<endl;
        return ;
    }
    if(h==t)
    {
        delete h;
        h=NULL;
        print();
        return ;
    }

    h->next->prev=t;
    t->next=h->next;
    delete h;
    h=t->next;
    print();

}
void deleteend()
{
    if(h==NULL)
    {
        cout<<"Linked list is empty"<<endl;
        return ;
    }
    if(h==t)
    {
        delete h;
        h=NULL;
        print();
        return ;
    }
    t->prev->next=h;
    h->prev=t->prev;
    delete t;
    t=h->prev;
    print();

}
void deletepos()
{
    if(h==NULL)
    {
        cout<<"Linked list is empty";
        return ;
    }
    int p;
    cout<<"Enter the position whose data has to be deleted: ";
    cin>>p;
    if(p<=0||p>count1())
    {
        cout<<"Entered position is out of range"<<endl;
        return ;
    }
    if(p==1)
    deletebeg();
    else if(p==count1())
        deleteend();
    else
    {
        int c=0;
        p--;
        temp=h;
        while(c!=p)
        {
            temp=temp->next;
            c++;
        }
         temp->prev->next=temp->next;
         temp->next->prev=temp->prev;
         delete temp;
         print();
    }
}
void deleteall()
{
    if(h==NULL)
    {
        cout<<"Linked list is empty"<<endl;
        return ;
    }
    int p=count1();
    while(p!=0)
    {
        deleteend();
        p--;
    }
    print();
}
