#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include"interpreter.h"

Interpreter::Interpreter inter;
namespace BasicMath {
	class BasicMath {
		
		std::string c, nums1, nums2;
		std::vector<char> numinsert;
		double num1 = 0;
		
		public:
			
			double answer;
			void numToCharVec(double numtochars);
			void getNumsSimple(char op);
			void orderOfOperations(int addition, int subtraction, int multiplication, int division);
			void simpleMath(bool simple, int addition, int subtraction, int multiplication, int division);	
		
	};
	void BasicMath::numToCharVec(double numtochars) {
		std::string newstring = std::to_string(numtochars);
		numinsert = {newstring.begin(), newstring.end()};
		
	}
	void BasicMath::getNumsSimple(char op) {
		int i = 0;
		while (inter.split[i] != op) {
			c = (1, inter.split[i]);
			nums1 += c;
			i++;
		}
		i++;
		while (i != inter.split.size()) {
			c = (1, inter.split[i]);
			nums2 += c;
			i++;
		}
	}
	void BasicMath::orderOfOperations(int addition, int subtraction, int multiplication, int division) {
		//std::cout << "A S M D " << addition << " " << subtraction << " " << multiplication << " " << division << "\n";
		int i = 0;
		int index1 = 0;
		int index2 = 0;
		int add = addition;
		int sub = subtraction;
		int mult = multiplication;
		int div = division;
		while (add != 0 || sub != 0 || mult != 0 || div != 0) {
			i = 0;
			for (char elem : inter.split) {
				if (mult > 0 || div > 0) {
					if (elem == '*' || elem == '/') {
						while (i != 0 && inter.split[i - 1] != '+' && inter.split[i - 1] != '-'
							&& inter.split[i - 1] != '*' && inter.split[i - 1] != '/') {
							i--;
							index1 = i;
						}
						while (inter.split[i] != '+' && inter.split[i] != '-' && inter.split[i] != '*' 
							&& inter.split[i] != '/') {
							c = (1, inter.split[i]);
							nums1 += c;
							i++;
						}

						i++;
						while (i != inter.split.size() && inter.split[i] != '+' && inter.split[i] != '-'
							&& inter.split[i] != '*' && inter.split[i] != '/') {
							c = (1, inter.split[i]);
							nums2 += c;
							i++;
							index2 = i;
						}
						switch (elem) {
							case '*':
								num1 = stod(nums1) * stod(nums2);
								inter.split.erase(inter.split.begin() + index1, inter.split.begin() + index2);
								BasicMath::numToCharVec(num1);
								inter.split.insert(inter.split.begin() + index1, numinsert.begin(), numinsert.end());
								mult--;
								i = 0;
								break;
							case '/':
								num1 = stod(nums1) / stod(nums2);
								inter.split.erase(inter.split.begin() + index1, inter.split.begin() + index2);
								BasicMath::numToCharVec(num1);
								inter.split.insert(inter.split.begin() + index1, numinsert.begin(), numinsert.end());
								i = 0;
								div--;
								break;
						}
					}
					nums1 = "";
					nums2 = "";
					i++;
				}
				
				else if (add > 0 || sub > 0) {
					if (elem == '+' || elem == '-') {						
						int n = 0;
						while (i != 0 && inter.split[i - 1] != '+' && inter.split[i - 1] != '-'
							&& inter.split[i - 1] != '*' && inter.split[i - 1] != '/') {
							i--;
							n++;
							index1 = i;
						}
						while (inter.split[i] != '+' && inter.split[i] != '-' && inter.split[i] != '*'
							&& inter.split[i] != '/') {
							c = (1, inter.split[i]);
							nums1 += c;
							i++;
						}
						n = 0;
						i++;
						while (i != inter.split.size() && inter.split[i] != '+' && inter.split[i] != '-'
							&& inter.split[i] != '*' && inter.split[i] != '/') {
							c = (1, inter.split[i]);
							nums2 += c;
							i++;
							index2 = i;
						}
						switch (elem) {
						case '+':
							num1 = stod(nums1) + stod(nums2);
							inter.split.erase(inter.split.begin() + index1, inter.split.begin() + index2);
							BasicMath::numToCharVec(num1);
							inter.split.insert(inter.split.begin() + index1, numinsert.begin(), numinsert.end());
							i = 0;
							add--;
							std::cout << "Add " << num1 << "\n";
							break;

						//Exception thrown because of negative numbers
						case '-':
							std::cout << "Before " << num1 << "\n";
							num1 = stod(nums1) - stod(nums2);
							inter.split.erase(inter.split.begin() + index1, inter.split.begin() + index2);
							BasicMath::numToCharVec(num1);
							inter.split.insert(inter.split.begin() + index1, numinsert.begin(), numinsert.end());
							i = 0;
							sub--;
							std::cout << "Sub " << num1 << "\n";
							break;
						}
					}
					nums1 = "";
					nums2 = "";
					i++;
				}
			}
		}
		answer = num1;
	}
	void BasicMath::simpleMath(bool simple, int addition, int subtraction, int multiplication, int division) {		
		switch (simple) {
			case true:
				if (addition > 0) {
					BasicMath::getNumsSimple('+');
					answer = stod(nums1) + stod(nums2);
				}
				else if (subtraction > 0) {
					BasicMath::getNumsSimple('-');
					answer = stod(nums1) - stod(nums2);	
				}
				else if (multiplication > 0) {
					BasicMath::getNumsSimple('*');
					answer = stod(nums1) * stod(nums2);	
				}
				else if (division > 0) {
					BasicMath::getNumsSimple('/');
					answer = stod(nums1) / stod(nums2);	
				}
				break;
			case false:
				BasicMath::orderOfOperations(addition, subtraction, multiplication, division);
		}
		nums1 = "";
		nums2 = "";
	}
}