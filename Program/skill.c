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

void makeName(Player* p) {
	printf("[거친 비바람을 피해 들어온 낡은 여관, 타닥거리는 벽난로만이 온기를 더한다.]\n");
	printf("[카운터에 기댄 중년의 여관주인이 지친 눈으로 당신을 바라본다.]\n");
	printf("여관주인 : 또 한 명의 방랑자로군... 하지만 그 눈은 아직 희망을 잃지 않았어. 이 험한 땅에서 불릴 이름이라도 있나?\n");
	printf("이름 : ");

	if (fgets(p->name, 49, stdin) != NULL) {
		p->name[strcspn(p->name, "\n")] = '\0';
	}

	printf("여관주인 : %s 이라... 좋은 이름이야. 부디 절망이 아닌 승리와 함께 기억될 이름이 되길 바라지.\n", p->name);
	printf("여관주인 : 자, 여정에는 준비가 필요한 법. 이리 가까이 오게.\n");

	system("pause");
	system("cls");
}

void choiceJob(Player* p) {
	printf("[여관주인이 창고에서 먼지 쌓인 궤짝을 끌고 와 거친 나무 탁자 위에 올려놓는다.]\n");
	printf("여관주인 : 말만으로는 괴물을 잡을 순 없지. 모든 위대한 여정은 첫걸음, 그리고 첫 무기와 함께 시작되는 법이야.\n");
	printf("여관주인 : 자네의 심장이 이끄는 것을 골라보게.\n");
	printf("[1. 검과 방패	2. 낡은 장궁	3. 룬이 새겨진 지팡이]\n");
	printf("선택 : ");

	int playerChoice;
	scanf_s("%d", &playerChoice);

	switch (playerChoice)
	{
	case 1:
		p->equipment = 1; // 검
		printf("여관주인 : 검과 방패... 가장 정직하고 용감한 길이지.\n폭풍의 한가운데서도 두 발로 굳건히 서려는 자네의 의지가 보이는군.\n");
		p->hp = 150; p->attack = 20; p->defence = 50; p->speed = 1; p->totalHp = 150;
		p->level = 1; p->questPoint = 1; p->fightTurn = 1; p->successPoint = 0; p->temporary = 0;
		p->ammor = 0; p->stun = 0; p->skillPoint = 0; 
		break;
	case 2:
		p->equipment = 2; // 활
		printf("여관주인 : 장궁이라... 신중함과 날카로운 통찰력을 지닌 자만이 다룰 수 있는 무기지.\n혼돈 속에서도 침착하게 핵심을 꿰뚫어 보려는 자네에게 어울리는군.\n");
		p->hp = 100; p->attack= 50; p->defence = 10; p->speed = 6; p->totalHp = 100;
		p->level = 1; p->questPoint = 1; p->fightTurn = 1; p->successPoint = 0; p->temporary = 0;
		p->ammor = 0; p->stun = 0; p->skillPoint = 0;
		break;
	case 3:
		p->equipment = 3; // 지팡이
		printf("여관주인 : 룬 지팡이... 힘이 아닌 지혜로 세상을 이해하고, 보이지 않는 힘을 다스리려는 자의 선택이군.\n그 끝없는 탐구심을 존중하네.\n");
		p->hp = 100; p->attack = 30; p->defence = 20; p->speed = 3; p->totalHp = 100;
		p->level = 1; p->questPoint = 1; p->fightTurn = 1; p->successPoint = 0; p->temporary = 0;
		p->ammor = 0; p->stun = 0; p->skillPoint = 0;
		break;
	default:
		break;
	}

	cls();

	printf("여관주인 : 좋아, %s. 이제 자네는 단순한 방랑자가 아니라, 이 마을의 운명을 짊어질 수도 있는 모험가일세.\n", p->name);
	printf("여관주인 : 첫 번째 시련을 들을 준비는 되었나?\n");
	cls();
}