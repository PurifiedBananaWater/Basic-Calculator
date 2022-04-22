#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
//#include"interpreter.h"
#include"basicmath.h"
//#include"algebraone.h"


using std::cout;
using std::cin;
using std::string;


int main() {
	//Interpreter::Interpreter inter;
	BasicMath::BasicMath basic;
	string equation;

	/*
	std::vector<char> v2{'2', '4','/','4'};
	std::string c;
	std::string nums1, nums2;

	int i = 0;
	while (v2[i] != '/') {
		c = (1, v2[i]);
		nums1 += c;
		std::cout << nums1 << "\n";
		i++;
	}
	i++;
	while (i != v2.size()) {
		c = (1, v2[i]);
		nums2 += c;
		std::cout << nums2 << "\n";
		i++;
	}
	cout << "Answer = " << stod(nums1) / stod(nums2);
	*/
	
	while (equation != "Exit") {
		cout << "Calculator enter equation below:\n";
		cin >> equation;
		inter.interpret(equation);
		cout << "Split size " << inter.split.size() << "\n";
		
		basic.simpleMath(inter.simple, inter.addition, inter.subtraction, inter.multiplication, inter.division);
		cout << "= " << basic.answer << std::endl;
		inter.split.clear();
	}
	return 0;
}