#include <iostream>
#include <cmath>

using namespace std;

static double get_value () {
	double value;
	cin >> value;
	return value;
}

static void print_msg(string msg, short mod = 0, double res = 0) {
	switch (mod)
	{
	case 0:
		cout << msg << endl;
		break;
	case 1:
		cout << msg;
		break;
	case 2:
		cout << msg << res;
		break;
	default:
		break;
	}
}

int main()
{
	int opperation;
	double number1, number2, result;
	bool exit_status = false;

	const string initial_msg = "Operations in this calculator:";
	const string legend = "0 - exit\n1 - addition\n2 - subtraction\n3 - multiplication\n4 - division\n5 - modul\n";
	const string request_for_opperation = "Select an operation: ";
	const string request_for_number1 = "Type first number: ";
	const string request_for_number2 = "Type second number: ";
	const string exit_msg = "Exit";
	const string error_msg = "Error";
	const string illigal_msg = "Illegal operation";
	const string result_msg = "Result: ";

	print_msg(initial_msg);
	print_msg(legend);

	print_msg(request_for_opperation, 1);
	opperation = static_cast<int>(get_value());

	if (opperation != 0) {
		print_msg(request_for_number1, 1);
		number1 = get_value();
		print_msg(request_for_number2, 1);
		number2 = get_value();
	}

	switch (opperation)
	{
	case 0:
		exit_status = true;
		print_msg(exit_msg);
		break;
	case 1:
		result = number1 + number2;
		break;
	case 2:
		result = number1 - number2;
		break;
	case 3:
		result = number1 * number2;
		break;
	case 4:
		if (number1 == 0 || number2 == 0) {
			exit_status = true;
			print_msg(illigal_msg);
		} else {
			result = number1 / number2;
		}		
		break;
	case 5:
		if (number1 == 0 || number2 == 0) {
			exit_status = true;
			print_msg(illigal_msg);
		} else {
			result = fmod(number1, number2);
		}
		
		break;
	default:
		exit_status = true;
		print_msg(error_msg);
		break;
	}

	if (!exit_status) {
		print_msg(result_msg, 2, result);
	}

	return 0;
}