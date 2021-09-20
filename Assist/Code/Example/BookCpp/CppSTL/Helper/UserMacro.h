///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.0 (2021/02/27 12:45)

#ifndef CPP_STL_HELPER_USER_MACRO_H
#define CPP_STL_HELPER_USER_MACRO_H

#include "Framework/Helper/UserMacro.h"

#define CPP_STL_ClOSE_BEGIN (0x01)

#define CLOSE_USE_CPP_STL (CPP_STL_ClOSE_BEGIN)

#define CPP_STL_ClOSE_END CLOSE_USE_CPP_STL

#define CLOSE_CPP_STL_MAX ((CPP_STL_ClOSE_END << 1) - 1)

// ������ԣ�Ĭ��Ϊ0�����ֵΪ0x01��
#define COMPILE_CPP_STL_CLOSE 0x00

static_assert(0 <= COMPILE_CPP_STL_CLOSE, "COMPILE_CPP_STL_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_CPP_STL_CLOSE <= CLOSE_CPP_STL_MAX, "COMPILE_CPP_STL_CLOSE Must be less than or equal CLOSE_CPP_STL_MAX.");

#if !defined(COMPILE_CPP_STL_CLOSE) || (COMPILE_CPP_STL_CLOSE & CLOSE_USE_CPP_STL) != CLOSE_USE_CPP_STL

#endif  // !defined(COMPILE_CPP_STL_CLOSE) || (COMPILE_CPP_STL_CLOSE & CLOSE_USE_CPP_STL) != CLOSE_USE_CPP_STL

// �Ƿ����Ϊ��̬��
#ifdef BUILDING_STATIC
    #define BUILDING_CPP_STL_STATIC
#endif  // BUILDING_STATIC

#endif  // CPP_STL_HELPER_USER_MACRO_H
