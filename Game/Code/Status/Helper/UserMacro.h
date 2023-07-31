///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/25 16:27)

#ifndef STATUS_HELPER_USER_HELPER_H
#define STATUS_HELPER_USER_HELPER_H

#include "System/Helper/ConfigMacro.h"
#include "CoreTools/Helper/UserMacro.h"

#define STATUS_CLOSE_BEGIN (0x01)

#define CLOSE_USE_STATUS (STATUS_CLOSE_BEGIN)

#define STATUS_CLOSE_END CLOSE_USE_STATUS

#define CLOSE_STATUS_MAX (((STATUS_CLOSE_END) << 1) - 1)

// 编译测试（默认为0，最大值为0x01）
#define COMPILE_STATUS_CLOSE 0x00

static_assert(0 <= COMPILE_STATUS_CLOSE, "COMPILE_STATUS_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_STATUS_CLOSE <= CLOSE_STATUS_MAX, "COMPILE_STATUS_CLOSE Must be less than or equal CLOSE_STATUS_MAX.");

#if !defined(COMPILE_STATUS_CLOSE) || (COMPILE_STATUS_CLOSE & CLOSE_USE_STATUS) != CLOSE_USE_STATUS

#endif  // !defined(COMPILE_STATUS_CLOSE) || (COMPILE_STATUS_CLOSE & CLOSE_USE_STATUS) != CLOSE_USE_STATUS

#ifdef BUILDING_GAME_STATIC

    #define BUILDING_STATUS_STATIC

#endif  // BUILDING_GAME_STATIC

#endif  // STATUS_HELPER_USER_HELPER_H
