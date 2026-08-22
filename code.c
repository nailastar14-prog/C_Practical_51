

#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Structure to store question data
struct Question {
    char question[256];
    char optionA[100];
    char optionB[100];
    char optionC[100];
    char optionD[100];
    char correctAnswer;  // A, B, C, or D
};

int main() {
    // Array of 10 questions
    struct Question quiz[10] = {
        {
            "What is the capital of France?",
            "London",
            "Berlin",
            "Paris",
            "Madrid",
            'C'
        },
        {
            "Which planet is known as the Red Planet?",
            "Venus",
            "Mars",
            "Jupiter",
            "Saturn",
            'B'
        },
        {
            "What is 2 + 2 * 3?",
            "10",
            "8",
            "6",
            "12",
            'B'
        },
        {
            "Which language is known as the 'language of the web'?",
            "Python",
            "JavaScript",
            "Java",
            "C++",
            'B'
        },
        {
            "What does CPU stand for?",
            "Central Processing Unit",
            "Central Program Utility",
            "Central Processor Union",
            "Computer Personal Unit",
            'A'
        },
        {
            "Which data structure uses LIFO (Last In First Out)?",
            "Queue",
            "Stack",
            "Array",
            "Linked List",
            'B'
        },
        {
            "What is the chemical symbol for Gold?",
            "Go",
            "Gd",
            "Au",
            "Ag",
            'C'
        },
        {
            "Who wrote 'Romeo and Juliet'?",
            "Jane Austen",
            "William Shakespeare",
            "Mark Twain",
            "Charles Dickens",
            'B'
        },
        {
            "What is the smallest prime number?",
            "0",
            "1",
            "2",
            "3",
            'C'
        },
        {
            "Which country has the most population?",
            "India",
            "United States",
            "Indonesia",
            "Pakistan",
            'A'
        }
    };

    // Variables to track score
    int correctCount = 0;
    int wrongCount = 0;
    char userAnswer;
    int i;

    // Display welcome message
 
    printf("\nWelcome to the quiz! Instructions:\n");
    printf("- Answer 10 general knowledge questions\n");
    printf("- Each correct answer = 1 point (Max Score: 10)\n");
    printf("- To PASS: Score must be 5 or higher\n");
    printf("- Enter your answer as A, B, C, or D\n");
    printf("\nLet's start!\n\n");

    // Main quiz loop - ask all 10 questions
    for (i = 0; i < 10; i++) {
       
        printf("Question %d of 10\n", i + 1);
      
        printf("%s\n\n", quiz[i].question);
        
        // Display all 4 options
        printf("A) %s\n", quiz[i].optionA);
        printf("B) %s\n", quiz[i].optionB);
        printf("C) %s\n", quiz[i].optionC);
        printf("D) %s\n\n", quiz[i].optionD);

        // Get user input with validation
        int validInput = 0;
        while (!validInput) {
            printf("Your answer (A/B/C/D): ");
            scanf("%c", &userAnswer);
            
            // Clear input buffer (consume newline character)
            while (getchar() != '\n');
            
            // Convert to uppercase for case-insensitive comparison
            userAnswer = toupper(userAnswer);
            
            // Validate input
            if (userAnswer == 'A' || userAnswer == 'B' || userAnswer == 'C' || userAnswer == 'D') {
                validInput = 1;
            } else {
                printf("Invalid input! Please enter A, B, C, or D.\n\n");
            }
        }

        // Compare user answer with correct answer
        if (userAnswer == quiz[i].correctAnswer) {
            printf("✓ Correct!\n");
            correctCount++;
        } else {
            printf("✗ Wrong! The correct answer is: %c\n", quiz[i].correctAnswer);
            wrongCount++;
        }

        // Display current score progress
        printf("Score so far: %d/10\n\n", correctCount);
    }

    // Calculate results
    int finalScore = correctCount;
    int percentage = (finalScore * 100) / 10;
    char result[5];
    
    if (finalScore >= 5) {
        strcpy(result, "PASS");
    } else {
        strcpy(result, "FAIL");
    }

    // Display final summary report
    printf("\n");
    printf("=====================================\n");
    printf("        QUIZ COMPLETED!              \n");
    printf("=====================================\n");
    printf("Total Correct Answers: %d\n", correctCount);
    printf("Total Wrong Answers:   %d\n", wrongCount);
    printf("Final Score:           %d/10\n", finalScore);
    printf("Percentage:            %d%%\n", percentage);
    printf("Result:                %s\n", result);
    printf("=====================================\n\n");

    return 0;
}
