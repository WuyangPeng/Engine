//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.0 (2020/09/25 17:53)

#include "System/SystemExport.h"

#include "GL41Extensions.h"
#include "GLUtility.h"
#include "System/Helper/Detail/OpenGL/GLPluginMacro.h"
#include "System/OpenGL/Flags/GLExtensionsFlags.h"
#include "System/OpenGL/OpenGLUtility.h"

// OpenGL 4.1

namespace System
{
    auto g_ExistsOpenGL41 = ExistsOpenGLExtensions::Unknown;
}

System::ExistsOpenGLExtensions System::IsExistsOpenGL41() noexcept
{
    return g_ExistsOpenGL41;
}

void System::InitOpenGL41() noexcept
{
    if (System::OpenGLSystemVersion::Version41 <= System::GetOpenGLVersion())
    {
        g_ExistsOpenGL41 = ExistsOpenGLExtensions::Exists;
    }
    else
    {
        g_ExistsOpenGL41 = ExistsOpenGLExtensions::NotExist;
    }
}