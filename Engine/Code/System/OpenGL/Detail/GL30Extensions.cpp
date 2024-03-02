/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/21 17:20)

#include "System/SystemExport.h"

#include "GL30Extensions.h"
#include "System/Helper/Detail/OpenGL/GLPluginMacro.h"
#include "System/OpenGL/Flags/GLExtensionsFlags.h"
#include "System/OpenGL/OpenGLUtility.h"

// OpenGL 3.0

namespace System
{
    auto existsOpenGL30 = ExistsOpenGLExtensions::Unknown;

    PFNGLCOLORMASKIPROC glColorMaski{ nullptr };
    PFNGLGETBOOLEANI_VPROC glGetBooleani_v{ nullptr };
    PFNGLGETINTEGERI_VPROC glGetIntegeri_v{ nullptr };
    PFNGLENABLEIPROC glEnablei{ nullptr };
    PFNGLDISABLEIPROC glDisablei{ nullptr };
    PFNGLISENABLEDIPROC glIsEnabledi{ nullptr };
    PFNGLBEGINTRANSFORMFEEDBACKPROC glBeginTransformFeedback{ nullptr };
    PFNGLENDTRANSFORMFEEDBACKPROC glEndTransformFeedback{ nullptr };
    PFNGLBINDBUFFERRANGEPROC glBindBufferRange{ nullptr };
    PFNGLBINDBUFFERBASEPROC glBindBufferBase{ nullptr };
    PFNGLTRANSFORMFEEDBACKVARYINGSPROC glTransformFeedbackVaryings{ nullptr };
    PFNGLGETTRANSFORMFEEDBACKVARYINGPROC glGetTransformFeedbackVarying{ nullptr };
    PFNGLCLAMPCOLORPROC glClampColor{ nullptr };
    PFNGLBEGINCONDITIONALRENDERPROC glBeginConditionalRender{ nullptr };
    PFNGLENDCONDITIONALRENDERPROC glEndConditionalRender{ nullptr };
    PFNGLVERTEXATTRIBIPOINTERPROC glVertexAttribIPointer{ nullptr };
    PFNGLGETVERTEXATTRIBIIVPROC glGetVertexAttribIiv{ nullptr };
    PFNGLGETVERTEXATTRIBIUIVPROC glGetVertexAttribIuiv{ nullptr };
    PFNGLVERTEXATTRIBI1IPROC glVertexAttribI1i{ nullptr };
    PFNGLVERTEXATTRIBI2IPROC glVertexAttribI2i{ nullptr };
    PFNGLVERTEXATTRIBI3IPROC glVertexAttribI3i{ nullptr };
    PFNGLVERTEXATTRIBI4IPROC glVertexAttribI4i{ nullptr };
    PFNGLVERTEXATTRIBI1UIPROC glVertexAttribI1ui{ nullptr };
    PFNGLVERTEXATTRIBI2UIPROC glVertexAttribI2ui{ nullptr };
    PFNGLVERTEXATTRIBI3UIPROC glVertexAttribI3ui{ nullptr };
    PFNGLVERTEXATTRIBI4UIPROC glVertexAttribI4ui{ nullptr };
    PFNGLVERTEXATTRIBI1IVPROC glVertexAttribI1iv{ nullptr };
    PFNGLVERTEXATTRIBI2IVPROC glVertexAttribI2iv{ nullptr };
    PFNGLVERTEXATTRIBI3IVPROC glVertexAttribI3iv{ nullptr };
    PFNGLVERTEXATTRIBI4IVPROC glVertexAttribI4iv{ nullptr };
    PFNGLVERTEXATTRIBI1UIVPROC glVertexAttribI1uiv{ nullptr };
    PFNGLVERTEXATTRIBI2UIVPROC glVertexAttribI2uiv{ nullptr };
    PFNGLVERTEXATTRIBI3UIVPROC glVertexAttribI3uiv{ nullptr };
    PFNGLVERTEXATTRIBI4UIVPROC glVertexAttribI4uiv{ nullptr };
    PFNGLVERTEXATTRIBI4BVPROC glVertexAttribI4bv{ nullptr };
    PFNGLVERTEXATTRIBI4SVPROC glVertexAttribI4sv{ nullptr };
    PFNGLVERTEXATTRIBI4UBVPROC glVertexAttribI4ubv{ nullptr };
    PFNGLVERTEXATTRIBI4USVPROC glVertexAttribI4usv{ nullptr };
    PFNGLGETUNIFORMUIVPROC glGetUniformuiv{ nullptr };
    PFNGLBINDFRAGDATALOCATIONPROC glBindFragDataLocation{ nullptr };
    PFNGLGETFRAGDATALOCATIONPROC glGetFragDataLocation{ nullptr };
    PFNGLUNIFORM1UIPROC glUniform1ui{ nullptr };
    PFNGLUNIFORM2UIPROC glUniform2ui{ nullptr };
    PFNGLUNIFORM3UIPROC glUniform3ui{ nullptr };
    PFNGLUNIFORM4UIPROC glUniform4ui{ nullptr };
    PFNGLUNIFORM1UIVPROC glUniform1uiv{ nullptr };
    PFNGLUNIFORM2UIVPROC glUniform2uiv{ nullptr };
    PFNGLUNIFORM3UIVPROC glUniform3uiv{ nullptr };
    PFNGLUNIFORM4UIVPROC glUniform4uiv{ nullptr };
    PFNGLTEXPARAMETERIIVPROC glTexParameterIiv{ nullptr };
    PFNGLTEXPARAMETERIUIVPROC glTexParameterIuiv{ nullptr };
    PFNGLGETTEXPARAMETERIIVPROC glGetTexParameterIiv{ nullptr };
    PFNGLGETTEXPARAMETERIUIVPROC glGetTexParameterIuiv{ nullptr };
    PFNGLCLEARBUFFERIVPROC glClearBufferiv{ nullptr };
    PFNGLCLEARBUFFERUIVPROC glClearBufferuiv{ nullptr };
    PFNGLCLEARBUFFERFVPROC glClearBufferfv{ nullptr };
    PFNGLCLEARBUFFERFIPROC glClearBufferfi{ nullptr };
    PFNGLGETSTRINGIPROC glGetStringi{ nullptr };
    PFNGLISRENDERBUFFERPROC glIsRenderbuffer{ nullptr };
    PFNGLBINDRENDERBUFFERPROC glBindRenderbuffer{ nullptr };
    PFNGLDELETERENDERBUFFERSPROC glDeleteRenderbuffers{ nullptr };
    PFNGLGENRENDERBUFFERSPROC glGenRenderbuffers{ nullptr };
    PFNGLRENDERBUFFERSTORAGEPROC glRenderbufferStorage{ nullptr };
    PFNGLGETRENDERBUFFERPARAMETERIVPROC glGetRenderbufferParameteriv{ nullptr };
    PFNGLISFRAMEBUFFERPROC glIsFramebuffer{ nullptr };
    PFNGLBINDFRAMEBUFFERPROC glBindFramebuffer{ nullptr };
    PFNGLDELETEFRAMEBUFFERSPROC glDeleteFramebuffers{ nullptr };
    PFNGLGENFRAMEBUFFERSPROC glGenFramebuffers{ nullptr };
    PFNGLCHECKFRAMEBUFFERSTATUSPROC glCheckFramebufferStatus{ nullptr };
    PFNGLFRAMEBUFFERTEXTURE1DPROC glFramebufferTexture1D{ nullptr };
    PFNGLFRAMEBUFFERTEXTURE2DPROC glFramebufferTexture2D{ nullptr };
    PFNGLFRAMEBUFFERTEXTURE3DPROC glFramebufferTexture3D{ nullptr };
    PFNGLFRAMEBUFFERRENDERBUFFERPROC glFramebufferRenderbuffer{ nullptr };
    PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC glGetFramebufferAttachmentParameteriv{ nullptr };
    PFNGLGENERATEMIPMAPPROC glGenerateMipmap{ nullptr };
    PFNGLBLITFRAMEBUFFERPROC glBlitFramebuffer{ nullptr };
    PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC glRenderbufferStorageMultisample{ nullptr };
    PFNGLFRAMEBUFFERTEXTURELAYERPROC glFramebufferTextureLayer{ nullptr };
    PFNGLMAPBUFFERRANGEPROC glMapBufferRange{ nullptr };
    PFNGLFLUSHMAPPEDBUFFERRANGEPROC glFlushMappedBufferRange{ nullptr };
    PFNGLBINDVERTEXARRAYPROC glBindVertexArray{ nullptr };
    PFNGLDELETEVERTEXARRAYSPROC glDeleteVertexArrays{ nullptr };
    PFNGLGENVERTEXARRAYSPROC glGenVertexArrays{ nullptr };
    PFNGLISVERTEXARRAYPROC glIsVertexArray{ nullptr };
}

System::ExistsOpenGLExtensions System::IsExistsOpenGL30() noexcept
{
    return existsOpenGL30;
}

void System::InitOpenGL30() noexcept
{
    if (OpenGLSystemVersion::Version30 <= System::GetOpenGLVersion())
    {
        existsOpenGL30 = ExistsOpenGLExtensions::Exists;

        SYSTEM_GET_FUNCTION(glColorMaski);
        SYSTEM_GET_FUNCTION(glGetBooleani_v);
        SYSTEM_GET_FUNCTION(glGetIntegeri_v);
        SYSTEM_GET_FUNCTION(glEnablei);
        SYSTEM_GET_FUNCTION(glDisablei);
        SYSTEM_GET_FUNCTION(glIsEnabledi);
        SYSTEM_GET_FUNCTION(glBeginTransformFeedback);
        SYSTEM_GET_FUNCTION(glEndTransformFeedback);
        SYSTEM_GET_FUNCTION(glBindBufferRange);
        SYSTEM_GET_FUNCTION(glBindBufferBase);
        SYSTEM_GET_FUNCTION(glTransformFeedbackVaryings);
        SYSTEM_GET_FUNCTION(glGetTransformFeedbackVarying);
        SYSTEM_GET_FUNCTION(glClampColor);
        SYSTEM_GET_FUNCTION(glBeginConditionalRender);
        SYSTEM_GET_FUNCTION(glEndConditionalRender);
        SYSTEM_GET_FUNCTION(glVertexAttribIPointer);
        SYSTEM_GET_FUNCTION(glGetVertexAttribIiv);
        SYSTEM_GET_FUNCTION(glGetVertexAttribIuiv);
        SYSTEM_GET_FUNCTION(glVertexAttribI1i);
        SYSTEM_GET_FUNCTION(glVertexAttribI2i);
        SYSTEM_GET_FUNCTION(glVertexAttribI3i);
        SYSTEM_GET_FUNCTION(glVertexAttribI4i);
        SYSTEM_GET_FUNCTION(glVertexAttribI1ui);
        SYSTEM_GET_FUNCTION(glVertexAttribI2ui);
        SYSTEM_GET_FUNCTION(glVertexAttribI3ui);
        SYSTEM_GET_FUNCTION(glVertexAttribI4ui);
        SYSTEM_GET_FUNCTION(glVertexAttribI1iv);
        SYSTEM_GET_FUNCTION(glVertexAttribI2iv);
        SYSTEM_GET_FUNCTION(glVertexAttribI3iv);
        SYSTEM_GET_FUNCTION(glVertexAttribI4iv);
        SYSTEM_GET_FUNCTION(glVertexAttribI1uiv);
        SYSTEM_GET_FUNCTION(glVertexAttribI2uiv);
        SYSTEM_GET_FUNCTION(glVertexAttribI3uiv);
        SYSTEM_GET_FUNCTION(glVertexAttribI4uiv);
        SYSTEM_GET_FUNCTION(glVertexAttribI4bv);
        SYSTEM_GET_FUNCTION(glVertexAttribI4sv);
        SYSTEM_GET_FUNCTION(glVertexAttribI4ubv);
        SYSTEM_GET_FUNCTION(glVertexAttribI4usv);
        SYSTEM_GET_FUNCTION(glGetUniformuiv);
        SYSTEM_GET_FUNCTION(glBindFragDataLocation);
        SYSTEM_GET_FUNCTION(glGetFragDataLocation);
        SYSTEM_GET_FUNCTION(glUniform1ui);
        SYSTEM_GET_FUNCTION(glUniform2ui);
        SYSTEM_GET_FUNCTION(glUniform3ui);
        SYSTEM_GET_FUNCTION(glUniform4ui);
        SYSTEM_GET_FUNCTION(glUniform1uiv);
        SYSTEM_GET_FUNCTION(glUniform2uiv);
        SYSTEM_GET_FUNCTION(glUniform3uiv);
        SYSTEM_GET_FUNCTION(glUniform4uiv);
        SYSTEM_GET_FUNCTION(glTexParameterIiv);
        SYSTEM_GET_FUNCTION(glTexParameterIuiv);
        SYSTEM_GET_FUNCTION(glGetTexParameterIiv);
        SYSTEM_GET_FUNCTION(glGetTexParameterIuiv);
        SYSTEM_GET_FUNCTION(glClearBufferiv);
        SYSTEM_GET_FUNCTION(glClearBufferuiv);
        SYSTEM_GET_FUNCTION(glClearBufferfv);
        SYSTEM_GET_FUNCTION(glClearBufferfi);
        SYSTEM_GET_FUNCTION(glGetStringi);

        SYSTEM_GET_FUNCTION(glIsRenderbuffer);
        SYSTEM_GET_FUNCTION(glBindRenderbuffer);
        SYSTEM_GET_FUNCTION(glDeleteRenderbuffers);
        SYSTEM_GET_FUNCTION(glGenRenderbuffers);
        SYSTEM_GET_FUNCTION(glRenderbufferStorage);
        SYSTEM_GET_FUNCTION(glGetRenderbufferParameteriv);
        SYSTEM_GET_FUNCTION(glIsFramebuffer);
        SYSTEM_GET_FUNCTION(glBindFramebuffer);
        SYSTEM_GET_FUNCTION(glDeleteFramebuffers);
        SYSTEM_GET_FUNCTION(glGenFramebuffers);
        SYSTEM_GET_FUNCTION(glCheckFramebufferStatus);
        SYSTEM_GET_FUNCTION(glFramebufferTexture1D);
        SYSTEM_GET_FUNCTION(glFramebufferTexture2D);
        SYSTEM_GET_FUNCTION(glFramebufferTexture3D);
        SYSTEM_GET_FUNCTION(glFramebufferRenderbuffer);
        SYSTEM_GET_FUNCTION(glGetFramebufferAttachmentParameteriv);
        SYSTEM_GET_FUNCTION(glGenerateMipmap);
        SYSTEM_GET_FUNCTION(glBlitFramebuffer);
        SYSTEM_GET_FUNCTION(glRenderbufferStorageMultisample);
        SYSTEM_GET_FUNCTION(glFramebufferTextureLayer);
        SYSTEM_GET_FUNCTION(glMapBufferRange);
        SYSTEM_GET_FUNCTION(glFlushMappedBufferRange);
        SYSTEM_GET_FUNCTION(glBindVertexArray);
        SYSTEM_GET_FUNCTION(glDeleteVertexArrays);
        SYSTEM_GET_FUNCTION(glGenVertexArrays);
        SYSTEM_GET_FUNCTION(glIsVertexArray);
    }
    else
    {
        existsOpenGL30 = ExistsOpenGLExtensions::NotExist;
    }
}

void System::GLColorMaskI(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a) noexcept
{
    SYSTEM_BODY_5(glColorMaski, index, r, g, b, a);
}

void System::GLGetBooleanIv(GLenum target, GLuint index, GLboolean* data) noexcept
{
    SYSTEM_BODY_3(glGetBooleani_v, target, index, data);
}

void System::GLGetIntegerIv(GLenum target, GLuint index, GLint* data) noexcept
{
    SYSTEM_BODY_3(glGetIntegeri_v, target, index, data);
}

void System::GLEnableI(GLenum target, GLuint index) noexcept
{
    SYSTEM_BODY_2(glEnablei, target, index);
}

void System::GLDisableI(GLenum target, GLuint index) noexcept
{
    SYSTEM_BODY_2(glDisablei, target, index);
}

GLboolean System::GLIsEnabledI(GLenum target, GLuint index) noexcept
{
    SYSTEM_BODY_2_RESULT(glIsEnabledi, target, index, GL_FALSE);
}

void System::GLBeginTransformFeedback(GLenum primitiveMode) noexcept
{
    SYSTEM_BODY_1(glBeginTransformFeedback, primitiveMode);
}

void System::GLEndTransformFeedback() noexcept
{
    SYSTEM_BODY_0(glEndTransformFeedback);
}

void System::GLBindBufferRange(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size) noexcept
{
    SYSTEM_BODY_5(glBindBufferRange, target, index, buffer, offset, size);
}

void System::GLBindBufferBase(GLenum target, GLuint index, GLuint buffer) noexcept
{
    SYSTEM_BODY_3(glBindBufferBase, target, index, buffer);
}

void System::GLTransformFeedbackVaryings(GLuint program, GLsizei count, const GLchar* const* varyings, GLenum bufferMode) noexcept
{
    SYSTEM_BODY_4(glTransformFeedbackVaryings, program, count, varyings, bufferMode);
}

void System::GLGetTransformFeedbackVarying(GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLsizei* size, GLenum* type, GLchar* name) noexcept
{
    SYSTEM_BODY_7(glGetTransformFeedbackVarying, program, index, bufSize, length, size, type, name);
}

void System::GLClampColor(GLenum target, GLenum clamp) noexcept
{
    SYSTEM_BODY_2(glClampColor, target, clamp);
}

void System::GLBeginConditionalRender(GLuint id, GLenum mode) noexcept
{
    SYSTEM_BODY_2(glBeginConditionalRender, id, mode);
}

void System::GLEndConditionalRender() noexcept
{
    SYSTEM_BODY_0(glEndConditionalRender);
}

void System::GLVertexAttribIPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const void* pointer) noexcept
{
    SYSTEM_BODY_5(glVertexAttribIPointer, index, size, type, stride, pointer);
}

void System::GLGetVertexAttribIiv(GLuint index, GLenum pName, GLint* params) noexcept
{
    SYSTEM_BODY_3(glGetVertexAttribIiv, index, pName, params);
}

void System::GLGetVertexAttribIUiv(GLuint index, GLenum pName, GLuint* params) noexcept
{
    SYSTEM_BODY_3(glGetVertexAttribIuiv, index, pName, params);
}

void System::GLVertexAttribI1I(GLuint index, GLint x) noexcept
{
    SYSTEM_BODY_2(glVertexAttribI1i, index, x);
}

void System::GLVertexAttribI2I(GLuint index, GLint x, GLint y) noexcept
{
    SYSTEM_BODY_3(glVertexAttribI2i, index, x, y);
}

void System::GLVertexAttribI3I(GLuint index, GLint x, GLint y, GLint z) noexcept
{
    SYSTEM_BODY_4(glVertexAttribI3i, index, x, y, z);
}

void System::GLVertexAttribI4I(GLuint index, GLint x, GLint y, GLint z, GLint w) noexcept
{
    SYSTEM_BODY_5(glVertexAttribI4i, index, x, y, z, w);
}

void System::GLVertexAttribI1Ui(GLuint index, GLuint x) noexcept
{
    SYSTEM_BODY_2(glVertexAttribI1ui, index, x);
}

void System::GLVertexAttribI2Ui(GLuint index, GLuint x, GLuint y) noexcept
{
    SYSTEM_BODY_3(glVertexAttribI2ui, index, x, y);
}

void System::GLVertexAttribI3Ui(GLuint index, GLuint x, GLuint y, GLuint z) noexcept
{
    SYSTEM_BODY_4(glVertexAttribI3ui, index, x, y, z);
}

void System::GLVertexAttribI4Ui(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w) noexcept
{
    SYSTEM_BODY_5(glVertexAttribI4ui, index, x, y, z, w);
}

void System::GLVertexAttribI1Iv(GLuint index, const GLint* v) noexcept
{
    SYSTEM_BODY_2(glVertexAttribI1iv, index, v);
}

void System::GLVertexAttribI2Iv(GLuint index, const GLint* v) noexcept
{
    SYSTEM_BODY_2(glVertexAttribI2iv, index, v);
}

void System::GLVertexAttribI3Iv(GLuint index, const GLint* v) noexcept
{
    SYSTEM_BODY_2(glVertexAttribI3iv, index, v);
}

void System::GLVertexAttribI4Iv(GLuint index, const GLint* v) noexcept
{
    SYSTEM_BODY_2(glVertexAttribI4iv, index, v);
}

void System::GLVertexAttribI1Uiv(GLuint index, const GLuint* v) noexcept
{
    SYSTEM_BODY_2(glVertexAttribI1uiv, index, v);
}

void System::GLVertexAttribI2Uiv(GLuint index, const GLuint* v) noexcept
{
    SYSTEM_BODY_2(glVertexAttribI2uiv, index, v);
}

void System::GLVertexAttribI3Uiv(GLuint index, const GLuint* v) noexcept
{
    SYSTEM_BODY_2(glVertexAttribI3uiv, index, v);
}

void System::GLVertexAttribI4Uiv(GLuint index, const GLuint* v) noexcept
{
    SYSTEM_BODY_2(glVertexAttribI4uiv, index, v);
}

void System::GLVertexAttribI4Bv(GLuint index, const GLbyte* v) noexcept
{
    SYSTEM_BODY_2(glVertexAttribI4bv, index, v);
}

void System::GLVertexAttribI4Sv(GLuint index, const GLshort* v) noexcept
{
    SYSTEM_BODY_2(glVertexAttribI4sv, index, v);
}

void System::GLVertexAttribI4Ubv(GLuint index, const GLubyte* v) noexcept
{
    SYSTEM_BODY_2(glVertexAttribI4ubv, index, v);
}

void System::GLVertexAttribI4Usv(GLuint index, const GLushort* v) noexcept
{
    SYSTEM_BODY_2(glVertexAttribI4usv, index, v);
}

void System::GLGetUniformUiv(GLuint program, GLint location, GLuint* params) noexcept
{
    SYSTEM_BODY_3(glGetUniformuiv, program, location, params);
}

void System::GLBindFragDataLocation(GLuint program, GLuint color, const GLchar* name) noexcept
{
    SYSTEM_BODY_3(glBindFragDataLocation, program, color, name);
}

GLint System::GLGetFragDataLocation(GLuint program, const GLchar* name) noexcept
{
    SYSTEM_BODY_2_RESULT(glGetFragDataLocation, program, name, 0);
}

void System::GLUniform1Ui(GLint location, GLuint v0) noexcept
{
    SYSTEM_BODY_2(glUniform1ui, location, v0);
}

void System::GLUniform2Ui(GLint location, GLuint v0, GLuint v1) noexcept
{
    SYSTEM_BODY_3(glUniform2ui, location, v0, v1);
}

void System::GLUniform3Ui(GLint location, GLuint v0, GLuint v1, GLuint v2) noexcept
{
    SYSTEM_BODY_4(glUniform3ui, location, v0, v1, v2);
}

void System::GLUniform4Ui(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3) noexcept
{
    SYSTEM_BODY_5(glUniform4ui, location, v0, v1, v2, v3);
}

void System::GLUniform1Uiv(GLint location, GLsizei count, const GLuint* value) noexcept
{
    SYSTEM_BODY_3(glUniform1uiv, location, count, value);
}

void System::GLUniform2Uiv(GLint location, GLsizei count, const GLuint* value) noexcept
{
    SYSTEM_BODY_3(glUniform2uiv, location, count, value);
}

void System::GLUniform3Uiv(GLint location, GLsizei count, const GLuint* value) noexcept
{
    SYSTEM_BODY_3(glUniform3uiv, location, count, value);
}

void System::GLUniform4Uiv(GLint location, GLsizei count, const GLuint* value) noexcept
{
    SYSTEM_BODY_3(glUniform4uiv, location, count, value);
}

void System::GLTexParameterIiv(GLenum target, GLenum pName, const GLint* params) noexcept
{
    SYSTEM_BODY_3(glTexParameterIiv, target, pName, params);
}

void System::GLTexParameterIUiv(GLenum target, GLenum pName, const GLuint* params) noexcept
{
    SYSTEM_BODY_3(glTexParameterIuiv, target, pName, params);
}

void System::GLGetTexParameterIiv(GLenum target, GLenum pName, GLint* params) noexcept
{
    SYSTEM_BODY_3(glGetTexParameterIiv, target, pName, params);
}

void System::GLGetTexParameterIUiv(GLenum target, GLenum pName, GLuint* params) noexcept
{
    SYSTEM_BODY_3(glGetTexParameterIuiv, target, pName, params);
}

void System::GLClearBufferIv(GLenum buffer, GLint drawBuffer, const GLint* value) noexcept
{
    SYSTEM_BODY_3(glClearBufferiv, buffer, drawBuffer, value);
}

void System::GLClearBufferUiv(GLenum buffer, GLint drawBuffer, const GLuint* value) noexcept
{
    SYSTEM_BODY_3(glClearBufferuiv, buffer, drawBuffer, value);
}

void System::GLClearBufferFv(GLenum buffer, GLint drawBuffer, const GLfloat* value) noexcept
{
    SYSTEM_BODY_3(glClearBufferfv, buffer, drawBuffer, value);
}

void System::GLClearBufferFi(GLenum buffer, GLint drawBuffer, GLfloat depth, GLint stencil) noexcept
{
    SYSTEM_BODY_4(glClearBufferfi, buffer, drawBuffer, depth, stencil);
}

const GLubyte* System::GLGetStringI(GLenum name, GLuint index) noexcept
{
    SYSTEM_BODY_2_RESULT(glGetStringi, name, index, nullptr);
}

GLboolean System::GLIsRenderBuffer(GLuint renderBuffer) noexcept
{
    SYSTEM_BODY_1_RESULT(glIsRenderbuffer, renderBuffer, GL_FALSE);
}

void System::GLBindRenderBuffer(GLenum target, GLuint renderBuffer) noexcept
{
    SYSTEM_BODY_2(glBindRenderbuffer, target, renderBuffer);
}

void System::GLDeleteRenderBuffers(GLsizei n, const GLuint* renderBuffers) noexcept
{
    SYSTEM_BODY_2(glDeleteRenderbuffers, n, renderBuffers);
}

void System::GLGenRenderBuffers(GLsizei n, GLuint* renderBuffers) noexcept
{
    SYSTEM_BODY_2(glGenRenderbuffers, n, renderBuffers);
}

void System::GLRenderBufferStorage(GLenum target, GLenum internalFormat, GLsizei width, GLsizei height) noexcept
{
    SYSTEM_BODY_4(glRenderbufferStorage, target, internalFormat, width, height);
}

void System::GLGetRenderBufferParameterIv(GLenum target, GLenum pName, GLint* params) noexcept
{
    SYSTEM_BODY_3(glGetRenderbufferParameteriv, target, pName, params);
}

GLboolean System::GLIsFrameBuffer(GLuint frameBuffer) noexcept
{
    SYSTEM_BODY_1_RESULT(glIsFramebuffer, frameBuffer, GL_FALSE);
}

void System::GLBindFrameBuffer(GLenum target, GLuint frameBuffer) noexcept
{
    SYSTEM_BODY_2(glBindFramebuffer, target, frameBuffer);
}

void System::GLDeleteFrameBuffers(GLsizei n, const GLuint* frameBuffers) noexcept
{
    SYSTEM_BODY_2(glDeleteFramebuffers, n, frameBuffers);
}

void System::GLGenFrameBuffers(GLsizei n, GLuint* frameBuffers) noexcept
{
    SYSTEM_BODY_2(glGenFramebuffers, n, frameBuffers);
}

GLenum System::GLCheckFrameBufferStatus(GLenum target) noexcept
{
    SYSTEM_BODY_1_RESULT(glCheckFramebufferStatus, target, 0);
}

void System::GLFrameBufferTexture1D(GLenum target, GLenum attachment, GLenum texTarget, GLuint texture, GLint level) noexcept
{
    SYSTEM_BODY_5(glFramebufferTexture1D, target, attachment, texTarget, texture, level);
}

void System::GLFrameBufferTexture2D(GLenum target, GLenum attachment, GLenum texTarget, GLuint texture, GLint level) noexcept
{
    SYSTEM_BODY_5(glFramebufferTexture2D, target, attachment, texTarget, texture, level);
}

void System::GLFrameBufferTexture3D(GLenum target, GLenum attachment, GLenum texTarget, GLuint texture, GLint level, GLint zOffset) noexcept
{
    SYSTEM_BODY_6(glFramebufferTexture3D, target, attachment, texTarget, texture, level, zOffset);
}

void System::GLFrameBufferRenderBuffer(GLenum target, GLenum attachment, GLenum renderBufferTarget, GLuint renderBuffer) noexcept
{
    SYSTEM_BODY_4(glFramebufferRenderbuffer, target, attachment, renderBufferTarget, renderBuffer);
}

void System::GLGetFrameBufferAttachmentParameterIv(GLenum target, GLenum attachment, GLenum pName, GLint* params) noexcept
{
    SYSTEM_BODY_4(glGetFramebufferAttachmentParameteriv, target, attachment, pName, params);
}

void System::GLGenerateMipmap(GLenum target) noexcept
{
    SYSTEM_BODY_1(glGenerateMipmap, target);
}

void System::GLBlitFrameBuffer(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter) noexcept
{
    SYSTEM_BODY_10(glBlitFramebuffer, srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);
}

void System::GLRenderBufferStorageMultiSample(GLenum target, GLsizei samples, GLenum internalFormat, GLsizei width, GLsizei height) noexcept
{
    SYSTEM_BODY_5(glRenderbufferStorageMultisample, target, samples, internalFormat, width, height);
}

void System::GLFrameBufferTextureLayer(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer) noexcept
{
    SYSTEM_BODY_5(glFramebufferTextureLayer, target, attachment, texture, level, layer);
}

void* System::GLMapBufferRange(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access) noexcept
{
    SYSTEM_BODY_4_RESULT(glMapBufferRange, target, offset, length, access, nullptr);
}

void System::GLFlushMappedBufferRange(GLenum target, GLintptr offset, GLsizeiptr length) noexcept
{
    SYSTEM_BODY_3(glFlushMappedBufferRange, target, offset, length);
}

void System::GLBindVertexArray(GLuint array) noexcept
{
    SYSTEM_BODY_1(glBindVertexArray, array);
}

void System::GLDeleteVertexArrays(GLsizei n, const GLuint* arrays) noexcept
{
    SYSTEM_BODY_2(glDeleteVertexArrays, n, arrays);
}

void System::GLGenVertexArrays(GLsizei n, GLuint* arrays) noexcept
{
    SYSTEM_BODY_2(glGenVertexArrays, n, arrays);
}

GLboolean System::GLIsVertexArray(GLuint array) noexcept
{
    SYSTEM_BODY_1_RESULT(glIsVertexArray, array, GL_FALSE);
}
