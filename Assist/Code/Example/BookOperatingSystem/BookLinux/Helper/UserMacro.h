///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.6 (2021/11/21 14:32)

#ifndef BOOK_LINUX_MACRO_USER_MACRO_H
#define BOOK_LINUX_MACRO_USER_MACRO_H

#include "Framework/Helper/UserMacro.h"

#define BOOK_LINUX_ClOSE_BEGIN (0x01)

#define CLOSE_USE_BOOK_LINUX (BOOK_LINUX_ClOSE_BEGIN)

#define BOOK_LINUX_ClOSE_END CLOSE_USE_BOOK_LINUX

#define CLOSE_BOOK_LINUX_MAX ((BOOK_LINUX_ClOSE_END << 1) - 1)

// 编译测试（默认为0，最大值为0x01）
#define COMPILE_BOOK_LINUX_CLOSE 0x00

static_assert(0 <= COMPILE_BOOK_LINUX_CLOSE, "COMPILE_BOOK_LINUX_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_BOOK_LINUX_CLOSE <= CLOSE_BOOK_LINUX_MAX, "COMPILE_BOOK_LINUX_CLOSE Must be less than or equal CLOSE_BOOK_LINUX_MAX.");

#if !defined(COMPILE_BOOK_LINUX_CLOSE) || (COMPILE_BOOK_LINUX_CLOSE & CLOSE_USE_BOOK_LINUX) != CLOSE_USE_BOOK_LINUX

#endif  // !defined(COMPILE_BOOK_LINUX_CLOSE) || (COMPILE_BOOK_LINUX_CLOSE & CLOSE_USE_BOOK_LINUX) != CLOSE_USE_BOOK_LINUX

// 是否编译为静态库
#ifdef BUILDING_STATIC
    #define BUILDING_BOOK_LINUX_STATIC
#endif  // BUILDING_STATIC

#endif  // BOOK_LINUX_MACRO_USER_MACRO_H
