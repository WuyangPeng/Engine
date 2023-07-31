///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/25 16:51)

#ifndef TEAM_HELPER_USER_HELPER_H
#define TEAM_HELPER_USER_HELPER_H

#include "System/Helper/ConfigMacro.h"
#include "CoreTools/Helper/UserMacro.h"

#define TEAM_CLOSE_BEGIN (0x01)

#define CLOSE_USE_TEAM (TEAM_CLOSE_BEGIN)

#define TEAM_CLOSE_END CLOSE_USE_TEAM

#define CLOSE_TEAM_MAX (((TEAM_CLOSE_END) << 1) - 1)

// 编译测试（默认为0，最大值为0x01）
#define COMPILE_TEAM_CLOSE 0x00

static_assert(0 <= COMPILE_TEAM_CLOSE, "COMPILE_TEAM_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_TEAM_CLOSE <= CLOSE_TEAM_MAX, "COMPILE_TEAM_CLOSE Must be less than or equal CLOSE_TEAM_MAX.");

#if !defined(COMPILE_TEAM_CLOSE) || (COMPILE_TEAM_CLOSE & CLOSE_USE_TEAM) != CLOSE_USE_TEAM

#endif  // !defined(COMPILE_TEAM_CLOSE) || (COMPILE_TEAM_CLOSE & CLOSE_USE_TEAM) != CLOSE_USE_TEAM

#ifdef BUILDING_GAME_STATIC

    #define BUILDING_TEAM_STATIC

#endif  // BUILDING_GAME_STATIC

#endif  // TEAM_HELPER_USER_HELPER_H
