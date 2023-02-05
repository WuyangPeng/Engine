///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	历史的崛起版本：0.8.1.0 (2022/08/03 11:21)

#ifndef GAME_CLIENT_MIDDLE_LAYER_HELPER_USER_MACRO_H
#define GAME_CLIENT_MIDDLE_LAYER_HELPER_USER_MACRO_H

#include "Framework/Helper/UserMacro.h"

#define CLOSE_USE_XXX (0x01)
#define CLOSE_GAME_CLIENT_MIDDLE_LAYER_MAX (((CLOSE_USE_XXX) << 1) - 1)

// 编译测试（默认为0，最大值为0x01）
#define COMPILE_GAME_CLIENT_MIDDLE_LAYER_CLOSE 0x00

static_assert(0 <= COMPILE_GAME_CLIENT_MIDDLE_LAYER_CLOSE, "COMPILE_GAME_CLIENT_MIDDLE_LAYER_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_GAME_CLIENT_MIDDLE_LAYER_CLOSE <= CLOSE_GAME_CLIENT_MIDDLE_LAYER_MAX, "COMPILE_GAME_CLIENT_MIDDLE_LAYER_CLOSE Must be less than or equal CLOSE_GAME_CLIENT_MIDDLE_LAYER_MAX.");

#if !defined(COMPILE_GAME_CLIENT_MIDDLE_LAYER_CLOSE) || (COMPILE_GAME_CLIENT_MIDDLE_LAYER_CLOSE & CLOSE_USE_XXX) != CLOSE_USE_XXX

#endif  // !defined(COMPILE_GAME_CLIENT_MIDDLE_LAYER_CLOSE) || (COMPILE_GAME_CLIENT_MIDDLE_LAYER_CLOSE & CLOSE_USE_XXX) != CLOSE_USE_XXX

// 是否编译成静态库
#ifdef BUILDING_STATIC
    #define BUILDING_GAME_CLIENT_MIDDLE_LAYER_STATIC
#endif  // BUILDING_STATIC

#endif  // GAME_CLIENT_MIDDLE_LAYER_HELPER_USER_MACRO_H
