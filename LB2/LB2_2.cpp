#include <iostream>
using namespace std;
struct node {
	int data;
	node* next;
	node* prev;
};
node* head = NULL;
node* tail = NULL;
void MAKENULL() {
	head = NULL;
	tail = NULL;
}
node* END() {
	return tail;
}
node* FIRST() {
	return head;
}
void INSERT(int x, int pos) {
	node* temp = new node;
	temp->data = x;
	temp->prev = NULL;
	temp->next = NULL;
	if (head == NULL && tail == NULL) {
		head = temp;
		tail = temp;
		return;
	}
	if (pos == 1) {
		temp->next = head;
		head->prev = temp;
		head = temp;
		return;
	}
	node* cur = head;
	for (int i = 1; i < pos - 1; i++) {
		cur = cur->next;
	}
	temp->next = cur->next;
	temp->prev = cur;
	if (cur->next == NULL) {
		tail = temp;
	}
	else {
		cur->next->prev = temp;
	}
	cur->next = temp;
}
void DELETE(int pos) {
	if (head == NULL) {
		cout << "List is empty" << endl;
		return;
	}
	if (pos == 1) {
		node* temp = head;
		head = head->next;
		if (head == NULL) {
			tail = NULL;
		}
		else {
			head->prev = NULL;
		}
		delete temp;
		return;
	}
	node* cur = head;
	for (int i = 1; i < pos; i++) {
		cur = cur->next;
	}
	if (cur == tail) {
		tail = tail->prev;
		tail->next = NULL;
		delete cur;
		return;
	}
	cur->prev->next = cur->next;
	cur->next->prev = cur->prev;
	delete cur;
}
int LOCATE(int x) {
	node* cur = head;
	int pos = 1;
	while (cur != NULL) {
		if (cur->data == x) {
			return pos;
		}
		cur = cur->next;
		pos++;
	}
	return -1; // element not found
}
int RETRIEVE(int pos) {
	node* cur = head;
	for (int i = 1; i < pos; i++) {
		cur = cur->next;
	}
	return cur->data;
}
node* PREVIOUS(node* p) {
	return p->prev;
}
node* NEXT(node* p) {
	return p->next;
}
void PRINTLIST() {
	node* cur = head;
	while (cur != NULL) {
		cout << cur->data << " ";
		cur = cur->next;
	}
	cout << endl;
}
int main() {
	int n, x, pos;
	cout << "Enter number of items: ";
	cin >> n;
	cout << "Enter the items: " << endl;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		INSERT(x, i);
	}
	int choice;
	do {
		cout << "Choose an operation: " << endl;
		cout << "1. MAKENULL" << endl;
		cout << "2. END" << endl;
		cout << "3. FIRST" << endl;
		cout << "4. INSERT" << endl;
		cout << "5. DELETE" << endl;
		cout << "6. LOCATE" << endl;
		cout << "7. RETRIEVE" << endl;
		cout << "8. PREVIOUS" << endl;
		cout << "9. NEXT" << endl;
		cout << "10. PRINTLIST" << endl;
		cout << "0. Exit" << endl;
		cin >> choice;
		switch (choice) {
		case 1:
			MAKENULL();
			cout << "List is now empty" << endl;
			break;
		case 2:
			if (tail == NULL) {
				cout << "List is empty" << endl;
			}
			else {
				cout << "End of the list: " << tail->data << endl;
			}
			break;
		case 3:
			if (head == NULL) {
				cout << "List is empty" << endl;
			}
			else {
				cout << "Beginning of the list: " << head->data << endl;
			}
			break;
		case 4:
			cout << "Enter value and position to insert: ";
			cin >> x >> pos;
			INSERT(x, pos);
			cout << "Element inserted" << endl;
			break;
		case 5:
			cout << "Enter position to delete: ";
			cin >> pos;
			DELETE(pos);
			cout << "Element deleted" << endl;
			break;
		case 6:
			cout << "Enter element to locate: ";
			cin >> x;
			pos = LOCATE(x);
			if (pos == -1) {
				cout << "Element not found" << endl;
			}
			else {
				cout << "Element found at position " << pos << endl;
			}
			break;
		case 7:
			cout << "Enter position to retrieve element from: ";
			cin >> pos;
			x = RETRIEVE(pos);
			cout << "Element at position " << pos << " is " << x << endl;
			break;
		case 8:
			cout << "Enter position of current element: ";
			cin >> pos;
			if (pos == 1) {
				cout << "No previous element" << endl;
			}
			else {
				node* cur = head;
				for (int i = 1; i < pos; i++) {
					cur = cur->next;
				}
				node* prev = PREVIOUS(cur);
				cout << "Previous element is " << prev->data << endl;
			}
			break;
		case 9:
			cout << "Enter position of current element: ";
			cin >> pos;
			if (pos == n) {
				cout << "No next element" << endl;
			}
			else {
				node* cur = head;
				for (int i = 1; i < pos; i++) {
					cur = cur->next;
				}
				node* next = NEXT(cur);
				cout << "Next element is " << next->data << endl;
			}
			break;
		case 10:
			cout << "List contents: ";
			PRINTLIST();
			break;
		case 0:
			cout << "Exiting program" << endl;
			break;
		default:
			cout << "Invalid choice" << endl;
		}
	} while (choice != 0);
	return 0;
}
