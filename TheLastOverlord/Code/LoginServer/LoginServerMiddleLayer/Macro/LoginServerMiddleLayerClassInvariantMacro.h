// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���İ����汾��0.0.0.1 (2019/10/11 14:05)

#ifndef LOGIN_SERVER_MIDDLE_LAYER_MACRO_LOGIN_SERVER_MIDDLE_LAYER_CLASS_INVARIANT_MACRO_H
#define LOGIN_SERVER_MIDDLE_LAYER_MACRO_LOGIN_SERVER_MIDDLE_LAYER_CLASS_INVARIANT_MACRO_H

#include "UserMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#if !defined(LOGIN_SERVER_MIDDLE_LAYER_CLASS_INVARIANT_LEVEL)
	#define LOGIN_SERVER_MIDDLE_LAYER_CLASS_INVARIANT_LEVEL 8
#endif // LOGIN_SERVER_MIDDLE_LAYER_CLASS_INVARIANT_LEVEL

#if !defined(LOGIN_SERVER_MIDDLE_LAYER_CLASS_INVARIANT_CONST_LEVEL)
	#define LOGIN_SERVER_MIDDLE_LAYER_CLASS_INVARIANT_CONST_LEVEL 8
#endif // LOGIN_SERVER_MIDDLE_LAYER_CLASS_INVARIANT_CONST_LEVEL

static_assert(LOGIN_SERVER_MIDDLE_LAYER_CLASS_INVARIANT_LEVEL <= CLASS_INVARIANT_LEVEL, "Class invariant level definition error.");
static_assert(LOGIN_SERVER_MIDDLE_LAYER_CLASS_INVARIANT_CONST_LEVEL <= CLASS_INVARIANT_CONST_LEVEL, "Class invariant level definition error.");

#if 0 <= LOGIN_SERVER_MIDDLE_LAYER_CLASS_INVARIANT_LEVEL

	#define LOGIN_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_0 CLASS_IS_VALID_0
	#define LOGIN_SERVER_MIDDLE_LAYER_SELF_CLASS_IS_VALID_0 SELF_CLASS_IS_VALID_0

#else // LOGIN_SERVER_MIDDLE_LAYER_CLASS_INVARIANT_LEVEL < 0

	#define LOGIN_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_0 (static_cast<void>(0))
	#define LOGIN_SERVER_MIDDLE_LAYER_SELF_CLASS_IS_VALID_0 (static_cast<void>(0))

#endif // 0 <= LOGIN_SERVER_MIDDLE_LAYER_CLASS_INVARIANT_LEVEL

#if 1 <= LOGIN_SERVER_MIDDLE_LAYER_CLASS_INVARIANT_LEVEL

	#define LOGIN_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_1 CLASS_IS_VALID_1
	#define LOGIN_SERVER_MIDDLE_LAYER_SELF_CLASS_IS_VALID_1 SELF_CLASS_IS_VALID_1

#else // LOGIN_SERVER_MIDDLE_LAYER_CLASS_INVARIANT_LEVEL < 1

	#define LOGIN_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_1 (static_cast<void>(0))
	#define LOGIN_SERVER_MIDDLE_LAYER_SELF_CLASS_IS_VALID_1 (static_cast<void>(0))

#endif // 1 <= CLASS_INVARIANT_LEVEL

#if 2 <= LOGIN_SERVER_MIDDLE_LAYER_CLASS_INVARIANT_LEVEL

	#define LOGIN_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_2 CLASS_IS_VALID_2
	#define LOGIN_SERVER_MIDDLE_LAYER_SELF_CLASS_IS_VALID_2 SELF_CLASS_IS_VALID_2

#else // LOGIN_SERVER_MIDDLE_LAYER_CLASS_INVARIANT_LEVEL < 2

	#define LOGIN_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_2 (static_cast<void>(0))
	#define LOGIN_SERVER_MIDDLE_LAYER_SELF_CLASS_IS_VALID_2 (static_cast<void>(0))

#endif // 2 <= LOGIN_SERVER_MIDDLE_LAYER_CLASS_INVARIANT_LEVEL

#if 3 <= LOGIN_SERVER_MIDDLE_LAYER_CLASS_INVARIANT_LEVEL

	#define LOGIN_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_3 CLASS_IS_VALID_3
	#define LOGIN_SERVER_MIDDLE_LAYER_SELF_CLASS_IS_VALID_3 SELF_CLASS_IS_VALID_3

#else // LOGIN_SERVER_MIDDLE_LAYER_CLASS_INVARIANT_LEVEL < 3

	#define LOGIN_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_3 (static_cast<void>(0))
	#define LOGIN_SERVER_MIDDLE_LAYER_SELF_CLASS_IS_VALID_3 (static_cast<void>(0))

#endif // 3 <= LOGIN_SERVER_MIDDLE_LAYER_CLASS_INVARIANT_LEVEL

#if 4 <= LOGIN_SERVER_MIDDLE_LAYER_CLASS_INVARIANT_LEVEL

	#define LOGIN_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_4 CLASS_IS_VALID_4
	#define LOGIN_SERVER_MIDDLE_LAYER_SELF_CLASS_IS_VALID_4 SELF_CLASS_IS_VALID_4

#else // LOGIN_SERVER_MIDDLE_LAYER_CLASS_INVARIANT_LEVEL < 4

	#define LOGIN_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_4 (static_cast<void>(0))
	#define LOGIN_SERVER_MIDDLE_LAYER_SELF_CLASS_IS_VALID_4 (static_cast<void>(0))

#endif // 4 <= LOGIN_SERVER_MIDDLE_LAYER_CLASS_INVARIANT_LEVEL

#if 5 <= LOGIN_SERVER_MIDDLE_LAYER_CLASS_INVARIANT_LEVEL

	#define LOGIN_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_5 CLASS_IS_VALID_5
	#define LOGIN_SERVER_MIDDLE_LAYER_SELF_CLASS_IS_VALID_5 SELF_CLASS_IS_VALID_5

#else // LOGIN_SERVER_MIDDLE_LAYER_CLASS_INVARIANT_LEVEL < 5

	#define LOGIN_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_5 (static_cast<void>(0))
	#define LOGIN_SERVER_MIDDLE_LAYER_SELF_CLASS_IS_VALID_5 (static_cast<void>(0))

#endif // 5 <= LOGIN_SERVER_MIDDLE_LAYER_CLASS_INVARIANT_LEVEL

#if 6 <= LOGIN_SERVER_MIDDLE_LAYER_CLASS_INVARIANT_LEVEL

	#define LOGIN_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_6 CLASS_IS_VALID_6
	#define LOGIN_SERVER_MIDDLE_LAYER_SELF_CLASS_IS_VALID_6 SELF_CLASS_IS_VALID_6

#else // CLASS_INVARIANT_LEVEL < 6

	#define LOGIN_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_6 (static_cast<void>(0))
	#define LOGIN_SERVER_MIDDLE_LAYER_SELF_CLASS_IS_VALID_6 (static_cast<void>(0))

#endif // 6 <= LOGIN_SERVER_MIDDLE_LAYER_CLASS_INVARIANT_LEVEL

#if 7 <= LOGIN_SERVER_MIDDLE_LAYER_CLASS_INVARIANT_LEVEL

	#define LOGIN_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_7 CLASS_IS_VALID_7
	#define LOGIN_SERVER_MIDDLE_LAYER_SELF_CLASS_IS_VALID_7 SELF_CLASS_IS_VALID_7

#else // LOGIN_SERVER_MIDDLE_LAYER_CLASS_INVARIANT_LEVEL < 7

	#define LOGIN_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_7 (static_cast<void>(0))
	#define LOGIN_SERVER_MIDDLE_LAYER_SELF_CLASS_IS_VALID_7 (static_cast<void>(0))

#endif // 7 <= LOGIN_SERVER_MIDDLE_LAYER_CLASS_INVARIANT_LEVEL

#if 8 <= LOGIN_SERVER_MIDDLE_LAYER_CLASS_INVARIANT_LEVEL

	#define LOGIN_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_8 CLASS_IS_VALID_8
	#define LOGIN_SERVER_MIDDLE_LAYER_SELF_CLASS_IS_VALID_8 SELF_CLASS_IS_VALID_8

#else // LOGIN_SERVER_MIDDLE_LAYER_CLASS_INVARIANT_LEVEL < 8

	#define LOGIN_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_8 (static_cast<void>(0))
	#define LOGIN_SERVER_MIDDLE_LAYER_SELF_CLASS_IS_VALID_8 (static_cast<void>(0))

#endif // 8 <= LOGIN_SERVER_MIDDLE_LAYER_CLASS_INVARIANT_LEVEL

#if 9 <= LOGIN_SERVER_MIDDLE_LAYER_CLASS_INVARIANT_LEVEL

	#define LOGIN_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_9 CLASS_IS_VALID_9
	#define LOGIN_SERVER_MIDDLE_LAYER_SELF_CLASS_IS_VALID_9 SELF_CLASS_IS_VALID_9

#else // LOGIN_SERVER_MIDDLE_LAYER_CLASS_INVARIANT_LEVEL < 9

	#define LOGIN_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_9 (static_cast<void>(0))
	#define LOGIN_SERVER_MIDDLE_LAYER_SELF_CLASS_IS_VALID_9 (static_cast<void>(0))

#endif // 9 <= LOGIN_SERVER_MIDDLE_LAYER_CLASS_INVARIANT_LEVEL

#if 0 <= LOGIN_SERVER_MIDDLE_LAYER_CLASS_INVARIANT_CONST_LEVEL
	#define LOGIN_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_0 CLASS_IS_VALID_CONST_0
#else // LOGIN_SERVER_MIDDLE_LAYER_CLASS_INVARIANT_CONST_LEVEL < 0
	#define LOGIN_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_0 (static_cast<void>(0))
#endif // 0 <= LOGIN_SERVER_MIDDLE_LAYER_CLASS_INVARIANT_CONST_LEVEL

#if 1 <= LOGIN_SERVER_MIDDLE_LAYER_CLASS_INVARIANT_CONST_LEVEL
	#define LOGIN_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_1 CLASS_IS_VALID_CONST_1
#else // LOGIN_SERVER_MIDDLE_LAYER_CLASS_INVARIANT_CONST_LEVEL < 1
	#define LOGIN_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_1 (static_cast<void>(0))
#endif // 1 <= LOGIN_SERVER_MIDDLE_LAYER_CLASS_INVARIANT_CONST_LEVEL

#if 2 <= LOGIN_SERVER_MIDDLE_LAYER_CLASS_INVARIANT_CONST_LEVEL
	#define LOGIN_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_2 CLASS_IS_VALID_CONST_2
#else // LOGIN_SERVER_MIDDLE_LAYER_CLASS_INVARIANT_CONST_LEVEL < 2
	#define LOGIN_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_2 (static_cast<void>(0))
#endif // 2 <= LOGIN_SERVER_MIDDLE_LAYER_CLASS_INVARIANT_CONST_LEVEL

#if 3 <= LOGIN_SERVER_MIDDLE_LAYER_CLASS_INVARIANT_CONST_LEVEL
	#define LOGIN_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_3 CLASS_IS_VALID_CONST_3
#else // LOGIN_SERVER_MIDDLE_LAYER_CLASS_INVARIANT_CONST_LEVEL < 3
	#define LOGIN_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_3 (static_cast<void>(0))
#endif // 3 <= LOGIN_SERVER_MIDDLE_LAYER_CLASS_INVARIANT_CONST_LEVEL

#if 4 <= LOGIN_SERVER_MIDDLE_LAYER_CLASS_INVARIANT_CONST_LEVEL
	#define LOGIN_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_4 CLASS_IS_VALID_CONST_4
#else // LOGIN_SERVER_MIDDLE_LAYER_CLASS_INVARIANT_CONST_LEVEL < 4
	#define LOGIN_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_4 (static_cast<void>(0))
#endif // 4 <= LOGIN_SERVER_MIDDLE_LAYER_CLASS_INVARIANT_CONST_LEVEL

#if 5 <= LOGIN_SERVER_MIDDLE_LAYER_CLASS_INVARIANT_CONST_LEVEL
	#define LOGIN_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_5 CLASS_IS_VALID_CONST_5
#else // LOGIN_SERVER_MIDDLE_LAYER_CLASS_INVARIANT_CONST_LEVEL < 5
	#define LOGIN_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_5 (static_cast<void>(0))
#endif // 5 <= LOGIN_SERVER_MIDDLE_LAYER_CLASS_INVARIANT_CONST_LEVEL

#if 6 <= LOGIN_SERVER_MIDDLE_LAYER_CLASS_INVARIANT_CONST_LEVEL
	#define LOGIN_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_6 CLASS_IS_VALID_CONST_6
#else // LOGIN_SERVER_MIDDLE_LAYER_CLASS_INVARIANT_CONST_LEVEL < 6
	#define LOGIN_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_6 (static_cast<void>(0))
#endif // 6 <= LOGIN_SERVER_MIDDLE_LAYER_CLASS_INVARIANT_CONST_LEVEL

#if 7 <= LOGIN_SERVER_MIDDLE_LAYER_CLASS_INVARIANT_CONST_LEVEL
	#define LOGIN_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_7 CLASS_IS_VALID_CONST_7
#else // LOGIN_SERVER_MIDDLE_LAYER_CLASS_INVARIANT_CONST_LEVEL < 7
	#define LOGIN_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_7 (static_cast<void>(0))
#endif // 7 <= LOGIN_SERVER_MIDDLE_LAYER_CLASS_INVARIANT_CONST_LEVEL

#if 8 <= LOGIN_SERVER_MIDDLE_LAYER_CLASS_INVARIANT_CONST_LEVEL
	#define LOGIN_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_8 CLASS_IS_VALID_CONST_8
#else // LOGIN_SERVER_MIDDLE_LAYER_CLASS_INVARIANT_CONST_LEVEL < 8
	#define LOGIN_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_8 (static_cast<void>(0))
#endif // 8 <= LOGIN_SERVER_MIDDLE_LAYER_CLASS_INVARIANT_CONST_LEVEL

#if 9 <= LOGIN_SERVER_MIDDLE_LAYER_CLASS_INVARIANT_CONST_LEVEL
	#define LOGIN_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9 CLASS_IS_VALID_CONST_9
#else // LOGIN_SERVER_MIDDLE_LAYER_CLASS_INVARIANT_CONST_LEVEL < 9
	#define LOGIN_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9 (static_cast<void>(0))
#endif // 9 <= LOGIN_SERVER_MIDDLE_LAYER_CLASS_INVARIANT_CONST_LEVEL

#endif // LOGIN_SERVER_MIDDLE_LAYER_MACRO_LOGIN_SERVER_MIDDLE_LAYER_CLASS_INVARIANT_MACRO_H
