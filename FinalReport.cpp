#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <algorithm>
using namespace std;

// Structure to hold question, options, and correct answer
struct Question {
    string question;
    string options[4];
    char correctAnswer; // 'A','B','C','D'
};

// helper: convert string to lower-case
string toLowerStr(const string &s) {
    string t = s;
    transform(t.begin(), t.end(), t.begin(), [](unsigned char c){ return tolower(c); });
    return t;
}

// Function to show one question and check the answer
bool askQuestion(const Question &q) {
    cout << "\n" << q.question << "\n";
    for (int i = 0; i < 4; i++) {
        cout << char('A' + i) << ") " << q.options[i] << endl;
    }

    string input;
    cout << "\nEnter your answer (A/B/C/D) or type option (e.g. ls) or 'F' to exit: ";
    cin >> input;

    if (input.empty()) input = " "; 
    string inputUpper = input;
    transform(inputUpper.begin(), inputUpper.end(), inputUpper.begin(), [](unsigned char c){ return toupper(c); });
    string inputLower = toLowerStr(input);

    if (inputUpper == "F") {
        cout << "\n👋 Exiting the quiz... Thanks for playing!\n";
        exit(0);
    }

    // Resolve the user's answer to a letter A-D
    char answerLetter = '\0';
    if (inputUpper.size() == 1 && inputUpper[0] >= 'A' && inputUpper[0] <= 'D') {
        answerLetter = inputUpper[0];
    } else {
        for (int i = 0; i < 4; ++i) {
            if (toLowerStr(q.options[i]) == inputLower) {
                answerLetter = char('A' + i);
                break;
            }
        }
    }

    if (answerLetter == '\0') {
        cout << "❌ Invalid answer format.\n";
        cout << "👉 Correct answer: " << q.correctAnswer << ") " << q.options[q.correctAnswer - 'A'] << "\n";
        return false;
    }

    if (answerLetter == q.correctAnswer) {
        cout << "✅ Correct Answer!\n";
        return true;
    } else {
        cout << "❌ Wrong answer.\n";
        cout << "👉 Correct answer: " << q.correctAnswer << ") " << q.options[q.correctAnswer - 'A'] << "\n";
        return false;
    }
}

int main() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif

    cout << "=============================================\n";
    cout << "         🧠 C++ & LINUX QUIZ GAME            \n";
    cout << "=============================================\n";
    cout << "Rules:\n";
    cout << "👉 Answer each question (A/B/C/D) or type the option.\n";
    cout << "👉 Wrong answers show the correct one and move on.\n";
    cout << "👉 Press 'F' anytime to exit.\n";
    cout << "=============================================\n\n";

    // List of Linux + C++ questions
    Question questions[] = {
        // --- Linux Questions ---
        {"1️⃣ Which command lists all files and directories?",
         {"ls", "pwd", "cat", "cd"}, 'A'},

        {"2️⃣ Which command shows the current working directory?",
         {"who", "cd", "pwd", "dir"}, 'C'},

        {"3️⃣ Which command is used to change directories?",
         {"mv", "cd", "rm", "ls"}, 'B'},

        {"4️⃣ Which command displays the contents of a file?",
         {"cat", "ls", "nano", "grep"}, 'A'},

        {"5️⃣ Which command removes a file?",
         {"delete", "erase", "rm", "clear"}, 'C'},

        {"6️⃣ Which command shows running processes?",
         {"run", "ps", "proc", "top"}, 'B'},

        {"7️⃣ Which command shows manual pages?",
         {"help", "man", "guide", "show"}, 'B'},

        {"8️⃣ Which command clears the terminal screen?",
         {"clean", "clear", "erase", "cls"}, 'B'},

        {"9️⃣ Which command copies files?",
         {"copy", "cp", "mv", "clone"}, 'B'},

        {"🔟 Which command shows current date?",
         {"now", "time", "date", "cal"}, 'C'},

        // --- C++ Questions ---
        {"11️⃣ Which header file is used for input and output in C++?",
         {"stdio.h", "iostream", "fstream", "stdlib.h"}, 'B'},

        {"12️⃣ What is the correct syntax to output 'Hello World' in C++?",
         {"printf('Hello World');", "cout << 'Hello World';", "System.out.println('Hello World');", "Console.Write('Hello World');"}, 'B'},

        {"13️⃣ Which of the following is a valid C++ data type?",
         {"string", "word", "alphabet", "real"}, 'A'},

        {"14️⃣ Which operator is used to take input in C++?",
         {"<<", ">>", "->", "::"}, 'B'},

        {"15️⃣ Which keyword is used to define a class in C++?",
         {"function", "method", "class", "struct"}, 'C'},

        {"16️⃣ Which of the following is used to define a constant in C++?",
         {"const", "define", "constant", "final"}, 'A'},

        {"17️⃣ Which symbol is used to terminate a statement in C++?",
         {".", ",", ";", ":"}, 'C'},

        {"18️⃣ Which of the following is a valid loop in C++?",
         {"repeat", "loop", "while", "iterate"}, 'C'},

        {"19️⃣ Which keyword is used to create an object dynamically in C++?",
         {"malloc", "alloc", "new", "make"}, 'C'},

        {"20️⃣ Which of the following is a correct way to start the main function?",
         {"int main()", "void main()", "function main()", "main()"}, 'A'}
    };

    int totalQuestions = sizeof(questions) / sizeof(questions[0]);
    int score = 0;

    for (int i = 0; i < totalQuestions; i++) {
        bool correct = askQuestion(questions[i]);
        if (correct) ++score;
    }

    cout << "\n=============================================\n";
    cout << "🎉 You finished the quiz!\n";
    cout << "🏆 Your final score: " << score << " / " << totalQuestions << "\n";
    cout << "=============================================\n";

    char choice;
    cout << "\nDo you want to play again? (Y/N): ";
    cin >> choice;
    choice = toupper(choice);
    if (choice == 'Y') {
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
        main();
    } else {
        cout << "\n👋 Goodbye! Thanks for playing!\n";
    }

    return 0;
}
