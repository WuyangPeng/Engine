///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/04/28 16:21)

#ifndef ASSIST_TOOLS_MACRO_USER_MACRO_H
#define ASSIST_TOOLS_MACRO_USER_MACRO_H

#include "System/Helper/ConfigMacro.h"
#include "CoreTools/Helper/UserMacro.h"
#include "Mathematics/Helper/UserMacro.h"

#define CLOSE_USE_XXX (0x01)
#define CLOSE_ASSIST_TOOLS_MAX (((CLOSE_USE_XXX) << 1) - 1)

// 编译测试（默认为0，最大值为0x01）
#define COMPILE_ASSIST_TOOLS_CLOSE 0x00

static_assert(0 <= COMPILE_ASSIST_TOOLS_CLOSE, "COMPILE_ASSIST_TOOLS_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_ASSIST_TOOLS_CLOSE <= CLOSE_ASSIST_TOOLS_MAX, "COMPILE_ASSIST_TOOLS_CLOSE Must be less than or equal CLOSE_ASSIST_TOOLS_MAX.");

#if !defined(COMPILE_ASSIST_TOOLS_CLOSE) || (COMPILE_ASSIST_TOOLS_CLOSE & CLOSE_USE_XXX) != CLOSE_USE_XXX

#endif  // !defined(COMPILE_ASSIST_TOOLS_CLOSE) || (COMPILE_ASSIST_TOOLS_CLOSE & CLOSE_USE_XXX) != CLOSE_USE_XXX

// 是否编译为静态库
#ifdef BUILDING_STATIC
    #define BUILDING_ASSIST_TOOLS_STATIC
#endif  // BUILDING_STATIC

#endif  // ASSIST_TOOLS_MACRO_USER_MACRO_H
