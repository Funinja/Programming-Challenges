#include <iostream>
#include <vector>
#include <string>
#include<cmath>
#include<stdbool.h>

using namespace std;

int lengthOfLongestSubstring(string s) {
    vector<char> stored;

    int maxSize = 0;
    int currentCount = 0;
    bool found = false;

    for (int i = 0; i < s.size(); i++) {

        for (int j = 0; j < stored.size(); j++) { //search for repeating character
            if (stored[j] == s[i]) {
                found = true;

                stored.erase(stored.begin(), stored.begin() + j + 1);

                if (maxSize < currentCount) {
                    maxSize = currentCount;
                }

                stored.push_back(s[i]);

                currentCount = stored.size();

                break;

            }
        }

        if (!found) {
            stored.push_back(s[i]);
            currentCount++;

            if ((i == s.size() - 1) && (maxSize < currentCount)) {
                maxSize = currentCount;
            }

        }
        else {
            found = false;
        }

    }

    return maxSize;
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {



    return 1.0;
}

int reverse(int x) {
    if ((x < 10) && (x > -10)) return x;

    int i = 0;

    int digits = 0;
    int oriVal = x;

    if (x < 0) { // count digits

        digits = log10(x * (-1));
        oriVal *= -1; // reverse value

    }
    else {

        digits = log10(x);

    }

    int val = oriVal;

    int totalDigits = digits;

    int returnVal = 0;

    while (digits >= 0) {

        i = pow(10, digits);

        int num = oriVal / i;

        oriVal -= num * i;

        returnVal += num * pow(10, totalDigits - digits);

        digits--;


    }

    if (returnVal >= 2147483648 || returnVal <= -2147483648) return 0;

    if (x < 0) returnVal *= -1;

    return returnVal;

}

bool isPalindrome(int x) {

    if (x < 0) return false;

    if (x > -1 && x < 10) return true;

    vector<int> nums;

    int digits = log10(x);

    int pivot = digits / 2;

    int oriVal = x;

    int counter = 0;

    while (digits >= counter) {

        if (digits % 2 == 0) { //odd number of digits

            if (counter < digits / 2) { //check left to right

                int num = oriVal / (pow(10, digits - counter));

                oriVal -= num * (pow(10, digits - counter));

                nums.push_back(num);

            }
            else if (counter > digits / 2) {

                int num = oriVal / (pow(10, digits - counter));

                oriVal -= num * (pow(10, digits - counter));

                int i = counter - digits / 2;

                if (num != nums[nums.size() - i]) return false;

            }
            else {
                int num = oriVal / (pow(10, digits - counter));

                oriVal -= num * (pow(10, digits - counter));

            }

        }
        else {//even number of digits

            if (counter < (digits + 1) / 2) { //check left to right

                int num = oriVal / (pow(10, digits - counter));

                oriVal -= num * (pow(10, digits - counter));

                nums.push_back(num);

            }
            else{

                int num = oriVal / (pow(10, digits - counter));

                oriVal -= num * (pow(10, digits - counter));

                int i = counter - digits / 2;

                if (num != nums[nums.size() - i]) return false;

            }

        }

        counter++;
    }

    return true;

}

int main() {
    //vector<int> num1 = {1, 2, 4, 5};
    //vector<int> num2 = {3, 6, 7};
    cout << isPalindrome(1001);
	return 0;
}