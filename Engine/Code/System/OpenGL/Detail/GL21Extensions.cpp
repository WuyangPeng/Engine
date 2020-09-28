//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/25 17:36)

#include "System/SystemExport.h"

#include "GL21Extensions.h"
#include "GLUtility.h"
#include "System/Helper/Detail/OpenGL/GLPluginMacro.h"
#include "System/OpenGL/Flags/GLExtensionsFlags.h"
#include "System/OpenGL/OpenGLUtility.h"
#include "System/OpenGL/Using/GL21ExtensionsUsing.h"

// OpenGL 2.1
namespace System
{
    auto g_ExistsOpenGL21 = ExistsOpenGLExtensions::Unknown;
}

System::ExistsOpenGLExtensions System::IsExistsOpenGL21() noexcept
{
    return g_ExistsOpenGL21;
}

System::PgglUniformMatrix2x3fv System::gglUniformMatrix2x3fv{ nullptr };
System::PgglUniformMatrix3x2fv System::gglUniformMatrix3x2fv{ nullptr };
System::PgglUniformMatrix2x4fv System::gglUniformMatrix2x4fv{ nullptr };
System::PgglUniformMatrix4x2fv System::gglUniformMatrix4x2fv{ nullptr };
System::PgglUniformMatrix3x4fv System::gglUniformMatrix3x4fv{ nullptr };
System::PgglUniformMatrix4x3fv System::gglUniformMatrix4x3fv{ nullptr };

void System::GlUniformMatrix2x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept
{
    SYSTEM_BODY_4(gglUniformMatrix2x3fv, location, count, transpose, value);
}

void System::GlUniformMatrix3x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept
{
    SYSTEM_BODY_4(gglUniformMatrix3x2fv, location, count, transpose, value);
}

void System::GlUniformMatrix2x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept
{
    SYSTEM_BODY_4(gglUniformMatrix2x4fv, location, count, transpose, value);
}

void System::GlUniformMatrix4x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept
{
    SYSTEM_BODY_4(gglUniformMatrix4x2fv, location, count, transpose, value);
}

void System::GlUniformMatrix3x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept
{
    SYSTEM_BODY_4(gglUniformMatrix3x4fv, location, count, transpose, value);
}

void System::GlUniformMatrix4x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept
{
    SYSTEM_BODY_4(gglUniformMatrix4x3fv, location, count, transpose, value);
}

void System::InitOpenGL21()
{
    if (System::OpenGLSystemVersion::Version21 <= System::GetOpenGLVersion())
    {
        g_ExistsOpenGL21 = ExistsOpenGLExtensions::Exists;

        SYSTEM_GET_FUNCTION(gglUniformMatrix2x3fv);
        SYSTEM_GET_FUNCTION(gglUniformMatrix3x2fv);
        SYSTEM_GET_FUNCTION(gglUniformMatrix2x4fv);
        SYSTEM_GET_FUNCTION(gglUniformMatrix4x2fv);
        SYSTEM_GET_FUNCTION(gglUniformMatrix3x4fv);
        SYSTEM_GET_FUNCTION(gglUniformMatrix4x3fv);
    }
    else
    {
        g_ExistsOpenGL21 = ExistsOpenGLExtensions::NotExist;
    }
}
