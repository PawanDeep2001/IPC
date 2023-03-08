/*
	==================================================
	Workshop #4 (Part-2):
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
	int wish, i, priority[maximum], flag, years, months, filter, ans;
	const int max = 400000, min = 500, min_value = 100;
	double value[maximum], total, income, sum;
	char answer[maximum], n, y;
	total = 0;
	income = 0;
	i = 0;
	wish = 0;
	y = 'y';
	n = 'n';
	ans = 0;
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
		} while (answer[i] != 'y' || answer[i] != 'n');
	}
	printf("\nItem Priority Financed        Cost\n");
	printf("---- -------- -------- -----------\n");
	for (i = 0; i < wish; i++)
	{
		printf("%3d  %5d    %5c    %11.2lf\n", i + 1, priority[i], answer[i], value[i]);
		total += value[i];
	}
	printf("---- -------- -------- -----------\n");
	printf("                      $%11.2lf\n", total);

	do
	{
		printf("\nHow do you want to forecast your wish list?\n 1. All items (no filter)\n 2. By priority\n 0. Quit/Exit\nSelection: ");
		scanf("%d", &flag);
		if (flag == 0) {
			printf("\nBest of luck in all your future endeavours!\n");
		}
		else if (flag == 1) {
			ans = 0;
			printf("\n====================================================\n");
			printf("Filter:   All items\n");
			printf("Amount:   $%1.2lf\n", total);
			years = (int)total / (int)income / 12;
			months = (int)total / (int)income % 12;
			printf("Forecast: %d years, %d months\n", years, months+1);
			for (i = 0; i < wish; i++)
			{
				if (answer[i] == y)
				{
					ans = 1;
				}
			}
			if (ans==1)
			{
				printf("NOTE: Financing options are available on some items.\n      You can likely reduce the estimated months.\n");
			}
			
			printf("====================================================\n");
		}
		else if (flag == 2) {
			do
			{
				sum = 0;
				ans = 0;
				printf("\nWhat priority do you want to filter by? [1-3]: ");
				scanf("%d", &filter);
				if (filter < 1 || filter>3)
				{
					printf("ERROR: Value must be between 1 and 3");
				}
				for (i = 0; i < wish; i++)
				{
					if (priority[i] == filter)
					{
						sum += value[i];
						if (answer[i] == y)
						{
							ans = 1;
						}
					}
				}

			} while (filter < 1 || filter>3);
			years = (int)sum / (int)income / 12;
			months = (int)sum / (int)income % 12;
			printf("\n====================================================\n");
			printf("Filter:   by priority (%d)\n", filter);
			printf("Amount:   $%1.2lf\n",sum );
			printf("Forecast: %d years, %d months\n", years, months+1);
			
			if (ans == 1)
			{
				printf("NOTE: Financing options are available on some items.\n      You can likely reduce the estimated months.\n");
			}

			printf("====================================================\n");
		}
		else
		{
			printf("\nERROR: Invalid menu selection.\n");
		}
	} while (flag != 0);


	return 0;
}