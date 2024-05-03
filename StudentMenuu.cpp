int main() {

    // if student and he loged in
    int choice = StudenMenu(1);
    StudenChoice(choice, 1); // pass 1 to both functions if log in

    // if student and he signed in
    choice = StudenMenu(2);
    StudenChoice(choice, 2); // pass 2 to both functions if sign in

    return 0;
}
int StudenMenu(int number)
{
    int choice;
    switch (number) {
    case 1: // case log in
    {

        cout << "\t\ do you want to : \n";
        cout << "\t\ a:take up an exam ? press 1 to do so\n";
        cout << "\t\ b: view grades for a subject ? press 2 to do so\n";
        cout << "\t\ c: view all your grades ? press 3 to do so\n";
        cout << "\t\ d: exit your account ? press 4 to do so\n";
        cin >> choice;
        return choice;
    }
    break;
    case 2: // case sign in
    {
        cout << "\t\ do you want to : \n";
        cout << "\t\ a: take up an exam ? press 1 to do so\n";
        cout << "\t\ b: exit your account ? press 2 to do so\n";
        cin >> choice;
        return choice;
    }
    break;
    }
}

void StudenChoice(int choice, int number) {
    string subjectName;
    int id;
    bool loopcondition = true;
    if (number == 1) {

        switch (choice) {

        case 1:
        {
            // cout available exams
            // take exam function
        }
        break;
        case 2:
        {
            cout << " enter subject name and your ID to view your grades " << endl;
            cout << "enter subject name " << endl;
            cin >> subjectName;
            cout << "enter you ID " << endl;
            cin >> id;
            ViewSubjectGrades(subjectName, id);
        }
        break;
        case 3:
        {
            cout << "enter your ID to view all your grades\n";
            cin >> id;
            ViewAllMyGrades(id);
        }
        break;
        case 4:
            break;
        default:
            cout << "Invalid choice!\n";
            break;

        }

    }
    else if (number == 2) {

        switch (choice) {

        case 1:
        {
            // cout available exams
            // take exam function
        }
        break;
        case 2:
            break;
        default:
            cout << "Invalid choice!\n";
            break;
        }

    }
}
