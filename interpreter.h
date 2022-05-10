#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<numeric>


namespace Interpreter {
    class Interpreter {
        const std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
        public:
            bool simple;
            int addition, subtraction, multiplication, division, pairsofparenthesis, exponent, operators, letters;
            void countNegatives(std::string& arr, char firstop, char negativeop);
            void interpret(std::string& arr);
    };
    void Interpreter::countNegatives(std::string& arr, char firstop, char negativeop) {//counts the amount of negatives
        auto negativecount = { firstop, negativeop };                                  //and subtracts them from the 
        auto it = begin(arr);                                                          //subtraction and operators count
        it = std::search(begin(arr), end(arr), begin(negativecount), end(negativecount));
        while (it != end(arr)) {
            it = std::search(it + 1, end(arr), begin(negativecount), end(negativecount));
            subtraction--;
            operators--;
        }
    }
    void Interpreter::interpret(std::string& arr) {                 //Counts how many +, -, *, /, and ^ there are
        letters = 0;                                                //and sets bool simple = true if equation has 0 or 1 operators
        addition = std::count(begin(arr), end(arr), '+');
        subtraction = std::count(begin(arr), end(arr), '-');
        multiplication = std::count(begin(arr), end(arr), '*');
        division = std::count(begin(arr), end(arr), '/');
        pairsofparenthesis = std::count(begin(arr), end(arr), '(');
        exponent = std::count(begin(arr), end(arr), '^');
        operators = addition + subtraction + multiplication + division + pairsofparenthesis + exponent;


        if (arr[0] == '-') {
            subtraction--;
            operators--;
        }
        Interpreter::countNegatives(arr, '+', '-');
        Interpreter::countNegatives(arr, '-', '-');
        Interpreter::countNegatives(arr, '*', '-');
        Interpreter::countNegatives(arr, '/', '-');
        Interpreter::countNegatives(arr, '^', '-');

        simple = (operators <= 1);

        switch (operators) {
            case 0:
                std::string answer = "";
                double answer1 = std::stod(accumulate(begin(arr), end(arr), answer));
        }

        for (char i : arr) {
            int lettercount = std::count(begin(alphabet), end(alphabet), tolower(i));
            if (lettercount > 0) {
                 letters += lettercount;
            }
        }   
    }

}
