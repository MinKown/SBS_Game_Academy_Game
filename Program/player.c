#pragma once

#include "entities.h"
#include "all.h"

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

void cls() {
	printf("\n");
	system("pause");
	system("cls");
}

void choiceJob(Player* p) {
	printf("여관주인 : 말만으로는 괴물을 잡을 순 없지.\n");
	printf("여관주인 : 모든 위대한 여정은 첫 무기와 함께 시작되는 법이야.\n");
	printf("여관주인 : 자네의 심장이 이끄는 것을 골라보게.\n");
	printf("[1. 검과 방패	2. 낡은 장궁	3. 룬이 새겨진 지팡이]\n");
	printf("선택 : ");

	int playerChoice;
	scanf_s("%d", &playerChoice);

	switch (playerChoice)
	{
	case 1:
		p->equipment = 1; // 검
		printf("여관주인 : 검과 방패... 가장 정직하고 용감한 길이지. 자네의 의지가 보이는군.\n");
		p->hp = 120; p->attack = 25; p->defence = 15; p->speed = 2; p->totalHp = 120;
		p->level = 1; p->questPoint = 1; p->fightTurn = 1; p->successPoint = 0; p->temporary = 0;
		p->ammor = 0; p->stun = 0; p->skillPoint = 0;
		break;
	case 2:
		p->equipment = 2; // 활
		printf("여관주인 : 장궁이라... 신중함과 날카로운 통찰력을 지닌 자의 무기지.\n");
		p->hp = 80; p->attack = 40; p->defence = 5; p->speed = 8; p->totalHp = 80;
		p->level = 1; p->questPoint = 1; p->fightTurn = 1; p->successPoint = 0; p->temporary = 0;
		p->ammor = 0; p->stun = 0; p->skillPoint = 0;
		break;
	case 3:
		p->equipment = 3; // 지팡이
		printf("여관주인 : 룬 지팡이... 힘이 아닌 지혜로 세상을 다스리려는 자의 선택이군.\n");
		p->hp = 90; p->attack = 35; p->defence = 10; p->speed = 5; p->totalHp = 90;
		p->level = 1; p->questPoint = 1; p->fightTurn = 1; p->successPoint = 0; p->temporary = 0;
		p->ammor = 0; p->stun = 0; p->skillPoint = 0;
		break;
	default:
		printf("흠... 제대로 고른 것 맞나?\n");
		choiceJob(p);
		break;
	}

	cls();

	printf("여관주인 : 좋아, %s. 이제 자네는 단순한 방랑자가 아니라, 이 마을의 운명을 짊어질 수도 있는 모험가일세.\n", p->name);
	printf("여관주인 : 첫 번째 시련을 들을 준비는 되었나?\n");
	cls();
}

void makeName(Player* p) {
	printf("여관주인 : 또 한 명의 방랑자로군... 하지만 그 눈은 아직 희망을 잃지 않았어.\n");
	printf("여관주인 : 이 험한 땅에서 불릴 이름이라도 있나?\n");
	printf("이름 : ");

	if (fgets(p->name, 49, stdin) != NULL) {
		p->name[strcspn(p->name, "\n")] = '\0';
	}

	printf("\n여관주인 : %s 이라... 좋은 이름이야. 부디 절망이 아닌 승리와 함께 기억될 이름이 되길 바라지.\n", p->name);
	printf("여관주인 : 자, 여정에는 준비가 필요한 법. 이리 가까이 오게.\n");
	system("pause");
	system("cls");
}