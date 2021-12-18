#include<iostream>
using namespace std;

class Node{
	private:
		int val;
		Node* next;
	public:
		void setval(int v)
		{
			val=v;
		}
		void setnextnode(Node* n)
		{
			next=n;
		}
		int getval()
		{
			return val;
		}
		Node* getnextnode()
		{
			return next;
		}
		
};
class edgeNode{
	private:
		int linkval;
		edgeNode* linknext;
	public:
		void setlinkval(int v)
		{
			linkval=v;
		}
		void setlinknextnode(edgeNode* ln)
		{
			linknext=ln;
		}
		int getlinkval()
		{
			return linkval;
		}
		edgeNode* getlinknextnode()
		{
			return linknext;
		}
		
};

class linkedgelist{
	private:
		Node* head;
		Node* current;
		int size;
		edgeNode* ehead;
		edgeNode* ecurrent;
		int esize;
	public:
		linkedgelist()
		{
			head=NULL;
			current=NULL;
			size=0;
			ehead=NULL;
			ecurrent=NULL;
			esize=0;
		}
		
		void addnode(int s)
		{
			int v;
			int es;
			
			cout<<"Enter Value of Node: ";
			cin>>v;
			Node* temp=new Node();
			temp->setval(v);
			if(size==0)
			{
				temp->setnextnode(NULL);
				head=temp;
				current=head;
				size++;			
			}
			else
			{
				temp->setnextnode(current->getnextnode());
				current->setnextnode(temp);
				current=temp;
				size++;
			}
			cout<<"How many edges you want to enter :";
			cin>>es;
			addedgenode(es);
			if(size<s)
			addnode(s);
			
		}
		
		void addedgenode(int e)
			{
				int a;
				cout<<"Enter value of edge: ";
				cin>>a;
				edgeNode* link=new edgeNode();
				link->setlinkval(a);
				if(esize==0)
				{
					link->setlinknextnode(NULL);
					ehead=link;
					ecurrent=ehead;
					esize++;
				}
				else
				{
					link->setlinknextnode(ecurrent->getlinknextnode());
					ecurrent->setlinknextnode(link);
					ecurrent=link;
					esize++;
				}
				
				if(esize<e)
				addedgenode(e);
			}
			
			Node* returnhead()
			{
				return head;
			}
			edgeNode* returnehead()
			{
				return ehead;
			}
			
			void PRINT(Node* head)
			{			
			    if ( head== NULL)
			    {
			    	return ;
				}	     
			    cout << head->getval() << "   ";
			    
				printedge(ehead);		
			    PRINT(head->getnextnode());
			}
			void printedge(edgeNode* ehead)
			{
				if ( ehead== NULL)
				{
					return ;
				}
				cout<< ehead->getlinkval()<<endl;
				printedge(ehead->getlinknextnode());
				
			}
		
};

int main ()
{
	linkedgelist ll;
	ll.addnode(2);
	ll.PRINT(ll.returnhead());
	
	
}


