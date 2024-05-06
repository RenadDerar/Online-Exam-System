
void displayQuestion(question questiontype[]); // function to display the questions it takes the number of questions enterd by the teacher

void modifyexam(question questiontype[]);

void modifyexam(question questiontype[])
{
    int answer;
    char choiceAnswer;
    int deletedindex, editedquestionIndex, editQuestionChoiceIndex, editChoiceIndex;

    bool loopcondition = true;

    while (loopcondition == true) {

        displayQuestion(questiontype);
        //to display after each change in question list
        cout << "press: 1 for deleting a Question " << endl;
        cout << "press: 2 for editing a Question " << endl;
        cout << "press: 3 for editing a choice " << endl;
        cout << "press: 4 to exite" << endl;
        cin >> answer;
        cin.ignore();



        switch (answer)
        {

            //     case he want to delete a Question


        case 1:
        {
            cout << "enter number of Question you want to delete" << endl;
            cin >> deletedindex;
            cin.ignore();

            for (int i = deletedindex; i < 10; i++) {
                questiontype[i - 1] = questiontype[i];
            }

            // to stop repeating the last element
            for (int i = 0; i < 9; i++) {
                for (int j = i + 1; j < 10; j++) {
                    
                    if (questiontype[i].questionText == questiontype[j].questionText)
                    {
                        questiontype[j].questionText = "";
                    }


                }
            }
        }
        break;

        //      case he want to edit a question

        case 2:
        {
            cout << "enter number of Question you want to edit" << endl;
            cin >> editedquestionIndex;
            cin.ignore();
            //enter the question update
            cout << "enter the edited Question" << endl;
            getline(cin, questiontype[editedquestionIndex - 1].questionText);
            cin.ignore();
            
            

        }
        break;

        //     case he want to edit a choice

        case 3:
        {
            cout << "enter number of Question you want to edit its choice" << endl;
            cin >> editQuestionChoiceIndex;
            cin.ignore();


            cout << "enter number of choice you want to edit " << endl;
            cin >> editChoiceIndex;
            cin.ignore();


            //  enter the choice update
            cout << "enter the edited choice" << endl;
            getline(cin, questiontype[editQuestionChoiceIndex - 1].questionAnswer[editChoiceIndex - 1].choiceText);
            cin.ignore();

            cout << "is the new choice correct? y/n" << endl;
            cin >> choiceAnswer;
            

            if (choiceAnswer == 'Y' || choiceAnswer == 'y')
            {
                // seting the rest choices to false 
                for (int i = 0; i < 4; i++)
                {
                    questiontype[editQuestionChoiceIndex - 1].questionAnswer[i].isCorrect = false;
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

        case 4:
            loopcondition = false; // to exite the loop and go bake to main
            break;
        default:
        {
            cout << "invalid choice, please enter again !";
        }
        }
    }
}

void displayQuestion(question questiontype[]) {

    for (int i = 0; i < 10; i++)
    {
        // Check if questionText is not empty
        if (!chemistryQuestionList[i].questionText.empty()) {

            cout << i + 1 << "_ " << chemistryQuestionList[i].questionText << " ?" << endl;

            for (int j = 0; j < 4; j++)
            {
                // Check if choiceText is not empty
                if (!chemistryQuestionList[i].questionAnswer[j].choiceText.empty())
                {

                    cout << j + 1 << "_ " << chemistryQuestionList[i].questionAnswer[j].choiceText << " ." << endl;
                }


            }
        }
    }
}

