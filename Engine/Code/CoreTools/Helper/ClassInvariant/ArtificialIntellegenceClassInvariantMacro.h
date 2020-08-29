// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/18 10:04)

#ifndef CORE_TOOLS_HELPER_ARTIFICIAL_INTELLEGENCE_CLASS_INVARIANT_MACRO_H
#define CORE_TOOLS_HELPER_ARTIFICIAL_INTELLEGENCE_CLASS_INVARIANT_MACRO_H

#include "CoreTools/Helper/ClassInvariantMacro.h"

#if !defined(ARTIFICIAL_INTELLEGENCE_CLASS_INVARIANT_LEVEL)
	#define ARTIFICIAL_INTELLEGENCE_CLASS_INVARIANT_LEVEL 8
#endif // ARTIFICIAL_INTELLEGENCE_CLASS_INVARIANT_LEVEL

#if !defined(ARTIFICIAL_INTELLEGENCE_CLASS_INVARIANT_CONST_LEVEL)
	#define ARTIFICIAL_INTELLEGENCE_CLASS_INVARIANT_CONST_LEVEL 0
#endif // ARTIFICIAL_INTELLEGENCE_CLASS_INVARIANT_CONST_LEVEL

static_assert(ARTIFICIAL_INTELLEGENCE_CLASS_INVARIANT_LEVEL <= CLASS_INVARIANT_LEVEL, "Artificial Intellegence class invariant level definition error.");
static_assert(ARTIFICIAL_INTELLEGENCE_CLASS_INVARIANT_CONST_LEVEL <= CLASS_INVARIANT_CONST_LEVEL, "Artificial Intellegence class invariant level definition error.");

#if 0 <= ARTIFICIAL_INTELLEGENCE_CLASS_INVARIANT_LEVEL

	#define ARTIFICIAL_INTELLEGENCE_CLASS_IS_VALID_0 CLASS_IS_VALID_0
	#define ARTIFICIAL_INTELLEGENCE_SELF_CLASS_IS_VALID_0 SELF_CLASS_IS_VALID_0

#else // ARTIFICIAL_INTELLEGENCE_CLASS_INVARIANT_LEVEL < 0

	#define ARTIFICIAL_INTELLEGENCE_CLASS_IS_VALID_0 (static_cast<void>(0))
	#define ARTIFICIAL_INTELLEGENCE_SELF_CLASS_IS_VALID_0 (static_cast<void>(0))

#endif //0 <= ARTIFICIAL_INTELLEGENCE_CLASS_INVARIANT_LEVEL

#if 1 <= ARTIFICIAL_INTELLEGENCE_CLASS_INVARIANT_LEVEL

	#define ARTIFICIAL_INTELLEGENCE_CLASS_IS_VALID_1 CLASS_IS_VALID_1
	#define ARTIFICIAL_INTELLEGENCE_SELF_CLASS_IS_VALID_1 SELF_CLASS_IS_VALID_1

#else // ARTIFICIAL_INTELLEGENCE_CLASS_INVARIANT_LEVEL < 1

	#define ARTIFICIAL_INTELLEGENCE_CLASS_IS_VALID_1 (static_cast<void>(0))
	#define ARTIFICIAL_INTELLEGENCE_SELF_CLASS_IS_VALID_1 (static_cast<void>(0))

#endif // 1 <= CLASS_INVARIANT_LEVEL

#if 2 <= ARTIFICIAL_INTELLEGENCE_CLASS_INVARIANT_LEVEL

	#define ARTIFICIAL_INTELLEGENCE_CLASS_IS_VALID_2 CLASS_IS_VALID_2
	#define ARTIFICIAL_INTELLEGENCE_SELF_CLASS_IS_VALID_2 SELF_CLASS_IS_VALID_2

#else // ARTIFICIAL_INTELLEGENCE_CLASS_INVARIANT_LEVEL < 2

	#define ARTIFICIAL_INTELLEGENCE_CLASS_IS_VALID_2 (static_cast<void>(0))
	#define ARTIFICIAL_INTELLEGENCE_SELF_CLASS_IS_VALID_2 (static_cast<void>(0))

#endif // 2 <= ARTIFICIAL_INTELLEGENCE_CLASS_INVARIANT_LEVEL

#if 3 <= ARTIFICIAL_INTELLEGENCE_CLASS_INVARIANT_LEVEL

	#define ARTIFICIAL_INTELLEGENCE_CLASS_IS_VALID_3 CLASS_IS_VALID_3
	#define ARTIFICIAL_INTELLEGENCE_SELF_CLASS_IS_VALID_3 SELF_CLASS_IS_VALID_3

#else // ARTIFICIAL_INTELLEGENCE_CLASS_INVARIANT_LEVEL < 3

	#define ARTIFICIAL_INTELLEGENCE_CLASS_IS_VALID_3 (static_cast<void>(0))
	#define ARTIFICIAL_INTELLEGENCE_SELF_CLASS_IS_VALID_3 (static_cast<void>(0))

#endif // 3 <= ARTIFICIAL_INTELLEGENCE_CLASS_INVARIANT_LEVEL

#if 4 <= ARTIFICIAL_INTELLEGENCE_CLASS_INVARIANT_LEVEL

	#define ARTIFICIAL_INTELLEGENCE_CLASS_IS_VALID_4 CLASS_IS_VALID_4
	#define ARTIFICIAL_INTELLEGENCE_SELF_CLASS_IS_VALID_4 SELF_CLASS_IS_VALID_4

#else // ARTIFICIAL_INTELLEGENCE_CLASS_INVARIANT_LEVEL < 4

	#define ARTIFICIAL_INTELLEGENCE_CLASS_IS_VALID_4 (static_cast<void>(0))
	#define ARTIFICIAL_INTELLEGENCE_SELF_CLASS_IS_VALID_4 (static_cast<void>(0))

#endif // 4 <= ARTIFICIAL_INTELLEGENCE_CLASS_INVARIANT_LEVEL

#if 5 <= ARTIFICIAL_INTELLEGENCE_CLASS_INVARIANT_LEVEL

	#define ARTIFICIAL_INTELLEGENCE_CLASS_IS_VALID_5 CLASS_IS_VALID_5
	#define ARTIFICIAL_INTELLEGENCE_SELF_CLASS_IS_VALID_5 SELF_CLASS_IS_VALID_5

#else // ARTIFICIAL_INTELLEGENCE_CLASS_INVARIANT_LEVEL < 5

	#define ARTIFICIAL_INTELLEGENCE_CLASS_IS_VALID_5 (static_cast<void>(0))
	#define ARTIFICIAL_INTELLEGENCE_SELF_CLASS_IS_VALID_5 (static_cast<void>(0))

#endif // 5 <= ARTIFICIAL_INTELLEGENCE_CLASS_INVARIANT_LEVEL

#if 6 <= ARTIFICIAL_INTELLEGENCE_CLASS_INVARIANT_LEVEL

	#define ARTIFICIAL_INTELLEGENCE_CLASS_IS_VALID_6 CLASS_IS_VALID_6
	#define ARTIFICIAL_INTELLEGENCE_SELF_CLASS_IS_VALID_6 SELF_CLASS_IS_VALID_6

#else // CLASS_INVARIANT_LEVEL < 6

	#define ARTIFICIAL_INTELLEGENCE_CLASS_IS_VALID_6 (static_cast<void>(0))
	#define ARTIFICIAL_INTELLEGENCE_SELF_CLASS_IS_VALID_6 (static_cast<void>(0))

#endif // 6 <= ARTIFICIAL_INTELLEGENCE_CLASS_INVARIANT_LEVEL

#if 7 <= ARTIFICIAL_INTELLEGENCE_CLASS_INVARIANT_LEVEL

	#define ARTIFICIAL_INTELLEGENCE_CLASS_IS_VALID_7 CLASS_IS_VALID_7
	#define ARTIFICIAL_INTELLEGENCE_SELF_CLASS_IS_VALID_7 SELF_CLASS_IS_VALID_7

#else // ARTIFICIAL_INTELLEGENCE_CLASS_INVARIANT_LEVEL < 7

	#define ARTIFICIAL_INTELLEGENCE_CLASS_IS_VALID_7 (static_cast<void>(0))
	#define ARTIFICIAL_INTELLEGENCE_SELF_CLASS_IS_VALID_7 (static_cast<void>(0))

#endif // 7 <= ARTIFICIAL_INTELLEGENCE_CLASS_INVARIANT_LEVEL

#if 8 <= ARTIFICIAL_INTELLEGENCE_CLASS_INVARIANT_LEVEL

	#define ARTIFICIAL_INTELLEGENCE_CLASS_IS_VALID_8 CLASS_IS_VALID_8
	#define ARTIFICIAL_INTELLEGENCE_SELF_CLASS_IS_VALID_8 SELF_CLASS_IS_VALID_8

#else // ARTIFICIAL_INTELLEGENCE_CLASS_INVARIANT_LEVEL < 8

	#define ARTIFICIAL_INTELLEGENCE_CLASS_IS_VALID_8 (static_cast<void>(0))
	#define ARTIFICIAL_INTELLEGENCE_SELF_CLASS_IS_VALID_8 (static_cast<void>(0))

#endif // 8 <= ARTIFICIAL_INTELLEGENCE_CLASS_INVARIANT_LEVEL

#if 9 <= ARTIFICIAL_INTELLEGENCE_CLASS_INVARIANT_LEVEL

	#define ARTIFICIAL_INTELLEGENCE_CLASS_IS_VALID_9 CLASS_IS_VALID_9
	#define ARTIFICIAL_INTELLEGENCE_SELF_CLASS_IS_VALID_9 SELF_CLASS_IS_VALID_9

#else // ARTIFICIAL_INTELLEGENCE_CLASS_INVARIANT_LEVEL < 9

	#define ARTIFICIAL_INTELLEGENCE_CLASS_IS_VALID_9 (static_cast<void>(0))
	#define ARTIFICIAL_INTELLEGENCE_SELF_CLASS_IS_VALID_9 (static_cast<void>(0))

#endif // 9 <= ARTIFICIAL_INTELLEGENCE_CLASS_INVARIANT_LEVEL

#if 0 <= ARTIFICIAL_INTELLEGENCE_CLASS_INVARIANT_CONST_LEVEL
	#define ARTIFICIAL_INTELLEGENCE_CLASS_IS_VALID_CONST_0 CLASS_IS_VALID_CONST_0
#else // ARTIFICIAL_INTELLEGENCE_CLASS_INVARIANT_CONST_LEVEL < 0
	#define ARTIFICIAL_INTELLEGENCE_CLASS_IS_VALID_CONST_0 (static_cast<void>(0))
#endif // 0 <= ARTIFICIAL_INTELLEGENCE_CLASS_INVARIANT_CONST_LEVEL

#if 1 <= ARTIFICIAL_INTELLEGENCE_CLASS_INVARIANT_CONST_LEVEL
	#define ARTIFICIAL_INTELLEGENCE_CLASS_IS_VALID_CONST_1 CLASS_IS_VALID_CONST_1
#else // ARTIFICIAL_INTELLEGENCE_CLASS_INVARIANT_CONST_LEVEL < 1
	#define ARTIFICIAL_INTELLEGENCE_CLASS_IS_VALID_CONST_1 (static_cast<void>(0))
#endif // 1 <= ARTIFICIAL_INTELLEGENCE_CLASS_INVARIANT_CONST_LEVEL

#if 2 <= ARTIFICIAL_INTELLEGENCE_CLASS_INVARIANT_CONST_LEVEL
	#define ARTIFICIAL_INTELLEGENCE_CLASS_IS_VALID_CONST_2 CLASS_IS_VALID_CONST_2
#else // ARTIFICIAL_INTELLEGENCE_CLASS_INVARIANT_CONST_LEVEL < 2
	#define ARTIFICIAL_INTELLEGENCE_CLASS_IS_VALID_CONST_2 (static_cast<void>(0))
#endif // 2 <= ARTIFICIAL_INTELLEGENCE_CLASS_INVARIANT_CONST_LEVEL

#if 3 <= ARTIFICIAL_INTELLEGENCE_CLASS_INVARIANT_CONST_LEVEL
	#define ARTIFICIAL_INTELLEGENCE_CLASS_IS_VALID_CONST_3 CLASS_IS_VALID_CONST_3
#else // ARTIFICIAL_INTELLEGENCE_CLASS_INVARIANT_CONST_LEVEL < 3
	#define ARTIFICIAL_INTELLEGENCE_CLASS_IS_VALID_CONST_3 (static_cast<void>(0))
#endif // 3 <= ARTIFICIAL_INTELLEGENCE_CLASS_INVARIANT_CONST_LEVEL

#if 4 <= ARTIFICIAL_INTELLEGENCE_CLASS_INVARIANT_CONST_LEVEL
	#define ARTIFICIAL_INTELLEGENCE_CLASS_IS_VALID_CONST_4 CLASS_IS_VALID_CONST_4
#else // ARTIFICIAL_INTELLEGENCE_CLASS_INVARIANT_CONST_LEVEL < 4
	#define ARTIFICIAL_INTELLEGENCE_CLASS_IS_VALID_CONST_4 (static_cast<void>(0))
#endif // 4 <= ARTIFICIAL_INTELLEGENCE_CLASS_INVARIANT_CONST_LEVEL

#if 5 <= ARTIFICIAL_INTELLEGENCE_CLASS_INVARIANT_CONST_LEVEL
	#define ARTIFICIAL_INTELLEGENCE_CLASS_IS_VALID_CONST_5 CLASS_IS_VALID_CONST_5
#else // ARTIFICIAL_INTELLEGENCE_CLASS_INVARIANT_CONST_LEVEL < 5
	#define ARTIFICIAL_INTELLEGENCE_CLASS_IS_VALID_CONST_5 (static_cast<void>(0))
#endif // 5 <= ARTIFICIAL_INTELLEGENCE_CLASS_INVARIANT_CONST_LEVEL

#if 6 <= ARTIFICIAL_INTELLEGENCE_CLASS_INVARIANT_CONST_LEVEL
	#define ARTIFICIAL_INTELLEGENCE_CLASS_IS_VALID_CONST_6 CLASS_IS_VALID_CONST_6
#else // ARTIFICIAL_INTELLEGENCE_CLASS_INVARIANT_CONST_LEVEL < 6
	#define ARTIFICIAL_INTELLEGENCE_CLASS_IS_VALID_CONST_6 (static_cast<void>(0))
#endif // 6 <= ARTIFICIAL_INTELLEGENCE_CLASS_INVARIANT_CONST_LEVEL

#if 7 <= ARTIFICIAL_INTELLEGENCE_CLASS_INVARIANT_CONST_LEVEL
	#define ARTIFICIAL_INTELLEGENCE_CLASS_IS_VALID_CONST_7 CLASS_IS_VALID_CONST_7
#else // ARTIFICIAL_INTELLEGENCE_CLASS_INVARIANT_CONST_LEVEL < 7
	#define ARTIFICIAL_INTELLEGENCE_CLASS_IS_VALID_CONST_7 (static_cast<void>(0))
#endif // 7 <= ARTIFICIAL_INTELLEGENCE_CLASS_INVARIANT_CONST_LEVEL

#if 8 <= ARTIFICIAL_INTELLEGENCE_CLASS_INVARIANT_CONST_LEVEL
	#define ARTIFICIAL_INTELLEGENCE_CLASS_IS_VALID_CONST_8 CLASS_IS_VALID_CONST_8
#else // ARTIFICIAL_INTELLEGENCE_CLASS_INVARIANT_CONST_LEVEL < 8
	#define ARTIFICIAL_INTELLEGENCE_CLASS_IS_VALID_CONST_8 (static_cast<void>(0))
#endif // 8 <= ARTIFICIAL_INTELLEGENCE_CLASS_INVARIANT_CONST_LEVEL

#if 9 <= ARTIFICIAL_INTELLEGENCE_CLASS_INVARIANT_CONST_LEVEL
	#define ARTIFICIAL_INTELLEGENCE_CLASS_IS_VALID_CONST_9 CLASS_IS_VALID_CONST_9
#else // ARTIFICIAL_INTELLEGENCE_CLASS_INVARIANT_CONST_LEVEL < 9
	#define ARTIFICIAL_INTELLEGENCE_CLASS_IS_VALID_CONST_9 (static_cast<void>(0))
#endif // 9 <= ARTIFICIAL_INTELLEGENCE_CLASS_INVARIANT_CONST_LEVEL

#endif // CORE_TOOLS_HELPER_ARTIFICIAL_INTELLEGENCE_CLASS_INVARIANT_MACRO_H
