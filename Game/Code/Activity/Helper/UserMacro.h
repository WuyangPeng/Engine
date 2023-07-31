///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/25 15:18)

#ifndef ACTIVITY_HELPER_USER_HELPER_H
#define ACTIVITY_HELPER_USER_HELPER_H

#include "System/Helper/ConfigMacro.h"
#include "CoreTools/Helper/UserMacro.h"

#define ACTIVITY_CLOSE_BEGIN (0x01)

#define CLOSE_USE_ACTIVITY (ACTIVITY_CLOSE_BEGIN)

#define ACTIVITY_CLOSE_END CLOSE_USE_ACTIVITY

#define CLOSE_ACTIVITY_MAX (((ACTIVITY_CLOSE_END) << 1) - 1)

// ������ԣ�Ĭ��Ϊ0�����ֵΪ0x01��
#define COMPILE_ACTIVITY_CLOSE 0x00

static_assert(0 <= COMPILE_ACTIVITY_CLOSE, "COMPILE_ACTIVITY_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_ACTIVITY_CLOSE <= CLOSE_ACTIVITY_MAX, "COMPILE_ACTIVITY_CLOSE Must be less than or equal CLOSE_ACTIVITY_MAX.");

#if !defined(COMPILE_ACTIVITY_CLOSE) || (COMPILE_ACTIVITY_CLOSE & CLOSE_USE_ACTIVITY) != CLOSE_USE_ACTIVITY

#endif  // !defined(COMPILE_ACTIVITY_CLOSE) || (COMPILE_ACTIVITY_CLOSE & CLOSE_USE_ACTIVITY) != CLOSE_USE_ACTIVITY

#ifdef BUILDING_GAME_STATIC

    #define BUILDING_ACTIVITY_STATIC

#endif  // BUILDING_GAME_STATIC

#endif  // ACTIVITY_HELPER_USER_HELPER_H
