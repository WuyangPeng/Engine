/// Copyright (c) 2010-2025
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.2.0 (2025/03/22 11:09)

#ifndef THREADING_CORE_RENDER_ENGINE_ASSIST_USER_MACRO_H
#define THREADING_CORE_RENDER_ENGINE_ASSIST_USER_MACRO_H

#include "Framework/Helper/UserMacro.h"

#define ASSIST_ClOSE_BEGIN (0x01)

#define CLOSE_USE_ASSIST (ASSIST_ClOSE_BEGIN)

#define ASSIST_ClOSE_END CLOSE_USE_ASSIST

#define CLOSE_ASSIST_MAX ((ASSIST_ClOSE_END << 1) - 1)

// 编译测试（默认为0B0000，最大值为0B0001）
#define COMPILE_ASSIST_CLOSE 0B0000

static_assert(0 <= COMPILE_ASSIST_CLOSE, "COMPILE_ASSIST_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_ASSIST_CLOSE <= CLOSE_ASSIST_MAX, "COMPILE_ASSIST_CLOSE Must be less than or equal CLOSE_ASSIST_MAX.");

#if !defined(COMPILE_ASSIST_CLOSE) || (COMPILE_ASSIST_CLOSE & CLOSE_USE_ASSIST) != CLOSE_USE_ASSIST

    #define OPEN_ASSIST static_cast<void>(0)

#endif  // !defined(COMPILE_ASSIST_CLOSE) || (COMPILE_ASSIST_CLOSE & CLOSE_USE_ASSIST) != CLOSE_USE_ASSIST

#ifdef BUILDING_STATIC

    #define BUILDING_ASSIST_STATIC static_cast<void>(0)

#endif  // BUILDING_STATIC

#endif  // THREADING_CORE_RENDER_ENGINE_ASSIST_USER_MACRO_H