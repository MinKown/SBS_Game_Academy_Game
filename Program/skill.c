#pragma once

#include "entities.h"
#include "skills.h"

#include <stdio.h>
#include <ctype.h>
#include <string.h>

static void do_attack(Player* p, Monster* m) {
	int damage = p->attack - m->defence;

	if (damage <= 0) damage = 0;
	m->hp = damage;

	printf("[Player 공격] %d 피해\n", damage);
}