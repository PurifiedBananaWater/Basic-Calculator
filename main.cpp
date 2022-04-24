#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include"basicmath.h"



using std::cout;
using std::cin;
using std::string;
using std::vector;


int main() {
	BasicMath::BasicMath basic;
	string equation;
	
	while (equation != "Exit") {
		cout << "Calculator: Enter equation below:\n";
		cin >> equation;
		if (equation != "Exit") {
			vector<char> split = { equation.begin(), equation.end() };
			inter.interpret(split);
			basic.simpleMath(split, inter.simple, inter.addition, inter.subtraction, 
				inter.multiplication, inter.division, inter.pairsofparenthesis, inter.exponent);
		
			cout << "= " << basic.answer << std::endl;
			split.clear();
		}
		
	}
	return 0;
}