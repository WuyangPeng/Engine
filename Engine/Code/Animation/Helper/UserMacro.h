///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/01 19:56)

#ifndef ANIMATION_MACRO_USER_MACRO_H
#define ANIMATION_MACRO_USER_MACRO_H

#include "System/Helper/ConfigMacro.h"
#include "CoreTools/Helper/UserMacro.h"
#include "Mathematics/Helper/UserMacro.h"

#define ANIMATION_ClOSE_BEGIN (0x01)

#define CLOSE_USE_ANIMATION (ANIMATION_ClOSE_BEGIN)

#define ANIMATION_ClOSE_END CLOSE_USE_ANIMATION

#define CLOSE_ANIMATION_MAX (((ANIMATION_ClOSE_END) << 1) - 1)

// 编译测试（默认为0，最大值为0x01）
#define COMPILE_ANIMATION_CLOSE 0x00

static_assert(0 <= COMPILE_ANIMATION_CLOSE, "COMPILE_ANIMATION_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_ANIMATION_CLOSE <= CLOSE_ANIMATION_MAX, "COMPILE_ANIMATION_CLOSE Must be less than or equal CLOSE_ANIMATION_MAX.");

#if !defined(COMPILE_ANIMATION_CLOSE) || (COMPILE_ANIMATION_CLOSE & CLOSE_USE_ANIMATION) != CLOSE_USE_ANIMATION

#endif  // !defined(COMPILE_ANIMATION_CLOSE) || (COMPILE_ANIMATION_CLOSE & CLOSE_USE_ANIMATION) != CLOSE_USE_ANIMATION

#ifdef BUILDING_STATIC

    #define BUILDING_ANIMATION_STATIC

#endif  // BUILDING_STATIC

#endif  // ANIMATION_MACRO_USER_MACRO_H
