///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/25 15:55)

#ifndef INTERFACE_HELPER_USER_HELPER_H
#define INTERFACE_HELPER_USER_HELPER_H

#include "System/Helper/ConfigMacro.h"
#include "CoreTools/Helper/UserMacro.h"

#define INTERFACE_CLOSE_BEGIN (0x01)

#define CLOSE_USE_INTERFACE (INTERFACE_CLOSE_BEGIN)

#define INTERFACE_CLOSE_END CLOSE_USE_INTERFACE

#define CLOSE_INTERFACE_MAX (((INTERFACE_CLOSE_END) << 1) - 1)

// ������ԣ�Ĭ��Ϊ0�����ֵΪ0x01��
#define COMPILE_INTERFACE_CLOSE 0x00

static_assert(0 <= COMPILE_INTERFACE_CLOSE, "COMPILE_INTERFACE_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_INTERFACE_CLOSE <= CLOSE_INTERFACE_MAX, "COMPILE_INTERFACE_CLOSE Must be less than or equal CLOSE_INTERFACE_MAX.");

#if !defined(COMPILE_INTERFACE_CLOSE) || (COMPILE_INTERFACE_CLOSE & CLOSE_USE_INTERFACE) != CLOSE_USE_INTERFACE

#endif  // !defined(COMPILE_INTERFACE_CLOSE) || (COMPILE_INTERFACE_CLOSE & CLOSE_USE_INTERFACE) != CLOSE_USE_INTERFACE

#ifdef BUILDING_GAME_STATIC

    #define BUILDING_INTERFACE_STATIC

#endif  // BUILDING_GAME_STATIC

#endif  // INTERFACE_HELPER_USER_HELPER_H
