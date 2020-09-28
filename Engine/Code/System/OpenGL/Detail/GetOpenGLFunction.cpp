//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/25 16:22)

#include "System/SystemExport.h"

#include "GetOpenGLFunction.h"

using namespace std::literals;

std::string System::GetActualFunctionName(const char* functionName)
{
    if (functionName != nullptr)
    {
        const std::string actual{ functionName };
        constexpr auto beginIndex = 1;
        if (beginIndex < actual.size())
        {
            return actual.substr(beginIndex, actual.size() - beginIndex); 
        }
    }

    return ""s;
}
