#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<math.h>
#include<numeric>
#include"basicmath.h"
BasicMath::BasicMath basic;
namespace AlgebraOne {
    class AlgebraOne {
        char alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
            'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y' ,'z'};
        

        public:
            std::string answer;
            bool isInAlpha(char var);
            std::vector<char>::iterator alphaIt(std::vector<char>& arr);
            void quickSolve(std::vector<char>& side);
            void combineLikeTerms(std::vector<char>& arr, std::vector<char>::iterator itequal, 
                std::vector<char>::iterator itletter);
            void oneLetter(std::vector<char>& arr);
            void simplify(std::vector<char>& arr, int addition, int subtraction, int multiplication,
                int division, int pairsofparenthesis, int exponent, int letters);
    };
    bool AlgebraOne::isInAlpha(char var) {
        var = tolower(var);
        char* inalpha;
        inalpha = std::find(alphabet, alphabet + 26, var);
        if (inalpha != alphabet + 26) {
            return true;
        }

        else {
            return false;
        }
    }
    std::vector<char>::iterator AlgebraOne::alphaIt(std::vector<char>& arr) {
        std::vector<char>::iterator it = begin(arr);
        std::vector<char>::iterator itletter;
        for (char elem : arr) {
            if (AlgebraOne::isInAlpha(elem) == true) {
                itletter = it;
                break;
            }
            it++;
        }
        return itletter;
    }
    void AlgebraOne::quickSolve(std::vector<char>& side) {
        inter.interpret(side);
        basic.simpleMath(side, inter.simple, inter.addition, inter.subtraction,
            inter.multiplication, inter.division, inter.pairsofparenthesis, inter.exponent);
    } 
    
    void AlgebraOne::combineLikeTerms(std::vector<char>& arr, std::vector<char>::iterator itequal, std::vector<char>::iterator itletter) {
        std::vector<char> firstnum;
        std::vector<char> secondnum;
        char before_num;
        char x_num;
        bool left = false;

        //bool right = false;
        if (itletter < itequal) {
            left = true;
            before_num = *(itletter + 1);
            //x_num =
            firstnum = { itletter + 2, itequal };
            secondnum = { itequal + 1, end(arr)};
        }
        else {
            //right = true;
            firstnum = { itletter + 1, end(arr) };//5x+3=13
            secondnum = { begin(arr), itequal };
        }

        std::string nums1 = "";
        std::string nums2 = "";
     
        double num1 = std::stod(accumulate(begin(firstnum), end(firstnum), nums1));
        double num2 = std::stod(accumulate(begin(secondnum), end(secondnum), nums2));

        if (left == true) {
            switch (before_num) {
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

            }
        }


    } 
    
    void AlgebraOne::oneLetter(std::vector<char>& arr) {
        //std::string answer;

        std::vector<char>::iterator it = begin(arr);
        std::vector<char>::iterator it2;
        std::vector<char>::iterator itletter;
        std::vector<char>::iterator itequal = find(begin(arr), end(arr), '=');

        for (char elem : arr) {
            if (AlgebraOne::isInAlpha(elem) == true) {
                it2 = it;
                itletter = it;
                break;
            }
            it++;
        }
        while (*it != '+' && *it != '-' && *it != '*' && *it != '/' ) {
            
            if (*it == '=' || it == begin(arr)) { 
                it = it2 + 2;
                break;
            }
            it--;
        }
        std::vector<char> equation1;
        std::vector<char> equation2;
        bool before_equal = false;
        bool after_equal = false;
        if (it == it2 + 2) {
            while (*it2 != '=' && it2 != end(arr)) {
                it2++;
            }
            equation1 = { it, it2};
            AlgebraOne::quickSolve(equation1);
        }
        else {
            equation1 = { begin(arr), it };
            AlgebraOne::quickSolve(equation1);
        }
        std::string side1 = std::to_string(basic.answer);
         
        if (it2 == itequal) {
            equation2 = { itequal + 1, end(arr) };
            AlgebraOne::quickSolve(equation2);
        }
        else {
            equation2 = { begin(arr), itequal };
            AlgebraOne::quickSolve(equation2);
        }
        std::string side2 = std::to_string(basic.answer);
        std::vector<char> leftside;
        std::vector<char> rightside;
        if (itletter < itequal) {
            leftside = { begin(side1), end(side1) };
            rightside = { begin(side2), end(side2) };
            arr.erase(itletter + 2, itequal);
            arr.insert(itletter + 2, begin(leftside) , end(leftside));
            itequal = find(begin(arr), end(arr), '=');
            arr.erase(itequal + 1, end(arr));
            arr.insert(itequal + 1, begin(rightside), end(rightside));
            itequal = find(begin(arr), end(arr), '=');
            itletter = AlgebraOne::alphaIt(arr);
        }
        else {
            /// <summary>
            /// This will probably throw an Error when we get to it
            /// </summary>
            leftside = { begin(side2), end(side2) };
            rightside = { begin(side1), end(side1) };
            arr.erase(begin(arr), itequal);
            arr.insert(begin(arr), begin(leftside), end(leftside));
            itequal = find(begin(arr), end(arr), '=' );
            arr.erase(itletter + 2, end(arr));
            arr.insert(itletter + 2, begin(rightside), end(rightside));
            itequal = find(begin(arr), end(arr), '=');
        }
        AlgebraOne::combineLikeTerms(arr, itequal, itletter);
    }
    
    //5x+3=13
    void AlgebraOne::simplify(std::vector<char>& arr, int addition, int subtraction, int multiplication,
        int division, int pairsofparenthesis, int exponent, int letters) {
        if (letters == 1) {
            AlgebraOne::oneLetter(arr);
        }
    }

}