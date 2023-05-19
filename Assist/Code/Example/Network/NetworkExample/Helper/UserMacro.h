///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.8 (2023/05/10 18:21)

#ifndef NETWORK_EXAMPLE_MACRO_USER_MACRO_H
#define NETWORK_EXAMPLE_MACRO_USER_MACRO_H

#include "System/Helper/ConfigMacro.h"
#include "CoreTools/Helper/UserMacro.h"

#define CLOSE_USE_XXX (0x01)
#define CLOSE_NETWORK_EXAMPLE_MAX (((CLOSE_USE_XXX) << 1) - 1)

// ������ԣ�Ĭ��Ϊ0�����ֵΪ0x01��
#define COMPILE_NETWORK_EXAMPLE_CLOSE 0x00

static_assert(0 <= COMPILE_NETWORK_EXAMPLE_CLOSE, "COMPILE_NETWORK_EXAMPLE_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_NETWORK_EXAMPLE_CLOSE <= CLOSE_NETWORK_EXAMPLE_MAX, "COMPILE_NETWORK_EXAMPLE_CLOSE Must be less than or equal CLOSE_NETWORK_EXAMPLE_MAX.");

#if !defined(COMPILE_NETWORK_EXAMPLE_CLOSE) || (COMPILE_NETWORK_EXAMPLE_CLOSE & CLOSE_USE_XXX) != CLOSE_USE_XXX

#endif  // !defined(COMPILE_NETWORK_EXAMPLE_CLOSE) || (COMPILE_NETWORK_EXAMPLE_CLOSE & CLOSE_USE_XXX) != CLOSE_USE_XXX

#ifdef BUILDING_STATIC

    #define BUILDING_NETWORK_EXAMPLE_STATIC

#endif  // BUILDING_STATIC

#endif  // NETWORK_EXAMPLE_MACRO_USER_MACRO_H
