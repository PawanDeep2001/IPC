/*
	==================================================
	Workshop #4 (Part-1):
	==================================================
	Name   :Pawan Deep
	ID     :111144218
	Email  :pdeep1@myseneca.ca
	Section:IPC144 NGG
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define maximum 10
int main(void)
{
	int wish, i, priority[maximum];
	const int max = 400000, min = 500, min_value = 100;
	double value[maximum], total, income;
	char answer[maximum], n, y;
	total = 0;
	income = 0;
	i = 0;
	wish = 0;
	y = 'y';
	n = 'n';
	
	printf("+--------------------------+\n");
	printf("+   Wish List Forecaster   |\n");
	printf("+--------------------------+\n");
	do
	{
		printf("\nEnter your monthly NET income: $");
		scanf("%lf", &income);
		if (income < min)
		{
			printf("ERROR: You must have a consistent monthly income of at least $500.00\n");
		}
		if (income > max)
		{
			printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00\n");
		}

	} while (income<min || income>max);
	do
	{
		printf("\nHow many wish list items do you want to forecast?: ");
		scanf("%d", &wish);
		if (wish > maximum || wish < 1)
		{
			printf("ERROR: List is restricted to between 1 and 10 items.\n");
		}
	} while (wish > maximum || wish < 1);
	for (i = 0; i < wish; i++)
	{
		printf("\nItem-%d Details:\n", i + 1);
		do
		{
			printf("   Item cost: $");
			scanf("%lf", &value[i]);
			if (value[i] < min_value)
			{
				printf("      ERROR: Cost must be at least $100.00\n");
			}
		} while (value[i] < min_value);
		do
		{
			printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
			scanf("%d", &priority[i]);
			if (priority[i] > 3 || priority[i] < 1)
			{
				printf("      ERROR: Value must be between 1 and 3\n");
			}
		} while (priority[i] > 3 || priority[i] < 1);
		do
		{
			printf("   Does this item have financing options? [y/n]: ");
			scanf("%s", &answer[i]);
			if (answer[i] == y)
			{
				break;
			}
			else if (answer[i] == n)
			{
				break;
			}
			else
			{
				printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
			}
		} while (answer[i] != 'y' || answer[i] !='n');
	}
	printf("\nItem Priority Financed        Cost\n");
	printf("---- -------- -------- -----------\n");
	for (i = 0; i < wish; i++)
	{
		printf("%3d  %5d    %5c    %11.2lf\n", i + 1, priority[i], answer[i], value[i]);
		total += value[i];
	}
	printf("---- -------- -------- -----------\n");
	printf("                      $%11.2lf\n\n", total);
	printf("Best of luck in all your future endeavours!\n");
	return 0;
}