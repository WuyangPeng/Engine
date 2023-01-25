///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.0 (2023/01/12 18:55)

#include "System/SystemExport.h"

#include "GL21Extensions.h"
#include "GLUtility.h"
#include "System/Helper/Detail/OpenGL/GLPluginMacro.h"
#include "System/OpenGL/Flags/GLExtensionsFlags.h"
#include "System/OpenGL/OpenGLUtility.h"

// OpenGL 2.1
namespace System
{
    auto existsOpenGL21 = ExistsOpenGLExtensions::Unknown;

    PFNGLUNIFORMMATRIX2X3FVPROC glUniformMatrix2x3fv{ nullptr };
    PFNGLUNIFORMMATRIX3X2FVPROC glUniformMatrix3x2fv{ nullptr };
    PFNGLUNIFORMMATRIX2X4FVPROC glUniformMatrix2x4fv{ nullptr };
    PFNGLUNIFORMMATRIX4X2FVPROC glUniformMatrix4x2fv{ nullptr };
    PFNGLUNIFORMMATRIX3X4FVPROC glUniformMatrix3x4fv{ nullptr };
    PFNGLUNIFORMMATRIX4X3FVPROC glUniformMatrix4x3fv{ nullptr };
}

System::ExistsOpenGLExtensions System::IsExistsOpenGL21() noexcept
{
    return existsOpenGL21;
}

void System::InitOpenGL21() noexcept
{
    if (System::OpenGLSystemVersion::Version21 <= System::GetOpenGLVersion())
    {
        existsOpenGL21 = ExistsOpenGLExtensions::Exists;

        SYSTEM_GET_FUNCTION(glUniformMatrix2x3fv);
        SYSTEM_GET_FUNCTION(glUniformMatrix3x2fv);
        SYSTEM_GET_FUNCTION(glUniformMatrix2x4fv);
        SYSTEM_GET_FUNCTION(glUniformMatrix4x2fv);
        SYSTEM_GET_FUNCTION(glUniformMatrix3x4fv);
        SYSTEM_GET_FUNCTION(glUniformMatrix4x3fv);
    }
    else
    {
        existsOpenGL21 = ExistsOpenGLExtensions::NotExist;
    }
}

void System::GLUniformMatrix2x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept
{
    SYSTEM_BODY_4(glUniformMatrix2x3fv, location, count, transpose, value);
}

void System::GLUniformMatrix3x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept
{
    SYSTEM_BODY_4(glUniformMatrix3x2fv, location, count, transpose, value);
}

void System::GLUniformMatrix2x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept
{
    SYSTEM_BODY_4(glUniformMatrix2x4fv, location, count, transpose, value);
}

void System::GLUniformMatrix4x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept
{
    SYSTEM_BODY_4(glUniformMatrix4x2fv, location, count, transpose, value);
}

void System::GLUniformMatrix3x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept
{
    SYSTEM_BODY_4(glUniformMatrix3x4fv, location, count, transpose, value);
}

void System::GLUniformMatrix4x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) noexcept
{
    SYSTEM_BODY_4(glUniformMatrix4x3fv, location, count, transpose, value);
}
