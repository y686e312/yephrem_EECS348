#include <iostream>
#include <iomanip> // For formatting a double-precision number
#include <string>

// Add this line to avoid repeating std::
using namespace std;

// Prototype for the extractNumeric function
double extractNumeric(const string& str);

int main() {
    string input;
    
    while (true) {
        cout << "Enter a string (or 'END' to quit): ";
        cin >> input;

        if (input == "END")
            break;

        double number = extractNumeric(input);

        if (number != -999999.99) {
            cout << "The input is: " << fixed << setprecision(4) << number << endl;
        } else {
            cout << "The input is invalid." << endl;
        }
    }
    return 0;
}


double extractNumeric(const string& str) {
    float decimal_counter = 0;
    float decimal_mult = 0.1;
    float double_num = 0.0;
    float sign = 1; 

    for (float i = 0; i < str.length(); ++i) {
        char x = str[i];
        
        if (str.length() > 20) { //checks length
            return -999999.99;
        }

        else if (x == '+' || x == '-') { //checks if the index is a sign
            if (i == 0) { //checks if the sign is the first index 
                if (x == '-') { //changes sign accordingly
                    sign = -1;
                }
                else {
                    sign = 1;
                }
            }
            else { // invalid if it isnt the first index
                return -999999.99;
            }
        }

        else if (x == '.') { //if the index if a decimal point
            if (decimal_counter == 1) { //if there is already a decimal then invalid
                return -999999.99;
            }
            else { //account for the decimal
                decimal_counter += 1;
            }
        }
        
        else if (isdigit(x)) { //if the index is a digit
            if (decimal_counter == 1) { //checks for decimal
                double_num += (x - '0') * decimal_mult; //add digit and multiply the decimal val
                decimal_mult *= 0.1; //updates the next decimal place
            } 
            else {
                double_num = double_num * 10 + (x - '0'); //adds the index to the existing num
            }
        }
        
        else { 
            return -999999.99;
        }
    }

    return double_num * sign; 
}