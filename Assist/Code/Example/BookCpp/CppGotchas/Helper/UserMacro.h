///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.6.0.1 (2021/01/08 21:29)

#ifndef CPP_GOTCHAS_HELPER_USER_MACRO_H
#define CPP_GOTCHAS_HELPER_USER_MACRO_H

#include "Framework/Helper/UserMacro.h"

#define CPP_GOTCHAS_ClOSE_BEGIN (0x01)

#define CLOSE_USE_CPP_GOTCHAS (CPP_GOTCHAS_ClOSE_BEGIN)

#define CPP_GOTCHAS_ClOSE_END CLOSE_USE_CPP_GOTCHAS

#define CLOSE_CPP_GOTCHAS_MAX ((CPP_GOTCHAS_ClOSE_END << 1) - 1)

// ������ԣ�Ĭ��Ϊ0�����ֵΪ0x01��
#define COMPILE_CPP_GOTCHAS_CLOSE 0x00

static_assert(0 <= COMPILE_CPP_GOTCHAS_CLOSE, "COMPILE_CPP_GOTCHAS_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_CPP_GOTCHAS_CLOSE <= CLOSE_CPP_GOTCHAS_MAX, "COMPILE_CPP_GOTCHAS_CLOSE Must be less than or equal CLOSE_CPP_GOTCHAS_MAX.");

#if !defined(COMPILE_CPP_GOTCHAS_CLOSE) || (COMPILE_CPP_GOTCHAS_CLOSE & CLOSE_USE_CPP_GOTCHAS) != CLOSE_USE_CPP_GOTCHAS

#endif  // !defined(COMPILE_CPP_GOTCHAS_CLOSE) || (COMPILE_CPP_GOTCHAS_CLOSE & CLOSE_USE_CPP_GOTCHAS) != CLOSE_USE_CPP_GOTCHAS

// �Ƿ����Ϊ��̬��
#ifdef BUILDING_STATIC
    #define BUILDING_CPP_GOTCHAS_STATIC
#endif  // BUILDING_STATIC

#endif  // CPP_GOTCHAS_HELPER_USER_MACRO_H
