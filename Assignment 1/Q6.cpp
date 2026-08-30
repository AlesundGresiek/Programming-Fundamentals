#include<iostream>
using namespace std;
int main(){
	int a = 2;
	int b = 4;
	int c = 6;
	if(a == 4 || b > 2){
		cout << "A) a == 4 || b > 2 is True" << endl;
	}
	else{
		cout << "A) a == 4 || b > 2 is False" << endl;
	}
	if(6 <= c && a > 3){ //Aoa sir, aap ne yaha pr file me "a 3" likha va he, koi operator ni he, to mene suppose kr lia he 
		cout << "B) 6 <= c && a > 3 is True" << endl;
	}
	else{
		cout << "B) 6 <= c && a > 3 is False" << endl;
	}
	if(1 != b || c <= b){
		cout << "C) 1 != b || c <= b is True" << endl;
	}
	else{
		cout << "C) 1 != b || c <= b is False" << endl;
	}
	if(a >= -1 || a <= b){
		cout << "D) a >= -1 || a <= b is True" << endl;
	}
	else{
		cout << "D) a >= -1 || a <= b is False" << endl;
	}
	if(!(a>2)){
		cout << "E) !(a>2) is True" << endl;
	}
	else{
		cout << "E) !(a>2) is False" << endl;
	}
	
}
