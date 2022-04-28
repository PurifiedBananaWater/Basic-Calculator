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
	
	while (equation != "Exit") {
		cout << "Calculator: Enter equation below:\n";
		cin >> equation;
		if (equation != "Exit") {
			if (equation == "Simplify") {
				cin >> expression;
				//cout << "Add expression to simplify below:\n";

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
		
	}
	return 0;
}