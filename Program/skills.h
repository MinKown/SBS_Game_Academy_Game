#pragma once

#include <stdint.h>
typedef uint32_t SkillMask;

typedef struct Player Player;     // 전방 선언
typedef struct Monster Monster;   // 전방 선언

// 공용 스킬
#define SKILL_ATTACK		(1u << 0)		// 기본 공격
#define SKILL_HEAL			(1u << 1)		// 붕대 감기

// 검 스킬
#define SKILL_SLASH			(1u << 2)		// 배기
#define SKILL_CHARGE		(1u << 3)		// 돌진
#define SKILL_SHIELD_BLOCK	(1u << 4)		// 방패 막기
#define SKILL_BERSERK		(1u << 5)		// 분노

// 활 스킬
#define SKILL_ARROW_SHOT	(1u << 6)		// 화살 쏘기
#define SKILL_MULTI_SHOT	(1u << 7)		// 연속 쏘기
#define SKILL_POISON_ARROW	(1u << 8)		// 독화살
#define SKILL_EVASION		(1u << 9)		// 회피

// 지팡이 스킬
#define SKILL_FIREBALL		(1u << 10)		// 화염구
#define SKILL_ICE_WALL		(1u << 11)		// 얼음벽
#define SKILL_LIGHTNING		(1u << 12)		// 번개
#define SKILL_TELEPORT		(1u << 13)		// 순간이동

#define JOB_SWORD	(SKILL_ATTACK|SKILL_HEAL|SKILL_SLASH|SKILL_CHARGE|SKILL_SHIELD_BLOCK|SKILL_BERSERK)
#define JOB_BOW		(SKILL_ATTACK|SKILL_HEAL|SKILL_ARROW_SHOT|SKILL_MULTI_SHOT|SKILL_POISON_ARROW|SKILL_EVASION)
#define JOB_STAFF	(SKILL_ATTACK|SKILL_HEAL|SKILL_FIREBALL|SKILL_ICE_WALL|SKILL_LIGHTNING|SKILL_TELEPORT)

void applySkills(SkillMask selected, Player* p, Monster* m[]);