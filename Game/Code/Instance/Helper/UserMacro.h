///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/25 15:49)

#ifndef INSTANCE_HELPER_USER_HELPER_H
#define INSTANCE_HELPER_USER_HELPER_H

#include "System/Helper/ConfigMacro.h"
#include "CoreTools/Helper/UserMacro.h"

#define INSTANCE_CLOSE_BEGIN (0x01)

#define CLOSE_USE_INSTANCE (INSTANCE_CLOSE_BEGIN)

#define INSTANCE_CLOSE_END CLOSE_USE_INSTANCE

#define CLOSE_INSTANCE_MAX (((INSTANCE_CLOSE_END) << 1) - 1)

// ������ԣ�Ĭ��Ϊ0�����ֵΪ0x01��
#define COMPILE_INSTANCE_CLOSE 0x00

static_assert(0 <= COMPILE_INSTANCE_CLOSE, "COMPILE_INSTANCE_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_INSTANCE_CLOSE <= CLOSE_INSTANCE_MAX, "COMPILE_INSTANCE_CLOSE Must be less than or equal CLOSE_INSTANCE_MAX.");

#if !defined(COMPILE_INSTANCE_CLOSE) || (COMPILE_INSTANCE_CLOSE & CLOSE_USE_INSTANCE) != CLOSE_USE_INSTANCE

#endif  // !defined(COMPILE_INSTANCE_CLOSE) || (COMPILE_INSTANCE_CLOSE & CLOSE_USE_INSTANCE) != CLOSE_USE_INSTANCE

#ifdef BUILDING_GAME_STATIC

    #define BUILDING_INSTANCE_STATIC

#endif  // BUILDING_GAME_STATIC

#endif  // INSTANCE_HELPER_USER_HELPER_H
