//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/21 17:49)

#ifndef SYSTEM_HELPER_GL_PLUGIN_MACRO_H
#define SYSTEM_HELPER_GL_PLUGIN_MACRO_H

#include "System/Helper/UserMacro.h"

// 在每次OpenGL调用时默认行为没有额外的操作，如果必要，添加一个附加语义。

#define SYSTEM_ENTER_FUNCTION(glFunction)
#define SYSTEM_NONNULL_FUNCTION(glFunction)

#ifdef SYSTEM_ENABLE_GL_ERROR_CHECKING

    #include "System/OpenGL/Fwd/GLPluginFwd.h"

    // 这个函数断言在遇到一个空函数时。渲染器预计函数存在。
    #define SYSTEM_NULL_FUNCTION(glFunction) System::ReportNullFunction(SYSTEM_STRINGIZE(glFunction))

    // 每次调用OpenGL函数这个函数检查glGetError。
    #define SYSTEM_EXIT_FUNCTION(glFunction) System::ReportGLError(SYSTEM_STRINGIZE(glFunction))

#else  // !SYSTEM_ENABLE_GL_ERROR_CHECKING

    // 启用这一块则禁用错误检查。
    #define SYSTEM_NULL_FUNCTION(glFunction)
    #define SYSTEM_EXIT_FUNCTION(glFunction)

#endif  // SYSTEM_ENABLE_GL_ERROR_CHECKING

#endif  // SYSTEM_HELPER_GL_PLUGIN_MACRO_H
