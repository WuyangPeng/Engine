///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.5 (2021/10/28 22:20)

#ifndef CONCURRENT_PROGRAMMING_ON_WINDOWS_HELPER_USER_MACRO_H
#define CONCURRENT_PROGRAMMING_ON_WINDOWS_HELPER_USER_MACRO_H

#include "Framework/Helper/UserMacro.h"

#define CONCURRENT_PROGRAMMING_ON_WINDOWS_ClOSE_BEGIN (0x01)

#define CLOSE_USE_CONCURRENT_PROGRAMMING_ON_WINDOWS (CONCURRENT_PROGRAMMING_ON_WINDOWS_ClOSE_BEGIN)

#define CONCURRENT_PROGRAMMING_ON_WINDOWS_ClOSE_END CLOSE_USE_CONCURRENT_PROGRAMMING_ON_WINDOWS

#define CLOSE_CONCURRENT_PROGRAMMING_ON_WINDOWS_MAX ((CONCURRENT_PROGRAMMING_ON_WINDOWS_ClOSE_END << 1) - 1)

// 编译测试（默认为0，最大值为0x01）
#define COMPILE_CONCURRENT_PROGRAMMING_ON_WINDOWS_CLOSE 0x00

static_assert(0 <= COMPILE_CONCURRENT_PROGRAMMING_ON_WINDOWS_CLOSE, "COMPILE_CONCURRENT_PROGRAMMING_ON_WINDOWS_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_CONCURRENT_PROGRAMMING_ON_WINDOWS_CLOSE <= CLOSE_CONCURRENT_PROGRAMMING_ON_WINDOWS_MAX, "COMPILE_CONCURRENT_PROGRAMMING_ON_WINDOWS_CLOSE Must be less than or equal CLOSE_CONCURRENT_PROGRAMMING_ON_WINDOWS_MAX.");

#if !defined(COMPILE_CONCURRENT_PROGRAMMING_ON_WINDOWS_CLOSE) || (COMPILE_CONCURRENT_PROGRAMMING_ON_WINDOWS_CLOSE & CLOSE_USE_CONCURRENT_PROGRAMMING_ON_WINDOWS) != CLOSE_USE_CONCURRENT_PROGRAMMING_ON_WINDOWS

#endif  // !defined(COMPILE_CONCURRENT_PROGRAMMING_ON_WINDOWS_CLOSE) || (COMPILE_CONCURRENT_PROGRAMMING_ON_WINDOWS_CLOSE & CLOSE_USE_CONCURRENT_PROGRAMMING_ON_WINDOWS) != CLOSE_USE_CONCURRENT_PROGRAMMING_ON_WINDOWS

#ifdef BUILDING_STATIC
    #define BUILDING_CONCURRENT_PROGRAMMING_ON_WINDOWS_STATIC
#endif  // BUILDING_STATIC

#endif  // CONCURRENT_PROGRAMMING_ON_WINDOWS_HELPER_USER_MACRO_H
