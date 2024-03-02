/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.6 (2024/02/28 14:52)

#ifndef SYSTEM_OPENGL_GET_OPENGL_FUNCTION_H
#define SYSTEM_OPENGL_GET_OPENGL_FUNCTION_H

#include "System/Helper/ConfigMacro.h"

#include <boost/assert.hpp>
#include <string>

namespace System
{
    /// 每个平台必须实现这个函数。
    MAYBE_NULLPTR void* GetOpenGLFunctionPointer(const char* glFunction) noexcept;

    template <typename Function>
    void GetFunction(const char* functionName, Function& function) noexcept
    {
#if defined(SYSTEM_PLATFORM_WIN32)

        function = static_cast<Function>(GetOpenGLFunctionPointer(functionName));

#elif defined(SYSTEM_PLATFORM_LINUX)

        function = reinterpret_cast<Function>(GetOpenGLFunctionPointer(functionName));

#endif  // defined(SYSTEM_PLATFORM_WIN32) || defined(SYSTEM_PLATFORM_LINUX)

        BOOST_ASSERT(function != nullptr);
    }
}

#endif  // SYSTEM_OPENGL_GET_OPENGL_FUNCTION_H
