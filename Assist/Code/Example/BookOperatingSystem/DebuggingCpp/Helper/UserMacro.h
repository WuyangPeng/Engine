///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.4 (2021/10/07 23:22)

#ifndef DEBUGGING_CPP_HELPER_USER_MACRO_H
#define DEBUGGING_CPP_HELPER_USER_MACRO_H

#include "Framework/Helper/UserMacro.h"

#define DEBUGGING_CPP_ClOSE_BEGIN (0x01)

#define CLOSE_USE_DEBUGGING_CPP (DEBUGGING_CPP_ClOSE_BEGIN)

#define DEBUGGING_CPP_ClOSE_END CLOSE_USE_DEBUGGING_CPP

#define CLOSE_DEBUGGING_CPP_MAX ((DEBUGGING_CPP_ClOSE_END << 1) - 1)

// ������ԣ�Ĭ��Ϊ0�����ֵΪ0x01��
#define COMPILE_DEBUGGING_CPP_CLOSE 0x00

static_assert(0 <= COMPILE_DEBUGGING_CPP_CLOSE, "COMPILE_DEBUGGING_CPP_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_DEBUGGING_CPP_CLOSE <= CLOSE_DEBUGGING_CPP_MAX, "COMPILE_DEBUGGING_CPP_CLOSE Must be less than or equal CLOSE_DEBUGGING_CPP_MAX.");

#if !defined(COMPILE_DEBUGGING_CPP_CLOSE) || (COMPILE_DEBUGGING_CPP_CLOSE & CLOSE_USE_DEBUGGING_CPP) != CLOSE_USE_DEBUGGING_CPP

#endif  // !defined(COMPILE_DEBUGGING_CPP_CLOSE) || (COMPILE_DEBUGGING_CPP_CLOSE & CLOSE_USE_DEBUGGING_CPP) != CLOSE_USE_DEBUGGING_CPP

#ifdef BUILDING_STATIC
    #define BUILDING_DEBUGGING_CPP_STATIC
#endif  // BUILDING_STATIC

#endif  // DEBUGGING_CPP_HELPER_USER_MACRO_H