#include<string>
#include<vector>
#include<iostream>
#include<algorithm>

namespace Interpreter {
	class Interpreter {
		char alphabet[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
			'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y' ,'z' };
		public:
			bool simple;
			int addition, subtraction, multiplication, division, pairsofparenthesis, exponent, operators, letters;
			void countNegatives(std::vector<char>& arr, char firstop, char negativeop);
			void interpret(std::vector<char>& arr);
	};
	void Interpreter::countNegatives(std::vector<char>& arr, char firstop, char negativeop) {
		std::vector<char> negativecount = { firstop, negativeop };
		std::vector<char>::iterator it;
		it = std::search(begin(arr), end(arr), begin(negativecount), end(negativecount));
		while (it != end(arr)) {
			it = std::search(it + 1, end(arr), begin(negativecount), end(negativecount));
			subtraction--;
			operators--;
		}
	}
	void Interpreter::interpret(std::vector<char>& arr) {
		letters = 0;
		addition = std::count(begin(arr), end(arr), '+');
		subtraction = std::count(begin(arr), end(arr), '-');
		multiplication = std::count(begin(arr), end(arr), '*');
		division = std::count(begin(arr), end(arr), '/');
		pairsofparenthesis = std::count(begin(arr), end(arr), '(');
		exponent = std::count(begin(arr), end(arr), '^');
		operators = addition + subtraction + multiplication + division + pairsofparenthesis + exponent;

		
		

		if (arr[0] == '-') {
			subtraction--;
			operators--;
		}
		Interpreter::countNegatives(arr, '+', '-');
		Interpreter::countNegatives(arr, '-', '-');
		Interpreter::countNegatives(arr, '*', '-');
		Interpreter::countNegatives(arr, '/', '-');
		Interpreter::countNegatives(arr, '^', '-');

		simple = (operators <= 1);

		switch (operators) {
		case 0:
			std::string answer = "";
			for (char elem : arr) {
				answer = answer + elem;
			}
			double answer1 = stod(answer);
		}

		for (char i : arr) {
			int lettercount = std::count(alphabet, alphabet + 26, tolower(i));
			if (lettercount > 0) {
				 letters += lettercount;
			}
		}
		
		
		
	}

}
