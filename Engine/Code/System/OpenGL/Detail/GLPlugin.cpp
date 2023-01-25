///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.0 (2023/01/12 18:57)

#include "System/SystemExport.h"

#include "GL10Extensions.h"
#include "GLPlugin.h"
#include "GLUtility.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/Noexcept.h"
#include "System/OpenGL/Detail/GL11Extensions.h"
#include "System/OpenGL/Flags/GLExtensionsFlags.h"

#include <boost/assert.hpp>
#include <iostream>

using namespace std::literals;

namespace System
{
    void DoReportNullFunction(const char* glFunction)
    {
        const auto msg = glFunction + " = nullptr"s;
        std::cout << msg << std::endl;

        BOOST_ASSERT_MSG(false, msg.c_str());
    }

    void DoReportGLError(const char* glFunction)
    {
        // 这里直接调用glGetError，而不是GLGetError。
        auto code = UnderlyingCastEnum<OpenGLErrorCode>(glGetError());
        while (code != OpenGLErrorCode::NoError)
        {
            const auto errorString = GetOpenGLErrorString(code);
            std::cout << glFunction << ":" << errorString << std::endl;
            BOOST_ASSERT_MSG(false, errorString);

            code = UnderlyingCastEnum<OpenGLErrorCode>(glGetError());
        }
    }
}

void System::ReportNullFunction(const char* glFunction) noexcept
{
    NoexceptNoReturn(DoReportNullFunction, glFunction);
}

void System::ReportGLError(const char* glFunction) noexcept
{
    NoexceptNoReturn(DoReportGLError, glFunction);
}
