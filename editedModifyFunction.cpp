
void displayQuestion(int ARRAYSIZE1); // function to display the questions it takes the number of questions enterd by the teacher

void modifyexam(question questiontype[], int ARRAYSIZE1);

void modifyexam(question questiontype[], int ARRAYSIZE1)
{
    char answer, choiceAnswer;
    int deletedindex, editedquestionIndex, editQuestionChoiceIndex, editChoiceIndex;
    
    bool loopcondition = true;

    while (loopcondition == true) {

        displayQuestion(ARRAYSIZE1); //to display after each change in question list
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
                questiontype[i - 1] = questiontype[i];
            }
            ARRAYSIZE1--; // to decreas number of questions after deleting  
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
             getline(cin,questiontype[editedquestionIndex - 1].questionText);
            cin.ignore();
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
             getline(cin,questiontype[editQuestionChoiceIndex - 1].questionAnswer[editChoiceIndex - 1].choiceText);
            cin.ignore();

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



void displayQuestion(int ARRAYSIZE1) {
    for (int i = 0; i < ARRAYSIZE1; i++)
    {
        cout << i + 1 << "_ " << chemistryQuestionList[i].questionText << " ?" << endl;


        for (int j = 0; j < 4; j++)
        {
            cout << j + 1 << "_ " << chemistryQuestionList[i].questionAnswer[j].choiceText << " ." << endl;


        }
    }
}
