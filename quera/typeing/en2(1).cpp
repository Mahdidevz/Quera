#include <iostream>
using namespace std;

bool isVowel(char ch) {
    if (ch >= 'A' && ch <= 'Z') ch = ch + 32;
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y';
}

bool isAllUpperCase(const string& word) {
    for (char ch : word) {
        if (ch < 'A' || ch > 'Z') return false;
    }
    return true;
}

int main() {
    char ch;
    string word = "", result = "";
    int consonantCount = 0;

    while (cin.get(ch)) {
        if ((ch == ' ' || ch == '\n' || ch == '\t' || ch == '.' || ch == ',' || ch == '!' || ch == '?' || ch == '\'' || ch == '\"' || ch == ';' || ch == ':') && !word.empty()) {
            consonantCount = 0;
            bool isInvalid = false;

            for (int i = 0; i < word.length(); i++) {
                char c = word[i];
                if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
                    if (!isVowel(c)) {
                        consonantCount++;
                        if (consonantCount == 5) {
                            isInvalid = true;
                            break;
                        }
                    } else {
                        consonantCount = 0;
                    }
                }
            }

            if (isInvalid && !isAllUpperCase(word)) {
                result += word + " ";
            }

            word = "";
        } else if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            word += ch;
        }
    }

    if (!word.empty()) {
        consonantCount = 0;
        bool isInvalid = false;

        for (int i = 0; i < word.length(); i++) {
            char c = word[i];
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
                if (!isVowel(c)) {
                    consonantCount++;
                    if (consonantCount == 5) {
                        isInvalid = true;
                        break;
                    }
                } else {
                    consonantCount = 0;
                }
            }
        }

        if (isInvalid && !isAllUpperCase(word)) {
            result += word + " ";
        }
    }

    if (!result.empty() && result[result.length() - 1] == ' ') {
        result = result.substr(0, result.length() - 1);
    }

    cout << result << endl;

    return 0;
}
