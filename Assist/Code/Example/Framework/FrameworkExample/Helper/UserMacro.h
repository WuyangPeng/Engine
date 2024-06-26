///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/31 13:47)

#ifndef FRAMEWORK_EXAMPLE_HELPER_USER_MACRO_H
#define FRAMEWORK_EXAMPLE_HELPER_USER_MACRO_H

#include "Framework/Helper/UserMacro.h"

#define FRAMEWORK_EXAMPLE_ClOSE_BEGIN (0x01)

#define CLOSE_USE_FRAMEWORK_EXAMPLE (FRAMEWORK_EXAMPLE_ClOSE_BEGIN)

#define FRAMEWORK_EXAMPLE_ClOSE_END CLOSE_USE_FRAMEWORK_EXAMPLE

#define CLOSE_FRAMEWORK_EXAMPLE_MAX (((FRAMEWORK_EXAMPLE_ClOSE_END) << 1) - 1)

// 编译测试（默认为0，最大值为0x01）
#define COMPILE_FRAMEWORK_EXAMPLE_CLOSE 0x00

static_assert(0 <= COMPILE_FRAMEWORK_EXAMPLE_CLOSE, "COMPILE_FRAMEWORK_EXAMPLE_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_FRAMEWORK_EXAMPLE_CLOSE <= CLOSE_FRAMEWORK_EXAMPLE_MAX, "COMPILE_FRAMEWORK_EXAMPLE_CLOSE Must be less than or equal CLOSE_FRAMEWORK_EXAMPLE_MAX.");

#if !defined(COMPILE_FRAMEWORK_EXAMPLE_CLOSE) || (COMPILE_FRAMEWORK_EXAMPLE_CLOSE & CLOSE_USE_FRAMEWORK_EXAMPLE) != CLOSE_USE_FRAMEWORK_EXAMPLE

#endif  // !defined(COMPILE_FRAMEWORK_EXAMPLE_CLOSE) || (COMPILE_FRAMEWORK_EXAMPLE_CLOSE & CLOSE_USE_FRAMEWORK_EXAMPLE) != CLOSE_USE_FRAMEWORK_EXAMPLE

#ifdef BUILDING_STATIC

    #define BUILDING_FRAMEWORK_EXAMPLE_STATIC

#endif  // BUILDING_STATIC

#endif  // FRAMEWORK_EXAMPLE_HELPER_USER_MACRO_H
