#include<iostream>
#include<string>
#include<vector>
#include<array>
#include<algorithm>
#include <math.h>
#include"interpreter.h"


//Need to implement sqrt



 

Interpreter::Interpreter inter;
namespace BasicMath {
    class BasicMath {
        
        std::string c, nums1, nums2, numinsert, within;
        std::string::iterator right_bracket_it;
        std::string::iterator left_bracket_it;
        double num1 = 0;
        
        public:
            const std::string operator_string = "+-*/^";
            double answer;
            void eraseBrackets(std::string& arr, std::string::iterator left_bracket, std::string::iterator right_bracket);
            void getBracketIts(std::string& arr);
            void getNumsSimple(std::string& arr, char op);
            void parenthesis(std::string& arr, int pairsofparenthesis);
            void exponents(std::string& arr, int exponents);
            void orderOfOperations(std::string& arr, int addition, int subtraction, int multiplication, int division);
            void simpleMath(std::string& arr, bool simple, int addition, int subtraction, int multiplication, 
                int division, int pairsofparenthesis, int exponent);
        
    };
    void BasicMath::eraseBrackets(std::string& arr, std::string::iterator left_bracket_it, std::string::iterator right_bracket_it) {
        arr.erase(left_bracket_it);
        arr.erase(right_bracket_it - 1);
    }
    void BasicMath::getBracketIts(std::string& arr) {
        const std::array<char, 1> leftbracket{ '(' };
        right_bracket_it = find(begin(arr), end(arr), ')');
        left_bracket_it = find_end(begin(arr), right_bracket_it, begin(leftbracket), end(leftbracket));
        
    }
    void BasicMath::getNumsSimple(std::string& arr, char op) {
        std::string::iterator it;
        std::string::iterator opit = find(begin(arr), end(arr), op);
        nums1 = { begin(arr), opit };
        nums2 = { opit + 1, end(arr) };
    }
    void BasicMath::parenthesis(std::string& arr, int pairsofparenthesis) {    
        while (pairsofparenthesis != 0) {
                BasicMath::getBracketIts(arr);
                within.insert(within.begin(), left_bracket_it + 1, right_bracket_it);
                inter.interpret(within);
                BasicMath::exponents(within, inter.exponent);
                inter.interpret(within);
                BasicMath::orderOfOperations(within, inter.addition, inter.subtraction, inter.multiplication, inter.division);
                arr.erase(left_bracket_it + 1, right_bracket_it);
                arr.insert(left_bracket_it + 1, within.begin(), within.end());
                BasicMath::getBracketIts(arr);
                if (left_bracket_it == begin(arr)) {
                    switch (*right_bracket_it) {
                        case ')':
                            if (right_bracket_it + 1 <= end(arr) - 1) {
                                if (std::find(begin(operator_string), end(operator_string), *right_bracket_it) != end(operator_string)) {
                                    if (*right_bracket_it + 1 != *std::find(begin(operator_string), end(operator_string), *right_bracket_it)) {
                                        arr.erase(left_bracket_it);
                                        arr.erase(right_bracket_it + 1);
                                        within.clear();
                                        continue;
                                    }
                                }
                                else {
                                    arr.insert(right_bracket_it + 1, '*');
                                }
                            }
                    }
                    BasicMath::getBracketIts(arr);
                    BasicMath::eraseBrackets(arr, left_bracket_it, right_bracket_it);
                    within.clear();
                    pairsofparenthesis--;
                    continue;
                }
                BasicMath::getBracketIts(arr);
                switch (*(left_bracket_it - 1)) {
                case '+':
                    BasicMath::eraseBrackets(arr, left_bracket_it, right_bracket_it);
                    break;
                case '-':
                    BasicMath::eraseBrackets(arr, left_bracket_it, right_bracket_it);
                    break;
                case '*':
                    BasicMath::eraseBrackets(arr, left_bracket_it, right_bracket_it);
                    break;
                case '/':
                    BasicMath::eraseBrackets(arr, left_bracket_it, right_bracket_it);
                    break;
                case '(':
                    if (*right_bracket_it + 1 != *std::find(begin(operator_string), end(operator_string), *(right_bracket_it + 1))) {
                        arr.insert(right_bracket_it + 1, '*');
                    }

                    BasicMath::eraseBrackets(arr, left_bracket_it, right_bracket_it);
                    break;
                case '^':
                    BasicMath::eraseBrackets(arr, left_bracket_it, right_bracket_it);
                    break;
                default:
                    if (right_bracket_it + 1 != end(arr)) {
                        if(std::find(begin(operator_string), end(operator_string), *(right_bracket_it + 1)) == end(operator_string)) {
                            arr.insert(right_bracket_it + 1, '*');
                        }
                    }
                    BasicMath::eraseBrackets(arr, left_bracket_it, right_bracket_it);
                    arr.insert(left_bracket_it, '*');
                    break;
                }
                within.clear();
                pairsofparenthesis--;
            
        }

        
    }
    void BasicMath::exponents(std::string& arr, int exponent) {
        int index1 = 0;
        int index2 = 0;
        while (exponent != 0) {
            int i = 0;
            int n = 0;
            bool negative = false;

            for (char& elem : arr) {
                if (elem == '^') {
                    while (i != 0 && arr[i - 1] != '+' && arr[i - 1] != '-'
                        && arr[i - 1] != '*' && arr[i - 1] != '/') {
                        i--;
                        index1 = i;
                    }
                    if (i - 1 == 0 && arr[i - 1] == '-') {
                        negative = true;
                        index1 = i - 1;
                    }
                    else if (arr[n + 1] == '-') {
                        negative = true;

                    }
                    while (arr[i] != '+' && arr[i] != '-' && arr[i] != '*'
                        && arr[i] != '/' && arr[i] != '^') {

                        if (i - 1 == 0 && arr[i - 1] == '-' && negative == true) {
                            i = i - 1;
                            negative = false;
                        }
                        else if ((i - 2) > 0 && negative == true) {
                            if (arr[n + 1] == '-' && arr[n] == '+' && arr[n] == '-'
                                && arr[n] == '*' && arr[n] == '/') {
                                i = i - 1;
                                negative = false;
                            }
                        }
                        c = (1, arr[i]);
                        nums1 += c;
                        i++;
                    }
                    if (arr[i + 1] == '-') {
                        negative = true;

                    }

                    i++;
                    while (i != arr.size() && arr[i] != '+' && arr[i] != '-'
                        && arr[i] != '*' && arr[i] != '/' || negative == true) {
                        c = (1, arr[i]);
                        nums2 += c;
                        i++;
                        index2 = i;
                        negative = false;
                    }
                    num1 = pow(stod(nums1), stod(nums2));
                    arr.erase(arr.begin() + index1, arr.begin() + index2);
                    numinsert = std::to_string(num1);
                    arr.insert(arr.begin() + index1, numinsert.begin(), numinsert.end());
                    exponent--;
                    i = 0;
                    n++;
                }
                i++;
                nums1 = "";
                nums2 = "";
            }
        }
    }
    void BasicMath::orderOfOperations(std::string& arr, int addition, int subtraction, int multiplication, int division) {
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
            for (char &elem : arr) {
                broken = false;
                if (mult > 0 || div > 0) {
                    if (elem == '*' || elem == '/') {
                        while (i != 0 && arr[i - 1] != '+' && arr[i - 1] != '-'
                            && arr[i - 1] != '*' && arr[i - 1] != '/') {
                            i--;
                            index1 = i;
                        }
                        if (i - 1 == 0 && arr[i - 1] == '-') {
                            negative = true;
                            index1 = i - 1;	
                        }
                        else if (arr[n + 1] == '-') {
                            negative = true;
                            
                        }
                        while (arr[i] != '+' && arr[i] != '-' && arr[i] != '*' 
                            && arr[i] != '/') {
                        
                            if (i - 1 == 0 && arr[i - 1] == '-' && negative == true) {
                                i = i - 1;
                                negative = false;
                            }
                            else if ((i - 2) > 0 && negative == true) {
                                if (arr[n + 1] == '-' && arr[n] == '+' && arr[n] == '-'
                                    && arr[n] == '*' && arr[n] == '/') {
                                    i = i - 1;
                                    negative = false;
                                }
                            }
                            c = (1, arr[i]);
                            nums1 += c;
                            i++;
                        }
                        if (arr[n + 1] == '-') {
                            negative = true;
                            
                        }
                        i++;
                        while (i != arr.size() && arr[i] != '+' && arr[i] != '-'
                            && arr[i] != '*' && arr[i] != '/' || negative == true) {
                            c = (1, arr[i]);
                            nums2 += c;
                            i++;
                            index2 = i;
                            negative = false;
                        }
                        switch (elem) {
                            case '*':
                                num1 = stod(nums1) * stod(nums2);
                                arr.erase(arr.begin() + index1, arr.begin() + index2);
                                numinsert = std::to_string(num1);
                                arr.insert(arr.begin() + index1, numinsert.begin(), numinsert.end());
                                mult--;
                                i = 0;
                                broken = true;
                                break;
                            case '/':
                                num1 = stod(nums1) / stod(nums2);
                                arr.erase(arr.begin() + index1, arr.begin() + index2);
                                numinsert = std::to_string(num1);
                                arr.insert(arr.begin() + index1, numinsert.begin(), numinsert.end());
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
                        if (n == 0 && arr[n] == '-') {
                            continue;
                        }
                        while (i != 0 && arr[i - 1] != '+' && arr[i - 1] != '-'
                            && arr[i - 1] != '*' && arr[i - 1] != '/') {
                            i--;
                            
                            index1 = i;
                        }
                        if (i == 0 && arr[i] == '-') {
                            negative = true;
                            index1 = i;

                        }
                        else if (i - 1 == 0 && arr[i - 1] == '-') {
                            negative = true;
                            index1 = i - 1;
                        }
                        while (arr[i] != '+' && arr[i] != '-' && arr[i] != '*'
                            && arr[i] != '/' || negative == true) {
                            if (i == 0 && arr[i] == '-' && negative == true) {
                                negative = false;
                            }
                            else if ((i - 2) > 0 && negative == true) {
                                if (arr[n + 1] == '-' && arr[n] == '+' && arr[n] == '-'
                                    && arr[n] == '*' && arr[n] == '/') {
                                    i = i - 1;
                                    negative = false;
                                }
                            }
                            else if (i - 1 == 0 && arr[i - 1] == '-' && negative == true) {
                                i = i - 1;
                                negative = false;
                            }
                            c = (1, arr[i]);
                            nums1 += c;
                            i++;
                        }
                        if (arr[i + 1] == '-') {
                            negative = true;
                        }
                        opindx = i;
                        i++;
                        while (i != arr.size() && arr[i] != '+' && arr[i] != '-'
                            && arr[i] != '*' && arr[i] != '/' || negative == true) {
                            c = (1, arr[i]);
                            nums2 += c;
                            i++;
                            index2 = i;
                            negative = false;
                        }
                        switch (elem) {
                        case '+':
                            num1 = stod(nums1) + stod(nums2);
                            arr.erase(arr.begin() + index1, arr.begin() + index2);
                            numinsert = std::to_string(num1);
                            arr.insert(arr.begin() + index1, numinsert.begin(), numinsert.end());
                            i = 0;
                            add--;
                            broken = true;
                            break;
                        case '-':
                            if (elem == arr[0] && opindx == 0) {
                                i = 0;
                                broken = true;
                                break;
                            }
                            num1 = stod(nums1) - stod(nums2);
                            arr.erase(arr.begin() + index1, arr.begin() + index2);
                            numinsert = std::to_string(num1);
                            arr.insert(arr.begin() + index1, numinsert.begin(), numinsert.end());
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
    void BasicMath::simpleMath(std::string& arr, bool simple, int addition, int subtraction, 
        int multiplication, int division, int pairsofparenthesis, int exponent) {
        switch (simple) {
            case true:
                if (addition > 0) {
                    BasicMath::getNumsSimple(arr, '+');
                    answer = stod(nums1) + stod(nums2);
                }
                else if (subtraction > 0) {
                    BasicMath::getNumsSimple(arr, '-');
                    answer = stod(nums1) - stod(nums2);	
                }
                else if (multiplication > 0) {
                    BasicMath::getNumsSimple(arr, '*');
                    answer = stod(nums1) * stod(nums2);	
                }
                else if (division > 0) {
                    BasicMath::getNumsSimple(arr, '/');
                    answer = stod(nums1) / stod(nums2);	
                }
                else if (exponent > 0) {
                    BasicMath::getNumsSimple(arr, '^');
                    answer = pow(stod(nums1), stod(nums2));
                }
                else if (pairsofparenthesis > 0) {
                    BasicMath::parenthesis(arr, inter.pairsofparenthesis);
                    inter.interpret(arr);
                    simpleMath(arr, inter.simple, inter.addition, inter.subtraction,
                        inter.multiplication, inter.division, inter.pairsofparenthesis, inter.exponent);
                }
                else {
                    std::string num = "";
                    for (char elem : arr) {
                        num = num + elem;
                    }
                    answer = stod(num);
                }
                break;
            case false:
                BasicMath::parenthesis(arr, inter.pairsofparenthesis);
                inter.interpret(arr);
                BasicMath::exponents(arr, inter.exponent);
                inter.interpret(arr);
                BasicMath::orderOfOperations(arr, inter.addition, inter.subtraction, inter.multiplication, inter.division);
        }
        nums1 = "";
        nums2 = "";
    }
}
