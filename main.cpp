#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include"algebraone.h"




using std::cout;
using std::cin;
using std::string;
using std::vector;


int main() {
	AlgebraOne::AlgebraOne alg1;
	string equation;
	string expression;
	cout << "Type ^/ for square root i.e ^/4 = 2 or ^/(100+44) = 12\n";
	cout << "An equation with square root 2(^/4) = 4\n\n";
	cout << "Type Simplify (expression) to simplify expression.\n";
	cout << "i.e Simplify 5x+3=13   x = 2\n\n";
	cout << "Calculator: Enter equation below:\n";
	while (equation != "Exit") {
		cout << "Calculator: Enter equation below:\n";
		cin >> equation;
		if (equation != "Exit") {
			if (equation == "Simplify") {
				cin >> expression;
				inter.interpret(expression);
				alg1.simplify(expression, inter.addition, inter.subtraction,
					inter.multiplication, inter.division, inter.pairsofparenthesis, inter.exponent, inter.letters);
				cout << alg1.answer << std::endl;
			}
			else {
				inter.interpret(equation);
				basic.simpleMath(equation, inter.simple, inter.addition, inter.subtraction,
					inter.multiplication, inter.division, inter.pairsofparenthesis, inter.exponent);
				cout << "= " << basic.answer << std::endl;
			}
		}
		cout << std::endl;
		
	}
	return 0;
}