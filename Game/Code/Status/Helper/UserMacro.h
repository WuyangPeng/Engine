///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������Ϸ�汾��0.8.0.11 (2022/07/18 14:35)

#ifndef STATUSHELPER_USER_HELPER_H
#define STATUSHELPER_USER_HELPER_H

#include "System/Helper/ConfigMacro.h"
#include "CoreTools/Helper/UserMacro.h"

#define CLOSE_USE_XXX (0x01)
#define CLOSE_STATUSMAX (((CLOSE_USE_XXX) << 1) - 1)

// ������ԣ�Ĭ��Ϊ0�����ֵΪ0x01��
#define COMPILE_STATUSCLOSE 0x00

static_assert(0 <= COMPILE_STATUSCLOSE, "COMPILE_STATUSCLOSE Must be greater than or equal 0.");
static_assert(COMPILE_STATUSCLOSE <= CLOSE_STATUSMAX, "COMPILE_STATUSCLOSE Must be less than or equal CLOSE_STATUSMAX.");

// �Ƿ����Ϊ��̬��
#ifdef BUILDING_GAME_STATIC
    #define BUILDING_STATUSSTATIC
#endif  // BUILDING_GAME_STATIC

#if !defined(COMPILE_STATUSCLOSE) || (COMPILE_STATUSCLOSE & CLOSE_USE_XXX) != CLOSE_USE_XXX

#endif  // !defined(COMPILE_STATUSCLOSE) || (COMPILE_STATUSCLOSE & CLOSE_USE_XXX) != CLOSE_USE_XXX

#endif  // STATUSHELPER_USER_HELPER_H
