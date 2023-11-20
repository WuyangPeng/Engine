/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.0 (2023/11/19 00:20)

#ifndef DATABASE_SERVER_MIDDLE_LAYER_HELPER_USER_MACRO_H
#define DATABASE_SERVER_MIDDLE_LAYER_HELPER_USER_MACRO_H

#include "Framework/Helper/UserMacro.h"

#define DATABASE_SERVER_MIDDLE_LAYER_ClOSE_BEGIN (0x01)

#define CLOSE_USE_DATABASE_SERVER_MIDDLE_LAYER (DATABASE_SERVER_MIDDLE_LAYER_ClOSE_BEGIN)

#define DATABASE_SERVER_MIDDLE_LAYER_ClOSE_END CLOSE_USE_DATABASE_SERVER_MIDDLE_LAYER

#define CLOSE_DATABASE_SERVER_MIDDLE_LAYER_MAX (((DATABASE_SERVER_MIDDLE_LAYER_ClOSE_END) << 1) - 1)

// 编译测试（默认为0，最大值为0x01）
#define COMPILE_DATABASE_SERVER_MIDDLE_LAYER_CLOSE 0x00

static_assert(0 <= COMPILE_DATABASE_SERVER_MIDDLE_LAYER_CLOSE, "COMPILE_DATABASE_SERVER_MIDDLE_LAYER_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_DATABASE_SERVER_MIDDLE_LAYER_CLOSE <= CLOSE_DATABASE_SERVER_MIDDLE_LAYER_MAX, "COMPILE_DATABASE_SERVER_MIDDLE_LAYER_CLOSE Must be less than or equal CLOSE_DATABASE_SERVER_MIDDLE_LAYER_MAX.");

#if !defined(COMPILE_DATABASE_SERVER_MIDDLE_LAYER_CLOSE) || (COMPILE_DATABASE_SERVER_MIDDLE_LAYER_CLOSE & CLOSE_USE_DATABASE_SERVER_MIDDLE_LAYER) != CLOSE_USE_DATABASE_SERVER_MIDDLE_LAYER

#endif  // !defined(COMPILE_DATABASE_SERVER_MIDDLE_LAYER_CLOSE) || (COMPILE_DATABASE_SERVER_MIDDLE_LAYER_CLOSE & CLOSE_USE_DATABASE_SERVER_MIDDLE_LAYER) != CLOSE_USE_DATABASE_SERVER_MIDDLE_LAYER

#ifdef BUILDING_STATIC

    #define BUILDING_DATABASE_SERVER_MIDDLE_LAYER_STATIC

#endif  // BUILDING_STATIC

#endif  // DATABASE_SERVER_MIDDLE_LAYER_HELPER_USER_MACRO_H
