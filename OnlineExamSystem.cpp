#include <iostream>
#include <string>
// For using the getline function
using namespace std;

struct choice
{
    string choiceText;
    bool isCorrect;
};

struct question
{
    string questionText;
    choice questionAnswer[4];
};

int questionIndex = 0;

// Database for all questions
question englishQuestionList[10];
question mathQuestionList[10];
question biologyQuestionList[10];
question chemistryQuestionList[10];
question physicsQuestionList[10];

void createQuestion();

int main()
{}

void createQuestion()
{
    // Switch case to see which subject is to be used not yet included
    // For example, I'm choosing English

    cout << "Please enter your question: \n";
    getline(cin, englishQuestionList[questionIndex].questionText);
    // Using getline to input the full sentence instead of only one word

    // For loop for entering choices
    for (int i = 0; i < 4; i++)
    {
        char option;
        cout << "Please enter choice " << i + 1 << endl;
        getline(cin, englishQuestionList[questionIndex].questionAnswer[i].choiceText);
        cin.ignore();
        // To ignore the extra character added by the 'enter key'

        do
        {
            cout << "T/F?";
            cin >> option;
            cin.ignore();
            // Same thing here

            if (option == 'T' || option == 't')
            {
                englishQuestionList[questionIndex].questionAnswer[i].isCorrect = true;
                break;
            }
            else if (option == 'F' || option == 'f')
            {
                englishQuestionList[questionIndex].questionAnswer[i].isCorrect = false;
                break;
            }
            else
                cout << "Error! Please enter a valid choice! \n";
        } while (true);
    }
    questionIndex++;
}
