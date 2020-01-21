#include <iostream>

using namespace std;
class node
{
public:
    int data;
    node * lchild;
    node * rchild;
    //friend node * newNode(int data);
};
node * newNode(int data)
{
    node * t=new node;
    t->data=data;
    t->lchild=NULL;
    t->rchild=NULL;
    return t;
}
class BST
{

public:
    node * root;
    BST()
    {
        root=NULL;
    }
    void Iinsert(int key);
    node *Rinsert(node *,int key);
    void Inorder(node *);
    node *Delete(node *p,int key);
    int Height(node*p);
    node * InPre(node *p);
    node * Insuc(node *p);
    bool search(int key);
    node * Ilca(node *,int a,int b);
    int Findlevel(node *root,int key,int level);
    int FindDistance(int a,int b);
};
void BST::Iinsert(int key)
{
    if(root==NULL)
    {
        root=new node;
        root->data=key;
        root->lchild=root->rchild=NULL;
        return;
    }
    node *t=root,*r=NULL,*p;
    while(t!=NULL)
    {
        r=t;
     if(key<t->data)
        t=t->lchild;
     else if(key>t->data)
        t=t->rchild;
     else
        return;
    }
    p=new node;
    p->data=key;
    p->lchild=p->rchild=NULL;
    if(p->data<r->data)
        r->lchild=p;
    else
        r->rchild=p;

}
node * BST::Rinsert(node *p,int key)
{
    if(p==NULL)
    {
        node *t=new node;
        t->data=key;
        t->lchild=t->rchild=NULL;
        return t;
    }
    if(key < p->data)
        p->lchild=Rinsert(p->lchild,key);
    else if(key>p->data)
        p->rchild=Rinsert(p->rchild,key);
    return p;
}
void BST::Inorder(node *p)
{
	if(p)
	{
		Inorder(p->lchild);
    	cout<<p->data<<" ";
    	Inorder(p->rchild);
	}

}
bool BST::search(int key)
{
    node *p=root;
    while(p)
    {
        if(p->data==key)
            return true;
        if(key<p->data)
            p=p->lchild;
        else
            p=p->rchild;
    }
    return false;
}
node * BST::Delete(node *p,int key)
{
    node *q;
    if(p==NULL)
            return NULL;
    if(p->lchild==NULL && p->rchild==NULL)
    {
        if(p==root)
            root=NULL;
        delete p;
        return NULL;
    }
    if(key<p->data)
        p->lchild=Delete(p->lchild,key);
    else if(key>p->data)
        p->rchild=Delete(p->rchild,key);
    else
    {
        //when key value is found...
        if(Height(p->lchild)>Height(p->rchild))
        {
            q=InPre(p->lchild);
            p->data=q->data;
            p->lchild=Delete(p->lchild,q->data);
        }
        else
        {
            q=Insuc(p->rchild);
            p->data=q->data;
            p->rchild=Delete(p->rchild,q->data);
        }
    }
    return p;
}
int BST::Height(node *p)
{
    if(p==NULL)
        return 0;
    int x,y;
    x=Height(p->lchild);
    y=Height(p->rchild);
    return x>y?x+1:y+1;
}
node * BST::InPre(node *p)
{
    while(p && p->rchild!=NULL)
        p=p->rchild;
    return p;
}
node * BST::Insuc(node *p)
{
    while(p && p->lchild!=NULL)
        p=p->lchild;
    return p;
}
node * BST::Ilca(node *p,int a,int b)
{
    while(p!=NULL)
    {
        if(a>p->data && b>p->data)
            p=p->rchild;
        else if(a<p->data && b<p->data)
            p=p->lchild;
        else
            break;
    }
    return p;
}
int BST::Findlevel(node* root,int key,int level)
{
    if(root==NULL)//it is just like preorder traversal
        return -1;
    if(root->data==key)
        return level;
    int left=Findlevel(root->lchild,key,level+1);
    if(left==-1)
        return Findlevel(root->rchild,key,level+1);
    return left;
}
int BST::FindDistance(int a,int b)
{
    node *lca=Ilca(root,a,b);
    int d1=Findlevel(lca,a,0);
    int d2=Findlevel(lca,b,0);
    return d1+d2;
}
int main()
{
    /*BST t;
    //node *temp;
    t.root=t.Rinsert(t.root,9);
    t.Rinsert(t.root,5);
    t.Rinsert(t.root,10);
    t.Rinsert(t.root,2);
    t.Rinsert(t.root,13);
    t.Rinsert(t.root,8);
    t.Inorder(t.root);
    cout<<endl;
    cout<<t.FindDistance(8,10);
    //t.Delete(t.root,30);
    //t.Delete(t.root,3);
    //cout<<"\n";
    //t.Inorder(t.root);
    //int a=13,b=10;
   // cout<<"\nthe lca of "<<a<<" and "<<b<<" is : "<<t.Ilca(t.root,a,b)->data<<endl;*/
   node *root=newNode(6);
   root->lchild=newNode(2);
   root->rchild=newNode(8);
   root->lchild->lchild=newNode(1);
   root->lchild->rchild=newNode(9);
    return 0;
}
