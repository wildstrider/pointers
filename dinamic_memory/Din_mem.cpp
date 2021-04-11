#include <iostream>
using namespace std;
#define tab "\t"
#define COM

void FillRand(int arr[], const int n);
void fillRand(int** arr, int r, int c);
void Print(int arr[], const int n);
void Print(int** arr, int r, int c);

void push_back_rows(int**& arr, int& r, int c);
void push_front_rows(int**& arr, int& r, int c);

int main()
{
	setlocale(LC_ALL, "ru");
#ifndef COM


int n;
	cout << "Введите размер массива: ";
	cin >> n;
	cout << endl;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);
	int value;
	cout << "Введите добавляемое значение: "; cin >> value;
	int* buffer = new int[n + 1]{};
	for (int i = 0; i < n; i++) {

		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;

	arr[n] = value;
	n++;
	Print(arr, n);
	delete[] arr;


#endif 
	int r, c;
	cout << "Введите количество строк: "; cin >> r;
	cout << "Введите количество колонок: "; cin >> c;

	int** arr = new int* [r];

	for (int i = 0; i < r; i++) {

		arr[i] = new int[c];
	}

	fillRand(arr, r, c);
	Print(arr, r, c);
	cout << endl;
	int choice;
	cout << "Введите какую строку добавить." << endl;
	cout << "1 - первую строку."
		"\n2 - последнюю строку" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
		push_front_rows(arr, r, c);
		break;
	case 2:
		push_back_rows(arr, r, c);
	}
	
	Print(arr, r, c);

	for (int i = 0; i < r; i++) {
		delete[] arr[i];
	}
	delete[] arr;
	return 0;
}


void fillRand(int** arr, int r, int c) {

	for (int i = 0; i < r; i++) {

		for (int j = 0; j < c; j++) {

			arr[i][j] = rand() % 50;
		}
		cout << endl;
	}

}
void Print(int** arr, int r, int c) {

	for (int i = 0; i < r; i++) {

		for (int j = 0; j < c; j++) {

			

			cout << arr[i][j] << tab;
		}
		cout << endl;
	}
}
void push_back_rows(int**& arr, int& r, int c)
{
	int rows = r + 1;
	int** buffer = new int* [rows];

	for (int i = 0; i < rows; i++) {

		buffer[i] = new int[c] {};

	}

	for (int i = 0; i < r; i++) {

		for (int j = 0; j < c; j++) {

			buffer[i][j] = arr[i][j];
		}
		cout << endl;
	}
	for (int i = 0; i < r; i++) {
		delete[] arr[i];
	}
	delete[] arr;
	arr = buffer;
	r = rows;

}
void push_front_rows(int**& arr, int& r, int c)
{
	int rows = r + 1;
	int** buffer = new int* [rows] ;

	for (int i = 0; i < rows; i++) {

		buffer[i] = new int[c] {};

	}
	
	int temp = 0;
	for (int i = 0; i < rows; i++) {
		
		for (int j = 0; j < c; j++) {

			if (i != 0) 
				buffer[i][j] = arr[temp][j];
		}
		if (i != 0) {
			temp++;
		}
		cout << endl;
	}

	for (int i = 0; i < r; i++) {
		delete[] arr[i];
	}
	delete[] arr;
	arr = buffer;
	r = rows;

}



void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++) {

		arr[i] = rand() % 100;
	}
}
void Print(int arr[], const int n)
{
 
	for (int i = 0; i < n; i++) {
		
		cout << arr[i] << tab;
	}
	cout << endl;
}