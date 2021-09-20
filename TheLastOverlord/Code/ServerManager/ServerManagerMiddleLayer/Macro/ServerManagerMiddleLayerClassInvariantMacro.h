// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���İ����汾��0.0.0.1 (2019/10/13 16:49)

#ifndef SERVER_MANAGER_MIDDLE_LAYER_MACRO_SERVER_MANAGER_MIDDLE_LAYER_CLASS_INVARIANT_MACRO_H
#define SERVER_MANAGER_MIDDLE_LAYER_MACRO_SERVER_MANAGER_MIDDLE_LAYER_CLASS_INVARIANT_MACRO_H

#include "UserMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#if !defined(SERVER_MANAGER_MIDDLE_LAYER_CLASS_INVARIANT_LEVEL)
	#define SERVER_MANAGER_MIDDLE_LAYER_CLASS_INVARIANT_LEVEL 8
#endif // SERVER_MANAGER_MIDDLE_LAYER_CLASS_INVARIANT_LEVEL

#if !defined(SERVER_MANAGER_MIDDLE_LAYER_CLASS_INVARIANT_CONST_LEVEL)
	#define SERVER_MANAGER_MIDDLE_LAYER_CLASS_INVARIANT_CONST_LEVEL 8
#endif // SERVER_MANAGER_MIDDLE_LAYER_CLASS_INVARIANT_CONST_LEVEL

static_assert(SERVER_MANAGER_MIDDLE_LAYER_CLASS_INVARIANT_LEVEL <= CLASS_INVARIANT_LEVEL, "Class invariant level definition error.");
static_assert(SERVER_MANAGER_MIDDLE_LAYER_CLASS_INVARIANT_CONST_LEVEL <= CLASS_INVARIANT_CONST_LEVEL, "Class invariant level definition error.");

#if 0 <= SERVER_MANAGER_MIDDLE_LAYER_CLASS_INVARIANT_LEVEL

	#define SERVER_MANAGER_MIDDLE_LAYER_CLASS_IS_VALID_0 CLASS_IS_VALID_0
	#define SERVER_MANAGER_MIDDLE_LAYER_SELF_CLASS_IS_VALID_0 SELF_CLASS_IS_VALID_0

#else // SERVER_MANAGER_MIDDLE_LAYER_CLASS_INVARIANT_LEVEL < 0

	#define SERVER_MANAGER_MIDDLE_LAYER_CLASS_IS_VALID_0 (static_cast<void>(0))
	#define SERVER_MANAGER_MIDDLE_LAYER_SELF_CLASS_IS_VALID_0 (static_cast<void>(0))

#endif // 0 <= SERVER_MANAGER_MIDDLE_LAYER_CLASS_INVARIANT_LEVEL

#if 1 <= SERVER_MANAGER_MIDDLE_LAYER_CLASS_INVARIANT_LEVEL

	#define SERVER_MANAGER_MIDDLE_LAYER_CLASS_IS_VALID_1 CLASS_IS_VALID_1
	#define SERVER_MANAGER_MIDDLE_LAYER_SELF_CLASS_IS_VALID_1 SELF_CLASS_IS_VALID_1

#else // SERVER_MANAGER_MIDDLE_LAYER_CLASS_INVARIANT_LEVEL < 1

	#define SERVER_MANAGER_MIDDLE_LAYER_CLASS_IS_VALID_1 (static_cast<void>(0))
	#define SERVER_MANAGER_MIDDLE_LAYER_SELF_CLASS_IS_VALID_1 (static_cast<void>(0))

#endif // 1 <= CLASS_INVARIANT_LEVEL

#if 2 <= SERVER_MANAGER_MIDDLE_LAYER_CLASS_INVARIANT_LEVEL

	#define SERVER_MANAGER_MIDDLE_LAYER_CLASS_IS_VALID_2 CLASS_IS_VALID_2
	#define SERVER_MANAGER_MIDDLE_LAYER_SELF_CLASS_IS_VALID_2 SELF_CLASS_IS_VALID_2

#else // SERVER_MANAGER_MIDDLE_LAYER_CLASS_INVARIANT_LEVEL < 2

	#define SERVER_MANAGER_MIDDLE_LAYER_CLASS_IS_VALID_2 (static_cast<void>(0))
	#define SERVER_MANAGER_MIDDLE_LAYER_SELF_CLASS_IS_VALID_2 (static_cast<void>(0))

#endif // 2 <= SERVER_MANAGER_MIDDLE_LAYER_CLASS_INVARIANT_LEVEL

#if 3 <= SERVER_MANAGER_MIDDLE_LAYER_CLASS_INVARIANT_LEVEL

	#define SERVER_MANAGER_MIDDLE_LAYER_CLASS_IS_VALID_3 CLASS_IS_VALID_3
	#define SERVER_MANAGER_MIDDLE_LAYER_SELF_CLASS_IS_VALID_3 SELF_CLASS_IS_VALID_3

#else // SERVER_MANAGER_MIDDLE_LAYER_CLASS_INVARIANT_LEVEL < 3

	#define SERVER_MANAGER_MIDDLE_LAYER_CLASS_IS_VALID_3 (static_cast<void>(0))
	#define SERVER_MANAGER_MIDDLE_LAYER_SELF_CLASS_IS_VALID_3 (static_cast<void>(0))

#endif // 3 <= SERVER_MANAGER_MIDDLE_LAYER_CLASS_INVARIANT_LEVEL

#if 4 <= SERVER_MANAGER_MIDDLE_LAYER_CLASS_INVARIANT_LEVEL

	#define SERVER_MANAGER_MIDDLE_LAYER_CLASS_IS_VALID_4 CLASS_IS_VALID_4
	#define SERVER_MANAGER_MIDDLE_LAYER_SELF_CLASS_IS_VALID_4 SELF_CLASS_IS_VALID_4

#else // SERVER_MANAGER_MIDDLE_LAYER_CLASS_INVARIANT_LEVEL < 4

	#define SERVER_MANAGER_MIDDLE_LAYER_CLASS_IS_VALID_4 (static_cast<void>(0))
	#define SERVER_MANAGER_MIDDLE_LAYER_SELF_CLASS_IS_VALID_4 (static_cast<void>(0))

#endif // 4 <= SERVER_MANAGER_MIDDLE_LAYER_CLASS_INVARIANT_LEVEL

#if 5 <= SERVER_MANAGER_MIDDLE_LAYER_CLASS_INVARIANT_LEVEL

	#define SERVER_MANAGER_MIDDLE_LAYER_CLASS_IS_VALID_5 CLASS_IS_VALID_5
	#define SERVER_MANAGER_MIDDLE_LAYER_SELF_CLASS_IS_VALID_5 SELF_CLASS_IS_VALID_5

#else // SERVER_MANAGER_MIDDLE_LAYER_CLASS_INVARIANT_LEVEL < 5

	#define SERVER_MANAGER_MIDDLE_LAYER_CLASS_IS_VALID_5 (static_cast<void>(0))
	#define SERVER_MANAGER_MIDDLE_LAYER_SELF_CLASS_IS_VALID_5 (static_cast<void>(0))

#endif // 5 <= SERVER_MANAGER_MIDDLE_LAYER_CLASS_INVARIANT_LEVEL

#if 6 <= SERVER_MANAGER_MIDDLE_LAYER_CLASS_INVARIANT_LEVEL

	#define SERVER_MANAGER_MIDDLE_LAYER_CLASS_IS_VALID_6 CLASS_IS_VALID_6
	#define SERVER_MANAGER_MIDDLE_LAYER_SELF_CLASS_IS_VALID_6 SELF_CLASS_IS_VALID_6

#else // CLASS_INVARIANT_LEVEL < 6

	#define SERVER_MANAGER_MIDDLE_LAYER_CLASS_IS_VALID_6 (static_cast<void>(0))
	#define SERVER_MANAGER_MIDDLE_LAYER_SELF_CLASS_IS_VALID_6 (static_cast<void>(0))

#endif // 6 <= SERVER_MANAGER_MIDDLE_LAYER_CLASS_INVARIANT_LEVEL

#if 7 <= SERVER_MANAGER_MIDDLE_LAYER_CLASS_INVARIANT_LEVEL

	#define SERVER_MANAGER_MIDDLE_LAYER_CLASS_IS_VALID_7 CLASS_IS_VALID_7
	#define SERVER_MANAGER_MIDDLE_LAYER_SELF_CLASS_IS_VALID_7 SELF_CLASS_IS_VALID_7

#else // SERVER_MANAGER_MIDDLE_LAYER_CLASS_INVARIANT_LEVEL < 7

	#define SERVER_MANAGER_MIDDLE_LAYER_CLASS_IS_VALID_7 (static_cast<void>(0))
	#define SERVER_MANAGER_MIDDLE_LAYER_SELF_CLASS_IS_VALID_7 (static_cast<void>(0))

#endif // 7 <= SERVER_MANAGER_MIDDLE_LAYER_CLASS_INVARIANT_LEVEL

#if 8 <= SERVER_MANAGER_MIDDLE_LAYER_CLASS_INVARIANT_LEVEL

	#define SERVER_MANAGER_MIDDLE_LAYER_CLASS_IS_VALID_8 CLASS_IS_VALID_8
	#define SERVER_MANAGER_MIDDLE_LAYER_SELF_CLASS_IS_VALID_8 SELF_CLASS_IS_VALID_8

#else // SERVER_MANAGER_MIDDLE_LAYER_CLASS_INVARIANT_LEVEL < 8

	#define SERVER_MANAGER_MIDDLE_LAYER_CLASS_IS_VALID_8 (static_cast<void>(0))
	#define SERVER_MANAGER_MIDDLE_LAYER_SELF_CLASS_IS_VALID_8 (static_cast<void>(0))

#endif // 8 <= SERVER_MANAGER_MIDDLE_LAYER_CLASS_INVARIANT_LEVEL

#if 9 <= SERVER_MANAGER_MIDDLE_LAYER_CLASS_INVARIANT_LEVEL

	#define SERVER_MANAGER_MIDDLE_LAYER_CLASS_IS_VALID_9 CLASS_IS_VALID_9
	#define SERVER_MANAGER_MIDDLE_LAYER_SELF_CLASS_IS_VALID_9 SELF_CLASS_IS_VALID_9

#else // SERVER_MANAGER_MIDDLE_LAYER_CLASS_INVARIANT_LEVEL < 9

	#define SERVER_MANAGER_MIDDLE_LAYER_CLASS_IS_VALID_9 (static_cast<void>(0))
	#define SERVER_MANAGER_MIDDLE_LAYER_SELF_CLASS_IS_VALID_9 (static_cast<void>(0))

#endif // 9 <= SERVER_MANAGER_MIDDLE_LAYER_CLASS_INVARIANT_LEVEL

#if 0 <= SERVER_MANAGER_MIDDLE_LAYER_CLASS_INVARIANT_CONST_LEVEL
	#define SERVER_MANAGER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_0 CLASS_IS_VALID_CONST_0
#else // SERVER_MANAGER_MIDDLE_LAYER_CLASS_INVARIANT_CONST_LEVEL < 0
	#define SERVER_MANAGER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_0 (static_cast<void>(0))
#endif // 0 <= SERVER_MANAGER_MIDDLE_LAYER_CLASS_INVARIANT_CONST_LEVEL

#if 1 <= SERVER_MANAGER_MIDDLE_LAYER_CLASS_INVARIANT_CONST_LEVEL
	#define SERVER_MANAGER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_1 CLASS_IS_VALID_CONST_1
#else // SERVER_MANAGER_MIDDLE_LAYER_CLASS_INVARIANT_CONST_LEVEL < 1
	#define SERVER_MANAGER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_1 (static_cast<void>(0))
#endif // 1 <= SERVER_MANAGER_MIDDLE_LAYER_CLASS_INVARIANT_CONST_LEVEL

#if 2 <= SERVER_MANAGER_MIDDLE_LAYER_CLASS_INVARIANT_CONST_LEVEL
	#define SERVER_MANAGER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_2 CLASS_IS_VALID_CONST_2
#else // SERVER_MANAGER_MIDDLE_LAYER_CLASS_INVARIANT_CONST_LEVEL < 2
	#define SERVER_MANAGER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_2 (static_cast<void>(0))
#endif // 2 <= SERVER_MANAGER_MIDDLE_LAYER_CLASS_INVARIANT_CONST_LEVEL

#if 3 <= SERVER_MANAGER_MIDDLE_LAYER_CLASS_INVARIANT_CONST_LEVEL
	#define SERVER_MANAGER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_3 CLASS_IS_VALID_CONST_3
#else // SERVER_MANAGER_MIDDLE_LAYER_CLASS_INVARIANT_CONST_LEVEL < 3
	#define SERVER_MANAGER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_3 (static_cast<void>(0))
#endif // 3 <= SERVER_MANAGER_MIDDLE_LAYER_CLASS_INVARIANT_CONST_LEVEL

#if 4 <= SERVER_MANAGER_MIDDLE_LAYER_CLASS_INVARIANT_CONST_LEVEL
	#define SERVER_MANAGER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_4 CLASS_IS_VALID_CONST_4
#else // SERVER_MANAGER_MIDDLE_LAYER_CLASS_INVARIANT_CONST_LEVEL < 4
	#define SERVER_MANAGER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_4 (static_cast<void>(0))
#endif // 4 <= SERVER_MANAGER_MIDDLE_LAYER_CLASS_INVARIANT_CONST_LEVEL

#if 5 <= SERVER_MANAGER_MIDDLE_LAYER_CLASS_INVARIANT_CONST_LEVEL
	#define SERVER_MANAGER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_5 CLASS_IS_VALID_CONST_5
#else // SERVER_MANAGER_MIDDLE_LAYER_CLASS_INVARIANT_CONST_LEVEL < 5
	#define SERVER_MANAGER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_5 (static_cast<void>(0))
#endif // 5 <= SERVER_MANAGER_MIDDLE_LAYER_CLASS_INVARIANT_CONST_LEVEL

#if 6 <= SERVER_MANAGER_MIDDLE_LAYER_CLASS_INVARIANT_CONST_LEVEL
	#define SERVER_MANAGER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_6 CLASS_IS_VALID_CONST_6
#else // SERVER_MANAGER_MIDDLE_LAYER_CLASS_INVARIANT_CONST_LEVEL < 6
	#define SERVER_MANAGER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_6 (static_cast<void>(0))
#endif // 6 <= SERVER_MANAGER_MIDDLE_LAYER_CLASS_INVARIANT_CONST_LEVEL

#if 7 <= SERVER_MANAGER_MIDDLE_LAYER_CLASS_INVARIANT_CONST_LEVEL
	#define SERVER_MANAGER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_7 CLASS_IS_VALID_CONST_7
#else // SERVER_MANAGER_MIDDLE_LAYER_CLASS_INVARIANT_CONST_LEVEL < 7
	#define SERVER_MANAGER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_7 (static_cast<void>(0))
#endif // 7 <= SERVER_MANAGER_MIDDLE_LAYER_CLASS_INVARIANT_CONST_LEVEL

#if 8 <= SERVER_MANAGER_MIDDLE_LAYER_CLASS_INVARIANT_CONST_LEVEL
	#define SERVER_MANAGER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_8 CLASS_IS_VALID_CONST_8
#else // SERVER_MANAGER_MIDDLE_LAYER_CLASS_INVARIANT_CONST_LEVEL < 8
	#define SERVER_MANAGER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_8 (static_cast<void>(0))
#endif // 8 <= SERVER_MANAGER_MIDDLE_LAYER_CLASS_INVARIANT_CONST_LEVEL

#if 9 <= SERVER_MANAGER_MIDDLE_LAYER_CLASS_INVARIANT_CONST_LEVEL
	#define SERVER_MANAGER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9 CLASS_IS_VALID_CONST_9
#else // SERVER_MANAGER_MIDDLE_LAYER_CLASS_INVARIANT_CONST_LEVEL < 9
	#define SERVER_MANAGER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9 (static_cast<void>(0))
#endif // 9 <= SERVER_MANAGER_MIDDLE_LAYER_CLASS_INVARIANT_CONST_LEVEL

#endif // SERVER_MANAGER_MIDDLE_LAYER_MACRO_SERVER_MANAGER_MIDDLE_LAYER_CLASS_INVARIANT_MACRO_H
