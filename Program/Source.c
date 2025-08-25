#include <stdio.h>
#include <string.h>

struct Player
{
	char name[50];
	char equipment[30];
	int level;
	int hp;
	int attack;
	int defence;
	int questPoint;
};

struct Monster
{
	char name[50];
	int level;
	int hp;
	int attack;
	int defence;
};

void makeName(struct  Player* p) {
	printf("[낡은 여관의 문이 삐걱이며 열린다.]\n");
	printf("여관주인 : 그쪽은 이름이 어떻게 되나?\n");

	if (fgets(p->name, 49, stdin) != NULL) {
		p->name[strcspn(p->name, "\n")] = '\0';
	}

	printf("여관주인 : 좋아. 준비를 시작하지.\n");
	
	system("pause");
	system("cls");
}

void choiceJob(struct Player *p) {
	printf("[달그락거리며 여관주인은 여러 장구류를 가져온다.]\n");
	printf("여관주인 : 어떤걸 고르시겠습니까?\n");
	printf("[1. 검 2. 활 3. 지팡이]\n");

	int playerChoice;
	scanf_s("%d", &playerChoice);

	switch (playerChoice)
	{
	case 1:
		strcpy_s(p -> equipment, 30, "Sword");
		printf("여관주인 : 오, 튼튼한 검을 집었군.\n");
		printf("여관주인 : 이제 모험가다운 모습이로군!\n");
		p->hp = 150;
		p->attack = 10;
		p->defence = 50;
		p->level = 1;
		p->questPoint = 1;
		break;
	case 2:
		strcpy_s(p->equipment, 30, "Bow");
		printf("여관주인 : 조용히, 그러나 멀리 보는 눈을 가진 자네와 잘 어울리는군...\n");
		p->hp = 100;
		p->attack = 20;
		p->defence = 30;
		p->level = 1;
		p->questPoint = 1;
		break;
	case 3:
		strcpy_s(p->equipment, 30, "Wand");
		printf("여관주인 : 마법을 택했군, 지혜로운 선택일세...\n");
		p->hp = 100;
		p->attack = 30;
		p->defence = 10;
		p->level = 1;
		p->questPoint = 1;
		break;
	default:
		break;
	}

	system("pause");
	system("cls");
	printf("여관주인 : 무운을 비네\n");
	system("pause");
	system("cls");
}

void Quest() {
	
	
	const char* Talk[7] = {
		"여관주인 : 이 마을은 지금 벼랑 끝에 있다.",
		"여관주인 : 그러나 솟아날 구멍은 있지.",
		"여관주인 : 의뢰 세 건을 모두 끝내고나면 당신은 승리자로 이름을 남기게 될 것이다.",
		"여관주인 : 시작은 가볍게 하지.",
		"여관주인 : 숲 가장자리의 고블린, 그들의 이빨 3개를 모아와라.",
		"여관주인 : 너의 용기를 한 번 확인해보겠다.",
		"여관주인 : 돌아오면 다음 의뢰를 알려주지.",
	};
}

int main() {
	struct Player player;

	struct Monster frest[3] = { {"고블린", 1, 100, 10, 10}, {"고블린", 1, 100, 10, 10} , {"고블린", 1, 100, 10, 10} };

	printf("간단한 MUD 게임\n");

	makeName(&player);

	choiceJob(&player);

	Quest(&player);



	return 0;
}

