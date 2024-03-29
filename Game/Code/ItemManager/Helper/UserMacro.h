///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/25 16:00)

#ifndef ITEM_MANAGER_HELPER_USER_HELPER_H
#define ITEM_MANAGER_HELPER_USER_HELPER_H

#include "System/Helper/ConfigMacro.h"
#include "CoreTools/Helper/UserMacro.h"

#define ITEM_MANAGER_CLOSE_BEGIN (0x01)

#define CLOSE_USE_ITEM_MANAGER (ITEM_MANAGER_CLOSE_BEGIN)

#define ITEM_MANAGER_CLOSE_END CLOSE_USE_ITEM_MANAGER

#define CLOSE_ITEM_MANAGER_MAX (((ITEM_MANAGER_CLOSE_END) << 1) - 1)

// 编译测试（默认为0，最大值为0x01）
#define COMPILE_ITEM_MANAGER_CLOSE 0x00

static_assert(0 <= COMPILE_ITEM_MANAGER_CLOSE, "COMPILE_ITEM_MANAGER_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_ITEM_MANAGER_CLOSE <= CLOSE_ITEM_MANAGER_MAX, "COMPILE_ITEM_MANAGER_CLOSE Must be less than or equal CLOSE_ITEM_MANAGER_MAX.");

#if !defined(COMPILE_ITEM_MANAGER_CLOSE) || (COMPILE_ITEM_MANAGER_CLOSE & CLOSE_USE_ITEM_MANAGER) != CLOSE_USE_ITEM_MANAGER

#endif  // !defined(COMPILE_ITEM_MANAGER_CLOSE) || (COMPILE_ITEM_MANAGER_CLOSE & CLOSE_USE_ITEM_MANAGER) != CLOSE_USE_ITEM_MANAGER

#ifdef BUILDING_GAME_STATIC

    #define BUILDING_ITEM_MANAGER_STATIC

#endif  // BUILDING_GAME_STATIC

#endif  // ITEM_MANAGER_HELPER_USER_HELPER_H
