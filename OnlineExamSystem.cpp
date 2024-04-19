#include <iostream>
#include <string>
// For using the getline function
using namespace std;

struct choice
{
    string choiceText;
    bool isCorrect = false;
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


// Database for all questions
question *englishQuestionList= new question;
question *mathQuestionList = new question;
question *biologyQuestionList = new question;
question *chemistryQuestionList = new question;
question *physicsQuestionList = new question;



void createQuestion(question*questionBank, int index);
int currentTeacher = 0;
int main()
{  // this will be in the menu that the teacher sees AS AN EXAMPLE
    cout << " Press 1 if you want to create a new question!\n";
    // presses 1
    if (arrTC[currentTeacher].CourseCode == "E266")
        createQuestion(englishQuestionList, englishQuestionIndex);
    else if (arrTC[currentTeacher].CourseCode == "M161")
        createQuestion(mathQuestionList, mathQuestionIndex);
    else if (arrTC[currentTeacher].CourseCode == "B859")
    createQuestion(biologyQuestionList, biologyQuestionIndex);
    else if (arrTC[currentTeacher].CourseCode == "C602")
    createQuestion(chemistryQuestionList, chemistryQuestionIndex);
    else if (arrTC[currentTeacher].CourseCode == "P667");
    createQuestion(physicsQuestionList, physicsQuestionIndex);

    //deallocating the arrays;
    {
        delete[] englishQuestionList;
        englishQuestionList = NULL;
        delete[] mathQuestionList;
        mathQuestionList = NULL;
        delete[] biologyQuestionList;
       biologyQuestionList = NULL;
        delete[] chemistryQuestionList;
        chemistryQuestionList = NULL;
        delete[] physicsQuestionList;
       physicsQuestionList = NULL;
    }

}

void createQuestion(question* questiontype, int index)
{
    cout << "Please enter your question: \n";
    getline(cin, questiontype[index].questionText);
    // Using getline to input the full sentence instead of only one word

    // For loop for entering choices
    for (int i = 0; i < 4; i++)
    {
        char option;
        cout << "Please enter choice " << i + 1 << endl;
        getline(cin, questiontype[index].questionAnswer[i].choiceText);
        cin.ignore();
        // To ignore the extra character added by the 'enter key'

        questiontype[index].questionAnswer[i].isCorrect = false;

        do
        {
            cout << "T/F? (any true will automatically set all the rest to false!) \n";
            cin >> option;
            cin.ignore();
            // Same thing here
            if (option == 'F' || option == 'f')
            {
                questiontype[index].questionAnswer[i].isCorrect = false;
                break;
            }
            else if (option == 'T' || option == 't')
            {
                questiontype[index].questionAnswer[i].isCorrect = true;
                i = 4;
                // to exit the loop immediately
                break;
            }
            else
                cout << "Error! Please enter a valid choice! \n";
        } while (true);
    }
index++;
}
