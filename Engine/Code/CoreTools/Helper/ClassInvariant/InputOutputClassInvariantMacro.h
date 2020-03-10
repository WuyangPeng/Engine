// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/18 10:06)

#ifndef CORE_TOOLS_HELPER_INPUT_OUTPUT_CLASS_INVARIANT_MACRO_H
#define CORE_TOOLS_HELPER_INPUT_OUTPUT_CLASS_INVARIANT_MACRO_H

#include "CoreTools/Helper/ClassInvariantMacro.h"

#if !defined(INPUT_OUTPUT_CLASS_INVARIANT_LEVEL)
	#define INPUT_OUTPUT_CLASS_INVARIANT_LEVEL 8
#endif // INPUT_OUTPUT_CLASS_INVARIANT_LEVEL

#if !defined(INPUT_OUTPUT_CLASS_INVARIANT_CONST_LEVEL)
	#define INPUT_OUTPUT_CLASS_INVARIANT_CONST_LEVEL 0
#endif // INPUT_OUTPUT_CLASS_INVARIANT_CONST_LEVEL

static_assert(INPUT_OUTPUT_CLASS_INVARIANT_LEVEL <= CLASS_INVARIANT_LEVEL, "Input Output class invariant level definition error.");
static_assert(INPUT_OUTPUT_CLASS_INVARIANT_CONST_LEVEL <= CLASS_INVARIANT_CONST_LEVEL, "Input Output class invariant level definition error.");

#if 0 <= INPUT_OUTPUT_CLASS_INVARIANT_LEVEL

	#define INPUT_OUTPUT_CLASS_IS_VALID_0 CLASS_IS_VALID_0
	#define INPUT_OUTPUT_SELF_CLASS_IS_VALID_0 SELF_CLASS_IS_VALID_0

#else // INPUT_OUTPUT_CLASS_INVARIANT_LEVEL < 0

	#define INPUT_OUTPUT_CLASS_IS_VALID_0 ((void)0)
	#define INPUT_OUTPUT_SELF_CLASS_IS_VALID_0 ((void)0)

#endif //0 <= INPUT_OUTPUT_CLASS_INVARIANT_LEVEL

#if 1 <= INPUT_OUTPUT_CLASS_INVARIANT_LEVEL

	#define INPUT_OUTPUT_CLASS_IS_VALID_1 CLASS_IS_VALID_1
	#define INPUT_OUTPUT_SELF_CLASS_IS_VALID_1 SELF_CLASS_IS_VALID_1

#else // INPUT_OUTPUT_CLASS_INVARIANT_LEVEL < 1

	#define INPUT_OUTPUT_CLASS_IS_VALID_1 ((void)0)
	#define INPUT_OUTPUT_SELF_CLASS_IS_VALID_1 ((void)0)

#endif // 1 <= CLASS_INVARIANT_LEVEL

#if 2 <= INPUT_OUTPUT_CLASS_INVARIANT_LEVEL

	#define INPUT_OUTPUT_CLASS_IS_VALID_2 CLASS_IS_VALID_2
	#define INPUT_OUTPUT_SELF_CLASS_IS_VALID_2 SELF_CLASS_IS_VALID_2

#else // INPUT_OUTPUT_CLASS_INVARIANT_LEVEL < 2

	#define INPUT_OUTPUT_CLASS_IS_VALID_2 ((void)0)
	#define INPUT_OUTPUT_SELF_CLASS_IS_VALID_2 ((void)0)

#endif // 2 <= INPUT_OUTPUT_CLASS_INVARIANT_LEVEL

#if 3 <= INPUT_OUTPUT_CLASS_INVARIANT_LEVEL

	#define INPUT_OUTPUT_CLASS_IS_VALID_3 CLASS_IS_VALID_3
	#define INPUT_OUTPUT_SELF_CLASS_IS_VALID_3 SELF_CLASS_IS_VALID_3

#else // INPUT_OUTPUT_CLASS_INVARIANT_LEVEL < 3

	#define INPUT_OUTPUT_CLASS_IS_VALID_3 ((void)0)
	#define INPUT_OUTPUT_SELF_CLASS_IS_VALID_3 ((void)0)

#endif // 3 <= INPUT_OUTPUT_CLASS_INVARIANT_LEVEL

#if 4 <= INPUT_OUTPUT_CLASS_INVARIANT_LEVEL

	#define INPUT_OUTPUT_CLASS_IS_VALID_4 CLASS_IS_VALID_4
	#define INPUT_OUTPUT_SELF_CLASS_IS_VALID_4 SELF_CLASS_IS_VALID_4

#else // INPUT_OUTPUT_CLASS_INVARIANT_LEVEL < 4

	#define INPUT_OUTPUT_CLASS_IS_VALID_4 ((void)0)
	#define INPUT_OUTPUT_SELF_CLASS_IS_VALID_4 ((void)0)

#endif // 4 <= INPUT_OUTPUT_CLASS_INVARIANT_LEVEL

#if 5 <= INPUT_OUTPUT_CLASS_INVARIANT_LEVEL

	#define INPUT_OUTPUT_CLASS_IS_VALID_5 CLASS_IS_VALID_5
	#define INPUT_OUTPUT_SELF_CLASS_IS_VALID_5 SELF_CLASS_IS_VALID_5

#else // INPUT_OUTPUT_CLASS_INVARIANT_LEVEL < 5

	#define INPUT_OUTPUT_CLASS_IS_VALID_5 ((void)0)
	#define INPUT_OUTPUT_SELF_CLASS_IS_VALID_5 ((void)0)

#endif // 5 <= INPUT_OUTPUT_CLASS_INVARIANT_LEVEL

#if 6 <= INPUT_OUTPUT_CLASS_INVARIANT_LEVEL

	#define INPUT_OUTPUT_CLASS_IS_VALID_6 CLASS_IS_VALID_6
	#define INPUT_OUTPUT_SELF_CLASS_IS_VALID_6 SELF_CLASS_IS_VALID_6

#else // CLASS_INVARIANT_LEVEL < 6

	#define INPUT_OUTPUT_CLASS_IS_VALID_6 ((void)0)
	#define INPUT_OUTPUT_SELF_CLASS_IS_VALID_6 ((void)0)

#endif // 6 <= INPUT_OUTPUT_CLASS_INVARIANT_LEVEL

#if 7 <= INPUT_OUTPUT_CLASS_INVARIANT_LEVEL

	#define INPUT_OUTPUT_CLASS_IS_VALID_7 CLASS_IS_VALID_7
	#define INPUT_OUTPUT_SELF_CLASS_IS_VALID_7 SELF_CLASS_IS_VALID_7

#else // INPUT_OUTPUT_CLASS_INVARIANT_LEVEL < 7

	#define INPUT_OUTPUT_CLASS_IS_VALID_7 ((void)0)
	#define INPUT_OUTPUT_SELF_CLASS_IS_VALID_7 ((void)0)

#endif // 7 <= INPUT_OUTPUT_CLASS_INVARIANT_LEVEL

#if 8 <= INPUT_OUTPUT_CLASS_INVARIANT_LEVEL

	#define INPUT_OUTPUT_CLASS_IS_VALID_8 CLASS_IS_VALID_8
	#define INPUT_OUTPUT_SELF_CLASS_IS_VALID_8 SELF_CLASS_IS_VALID_8

#else // INPUT_OUTPUT_CLASS_INVARIANT_LEVEL < 8

	#define INPUT_OUTPUT_CLASS_IS_VALID_8 ((void)0)
	#define INPUT_OUTPUT_SELF_CLASS_IS_VALID_8 ((void)0)

#endif // 8 <= INPUT_OUTPUT_CLASS_INVARIANT_LEVEL

#if 9 <= INPUT_OUTPUT_CLASS_INVARIANT_LEVEL

	#define INPUT_OUTPUT_CLASS_IS_VALID_9 CLASS_IS_VALID_9
	#define INPUT_OUTPUT_SELF_CLASS_IS_VALID_9 SELF_CLASS_IS_VALID_9

#else // INPUT_OUTPUT_CLASS_INVARIANT_LEVEL < 9

	#define INPUT_OUTPUT_CLASS_IS_VALID_9 ((void)0)
	#define INPUT_OUTPUT_SELF_CLASS_IS_VALID_9 ((void)0)

#endif // 9 <= INPUT_OUTPUT_CLASS_INVARIANT_LEVEL

#if 0 <= INPUT_OUTPUT_CLASS_INVARIANT_CONST_LEVEL
	#define INPUT_OUTPUT_CLASS_IS_VALID_CONST_0 CLASS_IS_VALID_CONST_0
#else // INPUT_OUTPUT_CLASS_INVARIANT_CONST_LEVEL < 0
	#define INPUT_OUTPUT_CLASS_IS_VALID_CONST_0 ((void)0)
#endif // 0 <= INPUT_OUTPUT_CLASS_INVARIANT_CONST_LEVEL

#if 1 <= INPUT_OUTPUT_CLASS_INVARIANT_CONST_LEVEL
	#define INPUT_OUTPUT_CLASS_IS_VALID_CONST_1 CLASS_IS_VALID_CONST_1
#else // INPUT_OUTPUT_CLASS_INVARIANT_CONST_LEVEL < 1
	#define INPUT_OUTPUT_CLASS_IS_VALID_CONST_1 ((void)0)
#endif // 1 <= INPUT_OUTPUT_CLASS_INVARIANT_CONST_LEVEL

#if 2 <= INPUT_OUTPUT_CLASS_INVARIANT_CONST_LEVEL
	#define INPUT_OUTPUT_CLASS_IS_VALID_CONST_2 CLASS_IS_VALID_CONST_2
#else // INPUT_OUTPUT_CLASS_INVARIANT_CONST_LEVEL < 2
	#define INPUT_OUTPUT_CLASS_IS_VALID_CONST_2 ((void)0)
#endif // 2 <= INPUT_OUTPUT_CLASS_INVARIANT_CONST_LEVEL

#if 3 <= INPUT_OUTPUT_CLASS_INVARIANT_CONST_LEVEL
	#define INPUT_OUTPUT_CLASS_IS_VALID_CONST_3 CLASS_IS_VALID_CONST_3
#else // INPUT_OUTPUT_CLASS_INVARIANT_CONST_LEVEL < 3
	#define INPUT_OUTPUT_CLASS_IS_VALID_CONST_3 ((void)0)
#endif // 3 <= INPUT_OUTPUT_CLASS_INVARIANT_CONST_LEVEL

#if 4 <= INPUT_OUTPUT_CLASS_INVARIANT_CONST_LEVEL
	#define INPUT_OUTPUT_CLASS_IS_VALID_CONST_4 CLASS_IS_VALID_CONST_4
#else // INPUT_OUTPUT_CLASS_INVARIANT_CONST_LEVEL < 4
	#define INPUT_OUTPUT_CLASS_IS_VALID_CONST_4 ((void)0)
#endif // 4 <= INPUT_OUTPUT_CLASS_INVARIANT_CONST_LEVEL

#if 5 <= INPUT_OUTPUT_CLASS_INVARIANT_CONST_LEVEL
	#define INPUT_OUTPUT_CLASS_IS_VALID_CONST_5 CLASS_IS_VALID_CONST_5
#else // INPUT_OUTPUT_CLASS_INVARIANT_CONST_LEVEL < 5
	#define INPUT_OUTPUT_CLASS_IS_VALID_CONST_5 ((void)0)
#endif // 5 <= INPUT_OUTPUT_CLASS_INVARIANT_CONST_LEVEL

#if 6 <= INPUT_OUTPUT_CLASS_INVARIANT_CONST_LEVEL
	#define INPUT_OUTPUT_CLASS_IS_VALID_CONST_6 CLASS_IS_VALID_CONST_6
#else // INPUT_OUTPUT_CLASS_INVARIANT_CONST_LEVEL < 6
	#define INPUT_OUTPUT_CLASS_IS_VALID_CONST_6 ((void)0)
#endif // 6 <= INPUT_OUTPUT_CLASS_INVARIANT_CONST_LEVEL

#if 7 <= INPUT_OUTPUT_CLASS_INVARIANT_CONST_LEVEL
	#define INPUT_OUTPUT_CLASS_IS_VALID_CONST_7 CLASS_IS_VALID_CONST_7
#else // INPUT_OUTPUT_CLASS_INVARIANT_CONST_LEVEL < 7
	#define INPUT_OUTPUT_CLASS_IS_VALID_CONST_7 ((void)0)
#endif // 7 <= INPUT_OUTPUT_CLASS_INVARIANT_CONST_LEVEL

#if 8 <= INPUT_OUTPUT_CLASS_INVARIANT_CONST_LEVEL
	#define INPUT_OUTPUT_CLASS_IS_VALID_CONST_8 CLASS_IS_VALID_CONST_8
#else // INPUT_OUTPUT_CLASS_INVARIANT_CONST_LEVEL < 8
	#define INPUT_OUTPUT_CLASS_IS_VALID_CONST_8 ((void)0)
#endif // 8 <= INPUT_OUTPUT_CLASS_INVARIANT_CONST_LEVEL

#if 9 <= INPUT_OUTPUT_CLASS_INVARIANT_CONST_LEVEL
	#define INPUT_OUTPUT_CLASS_IS_VALID_CONST_9 CLASS_IS_VALID_CONST_9
#else // INPUT_OUTPUT_CLASS_INVARIANT_CONST_LEVEL < 9
	#define INPUT_OUTPUT_CLASS_IS_VALID_CONST_9 ((void)0)
#endif // 9 <= INPUT_OUTPUT_CLASS_INVARIANT_CONST_LEVEL

#endif // CORE_TOOLS_HELPER_INPUT_OUTPUT_CLASS_INVARIANT_MACRO_H
