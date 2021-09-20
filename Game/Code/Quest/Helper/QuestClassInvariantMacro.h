// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������Ϸ�汾��0.0.0.1 (2019/10/05 22:01)

#ifndef QUEST_MACRO_CLASS_INVARIANT_MACRO_H
#define QUEST_MACRO_CLASS_INVARIANT_MACRO_H

#include "UserMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#if !defined(QUEST_CLASS_INVARIANT_LEVEL)
	#define QUEST_CLASS_INVARIANT_LEVEL 8
#endif // QUEST_CLASS_INVARIANT_LEVEL

#if !defined(QUEST_CLASS_INVARIANT_CONST_LEVEL)
	#define QUEST_CLASS_INVARIANT_CONST_LEVEL 8
#endif // QUEST_CLASS_INVARIANT_CONST_LEVEL

static_assert(QUEST_CLASS_INVARIANT_LEVEL <= CLASS_INVARIANT_LEVEL, "Class invariant level definition error.");
static_assert(QUEST_CLASS_INVARIANT_CONST_LEVEL <= CLASS_INVARIANT_CONST_LEVEL, "Class invariant level definition error.");

#if 0 <= QUEST_CLASS_INVARIANT_LEVEL

	#define QUEST_CLASS_IS_VALID_0 CLASS_IS_VALID_0
	#define QUEST_SELF_CLASS_IS_VALID_0 SELF_CLASS_IS_VALID_0

#else // QUEST_CLASS_INVARIANT_LEVEL < 0

	#define QUEST_CLASS_IS_VALID_0 ((void)0)
	#define QUEST_SELF_CLASS_IS_VALID_0 ((void)0)

#endif // 0 <= QUEST_CLASS_INVARIANT_LEVEL

#if 1 <= QUEST_CLASS_INVARIANT_LEVEL

	#define QUEST_CLASS_IS_VALID_1 CLASS_IS_VALID_1
	#define QUEST_SELF_CLASS_IS_VALID_1 SELF_CLASS_IS_VALID_1

#else // QUEST_CLASS_INVARIANT_LEVEL < 1

	#define QUEST_CLASS_IS_VALID_1 ((void)0)
	#define QUEST_SELF_CLASS_IS_VALID_1 ((void)0)

#endif // 1 <= CLASS_INVARIANT_LEVEL

#if 2 <= QUEST_CLASS_INVARIANT_LEVEL

	#define QUEST_CLASS_IS_VALID_2 CLASS_IS_VALID_2
	#define QUEST_SELF_CLASS_IS_VALID_2 SELF_CLASS_IS_VALID_2

#else // QUEST_CLASS_INVARIANT_LEVEL < 2

	#define QUEST_CLASS_IS_VALID_2 ((void)0)
	#define QUEST_SELF_CLASS_IS_VALID_2 ((void)0)

#endif // 2 <= QUEST_CLASS_INVARIANT_LEVEL

#if 3 <= QUEST_CLASS_INVARIANT_LEVEL

	#define QUEST_CLASS_IS_VALID_3 CLASS_IS_VALID_3
	#define QUEST_SELF_CLASS_IS_VALID_3 SELF_CLASS_IS_VALID_3

#else // QUEST_CLASS_INVARIANT_LEVEL < 3

	#define QUEST_CLASS_IS_VALID_3 ((void)0)
	#define QUEST_SELF_CLASS_IS_VALID_3 ((void)0)

#endif // 3 <= QUEST_CLASS_INVARIANT_LEVEL

#if 4 <= QUEST_CLASS_INVARIANT_LEVEL

	#define QUEST_CLASS_IS_VALID_4 CLASS_IS_VALID_4
	#define QUEST_SELF_CLASS_IS_VALID_4 SELF_CLASS_IS_VALID_4

#else // QUEST_CLASS_INVARIANT_LEVEL < 4

	#define QUEST_CLASS_IS_VALID_4 ((void)0)
	#define QUEST_SELF_CLASS_IS_VALID_4 ((void)0)

#endif // 4 <= QUEST_CLASS_INVARIANT_LEVEL

#if 5 <= QUEST_CLASS_INVARIANT_LEVEL

	#define QUEST_CLASS_IS_VALID_5 CLASS_IS_VALID_5
	#define QUEST_SELF_CLASS_IS_VALID_5 SELF_CLASS_IS_VALID_5

#else // QUEST_CLASS_INVARIANT_LEVEL < 5

	#define QUEST_CLASS_IS_VALID_5 ((void)0)
	#define QUEST_SELF_CLASS_IS_VALID_5 ((void)0)

#endif // 5 <= QUEST_CLASS_INVARIANT_LEVEL

#if 6 <= QUEST_CLASS_INVARIANT_LEVEL

	#define QUEST_CLASS_IS_VALID_6 CLASS_IS_VALID_6
	#define QUEST_SELF_CLASS_IS_VALID_6 SELF_CLASS_IS_VALID_6

#else // CLASS_INVARIANT_LEVEL < 6

	#define QUEST_CLASS_IS_VALID_6 ((void)0)
	#define QUEST_SELF_CLASS_IS_VALID_6 ((void)0)

#endif // 6 <= QUEST_CLASS_INVARIANT_LEVEL

#if 7 <= QUEST_CLASS_INVARIANT_LEVEL

	#define QUEST_CLASS_IS_VALID_7 CLASS_IS_VALID_7
	#define QUEST_SELF_CLASS_IS_VALID_7 SELF_CLASS_IS_VALID_7

#else // QUEST_CLASS_INVARIANT_LEVEL < 7

	#define QUEST_CLASS_IS_VALID_7 ((void)0)
	#define QUEST_SELF_CLASS_IS_VALID_7 ((void)0)

#endif // 7 <= QUEST_CLASS_INVARIANT_LEVEL

#if 8 <= QUEST_CLASS_INVARIANT_LEVEL

	#define QUEST_CLASS_IS_VALID_8 CLASS_IS_VALID_8
	#define QUEST_SELF_CLASS_IS_VALID_8 SELF_CLASS_IS_VALID_8

#else // QUEST_CLASS_INVARIANT_LEVEL < 8

	#define QUEST_CLASS_IS_VALID_8 ((void)0)
	#define QUEST_SELF_CLASS_IS_VALID_8 ((void)0)

#endif // 8 <= QUEST_CLASS_INVARIANT_LEVEL

#if 9 <= QUEST_CLASS_INVARIANT_LEVEL

	#define QUEST_CLASS_IS_VALID_9 CLASS_IS_VALID_9
	#define QUEST_SELF_CLASS_IS_VALID_9 SELF_CLASS_IS_VALID_9

#else // QUEST_CLASS_INVARIANT_LEVEL < 9

	#define QUEST_CLASS_IS_VALID_9 ((void)0)
	#define QUEST_SELF_CLASS_IS_VALID_9 ((void)0)

#endif // 9 <= QUEST_CLASS_INVARIANT_LEVEL

#if 0 <= QUEST_CLASS_INVARIANT_CONST_LEVEL
	#define QUEST_CLASS_IS_VALID_CONST_0 CLASS_IS_VALID_CONST_0
#else // QUEST_CLASS_INVARIANT_CONST_LEVEL < 0
	#define QUEST_CLASS_IS_VALID_CONST_0 ((void)0)
#endif // 0 <= QUEST_CLASS_INVARIANT_CONST_LEVEL

#if 1 <= QUEST_CLASS_INVARIANT_CONST_LEVEL
	#define QUEST_CLASS_IS_VALID_CONST_1 CLASS_IS_VALID_CONST_1
#else // QUEST_CLASS_INVARIANT_CONST_LEVEL < 1
	#define QUEST_CLASS_IS_VALID_CONST_1 ((void)0)
#endif // 1 <= QUEST_CLASS_INVARIANT_CONST_LEVEL

#if 2 <= QUEST_CLASS_INVARIANT_CONST_LEVEL
	#define QUEST_CLASS_IS_VALID_CONST_2 CLASS_IS_VALID_CONST_2
#else // QUEST_CLASS_INVARIANT_CONST_LEVEL < 2
	#define QUEST_CLASS_IS_VALID_CONST_2 ((void)0)
#endif // 2 <= QUEST_CLASS_INVARIANT_CONST_LEVEL

#if 3 <= QUEST_CLASS_INVARIANT_CONST_LEVEL
	#define QUEST_CLASS_IS_VALID_CONST_3 CLASS_IS_VALID_CONST_3
#else // QUEST_CLASS_INVARIANT_CONST_LEVEL < 3
	#define QUEST_CLASS_IS_VALID_CONST_3 ((void)0)
#endif // 3 <= QUEST_CLASS_INVARIANT_CONST_LEVEL

#if 4 <= QUEST_CLASS_INVARIANT_CONST_LEVEL
	#define QUEST_CLASS_IS_VALID_CONST_4 CLASS_IS_VALID_CONST_4
#else // QUEST_CLASS_INVARIANT_CONST_LEVEL < 4
	#define QUEST_CLASS_IS_VALID_CONST_4 ((void)0)
#endif // 4 <= QUEST_CLASS_INVARIANT_CONST_LEVEL

#if 5 <= QUEST_CLASS_INVARIANT_CONST_LEVEL
	#define QUEST_CLASS_IS_VALID_CONST_5 CLASS_IS_VALID_CONST_5
#else // QUEST_CLASS_INVARIANT_CONST_LEVEL < 5
	#define QUEST_CLASS_IS_VALID_CONST_5 ((void)0)
#endif // 5 <= QUEST_CLASS_INVARIANT_CONST_LEVEL

#if 6 <= QUEST_CLASS_INVARIANT_CONST_LEVEL
	#define QUEST_CLASS_IS_VALID_CONST_6 CLASS_IS_VALID_CONST_6
#else // QUEST_CLASS_INVARIANT_CONST_LEVEL < 6
	#define QUEST_CLASS_IS_VALID_CONST_6 ((void)0)
#endif // 6 <= QUEST_CLASS_INVARIANT_CONST_LEVEL

#if 7 <= QUEST_CLASS_INVARIANT_CONST_LEVEL
	#define QUEST_CLASS_IS_VALID_CONST_7 CLASS_IS_VALID_CONST_7
#else // QUEST_CLASS_INVARIANT_CONST_LEVEL < 7
	#define QUEST_CLASS_IS_VALID_CONST_7 ((void)0)
#endif // 7 <= QUEST_CLASS_INVARIANT_CONST_LEVEL

#if 8 <= QUEST_CLASS_INVARIANT_CONST_LEVEL
	#define QUEST_CLASS_IS_VALID_CONST_8 CLASS_IS_VALID_CONST_8
#else // QUEST_CLASS_INVARIANT_CONST_LEVEL < 8
	#define QUEST_CLASS_IS_VALID_CONST_8 ((void)0)
#endif // 8 <= QUEST_CLASS_INVARIANT_CONST_LEVEL

#if 9 <= QUEST_CLASS_INVARIANT_CONST_LEVEL
	#define QUEST_CLASS_IS_VALID_CONST_9 CLASS_IS_VALID_CONST_9
#else // QUEST_CLASS_INVARIANT_CONST_LEVEL < 9
	#define QUEST_CLASS_IS_VALID_CONST_9 ((void)0)
#endif // 9 <= QUEST_CLASS_INVARIANT_CONST_LEVEL

#endif // QUEST_MACRO_CLASS_INVARIANT_MACRO_H
