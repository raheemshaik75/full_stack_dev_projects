#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Basically this void function that I have created is to display a farewell message to the user
void exitProgram() { // The function main begins
  printf("Thanks for using my Simple Calculator. Hope to see you again soon. "
         "Goodbye! "); // this is entred once the user has exit the program by selecting option X
}

int binOperationIsValid(char operation) {
        if(operation == '+' || operation == '-' || operation == '*' || operation == '/' || operation == '^' || operation == '%') {
            return 1;
        } 

        return 0;
    }

    int unOperationIsValid(char operation) {
        if(operation == 'S' || operation == 'L' || operation == 'E' || operation == 'C' || operation == 'F') {
            return 1;
        } 

        return 0;
    }

    int varNameIsValid(char c) {
        if(c == 'a' || c == 'b' || c == 'c' || c == 'd' || c == 'e') {
            return 1;
        } 

        return 0;
    }

    int varOrNumIsValid(char c) {
        if(c == 'V' || c == 'N') {
            return 1;
        } 

        return 0;
    }
void calculateForBin(double num1, double num2, char operation) {
        double result;
        switch(operation) {
                case '+':
                    result = num1 + num2;
                    printf("Result is: %lf\n", result);
                    break;
                case '-':
                    result = num1 - num2;
                    printf("Result is: %lf\n", result);
                    break;
                case '*':
                    result = num1 * num2;
                    printf("Result is: %lf\n", result);
                    break;
                case '/':
                    if (num2 == 0) {
                        printf("Error: You have divided by zero. Please try again!\n");
                        return 0;
                    }
                    result = num1 / num2;
                    printf("Result is: %lf\n", result);
                    break;
                case '%':
                    result = fmod(num1, num2);
                    printf("Result is: %lf\n", result);
                    break;
                case '^':
                    result = pow(num1, num2);
                    printf("Result is: %lf\n", result);
                    break;
                default:
                    printf("Invalid input! Please select an operation from here (+, -, *, /, %%, ^):\n");
                    break;
            }
    }

    void calculateForU(double num, char operation) {
        double result;
        switch(operation) {
                case 'S':
                   if(num < 0) {
                        printf("Number can't be negative. Try again: ");
                        while(!scanf("%lf", &num) || num < 0) {
                            printf("Invalid number argument. Try again: ");
                            getchar();
                        }
                    }
                    result = sqrt(num);
                    printf("Result is: %lf\n", result);
                    break;
                case 'L':
                    result = log(num);
                    printf("Result is: %lf\n", result);
                    break;
                case 'E':
                    result = exp(num);
                    printf("Result is: %lf\n", result);
                    break;
                case 'C':
                    result = ceil(num);
                    printf("Result is: %lf\n", result);
                    break;
                case 'F':
                    result = floor(num);
                    printf("Result is: %lf\n", result);
                    break;
                default:
                    puts("Invalid input for operations. You have to choose from (S, L, E, C, F).");
                    break;
            }
    }
int main() {

    printf("Welcome to my Command-line Calculator (CLC)\n");
    printf("Developer: Abdur Raheem Shaik\n");
    printf("Version: Assignment 2\n");
    printf("Date: 2023-11-22\n");
    printf("---------------------------------------\n");
    printf("Select one of the following items:\n");
    printf("(B) Binary Mathematical Operations, such as addition and subtraction.\n");
    printf("(U) Unary Mathematical Operations, such as square root, and log.\n");
    printf("(A) Advances Mathematical Operations, using variables, arrays.\n");
    printf("(V) Define variables and assign them values.\n");
    printf("(X) Exit\n");

    int index = 0;
    char option;
    int loop = 1;

    char varNames[100];
    double values[100];

    scanf(" %c", &option);

    while(loop == 1) {

        if(option == 'B'){ 
            double num1;
            double num2;
            char operation;

            printf("Please enter your first number:\n");
            while(!scanf("%lf", &num1)) {
                printf("Invalid input! Please input first number again:\n");
            }

            printf("Please select an operation (+, -, *, /, %%, ^):\n");
            scanf(" %c", &operation);
            while(!binOperationIsValid(operation)){
                printf("Invalid input! Please select an operation from here (+, -, *, /, %%, ^):\n");
                scanf(" %c", &operation);
            }

            printf("Please enter your second number:\n");
            while(!scanf("%lf", &num2)) {
                printf("Invalid input! Please enter second number again:\n");
            }

            calculateForBin(num1, num2, operation);
        } else if(option == 'X') {
            loop = 0;
        } else if(option == 'U') {
            double num;
            char operation;

            printf("Please enter a number:\n");
            while(!scanf("%lf", &num)) {
                printf("Invalid input! Please input a number again:\n");
            }

            printf("Please select an operation (S, L, E, C, F):\n");
            scanf(" %c", &operation);
            while(!unOperationIsValid(operation)){
                printf("Invalid input! Please select an operation from here (S, L, E, C, F):\n");
                scanf(" %c", &operation);
            }

            calculateForU(num, operation);
        } else if(option == 'V') {
            printf("Please select a single character variable name (a to e):\n");
            scanf(" %c", &varNames[index]);

            while(!varNameIsValid(varNames[index])) {
                printf("Please enter a valid variable name (a to e)\n");
                scanf(" %c", &varNames[index]);
            }

            printf("Enter your variable value: ");
            while(!scanf("%lf", &values[index])) {
                printf("Invalid input! Please enter number again:\n");
                scanf("%lf", &values[index]);
                getchar();
            }
            index++;
        } else if(option == 'A') {
            char childOption;
            printf("Please select an option B, U or X:\n");
            scanf(" %c", &childOption);

            switch(childOption) {
                case 'B':
                    {double num1;
                    double num2;
                    char operation;

                    char isNumOrVar;
                    printf("Is the first number a Variable or a Number? Enter V for variable and N for number:\n");
                    scanf(" %c", &isNumOrVar);

                    if(isNumOrVar == 'N'){
                        printf("Please enter your first number:\n");
                        while(!scanf("%lf", &num1)) {
                            printf("Invalid input! Please enter first number again:\n");
                        }
                    } else if(isNumOrVar == 'V') {
                        char varName;
                        printf("Please enter a variable name for your first number:\n");
                        scanf(" %c", &varName);
                        while(!varNameIsValid(varName)) {
                            printf("Invalid input! Please enter first variable name again:\n");
                            scanf(" %c", &varName);
                        }
                        for(int i = 0; i < 100; i++){
                            if(varNames[i] == varName){
                                num1 = values[i];
                                break;
                            }
                        }
                    }

                    printf("Please select an operation (+, -, *, /, %%, ^):\n");
                    scanf(" %c", &operation);
                    while(!binOperationIsValid(operation)){
                        printf("Invalid input! Please select an operation from here (+, -, *, /, %%, ^):\n");
                        scanf(" %c", &operation);
                    }

                    printf("Is the second number a Variable or a Number? Enter V for variable and N for number:\n");
                    scanf(" %c", &isNumOrVar);
                    while(!varOrNumIsValid(isNumOrVar)) {
                        printf("Invalid input! Please select either V or N:\n");
                        scanf(" %c", &isNumOrVar);
                    }

                    if(isNumOrVar == 'N'){
                        printf("Please enter your second number:\n");
                        while(!scanf("%lf", &num2)) {
                            printf("Invalid input! Please enter second number again:\n");
                        }
                    } else if(isNumOrVar == 'V') {
                        char varName;
                        printf("Please enter a variable name for your second number:\n");
                        scanf(" %c", &varName);
                        while(!varNameIsValid(varName)) {
                            printf("Invalid input! Please enter second variable name again:\n");
                            scanf(" %c", &varName);
                        }
                        for(int i = 0; i < 100; i++){
                            if(varNames[i] == varName){
                                num2 = values[i];
                                break;
                            }
                        }
                    }

                    calculateForBin(num1, num2, operation);
                    break;}
                case 'U':
                    {double num;
                    char operation;

                    char isNumOrVar;

                    printf("Is the number a Variable or a Number? Enter V for variable and N for number:\n");
                    scanf(" %c", &isNumOrVar);

                    if(isNumOrVar == 'N'){
                        printf("Please enter a number:\n");
                        while(!scanf("%lf", &num)) {
                            printf("Invalid input! Please enter number again:\n");
                        }
                    } else if(isNumOrVar == 'V') {
                        char varName;
                        printf("Please enter variable name number:\n");
                        scanf(" %c", &varName);
                        while(!varNameIsValid(varName)) {
                            printf("Invalid input! Please enter variable name again:\n");
                            scanf(" %c", &varName);
                        }
                        for(int i = 0; i < 100; i++){
                            if(varNames[i] == varName){
                                num = values[i];
                                break;
                            }
                        }
                    }

                    printf("Please select an operation: (S, L, E, C, F):\n");
                    scanf(" %c", &operation);
                    while(!unOperationIsValid(operation)){
                        printf("Please enter an operation from here (S, L, E, C, F):\n");
                        scanf(" %c", &operation);
                    }

                    calculateForU(num, operation);

                    break;}
                case 'X':
                    printf("Thanks for using my Simple Calculator. Hope to see you again soon. "
                         "Goodbye! ");
                    break;
                default:

                    printf("Invalid choice. Exited this session. Returned to main session.\n");
                    break;
            }

        } 

        if(loop != 0) {
            printf("\nTo begin another calculation, please select your option (B, U, A, V, X):\n");
            scanf(" %c", &option);
        }
    }

    exitProgram(); //Once the program has exited the program it will call the exitProgram function and state a farewell message that had been assigned at the very begining

    return 0;
}