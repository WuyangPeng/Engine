///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.1.5 (2021/06/08 10:21)

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
