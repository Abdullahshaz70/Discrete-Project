#include <iostream>

using namespace std;

char generateRandomChar() {
    const char allChars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()-_=+[]{}|;:,.<>?/~";
    return allChars[rand() % (sizeof(allChars) - 1)];
}

void generateRandomPassword(int length) {
    srand(time(0));

    string password = "";
    for (int i = 0; i < length; ++i) {
        password += generateRandomChar();
    }

    cout << "Generated password: " << password << endl;
}

bool isStrongPassword(const char password[], int& uppercase, int& lowercase, int& digits, int& special) {
    int length = 0;
    uppercase = 0;
    lowercase = 0;
    digits = 0;
    special = 0;

    while (password[length] != '\0') {
        char ch = password[length];
        length++;

        if (ch >= 'A' && ch <= 'Z') uppercase++;
        if (ch >= 'a' && ch <= 'z') lowercase++;
        if (ch >= '0' && ch <= '9') digits++;
        if (!(ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z' || ch >= '0' && ch <= '9')) special++;
    }

    return length >= 8 && uppercase > 0 && lowercase > 0 && digits > 0 && special > 0;
}

unsigned long long calculateCombinations(int length, int uppercase, int lowercase, int digits, int special) {
    const int UPPERCASE_SET = 26;
    const int LOWERCASE_SET = 26;
    const int DIGIT_SET = 10;
    const int SPECIAL_SET = 32;

    int totalCharTypes = 0;
    if (uppercase > 0) totalCharTypes += UPPERCASE_SET;
    if (lowercase > 0) totalCharTypes += LOWERCASE_SET;
    if (digits > 0) totalCharTypes += DIGIT_SET;
    if (special > 0) totalCharTypes += SPECIAL_SET;

    unsigned long long totalCombinations = 1;
    for (int i = 0; i < length; ++i) {
        totalCombinations *= totalCharTypes;
    }

    return totalCombinations;
}

int main() {
    int choice;

    do {
        cout << "Menu:\n";
        cout << "1. Password Strength Checker\n";
        cout << "2. Random Password Generator\n";
        cout << "3. Exit\n";
        cout << "Enter your choice (1-3): ";
        cin >> choice;

        if (choice == 1) {
            char password[100];
            cout << "Enter your password: ";
            cin >> password;

            int uppercase, lowercase, digits, special;

            if (isStrongPassword(password, uppercase, lowercase, digits, special)) {
                cout << "Your password is strong." << endl;
            }
            else {
                cout << "Your password is weak." << endl;
            }

            cout << "Uppercase letters: " << uppercase << endl;
            cout << "Lowercase letters: " << lowercase << endl;
            cout << "Digits: " << digits << endl;
            cout << "Special characters: " << special << endl;

            int passwordLength = 0;
            while (password[passwordLength] != '\0') passwordLength++;

            unsigned long long totalCombinations = calculateCombinations(passwordLength, uppercase, lowercase, digits, special);
            double probability = 1.0 / totalCombinations;

            cout << "Total possible combinations: " << totalCombinations << endl;
            cout << "Probability of guessing the password: " << probability << endl;
        }
        else if (choice == 2) {
            int length;
            cout << "Enter the desired password length: ";
            cin >> length;

            if (length < 8) {
                cout << "Password length should be at least 8 characters." << endl;
            }
            else {
                generateRandomPassword(length);
            }
        }
        else if (choice == 3) {
            cout << "Exiting program..." << endl;
        }
        else {
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 3);

    return 0;
}