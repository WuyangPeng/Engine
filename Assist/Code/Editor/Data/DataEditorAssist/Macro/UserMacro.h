///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/06 15:26)

#ifndef DATA_EDITOR_MACRO_USER_MACRO_H
#define DATA_EDITOR_MACRO_USER_MACRO_H

#include "System/Helper/ConfigMacro.h"
#include "CoreTools/Helper/UserMacro.h"

#define CLOSE_USE_XXX (0x01)
#define CLOSE_DATA_EDITOR_MAX (((CLOSE_USE_XXX) << 1) - 1)

// ������ԣ�Ĭ��Ϊ0�����ֵΪ0x01��
#define COMPILE_DATA_EDITOR_CLOSE 0x00

static_assert(0 <= COMPILE_DATA_EDITOR_CLOSE, "COMPILE_DATA_EDITOR_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_DATA_EDITOR_CLOSE <= CLOSE_DATA_EDITOR_MAX, "COMPILE_DATA_EDITOR_CLOSE Must be less than or equal CLOSE_DATA_EDITOR_MAX.");

#if !defined(COMPILE_DATA_EDITOR_CLOSE) || (COMPILE_DATA_EDITOR_CLOSE & CLOSE_USE_XXX) != CLOSE_USE_XXX

#endif  // !defined(COMPILE_DATA_EDITOR_CLOSE) || (COMPILE_DATA_EDITOR_CLOSE & CLOSE_USE_XXX) != CLOSE_USE_XXX

// �Ƿ����Ϊ��̬��
#ifdef BUILDING_STATIC
    #define BUILDING_DATA_EDITOR_STATIC
#endif  // BUILDING_STATIC

#endif  // DATA_EDITOR_MACRO_USER_MACRO_H
