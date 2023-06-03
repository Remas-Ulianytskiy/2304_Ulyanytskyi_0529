#include <iostream>

using namespace std;

static double get_value () {
	double value;
	cin >> value;
	return value;
}

static void print_msg(string msg, double num = 0, bool mod = 0) {
	if (mod == 0) {
		cout << msg << endl;		
	} else if (mod == 1) {
		cout << msg << num;
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

	print_msg(request_for_opperation);
	opperation = static_cast<int>(get_value());

	if (opperation != 0) {
		print_msg(request_for_number1);
		number1 = get_value();
		print_msg(request_for_number2);
		number2 = get_value();
	} else if (opperation == 0) {
		exit_status = true;
	}

	switch (opperation)
	{
	case 0:
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
			break;
		}
		result = number1 / number2;
		break;
	case 5:
		//result = number1 % number2;
		break;
	default:
		exit_status = true;
		print_msg(error_msg);
		break;
	}

	if (!exit_status) {
		print_msg(result_msg, result, 1);
	}

	return 0;
}