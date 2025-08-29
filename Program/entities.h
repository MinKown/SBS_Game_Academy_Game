#pragma once

typedef struct Player
{
	char name[50];
	int equipment;
	int level;
	int hp;
	int attack;
	int defence;
	int questPoint;				// 현재 퀘스트 진행도
	int fightTurn;
	int successPoint;			// 미션 성공 횟수
	int speed;					// 속도가 공격의 우선을 정함.
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