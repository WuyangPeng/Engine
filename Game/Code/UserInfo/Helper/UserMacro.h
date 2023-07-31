///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/25 16:57)

#ifndef USER_INFO_HELPER_USER_HELPER_H
#define USER_INFO_HELPER_USER_HELPER_H

#include "System/Helper/ConfigMacro.h"
#include "CoreTools/Helper/UserMacro.h"

#define USER_INFO_CLOSE_BEGIN (0x01)

#define CLOSE_USE_USER_INFO (USER_INFO_CLOSE_BEGIN)

#define USER_INFO_CLOSE_END CLOSE_USE_USER_INFO

#define CLOSE_USER_INFO_MAX (((USER_INFO_CLOSE_END) << 1) - 1)

// ������ԣ�Ĭ��Ϊ0�����ֵΪ0x01��
#define COMPILE_USER_INFO_CLOSE 0x00

static_assert(0 <= COMPILE_USER_INFO_CLOSE, "COMPILE_USER_INFO_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_USER_INFO_CLOSE <= CLOSE_USER_INFO_MAX, "COMPILE_USER_INFO_CLOSE Must be less than or equal CLOSE_USER_INFO_MAX.");

#if !defined(COMPILE_USER_INFO_CLOSE) || (COMPILE_USER_INFO_CLOSE & CLOSE_USE_USER_INFO) != CLOSE_USE_USER_INFO

#endif  // !defined(COMPILE_USER_INFO_CLOSE) || (COMPILE_USER_INFO_CLOSE & CLOSE_USE_USER_INFO) != CLOSE_USE_USER_INFO

#ifdef BUILDING_GAME_STATIC

    #define BUILDING_USER_INFO_STATIC

#endif  // BUILDING_GAME_STATIC

#endif  // USER_INFO_HELPER_USER_HELPER_H
