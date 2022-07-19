///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������Ϸ�汾��0.8.0.11 (2022/07/15 11:07)

#ifndef ITEM_MANAGER_HELPER_USER_HELPER_H
#define ITEM_MANAGER_HELPER_USER_HELPER_H

#include "System/Helper/ConfigMacro.h"
#include "CoreTools/Helper/UserMacro.h"

#define CLOSE_USE_XXX (0x01)
#define CLOSE_ITEM_MANAGER_MAX (((CLOSE_USE_XXX) << 1) - 1)

// ������ԣ�Ĭ��Ϊ0�����ֵΪ0x01��
#define COMPILE_ITEM_MANAGER_CLOSE 0x00

static_assert(0 <= COMPILE_ITEM_MANAGER_CLOSE, "COMPILE_ITEM_MANAGER_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_ITEM_MANAGER_CLOSE <= CLOSE_ITEM_MANAGER_MAX, "COMPILE_ITEM_MANAGER_CLOSE Must be less than or equal CLOSE_ITEM_MANAGER_MAX.");

// �Ƿ����Ϊ��̬��
#ifdef BUILDING_GAME_STATIC
    #define BUILDING_ITEM_MANAGER_STATIC
#endif  // BUILDING_GAME_STATIC

#if !defined(COMPILE_ITEM_MANAGER_CLOSE) || (COMPILE_ITEM_MANAGER_CLOSE & CLOSE_USE_XXX) != CLOSE_USE_XXX

#endif  // !defined(COMPILE_ITEM_MANAGER_CLOSE) || (COMPILE_ITEM_MANAGER_CLOSE & CLOSE_USE_XXX) != CLOSE_USE_XXX

#endif  // ITEM_MANAGER_HELPER_USER_HELPER_H
