///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.6.0.1 (2021/01/08 21:29)

#ifndef RUMINATIONS_ON_CPP_HELPER_USER_MACRO_H
#define RUMINATIONS_ON_CPP_HELPER_USER_MACRO_H

#include "Framework/Helper/UserMacro.h"

#define RUMINATIONS_ON_CPP_ClOSE_BEGIN (0x01)

#define CLOSE_USE_RUMINATIONS_ON_CPP (RUMINATIONS_ON_CPP_ClOSE_BEGIN)

#define RUMINATIONS_ON_CPP_ClOSE_END CLOSE_USE_RUMINATIONS_ON_CPP

#define CLOSE_RUMINATIONS_ON_CPP_MAX ((RUMINATIONS_ON_CPP_ClOSE_END << 1) - 1)

// ������ԣ�Ĭ��Ϊ0�����ֵΪ0x01��
#define COMPILE_RUMINATIONS_ON_CPP_CLOSE 0x00

static_assert(0 <= COMPILE_RUMINATIONS_ON_CPP_CLOSE, "COMPILE_RUMINATIONS_ON_CPP_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_RUMINATIONS_ON_CPP_CLOSE <= CLOSE_RUMINATIONS_ON_CPP_MAX, "COMPILE_RUMINATIONS_ON_CPP_CLOSE Must be less than or equal CLOSE_RUMINATIONS_ON_CPP_MAX.");

#if !defined(COMPILE_RUMINATIONS_ON_CPP_CLOSE) || (COMPILE_RUMINATIONS_ON_CPP_CLOSE & CLOSE_USE_RUMINATIONS_ON_CPP) != CLOSE_USE_RUMINATIONS_ON_CPP

#endif  // !defined(COMPILE_RUMINATIONS_ON_CPP_CLOSE) || (COMPILE_RUMINATIONS_ON_CPP_CLOSE & CLOSE_USE_RUMINATIONS_ON_CPP) != CLOSE_USE_RUMINATIONS_ON_CPP

// �Ƿ����Ϊ��̬��
#ifdef BUILDING_STATIC
    #define BUILDING_RUMINATIONS_ON_CPP_STATIC
#endif  // BUILDING_STATIC

#endif  // RUMINATIONS_ON_CPP_HELPER_USER_MACRO_H