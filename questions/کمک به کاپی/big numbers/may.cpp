#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct BigNumber {
    std::string digits;
    int sign;
};

BigNumber stringToBigNumber(const std::string& str) {
    BigNumber num;
    if (str[0] == '-') {
        num.sign = 1;
        num.digits = str.substr(1);
    } else {
        num.sign = 0;
        num.digits = str;
    }
    return num;
}

std::string bigNumberToString(const BigNumber& num) {
    return (num.sign == 1 ? "-" : "") + num.digits;
}

std::string add(const BigNumber& num1, const BigNumber& num2);

std::string subtract(BigNumber num1, BigNumber num2) {
    if (num1.sign != num2.sign) {
        num2.sign = 1 - num2.sign;
        return add(num1, num2);
    }
    
    bool isNegative = false;
    if (num1.digits.length() < num2.digits.length() ||
        (num1.digits.length() == num2.digits.length() && num1.digits < num2.digits)){
        std::swap(num1, num2);
        isNegative = true;
    }

    std::string result = "";
    int borrow = 0;
    int i = num1.digits.length() - 1;
    int j = num2.digits.length() - 1;

    while (i >= 0) {
        int digit1 = (num1.digits[i] - '0');
        int digit2 = (j >= 0) ? (num2.digits[j] - '0') : 0;

        int diff = digit1 - digit2 - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result = std::to_string(diff) + result;

        i--;
        j--;
    }
    
    size_t first_digit = result.find_first_not_of('0');
    if (first_digit == std::string::npos)
        return "0";
    else
        return (isNegative ^ (num1.sign == 1) ? "-" : "") + result.substr(first_digit);
}

std::string add(const BigNumber& num1, const BigNumber& num2) {
    if (num1.sign != num2.sign) {
        BigNumber temp_num2 = num2;
        temp_num2.sign = 1 - temp_num2.sign;
        return subtract(num1, temp_num2);
    }

    std::string result = "";
    int carry = 0;
    int i = num1.digits.length() - 1;
    int j = num2.digits.length() - 1;

    while (i >= 0 || j >= 0 || carry > 0) {
        int digit1 = (i >= 0) ? (num1.digits[i] - '0') : 0;
        int digit2 = (j >= 0) ? (num2.digits[j] - '0') : 0;

        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        result = std::to_string(sum % 10) + result;

        i--;
        j--;
    }
    size_t first_digit = result.find_first_not_of('0');
    if (first_digit == std::string::npos)
        return "0";
    else
        return (num1.sign == 1 ? "-" : "") + result.substr(first_digit);
}

std::string multiply(const BigNumber& num1, const BigNumber& num2) {
    int n1 = num1.digits.size();
    int n2 = num2.digits.size();
    std::vector<int> result(n1 + n2, 0);

    for (int i = n1 - 1; i >= 0; i--) {
        for (int j = n2 - 1; j >= 0; j--) {
            int p = (num1.digits[i] - '0') * (num2.digits[j] - '0');
            result[i + j + 1] += p;
        }
    }

    int carry = 0;
    for (int i = result.size() - 1; i >= 0; i--) {
        int sum = result[i] + carry;
        result[i] = sum % 10;
        carry = sum / 10;
    }

    std::string product = "";
    for (int digit : result) {
        product += std::to_string(digit);
    }
    
    size_t first_digit = product.find_first_not_of('0');
    if (first_digit == std::string::npos)
        return "0";
    else
        return (num1.sign != num2.sign && product.substr(first_digit) != "0" ? "-" : "") + product.substr(first_digit);
}


std::string power(BigNumber base, BigNumber exp) {
    if (exp.sign == 1)
        return "0";
    if (exp.digits == "0")
        return "1";
    
    BigNumber result;
    result.digits = "1";
    result.sign = 0;
    
    BigNumber temp_exp = exp;
    while (temp_exp.digits != "0"){
        result =  stringToBigNumber(multiply(result,base));
        temp_exp.digits = subtract(temp_exp, stringToBigNumber("1"));
    }
    
    return bigNumberToString(result);
}

// Function to divide two BigNumbers
std::string divide(BigNumber dividend, BigNumber divisor) {
    if (divisor.digits == "0") {
        return "inf";
    }
    if (dividend.digits == "0") {
        return "0";
    }
    
    bool isNegative = (dividend.sign != divisor.sign);
    BigNumber absDividend = dividend;
    absDividend.sign = 0;
    BigNumber absDivisor = divisor;
    absDivisor.sign = 0;

  if (absDivisor.digits.length() > absDividend.digits.length() || (absDivisor.digits.length() == absDividend.digits.length() && absDivisor.digits > absDividend.digits)){
        return "0";
    }
    
    std::string quotient = "";
    std::string remainder = "0";
    
    for (int i = 0; i < absDividend.digits.length(); i++){
        // Append next digit to the remainder
        remainder += absDividend.digits[i];

         // Remove leading zeros
        size_t first_digit = remainder.find_first_not_of('0');
        if (first_digit != std::string::npos)
            remainder = remainder.substr(first_digit);
        else
            remainder = "0"; // If remainder is all zeros set to "0"
        
        int count = 0;
        //Keep subtracting until remainder is less than divisor
        while(stringToBigNumber(remainder).digits.length() > absDivisor.digits.length()
              ||
              (stringToBigNumber(remainder).digits.length() == absDivisor.digits.length()
              && stringToBigNumber(remainder).digits >= absDivisor.digits)
            ){
             remainder = subtract(stringToBigNumber(remainder),absDivisor);
             count++;
        }
        quotient += std::to_string(count);
    }

    size_t first_digit = quotient.find_first_not_of('0');
    if (first_digit == std::string::npos)
        return "0";
    else{
         return (isNegative && quotient.substr(first_digit) != "0" ? "-" : "") + quotient.substr(first_digit);
    }
}


int main() {
    char operation;
    std::string num1_str, num2_str;

    std::cin >> operation >> num1_str >> num2_str;

    BigNumber num1 = stringToBigNumber(num1_str);
    BigNumber num2 = stringToBigNumber(num2_str);

    std::string result;
    switch (operation) {
        case '+':
            result = add(num1, num2);
            break;
        case '-':
            result = subtract(num1, num2);
            break;
        case '*':
            result = multiply(num1, num2);
            break;
        case '^':
            result = power(num1, num2);
            break;
        case '/':
            result = divide(num1, num2);
            break;
        default:
            result = "Invalid operation";
    }

    std::cout << result << std::endl;

    return 0;
}
