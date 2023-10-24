#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <cctype>

using namespace std;

//1. [10 Points] Read in (and validate) a Boolean function given as Assume that the variable name is a single Latin letter starting from “a”.Think about the checkers needed to validate the inputand list them in your report.

bool isValidVariable(char var) {
    return isalpha(var) && islower(var);
}

bool isValidSoP(const string& expression) {
    // Check that each term is valid
    for (char c : expression) {
        if (!isValidVariable(c) && c != '\'' && c != '+' && c != ' ' && c != '.') {
            return false;
        }
    }
    return true;
}

bool isValidPoS(const string& expression) {
    // Check that each term is valid
    for (char c : expression) {
        if (!isValidVariable(c) && c != '\'' && c != '+' && c != ' ' && c != '(' && c != ')') {
            return false;
        }
    }
    return true;
}

bool validateBooleanFunction(string expression) {

	if (isValidSoP(expression)) {
		cout << "Valid SoP expression: " << expression << endl;
		return 1;
	}
	else if (isValidPoS(expression)) {
		cout << "Valid PoS expression: " << expression << endl;
		return 1;
	}
	else {
		cout << "Invalid expression. Please enter a valid SoP or PoS expression." << endl;
		return 0;
	}
}



//2.[10 Points] Print the truth table of the function as well as the canonical SoP and PoS.

//3.[20 Points] Generate and print all prime implicants(PIs).For each PI show the minterms it covers as well as its binary representation.

//4.[15 Points] Using the PIs generated in part 2, obtainand print all the essential prime implicants EPIs(as Boolean expressions).

//5.[5 Pts] Print the minterms that are not covered by the essential PIs.

//6.[10 Points, Bonus] Solve the PI table and print the minimized Boolean expression of the Boolean function using the 3 - step heuristic discussed in the lecture.

//7.[5 Pts] Draw the K - Map showing the solution(up to 4 variables)
void draw_k_map(int no_of_variables, int *truth_able, int no_of_rows) {
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
// function to split a SOP boolean function into its products
vector<string> split_SOP(string str)
{
	vector<string> v;

	stringstream ss(str);

	while (ss.good()) {
		string substr;
		getline(ss, substr, '+');
		v.push_back(substr);
	}
	return v;

}

void draw_logic_circuit(string minimized_function) {
	vector <string> products = split_SOP(minimized_function);


}


int main() {
	int no_of_variables;
	cout << "Enter number of variables: ";
	cin >> no_of_variables;

	
	// validating number of variables
	if ((no_of_variables <0) || (no_of_variables > 10)) {
		cout << "wrong number of variables";
		return 0;
	}
	
	int no_of_rows = pow(2, no_of_variables);
	int* truth_table = new int[no_of_rows];

	string boolean_function;
	cout << "Enter boolean function: ";
	cin >> boolean_function;
	
	//validating boolean function
	if (validateBooleanFunction(boolean_function) == 0) {
		return 0;
	}
	

	// Draw K-map
	draw_k_map(no_of_variables, truth_table,no_of_rows);

	return 0;

}

// Test Cases
/*
1) number of variables = -1 boolean function = ***
2) number of variables = 12 boolean function = ***
3) number of variables = 1 boolean function = a
4) number of variables = 2 boolean function = ab'
5) number of variables = 3 boolean function = abc + b'c'
6) number of variables = 4 boolean function = (a+d)(b+c')
7) number of variables = 5 boolean function = ab'c'd + bce
8) number of variables = 6 boolean function = (a+c)(d+e)(b+d')
9) number of variables = 7 boolean function = (a+c')(d+e)(b'+d)(f+g)
10) number of variables = 8 boolean function = ab+g
11) number of variables = 9 boolean function = ab+ge+cd'+f'


*/