#define _CRT_SECURE_NO_WARNINGS
#include "my_lib.h"
//version 0.3

int int_rand_min_max(const int min, const int max)
{
	const double rand_0_1 = rand() / (RAND_MAX + 1.0);
	int n = max - min + 1;
	const int res = min + (int)(rand_0_1 * n);
	return res;
}

int input_int_number() {
	int number = 0;
	printf("Input number: \n");

	while (scanf("%d", &number) != 1)
	{
		while (getchar() != '\n');

		printf("Input error: not a number entered\n");
	}
	return number;
}

	int get_int_number_on_positive() {
	int number = 0;
	int is_negative = 0;

	do {
		number = input_int_number();

		is_negative = (number < 0.0);
		if (is_negative) {
			printf("Input error: not a correct number entered\n");
		}
		else {}

	} while (is_negative);
	return number;

}

int get_int_number_on_1_or_0() {
	int number = 0;
	int n_is_1_or_0 = 0;

	do {
		n_is_1_or_0 = 0;
		number = get_int_number_on_positive();

		if (number == 1) {
		}
		else {
			if (number == 0) {
			}
			else {
				printf("Input error: this is not correct number\n");
				n_is_1_or_0 = 1;
			}
		}

	} while (n_is_1_or_0);
	return number;
}

int get_int_number_than_greater_1() {
	int number = 0;
	int n_is_one_or_less = 0;

	do {
		number = input_int_number();

		n_is_one_or_less = (number < 1);
		if (n_is_one_or_less) {
			printf("Input error: not a correct number entered\n");
		}
		else {}

	} while (n_is_one_or_less);
	return number;
}

double input_double_number() {
	double number = 0;
	
	printf("Input number: \n");

	while (scanf("%lf", &number) != 1)
	{
		while (getchar() != '\n');

		printf("Input error: not a number entered\n");
	}
	return number;
}

double double_rand_min_max(const double min, const double max)
{
	const double rand_0_1 = rand() / (RAND_MAX + 1.0);
	const double res = rand_0_1 * (max - min) + min;
	return res;
	}

double get_double_number_than_greater_1() {
	double number = 0;
	int is_one_or_less = 1;

	do {
		number = input_double_number();

		is_one_or_less = (number < 1);
		if (is_one_or_less) {
			printf("Input error: not a correct number entered\n");
		}
		else {}

	} while (is_one_or_less);
	return number;
}

double get_double_number_on_positive() {
	double number = 0;
	int Input_error = 1;

	do {
		number = input_double_number();

		if (number <= 0) {
			printf("Input error: not a correct number entered\n");
		}
		else {
			Input_error = 0;
		}

	} while (Input_error);
	return number;
}

double get_double_number_than_greater_min_and_less_max(const double min, const double max) {
	double number = 0;
	int input_error = 1;

	do {
		number = input_double_number();

		if (number < min) {
			printf("Input error: not a correct number entered\n");
		}
		else {
			if (number > max) {
				printf("Input error: not a correct number entered\n");
			}
			else {
				input_error = 0;
			}
		}

	} while (input_error);
	return number;
}

int get_int_number_than_greater_min_and_less_max(const int min, const int max) {
	int number = 0;
	int input_error = 1;

	do {
		number = input_int_number();

		if (number < min) {
			printf("Input error: not a correct number entered\n");
		}
		else {
			if (number > max) {
				printf("Input error: not a correct number entered\n");
			}
			else {
				input_error = 0;
			}
		}

	} while (input_error);
	return number;
}