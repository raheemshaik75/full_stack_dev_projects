//Includes the processor directives
#include <stdio.h>
#include <math.h>

// Basically this void function that I have created is to display a farewell message to the user
void exitProgram() { // The function main begins
  printf("Thanks for using my Simple Calculator. Hope to see you again soon. "
         "Goodbye! "); // this is entred once the user has exit the program by selecting option E
}

int main() {
    printf("Welcome to my Command-line Calculator (CLC)\n");
    printf("Developer: Abdur Raheem Shaik\n");
    printf("Version: Assignment 1\n");
    printf("Date: 2023-10-24\n");
    printf("---------------------------------------\n");
    printf("Select one of the following items:\n");
    printf("(B) Binary Mathematical Operations, such as addition and subtraction.\n");
    printf("(U) Unary Mathematical Operations, such as square root, and log.\n");
    printf("(A) Advances Mathematical Operations, using variables, arrays.\n");
    printf("(V) Define variables and assign them values.\n");
    printf("(E) Exit\n");

    char option;
  // Reads the option that has been selected by the user and  into option
    scanf(" %c", &option);

    int loop = 1;

    while(loop == 1) { 
        int num1; // defining the variables, first number 
        int num2; // second number
        char operation; 
        int result;

        if(option == 'B'){ //This will only run when B is entered
            printf("Please enter first number:\n"); //Gets first number 
            scanf("%d", &num1);
            printf("Please select your operation: (+, -, *, /, %, ^)\n"); //Gets the operation from the user
            scanf(" %c", &operation);
            printf("Please enter second number:\n"); //Gets the second number
            scanf("%d", &num2);
          // So if the option selected by the user is B then it will ask fro the first number and the operation and then the second number 


            switch(operation){ // switch function being used to determine what to do by the specific operater being entered by the user
                case '+': // if addition is selected it will add the first and second numbers
                    result = num1 + num2;
                    printf("Result is: %d\n", result);
                    break;
                case '-': // if subtraction is selected it will subtract the first and second numbers
                    result = num1 - num2;
                    printf("Result is: %d\n", result);
                    break;
                case '*': // if multiplication is selected then it will multiply the first and second numbers
                    result = num1 * num2;
                    printf("Result is: %d\n", result);
                    break;
                case '/': // if division is selected then it will divide the first and second numbers
                    if(num2 !=0) { // if dividing by zero then it will print an error message
                      result = num1 / num2;
                      printf("Result is: %d\n", result);
                    } else {
                      printf("Error: You have divided by zero. Please try again!\n");
                    }
                    break;
                case '%':
                    result = num1 % num2;
                    printf("Result is: %d\n", result);
                    break;
                case '^':
                    result = num1 ^ num2;
                    printf("Result is: %d\n", result);
                    break;
                default:
                    printf("Error: Invalid input please slect an operation from here (+, -, *, /, %, ^)."); // if anything other than these operations are inputed then an error message will be displayed  to the user
                    break;
            }
        } else if(option == 'E') { 
            loop = 0;
        } else {
            printf("Sorry, at this time I don't have enough knowledge to serve you in this category.");
        }   // So as long as the option is not E the program will keep running but if E if is entred by the user then the program will exit and it will stop running

        if(loop != 0){
          // Informing the user to select an option and if the the loop is does not exit will enter this to start anothe one
            printf("To begin another calculation, please select your option: (B, U, A, V, E)\n");
            scanf(" %c", &option);
        }
    }

    exitProgram(); //Once the program has exited the program it will call the exitProgram function and state a farewell message that had been assigned at the very begining
  
    return 0;
}