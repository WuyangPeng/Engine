//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/25 17:56)

#include "System/SystemExport.h"

#include "GLARBESExtensions.h"
#include "GLUtility.h"
#include "System/Helper/Detail/OpenGL/GLPluginMacro.h"
#include "System/OpenGL/Flags/GLExtensionsFlags.h"
#include "System/OpenGL/OpenGLUtility.h"

// GL_ARB_ES2_compatibility

namespace System
{
    auto g_ExistsGlArbEs2Compatibility = ExistsOpenGLExtensions::Unknown;
}

System::ExistsOpenGLExtensions System::IsExistsGlArbEs2Compatibility() noexcept
{
    return g_ExistsGlArbEs2Compatibility;
}

namespace System
{
    using PgglClearDepthf = void(OPENGL_STDCALL*)(GLclampf d);
    using PgglDepthRangef = void(OPENGL_STDCALL*)(GLclampf n, GLclampf f);
    using PgglGetShaderPrecisionFormat = void(OPENGL_STDCALL*)(GLenum shadertype, GLenum precisiontype, GLint* range, GLint* precision);
    using PgglReleaseShaderCompiler = void(OPENGL_STDCALL*)();
    using PgglShaderBinary = void(OPENGL_STDCALL*)(GLsizei count, const GLuint* shaders, GLenum binaryformat, const void* binary, GLsizei length);
}

namespace System
{
    PgglClearDepthf gglClearDepthf{ nullptr };
    PgglDepthRangef gglDepthRangef{ nullptr };
    PgglGetShaderPrecisionFormat gglGetShaderPrecisionFormat{ nullptr };
    PgglReleaseShaderCompiler gglReleaseShaderCompiler{ nullptr };
    PgglShaderBinary gglShaderBinary{ nullptr };
}

void System::GlClearDepthf(GLclampf d) noexcept
{
    SYSTEM_BODY_1(gglClearDepthf, d);
}

void System::GlDepthRangef(GLclampf n, GLclampf f) noexcept
{
    SYSTEM_BODY_2(gglDepthRangef, n, f);
}

void System::GlGetShaderPrecisionFormat(GLenum shadertype, GLenum precisiontype, GLint* range, GLint* precision) noexcept
{
    SYSTEM_BODY_4(gglGetShaderPrecisionFormat, shadertype, precisiontype, range, precision);
}

void System::GlReleaseShaderCompiler() noexcept
{
    SYSTEM_BODY_0(gglReleaseShaderCompiler);
}

void System::GlShaderBinary(GLsizei count, const GLuint* shaders, GLenum binaryformat, const void* binary, GLsizei length) noexcept
{
    SYSTEM_BODY_5(gglShaderBinary, count, shaders, binaryformat, binary, length);
}

// GL_ARB_ES3_1_compatibility

namespace System
{
    auto g_ExistsGlArbEs31Compatibility = ExistsOpenGLExtensions::Unknown;
}

System::ExistsOpenGLExtensions System::IsExistsGlArbEs31Compatibility() noexcept
{
    return g_ExistsGlArbEs31Compatibility;
}

namespace System
{
    using PgglMemoryBarrierByRegion = void(OPENGL_STDCALL*)(GLbitfield barriers);
}

namespace System
{
    PgglMemoryBarrierByRegion gglMemoryBarrierByRegion{ nullptr };
}

void System::GlMemoryBarrierByRegion(GLbitfield barriers) noexcept
{
    SYSTEM_BODY_1(gglMemoryBarrierByRegion, barriers);
}

// GL_ARB_ES3_compatibility

namespace System
{
    auto g_ExistsGlArbEs3Compatibility = ExistsOpenGLExtensions::Unknown;
}

System::ExistsOpenGLExtensions System::IsExistsGlArbEs3Compatibility() noexcept
{
    return g_ExistsGlArbEs3Compatibility;
}

void System::InitGlArbEs2Compatibility()
{
    if (System::IsOpenGLSupportsExtension("GL_ARB_ES2_compatibility"))
    {
        g_ExistsGlArbEs2Compatibility = ExistsOpenGLExtensions::Exists;

        SYSTEM_GET_FUNCTION(gglClearDepthf);
        SYSTEM_GET_FUNCTION(gglDepthRangef);
        SYSTEM_GET_FUNCTION(gglGetShaderPrecisionFormat);
        SYSTEM_GET_FUNCTION(gglReleaseShaderCompiler);
        SYSTEM_GET_FUNCTION(gglShaderBinary);
    }
    else
    {
        g_ExistsGlArbEs2Compatibility = ExistsOpenGLExtensions::NotExist;
    }
}

void System::InitGlArbEs31Compatibility()
{
    if (System::IsOpenGLSupportsExtension("GL_ARB_ES3_compatibility"))
    {
        g_ExistsGlArbEs3Compatibility = ExistsOpenGLExtensions::Exists;
    }
    else
    {
        g_ExistsGlArbEs3Compatibility = ExistsOpenGLExtensions::NotExist;
    }
}

void System::InitGlArbEs3Compatibility()
{
    if (System::IsOpenGLSupportsExtension("GL_ARB_ES3_1_compatibility"))
    {
        g_ExistsGlArbEs31Compatibility = ExistsOpenGLExtensions::Exists;

        SYSTEM_GET_FUNCTION(gglMemoryBarrierByRegion);
    }
    else
    {
        g_ExistsGlArbEs31Compatibility = ExistsOpenGLExtensions::NotExist;
    }
}

void System::InitGlArbEs()
{
    InitGlArbEs2Compatibility();
    InitGlArbEs31Compatibility();
    InitGlArbEs3Compatibility();
}