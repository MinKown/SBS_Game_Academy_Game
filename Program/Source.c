#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <time.h>

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

struct Monster frest[2] = { {"고블린", 1, 100, 10, 10}, {"고블린", 1, 100, 10, 10} };
struct Monster river[3] = { {"도적", 1, 100, 10, 10}, {"도적", 1, 100, 10, 10}, {"도적", 1, 100, 10, 10} };
struct Monster northernHills[4] = { {"늑대", 1, 100, 10, 10}, {"늑대", 1, 100, 10, 10}, {"늑대", 1, 100, 10, 10}, {"늑대", 1, 100, 10, 10} };

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

void Quest(struct Player *p) {
	
	const char* Talk1[7] = {
		"여관주인 : 이 마을은 지금 벼랑 끝에 있다.",
		"여관주인 : 하지만 아직 희망은 남아 있지.",
		"여관주인 : 의뢰 세 건을 모두 완수한다면, 자네는 승리자로 이름을 남기게 될 것이다.",
		"여관주인 : 시작은 가볍게 하지.",
		"여관주인 : 숲 가장자리의 고블린, 그들의 이빨 2개를 모아와라.",
		"여관주인 : 너의 용기를 한 번 확인해보겠다.",
		"여관주인 : 돌아오면 다음 의뢰를 알려주지.",
	};

	const char* Talk2[6] = {
		"여관주인 : 고블린의 이빨을 모아오다니, 제법이군.",
		"여관주인 : 이제 마을 사람들이 읽어버린 물건을 찾아줄 차례다.",
		"여관주인 : 강가 근처에 도적떼가 출몰한다는 소문이 있다.",
		"여관주인 : 그들이 훔쳐간 [은반지]를 되찾아오게.",
		"여관주인 : 이번 의뢰를 단순하다고 생각하지말게.",
		"여관주인 : 성공하면 마지막 시련을 맡길 수 있겠지."
	};

	const char* Talk3[6] = {
		"여관주인 : 은반지를 되찾아왔다니, 훌륭하군.",
		"여관주인 : 이제 마지막 의뢰를 맡길 때가 된 것 같네.",
		"여관주인 : 마을 북쪽 구릉지에는 [회색 늑대]라 불리는 괴수가 살고있다.",
		"여관주인 : 수많은 이들이 녀석의 발톱에 쓰러져 갔다지.",
		"여관주인 : 녀석을 쓰러뜨리고, 회색 가죽을 가져오게.",
		"여관주인 : 이 임무를 완수한다면 자네는 진정한 승리자로 기억될 것이네."
	};

	const char* Talk4[4] = {
		"여관주인 : 모든 의뢰를 끝내다니, 대단하네.",
		"여관주인 : 이제 자네는 이 마을의 수호자로 불리게 될 걸세.",
		"여관주인 : 무운을 빈다.",
		"여관주인 : 그리고 자네의 앞길에 행운이 함께하길."
	};
	
	int i = 0;

	switch (p->questPoint)
	{
	case 1:
		while (i < 7) {
			if (GetAsyncKeyState(VK_SPACE) & 0x0001) {
				printf("%s\n", Talk1[i]);
				i++;
			}
		}
		p->questPoint++;
		break;
	case 2:
		while (i < 6) {
			if (GetAsyncKeyState(VK_SPACE) & 0x0001) {
				printf("%s\n", Talk2[i]);
				i++;
			}
		}
		p->questPoint++;
		break;
	case 3:
		while (i < 6) {
			if (GetAsyncKeyState(VK_SPACE) & 0x0001) {
				printf("%s\n", Talk3[i]);
				i++;
			}
		}
		p->questPoint++;
		break;
	case 4:
		while (i < 4) {
			if (GetAsyncKeyState(VK_SPACE) & 0x0001) {
				printf("%s\n", Talk4[i]);
				i++;
			}
		}
		break;
	default:
		break;
	}
}

int choiceMission() {
	int choice = 0;
	printf("1. 숲 가장자리	2. 마을 강가 근처	3. 북쪽 구릉지\n");
	printf("어디로 향하시겠습니까? : ");
	scanf_s("%d", &choice);

	return choice;
}

void battle(int stage, int random) {
	switch (stage) {
	case 1:
		for (int i = 0; i < 2; i++) {
			printf("적 : %s		체력 : %d	  공격력 : %d		방어력 : %d", frest[i].name, frest[i].hp, frest[i].attack, frest[i].defence);
		}
	}
}

int main() {
	struct Player player;



	srand(time(NULL));
	int random = rand() % 10 + 1;

	printf("간단한 MUD 게임\n");

	makeName(&player);

	choiceJob(&player);

	Quest(&player);

	battle(1, random);

	/*switch (choiceMission())
	{
	case 1:
		for (int i = 0; i < 3; i++) {
			printf("적 : %s		레벨 : %d	체력 : %d	공격력 : %d		방어력 : %d",
				frest[i].name, frest[i].level, frest[i].hp, frest[i].attack, frest[i].defence);
		}
	default:
		break;
	}*/

	return 0;
}

