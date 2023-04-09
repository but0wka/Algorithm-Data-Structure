#include <iostream>
#include <Windows.h>
using namespace std;
struct Stack {
	int* arr;
	int top = -1;
	int capacity;
};
void MAKENULL(Stack& s) {
	s.top = -1;
}
void PUSH(int x, Stack& s) {
	s.top++;
	s.arr[s.top] = x;
}
void POP(Stack& s) {
	if (s.top == -1) {
		cout << "Стек порожній!" << endl;
		return;
	}
	s.top--;
}
int TOP(Stack& s) {
	if (s.top == -1) {
		cout << "Стек порожній!" << endl;
		return -1;
	}
	return s.arr[s.top];
}
bool EMPTY(Stack& s) {
	return s.top == -1;
}
void PRINT(Stack& s) {
	if (s.top == -1) {
		cout << "Стек порожній!" << endl;
		return;
	}
	cout << "Стек: ";
	for (int i = s.top; i >= 0; i--) {
		cout << s.arr[i] << " ";
	}
	cout << endl;
}
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Stack s;
	cout << "Введіть розмірність стеку: ";
	cin >> s.capacity;
	s.arr = new int[s.capacity];
	cout << "Введіть елементи стеку: ";
	for (int i = 0; i < s.capacity; i++) {
		int x;
		cin >> x;
		PUSH(x, s);
	}
	bool exit = false;
	while (!exit) {
		cout << "Оберіть операцію:" << endl;
		cout << "1. MAKENULL" << endl;
		cout << "2. PUSH" << endl;
		cout << "3. POP" << endl;
		cout << "4. TOP" << endl;
		cout << "5. EMPTY" << endl;
		cout << "6. PRINT" << endl;
		cout << "7. Вихід" << endl;
		int choice;
		cin >> choice;
		switch (choice) {
		case 1:
			MAKENULL(s);
			PRINT(s);
			break;
		case 2:
			int x;
			cout << "Введіть елемент: ";
			cin >> x;
			PUSH(x, s);
			PRINT(s);
			break;
		case 3:
			POP(s);
			PRINT(s);
			break;
		case 4:
			cout << "Вершина стеку: " << TOP(s) << endl;
			break;
		case 5:
			cout << "Стек порожній? " << EMPTY(s) << endl;
			break;
		case 6:
			PRINT(s);
			break;
		case 7:
			exit = true;
			break;
		default:
			cout << "Невірний вибір. Спробуйте ще раз!" << endl;
			break;
		}
	}
	delete[] s.arr;
	return 0;
}
