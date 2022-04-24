#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include <math.h>
#include"interpreter.h"

Interpreter::Interpreter inter;
namespace BasicMath {
    class BasicMath {
        
        std::string c, nums1, nums2;
        std::vector<char> numinsert;
        std::vector<char> within;
        double num1 = 0;
        
        public:
            
            double answer;
            void numToCharVec(double numtochars);
            void getNumsSimple(std::vector<char>& arr, char op);
            void parenthesis(std::vector<char>& arr, int pairsofparenthesis);
            void exponents(std::vector<char>& arr, int exponents);
            void orderOfOperations(std::vector<char>& arr, int addition, int subtraction, int multiplication, int division);
            void simpleMath(std::vector<char>& arr, bool simple, int addition, int subtraction, int multiplication, 
                int division, int pairsofparenthesis, int exponent);
        
    };
    void BasicMath::numToCharVec(double numtochars) {
        std::string newstring = std::to_string(numtochars);
        numinsert = {newstring.begin(), newstring.end()};
        
    }
    void BasicMath::getNumsSimple(std::vector<char>& arr, char op) {
        int i = 0;
        while (arr[i] != op) {
            c = (1, arr[i]);
            nums1 += c;
            i++;
        }
        i++;
        while (i != arr.size()) {
            c = (1, arr[i]);
            nums2 += c;
            i++;
        }
    }
    void BasicMath::parenthesis(std::vector<char>& arr, int pairsofparenthesis) {

        int index1 = 0;
        int index2 = 0;
        while (pairsofparenthesis != 0) {
                int n = 0;
                for (char& elem : arr) {
                    if (elem == '(') {
                        index1 = n;
                    }
                    else if (elem == ')') {
                        index2 = n;
                        break;
                    }
                    n++;
                }
                within.insert(within.begin(), arr.begin() + index1 + 1, arr.begin() + index2);
                inter.interpret(within);
                BasicMath::exponents(within, inter.exponent);
                inter.interpret(within);
                BasicMath::orderOfOperations(within, inter.addition, inter.subtraction, inter.multiplication, inter.division);
                arr.erase(arr.begin() + index1 + 1, arr.begin() + index2);
                arr.insert(arr.begin() + index1 + 1, within.begin(), within.end());
                index2 = 0;
                n = 0;
                for (char& i : arr) {
                    if (i == '(') {
                        index1 = n;
                    }
                    else if (i == ')') {
                        index2 = n;
                        break;
                    }
                    n++;
                }
                if (index1 == 0) {
                    switch (arr[index2]) {
                    case ')':
                        if (index2 + 1 <= arr.size() - 1) {
                            if (arr[index2 + 1] == '+' || arr[index2 + 1] == '-'
                                || arr[index2 + 1] == '*' || arr[index2 + 1] == '/') {
                                arr.erase(arr.begin() + index1);
                                arr.erase(arr.begin() + index2 - 1);
                                within.clear();
                                pairsofparenthesis--;
                                continue;
                            }
                            else {
                                arr.insert(arr.begin() + index2 + 1, '*');
                            }
                        }
                    }
                    arr.erase(arr.begin() + index1);
                    arr.erase(arr.begin() + index2 - 1);
                    within.clear();
                    pairsofparenthesis--;
                    continue;
                }

                switch (arr[index1 - 1]) {
                case '+':
                    arr.erase(arr.begin() + index1);
                    arr.erase(arr.begin() + index2 - 1);
                    break;
                case '-':
                    arr.erase(arr.begin() + index1);
                    arr.erase(arr.begin() + index2 - 1);
                    break;
                case '*':
                    arr.erase(arr.begin() + index1);
                    arr.erase(arr.begin() + index2 - 1);
                    break;
                case '/':
                    arr.erase(arr.begin() + index1);
                    arr.erase(arr.begin() + index2 - 1);
                    break;
                case '(':
                    switch (arr[index2]) {
                    case ')':
                        if (arr[index2 + 1] != '+' && arr[index2 + 1] != '-' && arr[index2 + 1] != '*'
                            && arr[index2 + 1] != '/' && arr[index2 + 1] != '^') {
                            arr.insert(arr.begin() + index2 + 1, '*');
                        }
                    }
                    arr.erase(arr.begin() + index1);
                    arr.erase(arr.begin() + index2 - 1);
                    
                    break;
                default:
                    arr.erase(arr.begin() + index1);
                    arr.erase(arr.begin() + index2 - 1);
                    arr.insert(arr.begin() + index1, '*');
                    break;
                }
                within.clear();
                pairsofparenthesis--;
            
        }

        
    }
    void BasicMath::exponents(std::vector<char>& arr, int exponent) {
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
                    BasicMath::numToCharVec(num1);
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
    void BasicMath::orderOfOperations(std::vector<char>& arr, int addition, int subtraction, int multiplication, int division) {
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
                                BasicMath::numToCharVec(num1);
                                arr.insert(arr.begin() + index1, numinsert.begin(), numinsert.end());
                                mult--;
                                i = 0;
                                broken = true;
                                break;
                            case '/':
                                num1 = stod(nums1) / stod(nums2);
                                arr.erase(arr.begin() + index1, arr.begin() + index2);
                                BasicMath::numToCharVec(num1);
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
                            BasicMath::numToCharVec(num1);
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
                            BasicMath::numToCharVec(num1);
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
    void BasicMath::simpleMath(std::vector<char>& arr, bool simple, int addition, int subtraction, 
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
                break;
            case false:
                BasicMath::parenthesis(arr, inter.pairsofparenthesis);
                inter.interpret(arr);
                //Exponents are wonky
                BasicMath::exponents(arr, inter.exponent);
                inter.interpret(arr);
                BasicMath::orderOfOperations(arr, inter.addition, inter.subtraction, inter.multiplication, inter.division);
        }
        nums1 = "";
        nums2 = "";
    }
}
