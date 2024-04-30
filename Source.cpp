#include <iostream> 
#include <fstream> 
#include <string>

using namespace std;

struct course  // i changed any mention of "subject" into "course" for consistency's sake
{
	string CourseCode,grades[10];                                   
};
struct teacher
{
	string username, password, CourseCode;
}arrTC[5];
struct student
{
	string username, password;
	int ID;
	course arrSJ[5];
}arrSD[10];

void ViewStudentGrades(string& ExamFileName);
void ViewCourseGrades(int ID, string& CourseCode);
void SaveCourseGrades(int ID, string& CourseCode, string& content);
void ViewAllMyGrades(int ID);
void SaveAlMyGrades(int ID, string& content);

int main()
{   
    // When a teacher wants to see their students grades
    string ExamFileName;
    cout << "What is the name of the exam file you want to see the grades of: ";
    cin >> ExamFileName;

    int ID;
    string CourseCode;
    // when a student wants to see the grades of a specific course they've chosen
    cout << "Enter the following information for confirmation: " << endl;
    cout << "ID: ";
    cin >> ID;
    cout << "Course code: ";
    cin >> CourseCode;

    // When a student wants to see all of their grades
    cout << "Please enter your ID for confirmation:";
    cin >> ID;

	return 0;
}

// A function for the teacher to view their students grades
void ViewStudentGrades(string& ExamFileName)
{
    string grades;
    ifstream GradeFile;
    bool FileOpened = false;

    do  // this loop allows the teacher to re enter the exam name in case they've entered it wrong
    {
        GradeFile.open(ExamFileName + " Grades.txt", ios::in); // opens the file 
        if (!GradeFile.is_open())
        {
            char ans;
            cout << "Failed to open the file." << endl;
            cout << "Do you want to try again? (y/n): ";
            cin >> ans;
            switch (ans)
            {
            case 'Y':
            case 'y':
                cout << "Enter the name of the exam you want to see the grades of: ";
                cin >> ExamFileName;
                continue;
            case 'N':
            case 'n':
                return;  // exits the function if the teacher doesn't want to retry, will later be replace with the teacher menu function
            default:
                cout << "Invalid answer! Please enter either y/n." << endl;
                cin >> ans;
                if (ans == 'Y' || ans == 'y')
                    continue;
                else if (ans == 'N' || ans == 'n')
                    return;  // exits the function if the teacher doesn't want to retry, will later be replace with the teacher menu function
            }
        }
        else
        {
            FileOpened = true;
        }
    } while (!FileOpened);

    cout << "\t\t\t\t" << ExamFileName << endl;
    cout << "------------------------------------------------------" << endl;
    while (getline(GradeFile, grades)) // reads the file line by line
    {
        cout << grades << endl;
    }
    GradeFile.close();
    // teacher menu
}
// A function for the students to view the grades of a specific subject
void ViewCourseGrades(int ID, string& CourseCode)
{
        // displays the grades to the student
    bool StudentFound = false;
    bool CourseFound = false;
    string grades;  // saves the grades so it would be easier to put it in a file
    for (int i = 0; i < 10 && !StudentFound; i++)  // searches for the student, & once they're found the loop is exited 
    {
        if (arrSD[i].ID == ID)
        {
            StudentFound = true;
            for (int j = 0; j < 5 && !CourseFound; j++)  // searches for the course code, & once they're found the loop is exited 
            {
                if (arrSD[i].arrSJ[j].CourseCode == CourseCode)
                {
                    CourseFound = true;
                    cout << "\t\t\t\t"<< CourseCode<<" Grades for Student ID no.: " << ID  << endl;
                    cout << "---------------------------------------------------------------------" << endl;
                    for (int k = 0; k < 10; k++)
                    {
                        if (!arrSD[i].arrSJ[j].grades[k].empty() && arrSD[i].arrSJ[j].grades[k] != "garbage")  // doesn't print any empty or garbage values
                        {
                            cout << "Grade " << k + 1 << ": " << arrSD[i].arrSJ[j].grades[k] << endl;
                            grades += "Grade " + to_string(k + 1) + ": " + arrSD[i].arrSJ[j].grades[k] << endl;  // to_string converts the number into string
                        }
                    }
                    return;  // exits the function after printing the grades, will later be replace with the student menu function
                }
            }
        }
    }
    if (!StudentFound)
    {
        cout << "Invalid ID! Please re-enter your information for confirmation." << endl;
        cout << "ID: ";
        cin >> ID;
        cout << "Course code: ";
        cin >> CourseCode;
        ViewCourseGrades(ID, CourseCode);
    }
    else if (!CourseFound)
    {
        cout << "Invalid course code! Please re-enter your information for confirmation." << endl;
        cout << "ID: ";
        cin >> ID;
        cout << "Course code: ";
        cin >> CourseCode;
        ViewCourseGrades(ID,CourseCode);
    }
    SaveCourseGrades(ID, CourseCode, grades);
    // student menu function
}
// A function to save all the grades of a specific course after displaying them to the student
void SaveCourseGrades(int ID, string& CourseCode, string& content)
{
    ofstream GradeFile;
    string ID_str = to_string(ID);   // converts the ID into string for the filename
    GradeFile.open(CourseCode + "Grades for Student ID no.: " + ID_str + ".txt", ios::out | ios::app);  // "app" allows the grades to be added to the same file
    while (!GradeFile.is_open())
    {
        char ans;
        cout << "Failed to open a file to save the grades." << endl;
        cout << "Do you want the program to try again?(y/n): ";
        cin >> ans;
        switch (ans)
        {
        case 'Y':
        case'y':
            break;
        case'N':
        case'n':
            return;  // exits the function , will later be replace with the student menu function
        default:
            cout << "Invalid answer! Please enter either y/n." << endl;
            cin >> ans;
            if (ans == 'Y' || ans == 'y')
                break;
            else if (ans == 'N' || ans == 'n')
                return;  // exits the function, will later be replace with the teacher menu function
        }
    }
    GradeFile << "\t\t\t\t" << CourseCode << " Grades" << endl;
    GradeFile << "------------------------------------------------------" << endl;
    GradeFile << content;
    cout << "Yoour grades have been saved to the file: " << CourseCode + "Grades for Student ID no.: " + ID_str + ".txt" << endl;
    GradeFile.close();
    // student menu
}
// A function for the students to view all their grades on all the exams they've part took in
void ViewAllMyGrades(int ID)
{
    bool StudentFound = false;
    string grades;  // saves the grades so it would be easier to put it in a file

    for (int i = 0; i < 10 && !StudentFound; i++)  // searches for the student, & once they're found the loop is exited 
    {
        if (arrSD[i].ID == ID)
        {
            StudentFound = true;
            cout << "\t\t\t\t Grades for Student ID no.: " << ID << endl;
            cout << "---------------------------------------------------------------------" << endl;
            for (int j = 0; j < 5; j++)  // cycles through each course
            {
                cout << "Course code: " << arrSD[i].arrSJ[j] << endl;
                cout << "--------------------------------------------" << endl;
                for (int k = 0; k < 10; k++)
                {
                    if (!arrSD[i].arrSJ[j].grades[k].empty() && arrSD[i].arrSJ[j].grades[k] != "garbage")  // doesn't print any empty or garbage values
                    {
                        cout << "Grade " << k + 1 << ": " << arrSD[i].arrSJ[j].grades[k] << endl;
                        grades += "Grade " << to_string(k + 1) << ": " << arrSD[i].arrSJ[j].grades[k] << endl;  // to_string converts the number into string
                    }
                }
                return;  // exits the function after printing the grades, will later be replace with the student menu function
            }
        }
    }
    if (!StudentFound)
    {
        cout << "Invalid ID! Please re-enter your information for confirmation." << endl;
        cout << "ID: ";
        cin >> ID;
        ViewAllMyGrades(ID);
    }
    SaveAlMyGrades(ID, grades);
}
// A function to save all the grades in a file after displaying them to the student
void SaveAlMyGrades(int ID,string& content)
{
    ofstream GradeFile;
    string ID_str = to_string(ID);   // converts the ID into string for the filename
    GradeFile.open("Grades for Student ID no.: " + to_string(ID) + ".txt", ios::out | ios::app);  // "app" allows the grades to be added to the same file
    while (!GradeFile.is_open())
    {
        char ans;
        cout << "Failed to open a file to save the grades." << endl;
        cout << "Do you want the program to try again?(y/n): ";
        cin >> ans;
        switch (ans)
        {
        case 'Y':
        case'y':
            break;
        case'N':
        case'n':
            return;  // exits the function , will later be replace with the student menu function
        default:
            cout << "Invalid answer! Please enter either y/n." << endl;
            cin >> ans;
            if (ans == 'Y' || ans == 'y')
                break;
            else if (ans == 'N' || ans == 'n')
                return;  // exits the function, will later be replace with the teacher menu function
        }
    }
    GradeFile << "\t\t\t\t Grades for Student ID no.: " << ID << endl;
    GradeFile << "---------------------------------------------------------------------" << endl;
    GradeFile << content;
    cout << "Your grades have been saved to the file: Grades for Student ID no.: " << to_string(ID) + ".txt" << endl;
    GradeFile.close();
    // student menu function
}