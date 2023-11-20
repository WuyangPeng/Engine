/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.0 (2023/11/19 00:20)

#ifndef BACKGROUND_CLIENT_CORE_HELPER_USER_MACRO_H
#define BACKGROUND_CLIENT_CORE_HELPER_USER_MACRO_H

#include "Framework/Helper/UserMacro.h"

#define BACKGROUND_CLIENT_CORE_ClOSE_BEGIN (0x01)

#define CLOSE_USE_BACKGROUND_CLIENT_CORE (BACKGROUND_CLIENT_CORE_ClOSE_BEGIN)

#define BACKGROUND_CLIENT_CORE_ClOSE_END CLOSE_USE_BACKGROUND_CLIENT_CORE

#define CLOSE_BACKGROUND_CLIENT_CORE_MAX (((BACKGROUND_CLIENT_CORE_ClOSE_END) << 1) - 1)

// 编译测试（默认为0，最大值为0x01）
#define COMPILE_BACKGROUND_CLIENT_CORE_CLOSE 0x00

static_assert(0 <= COMPILE_BACKGROUND_CLIENT_CORE_CLOSE, "COMPILE_BACKGROUND_CLIENT_CORE_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_BACKGROUND_CLIENT_CORE_CLOSE <= CLOSE_BACKGROUND_CLIENT_CORE_MAX, "COMPILE_BACKGROUND_CLIENT_CORE_CLOSE Must be less than or equal CLOSE_BACKGROUND_CLIENT_CORE_MAX.");

#if !defined(COMPILE_BACKGROUND_CLIENT_CORE_CLOSE) || (COMPILE_BACKGROUND_CLIENT_CORE_CLOSE & CLOSE_USE_BACKGROUND_CLIENT_CORE) != CLOSE_USE_BACKGROUND_CLIENT_CORE

#endif  // !defined(COMPILE_BACKGROUND_CLIENT_CORE_CLOSE) || (COMPILE_BACKGROUND_CLIENT_CORE_CLOSE & CLOSE_USE_BACKGROUND_CLIENT_CORE) != CLOSE_USE_BACKGROUND_CLIENT_CORE

#ifdef BUILDING_STATIC

    #define BUILDING_BACKGROUND_CLIENT_CORE_STATIC (static_cast<void>(0))

#endif  // BUILDING_STATIC

#endif  // BACKGROUND_CLIENT_CORE_HELPER_USER_MACRO_H
