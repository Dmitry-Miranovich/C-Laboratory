#include <Windows.h>
#include <stdio.h>
#include <iostream>

using namespace std;

void func(int k, int n = 21, int m = 32) 
{
	cout << n << m << endl;
}


void main()
{
	int k = 5;
	func(k);
}