///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.1 (2021/07/28 15:24)

#ifndef CORE_TOOLS_EXAMPLE_HELPER_USER_MACRO_H
#define CORE_TOOLS_EXAMPLE_HELPER_USER_MACRO_H

#include "System/Helper/UserMacro.h"

#define CORE_TOOLS_EXAMPLE_ClOSE_BEGIN (0x01)

#define CLOSE_USE_CORE_TOOLS_EXAMPLE (CORE_TOOLS_EXAMPLE_ClOSE_BEGIN)

#define CORE_TOOLS_EXAMPLE_ClOSE_END CLOSE_USE_CORE_TOOLS_EXAMPLE

#define CLOSE_CORE_TOOLS_EXAMPLE_MAX ((CORE_TOOLS_EXAMPLE_ClOSE_END << 1) - 1)

// ������ԣ�Ĭ��Ϊ0x00�����ֵΪ0x01��
#define COMPILE_CORE_TOOLS_EXAMPLE_CLOSE 0x00

static_assert(0 <= COMPILE_CORE_TOOLS_EXAMPLE_CLOSE, "COMPILE_CORE_TOOLS_EXAMPLE_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_CORE_TOOLS_EXAMPLE_CLOSE <= CLOSE_CORE_TOOLS_EXAMPLE_MAX, "COMPILE_CORE_TOOLS_EXAMPLE_CLOSE Must be less than or equal CLOSE_CORE_TOOLS_EXAMPLE_MAX.");

#if !defined(COMPILE_CORE_TOOLS_EXAMPLE_CLOSE) || (COMPILE_CORE_TOOLS_EXAMPLE_CLOSE & CLOSE_USE_CORE_TOOLS_EXAMPLE) != CLOSE_USE_CORE_TOOLS_EXAMPLE

#endif  // !defined(COMPILE_CORE_TOOLS_EXAMPLE_CLOSE) || (COMPILE_CORE_TOOLS_EXAMPLE_CLOSE & CLOSE_USE_CORE_TOOLS_EXAMPLE) != CLOSE_USE_CORE_TOOLS_EXAMPLE

// �Ƿ����Ϊ��̬��
#ifdef BUILDING_STATIC
    #define BUILDING_CORE_TOOLS_EXAMPLE_STATIC
#endif  // BUILDING_STATIC

#endif  // CORE_TOOLS_EXAMPLE_HELPER_USER_MACRO_H
