#pragma once

#include "entities.h"
#include "skills.h"

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

// �⺻ ��ų
static void playerAttack(Player* p, Monster* m) {
	int damage = p->attack - m->defence;
	if (damage <= 0) damage = 0;

	m->hp -= damage;

	printf("[Player ����] %d ����\n", damage);

}

static void enemyAttack(Player* p, Monster* m) {
	int enemy_damage = m->attack - p->defence;
	if (enemy_damage <= 0) enemy_damage = 0;

	p->hp -= enemy_damage;

	printf("[%s ����] %d ����\n", m->name, enemy_damage);
}

// �� ��ų
static void playerSlash(Player* p, Monster* m) {

}

static void playerCharge(Player* p, Monster* m) {

}

static void playerShieldBlock(Player* p, Monster* m) {

}

static void playerBerserk(Player* p, Monster* m) {

}

// Ȱ ��ų
static void playerArrowShot(Player* p, Monster* m) {

}

static void playerMultiShot(Player* p, Monster* m) {

}

static void playerPoisonArrow(Player* p, Monster* m) {

}

static void playerEvasion(Player* p, Monster* m) {

}

// ������ ��ų
static void playerFireball(Player* p, Monster* m) {

}

static void playerIceWall(Player* p, Monster* m) {

}

static void playerLightning(Player* p, Monster* m) {
	printf("[Player ����] %s ����", m->name);
	m->stun = 1;
}

static void playerTeleport(Player* p, Monster* m) {

}

void applySkills(SkillMask selected ,Player* p, Monster* m) {
	int enemyStun = 0;

	// Enemy�� �ӵ��� Player���� ���� ���
	if (m->speed > p->speed) {
		enemyAttack(p, m);

		// �⺻ ��ų
		if (selected & SKILL_ATTACK) playerAttack(p, m);
		if (selected & SKILL_HEAL) playerAttack(p, m);

		// �� ��ų
		if (selected & SKILL_SLASH) playerSlash(p, m);
		if (selected & SKILL_CHARGE) playerCharge(p, m);
		if (selected & SKILL_SHIELD_BLOCK) playerShieldBlock(p, m);
		if (selected & SKILL_BERSERK) playerBerserk(p, m);

		// Ȱ ��ų
		if (selected & SKILL_ARROW_SHOT) playerArrowShot(p, m);
		if (selected & SKILL_MULTI_SHOT) playerMultiShot(p, m);
		if (selected & SKILL_POISON_ARROW) playerPoisonArrow(p, m);
		if (selected & SKILL_EVASION) playerEvasion(p, m);

		// ������ ��ų
		if (selected & SKILL_FIREBALL) playerFireball(p, m);
		if (selected & SKILL_ICE_WALL) playerIceWall(p, m);
		if (selected & SKILL_LIGHTNING) playerLightning(p, m);
		if (selected & SKILL_TELEPORT) playerTeleport(p, m);
	}
	// Player�� �ӵ��� Enemy���� ���� ���
	else {
		// �⺻ ��ų
		if (selected & SKILL_ATTACK) playerAttack(p, m);
		if (selected & SKILL_HEAL) playerAttack(p, m);

		// �� ��ų
		if (selected & SKILL_SLASH) playerSlash(p, m);
		if (selected & SKILL_CHARGE) playerCharge(p, m);
		if (selected & SKILL_SHIELD_BLOCK) playerShieldBlock(p, m);
		if (selected & SKILL_BERSERK) playerBerserk(p, m);

		// Ȱ ��ų
		if (selected & SKILL_ARROW_SHOT) playerAttack(p, m);
		if (selected & SKILL_MULTI_SHOT) playerAttack(p, m);
		if (selected & SKILL_POISON_ARROW) playerAttack(p, m);
		if (selected & SKILL_EVASION) playerAttack(p, m);

		// ������ ��ų
		if (selected & SKILL_FIREBALL) playerAttack(p, m);
		if (selected & SKILL_ICE_WALL) playerAttack(p, m);
		if (selected & SKILL_LIGHTNING) playerAttack(p, m);
		if (selected & SKILL_TELEPORT) playerAttack(p, m);

		enemyAttack(p, m);
	}
}

int checkStun(Player* p, Monster* m) {
	if (p->stun >= 1) {
		printf("[Player�� ���� ���� ���� �Դϴ�.]\n");
		return p->stun;
	}
	if (m->stun >= 1) {
		printf("[Enemy�� ���� ���� ���� �Դϴ�.]\n");
		return m->stun;
	}
}

SkillMask showSkillsList(struct Player* p) {
	int choice, skillChoice;
	printf("1. �⺻ ��ų		2. ���� ��ų\n");
	printf("���� : ");
	scanf_s("%d", &choice);

	switch (choice)
	{
	case 1:
		printf("[�⺻ ��ų]\n");
		printf("1. �Ϲ� ����	2. ȸ��\n");
		printf("���� : ");
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
		printf("[���� ��ų]\n");
		switch (p->equipment)
		{
		case 1:		// ��
			printf("1. ���		2. ����		3. ���� ����	4. �г�\n");
			printf("���� : ");
			scanf_s("%d", &skillChoice);
			switch (skillChoice)
			{
			case 1:		return SKILL_SLASH;				// ���
			case 2:		return SKILL_CHARGE;			// ����
			case 3:		return SKILL_SHIELD_BLOCK;		// ���� ����
			case 4:		return SKILL_BERSERK;			// �г�
			default: 	break;
			}
			break;

		case 2:		// Ȱ
			printf("1. ���		2. ���� ���	3. ��ȭ��	4. ȸ��\n");
			printf("���� : ");
			scanf_s("%d", &skillChoice);
			switch (skillChoice)
			{
			case 1:		return SKILL_ARROW_SHOT;		// ���
			case 2:		return SKILL_MULTI_SHOT;		// ���� ���
			case 3:		return SKILL_POISON_ARROW;		// ��ȭ��
			case 4:		return SKILL_EVASION;			// ȸ��
			default: 	break;
			}
			break;

		case 3:		// ������
			printf("1. ȭ����		2. ������		3. ����		4. �����̵�\n");
			printf("���� : ");
			scanf_s("%d", &skillChoice);
			switch (skillChoice)
			{
			case 1:		return SKILL_FIREBALL;			// ȭ����
			case 2:		return SKILL_ICE_WALL;			// ������
			case 3:		return SKILL_LIGHTNING;			// ����
			case 4:		return SKILL_TELEPORT;			// �����̵�
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