/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/10 19:41)

#ifndef ANIMATION_MACRO_USER_MACRO_H
#define ANIMATION_MACRO_USER_MACRO_H

#include "System/Helper/ConfigMacro.h"
#include "CoreTools/Helper/UserMacro.h"
#include "Mathematics/Helper/UserMacro.h"

#define ANIMATION_ClOSE_BEGIN (0x01)

#define CLOSE_USE_ANIMATION (ANIMATION_ClOSE_BEGIN)

#define ANIMATION_ClOSE_END CLOSE_USE_ANIMATION

#define CLOSE_ANIMATION_MAX (((ANIMATION_ClOSE_END) << 1) - 1)

// 编译测试（默认为0B0000，最大值为0B0001）
#define COMPILE_ANIMATION_CLOSE 0B0000

static_assert(0 <= COMPILE_ANIMATION_CLOSE, "COMPILE_ANIMATION_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_ANIMATION_CLOSE <= CLOSE_ANIMATION_MAX, "COMPILE_ANIMATION_CLOSE Must be less than or equal CLOSE_ANIMATION_MAX.");

#if !defined(COMPILE_ANIMATION_CLOSE) || (COMPILE_ANIMATION_CLOSE & CLOSE_USE_ANIMATION) != CLOSE_USE_ANIMATION

#endif  // !defined(COMPILE_ANIMATION_CLOSE) || (COMPILE_ANIMATION_CLOSE & CLOSE_USE_ANIMATION) != CLOSE_USE_ANIMATION

#ifdef BUILDING_STATIC

    #define BUILDING_ANIMATION_STATIC

#endif  // BUILDING_STATIC

#endif  // ANIMATION_MACRO_USER_MACRO_H
