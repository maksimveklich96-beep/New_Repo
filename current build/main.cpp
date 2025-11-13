#define NOMINMAX
#include <iostream>
#include <cmath>
#include <windows.h>
#include <string>
#include <limits>
#include <cctype>
//test git

void CheckNumType() {
    if(std::cin.fail()){
        throw "Wrong data type.\n";
    }
}

void CheckNum_b(double a, double b) {
    if (b < a) {
        throw "+---------------------------------------------------------------+\n"
              "|Error: upper limit must be > lower limit and must be a number  |\n"
              "|                    You should write it again                  |\n"
              "+---------------------------------------------------------------+\n";
    }
}

void CheckStepValue(double step){
    if (step <= 0) {
        throw "+--------------------------------------------------+\n"
              "|Error: step must be a number that is bigger than 0|\n"
              "|           You should write it again              |\n"
              "+--------------------------------------------------+\n";
    }
}

void n_Check(double x, int n){
    if (x < 0 && n <= 3 ){
        throw "x < 0, so n must be > 3. Please, enter n again.\n";
    }
    else if (x >= 0 && n <= 0) {
        throw "x >= 0, so n must be > 0. Please, enter n again.\n";
    }
}


long double calculateY(double x, int n) {
    long double result = 0.0;

    if (x < 0) {
        long double sum = 0.0;
        for (int i = 3; i <= n; i++) {
            sum += (1.0 / (2 * i)) + (1.0 / x);
        }
        result = (x + 3) * sum;
    } else {
        long double sum = 0.0;
        for (int i = 0; i <= n; i++) {
            long double product = 1.0;
            for (int j = 1; j <= n + 2; j++) {
                product *= pow((9 * i - j + pow(j, 3)), 2);
            }
            sum += product;
        }
        result = sum;
    }

    return result;
}

#ifndef _UNITTEST
int main() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 10);

    char temp_answer;
    std::cout << "+---------------------------------------------------------------------+\n"
                 "| Hello, this is the program for calculating depending on x you input |\n"
                 "|         Now, please type any key to enter the main menu             |\n"
                 "+---------------------------------------------------------------------+\n";
    std::cin >> temp_answer;

    while (true) {
        char choice;
        std::cout << "+-------------------------------------------------------------------------------------------------------------------+\n"
                     "|              There are some rules you need to know before using the program:                                      |\n"
                     "+-------------------------------------------------------------------------------------------------------------------+\n"
                     "|1) If x < 0, then y = (x + 3) * sum from i = 3 to n of (1/(2*i) + 1/x)                                             |\n"
                     "|2) If x >= 0, then y = sum from i = 0 to n of product from j = 1 to n+2 of (9*i - j + j^3)^2                       |\n"
                     "|You will be asked to input the lower limit (a), the step, the upper limit (b), and n.                              |\n"
                     "|The program will calculate y for x in [a, b] with the given step.                                                  |\n"
                     "|Note: Step must be > 0, upper limit must be > lower limit.                                                         |\n"
                     "|For x < 0, n must be > 3; for x >= 0, n must be > 0.                                                               |\n"
                     "+-------------------------------------------------------------------------------------------------------------------+\n"
                     "|Type (s) to start the calculations, or (e) to exit the program                                                     |\n"
                     "|Note: Register does not matter, so (S) or (E) will work just fine                                                  |\n"
                     "+-------------------------------------------------------------------------------------------------------------------+\n";

        std::cin >> choice;
        
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        
        if (choice == 'e' || choice == 'E') {
            std::cout << "+--------------------------+\n"
                         "|     Program finished     |\n"
                         "|         Goodbye          |\n"
                         "+--------------------------+\n";
            return 0;
        }

        if (choice != 's' && choice != 'S') {
            std::cout << "Invalid input, please try again.\n";
            continue;
        }
        while (true){
            double a, b, step, x;
            int n;
            try {
                std::cout << "+-----------------------------------------------------------------------------+\n"
                    "| Write the lower limit (a, x), the upper limit (b), the step and n           |\n"
                    "| Important! Value of n depends on value of x, so if x < 0, then n must be > 3|\n"
                    "| However, if x >= 0, then n > 0                                              |\n"
                    "+-----------------------------------------------------------------------------+\n";

                
                while (true) {
                    try {
                        std::cout << "Enter a: ";
                        std::cin >> a;
                        CheckNumType(); 
                        x = a; 
                        break; 
                    }
                    catch (const char* ex) {
                        SetConsoleTextAttribute(hConsole, 12); 
                        std::cout << ex << "\n";
                        SetConsoleTextAttribute(hConsole, 10); 
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    }
                }

                
                while (true) {
                    try {
                        std::cout << "Enter b, b must be bigger than " << a << ": ";
                        std::cin >> b;
                        CheckNumType(); 
                        CheckNum_b(a, b);
                        break; 
                    }
                    catch (const char* ex) {
                        SetConsoleTextAttribute(hConsole, 12);
                        std::cout << ex << "\n";
                        SetConsoleTextAttribute(hConsole, 10);
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    }
                }

                while (true) {
                    try {
                        std::cout << "Enter step, step must be bigger than 0: ";
                        std::cin >> step;
                        CheckNumType();
                        CheckStepValue(step);
                        break;
                    }
                    catch (const char* ex) {
                        SetConsoleTextAttribute(hConsole, 12);
                        std::cout << ex << "\n";
                        SetConsoleTextAttribute(hConsole, 10);
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    }
                }

                

                while (true) {
                    try {
                        if (x < 0) {
                            std::cout << "Enter n > 3";
                            std::cin >> n;
                            CheckNumType();
                            n_Check(x, n);
                            break;
                        }
                        else if (x >= 0) {
                            std::cout << "Enter n > 0";
                            std::cin >> n;
                            CheckNumType();
                            n_Check(x, n);
                            break;
                        }
                    }
                    catch (const char* ex) {
                        SetConsoleTextAttribute(hConsole, 12);
                        std::cout << ex << "\n";
                        SetConsoleTextAttribute(hConsole, 10);
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                       
                    }
                }
                
               while (x <= b) {
                    long double y = calculateY(x, n);
                    std::cout << "x = " << x << ", y = " << y << std::endl;
                    x += step;
               }
            }
            catch (const char* ex) {
                SetConsoleTextAttribute(hConsole, 12); 
                std::cout << ex << "\n";
                SetConsoleTextAttribute(hConsole, 10);
                
                std::cin.clear(); 
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                continue;
            }
            catch(...){
                SetConsoleTextAttribute(hConsole, 12);
                std::cout << "An unknown error occurred.\n";
                SetConsoleTextAttribute(hConsole, 10);

                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                continue;
            }
            std::cout << "Now type any key to continue\n";
            std::cin >> temp_answer;

            char next;
            std::cout << "+----------------------------------------------+\n"
                     "| Choose one out of three options              |\n"
                     "+----------------------------------------------+\n"
                     "| (y) Repeat calculations                      |\n"
                     "| (any key, except y and e) Return to main menu|\n"
                     "| (e) Exit program                             |\n"
                     "+----------------------------------------------+\n";
            std::cin >> next;

            if (next == 'e' || next == 'E') {
                std::cout << "+--------------------------+\n"
                         "|     Program finished     |\n"
                         "|         Goodbye          |\n"
                         "+--------------------------+\n";
                return 0;
            } else if (next == 'y' || next == 'Y') {
                continue;
            } else {
                break;
            }
        }
    }

        return 0;
    }
#endif