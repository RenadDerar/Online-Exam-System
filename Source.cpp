#include <iostream> 
#include <fstream> 
#include <string>

struct subject
{
	string CourseCode;                                   
	float grade;
};
struct teacher
{
	string username, password, CourseCode;
}arrTC[5];
struct student
{
	string username, password;
	int ID;
	subject arrSJ[5];
}arrSD[10];
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

void createQuestion(question* questionBank, int index);
void ViewStudentGrades(const string &ExamName);
void ViewSubjectGrades(const string &subject);
void ViewAllMyGrades(int ID);

//question indicies 
int englishQuestionIndex = 0;
int mathQuestionIndex = 0;
int biologyQuestionIndex = 0;
int chemistryQuestionIndex = 0;
int physicsQuestionIndex = 0;

// Database for all questions
question* englishQuestionList = new question;
question* mathQuestionList = new question;
question* biologyQuestionList = new question;
question* chemistryQuestionList = new question;
question* physicsQuestionList = new question;

using namespace std;

int main()
{
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
	return 0;
}

// a function for the teacher to create new queestions for their exams
void createQuestion(question* questionBank, int index)
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
// a function for the teacher to view their students grades
void ViewStudentGrades(const string &ExamFileName)
{
	string grades;
	ifstream GradeFile;

	GradeFile.open(ExamFileName+".txt", ios::in);       // opens the file 
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