///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/29 23:06)

#ifndef SYSTEM_OPENGL_GET_OPENGL_FUNCTION_H
#define SYSTEM_OPENGL_GET_OPENGL_FUNCTION_H

#include "System/Helper/ConfigMacro.h"

#include <boost/assert.hpp>
#include <string>

namespace System
{
    MAYBE_NULLPTR void* GetOpenGLFunctionPointer(const char* glFunction) noexcept;

    template <typename Function>
    void GetFunction(const char* functionName, Function& function) noexcept
    {
        function = static_cast<Function>(GetOpenGLFunctionPointer(functionName));

        BOOST_ASSERT(function != nullptr);
    }
}

#endif  // SYSTEM_OPENGL_GET_OPENGL_FUNCTION_H
