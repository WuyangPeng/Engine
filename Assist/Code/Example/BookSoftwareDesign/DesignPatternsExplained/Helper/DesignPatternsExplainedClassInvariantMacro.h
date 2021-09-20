// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨���汾��0.0.3.0 (2020/03/24 23:26)

#ifndef DESIGN_PATTERNS_EXPLAINED_DESIGN_PATTERNS_EXPLAINED_CLASS_INVARIANT_MACRO_H
#define DESIGN_PATTERNS_EXPLAINED_DESIGN_PATTERNS_EXPLAINED_CLASS_INVARIANT_MACRO_H

#include "UserMacro.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"

#if !defined(DESIGN_PATTERNS_EXPLAINED_CLASS_INVARIANT_LEVEL)
	#define DESIGN_PATTERNS_EXPLAINED_CLASS_INVARIANT_LEVEL 8
#endif // DESIGN_PATTERNS_EXPLAINED_CLASS_INVARIANT_LEVEL

#if !defined(DESIGN_PATTERNS_EXPLAINED_CLASS_INVARIANT_CONST_LEVEL)
	#define DESIGN_PATTERNS_EXPLAINED_CLASS_INVARIANT_CONST_LEVEL 8
#endif // DESIGN_PATTERNS_EXPLAINED_CLASS_INVARIANT_CONST_LEVEL

static_assert(DESIGN_PATTERNS_EXPLAINED_CLASS_INVARIANT_LEVEL <= USER_CLASS_INVARIANT_LEVEL, "Class invariant level definition error.");
static_assert(DESIGN_PATTERNS_EXPLAINED_CLASS_INVARIANT_CONST_LEVEL <= USER_CLASS_INVARIANT_CONST_LEVEL, "Class invariant level definition error.");

#if 0 <= DESIGN_PATTERNS_EXPLAINED_CLASS_INVARIANT_LEVEL

	#define DESIGN_PATTERNS_EXPLAINED_CLASS_IS_VALID_0 USER_CLASS_IS_VALID_0
	#define DESIGN_PATTERNS_EXPLAINED_SELF_CLASS_IS_VALID_0 USER_SELF_CLASS_IS_VALID_0

#else // DESIGN_PATTERNS_EXPLAINED_CLASS_INVARIANT_LEVEL < 0

	#define DESIGN_PATTERNS_EXPLAINED_CLASS_IS_VALID_0 ((void)0)
	#define DESIGN_PATTERNS_EXPLAINED_SELF_CLASS_IS_VALID_0 ((void)0)

#endif // 0 <= DESIGN_PATTERNS_EXPLAINED_CLASS_INVARIANT_LEVEL

#if 1 <= DESIGN_PATTERNS_EXPLAINED_CLASS_INVARIANT_LEVEL

	#define DESIGN_PATTERNS_EXPLAINED_CLASS_IS_VALID_1 USER_CLASS_IS_VALID_1
	#define DESIGN_PATTERNS_EXPLAINED_SELF_CLASS_IS_VALID_1 USER_SELF_CLASS_IS_VALID_1

#else // DESIGN_PATTERNS_EXPLAINED_CLASS_INVARIANT_LEVEL < 1

	#define DESIGN_PATTERNS_EXPLAINED_CLASS_IS_VALID_1 ((void)0)
	#define DESIGN_PATTERNS_EXPLAINED_SELF_CLASS_IS_VALID_1 ((void)0)

#endif // 1 <= CLASS_INVARIANT_LEVEL

#if 2 <= DESIGN_PATTERNS_EXPLAINED_CLASS_INVARIANT_LEVEL

	#define DESIGN_PATTERNS_EXPLAINED_CLASS_IS_VALID_2 USER_CLASS_IS_VALID_2
	#define DESIGN_PATTERNS_EXPLAINED_SELF_CLASS_IS_VALID_2 USER_SELF_CLASS_IS_VALID_2

#else // DESIGN_PATTERNS_EXPLAINED_CLASS_INVARIANT_LEVEL < 2

	#define DESIGN_PATTERNS_EXPLAINED_CLASS_IS_VALID_2 ((void)0)
	#define DESIGN_PATTERNS_EXPLAINED_SELF_CLASS_IS_VALID_2 ((void)0)

#endif // 2 <= DESIGN_PATTERNS_EXPLAINED_CLASS_INVARIANT_LEVEL

#if 3 <= DESIGN_PATTERNS_EXPLAINED_CLASS_INVARIANT_LEVEL

	#define DESIGN_PATTERNS_EXPLAINED_CLASS_IS_VALID_3 USER_CLASS_IS_VALID_3
	#define DESIGN_PATTERNS_EXPLAINED_SELF_CLASS_IS_VALID_3 USER_SELF_CLASS_IS_VALID_3

#else // DESIGN_PATTERNS_EXPLAINED_CLASS_INVARIANT_LEVEL < 3

	#define DESIGN_PATTERNS_EXPLAINED_CLASS_IS_VALID_3 ((void)0)
	#define DESIGN_PATTERNS_EXPLAINED_SELF_CLASS_IS_VALID_3 ((void)0)

#endif // 3 <= DESIGN_PATTERNS_EXPLAINED_CLASS_INVARIANT_LEVEL

#if 4 <= DESIGN_PATTERNS_EXPLAINED_CLASS_INVARIANT_LEVEL

	#define DESIGN_PATTERNS_EXPLAINED_CLASS_IS_VALID_4 USER_CLASS_IS_VALID_4
	#define DESIGN_PATTERNS_EXPLAINED_SELF_CLASS_IS_VALID_4 USER_SELF_CLASS_IS_VALID_4

#else // DESIGN_PATTERNS_EXPLAINED_CLASS_INVARIANT_LEVEL < 4

	#define DESIGN_PATTERNS_EXPLAINED_CLASS_IS_VALID_4 ((void)0)
	#define DESIGN_PATTERNS_EXPLAINED_SELF_CLASS_IS_VALID_4 ((void)0)

#endif // 4 <= DESIGN_PATTERNS_EXPLAINED_CLASS_INVARIANT_LEVEL

#if 5 <= DESIGN_PATTERNS_EXPLAINED_CLASS_INVARIANT_LEVEL

	#define DESIGN_PATTERNS_EXPLAINED_CLASS_IS_VALID_5 USER_CLASS_IS_VALID_5
	#define DESIGN_PATTERNS_EXPLAINED_SELF_CLASS_IS_VALID_5 USER_SELF_CLASS_IS_VALID_5

#else // DESIGN_PATTERNS_EXPLAINED_CLASS_INVARIANT_LEVEL < 5

	#define DESIGN_PATTERNS_EXPLAINED_CLASS_IS_VALID_5 ((void)0)
	#define DESIGN_PATTERNS_EXPLAINED_SELF_CLASS_IS_VALID_5 ((void)0)

#endif // 5 <= DESIGN_PATTERNS_EXPLAINED_CLASS_INVARIANT_LEVEL

#if 6 <= DESIGN_PATTERNS_EXPLAINED_CLASS_INVARIANT_LEVEL

	#define DESIGN_PATTERNS_EXPLAINED_CLASS_IS_VALID_6 USER_CLASS_IS_VALID_6
	#define DESIGN_PATTERNS_EXPLAINED_SELF_CLASS_IS_VALID_6 USER_SELF_CLASS_IS_VALID_6

#else // CLASS_INVARIANT_LEVEL < 6

	#define DESIGN_PATTERNS_EXPLAINED_CLASS_IS_VALID_6 ((void)0)
	#define DESIGN_PATTERNS_EXPLAINED_SELF_CLASS_IS_VALID_6 ((void)0)

#endif // 6 <= DESIGN_PATTERNS_EXPLAINED_CLASS_INVARIANT_LEVEL

#if 7 <= DESIGN_PATTERNS_EXPLAINED_CLASS_INVARIANT_LEVEL

	#define DESIGN_PATTERNS_EXPLAINED_CLASS_IS_VALID_7 USER_CLASS_IS_VALID_7
	#define DESIGN_PATTERNS_EXPLAINED_SELF_CLASS_IS_VALID_7 USER_SELF_CLASS_IS_VALID_7

#else // DESIGN_PATTERNS_EXPLAINED_CLASS_INVARIANT_LEVEL < 7

	#define DESIGN_PATTERNS_EXPLAINED_CLASS_IS_VALID_7 ((void)0)
	#define DESIGN_PATTERNS_EXPLAINED_SELF_CLASS_IS_VALID_7 ((void)0)

#endif // 7 <= DESIGN_PATTERNS_EXPLAINED_CLASS_INVARIANT_LEVEL

#if 8 <= DESIGN_PATTERNS_EXPLAINED_CLASS_INVARIANT_LEVEL

	#define DESIGN_PATTERNS_EXPLAINED_CLASS_IS_VALID_8 USER_CLASS_IS_VALID_8
	#define DESIGN_PATTERNS_EXPLAINED_SELF_CLASS_IS_VALID_8 USER_SELF_CLASS_IS_VALID_8

#else // DESIGN_PATTERNS_EXPLAINED_CLASS_INVARIANT_LEVEL < 8

	#define DESIGN_PATTERNS_EXPLAINED_CLASS_IS_VALID_8 ((void)0)
	#define DESIGN_PATTERNS_EXPLAINED_SELF_CLASS_IS_VALID_8 ((void)0)

#endif // 8 <= DESIGN_PATTERNS_EXPLAINED_CLASS_INVARIANT_LEVEL

#if 9 <= DESIGN_PATTERNS_EXPLAINED_CLASS_INVARIANT_LEVEL

	#define DESIGN_PATTERNS_EXPLAINED_CLASS_IS_VALID_9 USER_CLASS_IS_VALID_9
	#define DESIGN_PATTERNS_EXPLAINED_SELF_CLASS_IS_VALID_9 USER_SELF_CLASS_IS_VALID_9

#else // DESIGN_PATTERNS_EXPLAINED_CLASS_INVARIANT_LEVEL < 9

	#define DESIGN_PATTERNS_EXPLAINED_CLASS_IS_VALID_9 ((void)0)
	#define DESIGN_PATTERNS_EXPLAINED_SELF_CLASS_IS_VALID_9 ((void)0)

#endif // 9 <= DESIGN_PATTERNS_EXPLAINED_CLASS_INVARIANT_LEVEL

#if 0 <= DESIGN_PATTERNS_EXPLAINED_CLASS_INVARIANT_CONST_LEVEL
	#define DESIGN_PATTERNS_EXPLAINED_CLASS_IS_VALID_CONST_0 USER_CLASS_IS_VALID_CONST_0
#else // DESIGN_PATTERNS_EXPLAINED_CLASS_INVARIANT_CONST_LEVEL < 0
	#define DESIGN_PATTERNS_EXPLAINED_CLASS_IS_VALID_CONST_0 ((void)0)
#endif // 0 <= DESIGN_PATTERNS_EXPLAINED_CLASS_INVARIANT_CONST_LEVEL

#if 1 <= DESIGN_PATTERNS_EXPLAINED_CLASS_INVARIANT_CONST_LEVEL
	#define DESIGN_PATTERNS_EXPLAINED_CLASS_IS_VALID_CONST_1 USER_CLASS_IS_VALID_CONST_1
#else // DESIGN_PATTERNS_EXPLAINED_CLASS_INVARIANT_CONST_LEVEL < 1
	#define DESIGN_PATTERNS_EXPLAINED_CLASS_IS_VALID_CONST_1 ((void)0)
#endif // 1 <= DESIGN_PATTERNS_EXPLAINED_CLASS_INVARIANT_CONST_LEVEL

#if 2 <= DESIGN_PATTERNS_EXPLAINED_CLASS_INVARIANT_CONST_LEVEL
	#define DESIGN_PATTERNS_EXPLAINED_CLASS_IS_VALID_CONST_2 USER_CLASS_IS_VALID_CONST_2
#else // DESIGN_PATTERNS_EXPLAINED_CLASS_INVARIANT_CONST_LEVEL < 2
	#define DESIGN_PATTERNS_EXPLAINED_CLASS_IS_VALID_CONST_2 ((void)0)
#endif // 2 <= DESIGN_PATTERNS_EXPLAINED_CLASS_INVARIANT_CONST_LEVEL

#if 3 <= DESIGN_PATTERNS_EXPLAINED_CLASS_INVARIANT_CONST_LEVEL
	#define DESIGN_PATTERNS_EXPLAINED_CLASS_IS_VALID_CONST_3 USER_CLASS_IS_VALID_CONST_3
#else // DESIGN_PATTERNS_EXPLAINED_CLASS_INVARIANT_CONST_LEVEL < 3
	#define DESIGN_PATTERNS_EXPLAINED_CLASS_IS_VALID_CONST_3 ((void)0)
#endif // 3 <= DESIGN_PATTERNS_EXPLAINED_CLASS_INVARIANT_CONST_LEVEL

#if 4 <= DESIGN_PATTERNS_EXPLAINED_CLASS_INVARIANT_CONST_LEVEL
	#define DESIGN_PATTERNS_EXPLAINED_CLASS_IS_VALID_CONST_4 USER_CLASS_IS_VALID_CONST_4
#else // DESIGN_PATTERNS_EXPLAINED_CLASS_INVARIANT_CONST_LEVEL < 4
	#define DESIGN_PATTERNS_EXPLAINED_CLASS_IS_VALID_CONST_4 ((void)0)
#endif // 4 <= DESIGN_PATTERNS_EXPLAINED_CLASS_INVARIANT_CONST_LEVEL

#if 5 <= DESIGN_PATTERNS_EXPLAINED_CLASS_INVARIANT_CONST_LEVEL
	#define DESIGN_PATTERNS_EXPLAINED_CLASS_IS_VALID_CONST_5 USER_CLASS_IS_VALID_CONST_5
#else // DESIGN_PATTERNS_EXPLAINED_CLASS_INVARIANT_CONST_LEVEL < 5
	#define DESIGN_PATTERNS_EXPLAINED_CLASS_IS_VALID_CONST_5 ((void)0)
#endif // 5 <= DESIGN_PATTERNS_EXPLAINED_CLASS_INVARIANT_CONST_LEVEL

#if 6 <= DESIGN_PATTERNS_EXPLAINED_CLASS_INVARIANT_CONST_LEVEL
	#define DESIGN_PATTERNS_EXPLAINED_CLASS_IS_VALID_CONST_6 USER_CLASS_IS_VALID_CONST_6
#else // DESIGN_PATTERNS_EXPLAINED_CLASS_INVARIANT_CONST_LEVEL < 6
	#define DESIGN_PATTERNS_EXPLAINED_CLASS_IS_VALID_CONST_6 ((void)0)
#endif // 6 <= DESIGN_PATTERNS_EXPLAINED_CLASS_INVARIANT_CONST_LEVEL

#if 7 <= DESIGN_PATTERNS_EXPLAINED_CLASS_INVARIANT_CONST_LEVEL
	#define DESIGN_PATTERNS_EXPLAINED_CLASS_IS_VALID_CONST_7 USER_CLASS_IS_VALID_CONST_7
#else // DESIGN_PATTERNS_EXPLAINED_CLASS_INVARIANT_CONST_LEVEL < 7
	#define DESIGN_PATTERNS_EXPLAINED_CLASS_IS_VALID_CONST_7 ((void)0)
#endif // 7 <= DESIGN_PATTERNS_EXPLAINED_CLASS_INVARIANT_CONST_LEVEL

#if 8 <= DESIGN_PATTERNS_EXPLAINED_CLASS_INVARIANT_CONST_LEVEL
	#define DESIGN_PATTERNS_EXPLAINED_CLASS_IS_VALID_CONST_8 USER_CLASS_IS_VALID_CONST_8
#else // DESIGN_PATTERNS_EXPLAINED_CLASS_INVARIANT_CONST_LEVEL < 8
	#define DESIGN_PATTERNS_EXPLAINED_CLASS_IS_VALID_CONST_8 ((void)0)
#endif // 8 <= DESIGN_PATTERNS_EXPLAINED_CLASS_INVARIANT_CONST_LEVEL

#if 9 <= DESIGN_PATTERNS_EXPLAINED_CLASS_INVARIANT_CONST_LEVEL
	#define DESIGN_PATTERNS_EXPLAINED_CLASS_IS_VALID_CONST_9 USER_CLASS_IS_VALID_CONST_9
#else // DESIGN_PATTERNS_EXPLAINED_CLASS_INVARIANT_CONST_LEVEL < 9
	#define DESIGN_PATTERNS_EXPLAINED_CLASS_IS_VALID_CONST_9 ((void)0)
#endif // 9 <= DESIGN_PATTERNS_EXPLAINED_CLASS_INVARIANT_CONST_LEVEL

#endif // DESIGN_PATTERNS_EXPLAINED_DESIGN_PATTERNS_EXPLAINED_CLASS_INVARIANT_MACRO_H