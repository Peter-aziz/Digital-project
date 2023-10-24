#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <sstream>
#include <cmath>
using namespace std;

//1. [10 Points] Read in (and validate) a Boolean function given as Assume that the variable name is a single Latin letter starting from “a”.Think about the checkers needed to validate the inputand list them in your report.

void sortString(string& str)         //Sort the string of the Boolean function.
{

	sort(str.begin(), str.end());
	
}



//2.[10 Points] Print the truth table of the function as well as the canonical SoP and PoS.

//3.[20 Points] Generate and print all prime implicants(PIs).For each PI show the minterms it covers as well as its binary representation.

//4.[15 Points] Using the PIs generated in part 2, obtainand print all the essential prime implicants EPIs(as Boolean expressions).

//5.[5 Pts] Print the minterms that are not covered by the essential PIs.

//6.[10 Points, Bonus] Solve the PI table and print the minimized Boolean expression of the Boolean function using the 3 - step heuristic discussed in the lecture.

//7.[5 Pts] Draw the K - Map showing the solution(up to 4 variables)
void draw_k_map(int no_of_variables, int truth_able[]) {
	if (no_of_variables == 1) {
		int k_map[1][2];
		// k map with 1 cell
		k_map[0][0] = truth_able[0];
		k_map[0][1] = truth_able[1];
		cout << "-----------------------" << endl << "K-map:" <<endl ;
		cout << k_map[0][0] << endl;
		cout << k_map[0][1] << endl;
		cout << "-----------------------" << endl;
	}
	else if (no_of_variables == 2) {
		int k_map[2][2];
		// add values from truth tabe
		k_map[0][0] = truth_able[0];
		k_map[0][1] = truth_able[1];
		k_map[1][0] = truth_able[2];
		k_map[1][1] = truth_able[3];
		// print K-map
		cout << "-----------------------" << endl << "K-map:" << endl;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				cout << k_map[i][j] << ' ';
			}
			cout << endl;
		}
		cout << "-----------------------" << endl;
		
	}
	else if (no_of_variables == 3) {
		int k_map[2][4];
		// add values from truth tabe
		k_map[0][0] = truth_able[0];
		k_map[0][1] = truth_able[1];
		k_map[0][2] = truth_able[3];
		k_map[0][3] = truth_able[2];
		k_map[1][0] = truth_able[4];
		k_map[1][1] = truth_able[5];
		k_map[1][2] = truth_able[7];
		k_map[1][3] = truth_able[6];
		// print K-map
		cout << "-----------------------" << endl << "K-map:" << endl;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 4; j++) {
				cout << k_map[i][j] << ' ';
			}
			cout << endl;
		}
		cout << "-----------------------" << endl;

	}
	else if (no_of_variables == 4) {
		int k_map[4][4];
		// add values from truth tabe
		k_map[0][0] = truth_able[0];
		k_map[0][1] = truth_able[1];
		k_map[0][2] = truth_able[3];
		k_map[0][3] = truth_able[2];
		k_map[1][0] = truth_able[4];
		k_map[1][1] = truth_able[5];
		k_map[1][2] = truth_able[7];
		k_map[1][3] = truth_able[6];
		k_map[2][0] = truth_able[12];
		k_map[2][1] = truth_able[13];
		k_map[2][2] = truth_able[15];
		k_map[2][3] = truth_able[14];
		k_map[3][0] = truth_able[8];
		k_map[3][1] = truth_able[9];
		k_map[3][2] = truth_able[11];
		k_map[3][3] = truth_able[10];
		// print K-map
		cout << "-----------------------" << endl << "K-map:" << endl;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				cout << k_map[i][j] << ' ';
			}
			cout << endl;
		}
		cout << "-----------------------" << endl;

	}
	else {
		cout << "no K-map avaliable";
		return;
	}

}

//8.[5 Pts] Draw the logic circuit of the minimized function(up to 10 variables); you may use https ://wavedrom.com/tutorial2.html



int main() {
	int no_of_variables;
	cout << "Enter number of variables: ";
	cin >> no_of_variables;

	// validating number of variables
	if ((no_of_variables <0) || (no_of_variables > 10)) {
		cout << "wrong number of variables";
		return 0;
	}

	string boolean_function;
	cout << "Enter boolean function: ";
	cin >> boolean_function;
	//validating boolean function

	int test_array[16] = { 0,1,1,0,1,0,0,0,0,0,1,0,0,1,0,0 };
	draw_k_map(no_of_variables, test_array);

	return 0;

}
