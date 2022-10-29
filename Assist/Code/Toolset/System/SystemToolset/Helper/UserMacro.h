///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.1.3 (2022/10/24 22:42)

#ifndef SYSTEM_TOOLSET_HELPER_USER_MACRO_H
#define SYSTEM_TOOLSET_HELPER_USER_MACRO_H

#include "System/Helper/UserMacro.h"

#define SYSTEM_TOOLSET_ClOSE_BEGIN (0x01)

#define CLOSE_USE_SYSTEM_TOOLSET (SYSTEM_TOOLSET_ClOSE_BEGIN)

#define SYSTEM_TOOLSET_ClOSE_END CLOSE_USE_SYSTEM_TOOLSET

#define CLOSE_SYSTEM_TOOLSET_MAX ((SYSTEM_TOOLSET_ClOSE_END << 1) - 1)

// 编译测试（默认为0，最大值为0x01）
#define COMPILE_SYSTEM_TOOLSET_CLOSE 0x00

static_assert(0 <= COMPILE_SYSTEM_TOOLSET_CLOSE, "COMPILE_SYSTEM_TOOLSET_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_SYSTEM_TOOLSET_CLOSE <= CLOSE_SYSTEM_TOOLSET_MAX, "COMPILE_SYSTEM_TOOLSET_CLOSE Must be less than or equal CLOSE_SYSTEM_TOOLSET_MAX.");

#if !defined(COMPILE_SYSTEM_TOOLSET_CLOSE) || (COMPILE_SYSTEM_TOOLSET_CLOSE & CLOSE_USE_SYSTEM_TOOLSET) != CLOSE_USE_SYSTEM_TOOLSET

#endif  // !defined(COMPILE_SYSTEM_TOOLSET_CLOSE) || (COMPILE_SYSTEM_TOOLSET_CLOSE & CLOSE_USE_SYSTEM_TOOLSET) != CLOSE_USE_SYSTEM_TOOLSET

#ifdef BUILDING_STATIC
    #define BUILDING_SYSTEM_TOOLSET_STATIC
#endif  // BUILDING_STATIC

#endif  // SYSTEM_TOOLSET_HELPER_USER_MACRO_H
