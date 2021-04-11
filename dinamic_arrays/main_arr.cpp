#include <iostream>

using namespace std;
#define tab "\t"

void fillRand(int arr[], const int n);
void Print(int* arr, const int n);
void main()
{
	setlocale(LC_ALL, "ru");
	int n;
	cout << "Введите размер массива: ";
	// обьявление динамического массива 
	cin >> n;
	cout << endl;
	int* arr = new int[n] {};
	//использование динамического массива
	Print(arr, n);
	fillRand(arr, n);
	Print(arr, n);
	
	//удаление динамического массива
	delete[] arr;
}

void fillRand(int arr[], const int n) {

	for (int i = 0; i < n; i++) {

		*(arr + i) = rand();
	}
}
void Print(int* arr, const int n) {
	for (int i = 0; i < n; i++) {

		cout << arr[i] << tab;
	}
	cout << endl;


}