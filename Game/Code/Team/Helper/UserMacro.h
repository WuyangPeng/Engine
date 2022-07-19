///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎游戏版本：0.8.0.11 (2022/07/18 17:12)

#ifndef TEAM_HELPER_USER_HELPER_H
#define TEAM_HELPER_USER_HELPER_H

#include "System/Helper/ConfigMacro.h"
#include "CoreTools/Helper/UserMacro.h"

#define CLOSE_USE_XXX (0x01)
#define CLOSE_TEAM_MAX (((CLOSE_USE_XXX) << 1) - 1)

// 编译测试（默认为0，最大值为0x01）
#define COMPILE_TEAM_CLOSE 0x00

static_assert(0 <= COMPILE_TEAM_CLOSE, "COMPILE_TEAM_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_TEAM_CLOSE <= CLOSE_TEAM_MAX, "COMPILE_TEAM_CLOSE Must be less than or equal CLOSE_TEAM_MAX.");

// 是否编译为静态库
#ifdef BUILDING_GAME_STATIC
    #define BUILDING_TEAM_STATIC
#endif  // BUILDING_GAME_STATIC

#if !defined(COMPILE_TEAM_CLOSE) || (COMPILE_TEAM_CLOSE & CLOSE_USE_XXX) != CLOSE_USE_XXX

#endif  // !defined(COMPILE_TEAM_CLOSE) || (COMPILE_TEAM_CLOSE & CLOSE_USE_XXX) != CLOSE_USE_XXX

#endif  // TEAM_HELPER_USER_HELPER_H
