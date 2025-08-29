#pragma once

#include <stdint.h>
typedef uint32_t SkillMask;

typedef struct Player Player;     // ���� ����
typedef struct Monster Monster;   // ���� ����

// ���� ��ų
#define SKILL_ATTACK		(1u << 0)		// �⺻ ����
#define SKILL_HEAL			(1u << 1)		// �ش� ����

// �� ��ų
#define SKILL_SLASH			(1u << 2)		// ���
#define SKILL_CHARGE		(1u << 3)		// ����
#define SKILL_SHIELD_BLOCK	(1u << 4)		// ���� ����
#define SKILL_BERSERK		(1u << 5)		// �г�

// Ȱ ��ų
#define SKILL_ARROW_SHOT	(1u << 6)		// ȭ�� ���
#define SKILL_MULTI_SHOT	(1u << 7)		// ���� ���
#define SKILL_POISON_ARROW	(1u << 8)		// ��ȭ��
#define SKILL_EVASION		(1u << 9)		// ȸ��

// ������ ��ų
#define SKILL_FIREBALL		(1u << 10)		// ȭ����
#define SKILL_ICE_WALL		(1u << 11)		// ������
#define SKILL_LIGHTNING		(1u << 12)		// ����
#define SKILL_TELEPORT		(1u << 13)		// �����̵�

#define JOB_SWORD	(SKILL_ATTACK|SKILL_HEAL|SKILL_SLASH|SKILL_CHARGE|SKILL_SHIELD_BLOCK|SKILL_BERSERK)
#define JOB_BOW		(SKILL_ATTACK|SKILL_HEAL|SKILL_ARROW_SHOT|SKILL_MULTI_SHOT|SKILL_POISON_ARROW|SKILL_EVASION)
#define JOB_STAFF	(SKILL_ATTACK|SKILL_HEAL|SKILL_FIREBALL|SKILL_ICE_WALL|SKILL_LIGHTNING|SKILL_TELEPORT)

void applySkills(SkillMask selected, Player* p, Monster* m[]);