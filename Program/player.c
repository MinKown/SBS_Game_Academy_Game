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
	printf("�������� : �������δ� ������ ���� �� ����.\n");
	printf("�������� : ��� ������ ������ ù ����� �Բ� ���۵Ǵ� ���̾�.\n");
	printf("�������� : �ڳ��� ������ �̲��� ���� ��󺸰�.\n");
	printf("[1. �˰� ����	2. ���� ���	3. ���� ������ ������]\n");
	printf("���� : ");

	int playerChoice;
	scanf_s("%d", &playerChoice);

	switch (playerChoice)
	{
	case 1:
		p->equipment = 1; // ��
		printf("�������� : �˰� ����... ���� �����ϰ� �밨�� ������. �ڳ��� ������ ���̴±�.\n");
		p->hp = 120; p->attack = 25; p->defence = 15; p->speed = 2; p->totalHp = 120;
		p->level = 1; p->questPoint = 1; p->fightTurn = 1; p->successPoint = 0; p->temporary = 0;
		p->ammor = 0; p->stun = 0; p->skillPoint = 0;
		break;
	case 2:
		p->equipment = 2; // Ȱ
		printf("�������� : ����̶�... �����԰� ��ī�ο� �������� ���� ���� ������.\n");
		p->hp = 80; p->attack = 40; p->defence = 5; p->speed = 8; p->totalHp = 80;
		p->level = 1; p->questPoint = 1; p->fightTurn = 1; p->successPoint = 0; p->temporary = 0;
		p->ammor = 0; p->stun = 0; p->skillPoint = 0;
		break;
	case 3:
		p->equipment = 3; // ������
		printf("�������� : �� ������... ���� �ƴ� ������ ������ �ٽ������� ���� �����̱�.\n");
		p->hp = 90; p->attack = 35; p->defence = 10; p->speed = 5; p->totalHp = 90;
		p->level = 1; p->questPoint = 1; p->fightTurn = 1; p->successPoint = 0; p->temporary = 0;
		p->ammor = 0; p->stun = 0; p->skillPoint = 0;
		break;
	default:
		printf("��... ����� �� �� �³�?\n");
		choiceJob(p);
		break;
	}

	cls();

	printf("�������� : ����, %s. ���� �ڳ״� �ܼ��� ����ڰ� �ƴ϶�, �� ������ ����� ������ ���� �ִ� ���谡�ϼ�.\n", p->name);
	printf("�������� : ù ��° �÷��� ���� �غ�� �Ǿ���?\n");
	cls();
}

void makeName(Player* p) {
	printf("�������� : �� �� ���� ����ڷα�... ������ �� ���� ���� ����� ���� �ʾҾ�.\n");
	printf("�������� : �� ���� ������ �Ҹ� �̸��̶� �ֳ�?\n");
	printf("�̸� : ");

	if (fgets(p->name, 49, stdin) != NULL) {
		p->name[strcspn(p->name, "\n")] = '\0';
	}

	printf("\n�������� : %s �̶�... ���� �̸��̾�. �ε� ������ �ƴ� �¸��� �Բ� ���� �̸��� �Ǳ� �ٶ���.\n", p->name);
	printf("�������� : ��, �������� �غ� �ʿ��� ��. �̸� ������ ����.\n");
	system("pause");
	system("cls");
}