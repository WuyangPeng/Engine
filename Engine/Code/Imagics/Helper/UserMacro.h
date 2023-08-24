///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/02 11:21)

#ifndef IMAGICS_IMAGICS_HELPER_USER_MACRO_H
#define IMAGICS_IMAGICS_HELPER_USER_MACRO_H

#include "System/Helper/ConfigMacro.h"
#include "CoreTools/Helper/UserMacro.h"
#include "Mathematics/Helper/UserMacro.h"

#define IMAGICS_ClOSE_BEGIN (0x01)

#define CLOSE_USE_OPENCV (IMAGICS_ClOSE_BEGIN)

#define IMAGICS_ClOSE_END CLOSE_USE_OPENCV

#define CLOSE_IMAGICS_MAX (((IMAGICS_ClOSE_END) << 1) - 1)

// 编译测试（默认为0，最大值为0x03）
#define COMPILE_IMAGICS_CLOSE 0x00

static_assert(0 <= COMPILE_IMAGICS_CLOSE, "COMPILE_IMAGICS_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_IMAGICS_CLOSE <= CLOSE_IMAGICS_MAX, "COMPILE_IMAGICS_CLOSE Must be less than or equal CLOSE_IMAGICS_MAX.");

#if !defined(COMPILE_PHYSICS_CLOSE) || (COMPILE_PHYSICS_CLOSE & CLOSE_USE_OPENCV) != CLOSE_USE_OPENCV

    #define IMAGICS_USE_OPENCV

#endif  // !defined(COMPILE_PHYSICS_CLOSE) || (COMPILE_PHYSICS_CLOSE & CLOSE_USE_OPENCV) != CLOSE_USE_OPENCV

#ifdef BUILDING_STATIC

    #define BUILDING_IMAGICS_STATIC

#endif  // BUILDING_STATIC

#endif  // IMAGICS_IMAGICS_HELPER_USER_MACRO_H
