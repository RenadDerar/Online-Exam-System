#include <iostream>
#include <string>
#include <fstream>
#include <windows.h> // for Sleep()
#include <stdlib.h> // for the system()

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

//all functions
void createQuestion(question questionBank[], int index);
void modifyexam(question questiontype[]);
void ViewStudentGrades(const string& ExamName);

void ViewSubjectGrades(const string& subject);
void ViewAllMyGrades(int ID);

void timerFunction(int min);

int teacherMenu();
void handleChoice(int choice);


int currentTeacher = 0;
int main()

{
    /* first thing in main, loading from file pre - existing questions
english*/
    ifstream questionFile("questionsList.txt");
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

    // this will be in the menu that the teacher sees AS AN EXAMPLE
   // cout << " Press 1 if you want to create a new question!\n";
    {
        if (arrTC[currentTeacher].CourseCode == "E266")
            createQuestion(englishQuestionList, englishQuestionIndex);
        else if (arrTC[currentTeacher].CourseCode == "M161")
            createQuestion(mathQuestionList, mathQuestionIndex);
        else if (arrTC[currentTeacher].CourseCode == "B859")
            createQuestion(biologyQuestionList, biologyQuestionIndex);
        else if (arrTC[currentTeacher].CourseCode == "C602")
            createQuestion(chemistryQuestionList, chemistryQuestionIndex);
        else if (arrTC[currentTeacher].CourseCode == "P667")
            createQuestion(physicsQuestionList, physicsQuestionIndex);
    }

    ///////////////////////////////////////////////////
     // when a teacher wants to see their students grades
    string ExamFileName;
    cout << "What is the name of the exam file you want to see the grades of: ";
    cin >> ExamFileName;

    // when a student wants to see their grades in a specific subject
    int ID;
    string subject;
    cout << "What subject do you want to see the grades of: ";
    cin >> subject;
    cout << "Please enter your ID for conformation:";
    cin >> ID;

    // when a student wants to see all of their grades
    cout << "Please enter your ID for conformation:";
    cin >> ID;

    ////////////////////////////////////////////////////

    int choice = teacherMenu();
    handleChoice(choice);

    /////////////////////////////////////////////////////
    //   case he want to modify exam
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
    ////////////////////////////this part is to be included in createxam u guys! nada and mishkat//////////////////////////////
    int minutes;

    cout << "enter how many minutes will the exam be?" << endl;
    cin >> minutes;
    timerFunction(minutes);


    return 0;

}

// a function for the teacher to create new questions for their exams
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
    questiontype[index].questionAnswer[correctChoice - 1].isCorrect = true;
    index++;
}

//a function that lets the teacher modify exams

//modifing exam
void modifyexam(question questiontype[])
{
    char answer, d, D, a, A, f, F, choiceAnswer;
    int deletedindex, editedquestionIndex, editQuestionChoiceIndex, editChoiceIndex;
    bool loopcondition = true;

    while (loopcondition == true) {


        cout << "press: d for deleting a Question " << endl;
        cout << "press: e for editing a Question " << endl;
        cout << "press: f for editing a choice " << endl;
        cout << "press: n to exite" << endl;
        cin >> answer;



        switch (answer)
        {

            //     case he want to delete a Question

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
        //      case he want to edit a question

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
        //     case he want to edit a choice
        case 'f':
        case 'F':
        {
            cout << "enter number of Question you want to edit its choice" << endl;
            cin >> editQuestionChoiceIndex;

            cout << "enter number of choice you want to edit " << endl;
            cin >> editChoiceIndex;

            //  enter the choice update
            cout << "enter the edited choice" << endl;
            cin >> questiontype[editQuestionChoiceIndex - 1].questionAnswer[editChoiceIndex - 1].choiceText;

            cout << "is the new choice correct? y/n" << endl;
            cin >> choiceAnswer;

            if (choiceAnswer == 'Y' || choiceAnswer == 'y')
            {
                // seting the rest choices to false 
                for (int i = 0; i < 4; i++)
                {
                    questiontype[editQuestionChoiceIndex - 1].questionAnswer[4].isCorrect = false;
                }
                questiontype[editQuestionChoiceIndex - 1].questionAnswer[editChoiceIndex - 1].isCorrect = true;
            }
            else
            {
                questiontype[editQuestionChoiceIndex - 1].questionAnswer[editChoiceIndex - 1].isCorrect = false;
            }
        }
        break;
        // case he want to exit
        case 'n':
        case 'N':
            loopcondition = false; // to exite the loop and go bake to main
            break;

        }
    }


}

//creating an exam

// a function for the teacher to view their students grades
void ViewStudentGrades(const string& ExamFileName)
{
    string grades;
    ifstream GradeFile;

    GradeFile.open(ExamFileName + ".txt", ios::in);       // opens the file 
    if (!GradeFile.is_open())
    {
        cout << "Failed to open the file." << endl;
        return;                                       // exits function if the file failed to open
    }
    else
    {
        cout << "\t Student Grades in the " << ExamFileName << "\t" << endl;
        cout << "------------------------------------------------------" << endl;
        while (getline(GradeFile, grades))           // reads the file line by line
        {
            cout << "\t" << grades << "\t" << endl;
        }
        GradeFile.close();
    }
}

// a function for the students to view the grades of a specific subject
void ViewSubjectGrades(const string& subject, int ID)
{
    string grades;
    ifstream GradeFile;
    bool SDfound = false;
    for (int i = 0; i < 10; i++)
    {
        if (arrSD[i].ID == ID)
        {
            SDfound = true;
            string ID_str = to_string(ID);   // converts the ID into string for the filename
            GradeFile.open(subject + " Grades for Student no.: " + ID_str + ".txt", ios::in);     // opens the file 
            if (!GradeFile.is_open())
            {
                cout << "Failed to open the file. (Check the spelling of the subject entered)" << endl;
                return;                                         // exits function if the file failed to open
            }
            else
            {
                cout << "\t" << "\t" << "\t" << "\t" << subject << " Grades\t" << endl;
                cout << "-----------------------------------------------------------------------------------------" << endl;
                while (getline(GradeFile, grades))           // reads the file line by line
                {
                    cout << "\t" << grades;
                }
                GradeFile.close();
                return;          // exit the function after printing the grades
            }
        }
    }
    if (!SDfound)
    {
        cout << "Invalid or Incorrect ID." << endl;
    }
}

// a function for the students to view all their grades on all the exams they've part took in
void ViewAllMyGrades(int ID)
{
    string grades;
    ifstream GradeFile;
    bool SDfound = false;
    for (int i = 0; i < 10; i++)
    {
        if (arrSD[i].ID == ID)
        {
            SDfound = true;
            string ID_str = to_string(ID);   // converts the ID into string for the filename
            GradeFile.open("Grades for Student no.: " + ID_str + ".txt", ios::in);     // opens the file 
            if (!GradeFile.is_open())
            {
                cout << "Failed to open the file. (Check the spelling of the subject entered)" << endl;
                return;                                         // exits function if the file failed to open
            }
            else
            {
                cout << "\t\t\t\tYour Grades\t" << endl;
                cout << "-------------------------------------------------------------------------------------------------------------" << endl;
                while (getline(GradeFile, grades))           // reads the file line by line
                {
                    cout << "\t" << grades;
                }
                GradeFile.close();
                return;          // exit the function after printing the grades
            }
        }
    }
    if (!SDfound)
    {
        cout << "Invalid or Incorrect ID." << endl;
    }
}

//the menu function for the teacher
int teacherMenu()
{
    int choice;
    cout << "\t\ do you want to : \n";
    cout << "\t\ a: create new questions ? press 1 to do so\n";
    cout << "\t\ b: create a new exam ? press 2 to do so\n";
    cout << "\t\ c: modify a previous exam ? press 3 to do so \n";
    cout << "\t\ d: view your students grades ? press 4 to do so  \n";
    cin >> choice;
    return choice;
}
void handleChoice(int choice) {
    switch (choice) {
    case 1:
    {
        cout << "Creating new questions...\n";
        // createQuestion(questionBank[],index);
    }
    break;
    case 2:
        cout << "Creating a new exam...\n";
        //code for creating an exam here (still not present)
        break;
    case 3:
        cout << "Modifying a previous exam...\n";
        // code for modifying an exam here
        break;
    case 4:
        cout << "Viewing students' grades...\n";
        //ViewStudentGrades(const string & ExamFileName)
        break;
    default:
        cout << "Invalid choice!\n";
        break;
    }
}
void timerFunction(int min) {
    int sec = 0;
    int minutes = min;
    while (true) {
        if (min == 0 && sec == 0) {
            break;
        }
        if (sec == 0) {
            sec = 60;
            min--;
        }
        system("cls");    // to stop repeating cout statement each loop iteration
        cout << ">>>> the exam time is " << minutes << " minutes " << " <<<<" << endl;
        cout << "time left: " << min << ":" << sec-- << endl;

        Sleep(1000);     //for the speed of timer >> will get back to loop every 1000 milliseconds after printing the min and sec

    }
    cout << "time is up !" << endl;


}



