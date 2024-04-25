#include <iostream>
#include <string>
#include <fstream>

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


struct subject
{
    string CourseCode;
    float grade;
}arrSJ[5];
struct teacher
{
    string username, password, CourseCode;
}arrTC[5];
struct student
{
    string username, password;
    int ID;
    subject subj;
}arrSD[10];


//question indicies 
int englishQuestionIndex = 3;
int mathQuestionIndex = 3;
int biologyQuestionIndex = 3;
int chemistryQuestionIndex = 3;
int physicsQuestionIndex = 3;

//question arrays
const int ARRAYSIZE = 10;
question englishQuestionList[ARRAYSIZE];
question mathQuestionList[ARRAYSIZE];
question biologyQuestionList[ARRAYSIZE];
question chemistryQuestionList[ARRAYSIZE];
question physicsQuestionList[ARRAYSIZE];



void modifyexam(question questiontype[]);
int currentTeacher = 0;
int main()
{
    //   case he want to modify exam
    if (arrTC[currentTeacher].CourseCode == "E266")
        modifyexam(englishQuestionList);
    else if (arrTC[currentTeacher].CourseCode == "M161")
        modifyexam(mathQuestionList);
    else if (arrTC[currentTeacher].CourseCode == "B859")
        modifyexam(biologyQuestionList);
    else if (arrTC[currentTeacher].CourseCode == "C602")
        modifyexam(chemistryQuestionList);
    else if (arrTC[currentTeacher].CourseCode == "P667")
        modifyexam(physicsQuestionList);
    return 0;
}



//modifing exam
void modifyexam(question questiontype[]) {
    char answer, d, D, a, A, f, F, choiceAnswer;
    int deletedindex, editedquestionIndex, editQuestionChoiceIndex, editChoiceIndex;
    bool loopcondition = true;

    while (loopcondition == true) {


        cout << "press: d for deleting a Question " << endl;
        cout << "press: e for editing a Question " << endl;
        cout << "press: f for editing a choice " << endl;
        cout << "press: n to exite" << endl;
        cin >> answer;



        switch (answer) {

            //     case he want to delete a Question

        case 'd':
        case 'D':
        {
            cout << "enter number of Question you want to delete" << endl;
            cin >> deletedindex;
            for (int i = deletedindex; i < ARRAYSIZE; i++) {
                questiontype[deletedindex - 1] = questiontype[deletedindex + 1];
            }
        }
        break;
        //      case he want to edit a question

        case 'e':
        case 'E':
        {
            cout << "enter number of Question you want to edit" << endl;
            cin >> editedquestionIndex;
            //enter the question update
            cout << "enter the edited Question" << endl;
            cin >> questiontype[editedquestionIndex - 1].questionText;
        }
        break;
        //     case he want to edit a choice
        case 'f':
        case 'F': {
            cout << "enter number of Question you want to edit its choice" << endl;
            cin >> editQuestionChoiceIndex;
            cout << "enter number of choice you want to edit " << endl;
            cin >> editChoiceIndex;
            //  enter the choice update
            cout << "enter the edited choice" << endl;
            cin >> questiontype[editQuestionChoiceIndex - 1].questionAnswer[editChoiceIndex - 1].choiceText;

            cout << "is the new choice correct? y/n" << endl;
            cin >> choiceAnswer;
            if (choiceAnswer == 'Y' || choiceAnswer == 'y') {
                // seting the rest choices to false 
                for (int i = 0; i < 4; i++) {
                    questiontype[editQuestionChoiceIndex - 1].questionAnswer[4].isCorrect = false;
                }
                questiontype[editQuestionChoiceIndex - 1].questionAnswer[editChoiceIndex - 1].isCorrect = true;
            }
            else {
                questiontype[editQuestionChoiceIndex - 1].questionAnswer[editChoiceIndex - 1].isCorrect = false;
            }
        }
                break;
                // case he want to exist
        case 'n':
        case 'N':
            loopcondition = false; // to exite the loop and go bake to main
            break;
        }
    }


}