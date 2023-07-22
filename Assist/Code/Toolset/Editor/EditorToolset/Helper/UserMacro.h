///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.12 (2023/06/15 18:16)

#ifndef EDITOR_HELPER_USER_MACRO_H
#define EDITOR_HELPER_USER_MACRO_H

#include "System/Helper/ConfigMacro.h"
#include "CoreTools/Helper/UserMacro.h"

#define CLOSE_USE_XXX (0x01)
#define CLOSE_EDITOR_MAX (((CLOSE_USE_XXX) << 1) - 1)

// ������ԣ�Ĭ��Ϊ0�����ֵΪ0x01��
#define COMPILE_EDITOR_CLOSE 0x00

static_assert(0 <= COMPILE_EDITOR_CLOSE, "COMPILE_EDITOR_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_EDITOR_CLOSE <= CLOSE_EDITOR_MAX, "COMPILE_EDITOR_CLOSE Must be less than or equal CLOSE_EDITOR_MAX.");

#if !defined(COMPILE_EDITOR_CLOSE) || (COMPILE_EDITOR_CLOSE & CLOSE_USE_XXX) != CLOSE_USE_XXX

#endif  // !defined(COMPILE_EDITOR_CLOSE) || (COMPILE_EDITOR_CLOSE & CLOSE_USE_XXX) != CLOSE_USE_XXX

// �Ƿ����Ϊ��̬��
#ifdef BUILDING_STATIC

    #define BUILDING_EDITOR_STATIC

#endif  // BUILDING_STATIC

#endif  // EDITOR_HELPER_USER_MACRO_H