<<<<<<< HEAD
#include <iostream>
#include <cmath>
#include <windows.h>
#include <string>
#include <limits>
#include <cctype>
//test git

bool isInteger(const std::string& s) {
    if (s.empty()) return false;
    size_t start = 0;
    if (s[0] == '-' || s[0] == '+') start = 1;
    for (size_t i = start; i < s.size(); ++i) {
        if (!std::isdigit(s[i])) return false;
    }
    return true;
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
            double a, b, step;
            int n;
            std::cout << "+-----------------------------------------------------------------------------+\n"
                     "| Write the lower limit (a, x), the upper limit (b), the step and n           |\n"
                     "| Important! Value of n depends on value of x, so if x < 0, then n must be > 3|\n"
                     "| However, if x >= 0, then n > 0                                              |\n"
                     "+-----------------------------------------------------------------------------+\n";

            while (true) {
                std::cout << "Enter a: ";
                if (std::cin >> a) break;
                std::cout << "Error: a must be a number, please write it again\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }

            while (true) {
                std::cout << "Enter b, b must be bigger than " << a << ": ";
                if (std::cin >> b && b > a) break;
                std::cout << "+---------------------------------------------------------------+\n"
                         "|Error: upper limit must be > lower limit and must be a number  |\n"
                         "|             You should write it again                         |\n"
                         "+---------------------------------------------------------------+\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }

            while (true) {
            std::cout << "Enter step, step must be bigger than 0: ";
                if (std::cin >> step && step > 0) break;
                std::cout << "+--------------------------------------------------+\n"
                         "|Error: step must be a number that is bigger than 0|\n"
                         "|           You should write it again              |\n"
                         "+--------------------------------------------------+\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 

     
            std::string input;
            while (true) {
                if (a < 0)
                    std::cout << "x < 0, so n must be > 3: ";
                else
                    std::cout << "x >= 0, so n must be > 0: ";

                std::cin >> input;

                if (!isInteger(input)) {
                    std::cout << "+--------------------------+\n"
                             "|Error: n must be integer  |\n"
                             "|You should write it again |\n"
                             "+--------------------------+\n";
                    continue;
                }

                n = std::stoi(input);

                if (a < 0 && n <= 3) {
                    std::cout << "x < 0, so n must be > 3. Please, enter n again.\n";
                    continue;
                }
                if (a >= 0 && n <= 0) {
                    std::cout << "x >= 0, so n must be > 0. Please, enter n again.\n";
                    continue;
                }

                break;
            }

        
            double x = a;
            while (x <= b) {
                long double y = calculateY(x, n);
                std::cout << "x = " << x << ", y = " << y << std::endl;
                x += step;
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
=======
#include <iostream>
#include <cmath>
#include <windows.h>
#include <string>
#include <limits>
#include <cctype>


bool isInteger(const std::string& s) {
    if (s.empty()) return false;
    size_t start = 0;
    if (s[0] == '-' || s[0] == '+') start = 1;
    for (size_t i = start; i < s.size(); ++i) {
        if (!std::isdigit(s[i])) return false;
    }
    return true;
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
            double a, b, step;
            int n;
            std::cout << "+-----------------------------------------------------------------------------+\n"
                     "| Write the lower limit (a, x), the upper limit (b), the step and n           |\n"
                     "| Important! Value of n depends on value of x, so if x < 0, then n must be > 3|\n"
                     "| However, if x >= 0, then n > 0                                              |\n"
                     "+-----------------------------------------------------------------------------+\n";

            while (true) {
                std::cout << "Enter a: ";
                if (std::cin >> a) break;
                std::cout << "Error: a must be a number, please write it again\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }

            while (true) {
                std::cout << "Enter b, b must be bigger than " << a << ": ";
                if (std::cin >> b && b > a) break;
                std::cout << "+---------------------------------------------------------------+\n"
                         "|Error: upper limit must be > lower limit and must be a number  |\n"
                         "|             You should write it again                         |\n"
                         "+---------------------------------------------------------------+\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }

            while (true) {
            std::cout << "Enter step, step must be bigger than 0: ";
                if (std::cin >> step && step > 0) break;
                std::cout << "+--------------------------------------------------+\n"
                         "|Error: step must be a number that is bigger than 0|\n"
                         "|           You should write it again              |\n"
                         "+--------------------------------------------------+\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 

     
            std::string input;
            while (true) {
                if (a < 0)
                    std::cout << "x < 0, so n must be > 3: ";
                else
                    std::cout << "x >= 0, so n must be > 0: ";

                std::cin >> input;

                if (!isInteger(input)) {
                    std::cout << "+--------------------------+\n"
                             "|Error: n must be integer  |\n"
                             "|You should write it again |\n"
                             "+--------------------------+\n";
                    continue;
                }

                n = std::stoi(input);

                if (a < 0 && n <= 3) {
                    std::cout << "x < 0, so n must be > 3. Please, enter n again.\n";
                    continue;
                }
                if (a >= 0 && n <= 0) {
                    std::cout << "x >= 0, so n must be > 0. Please, enter n again.\n";
                    continue;
                }

                break;
            }

        
            double x = a;
            while (x <= b) {
                long double y = calculateY(x, n);
                std::cout << "x = " << x << ", y = " << y << std::endl;
                x += step;
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
>>>>>>> 2c42965ba59231cb71ae14d320d92d6a5d209cdc
