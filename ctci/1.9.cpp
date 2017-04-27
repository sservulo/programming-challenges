#include<iostream>
using namespace std;

bool isRotation(string s1, string s2){
	s1 += s1;

	size_t isSubstring = s1.find(s2);

	if(isSubstring != string::npos){return true;}

	return false;
}

int main(){
	string s1 = "waterbottle";
	string s2 = "erbottlewat";
	cout << isRotation(s1, s2) << endl;
	return 0;
}
