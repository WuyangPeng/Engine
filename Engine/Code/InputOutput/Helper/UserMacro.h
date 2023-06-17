///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/09 19:51)

#ifndef INPUT_OUTPUT_MACRO_USER_MACRO_H
#define INPUT_OUTPUT_MACRO_USER_MACRO_H

#include "CoreTools/Helper/UserMacro.h"

#define CLOSE_USE_X (0x01)
#define CLOSE_INPUT_OUTPUT_MAX (((CLOSE_USE_X) << 1) - 1)

// ������ԣ�Ĭ��Ϊ0�����ֵΪ0x01��
#define COMPILE_INPUT_OUTPUT_CLOSE 0x00

static_assert(0 <= COMPILE_INPUT_OUTPUT_CLOSE, "COMPILE_INPUT_OUTPUT_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_INPUT_OUTPUT_CLOSE <= CLOSE_INPUT_OUTPUT_MAX, "COMPILE_INPUT_OUTPUT_CLOSE Must be less than or equal CLOSE_INPUT_OUTPUT_MAX.");

#if !defined(COMPILE_INPUT_OUTPUT_CLOSE) || (COMPILE_INPUT_OUTPUT_CLOSE & CLOSE_USE_X) != CLOSE_USE_X
    #define INPUT_OUTPUT_USE_X
#endif  // !defined(COMPILE_INPUT_OUTPUT_CLOSE) || (COMPILE_INPUT_OUTPUT_CLOSE & CLOSE_USE_X) != CLOSE_USE_X

#ifdef BUILDING_STATIC

    #define BUILDING_INPUT_OUTPUT_STATIC

#endif  // BUILDING_STATIC

#endif  // INPUT_OUTPUT_MACRO_USER_MACRO_H
