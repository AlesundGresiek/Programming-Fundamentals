#include<iostream>
using namespace std;

void checkInitials(char array[], char toCheck){
	bool check = 0;
	for(int i = 0; i < 11; i++){
		if(array[i] == toCheck){
			check = 1;
		}
	}
	if(check)
	cout << "Player is playing on the team";
	else
	cout << "Player is NOT playing on the team";
}
//This is case sensitive, as making it universal would've been too much work
int main(){
	char team[11];
	char toCheck;
	for(int i = 0; i < 11; i++){
		cout << "Enter Initial of Player " << i + 1 << ": ";
		cin >> team[i];
	}
	cout << "Enter the Initial of the Player you want to check: ";
	cin >> toCheck;
	checkInitials(team, toCheck);
}
