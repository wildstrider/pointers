#include <iostream>
using namespace std;

#define tab "\t"
//define ������� ���������������� (������)

void Exchange( int& a, int& b);// �������� �������(function declaration)

int main() {
	setlocale(LC_ALL, "ru");
	int a = 2;
	int b = 3;
	
	cout << a << tab << b << endl;
    Exchange(a, b);// ����� �������
	cout << a << tab << b << endl;
}

void Exchange(int& a,int& b)//���������� �������(�����������)
{
	int temp;
	temp = b;
	b = a;
	a = temp;

}