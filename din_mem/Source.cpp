#include<iostream>
using namespace std;
//#define dinamic_memory3

#define tab "\t"

void FillRand(int arr[], const int n);
void FillRand(int** arr, const int n, const int m);
void Print(int arr[], const int n);
void Print(int** arr, const int n, const int m);

void push_back(int*& arr, int& n, int value);
void push_front(int*& arr, int& n, int value);


void pop_back(int*& arr, int& n);	//������� ������� � ����� �������
void pop_front(int*& arr, int& n);

void erase(int*& arr, int& n);
void insert(int*& arr, int& n, int value, int index);

void push_row_back(int**& arr, int& m, int n);

//#define PUSH_BACK
//#define DYNAMIC_MEMORY1
//#define DYNAMIC_MEMORY2
//#define DINAMIC_MEMORY2
#define DEBUG_ARRAYS
void main()
{
	setlocale(LC_ALL, "");

	//int n;
	//cout << "������� ������ �������: "; cin >> n;
	//int* arr = new int[n] {};
	//FillRand(arr, n);
	//Print(arr, n);
	//int value;	//���������� ��������
	//cout << "������� ����������� ��������: "; cin >> value;
#ifdef PUSH_BACK
	//1) ������� �������� ������ ������� �������:
	int* buffer = new int[n + 1]{};
	//2) �������� ��� �������� �� ��������� ������� � ��������:
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	//3) ����� ���� ��� ������ �����������, �������� ������ ����� �������:
	delete[] arr;
	//4) ��������� ����� � ��������� �� �������� ������:
	arr = buffer;
	//5) � ������ ����� ����� ����� ����� �������� ����� �������� � ����� �������:
	arr[n] = value;
	n++;
#endif  PUSH_BACK
	/*push_back(arr, n, value);
	Print(arr, n);

	cout << "������� ����������� ��������: "; cin >> value;
	push_front(arr, n, value);
	Print(arr, n);



	cout << "�������� ���������� ��������:\n";
	pop_back(arr, n);
	Print(arr, n);
	delete[] arr;*/


#ifdef DINAMIC_MEMORY2
	int m;//���������� �����
	int n; // ���������� ��������� ������
	cout << "������� ���������� �����: "; cin >> m;
	cout << "������� ���������� ��������� �����: "; cin >> n;

	int** arr = new int* [m];

	for (int i = 0; i < m; i++)
	{
		arr[i] = new int[n] {};
	}


	FillRand(arr, m, n);
	Print(arr, m, n);
	push_row_back(arr, m, n);

	for (int i = 0; i < m; i++)
	{
		delete[] arr[i];
	}

	delete[] arr;

#endif // 

#ifdef DEBUG_ARRAYS
	const int n = 5;
	int arr[n] = { 3,5,1,8,4 };


#endif // DEBUG_ARRAYS



	




}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}

void FillRand(int** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}

void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
}

void Print(int** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j] << tab;
		}
		cout << endl;
	}

}

void push_back(int*& arr, int& n, int value)
{
	//1) ������� �������� ������ ������� �������:
	int* buffer = new int[n + 1]{};
	//2) �������� ��� �������� �� ��������� ������� � ��������:
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];	//�������� �������� ��������������
	}
	//3) ����� ���� ��� ������ �����������, �������� ������ ����� �������:
	delete[] arr;
	//4) ��������� ����� � ��������� �� �������� ������:
	arr = buffer;
	//5) � ������ ����� ����� ����� ����� �������� ����� �������� � ����� �������:
	arr[n] = value;
	n++;
}
void push_front(int*& arr, int& n, int value)
{
	int* buffer = new int[n + 1 / �������, ����������� / ]{};
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];	//�������� �������� �� ��������� �� ���� ������� ������
	}
	delete[] arr;
	arr = buffer;
	arr[0] = value;
	n++;
}

void insert(int*& arr, int& n, int value, int index)
{
	int* buffer = new int[n + 1]{};
	for (int i = 0; i < index; i++)
		buffer[i] = arr[i];
	for (int i = 0; i < index; i++)
		buffer[i + 1] = arr[i];
	delete[] arr;
	arr = buffer;
	arr[index] = value;
	n++;
}


void pop_back(int*& arr, int& n)
{
	int* buffer = new int[--n]{};	//�������� ������ ��������� ���������� ���� ������
	//��� ���� ����� ������� ������� �� �������, 
	//� �������� ������ ����� ����������� ��� �������� ����� ����������:
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
}
void pop_front(int*& arr, int& n)
{
	int* buffer = new int[--n]{};
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	arr = buffer;
}

void erase(int*& arr, int& n, int index)
{
	int* buffer = new int[--n]{};
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i < index ? i : i + 1];
	}
	delete[] arr;
	arr = buffer;
}

void push_row_back(int**& arr, int& m, int n) {

	int** buffer = new int* [m + 1];
	for (int i = 0; i < m; i++) {

		buffer[i] = new int[n] {};
	}
	for (int i = 0; i < m; i++) {

		for (int j = 0; j < n; j++) {

			buffer[i][j] = arr[i][j];
		}
	}
	for (int i = 0; i < m; i++) {
		delete[] arr[i];
	}
	delete[] arr;
	arr = buffer;
	m++;
}