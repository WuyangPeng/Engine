///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.5 (2021/10/28 22:20)

#ifndef PARALLEL_AND_DISTRIBUTED_PROGRAMMING_USING_CPP_HELPER_USER_MACRO_H
#define PARALLEL_AND_DISTRIBUTED_PROGRAMMING_USING_CPP_HELPER_USER_MACRO_H

#include "Framework/Helper/UserMacro.h"

#define PARALLEL_AND_DISTRIBUTED_PROGRAMMING_USING_CPP_ClOSE_BEGIN (0x01)

#define CLOSE_USE_PARALLEL_AND_DISTRIBUTED_PROGRAMMING_USING_CPP (PARALLEL_AND_DISTRIBUTED_PROGRAMMING_USING_CPP_ClOSE_BEGIN)

#define PARALLEL_AND_DISTRIBUTED_PROGRAMMING_USING_CPP_ClOSE_END CLOSE_USE_PARALLEL_AND_DISTRIBUTED_PROGRAMMING_USING_CPP

#define CLOSE_PARALLEL_AND_DISTRIBUTED_PROGRAMMING_USING_CPP_MAX ((PARALLEL_AND_DISTRIBUTED_PROGRAMMING_USING_CPP_ClOSE_END << 1) - 1)

// 编译测试（默认为0，最大值为0x01）
#define COMPILE_PARALLEL_AND_DISTRIBUTED_PROGRAMMING_USING_CPP_CLOSE 0x00

static_assert(0 <= COMPILE_PARALLEL_AND_DISTRIBUTED_PROGRAMMING_USING_CPP_CLOSE, "COMPILE_PARALLEL_AND_DISTRIBUTED_PROGRAMMING_USING_CPP_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_PARALLEL_AND_DISTRIBUTED_PROGRAMMING_USING_CPP_CLOSE <= CLOSE_PARALLEL_AND_DISTRIBUTED_PROGRAMMING_USING_CPP_MAX, "COMPILE_PARALLEL_AND_DISTRIBUTED_PROGRAMMING_USING_CPP_CLOSE Must be less than or equal CLOSE_PARALLEL_AND_DISTRIBUTED_PROGRAMMING_USING_CPP_MAX.");

#if !defined(COMPILE_PARALLEL_AND_DISTRIBUTED_PROGRAMMING_USING_CPP_CLOSE) || (COMPILE_PARALLEL_AND_DISTRIBUTED_PROGRAMMING_USING_CPP_CLOSE & CLOSE_USE_PARALLEL_AND_DISTRIBUTED_PROGRAMMING_USING_CPP) != CLOSE_USE_PARALLEL_AND_DISTRIBUTED_PROGRAMMING_USING_CPP

#endif  // !defined(COMPILE_PARALLEL_AND_DISTRIBUTED_PROGRAMMING_USING_CPP_CLOSE) || (COMPILE_PARALLEL_AND_DISTRIBUTED_PROGRAMMING_USING_CPP_CLOSE & CLOSE_USE_PARALLEL_AND_DISTRIBUTED_PROGRAMMING_USING_CPP) != CLOSE_USE_PARALLEL_AND_DISTRIBUTED_PROGRAMMING_USING_CPP

#ifdef BUILDING_STATIC
    #define BUILDING_PARALLEL_AND_DISTRIBUTED_PROGRAMMING_USING_CPP_STATIC
#endif  // BUILDING_STATIC

#endif  // PARALLEL_AND_DISTRIBUTED_PROGRAMMING_USING_CPP_HELPER_USER_MACRO_H
