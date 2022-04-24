#include<string>
#include<vector>
#include<iostream>
namespace Interpreter {
	class Interpreter {

		public:
			bool simple;
			int addition, subtraction, multiplication, division, pairsofparenthesis, exponent, operators;
			void interpret(std::vector<char>& arr);
	};
	void Interpreter::interpret(std::vector<char>& arr) {
		addition = 0;
		subtraction = 0;
		multiplication = 0;
		division = 0;
		pairsofparenthesis = 0;
		exponent = 0;
		operators = 0;
		int n = 0;
		int index = -1;
		for (char i : arr) {
			switch (i) {
			case '+':
				if (arr[n + 1] == '-') {
					subtraction--;
				}
				addition++;
				operators++;
				n++;
				index = n;
				continue;
			case '-':
				if (arr[n] == '-' && n != index) {
					subtraction--;
				}
				else if (arr[n + 1] == '-') {
					subtraction--;
				}
				subtraction++;
				operators++;
				n++;
				index = n;
				continue;
			case '*':
				if (arr[n + 1] == '-') {
					subtraction--;
				}
				multiplication++;
				operators++;
				n++;
				index = n;
				continue;
			case '/':
				if (arr[n + 1] == '-') {
					subtraction--;
				}
				division++;
				operators++;
				n++;
				index = n;
				continue;
			case '(':
				if (arr[n + 1] == '-') {
					subtraction--;
				}
				pairsofparenthesis++;
				operators += 2;
				n++;
				index = n;
				continue;
			case '^':
				if (arr[n + 1] == '-') {
					subtraction--;
				}
				exponent++;
				operators++;
				n++;
				index = n;
				continue;
			}
			n++;
			index = n;
		}
		if (operators == 1) {
			simple = true;
		}
		else {
			simple = false;
		}
		
		
	}

}
