#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include"basicmath.h"



using std::cout;
using std::cin;
using std::string;


int main() {
	BasicMath::BasicMath basic;
	string equation;
	
	while (equation != "Exit") {
		cout << "Calculator: Enter equation below:\n";
		cin >> equation;
		inter.interpret(equation);
		basic.simpleMath(inter.simple, inter.addition, inter.subtraction, inter.multiplication, inter.division);
		if (equation != "Exit") {
			cout << "= " << basic.answer << std::endl;
		}
		inter.split.clear();
	}
	return 0;
}