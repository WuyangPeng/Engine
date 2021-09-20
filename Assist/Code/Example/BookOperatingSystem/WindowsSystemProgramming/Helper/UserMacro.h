///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.3 (2021/05/12 16:57)

#ifndef WINDOWS_SYSTEM_PROGRAMMING_MACRO_USER_MACRO_H
#define WINDOWS_SYSTEM_PROGRAMMING_MACRO_USER_MACRO_H

#include "Framework/Helper/UserMacro.h"

#define WINDOWS_SYSTEM_PROGRAMMING_ClOSE_BEGIN (0x01)

#define CLOSE_USE_WINDOWS_SYSTEM_PROGRAMMING (WINDOWS_SYSTEM_PROGRAMMING_ClOSE_BEGIN)

#define WINDOWS_SYSTEM_PROGRAMMING_ClOSE_END CLOSE_USE_WINDOWS_SYSTEM_PROGRAMMING

#define CLOSE_WINDOWS_SYSTEM_PROGRAMMING_MAX ((WINDOWS_SYSTEM_PROGRAMMING_ClOSE_END << 1) - 1)

// ������ԣ�Ĭ��Ϊ0�����ֵΪ0x01��
#define COMPILE_WINDOWS_SYSTEM_PROGRAMMING_CLOSE 0x00

static_assert(0 <= COMPILE_WINDOWS_SYSTEM_PROGRAMMING_CLOSE, "COMPILE_WINDOWS_SYSTEM_PROGRAMMING_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_WINDOWS_SYSTEM_PROGRAMMING_CLOSE <= CLOSE_WINDOWS_SYSTEM_PROGRAMMING_MAX, "COMPILE_WINDOWS_SYSTEM_PROGRAMMING_CLOSE Must be less than or equal CLOSE_WINDOWS_SYSTEM_PROGRAMMING_MAX.");

#if !defined(COMPILE_WINDOWS_SYSTEM_PROGRAMMING_CLOSE) || (COMPILE_WINDOWS_SYSTEM_PROGRAMMING_CLOSE & CLOSE_USE_WINDOWS_SYSTEM_PROGRAMMING) != CLOSE_USE_WINDOWS_SYSTEM_PROGRAMMING

#endif  // !defined(COMPILE_WINDOWS_SYSTEM_PROGRAMMING_CLOSE) || (COMPILE_WINDOWS_SYSTEM_PROGRAMMING_CLOSE & CLOSE_USE_WINDOWS_SYSTEM_PROGRAMMING) != CLOSE_USE_WINDOWS_SYSTEM_PROGRAMMING

// �Ƿ����Ϊ��̬��
#ifdef BUILDING_STATIC
    #define BUILDING_WINDOWS_SYSTEM_PROGRAMMING_STATIC
#endif  // BUILDING_STATIC

#endif  // WINDOWS_SYSTEM_PROGRAMMING_MACRO_USER_MACRO_H