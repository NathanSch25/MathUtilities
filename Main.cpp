/*----------------------| 
Nathan R.Schober        |
10/17/2023 - 11/03/2023 |
Grade and Regresion     |
-----------------------*/

#include <iostream>
#include <string>
using namespace std;


void GradeCalculator() {
	int HomeWork = 0;
	int Tests = 0;
	float HomeworkGrade = 0.0;
	float Grade = 0.0;
	float totalPoints = 0.0;
	float pointsEarned = 0.0;
	float x = 0.0;
	float percent = 0.0;
	

	cout << "How many homeworks have passed" << endl;
	cin >> HomeWork;
	cout << "How many Tests have passed" << endl;
	cin >> Tests;

	//determins the total posible grade and aquired grade for all assignments
	for (int i = 1; i <= HomeWork; ++i) {
		cout << "What was the total posible points on assinment " << i << "?" << endl;
		cin >> x;
		totalPoints += x;

		cout << "How many points were earned on assinment " << i << "?" << endl;
		cin >> x;
		pointsEarned += x;
	}
	//determins how many points make 1% of the homework grade
	percent = totalPoints / 100;
	//converts points earned into a 1 out of 100
	HomeworkGrade = pointsEarned / percent;
	
	//calculates the homework grade and test grades is a test has been taken
	if (Tests != 0) {
		/*all tests are worth 20% and homework makes up the rest of my grade
		this function determins how much of my grade is from a test and
		converts homeworkGrade from 80% of 100% to 80% of the excess percent */
		HomeworkGrade = HomeworkGrade * (1 - (.20 * Tests));

		totalPoints = 0;
		pointsEarned = 0;

		//all test are out of 100 so this adds up all the test grades
		for (int i = 1; i <= Tests; ++i) {
			cout << "What was your grade on test " << i << "?" << endl;
			cin >> x;
			totalPoints += x;

		}
		//converts total points into a 1 out of 100 scale
		percent = (totalPoints / Tests) / 100;
		//converts percent from 80% of 100% to 80% of .2 times the number of tests
		Grade = (20 * Tests) * percent;

	}
	
	cout << "Your current grade for the year is " << HomeworkGrade + Grade << "%." << endl;

	

}
void RegresionCalculator() {
	float x = 0;
	float xSum = 0;
	float y = 0;
	float ySum = 0;
	float xSqr = 0;
	float xy = 0;
	float N = 0;
	float M = 0;
	float B = 0;

	//determing how many times to iterate
	cout << "How many points are there?" << endl;
	cin >> N;

	//gets the primary values needed for calculations
	for (int i = 0; i < N; ++i) {
		//gets the x,y cordants of all points
		cout << "What is the x value of point " << i + 1 << endl;
		cin >> x;
		cout << "What is the y value of point " << i + 1 << endl;
		cin >> y;

		//gets the sum of Xs and Ys
		xSum += x;
		ySum += y;

		//gets the value of all x points as x^2
		xSqr += (x * x);
		//adds all x * y
		xy += (x * y);
	}

	M = ((N * xy) - (xSum * ySum)) / ((N * xSqr) - (xSum * xSum));
	B = ((1/N)*ySum)-((M*xSum)/N);

	cout << "m == " << M << endl << "b == " << B << endl;
	
	

}
int main() {
	int user = 0;

	while (user != -1){
		cout << "What are you useing:" << endl;
		cout << "1:  Grade calculator" << endl;
		cout << "2:  Regresion calculator" << endl;
		cout << "-1:  Quit" << endl;
		cin >> user;

		switch (user) {
		case 1:
			GradeCalculator();
			break;
		case 2:
			RegresionCalculator();
			break;
		case -1:
			cout << "Have a good day :)";
			break;
		default:
			cout << "Fuck" << endl;
			break;
		}
	}
	return 0;
}
