///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.0 (2021/02/16 17:46)

#ifndef CPP_CODING_STANDARDS_HELPER_USER_MACRO_H
#define CPP_CODING_STANDARDS_HELPER_USER_MACRO_H

#include "Framework/Helper/UserMacro.h"

#define CPP_CODING_STANDARDS_ClOSE_BEGIN (0x01)

#define CLOSE_USE_CPP_CODING_STANDARDS (CPP_CODING_STANDARDS_ClOSE_BEGIN)

#define CPP_CODING_STANDARDS_ClOSE_END CLOSE_USE_CPP_CODING_STANDARDS

#define CLOSE_CPP_CODING_STANDARDS_MAX ((CPP_CODING_STANDARDS_ClOSE_END << 1) - 1)

// ������ԣ�Ĭ��Ϊ0�����ֵΪ0x01��
#define COMPILE_CPP_CODING_STANDARDS_CLOSE 0x00

static_assert(0 <= COMPILE_CPP_CODING_STANDARDS_CLOSE, "COMPILE_CPP_CODING_STANDARDS_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_CPP_CODING_STANDARDS_CLOSE <= CLOSE_CPP_CODING_STANDARDS_MAX, "COMPILE_CPP_CODING_STANDARDS_CLOSE Must be less than or equal CLOSE_CPP_CODING_STANDARDS_MAX.");

#if !defined(COMPILE_CPP_CODING_STANDARDS_CLOSE) || (COMPILE_CPP_CODING_STANDARDS_CLOSE & CLOSE_USE_CPP_CODING_STANDARDS) != CLOSE_USE_CPP_CODING_STANDARDS

#endif  // !defined(COMPILE_CPP_CODING_STANDARDS_CLOSE) || (COMPILE_CPP_CODING_STANDARDS_CLOSE & CLOSE_USE_CPP_CODING_STANDARDS) != CLOSE_USE_CPP_CODING_STANDARDS

// �Ƿ����Ϊ��̬��
#ifdef BUILDING_STATIC
    #define BUILDING_CPP_CODING_STANDARDS_STATIC
#endif  // BUILDING_STATIC

#endif  // CPP_CODING_STANDARDS_HELPER_USER_MACRO_H
