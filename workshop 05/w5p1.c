/*
	==================================================
	Workshop #5 (Part-1):
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
	int position1, position2, i;
	position1 = 1;
	position2 = 5;
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
		scanf("%d",&player.lives);
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
		if (game.maxMoves > game.pathLenth * 75 / 100 || game.maxMoves < player.lives)
		{
			printf("    Value must be between %d and %d\n", player.lives, game.pathLenth * 75 / 100);
		}
	} while (game.maxMoves > game.pathLenth * 75 / 100 || game.maxMoves < player.lives);
	printf("\nBOMB Placement\n");
	printf("--------------\n");
	printf("Enter the bomb positions in sets of 5 where a value\nof 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.pathLenth);
	for ( i = 0; i < game.pathLenth; i+=multiple)
	{
		printf("   Positions [%2d-%2d]: ", position1, position2);
		scanf("\n%1d %1d %1d %1d %1d", &game.bombs[i], &game.bombs[i + 1], &game.bombs[i + 2], &game.bombs[i + 3],& game.bombs[i + 4]);
		position1 += 5;
		position2 += 5;
	}
	printf("BOMB placement set\n\n");
	printf("TREASURE Placement\n");
	printf("------------------\n");
	printf("Enter the treasure placements in sets of 5 where a value\nof 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n(Example: 1 0 0 1 1) NOTE: there are 35 to set!\n");
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
	for ( i = 0; i < game.pathLenth; i++)
	{
		printf("%d", game.bombs[i]);
	}
	printf("\n   Treasure   : ");
	for (i = 0; i < game.pathLenth; i++)
	{
		printf("%d", game.treasure[i]);
	}
	printf("\n\n====================================\n");
	printf("~ Get ready to play TREASURE HUNT! ~\n");
	printf("====================================\n");
	return 0;
}