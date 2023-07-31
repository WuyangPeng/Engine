///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/25 16:22)

#ifndef SHOP_HELPER_USER_HELPER_H
#define SHOP_HELPER_USER_HELPER_H

#include "System/Helper/ConfigMacro.h"
#include "CoreTools/Helper/UserMacro.h"

#define SHOP_CLOSE_BEGIN (0x01)

#define CLOSE_USE_SHOP (SHOP_CLOSE_BEGIN)

#define SHOP_CLOSE_END CLOSE_USE_SHOP

#define CLOSE_SHOP_MAX (((SHOP_CLOSE_END) << 1) - 1)

// 编译测试（默认为0，最大值为0x01）
#define COMPILE_SHOP_CLOSE 0x00

static_assert(0 <= COMPILE_SHOP_CLOSE, "COMPILE_SHOP_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_SHOP_CLOSE <= CLOSE_SHOP_MAX, "COMPILE_SHOP_CLOSE Must be less than or equal CLOSE_SHOP_MAX.");

#if !defined(COMPILE_SHOP_CLOSE) || (COMPILE_SHOP_CLOSE & CLOSE_USE_SHOP) != CLOSE_USE_SHOP

#endif  // !defined(COMPILE_SHOP_CLOSE) || (COMPILE_SHOP_CLOSE & CLOSE_USE_SHOP) != CLOSE_USE_SHOP

#ifdef BUILDING_GAME_STATIC

    #define BUILDING_SHOP_STATIC

#endif  // BUILDING_GAME_STATIC

#endif  // SHOP_HELPER_USER_HELPER_H
