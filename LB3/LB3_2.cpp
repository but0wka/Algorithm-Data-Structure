#include <iostream>
#include <Windows.h>
using namespace std;
const int MAX_SIZE = 100;
struct Queue {
	int data[MAX_SIZE];
	int front;
	int rear;
	int size;
};
void MAKENULL(Queue& Q) {
	Q.front = 0;
	Q.rear = MAX_SIZE - 1;
	Q.size = 0;
}
int FRONT(Queue& Q) {
	return Q.data[Q.front];
}
void ENQUEUE(int x, Queue& Q) {
	if (Q.size == MAX_SIZE) {
		cout << "Переповнення черги" << endl;
		return;
	}
	Q.rear = (Q.rear + 1) % MAX_SIZE;
	Q.data[Q.rear] = x;
	Q.size++;
}
void DEQUEUE(Queue& Q) {
	if (Q.size == 0) {
		cout << "Недостатньо елементів у черзі" << endl;
		return;
	}
	Q.front = (Q.front + 1) % MAX_SIZE;
	Q.size--;
}
bool EMPTY(Queue& Q) {
	return Q.size == 0;
}
void PRINT(Queue& Q) {
	if (Q.size == 0) {
		cout << "Черга порожня" << endl;
		return;
	}
	cout << "Черга: ";
	for (int i = Q.front; i <= Q.rear; i = (i + 1) % MAX_SIZE) {
		cout << Q.data[i] << " ";
	}
	cout << endl;
}
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Queue Q;
	int size;
	cout << "Введіть розмір черги: ";
	cin >> size;
	MAKENULL(Q);
	cout << "Введіть елементи черги: ";
	for (int i = 0; i < size; i++) {
		int x;
		cin >> x;
		ENQUEUE(x, Q);
	}
	while (true) {
		int choice;
		cout << endl << "Оберіть операцію:" << endl;
		cout << "1. MAKENULL" << endl;
		cout << "2. FRONT" << endl;
		cout << "3. ENQUEUE" << endl;
		cout << "4. DEQUEUE" << endl;
		cout << "5. EMPTY" << endl;
		cout << "6. PRINT" << endl;
		cout << "0. Вихід" << endl;
		cin >> choice;
		switch (choice) {
		case 0:
			return 0;
		case 1:
			MAKENULL(Q);
			break;
		case 2:
			if (EMPTY(Q)) {
				cout << "Черга порожня" << endl;
			}
			else {
				cout << "Перший елемент: " << FRONT(Q) << endl;
			}
			break;
		case 3:
			int x;
			cout << "Введіть елемент для включення: ";
			cin >> x;
			ENQUEUE(x, Q);
			break;
		case 4:
			DEQUEUE(Q);
			break;
		case 5:
			if (EMPTY(Q)) {
				cout << "Черга порожня" << endl;
			}
			else {
				cout << "Черга не порожня" << endl;
			}
			break;
		case 6:
			PRINT(Q);
			break;
		default:
			cout << "Невірний вибір. Спробуйте ще раз!" << endl;
		}
	}
	return 0;
}
