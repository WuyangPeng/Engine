///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.4 (2021/10/07 23:22)

#ifndef SAFE_CPP_HELPER_USER_MACRO_H
#define SAFE_CPP_HELPER_USER_MACRO_H

#include "Framework/Helper/UserMacro.h"

#define SAFE_CPP_ClOSE_BEGIN (0x01)

#define CLOSE_USE_SAFE_CPP (SAFE_CPP_ClOSE_BEGIN)

#define SAFE_CPP_ClOSE_END CLOSE_USE_SAFE_CPP

#define CLOSE_SAFE_CPP_MAX ((SAFE_CPP_ClOSE_END << 1) - 1)

// 编译测试（默认为0，最大值为0x01）
#define COMPILE_SAFE_CPP_CLOSE 0x00

static_assert(0 <= COMPILE_SAFE_CPP_CLOSE, "COMPILE_SAFE_CPP_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_SAFE_CPP_CLOSE <= CLOSE_SAFE_CPP_MAX, "COMPILE_SAFE_CPP_CLOSE Must be less than or equal CLOSE_SAFE_CPP_MAX.");

#if !defined(COMPILE_SAFE_CPP_CLOSE) || (COMPILE_SAFE_CPP_CLOSE & CLOSE_USE_SAFE_CPP) != CLOSE_USE_SAFE_CPP

#endif  // !defined(COMPILE_SAFE_CPP_CLOSE) || (COMPILE_SAFE_CPP_CLOSE & CLOSE_USE_SAFE_CPP) != CLOSE_USE_SAFE_CPP

#ifdef BUILDING_STATIC
    #define BUILDING_SAFE_CPP_STATIC
#endif  // BUILDING_STATIC

#endif  // SAFE_CPP_HELPER_USER_MACRO_H
