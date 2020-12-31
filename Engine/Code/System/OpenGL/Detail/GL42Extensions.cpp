//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.0 (2020/09/25 17:54)

#include "System/SystemExport.h"

#include "GL42Extensions.h"
#include "GLUtility.h"
#include "System/Helper/Detail/OpenGL/GLPluginMacro.h"
#include "System/OpenGL/Flags/GLExtensionsFlags.h"
#include "System/OpenGL/OpenGLUtility.h"

// OpenGL 4.2
namespace System
{
    auto g_ExistsOpenGL42 = ExistsOpenGLExtensions::Unknown;
}

System::ExistsOpenGLExtensions System::IsExistsOpenGL42() noexcept
{
    return g_ExistsOpenGL42;
}

void System::InitOpenGL42() noexcept
{
    if (System::OpenGLSystemVersion::Version42 <= System::GetOpenGLVersion())
    {
        g_ExistsOpenGL42 = ExistsOpenGLExtensions::Exists;
    }
    else
    {
        g_ExistsOpenGL42 = ExistsOpenGLExtensions::NotExist;
    }
}