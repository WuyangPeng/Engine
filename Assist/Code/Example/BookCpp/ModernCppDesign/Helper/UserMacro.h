///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.1 (2021/03/11 17:53)

#ifndef MODERN_CPP_DESIGN_HELPER_USER_MACRO_H
#define MODERN_CPP_DESIGN_HELPER_USER_MACRO_H

#include "Framework/Helper/UserMacro.h"

#define MODERN_CPP_DESIGN_ClOSE_BEGIN (0x01)

#define CLOSE_USE_MODERN_CPP_DESIGN (MODERN_CPP_DESIGN_ClOSE_BEGIN)

#define MODERN_CPP_DESIGN_ClOSE_END CLOSE_USE_MODERN_CPP_DESIGN

#define CLOSE_MODERN_CPP_DESIGN_MAX ((MODERN_CPP_DESIGN_ClOSE_END << 1) - 1)

// ������ԣ�Ĭ��Ϊ0�����ֵΪ0x01��
#define COMPILE_MODERN_CPP_DESIGN_CLOSE 0x00

static_assert(0 <= COMPILE_MODERN_CPP_DESIGN_CLOSE, "COMPILE_MODERN_CPP_DESIGN_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_MODERN_CPP_DESIGN_CLOSE <= CLOSE_MODERN_CPP_DESIGN_MAX, "COMPILE_MODERN_CPP_DESIGN_CLOSE Must be less than or equal CLOSE_MODERN_CPP_DESIGN_MAX.");

#if !defined(COMPILE_MODERN_CPP_DESIGN_CLOSE) || (COMPILE_MODERN_CPP_DESIGN_CLOSE & CLOSE_USE_MODERN_CPP_DESIGN) != CLOSE_USE_MODERN_CPP_DESIGN

#endif  // !defined(COMPILE_MODERN_CPP_DESIGN_CLOSE) || (COMPILE_MODERN_CPP_DESIGN_CLOSE & CLOSE_USE_MODERN_CPP_DESIGN) != CLOSE_USE_MODERN_CPP_DESIGN

// �Ƿ����Ϊ��̬��
#ifdef BUILDING_STATIC
    #define BUILDING_MODERN_CPP_DESIGN_STATIC
#endif  // BUILDING_STATIC

#endif  // MODERN_CPP_DESIGN_HELPER_USER_MACRO_H