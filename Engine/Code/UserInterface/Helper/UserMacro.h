/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/21 14:46)

#ifndef USER_INTERFACE_MACRO_USER_MACRO_H
#define USER_INTERFACE_MACRO_USER_MACRO_H

#include "CoreTools/Helper/UserMacro.h"

#define USER_INTERFACE_ClOSE_BEGIN (0x01)

#define CLOSE_USE_WX_WIDGETS (USER_INTERFACE_ClOSE_BEGIN)
#define CLOSE_USE_FLTK (USER_INTERFACE_ClOSE_BEGIN << 1)
#define CLOSE_USE_OPENGL (USER_INTERFACE_ClOSE_BEGIN << 2)
#define CLOSE_USE_DIRECTX (USER_INTERFACE_ClOSE_BEGIN << 3)

#define USER_INTERFACE_ClOSE_END CLOSE_USE_DIRECTX

#define CLOSE_USER_INTERFACE_MAX (((USER_INTERFACE_ClOSE_END) << 1) - 1)

// 编译测试（默认为0B0000，最大值为0B1111）
#define COMPILE_USER_INTERFACE_CLOSE 0B0000

static_assert(0 <= COMPILE_USER_INTERFACE_CLOSE, "COMPILE_USER_INTERFACE_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_USER_INTERFACE_CLOSE <= CLOSE_USER_INTERFACE_MAX, "COMPILE_ANIMATION_CLOSE Must be less than or equal CLOSE_USER_INTERFACE_MAX.");

#if !defined(COMPILE_USER_INTERFACE_CLOSE) || (COMPILE_USER_INTERFACE_CLOSE & CLOSE_USE_WX_WIDGETS) != CLOSE_USE_WX_WIDGETS

    #define USER_INTERFACE_USE_WX_WIDGETS

#endif  // !defined(COMPILE_USER_INTERFACE_CLOSE) || (COMPILE_USER_INTERFACE_CLOSE & CLOSE_USE_WX_WIDGETS) != CLOSE_USE_WX_WIDGETS

#if !defined(COMPILE_USER_INTERFACE_CLOSE) || (COMPILE_USER_INTERFACE_CLOSE & CLOSE_USE_FLTK) != CLOSE_USE_FLTK

    #define USER_INTERFACE_USE_FLTK

#endif  // !defined(COMPILE_USER_INTERFACE_CLOSE) || (COMPILE_USER_INTERFACE_CLOSE & CLOSE_USE_FLTK) != CLOSE_USE_FLTK

#if !defined(COMPILE_USER_INTERFACE_CLOSE) || (COMPILE_USER_INTERFACE_CLOSE & CLOSE_USE_OPENGL) != CLOSE_USE_OPENGL

    #define USER_INTERFACE_USE_OPENGL

#endif  // !defined(COMPILE_USER_INTERFACE_CLOSE) || (COMPILE_USER_INTERFACE_CLOSE & CLOSE_USE_OPENGL) != CLOSE_USE_OPENGL

#if !defined(COMPILE_USER_INTERFACE_CLOSE) || (COMPILE_USER_INTERFACE_CLOSE & CLOSE_USE_DIRECTX) != CLOSE_USE_DIRECTX

    #define USER_INTERFACE_USE_DIRECTX

#endif  // !defined(COMPILE_USER_INTERFACE_CLOSE) || (COMPILE_USER_INTERFACE_CLOSE & CLOSE_USE_DIRECTX) != CLOSE_USE_DIRECTX

#ifdef BUILDING_STATIC

    #define BUILDING_USER_INTERFACE_STATIC

#endif  // BUILDING_STATIC

#endif  // USER_INTERFACE_MACRO_USER_MACRO_H
