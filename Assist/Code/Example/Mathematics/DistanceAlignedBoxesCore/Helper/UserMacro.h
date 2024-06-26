/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/12 16:34)

#ifndef DISTANCE_ALIGNED_BOXES_CORE_HELPER_USER_MACRO_H
#define DISTANCE_ALIGNED_BOXES_CORE_HELPER_USER_MACRO_H

#include "Mathematics/Helper/UserMacro.h"

#define DISTANCE_ALIGNED_BOXES_CORE_ClOSE_BEGIN (0x01)

#define CLOSE_USE_DISTANCE_ALIGNED_BOXES_CORE (DISTANCE_ALIGNED_BOXES_CORE_ClOSE_BEGIN)

#define DISTANCE_ALIGNED_BOXES_CORE_ClOSE_END CLOSE_USE_DISTANCE_ALIGNED_BOXES_CORE

#define CLOSE_DISTANCE_ALIGNED_BOXES_CORE_MAX (((DISTANCE_ALIGNED_BOXES_CORE_ClOSE_END) << 1) - 1)

// 编译测试（默认为0B0000，最大值为0B0001）
#define COMPILE_DISTANCE_ALIGNED_BOXES_CORE_CLOSE 0B0000

static_assert(0 <= COMPILE_DISTANCE_ALIGNED_BOXES_CORE_CLOSE, "COMPILE_DISTANCE_ALIGNED_BOXES_CORE_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_DISTANCE_ALIGNED_BOXES_CORE_CLOSE <= CLOSE_DISTANCE_ALIGNED_BOXES_CORE_MAX, "COMPILE_DISTANCE_ALIGNED_BOXES_CORE_CLOSE Must be less than or equal CLOSE_DISTANCE_ALIGNED_BOXES_CORE_MAX.");

#if !defined(COMPILE_DISTANCE_ALIGNED_BOXES_CORE_CLOSE) || (COMPILE_DISTANCE_ALIGNED_BOXES_CORE_CLOSE & CLOSE_USE_DISTANCE_ALIGNED_BOXES_CORE) != CLOSE_USE_DISTANCE_ALIGNED_BOXES_CORE

#endif  // !defined(COMPILE_DISTANCE_ALIGNED_BOXES_CORE_CLOSE) || (COMPILE_DISTANCE_ALIGNED_BOXES_CORE_CLOSE & CLOSE_USE_DISTANCE_ALIGNED_BOXES_CORE) != CLOSE_USE_DISTANCE_ALIGNED_BOXES_CORE

#ifdef BUILDING_STATIC

    #define BUILDING_DISTANCE_ALIGNED_BOXES_CORE_STATIC static_cast<void>(0)

#endif  // BUILDING_STATIC

#endif  // DISTANCE_ALIGNED_BOXES_CORE_HELPER_USER_MACRO_H
