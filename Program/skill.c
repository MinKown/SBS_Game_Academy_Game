#pragma once

#include "entities.h"
#include "skills.h"

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

// 기본 스킬
static void playerAttack(Player* p, Monster* m) {
	int damage = p->attack - m->defence;
	if (damage <= 0) damage = 0;

	m->hp -= damage;

	printf("[Player 공격] %d 피해\n", damage);

}

static void enemyAttack(Player* p, Monster* m) {
	int enemy_damage = m->attack - p->defence;
	if (enemy_damage <= 0) enemy_damage = 0;

	p->hp -= enemy_damage;

	printf("[%s 공격] %d 피해\n", m->name, enemy_damage);
}

// 검 스킬
static void playerSlash(Player* p, Monster* m) {

}

static void playerCharge(Player* p, Monster* m) {

}

static void playerShieldBlock(Player* p, Monster* m) {

}

static void playerBerserk(Player* p, Monster* m) {

}

// 활 스킬
static void playerArrowShot(Player* p, Monster* m) {

}

static void playerMultiShot(Player* p, Monster* m) {

}

static void playerPoisonArrow(Player* p, Monster* m) {

}

static void playerEvasion(Player* p, Monster* m) {

}

// 지팡이 스킬
static void playerFireball(Player* p, Monster* m) {

}

static void playerIceWall(Player* p, Monster* m) {

}

static void playerLightning(Player* p, Monster* m) {
	printf("[Player 공격] %s 스턴", m->name);
	m->stun = 1;
}

static void playerTeleport(Player* p, Monster* m) {

}

void applySkills(SkillMask selected ,Player* p, Monster* m) {
	int enemyStun = 0;

	// Enemy의 속도가 Player보다 빠를 경우
	if (m->speed > p->speed) {
		enemyAttack(p, m);

		// 기본 스킬
		if (selected & SKILL_ATTACK) playerAttack(p, m);
		if (selected & SKILL_HEAL) playerAttack(p, m);

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
		if (selected & SKILL_TELEPORT) playerTeleport(p, m);
	}
	// Player의 속도가 Enemy보다 빠를 경우
	else {
		// 기본 스킬
		if (selected & SKILL_ATTACK) playerAttack(p, m);
		if (selected & SKILL_HEAL) playerAttack(p, m);

		// 검 스킬
		if (selected & SKILL_SLASH) playerSlash(p, m);
		if (selected & SKILL_CHARGE) playerCharge(p, m);
		if (selected & SKILL_SHIELD_BLOCK) playerShieldBlock(p, m);
		if (selected & SKILL_BERSERK) playerBerserk(p, m);

		// 활 스킬
		if (selected & SKILL_ARROW_SHOT) playerAttack(p, m);
		if (selected & SKILL_MULTI_SHOT) playerAttack(p, m);
		if (selected & SKILL_POISON_ARROW) playerAttack(p, m);
		if (selected & SKILL_EVASION) playerAttack(p, m);

		// 지팡이 스킬
		if (selected & SKILL_FIREBALL) playerAttack(p, m);
		if (selected & SKILL_ICE_WALL) playerAttack(p, m);
		if (selected & SKILL_LIGHTNING) playerAttack(p, m);
		if (selected & SKILL_TELEPORT) playerAttack(p, m);

		enemyAttack(p, m);
	}
}

int checkStun(Player* p, Monster* m) {
	if (p->stun >= 1) {
		printf("[Player는 현재 스턴 상태 입니다.]\n");
		return p->stun;
	}
	if (m->stun >= 1) {
		printf("[Enemy는 현재 스턴 상태 입니다.]\n");
		return m->stun;
	}
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
		case 1:
			return SKILL_ATTACK;
		case 2:
			return SKILL_HEAL;
		default:
			break;
		}
		break;

	case 2:
		printf("[직업 스킬]\n");
		switch (p->equipment)
		{
		case 1:		// 검
			printf("1. 배기		2. 돌진		3. 방패 막기	4. 분노\n");
			printf("선택 : ");
			scanf_s("%d", &skillChoice);
			switch (skillChoice)
			{
			case 1:		return SKILL_SLASH;				// 배기
			case 2:		return SKILL_CHARGE;			// 돌진
			case 3:		return SKILL_SHIELD_BLOCK;		// 방패 막기
			case 4:		return SKILL_BERSERK;			// 분노
			default: 	break;
			}
			break;

		case 2:		// 활
			printf("1. 쏘기		2. 연속 쏘기	3. 독화살	4. 회피\n");
			printf("선택 : ");
			scanf_s("%d", &skillChoice);
			switch (skillChoice)
			{
			case 1:		return SKILL_ARROW_SHOT;		// 쏘기
			case 2:		return SKILL_MULTI_SHOT;		// 연속 쏘기
			case 3:		return SKILL_POISON_ARROW;		// 독화살
			case 4:		return SKILL_EVASION;			// 회피
			default: 	break;
			}
			break;

		case 3:		// 지팡이
			printf("1. 화염구		2. 얼음벽		3. 번개		4. 순간이동\n");
			printf("선택 : ");
			scanf_s("%d", &skillChoice);
			switch (skillChoice)
			{
			case 1:		return SKILL_FIREBALL;			// 화염구
			case 2:		return SKILL_ICE_WALL;			// 얼음벽
			case 3:		return SKILL_LIGHTNING;			// 번개
			case 4:		return SKILL_TELEPORT;			// 순간이동
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