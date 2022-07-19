///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������Ϸ�汾��0.8.0.11 (2022/07/19 14:05)

#ifndef INSTANCE_HELPER_USER_HELPER_H
#define INSTANCE_HELPER_USER_HELPER_H

#include "System/Helper/ConfigMacro.h"
#include "CoreTools/Helper/UserMacro.h"

#define CLOSE_USE_XXX (0x01)
#define CLOSE_INSTANCE_MAX (((CLOSE_USE_XXX) << 1) - 1)

// ������ԣ�Ĭ��Ϊ0�����ֵΪ0x01��
#define COMPILE_INSTANCE_CLOSE 0x00

static_assert(0 <= COMPILE_INSTANCE_CLOSE, "COMPILE_INSTANCE_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_INSTANCE_CLOSE <= CLOSE_INSTANCE_MAX, "COMPILE_INSTANCE_CLOSE Must be less than or equal CLOSE_INSTANCE_MAX.");

// �Ƿ����Ϊ��̬��
#ifdef BUILDING_GAME_STATIC
    #define BUILDING_INSTANCE_STATIC
#endif  // BUILDING_GAME_STATIC

#if !defined(COMPILE_INSTANCE_CLOSE) || (COMPILE_INSTANCE_CLOSE & CLOSE_USE_XXX) != CLOSE_USE_XXX

#endif  // !defined(COMPILE_INSTANCE_CLOSE) || (COMPILE_INSTANCE_CLOSE & CLOSE_USE_XXX) != CLOSE_USE_XXX

#endif  // INSTANCE_HELPER_USER_HELPER_H
