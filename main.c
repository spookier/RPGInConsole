#include "game.h"

int main(void)
{
	srand(time(NULL));
	
	int randDmg;

	struct Player_s player;
	initPlayer(&player);
	
	struct Enemy_s enemy;
	initEnemy(&enemy);

	bool game = true;

	int levels = 1;

	printf("######## STARTING GAME ########\n");

	while (player.isAlive)
	{

		printf("You have spawned in a village. An old lady comes attacking you!\n");
		
		while (levels == 1)
		{
			randDmg = rand() % 10 + 1;
			sleep(2);

			printf("You attack her for %d\n", randDmg);	
			enemy.life -= randDmg;

			if (enemy.life <= 0)
			{
				printf("The old lady died!\n");
				sleep(2);
				levels = 2;
			}

			if (levels == 2)
			{
				enemy.life = 10;

				while(levels == 2)
				{
				printf("While you were running away from the village... You encounter a MONSTER! \n");
				
				randDmg = rand() % 3 + 1;
				
				sleep(3);
				
				printf("This monster attacks you for %d", randDmg);
					
				}
			}
		}


		if(!player.isAlive)
		{
			printf("GAME OVER");
		}
	}

}
