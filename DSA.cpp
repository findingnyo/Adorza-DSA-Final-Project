#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int MAX_QUESTIONS = 100;

struct Question {
    string category;
    string text;
    string options[4];
    int corIndex;
};

Question questions[MAX_QUESTIONS];
int questionCount = 0;

// ADDING QUESTIONS

void addQues() {
    if (questionCount >= MAX_QUESTIONS) {
        cout << "Question limit reached!\n";
        return;
    }

    Question q;
    cin.ignore();
    cout << "Enter category (Science/Tech/Society): ";
    getline(cin, q.category);
    cout << "Enter question: ";
    getline(cin, q.text);

    for (int i = 0; i < 4; ++i) {
        cout << "Option " << char('A' + i) << ": ";
        getline(cin, q.options[i]);
    }

    cout << "Enter correct option index (0-3): ";
    cin >> q.corIndex;

    questions[questionCount++] = q;
    cout << "Question added!\n";
}

// DELETING QUESTIONS

void delete() {
    int index;
    cout << "Enter index to delete: ";
    cin >> index;

    if (index < 0 || index >= questionCount) {
        cout << "Invalid index.\n";
        return;
    }

    for (int i = index; i < questionCount - 1; ++i) {
        questions[i] = questions[i + 1];
    }
    questionCount--;
    cout << "Question deleted.\n";
}

// DISPLAYING ALL QUESTIONS

void displayAll() {
    for (int i = 0; i < questionCount; ++i) {
        cout << "[" << i << "] (" << questions[i].category << ") " << questions[i].text << "\n";
        for (int j = 0; j < 4; ++j) {
            cout << "   " << char('A' + j) << ". " << questions[i].options[j] << "\n";
        }
        cout << "   Answer: " << char('A' + questions[i].corIndex) << "\n\n";
    }
}

// PLAY

void play() {
    int score = 0;
    for (int i = 0; i < questionCount; ++i) {
        cout << "(" << questions[i].category << ") " << questions[i].text << endl;
        for (int j = 0; j < 4; ++j) {
            cout << "   " << char('A' + j) << ". " << questions[i].options[j] << endl;
        }
        char answer;
        cout << "Your answer (A-D): ";
        cin >> answer;

        int ansIndex = toupper(answer) - 'A';
        if (ansIndex == questions[i].corIndex) {
            cout << "Correct!\n";
            score++;
        } else {
            cout << "Wrong! Correct answer is " << char('A' + questions[i].corIndex) << ".\n";
        }
        cout << "\n";
    }
    cout << "Quiz finished! Your score: " << score << "/" << questionCount << endl;
}

// SEARCH

void search() {
    cin.ignore();
    string keyword;
    cout << "Enter keyword to search: ";
    getline(cin, keyword);

    for (int i = 0; i < questionCount; ++i) {
        if (questions[i].text.find(keyword) != string::npos) {
            cout << "[" << i << "] (" << questions[i].category << ") " << questions[i].text << endl;
        }
    }
}

// SORTING

void sort() {
    for (int i = 0; i < questionCount - 1; ++i) {
        for (int j = 0; j < questionCount - i - 1; ++j) {
            if (questions[j].category > questions[j + 1].category) {
                swap(questions[j], questions[j + 1]);
            }
        }
    }
    cout << "Questions sorted by category.\n";
}

// DISPLAY MENU

void displayMenu() {
    cout << "\n==== Quiz Game Menu ====\n";
    cout << "1. Play Quiz\n";
    cout << "2. Add Question\n";
    cout << "3. Delete Question\n";
    cout << "4. Sort by Category\n";
    cout << "5. Search Questions\n";
    cout << "6. Display All Questions\n";
    cout << "7. Exit\n";
    cout << "Choose an option: ";
}

void addSampleQuestions() {
    questions[0] = {
        "Science",
        "What is the chemical symbol for water?",
        {"O2", "H2O", "CO2", "NaCl"},
        1
    };
    questions[1] = {
        "Tech",
        "Who is known as the father of computers?",
        {"Alan Turing", "Bill Gates", "Charles Babbage", "Steve Jobs"},
        2
    };
    questions[2] = {
        "Society",
        "Which organization is responsible for global health?",
        {"UNESCO", "WHO", "WTO", "IMF"},
        1
    };
    questions[3] = {
        "Society",
        "Which civlization was the first recorded civilizations of the world?",
        {"Mesopotamia", "Babylonian", "Greek", "Egyptian"},
        0
    };
    questions[4] = {
        "Tech",
        "Which invention was invented by the Greeks?",
        {"Sailboat", "Paper", "Wheel", "Alarm Clock"},
        3
    };
    questions[5] = {
        "Society",
        "Who was known for their published book 'The Origin of Species'?",
        {"Nicolaus Copernicus", "Charles Darwin", "Claudius Ptolemy", "Sigmund Freud"},
        1
    };
    questions[6] = {
        "Society",
        "Which personality represents internalized moral standards and ideals?",
        {"Id", "Ego", "Superego", "Psychoanalysis"},
        2
    };
    
    questionCount = 7;

}

int main() {
    cout << "=====================================\n";
    cout << "   Welcome to TechQuest: Play & Learn!\n";
    cout << "=====================================\n";
    cout << "Test your knowledge on Science, Tech, and Society!\n";

    addSampleQuestions();

    int x;
    do {
        displayMenu();
        cin >> x;

        if (x == 1) {
            play();
        } else if (x == 2) {
            addQues();
        } else if (x == 3) {
            deleteQuestion();
        } else if (x == 4) {
            sort();
        } else if (x == 5) {
            search();
        } else if (x == 6) {
            displayAll();
        } else if (x == 7) {
            cout << "Thank you for playing TechQuest!" << endl;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 7);
}
