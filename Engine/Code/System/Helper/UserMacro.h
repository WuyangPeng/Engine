// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.0 (2020/01/02 15:13)

#ifndef SYSTEM_HELPER_USER_MACRO_H
#define SYSTEM_HELPER_USER_MACRO_H

#include "ConfigMacro.h"

#define CLOSE_OPENGL2_NORMAL_ATTRIBUTES (0x01)
#define CLOSE_GLUT (0x01 << 1)
#define CLOSE_ENABLE_GL_ERROR_CHECKING (0x01 << 2)
#define CLOSE_DIRECTX (0x01 << 3)
#define CLOSE_SYSTEM_MAX ((CLOSE_DIRECTX << 1) - 1)

// 编译测试（默认为0，最大值为0x0F）
#define COMPILE_SYSTEM_CLOSE 0x00

static_assert(0 <= COMPILE_SYSTEM_CLOSE, "COMPILE_SYSTEM_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_SYSTEM_CLOSE <= CLOSE_SYSTEM_MAX, "COMPILE_SYSTEM_CLOSE Must be less than or equal CLOSE_SYSTEM_MAX.");

// 是否编译为静态库
#ifdef BUILDING_STATIC
	#define BUILDING_SYSTEM_STATIC
#endif // BUILDING_STATIC

// 是否使用Windows宏
#ifdef SYSTEM_PLATFORM_WIN32	 
	#define SYSTEM_USE_WINDOWS_MACRO
#endif // SYSTEM_PLATFORM_WIN32

// 是否使用自旋锁
#ifdef TCRE_USE_GCC
	#define SYSTEM_USE_SPIN_COUNT_CRITICAL_SECTION  
#endif // TCRE_USE_GCC

// 有些的OpenGL 2.x的驱动程序不正确处理法线属性。
// 这是一个问题，你应该要使用法线矢量到一个4元组的信息并传递到着色器。OpenGL 1.x的glNormalPointer假定法线是3元组。
// 如果你知道你的目标机器正确支持OpenGL 2.x的法线属性，定义下面的#define。
// 否则，渲染器将使用OpenGL 1.x的glNormalPointer。

// 在Macintosh上，无论是PowerPC还是英特尔，NVIDIA显卡，法线通用属性不起作用。
// 这是因为我们使用OpenGL 1.x的扩展着色器编程。我们需要更新到OpenGL 2.x及更高版本。

// 是否使用OpenGL2，默认使用
#if !defined(COMPILE_SYSTEM_CLOSE) || (COMPILE_SYSTEM_CLOSE & CLOSE_OPENGL2_NORMAL_ATTRIBUTES) != CLOSE_OPENGL2_NORMAL_ATTRIBUTES
	#define SYSTEM_USE_OPENGL2_NORMAL_ATTRIBUTES
#endif // !defined(COMPILE_SYSTEM_CLOSE) || (COMPILE_SYSTEM_CLOSE & CLOSE_OPENGL2_NORMAL_ATTRIBUTES) != CLOSE_OPENGL2_NORMAL_ATTRIBUTES

#if !defined(SYSTEM_USE_OPENGL2_NORMAL_ATTRIBUTES) &&  defined(SYSTEM_PLATFORM_MACOS)
	#define SYSTEM_USE_OPENGL2_NORMAL_ATTRIBUTES
#endif // !defined(SYSTEM_USE_OPENGL2_NORMAL_ATTRIBUTES) &&  defined(SYSTEM_PLATFORM_MACOS) 

// 是否使用glut，默认使用
#if !defined(COMPILE_SYSTEM_CLOSE) || (COMPILE_SYSTEM_CLOSE & CLOSE_GLUT) != CLOSE_GLUT
	#define SYSTEM_USE_GLUT
#endif //  !defined(COMPILE_SYSTEM_CLOSE) || (COMPILE_SYSTEM_CLOSE & CLOSE_GLUT) != CLOSE_GLUT

// 是否检查GL错误。
#if !defined(COMPILE_SYSTEM_CLOSE) || (COMPILE_SYSTEM_CLOSE & CLOSE_ENABLE_GL_ERROR_CHECKING) != CLOSE_ENABLE_GL_ERROR_CHECKING
	#ifdef _DEBUG
		#define SYSTEM_ENABLE_GL_ERROR_CHECKING
	#endif // _DEBUG
#endif //  !defined(COMPILE_SYSTEM_CLOSE) || (COMPILE_SYSTEM_CLOSE & CLOSE_ENABLE_GL_ERROR_CHECKING) != CLOSE_ENABLE_GL_ERROR_CHECKING

// 是否使用DirectX
#if !defined(COMPILE_SYSTEM_CLOSE) || (COMPILE_SYSTEM_CLOSE & CLOSE_DIRECTX) != CLOSE_DIRECTX
	#ifdef SYSTEM_PLATFORM_WIN32	 
		#define SYSTEM_USE_DIRECT_X_9
		#define SYSTEM_USE_DIRECT_X_10
		#define SYSTEM_USE_DIRECT_X_11
	#endif // SYSTEM_PLATFORM_WIN32
#endif //  !defined(COMPILE_SYSTEM_CLOSE) || (COMPILE_SYSTEM_CLOSE & CLOSE_DIRECTX) != CLOSE_DIRECTX

#include "PragmaWarning/EngineDisable.h"
	  
#endif // SYSTEM_HELPER_USER_MACRO_H
