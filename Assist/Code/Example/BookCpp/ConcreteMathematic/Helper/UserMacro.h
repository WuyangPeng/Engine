///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.0.1 (2021/02/09 14:57)

#ifndef CONCRETE_MATHEMATIC_HELPER_USER_MACRO_H
#define CONCRETE_MATHEMATIC_HELPER_USER_MACRO_H

#include "Framework/Helper/UserMacro.h"

#define CONCRETE_MATHEMATIC_ClOSE_BEGIN (0x01)

#define CLOSE_USE_CONCRETE_MATHEMATIC (CONCRETE_MATHEMATIC_ClOSE_BEGIN)

#define CONCRETE_MATHEMATIC_ClOSE_END CLOSE_USE_CONCRETE_MATHEMATIC

#define CLOSE_CONCRETE_MATHEMATIC_MAX ((CONCRETE_MATHEMATIC_ClOSE_END << 1) - 1)

// ������ԣ�Ĭ��Ϊ0�����ֵΪ0x01��
#define COMPILE_CONCRETE_MATHEMATIC_CLOSE 0x00

static_assert(0 <= COMPILE_CONCRETE_MATHEMATIC_CLOSE, "COMPILE_CONCRETE_MATHEMATIC_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_CONCRETE_MATHEMATIC_CLOSE <= CLOSE_CONCRETE_MATHEMATIC_MAX, "COMPILE_CONCRETE_MATHEMATIC_CLOSE Must be less than or equal CLOSE_CONCRETE_MATHEMATIC_MAX.");

#if !defined(COMPILE_CONCRETE_MATHEMATIC_CLOSE) || (COMPILE_CONCRETE_MATHEMATIC_CLOSE & CLOSE_USE_CONCRETE_MATHEMATIC) != CLOSE_USE_CONCRETE_MATHEMATIC

#endif  // !defined(COMPILE_CONCRETE_MATHEMATIC_CLOSE) || (COMPILE_CONCRETE_MATHEMATIC_CLOSE & CLOSE_USE_CONCRETE_MATHEMATIC) != CLOSE_USE_CONCRETE_MATHEMATIC

// �Ƿ����Ϊ��̬��
#ifdef BUILDING_STATIC
    #define BUILDING_CONCRETE_MATHEMATIC_STATIC
#endif  // BUILDING_STATIC

#endif  // CONCRETE_MATHEMATIC_HELPER_USER_MACRO_H