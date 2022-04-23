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
		int i = 0;
		int index1 = 0;
		int index2 = 0;
		int opindx;
		int add = addition;
		int sub = subtraction;
		int mult = multiplication;
		int div = division;
		bool broken = false;
		bool negative = false;
		while (add != 0 || sub != 0 || mult != 0 || div != 0) {
			i = 0;
			int n = 0;
			for (char &elem : inter.split) {
				broken = false;
				if (mult > 0 || div > 0) {
					if (elem == '*' || elem == '/') {
						while (i != 0 && inter.split[i - 1] != '+' && inter.split[i - 1] != '-'
							&& inter.split[i - 1] != '*' && inter.split[i - 1] != '/') {
							i--;
							index1 = i;
						}
						if (i - 1 == 0 && inter.split[i - 1] == '-') {
							negative = true;
							index1 = i - 1;	
						}
						else if (inter.split[n + 1] == '-') {
							negative = true;
							
						}
						
						while (inter.split[i] != '+' && inter.split[i] != '-' && inter.split[i] != '*' 
							&& inter.split[i] != '/') {
						
							if (i - 1 == 0 && inter.split[i - 1] == '-' && negative == true) {
								i = i - 1;
								negative = false;
							}
							else if ((i - 2) > 0 && negative == true) {
								if (inter.split[n + 1] == '-' && inter.split[n] == '+' && inter.split[n] == '-'
									&& inter.split[n] == '*' && inter.split[n] == '/') {
									i = i - 1;
									negative = false;
								}
							}
							c = (1, inter.split[i]);
							nums1 += c;
							i++;
						}

						if (inter.split[n + 1] == '-') {
							negative = true;
							
						}

						i++;
						while (i != inter.split.size() && inter.split[i] != '+' && inter.split[i] != '-'
							&& inter.split[i] != '*' && inter.split[i] != '/' || negative == true) {
							c = (1, inter.split[i]);
							nums2 += c;
							i++;
							index2 = i;
							negative = false;
						}
						switch (elem) {
							case '*':
								num1 = stod(nums1) * stod(nums2);
								inter.split.erase(inter.split.begin() + index1, inter.split.begin() + index2);
								BasicMath::numToCharVec(num1);
								inter.split.insert(inter.split.begin() + index1, numinsert.begin(), numinsert.end());
								mult--;
								i = 0;
								broken = true;
								break;
							case '/':
								num1 = stod(nums1) / stod(nums2);
								inter.split.erase(inter.split.begin() + index1, inter.split.begin() + index2);
								BasicMath::numToCharVec(num1);
								inter.split.insert(inter.split.begin() + index1, numinsert.begin(), numinsert.end());
								i = 0;
								broken = true;
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
						if (n == 0 && inter.split[n] == '-') {
							continue;
						}
						while (i != 0 && inter.split[i - 1] != '+' && inter.split[i - 1] != '-'
							&& inter.split[i - 1] != '*' && inter.split[i - 1] != '/') {
							i--;
							
							index1 = i;
						}
						if (i == 0 && inter.split[i] == '-') {
							negative = true;
							index1 = i;

						}
						else if (i - 1 == 0 && inter.split[i - 1] == '-') {
							negative = true;
							index1 = i - 1;
						}
						while (inter.split[i] != '+' && inter.split[i] != '-' && inter.split[i] != '*'
							&& inter.split[i] != '/' || negative == true) {
							if (i == 0 && inter.split[i] == '-' && negative == true) {
								negative = false;
							}
							else if ((i - 2) > 0 && negative == true) {
								if (inter.split[n + 1] == '-' && inter.split[n] == '+' && inter.split[n] == '-'
									&& inter.split[n] == '*' && inter.split[n] == '/') {
									i = i - 1;
									negative = false;
								}
							}
							else if (i - 1 == 0 && inter.split[i - 1] == '-' && negative == true) {
								i = i - 1;
								negative = false;
							}
							c = (1, inter.split[i]);
							nums1 += c;
							i++;
						}
						if (inter.split[i + 1] == '-') {
							negative = true;
						}
						opindx = i;
						i++;
						while (i != inter.split.size() && inter.split[i] != '+' && inter.split[i] != '-'
							&& inter.split[i] != '*' && inter.split[i] != '/' || negative == true) {
							c = (1, inter.split[i]);
							nums2 += c;
							i++;
							index2 = i;
							negative = false;
						}
						switch (elem) {
						case '+':
							num1 = stod(nums1) + stod(nums2);
							inter.split.erase(inter.split.begin() + index1, inter.split.begin() + index2);
							BasicMath::numToCharVec(num1);
							inter.split.insert(inter.split.begin() + index1, numinsert.begin(), numinsert.end());
							i = 0;
							add--;
							broken = true;
							break;
						case '-':
							if (elem == inter.split[0] && opindx == 0) {
								i = 0;
								broken = true;
								break;
							}
							num1 = stod(nums1) - stod(nums2);
							inter.split.erase(inter.split.begin() + index1, inter.split.begin() + index2);
							BasicMath::numToCharVec(num1);
							inter.split.insert(inter.split.begin() + index1, numinsert.begin(), numinsert.end());
							i = 0;
							if (sub != 0) {
								sub--;
							}
							broken = true;
							break;
						}
					}
					nums1 = "";
					nums2 = "";
					i++;
					
				}
				if(broken == true){
					break;
				}
				n++;
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
