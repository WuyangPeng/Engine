///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.6.0.0 (2020/12/19 21:26)

#ifndef BOOK_CPP_HELPER_USER_MACRO_H
#define BOOK_CPP_HELPER_USER_MACRO_H

#include "Framework/Helper/UserMacro.h"

#define BOOK_CPP_ClOSE_BEGIN (0x01)

#define CLOSE_USE_BOOK_CPP (BOOK_CPP_ClOSE_BEGIN)

#define BOOK_CPP_ClOSE_END CLOSE_USE_BOOK_CPP

#define CLOSE_BOOK_CPP_MAX ((BOOK_CPP_ClOSE_END << 1) - 1)

// 编译测试（默认为0，最大值为0x01）
#define COMPILE_BOOK_CPP_CLOSE 0x00

static_assert(0 <= COMPILE_BOOK_CPP_CLOSE, "COMPILE_BOOK_CPP_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_BOOK_CPP_CLOSE <= CLOSE_BOOK_CPP_MAX, "COMPILE_BOOK_CPP_CLOSE Must be less than or equal CLOSE_BOOK_CPP_MAX.");

#if !defined(COMPILE_BOOK_CPP_CLOSE) || (COMPILE_BOOK_CPP_CLOSE & CLOSE_USE_BOOK_CPP) != CLOSE_USE_BOOK_CPP

#endif  // !defined(COMPILE_BOOK_CPP_CLOSE) || (COMPILE_BOOK_CPP_CLOSE & CLOSE_USE_BOOK_CPP) != CLOSE_USE_BOOK_CPP

// 是否编译为静态库
#ifdef BUILDING_STATIC
    #define BUILDING_BOOK_CPP_STATIC static_cast<void>(0)
#endif  // BUILDING_STATIC

#endif  // BOOK_CPP_HELPER_USER_MACRO_H
