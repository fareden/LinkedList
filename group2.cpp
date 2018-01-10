// group2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
//this is a code block, everything inside gets tabulations
struct node {
	int number;
	string name;
	node *next;
};
//End of the code block
	bool isEmpty(node *head);
	void menu();
	void insert1(node *&head, node *&last, string name, int number);
	void insertNode(node *&head, node *&last, string name, int number);
	void remove(node *&head);
	void showList(node *current);
	void bubbleSort(struct node *head);
	void swap(struct node *a, struct node *b);

//Function, it is a code block...
bool isEmpty(node *head)
{
	if(head == NULL)	//Next line depends of this, we add spaces
		return true;		
	else	//This line doesn't depend from above
		return false;	//this depends from above line
}
//Code block ends...
//now look: this is an idented function
void menu() {
	cout << "Menu\n" ; //Menu
	cout << "1. Add the patient name.\n" ; //To add patient name
	cout << "2. Add patient number.\n" ; 
	cout << "3. Delete patient data.\n" ; 
	cout << "4. Display patient list.\n" ; 
	cout << "5. Sort by name.\n" ;
	cout << "6. Exit.\n" ; 
	//return choice;
}

//Next function have identation, always is easier to read...
void insertNode(node *&head, string name, int number) { 
	node *temp = new node;
	if(isEmpty(head)) {
		temp->number = number;
		temp->name = name;
		temp->next = NULL;
		head = temp;
	} else {
		temp->number = number;
		temp->name = name;
		temp->next = NULL;
		//We need to find the tail of the list... otherwise we only can have two elements (the new element will repleace the last one)		
		node *p = head;
		//this loop will search the tail, it will follow the list until the next node is null
		while (p->next != NULL)
			p = p->next;
		//now we just put the next element on the tail...
		p->next = temp;
	}
}
void remove(node *&head) {
	if(isEmpty(head))
		cout <<"This is already empty.\n" ;
	else if (head == head) {
		delete head;
		head = NULL;
	} else {
		node *temp = head;
		head = head ->next;
		delete temp;
	}
}
void showList(node *current) {
	if(isEmpty(current))
	cout << "This patient list is empty \n" ; 
	else 
	cout << "The patient list contains : \n" ; 
	while (current->next != NULL) 
	cout << current->number ;
	cout << current->name ;
	current = current-> next;
}

void bubbleSort(struct node *head)
{
    int swapped, i;
    struct node *name = NULL;

 
    /* Checking for empty list */
    if (name == NULL)
        return;
 
    do
    {
        swapped = 0;
        name = head;
 
        while (name->next != name)
        {
            if (name->name > name->next->name)
            { 
                swap(name, name->next);
                swapped = 1;
            }
            name = name->next;
        }
        name = name;
    }
    while (swapped);
}
 
/* function to swap data of two nodes a and b*/
void swap(struct node *a, struct node *b)
{
    string temp = a->name;
    a->name = b->name;
    b->name = temp;
}


int main() {
	node *head = NULL;
	node *last = NULL;	//I think this variable can disapear...
	char choice;
	int number;
	string name;
	int running = 1;
	while (running) {
		menu();
		cin >> choice;
		cin.ignore();
		std::cout << "You selected " << choice << " option\n";
		switch(choice) { 
			case '1': cout <<"Please enter patient name:" ;
			std::getline (std::cin, name);
			cout << "you entered " << name << " to the list\n";
			break;
			case '2': cout <<"Please enter a patient number:" ;
			std::getline (std::cin, name);
			cout << "you entered " << name << " to the list\n";
			//cin >> number;
			break;
			case '3': remove(head);
				cout <<"You have removed the patient data" << choice << "option\n";
			break;
			case '4': showList(head);
				cout <<"All the patient data";
			break;
			case '5': bubbleSort(head) ;
				cout <<"Sort by patient name";
			case '6': 
			cout <<"System exit\n" ;
			running = 0;
			break;

}
		if (name != "" && number > 0) {
			insertNode(head, name, number);
			name = "4";
			number = -1;
		}
	}
	return 0;
}
