///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������Ϸ�汾��0.8.0.11 (2022/07/19 11:23)

#ifndef ARENA_HELPER_USER_HELPER_H
#define ARENA_HELPER_USER_HELPER_H

#include "System/Helper/ConfigMacro.h"
#include "CoreTools/Helper/UserMacro.h"

#define CLOSE_USE_XXX (0x01)
#define CLOSE_ARENA_MAX (((CLOSE_USE_XXX) << 1) - 1)

// ������ԣ�Ĭ��Ϊ0�����ֵΪ0x01��
#define COMPILE_ARENA_CLOSE 0x00

static_assert(0 <= COMPILE_ARENA_CLOSE, "COMPILE_ARENA_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_ARENA_CLOSE <= CLOSE_ARENA_MAX, "COMPILE_ARENA_CLOSE Must be less than or equal CLOSE_ARENA_MAX.");

// �Ƿ����Ϊ��̬��
#ifdef BUILDING_GAME_STATIC
    #define BUILDING_ARENA_STATIC
#endif  // BUILDING_GAME_STATIC

#if !defined(COMPILE_ARENA_CLOSE) || (COMPILE_ARENA_CLOSE & CLOSE_USE_XXX) != CLOSE_USE_XXX

#endif  // !defined(COMPILE_ARENA_CLOSE) || (COMPILE_ARENA_CLOSE & CLOSE_USE_XXX) != CLOSE_USE_XXX

#endif  // ARENA_HELPER_USER_HELPER_H
