/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.0 (2023/11/19 00:20)

#ifndef RISE_OF_HISTORY_USER_MACRO_H
#define RISE_OF_HISTORY_USER_MACRO_H

#include "Framework/Helper/UserMacro.h"

#define RISE_OF_HISTORY_ClOSE_BEGIN (0x01)

#define CLOSE_USE_RISE_OF_HISTORY (RISE_OF_HISTORY_ClOSE_BEGIN)

#define RISE_OF_HISTORY_ClOSE_END CLOSE_USE_RISE_OF_HISTORY

#define CLOSE_RISE_OF_HISTORY_MAX ((RISE_OF_HISTORY_ClOSE_END << 1) - 1)

// 编译测试（默认为0B0000，最大值为0B0001）
#define COMPILE_RISE_OF_HISTORY_CLOSE 0B0000

static_assert(0 <= COMPILE_RISE_OF_HISTORY_CLOSE, "COMPILE_RISE_OF_HISTORY_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_RISE_OF_HISTORY_CLOSE <= CLOSE_RISE_OF_HISTORY_MAX, "COMPILE_RISE_OF_HISTORY_CLOSE Must be less than or equal CLOSE_RISE_OF_HISTORY_MAX.");

#if !defined(COMPILE_RISE_OF_HISTORY_CLOSE) || (COMPILE_RISE_OF_HISTORY_CLOSE & CLOSE_USE_RISE_OF_HISTORY) != CLOSE_USE_RISE_OF_HISTORY

#endif  // !defined(COMPILE_RISE_OF_HISTORY_CLOSE) || (COMPILE_RISE_OF_HISTORY_CLOSE & CLOSE_USE_RISE_OF_HISTORY) != CLOSE_USE_RISE_OF_HISTORY

#ifdef BUILDING_STATIC

    #define BUILDING_RISE_OF_HISTORY_STATIC (static_cast<void>(0))

#endif  // BUILDING_STATIC

#endif  // RISE_OF_HISTORY_USER_MACRO_H
