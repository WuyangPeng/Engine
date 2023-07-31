///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/25 15:37)

#ifndef GUILD_HELPER_USER_HELPER_H
#define GUILD_HELPER_USER_HELPER_H

#include "System/Helper/ConfigMacro.h"
#include "CoreTools/Helper/UserMacro.h"

#define GUILD_CLOSE_BEGIN (0x01)

#define CLOSE_USE_GUILD (GUILD_CLOSE_BEGIN)

#define GUILD_CLOSE_END CLOSE_USE_GUILD

#define CLOSE_GUILD_MAX (((GUILD_CLOSE_END) << 1) - 1)

// 编译测试（默认为0，最大值为0x01）
#define COMPILE_GUILD_CLOSE 0x00

static_assert(0 <= COMPILE_GUILD_CLOSE, "COMPILE_GUILD_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_GUILD_CLOSE <= CLOSE_GUILD_MAX, "COMPILE_GUILD_CLOSE Must be less than or equal CLOSE_GUILD_MAX.");

#if !defined(COMPILE_GUILD_CLOSE) || (COMPILE_GUILD_CLOSE & CLOSE_USE_GUILD) != CLOSE_USE_GUILD

#endif  // !defined(COMPILE_GUILD_CLOSE) || (COMPILE_GUILD_CLOSE & CLOSE_USE_GUILD) != CLOSE_USE_GUILD

#ifdef BUILDING_GAME_STATIC

    #define BUILDING_GUILD_STATIC

#endif  // BUILDING_GAME_STATIC

#endif  // GUILD_HELPER_USER_HELPER_H
