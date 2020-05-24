#include"Class_Haf.h"
#include<iomanip>
#include<iostream>
#include<string>

using namespace std;

int main() {
	code test;
	string str = "";
	string save = "";
	int save1[255];
	cout << "enter a string" << endl;
	getline(cin, str);
	const int N = 255;
	int counting[N];
	for (int i = 0; i < N; i++) {
		counting[i] = 0;
	}
	test.count(str, counting);
	test.print(str, counting, save, save1);
	cout << "this string takes" << " " << str.length() * 8 << " " << "bit" << endl;
	string testing = test.sort(save, save1);
	test.tree(testing, save1);
	node<trenode<char>>* save5 = nod.Head;

	test.coding(nod.Head, save1);
	test.code_main(nod.Head);
	test.print2(tre2.Head, testing);
	string help = test.finals(tre2.Head, str);
	cout << "final string" << " " << "-" << " " << help << endl;
	cout << "this string takes" << " " << help.length() << " " << "bit" << endl;
}