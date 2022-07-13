///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/12 13:57)

#ifndef IMAGICS_EXAMPLE_MACRO_USER_MACRO_H
#define IMAGICS_EXAMPLE_MACRO_USER_MACRO_H

#include "System/Helper/ConfigMacro.h"
#include "CoreTools/Helper/UserMacro.h"

#define CLOSE_USE_XXX (0x01)
#define CLOSE_IMAGICS_EXAMPLE_MAX (((CLOSE_USE_XXX) << 1) - 1)

// ������ԣ�Ĭ��Ϊ0�����ֵΪ0x01��
#define COMPILE_IMAGICS_EXAMPLE_CLOSE 0x00

static_assert(0 <= COMPILE_IMAGICS_EXAMPLE_CLOSE, "COMPILE_IMAGICS_EXAMPLE_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_IMAGICS_EXAMPLE_CLOSE <= CLOSE_IMAGICS_EXAMPLE_MAX, "COMPILE_IMAGICS_EXAMPLE_CLOSE Must be less than or equal CLOSE_IMAGICS_EXAMPLE_MAX.");

// �Ƿ����Ϊ��̬��
#ifdef BUILDING_STATIC
    #define BUILDING_IMAGICS_EXAMPLE_STATIC
#endif  // BUILDING_STATIC

#if !defined(COMPILE_IMAGICS_EXAMPLE_CLOSE) || (COMPILE_IMAGICS_EXAMPLE_CLOSE & CLOSE_USE_XXX) != CLOSE_USE_XXX

#endif  // !defined(COMPILE_IMAGICS_EXAMPLE_CLOSE) || (COMPILE_IMAGICS_EXAMPLE_CLOSE & CLOSE_USE_XXX) != CLOSE_USE_XXX

#endif  // IMAGICS_EXAMPLE_MACRO_USER_MACRO_H
