//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/25 17:52)

#include "System/SystemExport.h"

#include "GL33Extensions.h"
#include "GLUtility.h"
#include "System/Helper/Detail/OpenGL/GLPluginMacro.h"
#include "System/OpenGL/Flags/GLExtensionsFlags.h"
#include "System/OpenGL/OpenGLUtility.h"
#include "System/OpenGL/Using/GL33ExtensionsUsing.h"

// OpenGL 3.3
namespace System
{
    auto g_ExistsOpenGL33 = ExistsOpenGLExtensions::Unknown;
}

System::ExistsOpenGLExtensions System::IsExistsOpenGL33() noexcept
{
    return g_ExistsOpenGL33;
}

System::PgglVertexAttribDivisor System::gglVertexAttribDivisor{ nullptr };

void System::GlVertexAttribDivisor(GLuint index, GLuint divisor) noexcept
{
    SYSTEM_BODY_2(gglVertexAttribDivisor, index, divisor);
}

void System::InitOpenGL33()
{
    if (System::OpenGLSystemVersion::Version33 <= System::GetOpenGLVersion())
    {
        g_ExistsOpenGL33 = ExistsOpenGLExtensions::Exists;

        SYSTEM_GET_FUNCTION(gglVertexAttribDivisor);
    }
    else
    {
        g_ExistsOpenGL33 = ExistsOpenGLExtensions::NotExist;
    }
}