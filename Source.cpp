#include <iostream> 
#include <fstream> 
#include <string>

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

void ViewStudentGrades(string &subj);

using namespace std;

int main()
{

	return 0;
}

void ViewStudentGrades(string &subj)
{
	string grades;
	string GradeFileName = subj + " Grades.txt";
	ifstream GradeFile(GradeFileName);
	if (!GradeFile.is_open())
	{
		cout << "Trouble with opening the file." << endl;
	}
	else
	{
		while (!GradeFile.eof())
		{
			std::getline(GradeFile, grades);
			cout << "\t Student Grades in \t" << subj << endl;
			cout << "---------------------------------------" << endl;
			cout << grades << endl;
		}
		GradeFile.close();
	}
}