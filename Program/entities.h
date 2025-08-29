#pragma once

typedef struct Player
{
	char name[50];
	int equipment;
	int level;
	int hp;
	int attack;
	int defence;
	int questPoint;				// ���� ����Ʈ ���൵
	int fightTurn;
	int successPoint;			// �̼� ���� Ƚ��
	int speed;					// �ӵ��� ������ �켱�� ����.
}Player;

typedef struct Monster
{
	char name[50];
	int level;
	int hp;
	int attack;
	int defence;
	int speed;
}Monster;