///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.11 (2023/05/29 15:04)

#ifndef SCRIPT_MACRO_USER_MACRO_H
#define SCRIPT_MACRO_USER_MACRO_H

#include "CoreTools/Helper/UserMacro.h"

#define SCRIPT_CLOSE_BEGIN (0x01)

#define CLOSE_USE_LUA (SCRIPT_CLOSE_BEGIN)
#define CLOSE_USE_JAVA (SCRIPT_CLOSE_BEGIN << 1)
#define CLOSE_USE_PERL (SCRIPT_CLOSE_BEGIN << 2)
#define CLOSE_USE_PYTHON (SCRIPT_CLOSE_BEGIN << 3)

#define SCRIPT_CLOSE_END CLOSE_USE_PYTHON

#define CLOSE_SCRIPT_MAX (((SCRIPT_CLOSE_END) << 1) - 1)

// ������ԣ�Ĭ��Ϊ0�����ֵΪ0x0F��
#define COMPILE_SCRIPT_CLOSE 0x00

static_assert(0 <= COMPILE_SCRIPT_CLOSE, "COMPILE_SCRIPT_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_SCRIPT_CLOSE <= CLOSE_SCRIPT_MAX, "COMPILE_SCRIPT_CLOSE Must be less than or equal CLOSE_SCRIPT_MAX.");

#if !defined(COMPILE_SCRIPT_CLOSE) || (COMPILE_SCRIPT_CLOSE & CLOSE_USE_LUA) != CLOSE_USE_LUA

    #define SCRIPT_USE_LUA static_cast<void>(0)

#endif  // !defined(COMPILE_SCRIPT_CLOSE) || (COMPILE_SCRIPT_CLOSE & CLOSE_USE_LUA) != CLOSE_USE_LUA

#if !defined(COMPILE_SCRIPT_CLOSE) || (COMPILE_SCRIPT_CLOSE & CLOSE_USE_JAVA) != CLOSE_USE_JAVA

    #define SCRIPT_USE_JAVA static_cast<void>(0)

#endif  // !defined(COMPILE_SCRIPT_CLOSE) || (COMPILE_SCRIPT_CLOSE & CLOSE_USE_JAVA) != CLOSE_USE_JAVA

#if !defined(COMPILE_SCRIPT_CLOSE) || (COMPILE_SCRIPT_CLOSE & CLOSE_USE_PERL) != CLOSE_USE_PERL

    #define SCRIPT_USE_PERL static_cast<void>(0)

#endif  // !defined(COMPILE_SCRIPT_CLOSE) || (COMPILE_SCRIPT_CLOSE & CLOSE_USE_PERL) != CLOSE_USE_PERL

#if !defined(COMPILE_SCRIPT_CLOSE) || (COMPILE_SCRIPT_CLOSE & CLOSE_USE_PYTHON) != CLOSE_USE_PYTHON

    #define SCRIPT_USE_PYTHON static_cast<void>(0)

#endif  // !defined(COMPILE_SCRIPT_CLOSE) || (COMPILE_SCRIPT_CLOSE & CLOSE_USE_PYTHON) != CLOSE_USE_PYTHON

#ifdef BUILDING_STATIC

    #define BUILDING_SCRIPT_STATIC static_cast<void>(0)

#endif  // BUILDING_STATIC

#endif  // SCRIPT_MACRO_USER_MACRO_H
