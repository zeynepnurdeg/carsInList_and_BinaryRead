#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RANGE_OF_OUTPUTTED_CARS 15
#define SIZE_GUESS 20

typedef struct {
	char make[SIZE_GUESS];
	char model[SIZE_GUESS];
	int year;
	double price;
	char color[SIZE_GUESS];
}cars_t;

int readCars(FILE* inp, cars_t* cars) {
	int count = fread(cars, sizeof(cars_t), SIZE_GUESS, inp);
	return (count);
}

void printRandomCars(cars_t* arr, int size, int numOfCars, int index) {
	int carIndex;
	if (index != numOfCars)
	{
		carIndex = rand() % size;
		printf("%s %s %d %.2f %s\n", arr[carIndex].make, arr[carIndex].model, arr[carIndex].year, arr[carIndex].price, arr[carIndex].color);
		printRandomCars(arr, size, numOfCars, index + 1);
	}
}

int main(void)
{
	FILE* inp;
	inp = fopen("cars.bin", "rb");
	if (inp == NULL)
		printf("Error");
	else
	{
		cars_t arr[30];
		int size = readCars(inp, arr);
		fclose(inp);

		int numOfCars;
		srand(time(NULL));
		numOfCars = rand() % RANGE_OF_OUTPUTTED_CARS + 1;

		printf("%d car info: \n", numOfCars);
		printRandomCars(arr, size, numOfCars, 0);
	}
	return 0;
}