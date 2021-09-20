///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.1.5 (2021/06/12 18:21)

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

using std::cout;
using std::endl;
using std::string;
using namespace std::literals;

namespace System
{
    void DoReportNullFunction(const char* glFunction)
    {
        auto msg = glFunction + " = nullptr"s;
        cout << msg << endl;

        BOOST_ASSERT_MSG(false, msg.c_str());
    }

    void DoReportGLError(const char* glFunction)
    {
        // 这里直接调用glGetError，而不是GLGetError。
        auto code = UnderlyingCastEnum<OpenGLErrorCode>(glGetError());
        while (code != OpenGLErrorCode::NoError)
        {
            auto errorString = GetOpenGLErrorString(code);
            cout << glFunction << ":" << errorString << endl;
            BOOST_ASSERT_MSG(false, errorString);

            code = UnderlyingCastEnum<OpenGLErrorCode>(glGetError());
        }
    }
}

void System::ReportNullFunction(const char* glFunction) noexcept
{
    NoexceptNoReturn<const char*>(DoReportNullFunction, glFunction);
}

void System::ReportGLError(const char* glFunction) noexcept
{
    NoexceptNoReturn<const char*>(DoReportGLError, glFunction);
}
