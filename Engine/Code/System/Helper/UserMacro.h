//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/21 11:19)

#ifndef SYSTEM_HELPER_USER_MACRO_H
#define SYSTEM_HELPER_USER_MACRO_H

#include "ConfigMacro.h"

#define SYSTEM_ClOSE_BEGIN (0x01)

#define CLOSE_OPENGL2_NORMAL_ATTRIBUTES (SYSTEM_ClOSE_BEGIN)
#define CLOSE_GLUT (SYSTEM_ClOSE_BEGIN << 1)
#define CLOSE_ENABLE_GL_ERROR_CHECKING (SYSTEM_ClOSE_BEGIN << 2)
#define CLOSE_DIRECTX (SYSTEM_ClOSE_BEGIN << 3)

#define SYSTEM_ClOSE_END CLOSE_DIRECTX

#define CLOSE_SYSTEM_MAX ((SYSTEM_ClOSE_END << 1) - 1)

// 编译测试（默认为0，最大值为0x0F）
#define COMPILE_SYSTEM_CLOSE 0x00

static_assert(0 <= COMPILE_SYSTEM_CLOSE, "COMPILE_SYSTEM_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_SYSTEM_CLOSE <= CLOSE_SYSTEM_MAX, "COMPILE_SYSTEM_CLOSE Must be less than or equal CLOSE_SYSTEM_MAX.");

// 是否使用Windows宏
#ifdef SYSTEM_PLATFORM_WIN32
    #define SYSTEM_USE_WINDOWS_MACRO
#endif  // SYSTEM_PLATFORM_WIN32

// 是否使用自旋锁
#ifdef TCRE_USE_GCC
    #define SYSTEM_USE_SPIN_COUNT_CRITICAL_SECTION
#endif  // TCRE_USE_GCC

// 有些OpenGL 2.x的驱动程序无法正确处理法线属性。
// 如果您想使用法线向量将4元组的信息传递给着色器，则这是一个问题。
// OpenGL 1.x的glNormalPointer假定法线是3元组。
// 如果知道目标计算机正确支持OpenGL 2.x的法线属性，定义SYSTEM_USE_OPENGL2_NORMAL_ATTRIBUTES。
// 否则，渲染器将使用OpenGL 1.x的glNormalPointer。

// 在Macintosh上，无论是PowerPC还是英特尔，NVIDIA显卡，法线的通用属性均不起作用。
// 这是因为我们正在使用OpenGL 1.x的扩展程序进行着色器编程。我们需要更新到OpenGL 2.x及更高版本。

#if !defined(COMPILE_SYSTEM_CLOSE) || (COMPILE_SYSTEM_CLOSE & CLOSE_OPENGL2_NORMAL_ATTRIBUTES) != CLOSE_OPENGL2_NORMAL_ATTRIBUTES
    #define SYSTEM_USE_OPENGL2_NORMAL_ATTRIBUTES
#endif  // !defined(COMPILE_SYSTEM_CLOSE) || (COMPILE_SYSTEM_CLOSE & CLOSE_OPENGL2_NORMAL_ATTRIBUTES) != CLOSE_OPENGL2_NORMAL_ATTRIBUTES

#if !defined(SYSTEM_USE_OPENGL2_NORMAL_ATTRIBUTES) && defined(SYSTEM_PLATFORM_MACOS)
    #define SYSTEM_USE_OPENGL2_NORMAL_ATTRIBUTES
#endif  // !defined(SYSTEM_USE_OPENGL2_NORMAL_ATTRIBUTES) && defined(SYSTEM_PLATFORM_MACOS)

// 是否使用glut，默认使用
#if !defined(COMPILE_SYSTEM_CLOSE) || (COMPILE_SYSTEM_CLOSE & CLOSE_GLUT) != CLOSE_GLUT
    #define SYSTEM_USE_GLUT
#endif  //  !defined(COMPILE_SYSTEM_CLOSE) || (COMPILE_SYSTEM_CLOSE & CLOSE_GLUT) != CLOSE_GLUT

#ifdef _DEBUG

    #if !defined(COMPILE_SYSTEM_CLOSE) || (COMPILE_SYSTEM_CLOSE & CLOSE_ENABLE_GL_ERROR_CHECKING) != CLOSE_ENABLE_GL_ERROR_CHECKING
        // 是否检查GL错误。
        #define SYSTEM_ENABLE_GL_ERROR_CHECKING
    #endif  //  !defined(COMPILE_SYSTEM_CLOSE) || (COMPILE_SYSTEM_CLOSE & CLOSE_ENABLE_GL_ERROR_CHECKING) != CLOSE_ENABLE_GL_ERROR_CHECKING

#endif  // _DEBUG

#ifdef SYSTEM_PLATFORM_WIN32

    #if !defined(COMPILE_SYSTEM_CLOSE) || (COMPILE_SYSTEM_CLOSE & CLOSE_DIRECTX) != CLOSE_DIRECTX
        // 是否使用DirectX
        #define SYSTEM_USE_DIRECTX_9
        #define SYSTEM_USE_DIRECTX_10
        #define SYSTEM_USE_DIRECTX_11
    #endif  //  !defined(COMPILE_SYSTEM_CLOSE) || (COMPILE_SYSTEM_CLOSE & CLOSE_DIRECTX) != CLOSE_DIRECTX

#endif  // SYSTEM_PLATFORM_WIN32

// 是否编译为静态库
#ifdef BUILDING_STATIC
    #define BUILDING_SYSTEM_STATIC static_cast<void>(0)
#endif  // BUILDING_STATIC

#include "PragmaWarning/EngineDisable.h"

#endif  // SYSTEM_HELPER_USER_MACRO_H
