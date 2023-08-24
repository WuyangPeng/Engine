///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/02 14:34)

#ifndef RESOURCE_MANAGER_MACRO_USER_MACRO_H
#define RESOURCE_MANAGER_MACRO_USER_MACRO_H

#include "CoreTools/Helper/UserMacro.h"

#define RESOURCE_MANAGER_ClOSE_BEGIN (0x01)

#define CLOSE_USE_RESOURCE_MANAGER (RESOURCE_MANAGER_ClOSE_BEGIN)

#define RESOURCE_MANAGER_ClOSE_END CLOSE_USE_RESOURCE_MANAGER

#define CLOSE_RESOURCE_MANAGER_MAX (((RESOURCE_MANAGER_ClOSE_END) << 1) - 1)

// 编译测试（默认为0，最大值为0x01）
#define COMPILE_RESOURCE_MANAGER_CLOSE 0x00

static_assert(0 <= COMPILE_RESOURCE_MANAGER_CLOSE, "COMPILE_RESOURCE_MANAGER_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_RESOURCE_MANAGER_CLOSE <= CLOSE_RESOURCE_MANAGER_MAX, "COMPILE_RESOURCE_MANAGER_CLOSE Must be less than or equal CLOSE_RESOURCE_MANAGER_MAX.");

#if !defined(COMPILE_RESOURCE_MANAGER_CLOSE) || (COMPILE_RESOURCE_MANAGER_CLOSE & CLOSE_USE_RESOURCE_MANAGER) != CLOSE_USE_RESOURCE_MANAGER

#endif  // !defined(COMPILE_RESOURCE_MANAGER_CLOSE) || (COMPILE_RESOURCE_MANAGER_CLOSE & CLOSE_USE_RESOURCE_MANAGER) != CLOSE_USE_RESOURCE_MANAGER

#ifdef BUILDING_STATIC

    #define BUILDING_RESOURCE_MANAGER_STATIC

#endif  // BUILDING_STATIC

#endif  // RESOURCE_MANAGER_MACRO_USER_MACRO_H
