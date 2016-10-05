#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node *next;
};

struct HeadNode
{
	int count;
	Node *headPtr;
};

class LinkedList
{
	public:
		LinkedList();
		~LinkedList();

		void addToHead( int );
		bool removeFromHead();

		void addNode( int );
		bool deleteNode( int );
		void deleteAllNodes();

		bool isEmpty();
		int getNoOfNodes();

		void displayAllNodes();

	private:
		int dataCmp( int, int );
		void displayNode( Node* );

		HeadNode head;
};

int main(){
    LinkedList *list = new LinkedList;
    list->addNode(20);
    list->addNode(30);
    list->addNode(40);
    list->addNode(50);
    
    list->displayAllNodes();
    
    return 0;
}

LinkedList::LinkedList()
{
	head.count = 0;
	head.headPtr = NULL;
	return;
}

LinkedList::~LinkedList()
{
	deleteAllNodes();
	return;
}

void LinkedList::addToHead( int newData )
{
	Node *pNew = new Node;
	pNew -> data = newData;
	pNew -> next = head.headPtr;
	head.headPtr = pNew;
	head.count++;
}

bool LinkedList::removeFromHead()
{
	bool exit;
	Node *temp;

	if ( head.headPtr )
	{
		temp = head.headPtr;
		head.headPtr = head.headPtr -> next;
		delete temp;
		head.count--;
		exit = true; // returns true if successful
	}
	else
		exit = false; // returns false if unsuccessful

	return exit;
}

void LinkedList::addNode( int newData )
{
	Node *pNew = new Node,
	     *pPre = NULL,
	     *pCur = head.headPtr;
	pNew -> data = newData;

	while ( pCur && dataCmp( pNew -> data, pCur -> data ) >= 0 )
	{
		pPre = pCur;
		pCur = pCur -> next;
	}

	if ( pPre )
	{
		pNew -> next = pPre -> next;
		pPre -> next = pNew;
		head.count++;
	}
	else
	{
		pNew -> next = head.headPtr;
		head.headPtr = pNew;
		head.count++;
	}
	
}

bool LinkedList::deleteNode( int data )
{
	bool exit;
	Node *pPre = NULL,
	     *pCur = head.headPtr;

	while ( pCur && dataCmp( pCur -> data, data ) < 0 )
	{
		pPre = pCur;
		pCur = pCur -> next;
	}

	if ( pCur && dataCmp( pCur -> data, data ) == 0 )
	{
		if ( pPre )
		{
			pPre -> next = pCur -> next;
			delete pCur;
			head.count--;
			exit = true; // return true if successful
		}
		else
		{
			head.headPtr = pCur -> next;
			delete pCur;
			head.count--;
			exit = true; // return true if successful
		}
	}
	else
		exit = false; // return false if unsuccessful

	return exit;
}

void LinkedList::deleteAllNodes()
{
	Node *temp;

	while ( head.headPtr )
	{
		temp = head.headPtr;
		head.headPtr = head.headPtr -> next;
		delete temp;
		head.count--;
	}

	return;
}

bool LinkedList::isEmpty()
{
	return head.count == 0;
}


int LinkedList::getNoOfNodes()
{
	return head.count;
}

void LinkedList::displayAllNodes()
{
	Node *pCur = head.headPtr;
	int nodeCount = 1;

	while ( pCur )
	{
		cout << "Node " << nodeCount << ": ";
		displayNode( pCur );
		cout << endl;

		nodeCount++;
		pCur = pCur -> next;
	}

	return;
}


int LinkedList::dataCmp( int value0, int value1 )
{
	int exit = 0;

	if ( value0 < value1 )
		exit = -1;
	else if ( value0 > value1 )
		exit = 1;

	return exit;
}

void LinkedList::displayNode( Node *node )
{
	cout << node -> data;
	return;
}