#include <iostream>

using namespace std;
class NodeType {

public:
	NodeType(int = 0);  		// constructor with default value for
								// info field
	int info;                 	// data
	NodeType * nextPtr; 		// pointer to next node in the list

								//All the functions
	void insert(NodeType * &head, int value);
	void deleteFirst(NodeType *&head);
	bool find(NodeType * node, int num);
	void deleteList(NodeType * &head);
	void printList(NodeType * head);
	bool findAndDelete(NodeType * &head, int num);
	double NodeType::average(NodeType *&head);
	double NodeType::sum(NodeType *&head);
};

NodeType::NodeType(int data)
{
	info = data;
	nextPtr = 0;
}

//This Function inserts a node into the linkedlist
void NodeType::insert(NodeType * &head, int value) {
	NodeType * currentPtr = new NodeType; //creates new node
	currentPtr->info = value; //Assigns the value inputed by user to currentPtr->info
	currentPtr->nextPtr = head; //Assigns head to currentPtr -> next
	head = currentPtr; //Assigns currentPtr to head.
}

//This function print all the nodes in the linked list
void NodeType::printList(NodeType * head) {
	if (head == NULL) { //prints "list is empty" if the head pointer is empty
		cout << "list is empty";
	}


	NodeType * temp = head;
	while (temp != NULL) {
		cout << temp->info << " "; //Loops and prints each node every loop
		temp = temp->nextPtr;
	}
}

//This function deletes only the first node in the linked list 
void NodeType::deleteFirst(NodeType * &head) {
	if (head != NULL) {
		NodeType * temp; //temp node that will be set to equal the head
		temp = head;
		head = temp->nextPtr; //Assigns head to the nextPtr
		delete temp; //Deletes the node temp was pointing to.
	}
}

//This function searches for a node inputted by the user
bool NodeType::find(NodeType * head, int num) {

	NodeType * temp = head;

	while (temp != NULL) {
		if (temp->info == num) {
			return true;
		}
		temp = temp->nextPtr; //iterates through list until null or finds node in list
	}
	return false;
}


//This function deletes the entire list
void NodeType::deleteList(NodeType * &head) {
	NodeType * temp = head;
	NodeType * ptrNext;
	while (temp != NULL)
	{
		//cout << temp->info << endl;
		ptrNext = temp->nextPtr;
		delete temp;
		temp = ptrNext;
	}
	head = nullptr; //sets head equal to NULL
	printList(head);
}

double NodeType::average(NodeType *&head) {
	double sum=0;
	double avg = 0;
	int counter = 0;
	
	if (head == NULL) { //prints "list is empty" if the head pointer is empty
		cout << "list is empty";
	}


	NodeType * temp = head;
	while (temp != NULL) {
		
		sum = sum + temp->info;  
		temp = temp->nextPtr;
		counter++;
	}

	avg = sum / counter;
	
	return avg;

}


double NodeType::sum(NodeType *&head) {
	double sum = 0;
	

	if (head == NULL) { //prints "list is empty" if the head pointer is empty
		cout << "list is empty";
	}


	NodeType * temp = head;
	while (temp != NULL) {

		sum = sum + temp->info;  //Loops and prints each node every loop
		temp = temp->nextPtr;
		
	}

	

	return sum;

}

//This function searches for a node to delete then returns if it found the node or not (bool)
bool NodeType::findAndDelete(NodeType * &head, int num) {
	NodeType * temp = head;
	NodeType * prevTemp = NULL;

	while (temp != NULL) {
		if (temp->info == num) { // Checks if the data temp-<info is equal to the number inputted by user
			if (temp == head) { // checks if the temp is the head
				head = temp->nextPtr; //temp next is assigned to head (temp next is the new head)
				temp->nextPtr = NULL;
				delete temp; //deletes it
			}
			else {
				prevTemp->nextPtr = temp->nextPtr; // if not equal to head it assigns temp->next to prevTemp->next and iterates
				temp->nextPtr = NULL;								   //then it deletes the node if found and returns true
				delete temp;
			}
			return true;
		}
		prevTemp = temp;
		temp = temp->nextPtr;
	}

	return false;

}

int main() {

	NodeType * head = NULL;
	NodeType * currentPtr;


	char response;

	int loop = 1;



	do {
		//menu
		cout << endl;
		cout << "Welcome!" << endl;
		cout << "Please enter the letter that represents the function you would like to use: " << endl;
		cout << "I: Insert a node into the linked list " << endl;
		cout << "D: Delete the first node from the linked list " << endl;
		cout << "E: Delete entire linked list" << endl;
		cout << "F: Find and Delete a node from the linked list " << endl;
		cout << "A: Average " << endl;
		cout << "S: Sum " << endl;
		cout << "P: Print " << endl;
		cout << "Q: Quit" << endl;



		cin >> response;

		cout << endl;


		NodeType singlyList;

		//switch for options

		switch (response)
		{
			//This case asks the user to input a node they would like to insert into the linkedlist
		case 'I':
		case 'i': {
			int value;

			cout << "Please enter the digit you would like to enter:  " << endl;
			cin >> value;

			singlyList.insert(head, value);

			break;
		}

				  //This case deletes the first node in the list
		case 'D':
		case 'd': {


			singlyList.deleteFirst(head);

			if (head == NULL) {
				cout << "List is empty" << endl;//If the function returns false it outputs this
			}

			else {
				singlyList.printList(head); //If the function returns true it will output this
			}

			break;

		}

				  //This case deletes the entire linked list 
		case 'e':
		case 'E': {

			singlyList.deleteList(head);
			break;

		}

				  //This case asks the user to input a number they would like to delete in the linked list
		case 'f':
		case 'F': {

			int value;
			cout << "Please enter a digit in the linked list you would like to delete " << endl;
			cin >> value;
			bool val = singlyList.findAndDelete(head, value);
			if (val == 0) {
				cout << "number not found" << endl;  //If the function returns false it outputs this
			}

			else {
				cout << "Number found and deleted:  " << endl; //If the function returns true it will output this
				singlyList.printList(head); //Print the new list with the deleted node
				cout << endl;
			}

			break;
		}

				  //This case asks the user what number they would like to search for
		case 'A':
		case 'a': {

			
			cout << "The average of the numbers you entered is:  " << endl;
			

			cout << singlyList.average(head) << endl;
			

			break;

		}
		case 'S':
		case 's': {


			cout << "The sum of the numbers you entered is:  " << endl;


			cout << singlyList.sum(head) << endl;


			break;

		}

				  //This case prints out the linked list
		case 'P':
		case 'p': {

			singlyList.printList(head);
			cout << endl << endl;

			break;

		}

				  //This case quits the program
		case 'q':
		case 'Q':
		{

			loop = 0;

			break;
		}
		default:
			cout << "That is not a valid option" << endl;
		}
	} while (loop);


}