#include<string>
#include<vector>
#include<iostream>
namespace Interpreter {
	class Interpreter {

		public:
			bool simple;
			std::vector<char> split;
			int addition;
			int subtraction;
			int multiplication;
			int division;
			int operators;
			void interpret(std::string equation);
	};
	void Interpreter::interpret(std::string equation) {
		split = {equation.begin(), equation.end()};
		addition = 0;
		subtraction = 0;
		multiplication = 0;
		division = 0;
		operators = 0;
		int n = 0;
		int index = -1;
		for (char i : split) {
			switch (i) {
			case '+':
				if (split[n + 1] == '-') {
					subtraction--;
					//index = n + 1;
				}
				addition++;
				operators++;
				n++;
				index = n;
				continue;
			case '-':
				if (split[n] == '-' && n != index) {
					subtraction--;
					//index = n;
				}
				else if (split[n + 1] == '-') {
					subtraction--;
				}
				subtraction++;
				operators++;
				n++;
				index = n;
				continue;
			case '*':
				if (split[n + 1] == '-') {
					subtraction--;
					//index = n + 1;
				}
				multiplication++;
				operators++;
				n++;
				index = n;
				continue;
			case '/':
				if (split[n + 1] == '-') {
					subtraction--;
					//index = n + 1;
				}
				division++;
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
