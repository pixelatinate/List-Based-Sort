// Creates the benchmark files with different numbers of input

#include<iostream>
#include<fstream>

using namespace std;

int main(){

	ofstream file;
	file.open("list10M.txt");
		srand((unsigned)(0));
		int randNums;
		for (int i=0; i<10000000; i++){
			randNums = rand() % 999;
			file << randNums << '\n'; 
		}

	return 0;
}
