//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/25 17:55)

#include "System/SystemExport.h"

#include "GL44Extensions.h"
#include "GLUtility.h"
#include "System/Helper/Detail/OpenGL/GLPluginMacro.h"
#include "System/OpenGL/Flags/GLExtensionsFlags.h"
#include "System/OpenGL/OpenGLUtility.h"

// OpenGL 4.4
namespace System
{
    auto g_ExistsOpenGL44 = ExistsOpenGLExtensions::Unknown;
}

System::ExistsOpenGLExtensions System::IsExistsOpenGL44() noexcept
{
    return g_ExistsOpenGL44;
}

void System::InitOpenGL44() noexcept
{
    if (System::OpenGLSystemVersion::Version44 <= System::GetOpenGLVersion())
    {
        g_ExistsOpenGL44 = ExistsOpenGLExtensions::Exists;
    }
    else
    {
        g_ExistsOpenGL44 = ExistsOpenGLExtensions::NotExist;
    }
}