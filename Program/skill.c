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
	p->skillPoint++;

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
	int damage = p->attack + 20 - m->defence;
	if (damage <= 0) damage = 0;

	m->hp -= damage;
	p->skillPoint++;

	printf("[Player ����] %d ����\n", damage);
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
	if (p->speed >= m->speed) m->stun += 2;
	if (m->speed > p->speed) m->stun += 1;
	printf("[Player ����] %s ����", m->name);
}

static void playerConcentration(Player* p, Monster* m) {

}

void applySkills(SkillMask selected ,Player* p, Monster* m) {
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
	if (selected & SKILL_CONCENTRATION) playerConcentration(p, m);
}

void enemyTurn(Player* p, Monster* m) {
	enemyAttack(p, m);
}

int checkPlayerStun(Player* p) {
	if (p->stun >= 1) {
		printf("[Player�� ���� ���� ���� �Դϴ�.]\n");
		return p->stun;
	}
}

int checkEnemyStun(Monster* m) {
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
		case 1:		return SKILL_ATTACK;
		case 2:		return SKILL_HEAL;
		default:	break;
		}
		break;

	case 2:
		printf("[���� ��ų]\n");
		switch (p->equipment)
		{
		case 1:		// ��
			printf("1. ���(��ų ����Ʈ : 1)	2. ����(��ų ����Ʈ : 2)\n3. ���� ����(��ų ����Ʈ : 1)	4. �г�(��ų ����Ʈ : 3)\n");
			printf("���� : ");
			scanf_s("%d", &skillChoice);
			switch (skillChoice)
			{
			case 1:		
				if (p->skillPoint >= 1) {
					p->skillPoint--;
					return SKILL_SLASH;				// ���
				}
				else {
					printf("��ų ����Ʈ�� �����մϴ�.\n");
					showSkillsList(p);
					break;
				}
			case 2:		
				if (p->skillPoint >= 2) {
					p->skillPoint -= 2;
					return SKILL_CHARGE;			// ����
				}
				else {
					printf("��ų ����Ʈ�� �����մϴ�.\n");
					showSkillsList(p);
					break;
				}
			case 3:		
				if (p->skillPoint >= 1) {
					p->skillPoint--;
					return SKILL_SHIELD_BLOCK;		// ���� ����
				}
				else {
					printf("��ų ����Ʈ�� �����մϴ�.\n");
					showSkillsList(p);
					break;
				}
			case 4:		
				if (p->skillPoint >= 3) {
					p->skillPoint -= 3;
					return SKILL_BERSERK;			// �г�
				}
				else {
					printf("��ų ����Ʈ�� �����մϴ�.\n");
					showSkillsList(p);
					break;
				}
			default: 	break;
			}
			break;

		case 2:		// Ȱ
			printf("1. ���(��ų ����Ʈ : 1)	2. ���� ���(��ų ����Ʈ : 2)\n3. ��ȭ��(��ų ����Ʈ : 3)	4. ȸ��(��ų ����Ʈ : 1)\n");
			printf("���� : ");
			scanf_s("%d", &skillChoice);
			switch (skillChoice)
			{
			case 1:		
				if (p->skillPoint >= 1) {
					p->skillPoint--;
					return SKILL_ARROW_SHOT;		// ���
				}
				else {
					printf("��ų ����Ʈ�� �����մϴ�.\n");
					showSkillsList(p);
					break;
				}
			case 2:		
				if (p->skillPoint >= 2) {
					p->skillPoint -= 2;
					return SKILL_MULTI_SHOT;		// ���� ���
				}
				else {
					printf("��ų ����Ʈ�� �����մϴ�.\n");
					showSkillsList(p);
					break;
				}
			case 3:		
				if (p->skillPoint >= 3) {
					p->skillPoint -= 3;
					return SKILL_POISON_ARROW;		// ��ȭ��
				}
				else {
					printf("��ų ����Ʈ�� �����մϴ�.\n");
					showSkillsList(p);
					break;
				}
			case 4:		
				if (p->skillPoint >= 1) {
					p->skillPoint--;
					return SKILL_EVASION;			// ȸ��
				}
				else {
					printf("��ų ����Ʈ�� �����մϴ�.\n");
					showSkillsList(p);
					break;
				}
			default: 	break;
			}
			break;

		case 3:		// ������
			printf("1. ȭ����(��ų ����Ʈ : 1)	 	2. ������(��ų ����Ʈ : 2)\n3. ����(��ų ����Ʈ : 3)		4. ����(��ų ����Ʈ : 0)\n");
			printf("���� : ");
			scanf_s("%d", &skillChoice);
			switch (skillChoice)
			{
			case 1:		
				if (p->skillPoint >= 1) {
					p->skillPoint--;
					return SKILL_FIREBALL;				// ȭ����
				}
			case 2:		
				if (p->skillPoint >= 2) {
					p->skillPoint -= 2;
					return SKILL_ICE_WALL;				// ������
				}
				else {
					printf("��ų ����Ʈ�� �����մϴ�.\n");
					showSkillsList(p);
					break;
				}
			case 3:		
				if (p->skillPoint >= 3) {
					p->skillPoint -= 3;
					return SKILL_LIGHTNING;				// ����
				}
				else {
					printf("��ų ����Ʈ�� �����մϴ�.\n");
					showSkillsList(p);
					break;
				}
			case 4:		return SKILL_CONCENTRATION;		// ����
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