///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/14 16:56)

#ifndef ASSIST_TOOLS_MACRO_USER_MACRO_H
#define ASSIST_TOOLS_MACRO_USER_MACRO_H

#include "System/Helper/ConfigMacro.h"
#include "CoreTools/Helper/UserMacro.h"
#include "Mathematics/Helper/UserMacro.h"

#define ASSIST_TOOLS_ClOSE_BEGIN (0x01)

#define CLOSE_USE_ASSIST_TOOLS (ASSIST_TOOLS_ClOSE_BEGIN)

#define ASSIST_TOOLS_ClOSE_END CLOSE_USE_ASSIST_TOOLS

#define CLOSE_ASSIST_TOOLS_MAX (((ASSIST_TOOLS_ClOSE_END) << 1) - 1)

// 编译测试（默认为0，最大值为0x01）
#define COMPILE_ASSIST_TOOLS_CLOSE 0x00

static_assert(0 <= COMPILE_ASSIST_TOOLS_CLOSE, "COMPILE_ASSIST_TOOLS_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_ASSIST_TOOLS_CLOSE <= CLOSE_ASSIST_TOOLS_MAX, "COMPILE_ASSIST_TOOLS_CLOSE Must be less than or equal CLOSE_ASSIST_TOOLS_MAX.");

#if !defined(COMPILE_ASSIST_TOOLS_CLOSE) || (COMPILE_ASSIST_TOOLS_CLOSE & CLOSE_USE_ASSIST_TOOLS) != CLOSE_USE_ASSIST_TOOLS

#endif  // !defined(COMPILE_ASSIST_TOOLS_CLOSE) || (COMPILE_ASSIST_TOOLS_CLOSE & CLOSE_USE_ASSIST_TOOLS) != CLOSE_USE_ASSIST_TOOLS

#ifdef BUILDING_STATIC

    #define BUILDING_ASSIST_TOOLS_STATIC

#endif  // BUILDING_STATIC

#endif  // ASSIST_TOOLS_MACRO_USER_MACRO_H
