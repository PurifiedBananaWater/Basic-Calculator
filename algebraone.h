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
            auto alphaIt(std::string& arr);
            void quickSolve(std::string& side);
            void combineLikeTerms(std::string& arr, std::string::iterator itequal,
                std::string::iterator itletter);
            void oneLetter(std::string& arr);
            void simplify(std::string& arr, int addition, int subtraction, int multiplication,
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
    auto AlgebraOne::alphaIt(std::string& arr) {
        auto it = begin(arr);
        std::string::iterator itletter;
        for (char elem : arr) {
            if (AlgebraOne::isInAlpha(elem) == true) {
                itletter = it;
                break;
            }
            it++;
        }
        return itletter;
    }
    void AlgebraOne::quickSolve(std::string& side) {
        inter.interpret(side);
        basic.simpleMath(side, inter.simple, inter.addition, inter.subtraction,
            inter.multiplication, inter.division, inter.pairsofparenthesis, inter.exponent);
    } 
    
    void AlgebraOne::combineLikeTerms(std::string& arr, std::string::iterator itequal, std::string::iterator itletter) {
        std::string firstnum;
        std::string secondnum;
        std::string::iterator x_numit;
        std::string ops = "+-*/";
        //x_numit = find_if(begin(arr), itletter, [ops](auto elem)
            //{return *elem == find(begin(ops), end(ops), *elem); }); //Left off here want to return it of last occurence of a char in ops before letter maybe for_each instead
        char before_num;
        std::string x_nums = "";
        double x_num;
        bool left = false;
        answer = "";
        //5x+3=13
        
        //bool right = false;
        if (itletter < itequal) {
            left = true;
            before_num = *(itletter + 1);
            x_num = std::stod(accumulate(begin(arr), itletter, x_nums));
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
        num1 = num2 / x_num; //5x+3=13

        answer = answer + *itletter + *itequal + std::to_string(num1);

        


    } 
    
    void AlgebraOne::oneLetter(std::string& arr) {
        //std::string answer;

        auto it = begin(arr);
        auto it2 = begin(arr);
        auto itletter = begin(arr);
        auto itequal = find(begin(arr), end(arr), '=');

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
        std::string equation1;
        std::string equation2;
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
        std::string leftside;
        std::string rightside;
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
    void AlgebraOne::simplify(std::string& arr, int addition, int subtraction, int multiplication,
        int division, int pairsofparenthesis, int exponent, int letters) {
        if (letters == 1) {
            AlgebraOne::oneLetter(arr);
        }
    }

}