#include <iostream>
#include <vector>
#include <string>
#include<cmath>
#include<stdbool.h>
#include <algorithm>

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

string longestPalindrome(string s) {

    if (s.size() == 1) {
        return s;
    }

    string pS(1, s[0]);

    string tempString;

    for (int i = 0; i < s.size(); i++) {
        int counter = 1;

        if (i != 0 && i != s.size() - 1 && s[i - 1] == s[1 + i]) { //odd palindrome

            while (!(i + counter > s.size()) && !(i - counter < 0) && s[i - counter] == s[counter + i]) {

                counter++;

            }

            counter -= 1;

            tempString = s.substr(i - counter, counter * 2 + 1);

            if (tempString.size() > pS.size()) pS = tempString;
        }

        counter = 1;
        
        if (i != s.size() - 1 && s[i] == s[1 + i]) { //even palindrome

            while (!(i + counter > s.size() - 1) && !(i + 1 - counter < 0) && s[i + 1 - counter] == s[counter + i]) {

                counter++;

            }

            counter -= 1;

            tempString = s.substr(i + 1 - counter, counter * 2);

            if (tempString.size() > pS.size()) pS = tempString;

        }

    }

    return pS;


}

string convert(string s, int numRows) {
    if (numRows == 1) return s;

    const int size = numRows;
    string* rows = new string[size];


    for (int i = 0; i < s.size(); i++) {

        if (i < numRows) { //if beginning of string

            rows[i] = string(1, s[i]);

        }
        else if (i % (numRows * 2 - 2) < size) {

            rows[i % (numRows * 2 - 2)] += string(1, s[i]);

        }
        else {

            rows[numRows * 2 - 2 - (i % (numRows * 2 - 2))] += string(1, s[i]);

        }

    }

    string total = "";

    for (int i = 0; i < numRows; i++) {

        total += rows[i];

    }

    return total;

}

int sockMerchant(int n, vector<int> ar) {

    vector<int> bucket;

    vector<int> values;

    for (int i = 0; i < n; i++) {

        vector<int>::iterator it = find(values.begin(), values.end(), ar[i]);

        if (it != values.end()) { // if found

            bucket[it - values.begin()] += 1;

        }else { //if new

            bucket.push_back(1);
            values.push_back(ar[i]);


        }

    }

    int total = 0;

    for (int j = 0; j < values.size(); j++) {

        total += bucket[j] / 2;

    }

    return total;
}

int main() {
    //vector<int> num1 = {1, 2, 4, 5};
    //vector<int> num2 = {3, 6, 7};
    //cout << convert("AB", 1);
    int n = 9;
    vector<int> ar;

    ar = {10, 20, 20, 10, 10, 30, 50, 10, 20};

    cout << sockMerchant(n, ar);

    return 0;
}