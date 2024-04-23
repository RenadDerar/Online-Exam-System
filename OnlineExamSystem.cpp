#include <iostream>
#include <string>
#include <fstream>
// For using the getline function
using namespace std;

struct choice
{
    string choiceText;
    bool isCorrect= false;
};

struct question
{
    string questionText;
    choice questionAnswer[4];
};

//question indicies 
int englishQuestionIndex = 0;
int mathQuestionIndex = 0;
int biologyQuestionIndex = 0;
int chemistryQuestionIndex = 0;
int physicsQuestionIndex = 0;

struct teacher
{
    string username, password, CourseCode;
}arrTC[5];
 
const int ARRAYSIZE = 10;

question englishQuestionList[ARRAYSIZE];
question mathQuestionList[ARRAYSIZE];
question biologyQuestionList[ARRAYSIZE];
question chemistryQuestionList[ARRAYSIZE];
question physicsQuestionList[ARRAYSIZE];





void createQuestion(question*questionBank, int index);
int currentTeacher = 0;
int main()
{  // this will be in the menu that the teacher sees AS AN EXAMPLE
   // cout << " Press 1 if you want to create a new question!\n";
    

    ifstream questionFile("questionsList.txt");
    //loading from file pre-existing questions
    //english
        for (int i = 0; i < 3; i++)
        {
            getline(questionFile, englishQuestionList[i].questionText);


            for (int j = 0; j < 4; j++)
            {
                getline(questionFile, englishQuestionList[i].questionAnswer[j].choiceText);
            }
        }
        //math
        for (int i = 0; i < 3; i++)
        {
            getline(questionFile, mathQuestionList[i].questionText);


            for (int j = 0; j < 4; j++)
            {
                getline(questionFile, mathQuestionList[i].questionAnswer[j].choiceText);
            }
        }
        //chemistry
        for (int i = 0; i < 3; i++)
        {
            getline(questionFile, chemistryQuestionList[i].questionText);


            for (int j = 0; j < 4; j++)
            {
                getline(questionFile, chemistryQuestionList[i].questionAnswer[j].choiceText);
            }
        }
        //physics
        for (int i = 0; i < 3; i++)
        {
            getline(questionFile, physicsQuestionList[i].questionText);


            for (int j = 0; j < 4; j++)
            {
                getline(questionFile, physicsQuestionList[i].questionAnswer[j].choiceText);
            }
        }
        //biology
        for (int i = 0; i < 3; i++)
        {
            getline(questionFile, biologyQuestionList[i].questionText);


            for (int j = 0; j < 4; j++)
            {
                getline(questionFile, biologyQuestionList[i].questionAnswer[j].choiceText);
            }
        }
    

    return 0;

}

void createQuestion(question questiontype[], int index)
{
    cout << "Please enter your question: \n";
    getline(cin, questiontype[index].questionText);
    // Using getline to input the full sentence instead of only one word

    // For loop for entering choices
    for (int i = 0; i < 4; i++)
    {
      

        cout << "Please enter choice " << i + 1 << endl;
        getline(cin, questiontype[index].questionAnswer[i].choiceText);
        cin.ignore();
        // To ignore the extra character added by the 'enter key'
        questiontype[index].questionAnswer[i].isCorrect = false;
    }

    int correctChoice;

    cout << "Which choice is the correct choice? Please enter the number in order (From 1 to 4): \n";
    cin >> correctChoice;
    questiontype[index].questionAnswer[correctChoice-1].isCorrect = true;
    index++;

    ////////////////////////////////////////////// to check
    cout << "\nVerification for the created question:\n";
    cout << questiontype[index - 1].questionText << endl; // Access the question at the current index

    for (int i = 0; i < 4; i++) 
    {
        cout << "  - " << questiontype[index - 1].questionAnswer[i].choiceText << endl;
        if (questiontype[index - 1].questionAnswer[i].isCorrect)
            cout << "    (Correct Answer)" << endl; // Mark the correct answer
    }
}
