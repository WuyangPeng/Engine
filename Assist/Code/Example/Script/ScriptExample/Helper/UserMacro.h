///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.11 (2023/05/29 15:37)

#ifndef SCRIPT_EXAMPLE_HELPER_USER_MACRO_H
#define SCRIPT_EXAMPLE_HELPER_USER_MACRO_H

#include "System/Helper/ConfigMacro.h"
#include "CoreTools/Helper/UserMacro.h"

#define CLOSE_USE_XXX (0x01)
#define CLOSE_SCRIPT_EXAMPLE_MAX (((CLOSE_USE_XXX) << 1) - 1)

// ������ԣ�Ĭ��Ϊ0�����ֵΪ0x01��
#define COMPILE_SCRIPT_EXAMPLE_CLOSE 0x00

static_assert(0 <= COMPILE_SCRIPT_EXAMPLE_CLOSE, "COMPILE_SCRIPT_EXAMPLE_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_SCRIPT_EXAMPLE_CLOSE <= CLOSE_SCRIPT_EXAMPLE_MAX, "COMPILE_SCRIPT_EXAMPLE_CLOSE Must be less than or equal CLOSE_SCRIPT_EXAMPLE_MAX.");

#if !defined(COMPILE_SCRIPT_EXAMPLE_CLOSE) || (COMPILE_SCRIPT_EXAMPLE_CLOSE & CLOSE_USE_XXX) != CLOSE_USE_XXX

#endif  // !defined(COMPILE_SCRIPT_EXAMPLE_CLOSE) || (COMPILE_SCRIPT_EXAMPLE_CLOSE & CLOSE_USE_XXX) != CLOSE_USE_XXX

#ifdef BUILDING_STATIC

    #define BUILDING_SCRIPT_EXAMPLE_STATIC

#endif  // BUILDING_STATIC

#endif  // SCRIPT_EXAMPLE_HELPER_USER_MACRO_H
