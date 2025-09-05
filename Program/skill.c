#pragma once

#include "entities.h"
#include "all.h"

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

// 기본 스킬
static void playerAttack(Player* p, Monster* m) {
	int damage = p->attack - m->defence;
	if (damage <= 0) damage = 0;

	if (p->temporary >= 0) damage += p->temporary;

	m->hp -= damage;
	p->skillPoint++;

	if (p->temporary > 0) p->temporary = 0;

	printf("[Player 공격] %d 피해\n", damage);

}

static void playerHeal(Player* p) {
	switch (p->equipment)
	{
	case 1:
		p->hp += 20;
		if (p->hp >= p->totalHp) p->hp = 150;
		printf("[Player 회복] + 20 HP\n");
		break;
	case 2:
		p->hp += 20;
		if (p->hp >= p->totalHp) p->hp = 100;
		printf("[Player 회복] + 20 HP\n");
		break;
	case 3:
		p->hp += 20;
		if (p->hp >= p->totalHp) p->hp = 100;
		printf("[Player 회복] + 20 HP\n");
		break;
	}
}

static void enemyAttack(Player* p, Monster* m) {
	int enemy_damage = 0;

	if (p->ammor > 0) {
		enemy_damage = m->attack - p->ammor;
		p->ammor -= m->attack;
	}
	if (enemy_damage <= 0) enemy_damage = 0;
	if (p->ammor <= 0) p->ammor = 0;

	enemy_damage = m->attack - p->defence;
	if (enemy_damage <= 0) enemy_damage = 0;

	p->hp -= enemy_damage;

	printf("[%s 공격] %d 피해\n", m->name, enemy_damage);
}

// 검 스킬
static void playerSlash(Player* p, Monster* m) {
	int damage = p->attack + 15 - m->defence;
	if (damage <= 0) damage = 0;

	if (p->temporary >= 0) damage += p->temporary;

	m->hp -= damage;
	p->skillPoint++;

	if (p->temporary > 0) p->temporary = 0;

	printf("[Player 배기 공격] %d 피해\n", damage);
}

static void playerCharge(Player* p, Monster* m) {
	int damage = p->attack + 10 - m->defence;
	if (damage <= 0) damage = 0;

	if (p->temporary >= 0) damage += p->temporary;

	m->hp -= damage;
	p->skillPoint++;

	if (p->speed >= m->speed) m->stun += 2;
	if (m->speed > p->speed) m->stun += 1;

	if (p->temporary > 0) p->temporary = 0;

	printf("[Player 돌진 공격] %d 피해\n", damage);
	printf("[돌진으로 %s 기절]\n", m->name);
}

static void playerShieldBlock(Player* p, Monster* m) {
	p->ammor += 15;

	printf("[Player 방패 막기] 방어막 + %d\n", p->ammor);
}

static void playerBerserk(Player* p, Monster* m) {
	p->temporary += 10;

	printf("[Player 분노] 공격력 + %d\n", p->temporary);
}

// 활 스킬
static void playerArrowShot(Player* p, Monster* m) {
	int damage = p->attack + 15 - m->defence;
	if (damage <= 0) damage = 0;

	m->hp -= damage;
	p->skillPoint++;

	printf("[Player 화살 쏘기] %d 피해\n", damage);
}

static void playerMultiShot(Player* p, Monster* m) {
	int damage = p->attack + 15 - m->defence;
	if (damage <= 0) damage = 0;

	m->hp -= damage;
	m->hp -= damage;
	p->skillPoint++;

	printf("[Player 연속 쏘기] %d, %d 피해\n", damage, damage);
}

static void playerPoisonArrow(Player* p, Monster* m) {
	int debuff = 0;

	m->debuff += 2;

	printf("[Player 독화살] %d 피해]\n", 10);
}

static void playerEvasion(Player* p, Monster* m) {
	p->temporary++;

	printf("[Player 회피]\n");
}

// 지팡이 스킬
static void playerFireball(Player* p, Monster* m) {
	int damage = p->attack + 20 - m->defence;
	if (damage <= 0) damage = 0;

	m->hp -= damage;
	p->skillPoint++;

	printf("[Player 화염구] %d 피해\n", damage);
}

static void playerIceWall(Player* p, Monster* m) {
	p->ammor += 30;

	printf("[Player 얼음벽] 방어막 + %d\n", p->ammor);
}

static void playerLightning(Player* p, Monster* m) {
	if (p->speed >= m->speed) m->stun += 2;
	if (m->speed > p->speed) m->stun += 1;
	printf("[Player 공격] %s 스턴\n", m->name);
}

static void playerConcentration(Player* p, Monster* m) {
	p->skillPoint += 3;

	printf("[Player 집중] 스킬 포인트 + 3]\n");
}

void applySkills(SkillMask selected ,Player* p, Monster* m) {
	// 기본 스킬
	if (selected & SKILL_ATTACK) playerAttack(p, m);
	if (selected & SKILL_HEAL) playerHeal(p);

	// 검 스킬
	if (selected & SKILL_SLASH) playerSlash(p, m);
	if (selected & SKILL_CHARGE) playerCharge(p, m);
	if (selected & SKILL_SHIELD_BLOCK) playerShieldBlock(p, m);
	if (selected & SKILL_BERSERK) playerBerserk(p, m);

	// 활 스킬
	if (selected & SKILL_ARROW_SHOT) playerArrowShot(p, m);
	if (selected & SKILL_MULTI_SHOT) playerMultiShot(p, m);
	if (selected & SKILL_POISON_ARROW) playerPoisonArrow(p, m);
	if (selected & SKILL_EVASION) playerEvasion(p, m);

	// 지팡이 스킬
	if (selected & SKILL_FIREBALL) playerFireball(p, m);
	if (selected & SKILL_ICE_WALL) playerIceWall(p, m);
	if (selected & SKILL_LIGHTNING) playerLightning(p, m);
	if (selected & SKILL_CONCENTRATION) playerConcentration(p, m);
}

void enemyTurn(Player* p, Monster* m) {
	enemyAttack(p, m);
}

int checkPlayerStun(Player* p) {
	if (p->stun >= 1) {
		printf("[Player는 현재 스턴 상태 입니다.]\n");
		return p->stun;
	}
}

int checkEnemyStun(Monster* m) {
	if (m->stun >= 1) {
		printf("[Enemy는 현재 스턴 상태 입니다.]\n");
		return m->stun;
	}
}

void checkPoison(Monster* m) {
	if (m->debuff > 0) {
		printf("[Enemy는 현재 중독 상태 입니다.] 10 피해\n");
		m->hp -= 10;
		m->debuff--;
	}
}

int run() {
	return 3;
}

SkillMask showSkillsList(struct Player* p) {
	int choice, skillChoice;
	printf("1. 기본 스킬		2. 직업 스킬\n");
	printf("선택 : ");
	scanf_s("%d", &choice);

	switch (choice)
	{
	case 1:
		printf("[기본 스킬]\n");
		printf("1. 일반 공격	2. 회복\n");
		printf("선택 : ");
		scanf_s("%d", &skillChoice);
		switch (skillChoice)
		{
		case 1:		return SKILL_ATTACK;
		case 2:		return SKILL_HEAL;
		default:	break;
		}
		break;

	case 2:
		printf("[직업 스킬]\n");
		switch (p->equipment)
		{
		case 1:		// 검
			printf("1. 배기(스킬 포인트 : 1)	2. 돌진(스킬 포인트 : 2)\n3. 방패 막기(스킬 포인트 : 1)	4. 분노(스킬 포인트 : 3)\n");
			printf("5. 돌아가기\n");
			printf("선택 : ");
			scanf_s("%d", &skillChoice);
			switch (skillChoice)
			{
			case 1:		
				if (p->skillPoint >= 1) {
					p->skillPoint--;
					return SKILL_SLASH;				// 배기
				}
				else {
					printf("스킬 포인트가 부족합니다.\n");
					showSkillsList(p);
					break;
				}
			case 2:		
				if (p->skillPoint >= 2) {
					p->skillPoint -= 2;
					return SKILL_CHARGE;			// 돌진
				}
				else {
					printf("스킬 포인트가 부족합니다.\n");
					showSkillsList(p);
					break;
				}
			case 3:		
				if (p->skillPoint >= 1) {
					p->skillPoint--;
					return SKILL_SHIELD_BLOCK;		// 방패 막기
				}
				else {
					printf("스킬 포인트가 부족합니다.\n");
					showSkillsList(p);
					break;
				}
			case 4:		
				if (p->skillPoint >= 3) {
					p->skillPoint -= 3;
					return SKILL_BERSERK;			// 분노
				}
				else {
					printf("스킬 포인트가 부족합니다.\n");
					showSkillsList(p);
					break;
				}
			case 5:
				showSkillsList(p);
				break;
			default: 	break;
			}
			break;

		case 2:		// 활
			printf("1. 쏘기(스킬 포인트 : 1)	2. 연속 쏘기(스킬 포인트 : 2)\n3. 독화살(스킬 포인트 : 3)	4. 회피(스킬 포인트 : 1)\n");
			printf("5. 돌아가기\n");
			printf("선택 : ");
			scanf_s("%d", &skillChoice);
			switch (skillChoice)
			{
			case 1:		
				if (p->skillPoint >= 1) {
					p->skillPoint--;
					return SKILL_ARROW_SHOT;		// 쏘기
				}
				else {
					printf("스킬 포인트가 부족합니다.\n");
					showSkillsList(p);
					break;
				}
			case 2:		
				if (p->skillPoint >= 2) {
					p->skillPoint -= 2;
					return SKILL_MULTI_SHOT;		// 연속 쏘기
				}
				else {
					printf("스킬 포인트가 부족합니다.\n");
					showSkillsList(p);
					break;
				}
			case 3:		
				if (p->skillPoint >= 3) {
					p->skillPoint -= 3;
					return SKILL_POISON_ARROW;		// 독화살
				}
				else {
					printf("스킬 포인트가 부족합니다.\n");
					showSkillsList(p);
					break;
				}
			case 4:		
				if (p->skillPoint >= 1) {
					p->skillPoint--;
					return SKILL_EVASION;			// 회피
				}
				else {
					printf("스킬 포인트가 부족합니다.\n");
					showSkillsList(p);
					break;
				}
			case 5:
				showSkillsList(p);
				break;
			default: 	break;
			}
			break;

		case 3:		// 지팡이
			printf("1. 화염구(스킬 포인트 : 1)	 	2. 얼음벽(스킬 포인트 : 2)\n3. 번개(스킬 포인트 : 3)		4. 집중(스킬 포인트 : 0)\n");
			printf("5. 돌아가기\n");
			printf("선택 : ");
			scanf_s("%d", &skillChoice);
			switch (skillChoice)
			{
			case 1:		
				if (p->skillPoint >= 1) {
					p->skillPoint--;
					return SKILL_FIREBALL;				// 화염구
				}
			case 2:		
				if (p->skillPoint >= 2) {
					p->skillPoint -= 2;
					return SKILL_ICE_WALL;				// 얼음벽
				}
				else {
					printf("스킬 포인트가 부족합니다.\n");
					showSkillsList(p);
					break;
				}
			case 3:		
				if (p->skillPoint >= 3) {
					p->skillPoint -= 3;
					return SKILL_LIGHTNING;				// 번개
				}
				else {
					printf("스킬 포인트가 부족합니다.\n");
					showSkillsList(p);
					break;
				}
			case 4:		return SKILL_CONCENTRATION;		// 집중
			case 5:
				showSkillsList(p);
				break;
			default: 	break;
			}
			break;

		default:
			break;
		}
	default:
		break;
	}
}