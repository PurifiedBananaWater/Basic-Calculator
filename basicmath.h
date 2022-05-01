#include<iostream>
#include<string>
#include<vector>
#include<array>
#include<algorithm>
#include <math.h>
#include <iterator>
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
            auto isInOpString(char elem);
            void eraseBrackets(std::string& arr, std::string::iterator left_bracket, std::string::iterator right_bracket);
            void getBracketIts(std::string& arr);
            void getNumsSimple(std::string& arr, char op);
            void parenthesis(std::string& arr, int pairsofparenthesis);
            void exponents(std::string& arr, int exponents);
            void orderOfOperations(std::string& arr, int addition, int subtraction, int multiplication, int division);
            void simpleMath(std::string& arr, bool simple, int addition, int subtraction, int multiplication, 
                int division, int pairsofparenthesis, int exponent);
        
    };
    auto BasicMath::isInOpString(char elem) {
        char character = *find(begin(operator_string), end(operator_string), elem);
        return elem == character;
    }
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
        std::string::iterator it1, it2, it3;
        std::string::reverse_iterator r_it1;
        while (exponent != 0) {
            auto ops = operator_string;
            if (std::find(begin(arr), end(arr), '^') != end(arr)) {
                it1 = begin(arr);
                it2 = std::find(begin(arr), end(arr), '^');
                it3 = it2 + 1;
                r_it1 = std::make_reverse_iterator(find(begin(arr), end(arr), '^'));
                auto r_is_in_opstring = [ops,&r_it1](char elem) mutable {
                    r_it1++;
                    if (std::find(begin(ops), end(ops), elem) != end(ops)) {
                        return elem == *(std::find(begin(ops), end(ops), elem));
                    }};
                auto is_in_opstring = [ops, &it3](char elem) mutable {
                    it3++;
                    if (std::find(begin(ops), end(ops), elem) != end(ops)) {
                        return elem == *(std::find(begin(ops), end(ops), elem));
                    }};

                
                if (std::find_if(r_it1, rend(arr), r_is_in_opstring) != rend(arr)) {
                    it1 = (r_it1 - 1).base();
                }
                
                if (*(begin(arr)) == '-' && it1 - 1 == begin(arr)) {
                    it1 = it1 - 1;
                }

                nums1 = {it1, it2};
                it3 = std::find_if(it2 + 1, end(arr), is_in_opstring);

                if (it3 == end(arr)) {
                    nums2 = { (it2 + 1), (it3) };
                }
                else {
                    nums2 = { (it2 + 1), (it3 + 1) };
                }  
                num1 = pow(stod(nums1), stod(nums2));
                arr.erase(it1 , it3);
                numinsert = std::to_string(num1);
                arr.insert(it1, numinsert.begin(), numinsert.end());
                exponent--;
                nums1 = "";
                nums2 = "";
            }
        }
    }
    void BasicMath::orderOfOperations(std::string& arr, int addition, int subtraction, int multiplication, int division) {
        std::string::iterator it1, it2, it3;
        std::string::reverse_iterator r_it1;
        auto ops = operator_string;
        while (addition != 0 || subtraction != 0 || multiplication != 0 || division != 0) {
            it1 = begin(arr);
            auto mult_or_div = [](char elem) mutable {
                    switch (elem) {
                        case '*':
                            return true;
                        case '/':
                            return true;
                        default:
                            return false;
                    }};
            auto add_or_sub = [](char elem) mutable {
                switch (elem) {
                    case '+':
                        return true;
                    case '-':
                        return true;
                    default:
                        return false;
                    }};
            auto is_in_opstring = [ops](char elem) mutable {
                if (std::find(begin(ops), end(ops), elem) != end(ops)) {
                    return elem == *(std::find(begin(ops), end(ops), elem));
                }
                else {
                    return false;
                }
                };
            if (std::find_if(begin(arr), end(arr), mult_or_div) != end(arr)) {
                it2 = std::find_if(begin(arr), end(arr), mult_or_div);
                it3 = it2 + 1;
                if (*begin(arr) == '-') {
                    it1 = begin(arr);
                }
                else if (*(r_it1.base() + 1) == '-') {
                    it1 = (r_it1.base() + 1);
                }
                nums1 = {it1, it2};

                it3 = find_if(it3, end(arr), is_in_opstring);

                nums2 = { (it2 + 1), (it3) };

                switch (*it2) {
                    case '*':
                        num1 = stod(nums1) * stod(nums2);
                        arr.erase(it1, it3);
                        numinsert = std::to_string(num1);
                        arr.insert(it1, numinsert.begin(), numinsert.end());
                        multiplication--;
                        continue;
                    case '/':
                        num1 = stod(nums1) / stod(nums2);
                        arr.erase(it1, it3);
                        numinsert = std::to_string(num1);
                        arr.insert(it1, numinsert.begin(), numinsert.end());
                        division--;
                        continue;
                }
            }
            else if(std::find_if(begin(arr), end(arr), add_or_sub) != end(arr)) {
                it2 = std::find_if(begin(arr), end(arr), add_or_sub);
                it3 = it2 + 1;

                if (*begin(arr) == '-') {
                    it1 = begin(arr);
                    it2 = std::find_if(begin(arr) + 1, end(arr), add_or_sub);
                    
                }
                else if (*(it3) == '-') {
                    
                    it3 = it3 + 1;   
                }
                nums1 = { it1, it2 };
                it3 = find_if(it3, end(arr), is_in_opstring);
                nums2 = { (it2 + 1), (it3) };
                switch (*it2) {
                    case '+':
                        num1 = stod(nums1) + stod(nums2);
                        arr.erase(it1, it3);
                        numinsert = std::to_string(num1);
                        arr.insert(it1, numinsert.begin(), numinsert.end());
                        addition--;
                        continue;
                    case '-':
                        num1 = stod(nums1) - stod(nums2);
                        arr.erase(it1, it3);
                        numinsert = std::to_string(num1);
                        arr.insert(it1, numinsert.begin(), numinsert.end());
                        subtraction--;
                        continue;
                }
            }
        }
        answer = num1;
    }
    void BasicMath::simpleMath(std::string& arr, bool simple, int addition, int subtraction, 
        int multiplication, int division, int pairsofparenthesis, int exponent) {
        std::string::iterator it1 = begin(arr);
        std::string::iterator it2 = end(arr);
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
                    std::string num;
                    num = { it1, it2 };
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
