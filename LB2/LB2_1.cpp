#include <iostream>
using namespace std;
struct Node {
	int data;
	Node* next;
};
Node* head = NULL; // початок списку
// MAKENULL - створює порожній список
void MAKENULL() {
	head = NULL;
}
// END - повертає кінець списку
Node* END() {
	Node* p = head;
	while (p && p->next) {
		p = p->next;
	}
	return p;
}
// FIRST - повертає початок списку
Node* FIRST() {
	return head;
}
// INSERT - додає елемент до списку в задану позицію
void INSERT(int value, int pos) {
	Node* newNode = new Node;
	newNode->data = value;
	newNode->next = NULL;
	if (pos == 1) {
		newNode->next = head;
		head = newNode;
	}
	else {
		Node* prev = head;
		for (int i = 1; i < pos - 1 && prev; i++) {
			prev = prev->next;
		}
		if (prev) {
			newNode->next = prev->next;
			prev->next = newNode;
		}
	}
}
// DELETE - видаляє елемент з списку
void DELETE(int pos) {
	if (head) {
		if (pos == 1) {
			Node* temp = head;
			head = head->next;
			delete temp;
		}
		else {
			Node* prev = head;
			for (int i = 1; i < pos - 1 && prev->next; i++) {
				prev = prev->next;
			}
			if (prev->next) {
				Node* temp = prev->next;
				prev->next = prev->next->next;
				delete temp;
			}
		}
	}
}
// LOCATE - знаходить позицію елементу в списку
int LOCATE(int value) {
	Node* p = head;
	int pos = 1;
	while (p) {
		if (p->data == value) {
			return pos;
		}
		pos++;
		p = p->next;
	}
	return -1;
}
// RETRIEVE - повертає значення елементу списку
int RETRIEVE(int pos) {
	Node* p = head;
	int i = 1;
	while (p && i < pos) {
		p = p->next;
		i++;
	}
	if (p) {
		return p->data;
	}
	return -1;
}
// NEXT - повертає вказівник на наступний елемент списку
Node* NEXT(Node* p) {
	if (p) {
		return p->next;
	}
	return NULL;
}
void PRINTLIST() {
	Node* p = head;
	cout << "List: ";
	while (p) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}
int main() {
	int n;
	cout << "Enter number of elements in the list: ";
	cin >> n;
	// додавання елементів до списку
	for (int i = 0; i < n; i++) {
		int value;
		cout << "Enter element " << i + 1 << ": ";
		cin >> value;
		INSERT(value, i + 1);
	}
	// тестування операцій
	while (true) {
		cout << "\nSelect an operation to perform:" << endl;
		cout << "1. MAKENULL" << endl;
		cout << "2. END" << endl;
		cout << "3. FIRST" << endl;
		cout << "4. INSERT" << endl;
		cout << "5. DELETE" << endl;
		cout << "6. LOCATE" << endl;
		cout << "7. RETRIEVE" << endl;
		cout << "8. NEXT" << endl;
		cout << "8. PRINTLIST" << endl;
		cout << "0. Exit" << endl;
		int choice;
		cin >> choice;
		switch (choice) {
		case 1:
			MAKENULL();
			cout << "List is now empty" << endl;
			break;
		case 2: {
			Node* last = END();
			if (last) {
				cout << "Last element in the list is: " << last->data <<
					endl;
			}
			else {
				cout << "List is empty" << endl;
			}
			break;
		}
		case 3: {
			Node* first = FIRST();
			if (first) {
				cout << "First element in the list is: " << first->data
					<< endl;
			}
			else {
				cout << "List is empty" << endl;
			}
			break;
		}
		case 4: {
			int value, pos;
			cout << "Enter value to insert: ";
			cin >> value;
			cout << "Enter position to insert: ";
			cin >> pos;
			INSERT(value, pos);
			cout << "Element inserted successfully" << endl;
			break;
		}
		case 5: {
			int pos;
			cout << "Enter position of element to delete: ";
			cin >> pos;
			DELETE(pos);
			cout << "Element deleted successfully" << endl;
			break;
		}
		case 6: {
			int value;
			cout << "Enter value to locate: ";
			cin >> value;
			int pos = LOCATE(value);
			if (pos == -1) {
				cout << "Element not found in the list" << endl;
			}
			else {
				cout << "Element found at position " << pos << endl;
			}
			break;
		}
		case 7: {
			int pos;
			cout << "Enter position of element to retrieve: ";
			cin >> pos;
			int value = RETRIEVE(pos);
			if (value == -1) {
				cout << "Invalid position or list is empty" << endl;
			}
			else {
				cout << "Element retrieved: " << value << endl;
			}
			break;
		}
		case 8: {
			int pos;
			cout << "Enter position of element to get next element: ";
			cin >> pos;
			Node* p = head;
			for (int i = 1; i < pos && p; i++) {
				p = p->next;
			}
			if (p && p->next) {
				cout << "Next element is: " << p->next->data << endl;
			}
			else {
				cout << "Invalid position or no next element" << endl;
			}
			break;
		}
		case 9: {
			PRINTLIST();
			break;
		}
		case 0:
			cout << "Invalid choice, please enter a valid option!\n";
			break;
		}
	}
	return 0;
}
