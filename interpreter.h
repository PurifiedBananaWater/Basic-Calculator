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
		for (char i : split) {
			switch (i) {
			case '+':
				addition++;
				operators++;
				continue;
			case '-':
				subtraction++;
				operators++;
				continue;
			case '*':
				multiplication++;
				operators++;
				continue;
			case '/':
				division++;
				operators++;
				continue;
			}
		}
		if (operators == 1) {
			simple = true;
		}
		else {
			simple = false;
		}
		
		
	}

}
