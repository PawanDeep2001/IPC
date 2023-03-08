/*
	==================================================
	Workshop #5 (Part-2):
	==================================================
	Name   :Pawan Deep
	ID     :111144218
	Email  :pdeep1@myseneca.ca
	Section:IPC144 NGG
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define maximum 70
#define max_lives 10
#define max_path 70
#define min_path 10
#define multiple 5
struct PlayerInfo
{
	int lives;
	char character_symbol;
	int counter;
	int history[maximum];
};
struct GameInfo
{
	int maxMoves;
	int pathLenth;
	int bombs[maximum];
	int treasure[maximum];
};
int main(void)
{
	struct PlayerInfo player;
	struct GameInfo game;
	int position1, position2, i, moves, remaining_moves, remaining_lives, treasure;
	position1 = 1;
	position2 = 5;
	moves = 0;
	remaining_moves = 0;
	remaining_lives = 0;
	treasure = 0;
	printf("================================\n");
	printf("         Treasure Hunt!         \n");
	printf("================================\n\n");
	printf("PLAYER Configuration\n");
	printf("--------------------\n");
	printf("Enter a single character to represent the player: ");
	scanf(" %c", &player.character_symbol);
	do
	{
		printf("Set the number of lives: ");
		scanf("%d", &player.lives);
		remaining_lives = player.lives;
		if (player.lives > max_lives || player.lives < 1)
		{
			printf("     Must be between 1 and 10!\n");
		}
	} while (player.lives > max_lives || player.lives < 1);
	printf("Player configuration set-up is complete\n\n");
	printf("GAME Configuration\n");
	printf("------------------\n");
	do
	{
		printf("Set the path length (a multiple of 5 between 10-70): ");
		scanf("%d", &game.pathLenth);
		if (game.pathLenth > max_path || game.pathLenth < min_path || game.pathLenth % multiple != 0)
		{
			printf("     Must be a multiple of 5 and between 10-70!!!\n");
		}
	} while (game.pathLenth > max_path || game.pathLenth < min_path || game.pathLenth % multiple != 0);
	do
	{
		printf("Set the limit for number of moves allowed: ");
		scanf("%d", &game.maxMoves);
		remaining_moves = game.maxMoves;
		if (game.maxMoves > game.pathLenth * 75 / 100 || game.maxMoves < player.lives)
		{
			printf("    Value must be between %d and %d\n", player.lives, game.pathLenth * 75 / 100);
		}
	} while (game.maxMoves > game.pathLenth * 75 / 100 || game.maxMoves < player.lives);
	printf("\nBOMB Placement\n");
	printf("--------------\n");
	printf("Enter the bomb positions in sets of 5 where a value\nof 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.pathLenth);
	for (i = 0; i < game.pathLenth; i += multiple)
	{
		printf("   Positions [%2d-%2d]: ", position1, position2);
		scanf("\n%1d %1d %1d %1d %1d", &game.bombs[i], &game.bombs[i + 1], &game.bombs[i + 2], &game.bombs[i + 3], &game.bombs[i + 4]);
		position1 += 5;
		position2 += 5;
	}
	printf("BOMB placement set\n\n");
	printf("TREASURE Placement\n");
	printf("------------------\n");
	printf("Enter the treasure placements in sets of 5 where a value\nof 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.pathLenth);
	position1 = 1;
	position2 = 5;
	for (i = 0; i < game.pathLenth; i += multiple)
	{
		printf("   Positions [%2d-%2d]: ", position1, position2);
		scanf("\n%1d %1d %1d %1d %1d", &game.treasure[i], &game.treasure[i + 1], &game.treasure[i + 2], &game.treasure[i + 3], &game.treasure[i + 4]);
		position1 += 5;
		position2 += 5;
	}
	printf("TREASURE placement set\n\n");
	printf("GAME configuration set-up is complete...\n\n");
	printf("------------------------------------\n");
	printf("TREASURE HUNT Configuration Settings\n");
	printf("------------------------------------\n");
	printf("Player:\n");
	printf("   Symbol     : %c\n", player.character_symbol);
	printf("   Lives      : %d\n", player.lives);
	printf("   Treasure   : [ready for gameplay]\n");
	printf("   History    : [ready for gameplay]\n\n");
	printf("Game:\n");
	printf("   Path Length: %d\n", game.pathLenth);
	printf("   Bombs      : ");
	for (i = 0; i < game.pathLenth; i++)
	{
		printf("%d", game.bombs[i]);
	}
	printf("\n   Treasure   : ");
	for (i = 0; i < game.pathLenth; i++)
	{
		printf("%d", game.treasure[i]);
		player.history[i] = 0;
	}
	printf("\n\n====================================\n");
	printf("~ Get ready to play TREASURE HUNT! ~\n");
	printf("====================================\n");
	if (moves != 0)
		{
			printf("  ");
		}
		for (i = 0; i < game.pathLenth; i++)
		{
			if (moves == 0)
			{
				break;
			}
			else if (i + 1 == moves)
			{
				printf("%c", player.character_symbol);
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n  ");
		for (i = 0; i < game.pathLenth; i++)
		{
			if (game.bombs[i] == 1 && player.history[i] == 1 && game.treasure[i] == 0)
			{
				printf("!");

			}
			else if (game.treasure[i] ==1 && player.history[i] == 1 && game.bombs[i] == 0)
			{
				printf("$");

			}
			else if (game.bombs[i] == 1 && player.history[i] == 1 && game.treasure[i] == 1)
			{
				printf("&");

			}
			else if (game.bombs[i] == 0 && player.history[i] == 1 && game.treasure[i] == 0)
			{
				printf(".");

			}
			else 
			{
				printf("-");
			}

		}
		printf("\n  ");
		for (i = 0; i < game.pathLenth; i++)
		{
			if (i == 9)
			{
				printf("1");
			}
			else if (i == 19)
			{
				printf("2");
			}
			else if (i == 29)
			{
				printf("3");
			}
			else if (i == 39)
			{
				printf("4");
			}
			else if (i == 49)
			{
				printf("5");
			}
			else if (i == 59)
			{
				printf("6");
			}
			else if (i == 69)
			{
				printf("7");
			}
			else
			{
				printf("|");
			}

		}
		printf("\n  ");
		for (i = 0; i < game.pathLenth; i++)
		{
			if (i % 10 == 9)
			{
				printf("0");
			}
			else
			{
				printf("%1.0d", (i + 1) % 10);
			}
		}
		printf("\n+---------------------------------------------------+\n");
		printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", remaining_lives, treasure, remaining_moves);
		printf("+---------------------------------------------------+\n");
	do
	{
		
		do
		{
			printf("Next Move [1-%d]: ", game.pathLenth);
			scanf("%d", &moves);
				if (moves > 20 || moves < 1)
				{
					printf("  Out of Range!!!\n");
				}

		} while (moves > 20 || moves < 1);
		for (i = 0; i < game.pathLenth; i++)
		{

			if (player.history[i] == 1 && i + 1 == moves)
			{
				printf("\n===============> Dope! You've been here before!\n\n");
				break;
			}
			else if (game.treasure[i] == 1 && i + 1 == moves && game.bombs[i] == 0)
			{
				player.history[i] += 1;
				player.counter += 1;
				treasure += 1;
				remaining_moves -= 1;
				printf("\n===============> [$] $$$ Found Treasure! $$$ [$]\n\n");
			}
			else if (game.bombs[i] == 1 && i + 1 == moves && game.treasure[i] == 1)
			{
				remaining_lives -= 1;
				remaining_moves -= 1;
				player.counter += 1;
				treasure += 1;
				player.history[i] += 1;
				printf("\n===============> [&] !!! BOOOOOM !!! [&]\n");
				printf("===============> [&] $$$ Life Insurance Payout!!! [&]\n\n");
				if (remaining_lives==0)
				{
					printf("No more LIVES remaining!");
				}
			}
			else if (game.bombs[i] == 1 && i + 1 == moves && game.treasure[i] == 0)
			{
				remaining_lives -= 1;
				remaining_moves -= 1;
				player.history[i] += 1;
				printf("\n===============> [!] !!! BOOOOOM !!! [!]\n\n");
				if (remaining_lives==0)
				{
					printf("No more LIVES remaining!\n\n");
				}
			}
			else if (game.bombs[i] == 0 && i + 1 == moves && game.treasure[i] == 0)
			{
				remaining_moves -= 1;
				player.history[i] += 1;
				printf("\n===============> [.] ...Nothing found here... [.]\n\n");
			}
		}
		if (moves != 0)
		{
			printf("  ");
		}
		for (i = 0; i < game.pathLenth; i++)
		{
			if (moves == 0)
			{
				break;
			}
			else if (i + 1 == moves)
			{
				printf("%c", player.character_symbol);
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n  ");
		for (i = 0; i < game.pathLenth; i++)
		{
			if (game.bombs[i] == 1 && player.history[i] == 1 && game.treasure[i] == 0)
			{
				printf("!");

			}
			else if (game.treasure[i] ==1 && player.history[i] == 1 && game.bombs[i] == 0)
			{
				printf("$");

			}
			else if (game.bombs[i] == 1 && player.history[i] == 1 && game.treasure[i] == 1)
			{
				printf("&");

			}
			else if (game.bombs[i] == 0 && player.history[i] == 1 && game.treasure[i] == 0)
			{
				printf(".");

			}
			else 
			{
				printf("-");
			}

		}
		printf("\n  ");
		for (i = 0; i < game.pathLenth; i++)
		{
			if (i == 9)
			{
				printf("1");
			}
			else if (i == 19)
			{
				printf("2");
			}
			else if (i == 29)
			{
				printf("3");
			}
			else if (i == 39)
			{
				printf("4");
			}
			else if (i == 49)
			{
				printf("5");
			}
			else if (i == 59)
			{
				printf("6");
			}
			else if (i == 69)
			{
				printf("7");
			}
			else
			{
				printf("|");
			}

		}
		printf("\n  ");
		for (i = 0; i < game.pathLenth; i++)
		{
			if (i % 10 == 9)
			{
				printf("0");
			}
			else
			{
				printf("%1.0d", (i + 1) % 10);
			}
		}
		printf("\n+---------------------------------------------------+\n");
		printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", remaining_lives, treasure, remaining_moves);
		printf("+---------------------------------------------------+\n");
	} while (remaining_lives != 0 && remaining_moves != 0);
	printf("\n##################");
	printf("\n#   Game over!   #");
	printf("\n##################\n");
	printf("\nYou should play again and try to beat your score!\n");
	return 0;
}