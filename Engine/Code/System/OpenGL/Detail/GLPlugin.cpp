//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/26 14:15)

#include "System/SystemExport.h"

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
}

void System::ReportNullFunction(const char* glFunction) noexcept
{
    NoexceptNoReturn<const char*>(DoReportNullFunction, glFunction);
}

namespace System
{
    void DoReportGLError(const char* glFunction)
    {
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

void System ::ReportGLError(const char* glFunction) noexcept
{
    NoexceptNoReturn<const char*>(DoReportGLError, glFunction);
}
