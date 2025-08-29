#pragma once

#include "entities.h"
#include "skills.h"

#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <time.h>
#include <stdbool.h>

struct Player player;

struct Monster frest[2] = { {"고블린1", 1, 100, 10, 10, 10}, {"고블린2", 1, 100, 10, 10, 10} };
struct Monster river[3] = { {"도적1", 1, 100, 10, 10, 1}, {"도적2", 1, 100, 10, 10, 1}, {"도적3", 1, 100, 10, 10, 1} };
struct Monster hills[4] = { {"늑대1", 1, 100, 10, 10, 3}, {"늑대2", 1, 100, 10, 10, 3}, 
	{"늑대3", 1, 100, 10, 10, 3}, {"늑대", 1, 100, 10, 10, 5} };

void cls() {
	printf("\n");
	system("pause");
	system("cls");
}

void makeName() {
	printf("[낡은 여관의 문이 삐걱이며 열린다.]\n");
	printf("여관주인 : 그쪽은 이름이 어떻게 되나?\n");
	printf("이름 : ");
	if (fgets(player.name, 49, stdin) != NULL) {
		player.name[strcspn(player.name, "\n")] = '\0';
	}

	printf("여관주인 : 좋아. 준비를 시작하지.\n");
	
	system("pause");
	system("cls");
}

void choiceJob() {
	printf("[달그락거리며 여관주인은 여러 장구류를 가져온다.]\n");
	printf("여관주인 : 어떤걸 고르시겠습니까?\n");
	printf("[1. 검 2. 활 3. 지팡이]\n");
	printf("선택 : ");

	int playerChoice;
	scanf_s("%d", &playerChoice);

	switch (playerChoice)
	{
	case 1:
		player.equipment = 1; // 검
		printf("여관주인 : 오, 튼튼한 검을 집었군.\n");
		printf("여관주인 : 이제 모험가다운 모습이로군!\n");
		player.hp = 150; player.attack = 20; player.defence = 50; player.speed = 3;
		player.level = 1; player.questPoint = 1; player.fightTurn = 1; player.successPoint = 0;
		break;
	case 2:
		player.equipment = 2; // 활
		printf("여관주인 : 조용히, 그러나 멀리 보는 눈을 가진 자네와 잘 어울리는군...\n");
		player.hp = 100; player.attack = 50; player.defence = 10; player.speed = 2;
		player.level = 1; player.questPoint = 1; player.fightTurn = 1; player.successPoint = 0;
		break;
	case 3:
		player.equipment = 3; // 지팡이
		printf("여관주인 : 마법을 택했군, 지혜로운 선택일세...\n");
		player.hp = 100; player.attack = 30; player.defence = 20; player.speed = 6;
		player.level = 1; player.questPoint = 1; player.fightTurn = 1; player.successPoint = 0;
		break;
	default:
		break;
	}
	cls();
	printf("여관주인 : 무운을 비네");
	cls();
}

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

int choiceMission() {
	int choice = 0;
	printf("1. 숲 가장자리	2. 마을 강가 근처	3. 북쪽 구릉지		4. 마을\n");
	printf("어디로 향하시겠습니까? : ");
	scanf_s("%d", &choice);

	return choice;
}

void stageInfo(int stage, struct Monster *f, struct Monster* r, struct Monster* h) {
	switch (stage) {
	case 1:
		for (int i = 0; i < 2; i++) {
			printf("적 : %s		체력 : %d	  공격력 : %d		방어력 : %d		속도 : %d\n", 
				frest[i].name, frest[i].hp, frest[i].attack, frest[i].defence, frest[i].speed);
		}
		break;
	case 2:
		for (int i = 0; i < 3; i++) {
			printf("적 : %s		체력 : %d	  공격력 : %d		방어력 : %d		속도 : %d\n", 
				river[i].name, river[i].hp, river[i].attack, river[i].defence, river[i].speed);
		}
		break;
	case 3:
		for (int i = 0; i < 4; i++) {
			printf("적 : %s		체력 : %d	  공격력 : %d		방어력 : %d		속도 : %d\n", 
				hills[i].name, hills[i].hp, hills[i].attack, hills[i].defence, hills[i].speed);
		}
		break;
	}
	cls();
}

int skill() {
	int choice = 0, damage = 0;
	
	switch (player.equipment) {
	case 1:
		printf("검의 기술\n");
		printf("1. 베기\n");
		printf("=================\n");
		printf("선택 : ");
		scanf_s("%d", &choice);

		if (choice == 1) {
			damage = player.attack;
		}

		break;
	case 2:
		printf("활의 기술\n");
		printf("1. 쏘기\n");
		printf("=================\n");
		printf("선택 : ");
		scanf_s("%d", &choice);

		if (choice == 1) {
			damage = player.attack;
		}

		break;
	case 3:
		printf("지팡이의 기술\n");
		printf("1. 불꽃\n");
		printf("=================\n");
		printf("선택 : ");
		scanf_s("%d", &choice);

		if (choice == 1) {
			damage = player.attack;
		}

		break;
	}

	return damage;
}

void battle(int stage, struct Monster f[], struct Monster r[], struct Monster h[], int stageTurn, bool myTurn) {
	int damage = 0;
	int enemyDamage = 0;
	int turn = stageTurn;
	int random = 0;

	switch (stage) {
	case 1:
		damage = skill();
		enemyDamage = f[turn].attack;
		
		int playerTotalDamage = 0;
		int enemyTotalDamage = 0;

		if (f[turn].hp <= 0) {
			turn = 0;
		}
		printf("%d 번째 턴\n", turn + 1);

		if (f[turn].speed > player.speed) myTurn = false;

		// 속도에 따라 공격 순서가 바뀜.
		if (myTurn == true) {
			// player 크리티컬 : 30% 확률로 발동
			random = rand() % 100 + 1;
			if (random >= 70) {
				damage += damage;
				printf("[크리티컬!] ");
			}
			printf("나의 공격 (%d)\n", damage);
			
			// Enemy 방어
			if (damage > f[turn].defence) {
				playerTotalDamage = damage - f[turn].defence;
			}
			else playerTotalDamage = 0;
			
			f[turn].hp -= playerTotalDamage;

			if (f[turn].hp > 0) {
				// enemy 크리티컬 : 10% 확률로 발동
				random = rand() % 100 + 1;
				if (random >= 90) {
					enemyDamage += enemyDamage;
					printf("[크리티컬!] ");
				}
				printf("적의 공격 (%d)\n", enemyDamage);

				// Player 방어
				if (enemyDamage > player.defence) {
					enemyTotalDamage = enemyDamage - player.defence;
				}
				else enemyTotalDamage = 0;

				player.hp -= enemyTotalDamage;
			}
		}
		else {
			// enemy 크리티컬 : 10% 확률로 발동
			random = rand() % 100 + 1;
			if (random >= 10) {
				enemyDamage += enemyDamage;
				printf("[크리티컬!] ");
			}
			printf("적의 공격 (%d)\n", enemyDamage);
			
			// Player 방어
			if (enemyDamage > player.defence) {
				enemyTotalDamage = enemyDamage - player.defence;
			}
			else enemyTotalDamage = 0;

			player.hp -= enemyTotalDamage;

			if (player.hp > 0) {
				// player 크리티컬 : 30% 확률로 발동
				random = rand() % 100 + 1; 
				if (random >= 30) {
					damage += damage;
					printf("[크리티컬!] ");
				}
				printf("나의 공격 (%d)\n", damage);

				// Enemy 방어
				if (damage > f[turn].defence) {
					playerTotalDamage = damage - f[turn].defence;
				}
				else playerTotalDamage = 0;

				f[turn].hp -= playerTotalDamage;
			}
		}

		printf("\n");
		break;

	case 2:
		damage = skill();
		enemyDamage = r[turn].attack;

		if (r[turn].hp <= 0) {
			turn = 0;
		}
		printf("%d 번째 턴\n", turn + 1);

		if (r[turn].speed > player.speed) myTurn = false;

		// 속도에 따라 공격 순서가 바뀜.
		if (myTurn) {
			// player 크리티컬 : 30% 확률로 발동
			random = rand() % 100 + 1;
			if (random >= 70) {
				damage += damage;
				printf("[크리티컬!] ");
			}

			printf("나의 공격 (%d)\n", damage);
			
			// Enemy 방어
			if (damage > r[turn].defence) {
				playerTotalDamage = damage - r[turn].defence;
			}
			else playerTotalDamage = 0;

			r[turn].hp -= playerTotalDamage;

			if (r[turn].hp > 0) {
				// enemy 크리티컬 : 10% 확률로 발동
				random = rand() % 100 + 1;
				if (random >= 90) {
					enemyDamage += enemyDamage;
					printf("[크리티컬!] ");
				}
				printf("적의 공격 (%d)\n", enemyDamage);
				
				// Player 방어
				if (enemyDamage > player.defence) {
					enemyTotalDamage = enemyDamage - player.defence;
				}
				else enemyTotalDamage = 0;

				player.hp -= enemyTotalDamage;
			}
		}
		else {
			// enemy 크리티컬 : 10% 확률로 발동
			random = rand() % 100 + 1;
			if (random >= 90) {
				enemyDamage += enemyDamage;
				printf("[크리티컬!] ");
			}
			printf("적의 공격 (%d)\n", enemyDamage);
			
			// Player 방어
			if (enemyDamage > player.defence) {
				enemyTotalDamage = enemyDamage - player.defence;
			}
			else enemyTotalDamage = 0;

			player.hp -= enemyTotalDamage;

			if (player.hp > 0) {
				// player 크리티컬 : 30% 확률로 발동
				random = rand() % 100 + 1;
				if (random >= 70) {
					damage += damage;
					printf("[크리티컬!] ");
				}

				printf("나의 공격 (%d)\n", damage);
				
				// Enemy 방어
				if (damage > r[turn].defence) {
					playerTotalDamage = damage - r[turn].defence;
				}
				else playerTotalDamage = 0;

				r[turn].hp -= playerTotalDamage;
			}
		}

		printf("\n");
		break;

	case 3:
		damage = skill();
		enemyDamage = h[turn].attack;

		if (h[turn].hp <= 0) {
			turn = 0;
		}
		printf("%d 번째 턴\n", turn + 1);

		if (h[turn].speed > player.speed) myTurn = false;

		// 속도에 따라 공격 순서가 바뀜.
		if (myTurn == true) {
			// player 크리티컬 : 30% 확률로 발동
			random = rand() % 100 + 1;
			if (random >= 30) {
				damage += damage;
				printf("[크리티컬!] ");
			}

			printf("나의 공격 (%d)\n", damage);
			
			// Enemy 방어
			if (damage > h[turn].defence) {
				playerTotalDamage = damage - h[turn].defence;
			}
			else playerTotalDamage = 0;

			h[turn].hp -= playerTotalDamage;

			if (h[turn].hp > 0) {
				// enemy 크리티컬 : 10% 확률로 발동
				random = rand() % 100 + 1;
				if (random >= 10) {
					enemyDamage += enemyDamage;
					printf("[크리티컬!] ");
				}

				printf("적의 공격 (%d)\n", enemyDamage);
				
				// Player 방어
				if (h[turn].attack > player.defence) {
					enemyTotalDamage = enemyDamage - player.defence;
				}
				else enemyTotalDamage = 0;

				player.hp -= enemyTotalDamage;
			}
		}
		else {
			// enemy 크리티컬 : 10% 확률로 발동
			random = rand() % 100 + 1;
			if (random >= 10) {
				enemyDamage += enemyDamage;
				printf("[크리티컬!] ");
			}
			printf("적의 공격 (%d)\n", enemyDamage);
			
			// Player 방어
			if (f[turn].attack > player.defence) {
				enemyTotalDamage = enemyDamage - player.defence;
			}
			else enemyTotalDamage = 0;

			player.hp -= enemyTotalDamage;

			if (player.hp > 0) {
				// player 크리티컬 : 30% 확률로 발동
				random = rand() % 100 + 1;
				if (random >= 30) {
					damage += damage;
					printf("[크리티컬!] ");
				}

				printf("나의 공격 (%d)\n", damage);
				
				// Enemy 방어
				if (damage > h[turn].defence) {
					playerTotalDamage = damage - h[turn].defence;
				}
				else playerTotalDamage = 0;

				h[turn].hp -= playerTotalDamage;
			}
		}

		printf("\n");
		break;
	}
}

int main() {
	srand(time(NULL));
	//int random = rand() % 100 + 1;		// 1 ~ 100 난수
	int missionChoice = 0;				// switch (state) case 2: 에서 사용되는 선택
	int villageChoice = 0;				// switch (state) case 4: 에서 사용되는 선택
	int hotelChoice = 0;				// switch (state) case 4: 에서 사용되는 선택
	int state = 0;						// while 문 안에서 state를 이용해서 유기적인 반복문 진행
	int i = 0;
	int stageTurn = 0;					// 전투에서 벌어지는 턴
	int fightOrder = 0;					// 던전 몬스터의 수
	int useSmithy = 0;					// 최대 대장간 사용 수
	int useHotel = 0;					// 최대 여관 사용 수
	int useStore = 0;					// 최대 상점 사용 수
	int deathCount = 0;					// 죽은 횟수

	typedef uint32_t SkillMask;
	SkillMask test = 0;
	int testChoice = 0;

	bool myTurn = true;					// 내가 속도가 적보다 빠름
	bool running = true;
	bool fighting = true;

	while (running) {
		switch (state) {
		case 0:		// 직업 결정
			printf("간단한 MUD 게임\n");
			makeName();
			choiceJob();
			state = 1;
			break;
		case 1:		// 스토리 및 임무 받기
			switch (player.questPoint)
			{
				
			case 1:		// 첫 번째 임무
				printf("스페이스바를 눌러주세요.\n");
				while (i < 7) {
					if (GetAsyncKeyState(VK_SPACE) & 0x0001) {
						printf("%s\n", Talk1[i]);
						i++;
					}
				}
				state = 4;
				i = 0;
				break;

			case 2:		// 두 번째 임무
				printf("스페이스바를 눌러주세요.\n");
				while (i < 6) {
					if (GetAsyncKeyState(VK_SPACE) & 0x0001) {
						printf("%s\n", Talk2[i]);
						i++;
					}
				}
				state = 4;
				i = 0;
				break;

			case 3:		// 세 번째 임무
				printf("스페이스바를 눌러주세요.\n");
				while (i < 6) {
					if (GetAsyncKeyState(VK_SPACE) & 0x0001) {
						printf("%s\n", Talk3[i]);
						i++;
					}
				}
				state = 4;
				i = 0;
				break;

			case 4:		// 네 번째 임무
				printf("스페이스바를 눌러주세요.\n");
				while (i < 4) {
					if (GetAsyncKeyState(VK_SPACE) & 0x0001) {
						printf("%s\n", Talk4[i]);
						i++;
					}
				}
				state = 5;
				i = 0;
				break;
			}
			cls();
			break;

		case 2:		// 임무 장소 선택 및 설명
			missionChoice = choiceMission();
			if (missionChoice == 1 || missionChoice == 2 || missionChoice == 3) {
				
				state = 3;
			}
			else state = 4;
			
			break;

		case 3:		// 전투
			switch (missionChoice)
			{
			case 1:
				if (player.questPoint < 1) {
					printf("현재 접근할 수 없어.\n");
					state = 2;
					break;
				}
				if (player.successPoint >= 1) {
					printf("이곳에서의 볼 일은 끝났어.\n");
					state = 2;
					break;
				}

				stageInfo(missionChoice, frest, river, hills);

				while (fighting) {
					printf("나 : %s		체력 : %d	  공격력 : %d		방어력 : %d		속도 : %d\n",
						player.name, player.hp, player.attack, player.defence, player.speed);
					printf("적 : %s		체력 : %d	  공격력 : %d		방어력 : %d		속도 : %d\n",
						frest[fightOrder].name, frest[fightOrder].hp, frest[fightOrder].attack, frest[fightOrder].defence, frest[fightOrder].speed);

					//printf("선택 : ");
					//scanf_s("%d", &testChoice);
					//
					//if (testChoice == 1) test |= SKILL_ATTACK;

					applySkills(SKILL_ATTACK, &player, &frest[0]);

					// 수정할것. 공격은 되게 만들었지만, 이제 stageTurn, fightOrder 등 frest, river, hills도 되게 만들어야함.
					// hp가 0가 되는지 안되는지 모르다 보니 계속 공격만함.

					//battle(missionChoice, frest, river, hills, stageTurn, myTurn);
					myTurn = true;

					if (frest[fightOrder].hp <= 0) {
						stageTurn++;
						fightOrder++;
					}
					if (stageTurn == 2) {		// 모든 적 처치
						printf("나는 고블린들의 이빨을 뜯어 주머니에 넣었다.\n");
						player.questPoint++;
						player.successPoint++;
						stageTurn = 0;
						fightOrder = 0;
						break;
					}
					if (player.hp <= 0) {
						printf("나의 패배다.\n");
						fighting = false;
						state = 10;
						break;
					}
				}
				state = 4;		// 마을 귀환
				cls();

				break;

			case 2:
				if (player.questPoint < 2) {
					printf("현재 접근할 수 없어.\n");
					state = 2;
					break;
				}
				if (player.successPoint >= 2) {
					printf("이곳에서의 볼 일은 끝났어.\n");
					state = 2;
					break;

				}

				stageInfo(missionChoice, frest, river, hills);

				while (fighting) {
					printf("나 : %s		체력 : %d	  공격력 : %d		방어력 : %d		속도 : %d\n",
						player.name, player.hp, player.attack, player.defence, player.speed);
					printf("적 : %s		체력 : %d	  공격력 : %d		방어력 : %d		속도 : %d\n",
						river[fightOrder].name, river[fightOrder].hp, river[fightOrder].attack, river[fightOrder].defence, river[fightOrder].speed);
					
					battle(missionChoice, frest, river, hills, stageTurn, myTurn);

					if (river[fightOrder].hp <= 0) {
						stageTurn++;
						fightOrder++;
					}
					if (stageTurn == 3) {		// 모든 적 처치
						printf("도둑 클리어\n");
						player.questPoint++;
						player.successPoint++;
						stageTurn = 0;
						fightOrder = 0;
						break;
					}
					if (player.hp <= 0) {		
						printf("나의 패배다.\n");
						fighting = false;
						state = 10;
						break;
					}
				}
				state = 4;		// 마을 귀환
				cls();

				break;

			case 3:
				if (player.questPoint < 3) {
					printf("현재 접근할 수 없어.\n");
					state = 2;
					break;
				}
				if (player.successPoint >= 3) {
					printf("이곳에서의 볼 일은 끝났어.\n");
					state = 2;
					break;
				}

				stageInfo(missionChoice, frest, river, hills);

				while (fighting) {
					printf("나 : %s		체력 : %d	  공격력 : %d		방어력 : %d		속도 : %d\n",
						player.name, player.hp, player.attack, player.defence, player.speed);
					printf("적 : %s		체력 : %d	  공격력 : %d		방어력 : %d		속도 : %d\n",
						hills[fightOrder].name, hills[fightOrder].hp, hills[fightOrder].attack, hills[fightOrder].defence, hills[fightOrder].speed);
					
					

					battle(missionChoice, frest, river, hills, stageTurn, myTurn);

					if (hills[fightOrder].hp <= 0) {
						stageTurn++;
						fightOrder++;
					}
					if (stageTurn == 4) {		// 모든 적 처치
						printf("늑대 클리어\n");
						player.questPoint++;
						player.successPoint++;
						stageTurn = 0;
						fightOrder = 0;
						break;
					}
					if (player.hp <= 0) {
						printf("나의 패배다.\n");
						fighting = false;
						state = 7;
						break;
					}
				}
				state = 4;		// 마을 귀환
				cls();

				break;
			default:
				break;
			}
			break;

		case 4:		// 마을
			printf("마을\n");
			printf("1. 여관		2. 대장간		3. 상점		4. 임무 수행\n");
			printf("선택 : ");
			scanf_s("%d", &villageChoice);

			switch (villageChoice)
			{
			case 1:		// 여관
				printf("무엇을 하지 ?\n");
				printf("1. 휴식		2. 여관주인\n");
				printf("선택 : ");
				scanf_s("%d", &hotelChoice);
				switch (hotelChoice)
				{
				case 1:			// 휴식
					if (useHotel >= 6) {
						printf("사용 할 수 있는 횟수를 넘어섰습니다.\n");
						break;
						state = 4;
					}
					printf("잠시 휴식을 해야겠어.\n");
					printf("현재 %d 번 사용하셨습니다. 총 6번 사용 가능합니다.\n", useHotel + 1);
					if (player.equipment == 1) player.hp = 150;
					if (player.equipment == 2) player.hp = 100;
					if (player.equipment == 3) player.hp = 100;

					useHotel++;

					break;
				case 2:
					state = 1;
					break;
				default:
					break;
				}
				break;
			case 2:		// 대장간
				if (useSmithy >= 6) {
					printf("사용 할 수 있는 횟수를 넘어섰습니다.\n");
					break;
					state = 4;
				}
				printf("대장간 사용\n");				

				switch (player.equipment)
				{
				case 1:		// 검
					printf("깡 깡 깡\n");
					printf("대장장이가 망치를 들고 내려치는 소리가 들린다.\n");
					printf("[힘 + 10]\n");
					player.attack += 10;
					break;
				case 2:		// 활
					break;
				case 3:		// 마법사
					break;
				}


				printf("현재 %d 번 사용하셨습니다. 총 6번 사용 가능합니다.\n", useSmithy + 1);
				useSmithy++;
				state = 4;
				break;
			case 3:		// 상점
				if (useStore >= 6) {
					printf("사용 할 수 있는 횟수를 넘어섰습니다.\n");
					break;
					state = 4;
				}
				printf("상점 사용\n");
				printf("현재 %d 번 사용하셨습니다. 총 6번 사용 가능합니다.\n", useStore + 1);
				
				useStore++;
				state = 4;
				break;
			case 4:
				state = 2;
				break;
			}
			break;

		case 5:		// 승리
			cls();
			printf("당신의 승리입니다.\n");
			break;

		case 6:		// 종료
			cls();
			printf("당신의 패배입니다.\n");
			break;
		case 7:		// 성당 : 죽은 뒤 다시 태어남
			if (deathCount >= 6) {
				break;
				state = 6;
			}
			printf("성당 사용\n");
			printf("현재 %d 번 사용하셨습니다. 총 6번 사용 가능합니다.\n", deathCount + 1);
			deathCount++;
			state = 4;
			break;
		}
		
		if (player.hp <= 0) {
			break;
		}
		if (state == 5) break;
		if (state == 6) break;
	}

	return 0;
}

