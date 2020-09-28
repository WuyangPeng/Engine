//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.0 (2020/09/25 14:57)

#ifndef SYSTEM_OPENGL_GET_OPENGL_FUNCTION_H
#define SYSTEM_OPENGL_GET_OPENGL_FUNCTION_H

#include "System/Helper/ConfigMacro.h"
#include "System/Helper/Noexcept.h"

#include <boost/assert.hpp>
#include <string>

extern "C"
{
    void* GetOpenGLFunctionPointer(const char* glFunction) noexcept;
}

namespace System
{
    std::string GetActualFunctionName(const char* functionName);

    template <typename Function>
    void GetFunction(const char* functionName, Function& function)
    {
        using namespace std::literals;
        const auto actual = GetActualFunctionName(functionName);

        function = static_cast<Function>(GetOpenGLFunctionPointer(actual.c_str()));

        BOOST_ASSERT_MSG(function, (functionName + " is nullptr."s).c_str());
    }

    template <typename Function>
    void GetFunctionSuffix(const char* functionName, Function& functionSuffix, Function& function, bool allowOverride)
    {
        using namespace std::literals;

        const auto actual = GetActualFunctionName(functionName);
        functionSuffix = static_cast<Function>(GetOpenGLFunctionPointer(actual.c_str()));

        BOOST_ASSERT_MSG(functionSuffix, (functionName + " is nullptr."s).c_str());

        if (allowOverride && function == nullptr)
        {
            function = functionSuffix;
        }
    }
}

#endif  // SYSTEM_OPENGL_GET_OPENGL_FUNCTION_H
