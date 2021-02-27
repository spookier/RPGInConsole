#ifndef _GAME_H
#define _GAME_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define true 1
#define false 0


typedef int bool;

struct Player_s
{
    int life;
    int potions;
    int damage;
	bool isAlive;
};

struct Enemy_s
{
    int life;
    int damage;
	bool enemyisAlive;
};

void initPlayer(struct Player_s *player)
{
    player->life = 20; 
    player->potions = 3;
    player->damage = 2;
	player->isAlive = true;
}

void initEnemy(struct Enemy_s *enemy)
{
    enemy->life = 10; 
    enemy->damage = 2;
	enemy->enemyisAlive = true;
}

void DamagePlayer(struct Player_s *player, int damage)
{		
		player->life -= damage;

	 if (player->life <= 0 && player->potions >= 1)
        {
            printf("Healing yourself for 5 HP");
            player->potions--;
            player->life += 5;
        }

        else if (player->life == 0 && player->potions <= 0)
        {
            printf("UR DEAD XD");
			player->isAlive = false;
        }
}





void clrscr()
{
    system("@cls||clear");
}

#endif
