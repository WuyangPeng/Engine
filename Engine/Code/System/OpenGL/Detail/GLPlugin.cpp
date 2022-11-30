///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.4 (2022/11/19 18:38)

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
        auto msg = glFunction + " = nullptr"s;
        std::cout << msg << std::endl;

        BOOST_ASSERT_MSG(false, msg.c_str());
    }

    void DoReportGLError(const char* glFunction)
    {
        // ����ֱ�ӵ���glGetError��������GLGetError��
        auto code = UnderlyingCastEnum<OpenGLErrorCode>(glGetError());
        while (code != OpenGLErrorCode::NoError)
        {
            auto errorString = GetOpenGLErrorString(code);
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
