///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.1 (2021/03/11 17:53)

#ifndef THE_ART_OF_CPP_HELPER_USER_MACRO_H
#define THE_ART_OF_CPP_HELPER_USER_MACRO_H

#include "Framework/Helper/UserMacro.h"

#define THE_ART_OF_CPP_ClOSE_BEGIN (0x01)

#define CLOSE_USE_THE_ART_OF_CPP (THE_ART_OF_CPP_ClOSE_BEGIN)

#define THE_ART_OF_CPP_ClOSE_END CLOSE_USE_THE_ART_OF_CPP

#define CLOSE_THE_ART_OF_CPP_MAX ((THE_ART_OF_CPP_ClOSE_END << 1) - 1)

// 编译测试（默认为0，最大值为0x01）
#define COMPILE_THE_ART_OF_CPP_CLOSE 0x00

static_assert(0 <= COMPILE_THE_ART_OF_CPP_CLOSE, "COMPILE_THE_ART_OF_CPP_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_THE_ART_OF_CPP_CLOSE <= CLOSE_THE_ART_OF_CPP_MAX, "COMPILE_THE_ART_OF_CPP_CLOSE Must be less than or equal CLOSE_THE_ART_OF_CPP_MAX.");

#if !defined(COMPILE_THE_ART_OF_CPP_CLOSE) || (COMPILE_THE_ART_OF_CPP_CLOSE & CLOSE_USE_THE_ART_OF_CPP) != CLOSE_USE_THE_ART_OF_CPP

#endif  // !defined(COMPILE_THE_ART_OF_CPP_CLOSE) || (COMPILE_THE_ART_OF_CPP_CLOSE & CLOSE_USE_THE_ART_OF_CPP) != CLOSE_USE_THE_ART_OF_CPP

// 是否编译为静态库
#ifdef BUILDING_STATIC
    #define BUILDING_THE_ART_OF_CPP_STATIC
#endif  // BUILDING_STATIC

#endif  // THE_ART_OF_CPP_HELPER_USER_MACRO_H
