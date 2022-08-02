///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	最后的霸王版本：0.8.0.12 (2022/07/24 0:52)

#ifndef LOGIN_SERVER_MIDDLE_LAYER_MACRO_USER_MACRO_H
#define LOGIN_SERVER_MIDDLE_LAYER_MACRO_USER_MACRO_H

#include "Framework/Helper/UserMacro.h"

#define CLOSE_USE_XXX (0x01)
#define CLOSE_LOGIN_SERVER_MIDDLE_LAYER_MAX (((CLOSE_USE_XXX) << 1) - 1)

// 编译测试（默认为0，最大值为0x01）
#define COMPILE_LOGIN_SERVER_MIDDLE_LAYER_CLOSE 0x00

static_assert(0 <= COMPILE_LOGIN_SERVER_MIDDLE_LAYER_CLOSE, "COMPILE_LOGIN_SERVER_MIDDLE_LAYER_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_LOGIN_SERVER_MIDDLE_LAYER_CLOSE <= CLOSE_LOGIN_SERVER_MIDDLE_LAYER_MAX, "COMPILE_LOGIN_SERVER_MIDDLE_LAYER_CLOSE Must be less than or equal CLOSE_LOGIN_SERVER_MIDDLE_LAYER_MAX.");

#if !defined(COMPILE_LOGIN_SERVER_MIDDLE_LAYER_CLOSE) || (COMPILE_LOGIN_SERVER_MIDDLE_LAYER_CLOSE & CLOSE_USE_XXX) != CLOSE_USE_XXX

#endif  // !defined(COMPILE_LOGIN_SERVER_MIDDLE_LAYER_CLOSE) || (COMPILE_LOGIN_SERVER_MIDDLE_LAYER_CLOSE & CLOSE_USE_XXX) != CLOSE_USE_XXX

// 是否编译成静态库
#ifdef BUILDING_STATIC
    #define BUILDING_LOGIN_SERVER_MIDDLE_LAYER_STATIC
#endif  // BUILDING_STATIC

#endif  // LOGIN_SERVER_MIDDLE_LAYER_MACRO_USER_MACRO_H
