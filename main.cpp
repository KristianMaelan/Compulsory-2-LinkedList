#include "MainDeclarations.h"

int RandomArray[40];
	LinkedList LL1;

void PopulateArray();
void PrintList();

int main()
{
	//Poppulating array and sending the information to the linked list
	PopulateArray();
	for (int i = 0; i < 40; i++)
	{
		//LL1.data = RandomArray[i];
		LL1.AddAtEnd(RandomArray[i]);
	}

	//Compulsory assignment:
	std::cout << "Printing list before execution: " << std::endl;
	LL1.PrintDataForward();

	//1. Add to tail(end of list)
	std::cout << "Adding to end: " << std::endl;
	LL1.AddAtEnd(113);
	//2. Remove
	std::cout << "Removing element: " << std::endl;
	LL1.DeleteElement(5);
	//3. Insert at
	std::cout << "Inserting at:  " << std::endl;
	LL1.AddInMiddle(5, 24);
	//4. Sort function
	std::cout << "Sorting list: " << std::endl;
	LL1.SortList();
	//5. Print / return number of elements in list
	std::cout << "Returning number of elements: " << std::endl;
	std::cout << LL1.ReturnElements() << std::endl;
	//6. Print from head
	std::cout << "Print from head: " << std::endl;
	LL1.PrintDataForward();
	//7. Print from tail
	std::cout << "Print from tail: " << std::endl;
	LL1.PrintDataBackward();
	//8. Pop function(which every time this function is called one item from the end of the list is removed)
	std::cout << "Deletes tail: " << std::endl;
	LL1.DeleteBack();
	//9. Add to head(add to the beginning of the list
	std::cout << "Adds to beginning: " << std::endl;
	LL1.AddInBeginning(27);

	//Print at end
	LL1.PrintDataForward();

	std::cout << "Comp 2 finished running..." << std::endl;
	return 0;
}

void PopulateArray()
{
	std::srand(time(0));
	for (int i = 0; i <= 39; i++)
	{
		RandomArray[i] = rand() % 113;
	}
}

void PrintList()
{
	std::cout << "Print backwards: " << std::endl;
	LL1.PrintDataBackward();

	LL1.DeleteElement(2);
	std::cout << "Print forwards: " << std::endl;

	LL1.PrintDataForward();
}