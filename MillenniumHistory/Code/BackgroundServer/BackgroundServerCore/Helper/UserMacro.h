/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/25 20:42)

#ifndef BACKGROUND_SERVER_CORE_HELPER_USER_MACRO_H
#define BACKGROUND_SERVER_CORE_HELPER_USER_MACRO_H

#include "Framework/Helper/UserMacro.h"

#define BACKGROUND_SERVER_CORE_ClOSE_BEGIN (0x01)

#define CLOSE_USE_BACKGROUND_SERVER_CORE (BACKGROUND_SERVER_CORE_ClOSE_BEGIN)

#define BACKGROUND_SERVER_CORE_ClOSE_END CLOSE_USE_BACKGROUND_SERVER_CORE

#define CLOSE_BACKGROUND_SERVER_CORE_MAX (((BACKGROUND_SERVER_CORE_ClOSE_END) << 1) - 1)

// 编译测试（默认为0B0000，最大值为0B0001）
#define COMPILE_BACKGROUND_SERVER_CORE_CLOSE 0B0000

static_assert(0 <= COMPILE_BACKGROUND_SERVER_CORE_CLOSE, "COMPILE_BACKGROUND_SERVER_CORE_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_BACKGROUND_SERVER_CORE_CLOSE <= CLOSE_BACKGROUND_SERVER_CORE_MAX, "COMPILE_BACKGROUND_SERVER_CORE_CLOSE Must be less than or equal CLOSE_BACKGROUND_SERVER_CORE_MAX.");

#if !defined(COMPILE_BACKGROUND_SERVER_CORE_CLOSE) || (COMPILE_BACKGROUND_SERVER_CORE_CLOSE & CLOSE_USE_BACKGROUND_SERVER_CORE) != CLOSE_USE_BACKGROUND_SERVER_CORE

#endif  // !defined(COMPILE_BACKGROUND_SERVER_CORE_CLOSE) || (COMPILE_BACKGROUND_SERVER_CORE_CLOSE & CLOSE_USE_BACKGROUND_SERVER_CORE) != CLOSE_USE_BACKGROUND_SERVER_CORE

#ifdef BUILDING_STATIC

    #define BUILDING_BACKGROUND_SERVER_CORE_STATIC (static_cast<void>(0))

#endif  // BUILDING_STATIC

#endif  // BACKGROUND_SERVER_CORE_HELPER_USER_MACRO_H
