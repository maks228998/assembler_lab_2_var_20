#define _CRT_SECURE_NO_WARNINGS
#include<cstdlib>
#include "my_lib.h"

int main() {
	printf("|Summ (Ai) * X + Summ (Bij) * Y|\n");
	printf("Number X\n");
	int number_x = input_int_number();
	printf("Number Y\n");
	int number_y = input_int_number();

	const int arrays_lenght = 3;
	const int arrays_size = 3;

	int proverka = arrays_size;
	int array_a[arrays_lenght];
	int array_b[arrays_lenght][arrays_size];

	printf("If you want to generate an array A enter 0\n");
	printf("If you want to enter an array A enter 1\n");

	const int choice = get_int_number_on_1_or_0();

	if (choice) {
		printf("Input %d elenet of array A\n", arrays_lenght);
		for (int counter = 0; counter < arrays_lenght; counter++) {
			array_a[counter] = input_int_number();
		}
	}
	else {

		srand(time(NULL));

		printf("Enter the minimum element of array:\n");
		const int min = input_int_number();

		printf("Enter the maximum element of array:\n");
		const int max = input_int_number();

		printf("Generated element of array:\n");

		for (int counter = 0; counter < arrays_lenght; counter++) {
			array_a[counter] = int_rand_min_max(min, max);
			printf("%d\n", array_a[counter]);
		}
	}

	printf("If you want to generate an array B enter 0\n");
	printf("If you want to enter an array B enter 1\n");

	const int choice_2 = get_int_number_on_1_or_0();


	if (choice_2) {
		printf("Input %d elemet of array B\n", arrays_lenght * arrays_size);
		for (int counter = 0; counter < arrays_lenght; counter++) {
			for (int counter_2 = 0; counter_2 < arrays_size; counter_2++) {
				array_b[counter][counter_2] = input_int_number();
			}
		}
	}
	else {

		srand(time(NULL));

		printf("Enter the minimum element of array:\n");
		const int min = input_int_number();

		printf("Enter the maximum element of array:\n");
		const int max = input_int_number();

		printf("Generated element of array:\n");
		for (int counter = 0; counter < arrays_lenght; counter++) {
			for (int counter_2 = 0; counter_2 < arrays_size; counter_2++) {
				array_b[counter][counter_2] = int_rand_min_max(min, max);
				printf("%d\n", array_b[counter][counter_2]);
			}
		}
	}

	int array_a_summ = 0;
	int array_b_summ = 0;

	for (int counter = 0; counter < arrays_lenght; counter++) {
		array_a_summ = array_a_summ + array_a[counter];
		for (int counter_2 = 0; counter_2 < arrays_size; counter_2++) {
			array_b_summ = array_b_summ + array_b[counter][counter_2];
		}
	}

	array_a_summ = array_a_summ * number_x;
	array_b_summ = array_b_summ * number_y;
	int arrays_summ = array_a_summ + array_b_summ;
	int arrays_abs_c = abs(arrays_summ);

	printf("Computation in C : %d\n" , arrays_abs_c);

	int assembler = 0;

	_asm {
		mov ecx, arrays_lenght
		mov eax, 0
		lea edx, array_a
		lea ebx, array_b

			point_one:

				add eax, [edx]
				add edx, 4

			loop point_one

		imul eax, number_x
		mov assembler, eax
		xor eax, eax
		mov ecx, arrays_lenght
		imul ecx, arrays_size

			point_two:

				add eax, [ebx]
				add ebx, 4

			loop point_two

		imul eax, number_y
		add  eax, assembler


			 jge point_three

				neg  eax

			point_three:

		mov assembler, eax				
	}

	printf("Computation in Assembler : %d\n", assembler);
}