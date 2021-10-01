#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>

using namespace std;


void isTriangle(int num);

void isPower(int num);

void isConSquare(const int& num);

void isAbundant(int num);

inline int sumOfConSquare(const int& lowerB,const int& upperB){
    return (2*upperB+1)*(upperB+1)*upperB/6 - (2*lowerB-1)*(lowerB-1)*lowerB/6;
}

int main() {
    int targetNum, testCtg;
    int temp_first, temp_second; // store the intermediate value which could be out-of-range
    while (true) {
        cout << "Please enter the integer and the test choice: ";
        cin >> temp_first >> temp_second;
        if (temp_first <= 0 || temp_first >= 10000000 || temp_second < 1 || temp_second > 4) {
            continue;
        } else {
            targetNum = temp_first,
                    testCtg = temp_second;
            break;
        }
    }
    switch (testCtg) {
        case 1:
            isTriangle(targetNum);
            break;
        case 2:
            isPower(targetNum);
            break;
        case 3:
            isConSquare(targetNum);
            break;
        case 4:
            isAbundant(targetNum);
            break;
        default:
            break;
    }
    return 0;

}

void isTriangle(int num) {
    int possibleLower = floor(sqrt(num * 2));
    int possibleLarger = possibleLower + 1;
    if (possibleLower * possibleLarger == num * 2)
        cout << "Pass" << endl;
    else
        cout << "Fail" << endl;
}

void isPower(int num) {
    /// i should be the only divisor of num
    int squareRoot = ceil(sqrt(num)); // search through 2 - square root of num
    for (int i = 2; i < squareRoot; ++i) {
        if (num % i != 0) // i is not the divisor
            continue;
        else {
            /// check whether i is the only divisor
            /// if not, output "fail"
            while (true) {
                if (num % i == 0)
                    num = num / i;
                    /// the fail symbol
                else {
                    cout << "Fail" << endl;
                    return;
                }
                /// the success symbol
                if (num == 1) {
                    cout << "Pass" << endl;
                    return;
                }
            }
        }

    }
}

void isConSquare(const int& num) {
    int squareRootM = ceil(sqrt(num));
    if (squareRootM == sqrt(num)){ // simple cases, square numbers
        cout << "Pass" << endl;
        return;
    }else{
        for (int begin = 1; begin < squareRootM; ++begin) {
            int  threshold = begin + 1;
            while( num >= sumOfConSquare(begin,threshold)){
                if (num == sumOfConSquare(begin,threshold)){
                    cout << "Pass" << endl;
                    return;
                }else
                threshold ++ ;
            }
        }
    }
    cout << "Fail" << endl;
}

void isAbundant(int num) {
    int sum_of_proper_divisor = 1;
    for (int i = 2; i < ceil(sqrt(num)); ++i) {
        if (num % i == 0) {
            // proper divisor found
            sum_of_proper_divisor += i;
            sum_of_proper_divisor += num / i;
        }else
            continue;
    }
    if (sum_of_proper_divisor > num){
        cout << "Pass" << endl;
    } else
        cout << "Fail" << endl;
}

