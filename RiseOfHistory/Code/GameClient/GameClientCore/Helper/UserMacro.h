///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	历史的崛起版本：0.9.0.12 (2023/06/17 12:45)

#ifndef GAME_CLIENT_CORE_HELPER_USER_MACRO_H
#define GAME_CLIENT_CORE_HELPER_USER_MACRO_H

#include "Framework/Helper/UserMacro.h"

#define CLOSE_USE_GAME_CLIENT_CORE (0x01)
#define CLOSE_GAME_CLIENT_CORE_MAX (((CLOSE_USE_GAME_CLIENT_CORE) << 1) - 1)

// 编译测试（默认为0，最大值为0x01）
#define COMPILE_GAME_CLIENT_CORE_CLOSE 0x00

static_assert(0 <= COMPILE_GAME_CLIENT_CORE_CLOSE, "COMPILE_GAME_CLIENT_CORE_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_GAME_CLIENT_CORE_CLOSE <= CLOSE_GAME_CLIENT_CORE_MAX, "COMPILE_GAME_CLIENT_CORE_CLOSE Must be less than or equal CLOSE_GAME_CLIENT_CORE_MAX.");

#if !defined(COMPILE_GAME_CLIENT_CORE_CLOSE) || (COMPILE_GAME_CLIENT_CORE_CLOSE & CLOSE_USE_GAME_CLIENT_CORE) != CLOSE_USE_GAME_CLIENT_CORE

#endif  // !defined(COMPILE_GAME_CLIENT_CORE_CLOSE) || (COMPILE_GAME_CLIENT_CORE_CLOSE & CLOSE_USE_GAME_CLIENT_CORE) != CLOSE_USE_GAME_CLIENT_CORE

#ifdef BUILDING_STATIC

    #define BUILDING_GAME_CLIENT_CORE_STATIC

#endif  // BUILDING_STATIC

#endif  // GAME_CLIENT_CORE_HELPER_USER_MACRO_H
