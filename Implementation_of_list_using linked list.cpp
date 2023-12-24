#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
int element;
struct node *next;
}*list=NULL,*p;
struct node *find(int);
struct node *findprevious(int); 
void insert(int X);
void deletion(int X);
void display();
void main()
{
int data,ch; clrscr();
cout<<"1.Insert\n2.Deletion\n3.Display\n4.Exit"; do
{
cout<<"\nenter your choice"; cin>>ch;
switch(ch)
{
case 1:
cout<<"enter the element to insert"; 
cin>>data;
insert(data);
 

break; case 2:
cout<<"enter the element to delete"; 
cin>>data;
deletion(data); 
break;
case 3:
display(); 
break;
case 4:
exit(0);
}
}while(ch<4);
getch();
}
void insert(int X)
{
struct node *newnode; int pos;
newnode=(struct node*)malloc(sizeof(struct node)); newnode->element=X;
if(list->next==NULL)
{

list->next=newnode; newnode->next=NULL;
}
else
{
cout<<"\n enter the value after which the element to be inserted"; cin>>pos;
p=find(pos);
newnode->next=p->next;
p->next=newnode;
}
}
struct node *find(int s)
{
p=list->next;
while(p!=NULL&&p->element!=s) p=p->next;
return p;
}
 

void deletion(int X)
{
struct node *temp;
temp=(struct node*)malloc(sizeof(struct node));
p=findprevious(X);
if(p->next!=NULL)
{
temp=p->next;
p->next=temp->next;
cout<<"\n the deleted element is"<<temp->element; 
free(temp);
}
else
cout<<"\n element not found in the list";
}
struct node *findprevious(int s)
{
p=list;
while(p->next!=NULL&&p->next->element!=s) p=p->next;
return p;
}
void display()
{
if(list->next==NULL)
cout<<"list is empty";
else
{
p=list->next;
cout<<"\n the contents of the list are:\n";
while(p!=NULL)
{
cout<<p->element; p=p->next;
}
cout<<"null";
}
}
