#pragma once

#include "entities.h"
#include "all.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <time.h>
#include <stdbool.h>

typedef uint32_t SkillMask;

struct Player player;

// monster: name, level, hp, attack, defence, speed, stun, debuff
struct Monster frest[2] = { {"고블린 척후병", 1, 40, 15, 5, 2, 0, 0, 40}, {"고블린 좀도둑", 1, 50, 18, 5, 1, 0, 0, 40} };
struct Monster river[3] = { {"도적 매복자", 1, 60, 25, 10, 7, 0, 0, 60}, {"도적 싸움꾼", 1, 90, 35, 15, 2, 0, 0, 90}, 
	{"도적 두목", 1, 110, 30, 20, 4, 0, 0, 110} };
struct Monster hills[4] = { {"어린 회색 늑대", 1, 80, 30, 20, 8, 0, 0, 80}, {"어린 회색 늑대", 1, 80, 30, 20, 8, 0, 0, 80},
	{"성체 회색 늑대", 1, 120, 45, 25, 6, 0, 0, 120}, {"우두머리 회색 늑대", 1, 200, 50, 30, 7, 0, 0, 200} };

void stepUp();
void playerLevelUp(int lv);
void enemyLevelUp(int newLevel);



void setTextColor(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// 타이틀 화면을 출력하는 함수
int showTitleScreen() {
	system("cls");
	int choice = 0;

	setTextColor(8);
	printf("\n\n");
	printf("        +--------------------------------------------------------------------+\n");
	setTextColor(14);
	printf("\n"); // 위쪽 여백 추가
	printf("           ::::::::::    ::::::::      ::      ::    :::::::::: \n");
	printf("           ::            ::    ::      ::::  ::::    ::         \n");
	printf("           ::  ::::::    ::::::::      ::  ::  ::    :::::::::: \n");
	printf("           ::      ::    ::    ::      ::      ::    ::         \n");
	printf("           ::::::::::    ::    ::      ::      ::    :::::::::: \n");
	printf("\n"); // 아래쪽 여백 추가
	printf("						THE LAST STORY \n");
	setTextColor(8);
	printf("        +--------------------------------------------------------------------+\n\n");
	printf("\n");

	setTextColor(15);
	printf("                          [ 1. 새로운 모험 시작 ]\n\n");
	printf("                          [ 2. 현실로 돌아가기 ]\n\n");

	setTextColor(7);
	printf("                                                              By [Kang]\n");
	printf("--------------------------------------------------------------------------------\n");
	printf("  선택: ");
	scanf_s("%d", &choice);
	while (getchar() != '\n'); // 입력 버퍼 비우기
	return choice;
}

void printHpBar(int Hp, int maxHp) {
	int barLenght = 20;
	int Hp_val = (Hp < 0) ? 0 : Hp;
	int percentage = (int)(((float)Hp / maxHp) * 100);
	int filledLenght = (int)(barLenght * percentage / 100);

	printf(" [");
	for (int i = 0; i < barLenght; i++) {
		if (i < filledLenght) {
			printf("#");
		}
		else {
			printf("-");
		}
	}
	printf("] %d%% \n", percentage);
}

const char* Talk1[7] = {
		"여관주인 : 이 여관도 한때는 여행자들의 노랫소리로 가득했지... 하지만 이젠 아니야.",
		"여관주인 : 공포는 소리 없이 퍼져나가 마을 전체를 잠식했네. 그 시작은 아주 사소한 것이었지.",
		"여관주인 : 숲 가장자리의 고블린들... 녀석들은 그 자체로 큰 위협은 아니지만, 우리를 갉아먹는 절망의 상징일세.",
		"여관주인 : 사람들에게 아직 희망이 남아있다는 걸 보여줘야 하네.",
		"여관주인 : 녀석들을 처리하고, 그 증거로 [고블린의 이빨] 두 개를 가져오게.",
		"여관주인 : 이건 단순한 사냥이 아니야. 어둠 속에 첫 촛불을 밝히는 일일세.",
		"여관주인 : 자네의 용기를... 이 마을의 마지막 희망을 시험해 보겠네.",
};

const char* Talk2[6] = {
	"여관주인 : 돌아왔군! 그 이빨을 보니... 그래, 아직 끝난 게 아니었어.",
	"여관주인 : 자네 덕분에 마을에 아주 작은 활기가 돌기 시작했네. 하지만 진정한 위협은 아직 남아있지.",
	"여관주인 : 두려움이 퍼진 틈을 타, 강가에 도적 떼가 들끓고 있네. 그들은 사람들의 재산뿐만 아니라 희망마저 훔쳐가고 있어.",
	"여관주인 : 최근 한 가족이 대대로 물려오던 [은반지]를 잃고 상심에 빠져있다네.",
	"여관주인 : 그들에게 반지를 되찾아주게. 이건 단순한 물건이 아니야. 우리가 빼앗긴 것을 되찾을 수 있다는 증거가 될 걸세.",
	"여관주인 : 이번 임무는 자네의 힘뿐만 아니라, 약자를 지키려는 의지를 시험하게 될 걸세."
};

const char* Talk3[6] = {
	"여관주인 : 은반지가 돌아왔다는 소식에 그 가족이 눈물을 흘리는 것을 보았네. 자네가 해낸 일이야.",
	"여관주인 : 이제 마을 사람들은 자네를 단순한 모험가가 아닌, 희망의 상징으로 보고 있네.",
	"여관주인 : 하지만 우리를 짓누르는 공포의 근원은 아직 남아있어. 북쪽 구릉지에 도사린 어둠 말일세.",
	"여관주인 : 사람들은 그곳의 지배자를 [회색 늑대]라 부르지. 녀석은 짐승이 아니라, 이 땅에 내린 재앙 그 자체야.",
	"여관주인 : 수많은 용감한 이들이 녀석에게 도전했지만, 누구도 돌아오지 못했네.",
	"여관주인 : 녀석을 쓰러뜨리고, 그 악명을 증명하는 [회색 가죽]을 가져오게. 이 마을의 진정한 수호자가 될 마지막 시련일세."
};

const char* Talk4[4] = {
	"여관주인 : 해냈군... 정말로 해냈어! 자네가 돌아왔을 때, 구릉지의 음산한 바람이 멎는 것을 느꼈네.",
	"여관주인 : 보게, 창밖을. 사람들이 광장에 모여 자네의 이름을 외치고 있어. 더 이상 두려움에 떨지 않아.",
	"여관주인 : 자네는 이 마을을 구했을 뿐만 아니라, 우리에게 내일을 되찾아 주었네. 우리는 자네를 영원히 '마을의 수호자'로 기억할 걸세.",
	"여관주인 : 진심으로 감사하네, 영웅이여. 자네의 앞길에 언제나 행운과 영광이 함께하길."
};

int choiceMission() {
	int choice = 0;
	printf("1. 숲 가장자리		2. 마을 강가 근처\n3. 북쪽 구릉지		4. 마을\n");
	printf("어디로 향하시겠습니까? : ");
	scanf_s("%d", &choice);

	cls();

	return choice;
}

void stageInfo(int stage, struct Monster *f, struct Monster* r, struct Monster* h) {
	printf("========================================\n");
	printf("			[적 정보]\n");
	printf("========================================\n");

	switch (stage) {
	case 1:
		printf("숲 가장자리에는 총 %d 마리의 적이 있습니다.\n\n", 2);
		for (int i = 0; i < 2; i++) {
			printf("  - %s (LV.%d)\n", frest[i].name, frest[i].level);
		}
		break;
	case 2:
		printf("강가 근처에는 총 %d 마리의 적이 있습니다.\n\n", 3);
		for (int i = 0; i < 3; i++) {
			printf("  - %s (LV.%d)\n", river[i].name, river[i].level);
		}
		break;
	case 3:
		printf("북쪽 구릉지에는 총 %d 마리의 적이 있습니다.\n\n", 4);
		for (int i = 0; i < 4; i++) {
			printf("  - %s (LV.%d)\n", hills[i].name, hills[i].level);
		}
		break;
	}

	printf("========================================\n");
	cls();
}


void playerLevelUp(int lv) {
	if (lv >= 2) {
		player.level++;
	}
	cls();

	stepUp();
	enemyLevelUp(1);
	lv = 0;
}

void stepUp() {
	switch (player.equipment)
	{
	case 1:
		player.hp += 15;
		player.totalHp += 15;
		player.attack += 7;
		player.defence += 5;
		

		printf("[레벨 업 !]\n");
		printf("[체력 + 15  공격력 + 7  방어력 + 5]\n");
		break;
	case 2:
		player.hp += 8;
		player.totalHp += 8;
		player.attack += 12;
		player.defence += 2;

		printf("[레벨 업 !]\n");
		printf("[체력 + 8  공격력 + 12  방어력 + 2]\n");
		break;
	case 3:
		player.hp += 10;
		player.totalHp += 10;
		player.attack += 10;
		player.defence += 3;

		printf("[레벨 업 !]\n");
		printf("[체력 + 10  공격력 + 10  방어력 + 3]\n");
		break;
	}
}

void enemyLevelUp(int newLevel) {
	printf("[적들의 레벨이 상승했습니다!]\n");

	// === 숲 몬스터 레벨업 ===
	// 고블린 척후병 (성장 계수: 체+5, 공+2, 방+1)
	frest[0].level += newLevel;
	frest[0].hp += 5;
	frest[0].attack += 2;
	frest[0].defence += 1;
	frest[0].totalHp += 5;
	// 고블린 좀도둑 (성장 계수: 체+6, 공+3, 방+1)
	frest[1].level += newLevel;
	frest[1].hp += 6;
	frest[1].attack += 3;
	frest[1].defence += 1;
	frest[1].totalHp += 6;

	// === 강가 몬스터 레벨업 ===
	// 도적 매복자 (성장 계수: 체+8, 공+4, 방+2)
	river[0].level += newLevel;
	river[0].hp += 8;
	river[0].attack += 4;
	river[0].defence += 2;
	river[0].totalHp += 8;
	// 도적 싸움꾼 (성장 계수: 체+15, 공+6, 방+2)
	river[1].level += newLevel;
	river[1].hp += 15;
	river[1].attack += 6;
	river[1].defence += 2;
	river[1].totalHp += 15;
	// 도적 두목 (성장 계수: 체+12, 공+5, 방+3)
	river[2].level += newLevel;
	river[2].hp += 12;
	river[2].attack += 5;
	river[2].defence += 3;
	river[2].totalHp += 12;

	// === 구릉지 몬스터 레벨업 ===
	// 어린 회색 늑대 (성장 계수: 체+10, 공+5, 방+3)
	hills[0].level += newLevel;
	hills[0].hp += 10;
	hills[0].attack += 5;
	hills[0].defence += 3;;
	hills[0].totalHp += 10;
	hills[1].level += newLevel;
	hills[1].hp += 10;
	hills[1].attack += 5;
	hills[1].defence += 3;
	hills[1].totalHp += 10;
	// 성체 회색 늑대 (성장 계수: 체+18, 공+7, 방+4)
	hills[2].level += newLevel;
	hills[2].hp += 18;
	hills[2].attack += 7;
	hills[2].defence += 4;
	hills[2].totalHp += 18;
	// 우두머리 회색 늑대 (성장 계수: 체+25, 공+8, 방+5)
	hills[3].level += newLevel;
	hills[3].hp += 25;
	hills[3].attack += 8;
	hills[3].defence += 5;
	hills[3].totalHp += 25;
}




int main() {
	srand((unsigned int)time(NULL));
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
	int totalHp = 0;					// 총 체력
	int lv = 0;							// 레벨
	int cho;

	SkillMask skillMask = 0;

	bool running = true;
	bool fighting = true;

	

	while (running) {
		switch (state) {
		case 0:		// 직업 결정
			cho = showTitleScreen();

			if (cho == 2) {
				running = false; // 게임 종료
				break;
			}
			// 잘못된 입력은 루프를 반복하여 타이틀 화면을 다시 보여줌

			cls();

			makeName(&player);
			choiceJob(&player);
			
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
				cls();
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
				cls();
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
				cls();
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
					printf("==============================================================\n");
					printf("	[전투 중] %s | 남은 적: %d / %d\n", frest[fightOrder].name, fightOrder + 1, 2);
					printf("--------------------------------------------------------------\n");

					printf("  [ %-20s ] (Lv.%d)\n", player.name, player.level);
					printf("  HP: %d | %d\n", player.hp, player.totalHp);
					printHpBar(player.hp, player.totalHp);
					printf("  공격력 : %-5d 방어력 : %-5d 스피드 : %-5d 스킬포인트 : %-5d\n",
						player.attack, player.defence, player.speed, player.skillPoint);
					if (player.stun > 0) printf("	상태: [기절됨! (%d)턴]\n", player.stun);
					printf("\n");

					printf("  [ %-20s ] (Lv.%d)\n", frest[fightOrder].name, frest[fightOrder].level);
					printf("  HP: %d\n", frest[fightOrder].hp);
					printHpBar(frest[fightOrder].hp, frest[fightOrder].totalHp);
					printf("  공격력 : %-5d 방어력 : %-5d 스피드 : %-5d\n", 
						frest[fightOrder].attack, frest[fightOrder].defence, frest[fightOrder].speed);
					if (frest[fightOrder].stun > 0) printf("  상태: [기절됨! (%d)턴]\n", frest[fightOrder].stun);
					if (frest[fightOrder].debuff > 0) printf("  상태: [중독됨! (%d)턴]\n", frest[fightOrder].debuff);
					
					printf("==============================================================\n");

					skillMask |= showSkillsList(&player);

					checkPlayerStun(&player);
					checkEnemyStun(&frest[fightOrder]);
					if (player.equipment == 2) checkPoison(&frest[fightOrder]);

					if (player.speed >= frest[fightOrder].speed) {
						if (player.stun <= 0) {
							applySkills(skillMask, &player, &frest[fightOrder]);
						}
						else {
							player.stun--;
						}

						if (frest[fightOrder].stun <= 0) {
							enemyTurn(&player, &frest[fightOrder]);
						}
						else {
							frest[fightOrder].stun--;
						}
					}
					else if (frest[fightOrder].speed > player.speed) {
						if (frest[fightOrder].stun <= 0) {
							enemyTurn(&player, &frest[fightOrder]);
						}
						else {
							frest[fightOrder].stun--;
						}

						if (player.stun <= 0) {
							applySkills(skillMask, &player, &frest[fightOrder]);
						}
						else {
							player.stun--;
						}
					}
					
					skillMask = 0;

					cls();

					if (frest[fightOrder].hp <= 0) {
						printf("%s 을 쓰러트렸습니다.\n", frest[fightOrder].name);
						stageTurn++;
						fightOrder++;
						lv++;
						cls();
					}

					if (lv == 2) {
						playerLevelUp(lv);
					}

					if (stageTurn == 2) {		// 모든 적 처치
						printf("나는 고블린들의 이빨을 뜯어 주머니에 넣었다.\n");
						player.questPoint++;
						player.successPoint++;
						player.ammor = 0;
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
					printf("==============================================================\n");
					printf("	[전투 중] %s | 남은 적: %d / %d\n", river[fightOrder].name, fightOrder + 1, 3);
					printf("--------------------------------------------------------------\n");

					printf("  [ %-20s ] (Lv.%d)\n", player.name, player.level);
					printf("  HP: %d | %d\n", player.hp, player.totalHp);
					printHpBar(player.hp, player.totalHp);
					printf("  공격력 : %-5d 방어력 : %-5d 스피드 : %-5d 스킬포인트 : %-5d\n",
						player.attack, player.defence, player.speed, player.skillPoint);
					if (player.stun > 0) printf("	상태: [기절됨! (%d)턴]\n", player.stun);
					printf("\n");

					printf("  [ %-20s ] (Lv.%d)\n", river[fightOrder].name, river[fightOrder].level);
					printf("  HP: %d\n", river[fightOrder].hp);
					printHpBar(river[fightOrder].hp, river[fightOrder].totalHp);
					printf("  공격력 : %-5d 방어력 : %-5d 스피드 : %-5d\n",
						river[fightOrder].attack, river[fightOrder].defence, river[fightOrder].speed);
					if (river[fightOrder].stun > 0) printf("  상태: [기절됨! (%d)턴]\n", river[fightOrder].stun);
					if (river[fightOrder].debuff > 0) printf("  상태: [중독됨! (%d)턴]\n", river[fightOrder].debuff);

					printf("==============================================================\n");

					skillMask |= showSkillsList(&player);

					checkPlayerStun(&player);
					checkEnemyStun(&river[fightOrder]);
					if (player.equipment == 2) checkPoison(&river[fightOrder]);

					if (player.speed >= river[fightOrder].speed) {
						if (player.stun <= 0) {
							applySkills(skillMask, &player, &river[fightOrder]);
						}
						else {
							player.stun--;
						}

						if (river[fightOrder].stun <= 0) {
							enemyTurn(&player, &river[fightOrder]);
						}
						else {
							river[fightOrder].stun--;
						}
					}
					else if (river[fightOrder].speed > player.speed) {
						if (river[fightOrder].stun <= 0) {
							enemyTurn(&player, &river[fightOrder]);
						}
						else {
							river[fightOrder].stun--;
						}

						if (player.stun <= 0) {
							applySkills(skillMask, &player, &river[fightOrder]);
						}
						else {
							player.stun--;
						}
					}

					skillMask = 0;

					cls();

					if (river[fightOrder].hp <= 0) {
						printf("%s 을 쓰러트렸습니다.\n", river[fightOrder].name);
						stageTurn++;
						fightOrder++;
						lv++;
						cls();
					}

					if (lv == 2) {
						playerLevelUp(lv);
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
					printf("==============================================================\n");
					printf("	[전투 중] %s | 남은 적: %d / %d\n", hills[fightOrder].name, fightOrder + 1, 4);
					printf("--------------------------------------------------------------\n");

					printf("  [ %-20s ] (Lv.%d)\n", player.name, player.level);
					printf("  HP: %d | %d\n", player.hp, player.totalHp);
					printHpBar(player.hp, player.totalHp);
					printf("  공격력 : %-5d 방어력 : %-5d 스피드 : %-5d 스킬포인트 : %-5d\n",
						player.attack, player.defence, player.speed, player.skillPoint);
					if (player.stun > 0) printf("	상태: [기절됨! (%d)턴]\n", player.stun);
					printf("\n");

					printf("  [ %-20s ] (Lv.%d)\n", hills[fightOrder].name, hills[fightOrder].level);
					printf("  HP: %d\n", hills[fightOrder].hp);
					printHpBar(hills[fightOrder].hp, hills[fightOrder].totalHp);
					printf("  공격력 : %-5d 방어력 : %-5d 스피드 : %-5d\n",
						hills[fightOrder].attack, hills[fightOrder].defence, hills[fightOrder].speed);
					if (hills[fightOrder].stun > 0) printf("  상태: [기절됨! (%d)턴]\n", hills[fightOrder].stun);
					if (hills[fightOrder].debuff > 0) printf("  상태: [중독됨! (%d)턴]\n", hills[fightOrder].debuff);

					printf("==============================================================\n");

					skillMask |= showSkillsList(&player);

					checkPlayerStun(&player);
					checkEnemyStun(&hills[fightOrder]);
					if (player.equipment == 2) checkPoison(&hills[fightOrder]);

					if (player.speed >= hills[fightOrder].speed) {
						if (player.stun <= 0) {
							applySkills(skillMask, &player, &hills[fightOrder]);
						}
						else {
							player.stun--;
						}

						if (hills[fightOrder].stun <= 0) {
							enemyTurn(&player, &hills[fightOrder]);
						}
						else {
							hills[fightOrder].stun--;
						}
					}
					else if (hills[fightOrder].speed > player.speed) {
						if (hills[fightOrder].stun <= 0) {
							enemyTurn(&player, &hills[fightOrder]);
						}
						else {
							hills[fightOrder].stun--;
						}

						if (player.stun <= 0) {
							applySkills(skillMask, &player, &hills[fightOrder]);
						}
						else {
							player.stun--;
						}
					}

					skillMask = 0;

					cls();

					if (hills[fightOrder].hp <= 0) {
						printf("%s 을 쓰러트렸습니다.\n", hills[fightOrder].name);
						stageTurn++;
						fightOrder++;
						lv++;
						cls();
					}

					if (lv == 2) {
						playerLevelUp(lv);
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
			printf("1. 여관(체력 회복/여관 주인)\n2. 대장간(무작위 능력치 상승)\n3. 상점(미구현)\n4. 임무 수행\n");
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
					player.hp = player.totalHp;

					useHotel++;
					cls();
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
				printf("조금 이상한 대장간 사용\n");				
				printf("[무작위 능력치가 상승한다.]\n");
				
				int random = rand() % 4 + 1;
				int random2 = rand() % 10 + 1;

				switch (player.equipment)
				{
				case 1:		// 검
					switch (random)
					{
					case 1:
						printf("[힘 + %d]\n", random2);
						player.attack += random2;
						break;
					case 2:
						printf("[체력 + %d]\n", random2);
						player.hp += random2;
						totalHp = player.hp;
						break;
					case 3:
						printf("[속도 + %d]\n", random2);
						player.speed += random2;
						break;
					case 4:
						printf("[방어 + %d]\n", random2);
						player.defence += random2;
						break;
					}
					break;
				case 2:		// 활
					switch (random)
					{
					case 1:
						printf("[힘 + %d]\n", random2);
						player.attack += random2;
						break;
					case 2:
						printf("[체력 + %d]\n", random2);
						player.hp += random2;
						totalHp = player.hp;
						break;
					case 3:
						printf("[속도 + %d]\n", random2);
						player.speed += random2;
						break;
					case 4:
						printf("[방어 + %d]\n", random2);
						player.defence += random2;
						break;
					}
					break;
				case 3:		// 마법사
					switch (random)
					{
					case 1:
						printf("[힘 + %d]\n", random2);
						player.attack += random2;
						break;
					case 2:
						printf("[체력 + %d]\n", random2);
						player.hp += random2;
						totalHp = player.hp;
						break;
					case 3:
						printf("[속도 + %d]\n", random2);
						player.speed += random2;
						break;
					case 4:
						printf("[방어 + %d]\n", random2);
						player.defence += random2;
						break;
					}
					break;
				}
				printf("현재 %d 번 사용하셨습니다. 총 6번 사용 가능합니다.\n", useSmithy + 1);
				useSmithy++;
				state = 4;
				cls();
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
				cls();
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

