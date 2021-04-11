#include <iostream>
using namespace std;

#define tab "\t"
//define создает макроопределение (макрос)

void Exchange( int& a, int& b);// прототип функции(function declaration)

int main() {
	setlocale(LC_ALL, "ru");
	int a = 2;
	int b = 3;
	
	cout << a << tab << b << endl;
    Exchange(a, b);// вызов функций
	cout << a << tab << b << endl;
}

void Exchange(int& a,int& b)//реализация фунуции(определение)
{
	int temp;
	temp = b;
	b = a;
	a = temp;

}