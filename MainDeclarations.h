#pragma once
#include <iostream>

class Node
{
public:

	int data;
	Node* Next;
	Node* Previous;
};

class LinkedList : public Node
{
public:
	Node* head;
	Node* tail;

	//LinkedList constructor
	LinkedList()
	{
		head = nullptr;
		tail = nullptr;
		head = tail;
	}
	//Destructor not needed, using free and not delete

	//Adding to list
	//Adds element at beginning
	void AddAtEnd(int data);
	void AddInMiddle(int index, int data);
	void AddInBeginning(int data);

	//Deleting nodes
	//Delete specific element
	void DeleteElement(int index);
	//Deletes tail (Popback)
	void DeleteBack();
	//Deletes duplicate nodes
	void RemoveDuplicates();

	//Information
	//Prints List Backwards and forwards.
	void PrintDataForward();
	void PrintDataBackward();
	//Returns number of elements in list
	int ReturnElements();
	//Sort List
	void SortList();

};

void LinkedList::AddAtEnd(int data)
{
	Node* newNode = new Node();
	newNode->data = data;

	newNode->Next = nullptr;
	newNode->Previous = nullptr;
	
	if (head == nullptr)
	{
		head = newNode;
		tail = head;
	}

	else
	{
		newNode->Previous = tail;
		tail->Next = newNode;
		tail = newNode;
	}
}

inline void LinkedList::AddInMiddle(int index, int data)
{
	if (index == 1)
	{
		AddInBeginning(data);
	}
	else if (index == ReturnElements())
	{
		AddAtEnd(data);
	}
	else if (index > 1 &&  index < ReturnElements())
	{
		
	Node* newNode = new Node();
	newNode->data = data;

	Node* NodePtr = head;
	int indexCheck = 0;
	while (indexCheck < index)
	{
		NodePtr = NodePtr->Next;
		indexCheck++;
	}
		newNode->Next = NodePtr;
		newNode->Previous = NodePtr->Previous;
		NodePtr->Previous->Next = newNode;
		NodePtr->Previous = newNode;
	}

}

void LinkedList::AddInBeginning(int data)
{
	Node* newNode = new Node();
	newNode->data = data;

	newNode->Next = head;
	head = newNode;
}

void LinkedList::DeleteElement(int index)
{
	Node* NodePtr = head;
	int indexCheck = 0;
	while (indexCheck < index)
	{
		
		NodePtr = NodePtr->Next;

		indexCheck++;
	}

	Node* nextNode = NodePtr->Next;
	Node* prevNode = NodePtr->Previous;

	nextNode->Previous = prevNode;
	prevNode->Next = nextNode;

	free(NodePtr);
	
}


void LinkedList::PrintDataForward()
{
	Node* NodePtr = head;

	while (NodePtr != nullptr)
	{
		std::cout << NodePtr->data << " | ";
		NodePtr = NodePtr->Next;
	}
	std::cout << std::endl;
}

void LinkedList::PrintDataBackward()
{
	Node* NodePtr = tail;

	while (NodePtr != nullptr)
	{
		std::cout << NodePtr->data << " | ";
		NodePtr = NodePtr->Previous;
	}
	std::cout << std::endl;
}

int LinkedList::ReturnElements()
{
	Node* temporary = head;

	int num = 0;

	while(temporary != nullptr)
	{
		temporary = temporary->Next;
		num += 1;
	}

	return num;
}

void LinkedList::SortList()
{
	Node* current = head;
	Node* temp = nullptr;


	if(head != nullptr)
	{
		//Loops until the current node is a nullptr. 
		while (current != nullptr)
		{
			temp = current->Next;

			while (temp != nullptr)
			{
				if (current->data > temp->data)
				{
					int a = current->data;
					current->data = temp->data;
					temp->data = a;
				}
				temp = temp->Next;
			}
			current = current->Next;
		}
	}
}

void LinkedList::RemoveDuplicates()
{
	this->SortList();

	Node* NodePtr = head;

	while (NodePtr != tail)
	{
	Node* NodeToCheck = NodePtr->Next;

		if (NodePtr->data == NodeToCheck->data)
		{
			NodePtr->Next = NodeToCheck->Next;
			NodeToCheck->Next->Previous = NodePtr;

			free(NodeToCheck);
		}
		NodePtr = NodePtr->Next;
	}
}

void LinkedList::DeleteBack()
{
	Node* DeleteBack = tail;
	Node* NewBack = DeleteBack->Previous;

	NewBack->Next = nullptr;
	tail = NewBack;

	free(DeleteBack);
}