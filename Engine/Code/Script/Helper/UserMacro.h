///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.2 (2020/11/06 10:08)

#ifndef SCRIPT_MACRO_USER_MACRO_H
#define SCRIPT_MACRO_USER_MACRO_H

#include "CoreTools/Helper/UserMacro.h"

#define SCRIPT_ClOSE_BEGIN (0x01)

#define CLOSE_USE_LUA (SCRIPT_ClOSE_BEGIN)

#define SCRIPT_ClOSE_END CLOSE_USE_LUA

#define CLOSE_SCRIPT_MAX (((SCRIPT_ClOSE_END) << 1) - 1)

// ������ԣ�Ĭ��Ϊ0�����ֵΪ0x01��
#define COMPILE_SCRIPT_CLOSE 0x00

static_assert(0 <= COMPILE_SCRIPT_CLOSE, "COMPILE_SCRIPT_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_SCRIPT_CLOSE <= CLOSE_SCRIPT_MAX, "COMPILE_SCRIPT_CLOSE Must be less than or equal CLOSE_SCRIPT_MAX.");

#if !defined(COMPILE_SCRIPT_CLOSE) || (COMPILE_SCRIPT_CLOSE & CLOSE_USE_LUA) != CLOSE_USE_LUA
    #define SCRIPT_USE_LUA static_cast<void>(0)
#endif  // !defined(COMPILE_SCRIPT_CLOSE) || (COMPILE_SCRIPT_CLOSE & CLOSE_USE_LUA) != CLOSE_USE_LUA

// �Ƿ����Ϊ��̬��
#ifdef BUILDING_STATIC
    #define BUILDING_SCRIPT_STATIC static_cast<void>(0)
#endif  // BUILDING_STATIC

#endif  // SCRIPT_MACRO_USER_MACRO_H
