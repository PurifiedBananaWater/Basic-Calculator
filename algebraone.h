#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<math.h>
#include"basicmath.h"
BasicMath::BasicMath basic;
namespace AlgebraOne {
	class AlgebraOne {
		char alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
			'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y' ,'z'};

		public:
			bool isInAlpha(char var);
			std::string oneLetter(std::vector<char>& arr);
			void simplify(std::vector<char>& arr, int addition, int subtraction, int multiplication,
				int division, int pairsofparenthesis, int exponent, int letters);
	};
	bool AlgebraOne::isInAlpha(char var) {
		var = tolower(var);
		char* exist;
		exist = std::find(alphabet, alphabet + 26, var);
		if (exist != alphabet + 26) {
			return true;
		}
		else {
			return false;
		}
	}

	std::string AlgebraOne::oneLetter(std::vector<char>& arr) {
		std::string answer;
		return answer;
	}

	void AlgebraOne::simplify(std::vector<char>& arr, int addition, int subtraction, int multiplication,
		int division, int pairsofparenthesis, int exponent, int letters) {
		if (letters == 1) {
			//answer = AlgebraOne::oneLetter(arr);
		}
	}

}