///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.6.0.0 (2020/12/27 19:52)

#ifndef SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_HELPER_SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_INVARIANT_MACRO_H
#define SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_HELPER_SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_INVARIANT_MACRO_H

#include "UserMacro.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"

#if !defined(SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_INVARIANT_LEVEL)
	#define SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_INVARIANT_LEVEL 8
#endif // SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_INVARIANT_LEVEL

#if !defined(SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_INVARIANT_CONST_LEVEL)
	#define SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_INVARIANT_CONST_LEVEL 8
#endif // SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_INVARIANT_CONST_LEVEL

static_assert(SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_INVARIANT_LEVEL <= USER_CLASS_INVARIANT_LEVEL, "Class invariant level definition error.");
static_assert(SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_INVARIANT_CONST_LEVEL <= USER_CLASS_INVARIANT_CONST_LEVEL, "Class invariant level definition error.");

#if 0 <= SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_INVARIANT_LEVEL

	#define SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_IS_VALID_0 USER_CLASS_IS_VALID_0
	#define SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_SELF_CLASS_IS_VALID_0 USER_SELF_CLASS_IS_VALID_0

#else // SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_INVARIANT_LEVEL < 0

	#define SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_IS_VALID_0 (static_cast<void>(0))
	#define SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_SELF_CLASS_IS_VALID_0 (static_cast<void>(0))

#endif // 0 <= SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_INVARIANT_LEVEL

#if 1 <= SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_INVARIANT_LEVEL

	#define SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_IS_VALID_1 USER_CLASS_IS_VALID_1
	#define SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_SELF_CLASS_IS_VALID_1 USER_SELF_CLASS_IS_VALID_1

#else // SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_INVARIANT_LEVEL < 1

	#define SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_IS_VALID_1 (static_cast<void>(0))
	#define SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_SELF_CLASS_IS_VALID_1 (static_cast<void>(0))

#endif // 1 <= CLASS_INVARIANT_LEVEL

#if 2 <= SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_INVARIANT_LEVEL

	#define SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_IS_VALID_2 USER_CLASS_IS_VALID_2
	#define SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_SELF_CLASS_IS_VALID_2 USER_SELF_CLASS_IS_VALID_2

#else // SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_INVARIANT_LEVEL < 2

	#define SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_IS_VALID_2 (static_cast<void>(0))
	#define SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_SELF_CLASS_IS_VALID_2 (static_cast<void>(0))

#endif // 2 <= SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_INVARIANT_LEVEL

#if 3 <= SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_INVARIANT_LEVEL

	#define SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_IS_VALID_3 USER_CLASS_IS_VALID_3
	#define SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_SELF_CLASS_IS_VALID_3 USER_SELF_CLASS_IS_VALID_3

#else // SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_INVARIANT_LEVEL < 3

	#define SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_IS_VALID_3 (static_cast<void>(0))
	#define SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_SELF_CLASS_IS_VALID_3 (static_cast<void>(0))

#endif // 3 <= SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_INVARIANT_LEVEL

#if 4 <= SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_INVARIANT_LEVEL

	#define SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_IS_VALID_4 USER_CLASS_IS_VALID_4
	#define SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_SELF_CLASS_IS_VALID_4 USER_SELF_CLASS_IS_VALID_4

#else // SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_INVARIANT_LEVEL < 4

	#define SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_IS_VALID_4 (static_cast<void>(0))
	#define SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_SELF_CLASS_IS_VALID_4 (static_cast<void>(0))

#endif // 4 <= SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_INVARIANT_LEVEL

#if 5 <= SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_INVARIANT_LEVEL

	#define SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_IS_VALID_5 USER_CLASS_IS_VALID_5
	#define SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_SELF_CLASS_IS_VALID_5 USER_SELF_CLASS_IS_VALID_5

#else // SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_INVARIANT_LEVEL < 5

	#define SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_IS_VALID_5 (static_cast<void>(0))
	#define SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_SELF_CLASS_IS_VALID_5 (static_cast<void>(0))

#endif // 5 <= SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_INVARIANT_LEVEL

#if 6 <= SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_INVARIANT_LEVEL

	#define SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_IS_VALID_6 USER_CLASS_IS_VALID_6
	#define SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_SELF_CLASS_IS_VALID_6 USER_SELF_CLASS_IS_VALID_6

#else // CLASS_INVARIANT_LEVEL < 6

	#define SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_IS_VALID_6 (static_cast<void>(0))
	#define SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_SELF_CLASS_IS_VALID_6 (static_cast<void>(0))

#endif // 6 <= SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_INVARIANT_LEVEL

#if 7 <= SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_INVARIANT_LEVEL

	#define SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_IS_VALID_7 USER_CLASS_IS_VALID_7
	#define SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_SELF_CLASS_IS_VALID_7 USER_SELF_CLASS_IS_VALID_7

#else // SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_INVARIANT_LEVEL < 7

	#define SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_IS_VALID_7 (static_cast<void>(0))
	#define SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_SELF_CLASS_IS_VALID_7 (static_cast<void>(0))

#endif // 7 <= SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_INVARIANT_LEVEL

#if 8 <= SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_INVARIANT_LEVEL

	#define SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_IS_VALID_8 USER_CLASS_IS_VALID_8
	#define SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_SELF_CLASS_IS_VALID_8 USER_SELF_CLASS_IS_VALID_8

#else // SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_INVARIANT_LEVEL < 8

	#define SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_IS_VALID_8 (static_cast<void>(0))
	#define SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_SELF_CLASS_IS_VALID_8 (static_cast<void>(0))

#endif // 8 <= SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_INVARIANT_LEVEL

#if 9 <= SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_INVARIANT_LEVEL

	#define SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_IS_VALID_9 USER_CLASS_IS_VALID_9
	#define SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_SELF_CLASS_IS_VALID_9 USER_SELF_CLASS_IS_VALID_9

#else // SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_INVARIANT_LEVEL < 9

	#define SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_IS_VALID_9 (static_cast<void>(0))
	#define SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_SELF_CLASS_IS_VALID_9 (static_cast<void>(0))

#endif // 9 <= SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_INVARIANT_LEVEL

#if 0 <= SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_INVARIANT_CONST_LEVEL
	#define SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_IS_VALID_CONST_0 USER_CLASS_IS_VALID_CONST_0
#else // SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_INVARIANT_CONST_LEVEL < 0
	#define SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_IS_VALID_CONST_0 (static_cast<void>(0))
#endif // 0 <= SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_INVARIANT_CONST_LEVEL

#if 1 <= SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_INVARIANT_CONST_LEVEL
	#define SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_IS_VALID_CONST_1 USER_CLASS_IS_VALID_CONST_1
#else // SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_INVARIANT_CONST_LEVEL < 1
	#define SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_IS_VALID_CONST_1 (static_cast<void>(0))
#endif // 1 <= SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_INVARIANT_CONST_LEVEL

#if 2 <= SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_INVARIANT_CONST_LEVEL
	#define SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_IS_VALID_CONST_2 USER_CLASS_IS_VALID_CONST_2
#else // SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_INVARIANT_CONST_LEVEL < 2
	#define SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_IS_VALID_CONST_2 (static_cast<void>(0))
#endif // 2 <= SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_INVARIANT_CONST_LEVEL

#if 3 <= SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_INVARIANT_CONST_LEVEL
	#define SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_IS_VALID_CONST_3 USER_CLASS_IS_VALID_CONST_3
#else // SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_INVARIANT_CONST_LEVEL < 3
	#define SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_IS_VALID_CONST_3 (static_cast<void>(0))
#endif // 3 <= SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_INVARIANT_CONST_LEVEL

#if 4 <= SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_INVARIANT_CONST_LEVEL
	#define SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_IS_VALID_CONST_4 USER_CLASS_IS_VALID_CONST_4
#else // SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_INVARIANT_CONST_LEVEL < 4
	#define SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_IS_VALID_CONST_4 (static_cast<void>(0))
#endif // 4 <= SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_INVARIANT_CONST_LEVEL

#if 5 <= SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_INVARIANT_CONST_LEVEL
	#define SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_IS_VALID_CONST_5 USER_CLASS_IS_VALID_CONST_5
#else // SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_INVARIANT_CONST_LEVEL < 5
	#define SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_IS_VALID_CONST_5 (static_cast<void>(0))
#endif // 5 <= SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_INVARIANT_CONST_LEVEL

#if 6 <= SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_INVARIANT_CONST_LEVEL
	#define SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_IS_VALID_CONST_6 USER_CLASS_IS_VALID_CONST_6
#else // SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_INVARIANT_CONST_LEVEL < 6
	#define SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_IS_VALID_CONST_6 (static_cast<void>(0))
#endif // 6 <= SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_INVARIANT_CONST_LEVEL

#if 7 <= SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_INVARIANT_CONST_LEVEL
	#define SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_IS_VALID_CONST_7 USER_CLASS_IS_VALID_CONST_7
#else // SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_INVARIANT_CONST_LEVEL < 7
	#define SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_IS_VALID_CONST_7 (static_cast<void>(0))
#endif // 7 <= SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_INVARIANT_CONST_LEVEL

#if 8 <= SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_INVARIANT_CONST_LEVEL
	#define SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_IS_VALID_CONST_8 USER_CLASS_IS_VALID_CONST_8
#else // SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_INVARIANT_CONST_LEVEL < 8
	#define SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_IS_VALID_CONST_8 (static_cast<void>(0))
#endif // 8 <= SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_INVARIANT_CONST_LEVEL

#if 9 <= SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_INVARIANT_CONST_LEVEL
	#define SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_IS_VALID_CONST_9 USER_CLASS_IS_VALID_CONST_9
#else // SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_INVARIANT_CONST_LEVEL < 9
	#define SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_IS_VALID_CONST_9 (static_cast<void>(0))
#endif // 9 <= SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_INVARIANT_CONST_LEVEL

#endif // SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_HELPER_SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_CLASS_INVARIANT_MACRO_H