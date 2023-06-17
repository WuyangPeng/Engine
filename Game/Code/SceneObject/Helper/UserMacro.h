///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎游戏版本：0.9.0.12 (2023/06/16 16:18)

#ifndef SCENE_OBJECT_HELPER_USER_HELPER_H
#define SCENE_OBJECT_HELPER_USER_HELPER_H

#include "System/Helper/ConfigMacro.h"
#include "CoreTools/Helper/UserMacro.h"

#define CLOSE_USE_XXX (0x01)
#define CLOSE_SCENE_OBJECT_MAX (((CLOSE_USE_XXX) << 1) - 1)

// 编译测试（默认为0，最大值为0x01）
#define COMPILE_SCENE_OBJECT_CLOSE 0x00

static_assert(0 <= COMPILE_SCENE_OBJECT_CLOSE, "COMPILE_SCENE_OBJECT_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_SCENE_OBJECT_CLOSE <= CLOSE_SCENE_OBJECT_MAX, "COMPILE_SCENE_OBJECT_CLOSE Must be less than or equal CLOSE_SCENE_OBJECT_MAX.");

#if !defined(COMPILE_SCENE_OBJECT_CLOSE) || (COMPILE_SCENE_OBJECT_CLOSE & CLOSE_USE_XXX) != CLOSE_USE_XXX

#endif  // !defined(COMPILE_SCENE_OBJECT_CLOSE) || (COMPILE_SCENE_OBJECT_CLOSE & CLOSE_USE_XXX) != CLOSE_USE_XXX

#ifdef BUILDING_GAME_STATIC

    #define BUILDING_SCENE_OBJECT_STATIC

#endif  // BUILDING_GAME_STATIC

#endif  // SCENE_OBJECT_HELPER_USER_HELPER_H
