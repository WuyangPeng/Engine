//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/25 17:54)

#include "System/SystemExport.h"

#include "GL43Extensions.h"
#include "GLUtility.h"
#include "System/Helper/Detail/OpenGL/GLPluginMacro.h"
#include "System/OpenGL/Flags/GLExtensionsFlags.h"
#include "System/OpenGL/OpenGLUtility.h"

// OpenGL 4.3
namespace System
{
    auto g_ExistsOpenGL43 = ExistsOpenGLExtensions::Unknown;
}

System::ExistsOpenGLExtensions System::IsExistsOpenGL43() noexcept
{
    return g_ExistsOpenGL43;
}

void System::InitOpenGL43() noexcept
{
    if (System::OpenGLSystemVersion::Version43 <= System::GetOpenGLVersion())
    {
        g_ExistsOpenGL43 = ExistsOpenGLExtensions::Exists;
    }
    else
    {
        g_ExistsOpenGL43 = ExistsOpenGLExtensions::NotExist;
    }
}