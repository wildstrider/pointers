#include <iostream>
using namespace std;
#define tab "\t"

void fill(int** arr, int rows, int cols) {

	for (int i = 0; i < rows; i++) {

		for (int j = 0; j < cols; j++) {

			arr[i][j] = rand() % 100;
		}
	}
}
void print(int** arr, int rows,int cols)
{
	for (int i = 0; i < rows; i++) {

		for (int j = 0; j < cols; j++) {

			cout << arr[i][j] << tab;
		}
		cout << endl;
	}
}
template <typename T> void push_back(T*& arr, int& n)
{
	T* buffer = new T[n]{};
	
	for (int i = 0; i < n-2; i++)
	{
		buffer[i] = arr[i];	
	}
	delete[] arr;
	arr = buffer;
	//n++;

}

void print(int* arr, int rows)
{
	for (int i = 0; i < rows; i++) {
       cout << arr[i] << tab;
	
	}
	cout << endl;
}

void push_cols_back(int**& arr, int rows, int& cols){
	cols+=2;
	for (int i = 0; i < rows; i++) {
       push_back(arr[i], cols);
	}
}
template <typename T> void push_rows_back(T**& arr, int& rows, int& cols)
{
	rows += 2;
	push_back(arr, rows);
    arr[rows-1] = new T[cols] {};
    arr[rows-2] = new T[cols] {};
}

int main() {

	setlocale(LC_ALL, "ru");
	int rows = 5;
	int cols = 5;
	int** arr = new int* [rows];
	for (int i = 0; i < rows; i++) {

		arr[i] = new int[cols];
	}
	//system("pause");
	//int* arr1 = new int[cols] {};
	//print(arr1, cols);
	fill(arr, rows, cols);
	print(arr, rows, cols);
	//push_back(arr1, cols);
	cout << endl;
	push_rows_back(arr, rows, cols);
	push_cols_back(arr, rows, cols);
	//print(arr1, cols);
	print(arr, rows, cols);
	//system("pause");
	for (int i = 0; i < rows; i++) {

		delete[] arr[i];
	}
	delete[] arr;
	return 0;
}