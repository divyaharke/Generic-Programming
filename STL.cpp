///////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : Singly Linked List.
// Input		 : Integer ,float , character.
// Output		 : Integer , float, character.
// Description	 : It is Used to store and remove data from linked list.
// Author		 : Divya Harke
//
///////////////////////////////////////////////////////////////////////////////////////////////////////


#include<iostream>
#include<stdio.h>
using namespace std;

template<typename T>
struct nodeS					// Structre Defination
{
	T data;
	struct nodeS *next;
};

template<class T>
class SinglyLL
{
private:
	nodeS<T>*first;
	int size;
	
public:						
	SinglyLL();
	void InsertFirst(T no);
	void InsertLast(T no);
	void DeleteFirst();
	void DeleteLast();
	void InsertAtPos(T no ,int);
	void DeleteAtPos(int);
	void Display();
	int Count();
};

template<class T>
	SinglyLL<T>::SinglyLL()
	{
		first =NULL;
		size = 0;
	}

///////////////////////////////////////////////////////////////////
//
// Function name 	: InsertFirst
// Description 		: Used to insert at first position of Linked List
// Parameters 		: Addreass of First pointer & data of node
// Return Value 	: void
//
///////////////////////////////////////////////////////////////////

template<class T>
void SinglyLL<T>::InsertFirst(T no)
{
	nodeS<T>*newn = new nodeS<T>; // newn = (PNODE)malloc(sizeof(NODE));
		
	newn -> data = no;
	newn -> next = NULL;
		
	if(first == NULL)
	{
		first = newn;
	}
	else
	{
		newn -> next = first;
		first = newn;
	}
	size++;
}

///////////////////////////////////////////////////////////////////
//
// Function name 	: InsertsLast
// Description 		: Used to insert at last position of Linked List
// Parameters 		: Addreass of First pointer & data of node
// Return Value 	: void
//
///////////////////////////////////////////////////////////////////

template<class T>
void SinglyLL<T>::InsertLast(T no)
{
	nodeS<T>*newn = new nodeS<T>; // newn = (PNODE)malloc(sizeof(NODE));
		
	newn -> data = no;
	newn -> next = NULL;
		
	if(first == NULL)
	{
		first = newn;
	}
	else
	{
		nodeS<T>*temp = first;
			
		while(temp -> next != NULL)
		{
			temp = temp -> next;
		}
		temp -> next = newn;
	}
	size++;
}

///////////////////////////////////////////////////////////////////
//
// Function name 	: DeleteFirst
// Description 		: Used to delete at first position of Linked List
// Parameters 		: Addreass of First pointer & data of node
// Return Value 	: void
//
///////////////////////////////////////////////////////////////////	
	
template<class T>	
void SinglyLL<T>::DeleteFirst()
{
	nodeS<T>*temp = first;
		
	if(first != NULL)
	{
		first = first -> next;
		delete temp;
			
		size--;
		
	}
}

///////////////////////////////////////////////////////////////////
//
// Function name 	: DeleteLast
// Description 		: Used to delete at last position of Linked List
// Parameters 		: Addreass of First pointer & data of node
// Return Value 	: void
//
///////////////////////////////////////////////////////////////////

template<class T>	
void SinglyLL<T>::DeleteLast()
{
	nodeS<T>*temp = first;
		
	if(first == NULL)
	{
		return;
	}
	if(first -> next == NULL)
	{
		delete first;
		first =NULL;
		size--;
	}
	else
	{
		while(temp -> next -> next != NULL)
		{
			temp = temp -> next;
		}
			
		delete temp -> next;
		temp -> next =NULL;
		size--;
	}
}

///////////////////////////////////////////////////////////////////
//
// Function name 	: InsertAtPosition
// Description 		: Used to insert at desired position of Linked List
// Parameters 		: Addreass of First pointer , posion to insert & data of node
// Return Value 	: void
//
///////////////////////////////////////////////////////////////////

template<class T>	
void SinglyLL<T>::InsertAtPos(T no , int ipos)
{
	nodeS<T>*newn = new nodeS<T>;
	nodeS<T>*temp = first;
	int i = 0;
		
	newn -> data = no;
	newn -> next = NULL;
		
	if(ipos == 1)
	{
		InsertFirst(no);
	}
	else if(ipos == size + 1)
	{
		InsertLast(no);
	}
	else
	{
		nodeS<T>*newn = new nodeS<T>;
		
		newn -> data = no;
		newn -> next = NULL;
		
		for(i = 1 ; i < ipos - 1 ; i++)
		{
			temp = temp -> next;
		}
		newn -> next = temp -> next;
		temp -> next = newn;
	}	
		size++;
}
	
///////////////////////////////////////////////////////////////////
//
// Function name 	: DeleteAtPosition
// Description 		: Used to delete at desired position of Linked List
// Parameters 		: Addreass of First pointer & posion to insert .
// Return Value 	: void
//
///////////////////////////////////////////////////////////////////	
	
template<class T>	
void SinglyLL<T>::DeleteAtPos(int ipos)
{
	nodeS<T>*temp = first;
	nodeS<T>*targated = NULL;
	int i = 0;
		
	if(ipos == 1)
	{
		DeleteFirst();
	}
	else if(ipos  == size + 1)
	{
		DeleteLast();
	}
	else
	{
		for(i = 1; i < ipos -1 ; i++)
		{
			temp = temp -> next;
		}
		targated = temp -> next;
		temp -> next = targated -> next;
		delete(targated);
	}
	size--;
}

///////////////////////////////////////////////////////////////////
//
// Function name 	: Display
// Description 		: Used to display complete Linked List
// Parameters 		: Addreass of First pointer.
// Return Value 	: void
//
///////////////////////////////////////////////////////////////////

template<class T>	
void SinglyLL<T>::Display()
{
		
	nodeS<T>*temp = first;
		
	if(size == 0)
	{
		cout<<"Linked list is empty \n";
		cout<<"NULL";
	}
		
	while(temp != NULL)
	{
		cout<<temp -> data <<"\t";
		temp = temp -> next;
	}
	cout<<"\n";
}
	
///////////////////////////////////////////////////////////////////
//
// Function name 	: Count
// Description 		: Used to count the nodes of Linked List
// Parameters 		: Size
// Return Value 	: integer
//
///////////////////////////////////////////////////////////////////	
	
template<class T>	
int SinglyLL<T>::Count()
{
	return size;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : Sigly Circular Linked List.
// Input		 : Integer ,float , character.
// Output		 : Integer , float, character.
// Description   : It is Used to store and remove data from linked list.
// Author		 : Divya Harke
//
///////////////////////////////////////////////////////////////////////////////////////////////////////


template<class T>
class SinglyCL
{
private:
	nodeS<T>*first;
	nodeS<T>*last;
	int size;
	
public:
	SinglyCL();
	void InsertFirst(T no);
	void InsertLast(T no);
	void InsertAtPos(T , int);
	void DeleteFirst();
	void DeleteLast();
	void DeleteAtPos(int);
	void Display();
	int Count();

};

template<class T>
SinglyCL<T>::SinglyCL()
{
	first = NULL;
	last = NULL;
	size = 0;
}
		
///////////////////////////////////////////////////////////////////
//
// Function name	 : InsertFirst
// Description 		 : Used to insert at first position of Linked List
// Parameters 		 : Addreass of First pointer & data of node
// Return Value		 : void
//
///////////////////////////////////////////////////////////////////
		
template<class T>	
void SinglyCL<T>::InsertFirst(T no)
{
	nodeS<T>*newn = new nodeS<T>;
		
	newn -> data = no;
	newn -> next = NULL;
		
	if((first ==NULL) && (last == NULL))
	{
		first = newn;
		last = newn;
	}
	else
	{
		newn -> next = first;
		first = newn;
		last -> next = first;
			
	}
	last -> next = first;
	size++;
}

///////////////////////////////////////////////////////////////////
//
// Function name 	: InsertLast
// Description 		: Used to insert at last position of Linked List
// Parameters 		: Addreass of First pointer & data of node
// Return Value 	: void
//
///////////////////////////////////////////////////////////////////
	
template<class T>	
void SinglyCL<T>::InsertLast(T no)
{
	nodeS<T>*newn = new nodeS<T>;
		
	newn -> data = no;
	newn -> next = NULL;
		
	if((first ==NULL) && (last == NULL))
	{
		first = newn;
		last = newn;
	}
	else
	{
		last -> next = newn;
		last = newn;
	}
	last -> next = first;
	size++;
}

///////////////////////////////////////////////////////////////////
//
// Function name 	: DeleteFirst
// Description 		: Used to delete at first position of Linked List
// Parameters 		: Addreass of First pointer & data of node
// Return Value 	: void
//
///////////////////////////////////////////////////////////////////
	
template<class T>
void SinglyCL<T>::DeleteFirst()
{
	if((first == NULL)&&(last == NULL))
	{
		return;
	}
	else if(first == last)
	{
		delete first;
		first = NULL;
		last =NULL;
	}
	else
	{
		first = first -> next;
		delete last -> next;
		last -> next = first;
	}
	size--;
}

///////////////////////////////////////////////////////////////////
//
// Function name 	: DeleteLast
// Description 		: Used to delete at last position of Linked List
// Parameters 		: Addreass of First pointer & data of node
// Return Value 	: void
//
///////////////////////////////////////////////////////////////////
	
template<class T>
void SinglyCL<T>::DeleteLast()
{
	nodeS<T>*temp =first;
		
    if((first == NULL)&&(last == NULL))
	{
		return;
	}
	else if(first == last)
	{
		delete first;
		first = NULL;
		last =NULL;
	}
	else
	{
		while(temp -> next != last)
		{
			temp = temp -> next; 
		}
			
		delete last;
		last = temp;
			
		last -> next = first;
	}
	size--;
}
	
///////////////////////////////////////////////////////////////////
//
// Function name 	: InsertAtPosition
// Description 		: Used to insert at desired position of Linked List
// Parameters 		: Addreass of First pointer , posion to insert & data of node
// Return Value 	: void
//
///////////////////////////////////////////////////////////////////
	
template<class T>	
void SinglyCL<T>::InsertAtPos(T no , int ipos)
{
	if((ipos < 1) ||(ipos >(size + 1)))	// Invalide position
	{
		return;
	}
		
	if(ipos == 1)	//First position
	{
		InsertFirst(no);
	}
	else if(ipos == size +1) //last position
	{
		InsertLast(no);
	}
	else
	{
		nodeS<T>*newn = new nodeS<T>;
			
		newn -> data = no;
		newn -> next = NULL;
			
		nodeS<T>*temp = first;
			
		for(int i = 1; i < ipos -1; i++)
		{
			temp = temp -> next;
		}
			
		newn -> next = temp -> next;
		temp -> next = newn;
		
		size++;
			
	}
}

///////////////////////////////////////////////////////////////////
//
// Function name 	: DeleteAtPosition
// Description 		: Used to delete at desired position of Linked List
// Parameters 		: Addreass of First pointer & posion to insert .
// Return Value 	: void
//
///////////////////////////////////////////////////////////////////	
	
template<class T>	
void SinglyCL<T>::DeleteAtPos(int ipos)
{
	if((ipos < 1)||(ipos > size))
	{
		return;
	}
		
	if(ipos == 1)
	{
		DeleteFirst();
	}
	else if(ipos == size)
	{
		DeleteLast();
	}
	else
	{
		nodeS<T>*temp =first;
		for(int i = 1; i< ipos -1 ; i++)
		{
			temp = temp -> next;
		}
			
		nodeS<T>*targated = temp -> next;
			
		temp -> next = targated -> next;
		delete targated;
	}
		
	size--;
}

///////////////////////////////////////////////////////////////////
//
// Function name 	: Display
// Description 		: Used to display complete Linked List
// Parameters 		: Addreass of First pointer.
// Return Value 	: void
//
///////////////////////////////////////////////////////////////////

template<class T>	
void SinglyCL<T>::Display()
{
	nodeS<T>*temp = first;
		
	if((first == NULL)&&(last == NULL))
	{
		return;
	}
		
	do
	{
		cout<<"|"<<temp->data<<"|->";
		temp = temp -> next;
	}while(temp != last -> next);
		
	cout<<"\n";
}

///////////////////////////////////////////////////////////////////
//
// Function name 	: Count
// Description 		: Used to count the nodes of Linked List
// Parameters 		: Size
// Return Value 	: integer
//
///////////////////////////////////////////////////////////////////

template<class T>	
int SinglyCL<T>::Count()
{
	return size;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : Doubly Linear Linked List.
// Input		 : Integer ,float , character.
// Output		 : Integer , float, character.
// Description   : It is Used to store and remove data from linked list.
// Author		 : Divya Harke
//
///////////////////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
struct nodeD					// Structre Defination
{
	T data;
	struct nodeD *next;
	struct nodeD *prev;
};

template <class T>
class DoublyLL
{
private:
	nodeD<T>*first;
	int size;
	
public:
	DoublyLL();
	void InsertFirst(T);
	void InsertLast(T);
	void DeleteFirst();
	void DeleteLast();
	void DeleteAtPos(int);
	void InsertAtPos(T,int);
	void Display();
	int Count();

};

template <class T>
DoublyLL<T>::DoublyLL()
{
	first = NULL;
	size = 0;
}

///////////////////////////////////////////////////////////////////
//
// Function name	 : InsertFirst
// Description		 : Used to insert at first position of Linked List
// Parameters		 : Addreass of First pointer & data of node
// Return Value		 : void
//
///////////////////////////////////////////////////////////////////
	
template <class T>
void DoublyLL<T>::InsertFirst(T iNo)
{
			
	nodeD<T>*newn = new nodeD<T>;
	
	newn -> data = iNo;
	newn -> next = NULL;
	newn -> prev = NULL;
	
	if(first == NULL)
	{
		first = newn;
	}
	else 
	{
		newn -> next = first ;
		first -> prev = newn;
		first = newn;
		
	}
	size++;
}

///////////////////////////////////////////////////////////////////
//
// Function name 	: InsertLast
// Description 		: Used to insert at last position of Linked List
// Parameters 		: Addreass of First pointer & data of node
// Return Value 	: void
//
///////////////////////////////////////////////////////////////////
	
template <class T>
void DoublyLL<T>::InsertLast(T iNo)
{
	nodeD<T>*temp = first;
		
	nodeD<T>*newn = new nodeD<T>;
		
	newn -> data = iNo;
	newn -> next = NULL;
	newn -> prev = NULL;
		
	if(temp == NULL)
	{
		temp = newn;
	}
	else
	{
		while(temp -> next != NULL)
	{
		temp = temp -> next;
	}
	temp -> next = newn;
	newn -> prev = temp ;
	}
	size++;
}

///////////////////////////////////////////////////////////////////
//
// Function name 	: DeleteFirst
// Description 		: Used to delete at first position of Linked List
// Parameters 		: Addreass of First pointer & data of node
// Return Value 	: void
//
///////////////////////////////////////////////////////////////////	
	
template <class T>
void DoublyLL<T>::DeleteFirst()
{
	nodeD<T>*temp = first ;
		
	if(first == NULL)
	{
		cout<<"Linked list is Empty \n";
		return;
	}
	else
	{
		first = first -> next;
		delete temp;
		first -> prev = NULL;
	}
	size--;
}

///////////////////////////////////////////////////////////////////
//
// Function name 	: DeleteLast
// Description 		: Used to delete at last position of Linked List
// Parameters 		: Addreass of First pointer & data of node
// Return Value 	: void
//
///////////////////////////////////////////////////////////////////
	
template <class T>
void DoublyLL<T>::DeleteLast()
{
	nodeD<T>*temp = first;
		
	if(size == 0)
	{
		cout<<"Linked list is empty \n";
		return;
	}
	else
	{
		while(temp -> next -> next != NULL)
		{
			temp = temp -> next;
		}
		delete temp -> next; 
		temp -> next = NULL;
	}
		
	size--;
}

///////////////////////////////////////////////////////////////////
//
// Function name 	: InsertAtPosition
// Description 		: Used to insert at desired position of Linked List
// Parameters 		: Addreass of First pointer , posion to insert & data of node
// Return Value 	: void
//
///////////////////////////////////////////////////////////////////
	
template <class T>
void DoublyLL<T>::InsertAtPos(T iNo, int iPos)
{
	nodeD<T>*temp = first;
		
	int i = 0;
		
	if((iPos < 1) || (iPos > size + 1))
	{
		cout<<"wrong input \n";
		return;
	}
		
	if(iPos == 1)
	{
		InsertFirst(iPos);
	}
	else if(iPos == size + 1)
	{
		InsertLast(iPos);
	}
	else
	{
		nodeD<T>*newn = new nodeD<T>;
			
		newn -> data = iNo;
		newn -> next = NULL;
		newn -> prev = NULL;
			
		for(i = 1; i < iPos - 1 ; i++)
		{
			temp = temp -> next;
		}
		newn -> next = temp -> next;
		newn -> prev = temp -> next -> prev;
		temp -> next -> prev = newn;
		temp -> next = newn;
			
	}
	size++;
}

///////////////////////////////////////////////////////////////////
//
// Function name 	: DeleteAtPosition
// Description 		: Used to delete at desired position of Linked List
// Parameters 		: Addreass of First pointer & posion to insert .
// Return Value 	: void
//
///////////////////////////////////////////////////////////////////
	
template <class T>
void DoublyLL<T>::DeleteAtPos(int iPos)
{
	nodeD<T>*temp = first;
	nodeD<T>*targated =NULL;
	int i = 0;
		
	if(size == 0)
	{
		cout<<"Linked list is empty \n";
		return;
	}
	else if(temp -> next == NULL)
	{
		delete temp -> next;
		temp = NULL;
	}
	else
	{
		for(i = 1 ; i < iPos - 1 ; i++)
		{
			temp =temp -> next;
		}
		targated = temp -> next;
		temp -> next = targated -> next;
		targated -> next -> prev = temp;
		delete targated;
	}
	size--;
}

///////////////////////////////////////////////////////////////////
//
// Function name 	: Display
// Description 		: Used to display complete Linked List
// Parameters 		: Addreass of First pointer.
// Return Value 	: void
//
///////////////////////////////////////////////////////////////////
	
template <class T>
void DoublyLL<T>::Display()
{
	nodeD<T>*temp = first;
		
		if(size == 0)
	{
		cout<<"Linked list is empty \n";
		cout<<"NULL";
	}
		
	while(temp != NULL)
	{
		cout<<temp -> data <<"\t";
		temp = temp -> next;
	}
	cout<<"\n";
}

///////////////////////////////////////////////////////////////////
//
// Function name 	: Count
// Description 		: Used to count the nodes of Linked List
// Parameters 		: Size
// Return Value 	: integer
//
///////////////////////////////////////////////////////////////////	
	
template <class T>
int DoublyLL<T>::Count()
{
	return size;
}	
	
	
///////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : Doubly Circular Linked List.
// Input		 : Integer ,float , character.
// Output		 : Integer , float, character.
// Description   : It is Used to store and remove data from linked list.
// Author		 : Divya Harke
//
///////////////////////////////////////////////////////////////////////////////////////////////////////


template<class T>
class DoublyCL
{
private:
	nodeD<T>*first;
	nodeD<T>*last;
	int size;

public:
	
	
	DoublyCL();
	void Display();
	int Count();
	void InsertFirst(T);
	void InsertLast(T);
	void InsertAtPos(T, int ipos);
	void DeleteFirst();
	void DeleteLast();
	void DeleteAtPos(int);
};

template<class T>
DoublyCL<T>::DoublyCL()
{
	first = NULL;
	last = NULL;
	size = 0;
}

///////////////////////////////////////////////////////////////////
//
// Function name	 : InsertFirst
// Description		 : Used to insert at first position of Linked List
// Parameters		 : Addreass of First pointer & data of node
// Return Value		 : void
//
///////////////////////////////////////////////////////////////////

template<class T>
void DoublyCL<T>::InsertFirst(T no)
{
	nodeD<T>*newn = new nodeD<T>;
	
	newn -> data = no;
	newn -> next = NULL;
	newn -> prev = NULL;
	
	if((first == NULL)&&(last == NULL))
	{
		first = newn;
		last = newn;
	}
	else
	{
		newn -> next = first;
		first -> prev = newn;
		first = newn;
	}
	
	last-> next = first;
	first -> prev = last;
	size++;
}

///////////////////////////////////////////////////////////////////
//
// Function name 	: InsertLast
// Description 		: Used to insert at last position of Linked List
// Parameters 		: Addreass of First pointer & data of node
// Return Value 	: void
//
///////////////////////////////////////////////////////////////////

template<class T>
void DoublyCL<T>::InsertLast(T no)
{
	nodeD<T>*newn = new nodeD<T>;
	
	newn -> data = no;
	newn -> next = NULL;
	newn -> prev = NULL;
	
	if((first == NULL)&&(last == NULL))
	{
		first = newn;
		last = newn;
	}
	else
	{
		last -> next = newn;
		newn -> prev = last;
		last = newn;
	}

	last-> next = first;
	first -> prev = last;
	size++;
}

///////////////////////////////////////////////////////////////////
//
// Function name 	: DeleteFirst
// Description 		: Used to delete at first position of Linked List
// Parameters 		: Addreass of First pointer & data of node
// Return Value 	: void
//
///////////////////////////////////////////////////////////////////	

template<class T>
void DoublyCL<T>::DeleteFirst()
{
	if((first == NULL) && (last == NULL))
	{
		return;
	}
	else if(first == last)
	{
		delete first;
		first =NULL;
		last =NULL;
	}
	else
	{
		first = first -> next;
		delete last -> next;
		first -> prev = last;
		last -> next = first;
	}
	size--;
}

///////////////////////////////////////////////////////////////////
//
// Function name 	: DeleteLast
// Description 		: Used to delete at last position of Linked List
// Parameters 		: Addreass of First pointer & data of node
// Return Value 	: void
//
///////////////////////////////////////////////////////////////////

template<class T>
void DoublyCL<T>::DeleteLast()
{
	if((first == NULL) && (last == NULL))
	{
		return;
	}
	else if(first == last)
	{
		delete first;
		first =NULL;
		last =NULL;
	}
	else
	{
		last = last -> prev ;
		delete last -> next;
		first -> prev = last;
		last -> next = first;
	}
	size--;
}

///////////////////////////////////////////////////////////////////
//
// Function name 	: InsertAtPosition
// Description 		: Used to insert at desired position of Linked List
// Parameters 		: Addreass of First pointer , posion to insert & data of node
// Return Value 	: void
//
///////////////////////////////////////////////////////////////////

template<class T>
void DoublyCL<T>::InsertAtPos(T no,int ipos)
{
	if((ipos < 1)||(ipos > size + 1))
	{
		return;
	}
	
	if(ipos == 1)
	{
		InsertFirst(no);
	}
	else if(ipos == size + 1)
	{
		InsertLast(no);
	}
	else
	{
		nodeD<T> *newn = new nodeD<T>;
		
		newn -> data = no;
		newn -> next = NULL;
		newn -> prev = NULL;
		
		nodeD<T> *temp =first;
		
		for(int i = 1; i < ipos -1 ; i++)
		{
			temp =temp -> next;
		}
		
		newn -> next = temp -> next;
		newn -> next -> prev = newn;
		temp -> next = newn;
		newn -> prev = temp;
		size++;
	}
}

///////////////////////////////////////////////////////////////////
//
// Function name 	: DeleteAtPosition
// Description 		: Used to delete at desired position of Linked List
// Parameters 		: Addreass of First pointer & posion to insert .
// Return Value 	: void
//
///////////////////////////////////////////////////////////////////

template<class T>
void DoublyCL<T>::DeleteAtPos(int ipos)
{
	if((ipos < 1)||(ipos > size))
	{
		return;
	}
	if(ipos == 1)
	{
		DeleteFirst();
	}
	else if(ipos == size)
	{
		DeleteLast();
	}
	else
	{
		nodeD<T> *temp = first;
		
		for(int i = 1; i < ipos - 1; i++)
		{
			temp = temp -> next;
		}
		
		temp -> next = temp -> next -> next;
		delete temp -> next -> prev;
		temp -> next -> prev = temp;
		
		size--;
	}
}

///////////////////////////////////////////////////////////////////
//
// Function name 	: Display
// Description 		: Used to display complete Linked List
// Parameters 		: Addreass of First pointer.
// Return Value 	: void
//
///////////////////////////////////////////////////////////////////

template<class T>
void DoublyCL<T>::Display()
{
	nodeD<T>*temp = first;
	
	for(int i = 1 ; i<= size ; i++)
	{
		cout<<"|"<<temp->data<<"|->";
		temp = temp -> next;
	}
	cout<<"\n";
}

///////////////////////////////////////////////////////////////////
//
// Function name 	: Count
// Description 		: Used to count the nodes of Linked List
// Parameters 		: Size
// Return Value 	: integer
//
///////////////////////////////////////////////////////////////////

template<class T>
int DoublyCL<T>:: Count()
{
	return size;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : Stack.
// Input		 : Integer ,float , character.
// Output		 : Integer , float, character.
// Description   : It is Used to store and remove data from stack.
// Author		 :Divya Harke
//
///////////////////////////////////////////////////////////////////////////////////////////////////////


template<class T>
class Stack	//Singly linear linked list
{
private:
	nodeS<T>*first;
	int size;
public:
	Stack();
	void push(T);
	int pop();
	void Display();
	int Count();
		
};
template<class T>
Stack<T>::Stack()
	{
		first =NULL;
		size = 0;
	}
		
///////////////////////////////////////////////////////////////////
//
// Function name 	: Push
// Description 		: Used to insert data.
// Parameters 		: Addreass of First pointer & data of node
// Return Value 	: void
//
///////////////////////////////////////////////////////////////////
		
template<class T>		
void Stack<T>::push(T no)	//InsertFirst()
	{
		nodeS<T>*newn = new nodeS<T>;
			
		newn -> data = no;
		newn -> next = NULL;
			
		if(first == NULL)
		{
			first = newn;
		}
		else
		{
		    newn -> next = first;
			first = newn;
		}
		size++;
	}

///////////////////////////////////////////////////////////////////
//
// Function name 	: Pop
// Description 		: Used to delete data.
// Parameters 		: Addreass of First pointer & data of node
// Return Value 	: void
//
///////////////////////////////////////////////////////////////////	

template<class T>		
int Stack<T>::pop()	//DeleteFirst()
	{
		int no = 0;
		nodeS<T>*temp = first;
		if(first == NULL)
		{
			cout<<"Stack is empty\n";
			return -1;
		}
		if(size == 1)
		{
			first = first -> next;
			delete first;
			first = NULL;
		}
		else
		{
			no = first -> data;
			first = first -> next;
			delete temp;
		}
		size--;
			
		return no;
	}

///////////////////////////////////////////////////////////////////
//
// Function name 	: Display
// Description 		: Used to display complete Stack
// Parameters 		: Addreass of First pointer.
// Return Value 	: void
//
///////////////////////////////////////////////////////////////////

template<class T>		
void Stack<T>::Display()
	{
		nodeS<T>*temp = first;
		while(temp != NULL)
		{
			cout<<"|"<<temp-> data<<"|"<<"\n";
			temp = temp -> next;
		}
	}
	
///////////////////////////////////////////////////////////////////
//
// Function name 	: Count
// Description 		: Used to display complete Stack
// Parameters 		: Size.
// Return Value 	: void
//
///////////////////////////////////////////////////////////////////
	
template<class T>
int Stack<T>::Count()
	{
		return size;
	}
	
	
///////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : Queue.
// Input		 : Integer ,float , character.
// Output		 : Integer , float, character.
// Description   : It is Used to store and remove data from linked list.
// Author		 :Divya Harke
//
///////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
class Queue								 //Singly linear linked list
{
private:
	nodeS<T>*first;
	int size;
	
public:
	Queue();
	void Enqueue(T);
	int Dequeue();
	void Display();
	int Count();
	
};

template<class T>
Queue<T>::Queue()
	{
		first =NULL;
		size = 0;
	}

///////////////////////////////////////////////////////////////////
//
// Function name 	: Enqueue
// Description 		: Used to insert data in queue
// Parameters 		: Addreass of First pointer & data of node
// Return Value 	: void
//
///////////////////////////////////////////////////////////////////	

template<class T>		
void Queue<T>::Enqueue(T no)				//InsertLast()
	{
		nodeS<T>*newn = new nodeS<T>;
		newn-> next = NULL;
		newn -> data = no;
			
		if(size == 0)
		{
		first = newn;
		}
		else 
		{
			nodeS<T>*temp = first;
			while(temp -> next != NULL)
			{
				temp =temp -> next;
			}
				temp -> next = newn;
		}
			size++;
	}		
	
///////////////////////////////////////////////////////////////////
//
// Function name 	: Dequeue
// Description 		: Used to Data data from queue
// Parameters 		: Addreass of First pointer & data of node
// Return Value 	: void
//
///////////////////////////////////////////////////////////////////		

template<class T>		
int Queue<T>::Dequeue()					   //DeleteFirst()
	{
		int no = 0;
		nodeS<T>*temp = first;
		if(first == NULL)
		{
			cout<<"Queue is empty\n";
			return -1;
		}
		if(size == 1)
		{
			first = first -> next;
			delete first;
			first = NULL;
		}
		else
		{
			no = first -> data;
			first = first -> next;
			delete temp;
		}
		size--;
			
		return no;
	}

///////////////////////////////////////////////////////////////////
//
// Function name 	: Display
// Description 		: Used to display complete Queue
// Parameters 		: Addreass of First pointer.
// Return Value 	: void
//
///////////////////////////////////////////////////////////////////
		
template<class T>		
void Queue<T>::Display()
	{
		nodeS<T>*temp = first;
		for(int i = 1; i<= size ; i++,temp = temp -> next)
		{
			cout<<"|"<<temp -> data<< "|->";
		}
	cout<<"\n";
				
	}
	
///////////////////////////////////////////////////////////////////
//
// Function name 	: Count
// Description 		: Used to count the nodes of queue
// Parameters 		: Size
// Return Value 	: integer
//
///////////////////////////////////////////////////////////////////
	
template<class T>	
int Queue<T>::Count()
	{
		return size;
	}


int main()
{
	/////////////////////////////////////////////////////////////////////
	// Function Name : Singly Linear Linked List.
	// Input		 : Integer.
	// Output		 : Integer.
	/////////////////////////////////////////////////////////////////////
	SinglyLL <int>iobj;
	cout<<"--------------------------------------------------------------------------------"<<"\n";
	cout<<"Output of Singly Linear Linked List : \n\n";
	cout<<"--------------------------------------------------------------------------------"<<"\n";
	iobj.InsertFirst(21);
	iobj.InsertFirst(11);
	
	iobj.InsertLast(51);
	iobj.InsertLast(101);
	
	iobj.InsertAtPos(75,3);
	iobj.Display();
	
	int iRet = iobj.Count();
	cout<<"Number of elements in SL are : "<<iRet<<"\n";
	
	iobj.DeleteAtPos(3);
	iobj.DeleteFirst();
	iobj.DeleteLast();
	
	iobj.Display();
	
	iRet = iobj.Count();
	cout<<"Number of elements in SL are : "<<iRet<<"\n";
	
	/////////////////////////////////////////////////////////////////////
	// Function Name : Singly Linear Linked List.
	// Input		 : float.
	// Output		 : float.
	/////////////////////////////////////////////////////////////////////
	
	SinglyLL <float>fobj;
	
	fobj.InsertFirst(21.5);
	fobj.InsertFirst(11.5);
	
	fobj.InsertLast(51.5);
	fobj.InsertLast(101.5);
	
	fobj.InsertAtPos(75.5,3);
	fobj.Display();
	
	iRet = fobj.Count();
	cout<<"Number of elements in SL are : "<<iRet<<"\n";
	
	fobj.DeleteAtPos(3);
	fobj.DeleteFirst();
	fobj.DeleteLast();
	
	fobj.Display();
	
	iRet = fobj.Count();
	cout<<"Number of elements in SL are : "<<iRet<<"\n";
	
	///////////////////////////////////////////////////////////////////// 
	// Function Name : Singly Linear Linked List.
	// Input		 : character.
	// Output		 : character.
	/////////////////////////////////////////////////////////////////////
	
	SinglyLL <char>cobj;
	
	cobj.InsertFirst('B');
	cobj.InsertFirst('A');
	
	cobj.InsertLast('C');
	cobj.InsertLast('D');
	
	cobj.InsertAtPos('E',3);
	cobj.Display();
	
	iRet = cobj.Count();
	cout<<"Number of elements in SL are : "<<iRet<<"\n";
	
	cobj.DeleteAtPos(3);
	cobj.DeleteFirst();
	cobj.DeleteLast();
	
	cobj.Display();
	
	iRet = cobj.Count();
	cout<<"Number of elements in SL are : "<<iRet<<"\n\n\n";
	
	/////////////////////////////////////////////////////////////////////
	// Function Name : Singly Circular Linked List.
	// Input		 : Integer.
	// Output		 : Integer.
	/////////////////////////////////////////////////////////////////////
	SinglyCL <int>iCLobj;
	cout<<"--------------------------------------------------------------------------------"<<"\n";
	cout<<"Output of Singly Circular Linked List : \n\n";
	cout<<"--------------------------------------------------------------------------------"<<"\n";
	iCLobj.InsertFirst(21);
	iCLobj.InsertFirst(11);
	
	iCLobj.InsertLast(51);
	iCLobj.InsertLast(101);
	
	iCLobj.InsertAtPos(75,3);
	iCLobj.Display();
	
	iRet = iCLobj.Count();
	cout<<"Number of elements in SCL are : "<<iRet<<"\n";
	
	iCLobj.DeleteAtPos(3);
	iCLobj.DeleteFirst();
	iCLobj.DeleteLast();
	
	iCLobj.Display();
	
	iRet = iCLobj.Count();
	cout<<"Number of elements in SCL are : "<<iRet<<"\n";
	
	/////////////////////////////////////////////////////////////////////
	// Function Name : Singly Circular Linked List.
	// Input		 : float.
	// Output		 : float.
	/////////////////////////////////////////////////////////////////////
	
	SinglyCL <float>fCLobj;
	
	fCLobj.InsertFirst(21.5);
	fCLobj.InsertFirst(11.5);
	
	fCLobj.InsertLast(51.5);
	fCLobj.InsertLast(101.5);
	
	fCLobj.InsertAtPos(75.5,3);
	fCLobj.Display();
	
	iRet = fCLobj.Count();
	cout<<"Number of elements in SCL are : "<<iRet<<"\n";
	
	fCLobj.DeleteAtPos(3);
	fCLobj.DeleteFirst();
	fCLobj.DeleteLast();
	
	fCLobj.Display();
	
	iRet = iCLobj.Count();
	cout<<"Number of elements in SCL are : "<<iRet<<"\n";
	
	///////////////////////////////////////////////////////////////////// 
	// Function Name : Singly Circular Linked List.
	// Input		 : character.
	// Output		 : character.
	/////////////////////////////////////////////////////////////////////
	
	SinglyCL <char>cCLobj;
	
	cCLobj.InsertFirst('B');
	cCLobj.InsertFirst('A');
	
	cCLobj.InsertLast('C');
	cCLobj.InsertLast('D');
	
	cCLobj.InsertAtPos('E',3);
	cCLobj.Display();
	
	iRet = cCLobj.Count();
	cout<<"Number of elements in SCL are : "<<iRet<<"\n";
	
	cCLobj.DeleteAtPos(3);
	cCLobj.DeleteFirst();
	cCLobj.DeleteLast();
	
	cCLobj.Display();
	
	iRet = iCLobj.Count();
	cout<<"Number of elements in SCL are : "<<iRet<<"\n\n\n";
	
	////////////////////////////////////////////////////////////////////
	// Function Name : Doubly Linear Linked List
	// Input		 : Integer 
	// Output		 : Integer
	////////////////////////////////////////////////////////////////////
	
	DoublyLL <int>iDLobj;
	cout<<"--------------------------------------------------------------------------------"<<"\n";
	cout<<"Output of Doubly Linear Linked List : \n\n";
	cout<<"--------------------------------------------------------------------------------"<<"\n";
	iDLobj.InsertFirst(21);
	iDLobj.InsertFirst(11);
	
	iDLobj.InsertLast(51);
	iDLobj.InsertLast(101);
	
	iDLobj.InsertAtPos(75,3);
	iDLobj.Display();
	
	iRet = iDLobj.Count();
	cout<<"Number of elements in DLL are : "<<iRet<<"\n";
	
	iDLobj.DeleteAtPos(3);
	iDLobj.DeleteFirst();
	iDLobj.DeleteLast();
	
	iDLobj.Display();
	
	iRet = iDLobj.Count();
	cout<<"Number of elements in DLL are : "<<iRet<<"\n";
	
	////////////////////////////////////////////////////////////
	// Function Name : Doubly Linear Linked List.
	// Input		 : float.
	// Output		 : float.
	////////////////////////////////////////////////////////////
	
	DoublyLL <float>fDLobj;
	
	fDLobj.InsertFirst(21.5);
	fDLobj.InsertFirst(11.5);
	
	fDLobj.InsertLast(51.5);
	fDLobj.InsertLast(101.5);
	
	fDLobj.InsertAtPos(75.5,3);
	fDLobj.Display();
	
	iRet = fDLobj.Count();
	cout<<"Number of elements in DLL are : "<<iRet<<"\n";
	
	fDLobj.DeleteAtPos(3);
	fDLobj.DeleteFirst();
	fDLobj.DeleteLast();
	
	fDLobj.Display();
	
	iRet = fDLobj.Count();
	cout<<"Number of elements in DLL are : "<<iRet<<"\n";
	
	/////////////////////////////////////////////////////////////////////
	// Function Name : Doubly Linear Linked List.
	// Input		 : character.
	// Output		 : character.
	/////////////////////////////////////////////////////////////////////
	
	DoublyLL <char>cDLobj;
	
	cDLobj.InsertFirst('B');
	cDLobj.InsertFirst('A');
	
	cDLobj.InsertLast('C');
	cDLobj.InsertLast('D');
	
	cDLobj.InsertAtPos('E',3);
	cDLobj.Display();
	
	iRet = cDLobj.Count();
	cout<<"Number of elements in DLL are : "<<iRet<<"\n";
	
	cDLobj.DeleteAtPos(3);
	cDLobj.DeleteFirst();
	cDLobj.DeleteLast();
	
	cDLobj.Display();
	
	iRet = fDLobj.Count();
	cout<<"Number of elements in DLL are : "<<iRet<<"\n\n\n";
	
	////////////////////////////////////////////////////////////////////
	// Function Name : Doubly Circular Linked List
	// Input		 : Integer 
	// Output		 : Integer
	////////////////////////////////////////////////////////////////////
	
	DoublyCL <int>iDCobj;
	cout<<"--------------------------------------------------------------------------------"<<"\n";
	cout<<"Output of Doubly Circular Linked List : \n\n";
	cout<<"--------------------------------------------------------------------------------"<<"\n";
	iDCobj.InsertFirst(21);
	iDCobj.InsertFirst(11);
	
	iDCobj.InsertLast(51);
	iDCobj.InsertLast(101);
	
	iDCobj.InsertAtPos(75,3);
	iDCobj.Display();
	
	iRet = iDCobj.Count();
	cout<<"Number of elements in DCLL are : "<<iRet<<"\n";
	
	iDCobj.DeleteAtPos(3);
	iDCobj.DeleteFirst();
	iDCobj.DeleteLast();
	
	iDCobj.Display();
	
	iRet = iDCobj.Count();
	cout<<"Number of elements in DCLL are : "<<iRet<<"\n";
	
	////////////////////////////////////////////////////////////
	// Function Name : Doubly Circular Linked List.
	// Input		 : float.
	// Output		 : float.
	////////////////////////////////////////////////////////////
	
	DoublyCL <float>fDCobj;
	
	fDCobj.InsertFirst(21.5);
	fDCobj.InsertFirst(11.5);
	
	fDCobj.InsertLast(51.5);
	fDCobj.InsertLast(101.5);
	
	fDCobj.InsertAtPos(75.5,3);
	fDCobj.Display();
	
	iRet = fDCobj.Count();
	cout<<"Number of elements in DCLL are : "<<iRet<<"\n";
	
	fDCobj.DeleteAtPos(3);
	fDCobj.DeleteFirst();
	fDCobj.DeleteLast();
	
	fDCobj.Display();
	
	iRet = iDCobj.Count();
	cout<<"Number of elements in DCLL are : "<<iRet<<"\n";
	
	/////////////////////////////////////////////////////////////////////
	// Function Name : Doubly Circular Linked List.
	// Input		 : character.
	// Output		 : character.
	/////////////////////////////////////////////////////////////////////
	
	DoublyCL <char>cDCobj;
	
	cDCobj.InsertFirst('B');
	cDCobj.InsertFirst('A');
	
	cDCobj.InsertLast('C');
	cDCobj.InsertLast('D');
	
	cDCobj.InsertAtPos('E',3);
	cDCobj.Display();
	
	iRet = cDCobj.Count();
	cout<<"Number of elements in DCLL are : "<<iRet<<"\n";
	
	cDCobj.DeleteAtPos(3);
	cDCobj.DeleteFirst();
	cDCobj.DeleteLast();
	
	cDCobj.Display();
	
	iRet = cDCobj.Count();
	cout<<"Number of elements in DCLL are : "<<iRet<<"\n\n\n";
	
	/////////////////////////////////////////////////////////////////////
	// Function Name : Stack
	// Input		 : Integer.
	// Output		 : Integer.
	/////////////////////////////////////////////////////////////////////
	
	Stack <int>iSobj;
	cout<<"--------------------------------------------------------------------------------"<<"\n";
	cout<<"Output of Stack using Linked List : \n\n";
	cout<<"--------------------------------------------------------------------------------"<<"\n";
	iSobj.push(11);
	iSobj.push(21);
	iSobj.push(51);
	iSobj.push(101);
	
	cout<<"Elements from stack : \n";
	iSobj.Display();
	
	int iret = iSobj.pop();
	cout<<"Poped elelmens is :"<<iret<<"\n";
	
	cout<<"Elemens from stack : \n";
	iSobj.Display();	// 51 21 11
	
	iret = iSobj.Count();
	cout<<"Size of stack : "<<iret<<"\n";
	
	/////////////////////////////////////////////////////////////////////
	// Function Name : Stack
	// Input		 : float.
	// Output		 : float.
	/////////////////////////////////////////////////////////////////////
	
	Stack <float>fSobj;
	
	fSobj.push(11.5);
	fSobj.push(21.5);
	fSobj.push(51.5);
	fSobj.push(101.5);
	
	cout<<"Elements from stack : \n";
	fSobj.Display();
	
	iret = fSobj.pop();
	cout<<"Poped elelmens is :"<<iret<<"\n";
	
	cout<<"Elemens from stack : \n";
	fSobj.Display();	
	
	iret = fSobj.Count();
	cout<<"Size of stack : "<<iret<<"\n";
	
	/////////////////////////////////////////////////////////////////////
	// Function Name : Stack
	// Input		 : character.
	// Output		 : character.
	/////////////////////////////////////////////////////////////////////
	
	Stack <char>cSobj;
	
	cSobj.push('A');
	cSobj.push('B');
	cSobj.push('C');
	cSobj.push('D');
	
	cout<<"Elements from stack : \n";
	cSobj.Display();
	
	iret = cSobj.pop();
	cout<<"Poped elelmens is :"<<iret<<"\n";
	
	cout<<"Elemens from stack : \n";
	cSobj.Display();	
	
	iret = cSobj.Count();
	cout<<"Size of stack : "<<iret<<"\n\n\n";
	
	/////////////////////////////////////////////////////////////////////
	// Function Name : Queue
	// Input		 : Integer.
	// Output		 : Integer.
	/////////////////////////////////////////////////////////////////////
	
	Queue <int>iQobj;
	cout<<"--------------------------------------------------------------------------------"<<"\n";
	cout<<"Output of Queue using Linked List : \n\n";
	cout<<"--------------------------------------------------------------------------------"<<"\n";
	iQobj.Enqueue(11);
	iQobj.Enqueue(21);
	iQobj.Enqueue(51);
	iQobj.Enqueue(101);
	
	cout<<"Elemets of Queue : \n";
	
	iQobj.Display();
	iRet = iQobj.Dequeue();
	cout<<"Removed element from queue : "<<iret<<"\n";
	
	iQobj.Display();	// 51 21 11
	
	iRet = iQobj.Count();
	cout<<"Size of Queue : "<<iret<<"\n";
	
	/////////////////////////////////////////////////////////////////////
	// Function Name : Queue
	// Input		 : float.
	// Output		 : float.
	/////////////////////////////////////////////////////////////////////
	
	Queue <float>fQobj;
	
	fQobj.Enqueue(11.5);
	fQobj.Enqueue(21.5);
	fQobj.Enqueue(51.5);
	fQobj.Enqueue(101.5);
	
	cout<<"Elemets of Queue : \n";
	
	fQobj.Display();
	iRet = fQobj.Dequeue();
	cout<<"Removed element from queue : "<<iret<<"\n";
	
	fQobj.Display();	// 51 21 11
	
	iRet = fQobj.Count();
	cout<<"Size of Queue : "<<iret<<"\n";
	
	/////////////////////////////////////////////////////////////////////
	// Function Name : Queue
	// Input		 : character.
	// Output		 : character.
	/////////////////////////////////////////////////////////////////////
	
	Queue <char>cQobj;
	
	cQobj.Enqueue('A');
	cQobj.Enqueue('B');
	cQobj.Enqueue('C');
	cQobj.Enqueue('D');
	
	cout<<"Elemets of Queue : \n";
	
	cQobj.Display();
	iRet = cQobj.Dequeue();
	cout<<"Removed element from queue : "<<iret<<"\n";
	
	cQobj.Display();	// 51 21 11
	
	iRet = cQobj.Count();
	cout<<"Size of Queue : "<<iret<<"\n\n\n";
	
	
	
	return 0;
}
