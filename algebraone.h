#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<math.h>
#include<numeric>
#include <functional>
#include"basicmath.h"
BasicMath::BasicMath basic;
namespace AlgebraOne {
    
    class AlgebraOne {
        private:
            const std::string alphabet = "abcdefghijklmnopqrstuvwxyz";

        public:
            std::string answer;
            bool isInAlpha(char var);
            auto alphaIt(std::string& arr);
            void getIts(std::string& arr, std::string::iterator& letter_it, std::string::iterator& equal_it,
                std::string::iterator& op_before_x, std::string::iterator& op_after_x, std::string::reverse_iterator& r_it1);
            void quickSolve(std::string& side);
            void combineSides(std::string& arr, std::string::iterator& equalt_it, std::string::iterator& letter_it,
                std::string::iterator& op_before_x, std::string::iterator& op_after_x, std::string::reverse_iterator& r_it1);
            void oneLetter(std::string& arr);
            void simplify(std::string& arr, int addition, int subtraction, int multiplication,
                int division, int pairsofparenthesis, int exponent, int letters);
    };
    
    bool AlgebraOne::isInAlpha(char var) {
        var = tolower(var);
        int inalpha;
        inalpha = std::count(begin(alphabet), end(alphabet), tolower(var));
        if (inalpha != 0) {
            return true;
        }

        else {
            return false;
        }
    }
    auto AlgebraOne::alphaIt(std::string& arr) {
        std::string::iterator itletter;
        std::string alpha = alphabet;
        itletter = find_if(begin(arr), end(arr), [alpha](char elem) mutable {
            if (std::find(begin(alpha), end(alpha), elem) != end(alpha)) {
                return elem == *(std::find(begin(alpha), end(alpha), elem));
            }
            else { return false; }
            });
        return itletter;
    }
    void AlgebraOne::getIts(std::string& arr, std::string::iterator& letter_it, std::string::iterator& equal_it,
        std::string::iterator& op_before_x, std::string::iterator& op_after_x, std::string::reverse_iterator& r_it1) {
        equal_it = find(begin(arr), end(arr), '=');
        letter_it = AlgebraOne::alphaIt(arr);
        r_it1 = std::make_reverse_iterator(letter_it);
        r_it1 = std::find_if(r_it1, rend(arr), basic.lmbda.r_is_in_opstring);
        if (r_it1 != rend(arr)){ op_before_x = r_it1.base() - 1; }
        else { op_before_x = r_it1.base(); }
        op_after_x = std::find_if(letter_it, end(arr), basic.lmbda.is_in_opstring);
    }
    void AlgebraOne::quickSolve(std::string& side) {
        inter.interpret(side);
        basic.simpleMath(side, inter.simple, inter.addition, inter.subtraction,
            inter.multiplication, inter.division, inter.pairsofparenthesis, inter.exponent);
        side = std::to_string(basic.answer);
    } 
    
    void AlgebraOne::combineSides(std::string& arr, std::string::iterator& equal_it, std::string::iterator& letter_it,
        std::string::iterator& op_before_x, std::string::iterator& op_after_x, std::string::reverse_iterator& r_it1) {
        std::string firstnum, secondnum;

        char before_num_op;
        std::string x_nums = "";
        double x_num;
        bool left = false;
        answer = "";

        if (letter_it < equal_it) {
            left = true;
            switch (*(letter_it + 1)) {
            case '=':
                before_num_op = *(begin(arr));
                if (op_before_x != begin(arr)) {
                    switch (*op_before_x) {
                    case '-':
                        x_num = std::stod(accumulate(op_before_x, op_after_x - 1, x_nums));
                        break;
                    default:
                        x_num = std::stod(accumulate(op_before_x + 1, op_after_x - 1, x_nums));
                    }
                    firstnum = { begin(arr), op_before_x };
                    secondnum = { equal_it + 1, end(arr) };
                }
                else {
                    x_num = std::stod(accumulate(op_before_x, op_after_x - 1, x_nums));
                    firstnum = "0";
                    secondnum = { equal_it + 1, end(arr) };
                }
                break;
            default:
                before_num_op = *(op_after_x);
                x_num = std::stod(accumulate(begin(arr), letter_it, x_nums));
                firstnum = { letter_it + 2, equal_it };
                secondnum = { equal_it + 1, end(arr) };
            }
        }
        else {
            switch (*op_before_x) {
            case '=':
                before_num_op = *(letter_it + 1);
                x_num = std::stod(accumulate(equal_it + 1, letter_it, x_nums));
                firstnum = { letter_it + 2, end(arr) };
                secondnum = { begin(arr), equal_it };
                break;
            default:
                before_num_op = *(equal_it + 1);
                switch (*op_before_x) {
                    case '-':
                        x_num = std::stod(accumulate(op_before_x, op_after_x - 1, x_nums));
                        break;
                    default:
                        x_num = std::stod(accumulate(op_before_x + 1, op_after_x - 1, x_nums));
                }
                firstnum = { equal_it + 1, op_before_x };
                secondnum = { begin(arr), equal_it };
            }
        }

        std::string nums1 = "";
        std::string nums2 = "";
     
        double num1 = std::stod(accumulate(begin(firstnum), end(firstnum), nums1));
        double num2 = std::stod(accumulate(begin(secondnum), end(secondnum), nums2));


        switch (before_num_op) {
            case '+':
                num2 = num2 - num1;
                break;
            case '-':
                num2 = num2 + num1;
                break;
            case '*':
                num2 = num2 / num1;
                break;
            case '/':
                num2 = num2 * num1;
                break;
            default:
                num2 = num2 - num1;

        }

        num1 = num2 / x_num;
        answer = answer + *letter_it + *equal_it + std::to_string(num1);
    } 
    
    void AlgebraOne::oneLetter(std::string& arr) {
        auto it1 = begin(arr);
        auto it2 = begin(arr);
        auto it3 = it2 + 1;
        auto letter_it = AlgebraOne::alphaIt(arr);
        auto equal_it = find(begin(arr), end(arr), '=');

        std::string::reverse_iterator r_it1 = std::make_reverse_iterator(letter_it);
        std::string::reverse_iterator r_it2 = std::make_reverse_iterator(equal_it);
      
        r_it1 = std::find_if(r_it1, rend(arr), basic.lmbda.r_is_in_opstring);// sets r_it1 to operator before x
        
        if (r_it1 != rend(arr)) {
            it2 = r_it1.base() - 1;//sets to operator before x
        }

        it3 = std::find_if(letter_it, end(arr), basic.lmbda.is_in_opstring);//set to operator after x

        auto& op_before_x = it2;
        auto& op_after_x = it3;
        std::string left_equation;
        std::string right_equation;

        if (op_before_x == begin(arr) && op_after_x < equal_it){//Essentially if xnum is the first num in the expression
            if (op_after_x != equal_it) {
                left_equation = { op_after_x + 1, equal_it };
                right_equation = { equal_it + 1, end(arr) };
                AlgebraOne::quickSolve(left_equation);
                AlgebraOne::quickSolve(right_equation);
                arr.erase(equal_it + 1, end(arr));
                arr.insert(equal_it + 1, begin(right_equation), end(right_equation));
                arr.erase(op_after_x + 1, equal_it);
                arr.insert(op_after_x + 1, begin(left_equation), end(left_equation));
            }
        }
        else if (op_before_x > begin(arr) && op_before_x < equal_it) {//if xnum is before equal i.e. 2+5x+1=13 ot 3+5x=13
            left_equation = { begin(arr), op_before_x };
            if (op_after_x != equal_it) {
                right_equation = { op_after_x + 1, equal_it };
            }
            else {
                right_equation = "0";
            }
            AlgebraOne::quickSolve(left_equation);
            AlgebraOne::quickSolve(right_equation);
            switch (*op_after_x) {
                case '+':
                    left_equation = std::to_string(stod(left_equation) + stod(right_equation));
                    arr.erase(op_after_x + 1, equal_it);
                    arr.insert(op_after_x + 1, begin(left_equation), end(left_equation));
                    AlgebraOne::getIts(arr, letter_it, equal_it, op_before_x, op_after_x, r_it1);
                    arr.erase(begin(arr), op_before_x);
                    break;
                case '-':
                    left_equation = std::to_string(stod(left_equation) - stod(right_equation));
                    arr.erase(op_after_x + 1, equal_it);
                    arr.insert(op_after_x + 1, begin(left_equation), end(left_equation));
                    AlgebraOne::getIts(arr, letter_it, equal_it, op_before_x, op_after_x, r_it1);
                    arr.erase(begin(arr), op_before_x);
                    break;
                case '*':
                    left_equation = std::to_string(stod(left_equation) * stod(right_equation));
                    arr.erase(op_after_x + 1, equal_it);
                    arr.insert(op_after_x + 1, begin(left_equation), end(left_equation));
                    AlgebraOne::getIts(arr, letter_it, equal_it, op_before_x, op_after_x, r_it1);
                    arr.erase(begin(arr), op_before_x);
                    break;
                case '/':
                    left_equation = std::to_string(stod(left_equation) / stod(right_equation));
                    arr.erase(op_after_x + 1, equal_it);
                    arr.insert(op_after_x + 1, begin(left_equation), end(left_equation));
                    AlgebraOne::getIts(arr, letter_it, equal_it, op_before_x, op_after_x, r_it1);
                    arr.erase(begin(arr), op_before_x);
                    break;
                default:
                    left_equation = std::to_string(stod(left_equation) + stod(right_equation));
                    arr.erase(begin(arr), op_before_x);
                    arr.insert(begin(arr), begin(left_equation), end(left_equation));
            }
        }
        else if (op_before_x == equal_it) {
            left_equation = {begin(arr), equal_it};
            right_equation = { op_after_x + 1, end(arr) };
            AlgebraOne::quickSolve(right_equation);
            AlgebraOne::quickSolve(left_equation);
            arr.erase(op_after_x + 1, end(arr));
            arr.insert(op_after_x + 1, begin(right_equation), end(right_equation));
            AlgebraOne::getIts(arr, letter_it, equal_it, op_before_x, op_after_x, r_it1);
            arr.erase(begin(arr), equal_it);
            arr.insert(begin(arr), begin(left_equation), end(left_equation));
        }
        else if (op_before_x > equal_it) {//for expressions such as 13=1+5x+2
            left_equation = { equal_it + 1, op_before_x };
            if (op_after_x != end(arr)) {
                right_equation = { op_after_x + 1, end(arr)};
            }
            else {
                right_equation = "0";
            }
            AlgebraOne::quickSolve(left_equation);
            AlgebraOne::quickSolve(right_equation);
            if (op_after_x != end(arr)) {
                switch (*op_after_x) {
                case '+':
                    right_equation = std::to_string(stod(left_equation) + stod(right_equation));
                    arr.erase(op_after_x + 1, end(arr));
                    arr.insert(op_after_x + 1, begin(right_equation), end(right_equation));
                    AlgebraOne::getIts(arr, letter_it, equal_it, op_before_x, op_after_x, r_it1);
                    arr.erase(equal_it + 1, op_before_x + 1);
                    break;
                case '-':
                    right_equation = std::to_string(stod(left_equation) - stod(right_equation));
                    arr.erase(op_after_x + 1, end(arr));
                    arr.insert(op_after_x + 1, begin(right_equation), end(right_equation));
                    AlgebraOne::getIts(arr, letter_it, equal_it, op_before_x, op_after_x, r_it1);
                    arr.erase(equal_it + 1, op_before_x + 1);
                    break;
                case '*':
                    right_equation = std::to_string(stod(left_equation) * stod(right_equation));
                    arr.erase(op_after_x + 1, end(arr));
                    arr.insert(op_after_x + 1, begin(right_equation), end(right_equation));
                    AlgebraOne::getIts(arr, letter_it, equal_it, op_before_x, op_after_x, r_it1);
                    arr.erase(equal_it + 1, op_before_x + 1);
                    break;
                case '/':
                    right_equation = std::to_string(stod(left_equation) / stod(right_equation));
                    arr.erase(op_after_x + 1, end(arr));
                    arr.insert(op_after_x + 1, begin(right_equation), end(right_equation));
                    AlgebraOne::getIts(arr, letter_it, equal_it, op_before_x, op_after_x, r_it1);
                    arr.erase(equal_it + 1, op_before_x + 1);
                    break;
                default:
                    right_equation = std::to_string(stod(left_equation) + stod(right_equation));
                    arr.erase(begin(arr), op_before_x);
                    arr.insert(begin(arr), begin(left_equation), end(left_equation));
                }
            }
            else {
                right_equation = std::to_string(stod(left_equation) + stod(right_equation));
                arr.erase(equal_it + 1, op_before_x);
                arr.insert(equal_it + 1, begin(left_equation), end(left_equation));
            }
        }
        else {
            right_equation = { equal_it + 1, end(arr) };
            AlgebraOne::quickSolve(right_equation);
            arr.erase(equal_it + 1, end(arr));
            arr.insert(equal_it + 1, begin(right_equation), end(right_equation));
        }

        AlgebraOne::getIts(arr, letter_it, equal_it, op_before_x, op_after_x, r_it1);
        AlgebraOne::combineSides(arr, equal_it, letter_it, op_before_x, op_after_x, r_it1);
    }

    void AlgebraOne::simplify(std::string& arr, int addition, int subtraction, int multiplication,
        int division, int pairsofparenthesis, int exponent, int letters) {
        if (letters == 1) {
            AlgebraOne::oneLetter(arr);

        }
    }

}