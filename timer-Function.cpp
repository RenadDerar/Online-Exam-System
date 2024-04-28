#include <iostream>
#include <windows.h> // for Sleep()
#include <stdlib.h> // for the system()

using namespace std;

void timerFunction(int min);



int main() {
	int minutes;

	cout << "enter how many minutes will the exam be?" << endl;
	cin >> minutes;
	timerFunction(minutes);

	return 0;

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
		cout << ">>>> the exam time is " << minutes << " minutes " << " <<<<" <<endl;
		cout <<"time left: " << min << ":" << sec-- << endl;
		
		Sleep(1000);     //for the speed of timer >> will get back to loop every 1000 milliseconds after printing the min and sec

	}
	cout << "time is up !" << endl;


}



