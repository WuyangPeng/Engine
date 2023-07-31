///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/25 15:22)

#ifndef ARENA_HELPER_USER_HELPER_H
#define ARENA_HELPER_USER_HELPER_H

#include "System/Helper/ConfigMacro.h"
#include "CoreTools/Helper/UserMacro.h"

#define ARENA_CLOSE_BEGIN (0x01)

#define CLOSE_USE_ARENA (ARENA_CLOSE_BEGIN)

#define ARENA_CLOSE_END CLOSE_USE_ARENA

#define CLOSE_ARENA_MAX (((ARENA_CLOSE_END) << 1) - 1)

// ������ԣ�Ĭ��Ϊ0�����ֵΪ0x01��
#define COMPILE_ARENA_CLOSE 0x00

static_assert(0 <= COMPILE_ARENA_CLOSE, "COMPILE_ARENA_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_ARENA_CLOSE <= CLOSE_ARENA_MAX, "COMPILE_ARENA_CLOSE Must be less than or equal CLOSE_ARENA_MAX.");

#if !defined(COMPILE_ARENA_CLOSE) || (COMPILE_ARENA_CLOSE & CLOSE_USE_ARENA) != CLOSE_USE_ARENA

#endif  // !defined(COMPILE_ARENA_CLOSE) || (COMPILE_ARENA_CLOSE & CLOSE_USE_ARENA) != CLOSE_USE_ARENA

#ifdef BUILDING_GAME_STATIC

    #define BUILDING_ARENA_STATIC

#endif  // BUILDING_GAME_STATIC

#endif  // ARENA_HELPER_USER_HELPER_H
