///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/29 23:37)

#include "System/SystemExport.h"

#include "GL45Extensions.h"
#include "System/Helper/Detail/OpenGL/GLPluginMacro.h"
#include "System/Helper/EnumCast.h"
#include "System/OpenGL/Flags/GLExtensionsFlags.h"
#include "System/OpenGL/OpenGLUtility.h"

// OpenGL 4.5
namespace System
{
    auto existsOpenGL45 = ExistsOpenGLExtensions::Unknown;

    PFNGLCLIPCONTROLPROC glClipControl{ nullptr };
    PFNGLCREATETRANSFORMFEEDBACKSPROC glCreateTransformFeedbacks{ nullptr };
    PFNGLTRANSFORMFEEDBACKBUFFERBASEPROC glTransformFeedbackBufferBase{ nullptr };
    PFNGLTRANSFORMFEEDBACKBUFFERRANGEPROC glTransformFeedbackBufferRange{ nullptr };
    PFNGLGETTRANSFORMFEEDBACKIVPROC glGetTransformFeedbackiv{ nullptr };
    PFNGLGETTRANSFORMFEEDBACKI_VPROC glGetTransformFeedbacki_v{ nullptr };
    PFNGLGETTRANSFORMFEEDBACKI64_VPROC glGetTransformFeedbacki64_v{ nullptr };
    PFNGLCREATEBUFFERSPROC glCreateBuffers{ nullptr };
    PFNGLNAMEDBUFFERSTORAGEPROC glNamedBufferStorage{ nullptr };
    PFNGLNAMEDBUFFERDATAPROC glNamedBufferData{ nullptr };
    PFNGLNAMEDBUFFERSUBDATAPROC glNamedBufferSubData{ nullptr };
    PFNGLCOPYNAMEDBUFFERSUBDATAPROC glCopyNamedBufferSubData{ nullptr };
    PFNGLCLEARNAMEDBUFFERDATAPROC glClearNamedBufferData{ nullptr };
    PFNGLCLEARNAMEDBUFFERSUBDATAPROC glClearNamedBufferSubData{ nullptr };
    PFNGLMAPNAMEDBUFFERPROC glMapNamedBuffer{ nullptr };
    PFNGLMAPNAMEDBUFFERRANGEPROC glMapNamedBufferRange{ nullptr };
    PFNGLUNMAPNAMEDBUFFERPROC glUnmapNamedBuffer{ nullptr };
    PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEPROC glFlushMappedNamedBufferRange{ nullptr };
    PFNGLGETNAMEDBUFFERPARAMETERIVPROC glGetNamedBufferParameteriv{ nullptr };
    PFNGLGETNAMEDBUFFERPARAMETERI64VPROC glGetNamedBufferParameteri64v{ nullptr };
    PFNGLGETNAMEDBUFFERPOINTERVPROC glGetNamedBufferPointerv{ nullptr };
    PFNGLGETNAMEDBUFFERSUBDATAPROC glGetNamedBufferSubData{ nullptr };
    PFNGLCREATEFRAMEBUFFERSPROC glCreateFramebuffers{ nullptr };
    PFNGLNAMEDFRAMEBUFFERRENDERBUFFERPROC glNamedFramebufferRenderbuffer{ nullptr };
    PFNGLNAMEDFRAMEBUFFERPARAMETERIPROC glNamedFramebufferParameteri{ nullptr };
    PFNGLNAMEDFRAMEBUFFERTEXTUREPROC glNamedFramebufferTexture{ nullptr };
    PFNGLNAMEDFRAMEBUFFERTEXTURELAYERPROC glNamedFramebufferTextureLayer{ nullptr };
    PFNGLNAMEDFRAMEBUFFERDRAWBUFFERPROC glNamedFramebufferDrawBuffer{ nullptr };
    PFNGLNAMEDFRAMEBUFFERDRAWBUFFERSPROC glNamedFramebufferDrawBuffers{ nullptr };
    PFNGLNAMEDFRAMEBUFFERREADBUFFERPROC glNamedFramebufferReadBuffer{ nullptr };
    PFNGLINVALIDATENAMEDFRAMEBUFFERDATAPROC glInvalidateNamedFramebufferData{ nullptr };
    PFNGLINVALIDATENAMEDFRAMEBUFFERSUBDATAPROC glInvalidateNamedFramebufferSubData{ nullptr };
    PFNGLCLEARNAMEDFRAMEBUFFERIVPROC glClearNamedFramebufferiv{ nullptr };
    PFNGLCLEARNAMEDFRAMEBUFFERUIVPROC glClearNamedFramebufferuiv{ nullptr };
    PFNGLCLEARNAMEDFRAMEBUFFERFVPROC glClearNamedFramebufferfv{ nullptr };
    PFNGLCLEARNAMEDFRAMEBUFFERFIPROC glClearNamedFramebufferfi{ nullptr };
    PFNGLBLITNAMEDFRAMEBUFFERPROC glBlitNamedFramebuffer{ nullptr };
    PFNGLCHECKNAMEDFRAMEBUFFERSTATUSPROC glCheckNamedFramebufferStatus{ nullptr };
    PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVPROC glGetNamedFramebufferParameteriv{ nullptr };
    PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVPROC glGetNamedFramebufferAttachmentParameteriv{ nullptr };
    PFNGLCREATERENDERBUFFERSPROC glCreateRenderbuffers{ nullptr };
    PFNGLNAMEDRENDERBUFFERSTORAGEPROC glNamedRenderbufferStorage{ nullptr };
    PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEPROC glNamedRenderbufferStorageMultisample{ nullptr };
    PFNGLGETNAMEDRENDERBUFFERPARAMETERIVPROC glGetNamedRenderbufferParameteriv{ nullptr };
    PFNGLCREATETEXTURESPROC glCreateTextures{ nullptr };
    PFNGLTEXTUREBUFFERPROC glTextureBuffer{ nullptr };
    PFNGLTEXTUREBUFFERRANGEPROC glTextureBufferRange{ nullptr };
    PFNGLTEXTURESTORAGE1DPROC glTextureStorage1D{ nullptr };
    PFNGLTEXTURESTORAGE2DPROC glTextureStorage2D{ nullptr };
    PFNGLTEXTURESTORAGE3DPROC glTextureStorage3D{ nullptr };
    PFNGLTEXTURESTORAGE2DMULTISAMPLEPROC glTextureStorage2DMultisample{ nullptr };
    PFNGLTEXTURESTORAGE3DMULTISAMPLEPROC glTextureStorage3DMultisample{ nullptr };
    PFNGLTEXTURESUBIMAGE1DPROC glTextureSubImage1D{ nullptr };
    PFNGLTEXTURESUBIMAGE2DPROC glTextureSubImage2D{ nullptr };
    PFNGLTEXTURESUBIMAGE3DPROC glTextureSubImage3D{ nullptr };
    PFNGLCOMPRESSEDTEXTURESUBIMAGE1DPROC glCompressedTextureSubImage1D{ nullptr };
    PFNGLCOMPRESSEDTEXTURESUBIMAGE2DPROC glCompressedTextureSubImage2D{ nullptr };
    PFNGLCOMPRESSEDTEXTURESUBIMAGE3DPROC glCompressedTextureSubImage3D{ nullptr };
    PFNGLCOPYTEXTURESUBIMAGE1DPROC glCopyTextureSubImage1D{ nullptr };
    PFNGLCOPYTEXTURESUBIMAGE2DPROC glCopyTextureSubImage2D{ nullptr };
    PFNGLCOPYTEXTURESUBIMAGE3DPROC glCopyTextureSubImage3D{ nullptr };
    PFNGLTEXTUREPARAMETERFPROC glTextureParameterf{ nullptr };
    PFNGLTEXTUREPARAMETERFVPROC glTextureParameterfv{ nullptr };
    PFNGLTEXTUREPARAMETERIPROC glTextureParameteri{ nullptr };
    PFNGLTEXTUREPARAMETERIIVPROC glTextureParameterIiv{ nullptr };
    PFNGLTEXTUREPARAMETERIUIVPROC glTextureParameterIuiv{ nullptr };
    PFNGLTEXTUREPARAMETERIVPROC glTextureParameteriv{ nullptr };
    PFNGLGENERATETEXTUREMIPMAPPROC glGenerateTextureMipmap{ nullptr };
    PFNGLBINDTEXTUREUNITPROC glBindTextureUnit{ nullptr };
    PFNGLGETTEXTUREIMAGEPROC glGetTextureImage{ nullptr };
    PFNGLGETCOMPRESSEDTEXTUREIMAGEPROC glGetCompressedTextureImage{ nullptr };
    PFNGLGETTEXTURELEVELPARAMETERFVPROC glGetTextureLevelParameterfv{ nullptr };
    PFNGLGETTEXTURELEVELPARAMETERIVPROC glGetTextureLevelParameteriv{ nullptr };
    PFNGLGETTEXTUREPARAMETERFVPROC glGetTextureParameterfv{ nullptr };
    PFNGLGETTEXTUREPARAMETERIIVPROC glGetTextureParameterIiv{ nullptr };
    PFNGLGETTEXTUREPARAMETERIUIVPROC glGetTextureParameterIuiv{ nullptr };
    PFNGLGETTEXTUREPARAMETERIVPROC glGetTextureParameteriv{ nullptr };
    PFNGLCREATEVERTEXARRAYSPROC glCreateVertexArrays{ nullptr };
    PFNGLDISABLEVERTEXARRAYATTRIBPROC glDisableVertexArrayAttrib{ nullptr };
    PFNGLENABLEVERTEXARRAYATTRIBPROC glEnableVertexArrayAttrib{ nullptr };
    PFNGLVERTEXARRAYELEMENTBUFFERPROC glVertexArrayElementBuffer{ nullptr };
    PFNGLVERTEXARRAYVERTEXBUFFERPROC glVertexArrayVertexBuffer{ nullptr };
    PFNGLVERTEXARRAYVERTEXBUFFERSPROC glVertexArrayVertexBuffers{ nullptr };
    PFNGLVERTEXARRAYATTRIBBINDINGPROC glVertexArrayAttribBinding{ nullptr };
    PFNGLVERTEXARRAYATTRIBFORMATPROC glVertexArrayAttribFormat{ nullptr };
    PFNGLVERTEXARRAYATTRIBIFORMATPROC glVertexArrayAttribIFormat{ nullptr };
    PFNGLVERTEXARRAYATTRIBLFORMATPROC glVertexArrayAttribLFormat{ nullptr };
    PFNGLVERTEXARRAYBINDINGDIVISORPROC glVertexArrayBindingDivisor{ nullptr };
    PFNGLGETVERTEXARRAYIVPROC glGetVertexArrayiv{ nullptr };
    PFNGLGETVERTEXARRAYINDEXEDIVPROC glGetVertexArrayIndexediv{ nullptr };
    PFNGLGETVERTEXARRAYINDEXED64IVPROC glGetVertexArrayIndexed64iv{ nullptr };
    PFNGLCREATESAMPLERSPROC glCreateSamplers{ nullptr };
    PFNGLCREATEPROGRAMPIPELINESPROC glCreateProgramPipelines{ nullptr };
    PFNGLCREATEQUERIESPROC glCreateQueries{ nullptr };
    PFNGLGETQUERYBUFFEROBJECTI64VPROC glGetQueryBufferObjecti64v{ nullptr };
    PFNGLGETQUERYBUFFEROBJECTIVPROC glGetQueryBufferObjectiv{ nullptr };
    PFNGLGETQUERYBUFFEROBJECTUI64VPROC glGetQueryBufferObjectui64v{ nullptr };
    PFNGLGETQUERYBUFFEROBJECTUIVPROC glGetQueryBufferObjectuiv{ nullptr };
    PFNGLMEMORYBARRIERBYREGIONPROC glMemoryBarrierByRegion{ nullptr };
    PFNGLGETTEXTURESUBIMAGEPROC glGetTextureSubImage{ nullptr };
    PFNGLGETCOMPRESSEDTEXTURESUBIMAGEPROC glGetCompressedTextureSubImage{ nullptr };
    PFNGLGETGRAPHICSRESETSTATUSPROC glGetGraphicsResetStatus{ nullptr };
    PFNGLGETNCOMPRESSEDTEXIMAGEPROC glGetnCompressedTexImage{ nullptr };
    PFNGLGETNTEXIMAGEPROC glGetnTexImage{ nullptr };
    PFNGLGETNUNIFORMDVPROC glGetnUniformdv{ nullptr };
    PFNGLGETNUNIFORMFVPROC glGetnUniformfv{ nullptr };
    PFNGLGETNUNIFORMIVPROC glGetnUniformiv{ nullptr };
    PFNGLGETNUNIFORMUIVPROC glGetnUniformuiv{ nullptr };
    PFNGLREADNPIXELSPROC glReadnPixels{ nullptr };
    PFNGLTEXTUREBARRIERPROC glTextureBarrier{ nullptr };
}

System::ExistsOpenGLExtensions System::IsExistsOpenGL45() noexcept
{
    return existsOpenGL45;
}

void System::InitOpenGL45() noexcept
{
    if (OpenGLSystemVersion::Version45 <= System::GetOpenGLVersion())
    {
        existsOpenGL45 = ExistsOpenGLExtensions::Exists;

        SYSTEM_GET_FUNCTION(glClipControl);
        SYSTEM_GET_FUNCTION(glCreateTransformFeedbacks);
        SYSTEM_GET_FUNCTION(glTransformFeedbackBufferBase);
        SYSTEM_GET_FUNCTION(glTransformFeedbackBufferRange);
        SYSTEM_GET_FUNCTION(glGetTransformFeedbackiv);
        SYSTEM_GET_FUNCTION(glGetTransformFeedbacki_v);
        SYSTEM_GET_FUNCTION(glGetTransformFeedbacki64_v);
        SYSTEM_GET_FUNCTION(glCreateBuffers);
        SYSTEM_GET_FUNCTION(glNamedBufferStorage);
        SYSTEM_GET_FUNCTION(glNamedBufferData);
        SYSTEM_GET_FUNCTION(glNamedBufferSubData);
        SYSTEM_GET_FUNCTION(glCopyNamedBufferSubData);
        SYSTEM_GET_FUNCTION(glClearNamedBufferData);
        SYSTEM_GET_FUNCTION(glClearNamedBufferSubData);
        SYSTEM_GET_FUNCTION(glMapNamedBuffer);
        SYSTEM_GET_FUNCTION(glMapNamedBufferRange);
        SYSTEM_GET_FUNCTION(glUnmapNamedBuffer);
        SYSTEM_GET_FUNCTION(glFlushMappedNamedBufferRange);
        SYSTEM_GET_FUNCTION(glGetNamedBufferParameteriv);
        SYSTEM_GET_FUNCTION(glGetNamedBufferParameteri64v);
        SYSTEM_GET_FUNCTION(glGetNamedBufferPointerv);
        SYSTEM_GET_FUNCTION(glGetNamedBufferSubData);
        SYSTEM_GET_FUNCTION(glCreateFramebuffers);
        SYSTEM_GET_FUNCTION(glNamedFramebufferRenderbuffer);
        SYSTEM_GET_FUNCTION(glNamedFramebufferParameteri);
        SYSTEM_GET_FUNCTION(glNamedFramebufferTexture);
        SYSTEM_GET_FUNCTION(glNamedFramebufferTextureLayer);
        SYSTEM_GET_FUNCTION(glNamedFramebufferDrawBuffer);
        SYSTEM_GET_FUNCTION(glNamedFramebufferDrawBuffers);
        SYSTEM_GET_FUNCTION(glNamedFramebufferReadBuffer);
        SYSTEM_GET_FUNCTION(glInvalidateNamedFramebufferData);
        SYSTEM_GET_FUNCTION(glInvalidateNamedFramebufferSubData);
        SYSTEM_GET_FUNCTION(glClearNamedFramebufferiv);
        SYSTEM_GET_FUNCTION(glClearNamedFramebufferuiv);
        SYSTEM_GET_FUNCTION(glClearNamedFramebufferfv);
        SYSTEM_GET_FUNCTION(glClearNamedFramebufferfi);
        SYSTEM_GET_FUNCTION(glBlitNamedFramebuffer);
        SYSTEM_GET_FUNCTION(glCheckNamedFramebufferStatus);
        SYSTEM_GET_FUNCTION(glGetNamedFramebufferParameteriv);
        SYSTEM_GET_FUNCTION(glGetNamedFramebufferAttachmentParameteriv);
        SYSTEM_GET_FUNCTION(glCreateRenderbuffers);
        SYSTEM_GET_FUNCTION(glNamedRenderbufferStorage);
        SYSTEM_GET_FUNCTION(glNamedRenderbufferStorageMultisample);
        SYSTEM_GET_FUNCTION(glGetNamedRenderbufferParameteriv);
        SYSTEM_GET_FUNCTION(glCreateTextures);
        SYSTEM_GET_FUNCTION(glTextureBuffer);
        SYSTEM_GET_FUNCTION(glTextureBufferRange);
        SYSTEM_GET_FUNCTION(glTextureStorage1D);
        SYSTEM_GET_FUNCTION(glTextureStorage2D);
        SYSTEM_GET_FUNCTION(glTextureStorage3D);
        SYSTEM_GET_FUNCTION(glTextureStorage2DMultisample);
        SYSTEM_GET_FUNCTION(glTextureStorage3DMultisample);
        SYSTEM_GET_FUNCTION(glTextureSubImage1D);
        SYSTEM_GET_FUNCTION(glTextureSubImage2D);
        SYSTEM_GET_FUNCTION(glTextureSubImage3D);
        SYSTEM_GET_FUNCTION(glCompressedTextureSubImage1D);
        SYSTEM_GET_FUNCTION(glCompressedTextureSubImage2D);
        SYSTEM_GET_FUNCTION(glCompressedTextureSubImage3D);
        SYSTEM_GET_FUNCTION(glCopyTextureSubImage1D);
        SYSTEM_GET_FUNCTION(glCopyTextureSubImage2D);
        SYSTEM_GET_FUNCTION(glCopyTextureSubImage3D);
        SYSTEM_GET_FUNCTION(glTextureParameterf);
        SYSTEM_GET_FUNCTION(glTextureParameterfv);
        SYSTEM_GET_FUNCTION(glTextureParameteri);
        SYSTEM_GET_FUNCTION(glTextureParameterIiv);
        SYSTEM_GET_FUNCTION(glTextureParameterIuiv);
        SYSTEM_GET_FUNCTION(glTextureParameteriv);
        SYSTEM_GET_FUNCTION(glGenerateTextureMipmap);
        SYSTEM_GET_FUNCTION(glBindTextureUnit);
        SYSTEM_GET_FUNCTION(glGetTextureImage);
        SYSTEM_GET_FUNCTION(glGetCompressedTextureImage);
        SYSTEM_GET_FUNCTION(glGetTextureLevelParameterfv);
        SYSTEM_GET_FUNCTION(glGetTextureLevelParameteriv);
        SYSTEM_GET_FUNCTION(glGetTextureParameterfv);
        SYSTEM_GET_FUNCTION(glGetTextureParameterIiv);
        SYSTEM_GET_FUNCTION(glGetTextureParameterIuiv);
        SYSTEM_GET_FUNCTION(glGetTextureParameteriv);
        SYSTEM_GET_FUNCTION(glCreateVertexArrays);
        SYSTEM_GET_FUNCTION(glDisableVertexArrayAttrib);
        SYSTEM_GET_FUNCTION(glEnableVertexArrayAttrib);
        SYSTEM_GET_FUNCTION(glVertexArrayElementBuffer);
        SYSTEM_GET_FUNCTION(glVertexArrayVertexBuffer);
        SYSTEM_GET_FUNCTION(glVertexArrayVertexBuffers);
        SYSTEM_GET_FUNCTION(glVertexArrayAttribBinding);
        SYSTEM_GET_FUNCTION(glVertexArrayAttribFormat);
        SYSTEM_GET_FUNCTION(glVertexArrayAttribIFormat);
        SYSTEM_GET_FUNCTION(glVertexArrayAttribLFormat);
        SYSTEM_GET_FUNCTION(glVertexArrayBindingDivisor);
        SYSTEM_GET_FUNCTION(glGetVertexArrayiv);
        SYSTEM_GET_FUNCTION(glGetVertexArrayIndexediv);
        SYSTEM_GET_FUNCTION(glGetVertexArrayIndexed64iv);
        SYSTEM_GET_FUNCTION(glCreateSamplers);
        SYSTEM_GET_FUNCTION(glCreateProgramPipelines);
        SYSTEM_GET_FUNCTION(glCreateQueries);
        SYSTEM_GET_FUNCTION(glGetQueryBufferObjecti64v);
        SYSTEM_GET_FUNCTION(glGetQueryBufferObjectiv);
        SYSTEM_GET_FUNCTION(glGetQueryBufferObjectui64v);
        SYSTEM_GET_FUNCTION(glGetQueryBufferObjectuiv);
        SYSTEM_GET_FUNCTION(glMemoryBarrierByRegion);
        SYSTEM_GET_FUNCTION(glGetTextureSubImage);
        SYSTEM_GET_FUNCTION(glGetCompressedTextureSubImage);
        SYSTEM_GET_FUNCTION(glGetGraphicsResetStatus);
        SYSTEM_GET_FUNCTION(glGetnCompressedTexImage);
        SYSTEM_GET_FUNCTION(glGetnTexImage);
        SYSTEM_GET_FUNCTION(glGetnUniformdv);
        SYSTEM_GET_FUNCTION(glGetnUniformfv);
        SYSTEM_GET_FUNCTION(glGetnUniformiv);
        SYSTEM_GET_FUNCTION(glGetnUniformuiv);
        SYSTEM_GET_FUNCTION(glReadnPixels);
        SYSTEM_GET_FUNCTION(glTextureBarrier);
    }
    else
    {
        existsOpenGL45 = ExistsOpenGLExtensions::NotExist;
    }
}

void System::GLClipControl(GLenum origin, GLenum depth) noexcept
{
    SYSTEM_BODY_2(glClipControl, origin, depth);
}

void System::GLCreateTransformFeedbacks(GLsizei n, GLuint* ids) noexcept
{
    SYSTEM_BODY_2(glCreateTransformFeedbacks, n, ids);
}

void System::GLTransformFeedbackBufferBase(GLuint xfb, GLuint index, GLuint buffer) noexcept
{
    SYSTEM_BODY_3(glTransformFeedbackBufferBase, xfb, index, buffer);
}

void System::GLTransformFeedbackBufferRange(GLuint xfb, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size) noexcept
{
    SYSTEM_BODY_5(glTransformFeedbackBufferRange, xfb, index, buffer, offset, size);
}

void System::GLGetTransformFeedbackiv(GLuint xfb, GLenum pname, GLint* param) noexcept
{
    SYSTEM_BODY_3(glGetTransformFeedbackiv, xfb, pname, param);
}

void System::GLGetTransformFeedbacki_v(GLuint xfb, GLenum pname, GLuint index, GLint* param) noexcept
{
    SYSTEM_BODY_4(glGetTransformFeedbacki_v, xfb, pname, index, param);
}

void System::GLGetTransformFeedbacki64_v(GLuint xfb, GLenum pname, GLuint index, GLint64* param) noexcept
{
    SYSTEM_BODY_4(glGetTransformFeedbacki64_v, xfb, pname, index, param);
}

void System::GLCreateBuffers(GLsizei n, GLuint* buffers) noexcept
{
    SYSTEM_BODY_2(glCreateBuffers, n, buffers);
}

void System::GLNamedBufferStorage(GLuint buffer, GLsizeiptr size, const void* data, GLbitfield flags) noexcept
{
    SYSTEM_BODY_4(glNamedBufferStorage, buffer, size, data, flags);
}

void System::GLNamedBufferData(GLuint buffer, GLsizeiptr size, const void* data, GLenum usage) noexcept
{
    SYSTEM_BODY_4(glNamedBufferData, buffer, size, data, usage);
}

void System::GLNamedBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr size, const void* data) noexcept
{
    SYSTEM_BODY_4(glNamedBufferSubData, buffer, offset, size, data);
}

void System::GLCopyNamedBufferSubData(GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size) noexcept
{
    SYSTEM_BODY_5(glCopyNamedBufferSubData, readBuffer, writeBuffer, readOffset, writeOffset, size);
}

void System::GLClearNamedBufferData(GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void* data) noexcept
{
    SYSTEM_BODY_5(glClearNamedBufferData, buffer, internalformat, format, type, data);
}

void System::GLClearNamedBufferSubData(GLuint buffer, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void* data) noexcept
{
    SYSTEM_BODY_7(glClearNamedBufferSubData, buffer, internalformat, offset, size, format, type, data);
}

void* System::GLMapNamedBuffer(GLuint buffer, GLenum access) noexcept
{
    SYSTEM_BODY_2_RESULT(glMapNamedBuffer, buffer, access, nullptr);
}

void* System::GLMapNamedBufferRange(GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access) noexcept
{
    SYSTEM_BODY_4_RESULT(glMapNamedBufferRange, buffer, offset, length, access, nullptr);
}

GLboolean System::GLUnmapNamedBuffer(GLuint buffer) noexcept
{
    SYSTEM_BODY_1_RESULT(glUnmapNamedBuffer, buffer, GL_FALSE);
}

void System::GLFlushMappedNamedBufferRange(GLuint buffer, GLintptr offset, GLsizeiptr length) noexcept
{
    SYSTEM_BODY_3(glFlushMappedNamedBufferRange, buffer, offset, length);
}

void System::GLGetNamedBufferParameteriv(GLuint buffer, GLenum pname, GLint* params) noexcept
{
    SYSTEM_BODY_3(glGetNamedBufferParameteriv, buffer, pname, params);
}

void System::GLGetNamedBufferParameteri64v(GLuint buffer, GLenum pname, GLint64* params) noexcept
{
    SYSTEM_BODY_3(glGetNamedBufferParameteri64v, buffer, pname, params);
}

void System::GLGetNamedBufferPointerv(GLuint buffer, GLenum pname, void** params) noexcept
{
    SYSTEM_BODY_3(glGetNamedBufferPointerv, buffer, pname, params);
}

void System::GLGetNamedBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr size, void* data) noexcept
{
    SYSTEM_BODY_4(glGetNamedBufferSubData, buffer, offset, size, data);
}

void System::GLCreateFramebuffers(GLsizei n, GLuint* framebuffers) noexcept
{
    SYSTEM_BODY_2(glCreateFramebuffers, n, framebuffers);
}

void System::GLNamedFramebufferRenderbuffer(GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) noexcept
{
    SYSTEM_BODY_4(glNamedFramebufferRenderbuffer, framebuffer, attachment, renderbuffertarget, renderbuffer);
}

void System::GLNamedFramebufferParameteri(GLuint framebuffer, GLenum pname, GLint param) noexcept
{
    SYSTEM_BODY_3(glNamedFramebufferParameteri, framebuffer, pname, param);
}

void System::GLNamedFramebufferTexture(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level) noexcept
{
    SYSTEM_BODY_4(glNamedFramebufferTexture, framebuffer, attachment, texture, level);
}

void System::GLNamedFramebufferTextureLayer(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer) noexcept
{
    SYSTEM_BODY_5(glNamedFramebufferTextureLayer, framebuffer, attachment, texture, level, layer);
}

void System::GLNamedFramebufferDrawBuffer(GLuint framebuffer, GLenum buf) noexcept
{
    SYSTEM_BODY_2(glNamedFramebufferDrawBuffer, framebuffer, buf);
}

void System::GLNamedFramebufferDrawBuffers(GLuint framebuffer, GLsizei n, const GLenum* bufs) noexcept
{
    SYSTEM_BODY_3(glNamedFramebufferDrawBuffers, framebuffer, n, bufs);
}

void System::GLNamedFramebufferReadBuffer(GLuint framebuffer, GLenum src) noexcept
{
    SYSTEM_BODY_2(glNamedFramebufferReadBuffer, framebuffer, src);
}

void System::GLInvalidateNamedFramebufferData(GLuint framebuffer, GLsizei numAttachments, const GLenum* attachments) noexcept
{
    SYSTEM_BODY_3(glInvalidateNamedFramebufferData, framebuffer, numAttachments, attachments);
}

void System::GLInvalidateNamedFramebufferSubData(GLuint framebuffer, GLsizei numAttachments, const GLenum* attachments, GLint x, GLint y, GLsizei width, GLsizei height) noexcept
{
    SYSTEM_BODY_7(glInvalidateNamedFramebufferSubData, framebuffer, numAttachments, attachments, x, y, width, height);
}

void System::GLClearNamedFramebufferiv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLint* value) noexcept
{
    SYSTEM_BODY_4(glClearNamedFramebufferiv, framebuffer, buffer, drawbuffer, value);
}

void System::GLClearNamedFramebufferuiv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLuint* value) noexcept
{
    SYSTEM_BODY_4(glClearNamedFramebufferuiv, framebuffer, buffer, drawbuffer, value);
}

void System::GLClearNamedFramebufferfv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLfloat* value) noexcept
{
    SYSTEM_BODY_4(glClearNamedFramebufferfv, framebuffer, buffer, drawbuffer, value);
}

void System::GLClearNamedFramebufferfi(GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil) noexcept
{
    SYSTEM_BODY_5(glClearNamedFramebufferfi, framebuffer, buffer, drawbuffer, depth, stencil);
}

void System::GLBlitNamedFramebuffer(GLuint readFramebuffer, GLuint drawFramebuffer, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter) noexcept
{
    SYSTEM_BODY_12(glBlitNamedFramebuffer, readFramebuffer, drawFramebuffer, srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);
}

GLenum System::GLCheckNamedFramebufferStatus(GLuint framebuffer, GLenum target) noexcept
{
    SYSTEM_BODY_2_RESULT(glCheckNamedFramebufferStatus, framebuffer, target, 0);
}

void System::GLGetNamedFramebufferParameteriv(GLuint framebuffer, GLenum pname, GLint* param) noexcept
{
    SYSTEM_BODY_3(glGetNamedFramebufferParameteriv, framebuffer, pname, param);
}

void System::GLGetNamedFramebufferAttachmentParameteriv(GLuint framebuffer, GLenum attachment, GLenum pname, GLint* params) noexcept
{
    SYSTEM_BODY_4(glGetNamedFramebufferAttachmentParameteriv, framebuffer, attachment, pname, params);
}

void System::GLCreateRenderbuffers(GLsizei n, GLuint* renderbuffers) noexcept
{
    SYSTEM_BODY_2(glCreateRenderbuffers, n, renderbuffers);
}

void System::GLNamedRenderbufferStorage(GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height) noexcept
{
    SYSTEM_BODY_4(glNamedRenderbufferStorage, renderbuffer, internalformat, width, height);
}

void System::GLNamedRenderbufferStorageMultisample(GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height) noexcept
{
    SYSTEM_BODY_5(glNamedRenderbufferStorageMultisample, renderbuffer, samples, internalformat, width, height);
}

void System::GLGetNamedRenderbufferParameteriv(GLuint renderbuffer, GLenum pname, GLint* params) noexcept
{
    SYSTEM_BODY_3(glGetNamedRenderbufferParameteriv, renderbuffer, pname, params);
}

void System::GLCreateTextures(GLenum target, GLsizei n, GLuint* textures) noexcept
{
    SYSTEM_BODY_3(glCreateTextures, target, n, textures);
}

void System::GLTextureBuffer(GLuint texture, GLenum internalformat, GLuint buffer) noexcept
{
    SYSTEM_BODY_3(glTextureBuffer, texture, internalformat, buffer);
}

void System::GLTextureBufferRange(GLuint texture, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size) noexcept
{
    SYSTEM_BODY_5(glTextureBufferRange, texture, internalformat, buffer, offset, size);
}

void System::GLTextureStorage1D(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width) noexcept
{
    SYSTEM_BODY_4(glTextureStorage1D, texture, levels, internalformat, width);
}

void System::GLTextureStorage2D(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height) noexcept
{
    SYSTEM_BODY_5(glTextureStorage2D, texture, levels, internalformat, width, height);
}

void System::GLTextureStorage3D(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth) noexcept
{
    SYSTEM_BODY_6(glTextureStorage3D, texture, levels, internalformat, width, height, depth);
}

void System::GLTextureStorage2DMultisample(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations) noexcept
{
    SYSTEM_BODY_6(glTextureStorage2DMultisample, texture, samples, internalformat, width, height, fixedsamplelocations);
}

void System::GLTextureStorage3DMultisample(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations) noexcept
{
    SYSTEM_BODY_7(glTextureStorage3DMultisample, texture, samples, internalformat, width, height, depth, fixedsamplelocations);
}

void System::GLTextureSubImage1D(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void* pixels) noexcept
{
    SYSTEM_BODY_7(glTextureSubImage1D, texture, level, xoffset, width, format, type, pixels);
}

void System::GLTextureSubImage2D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void* pixels) noexcept
{
    SYSTEM_BODY_9(glTextureSubImage2D, texture, level, xoffset, yoffset, width, height, format, type, pixels);
}

void System::GLTextureSubImage3D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void* pixels) noexcept
{
    SYSTEM_BODY_11(glTextureSubImage3D, texture, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);
}

void System::GLCompressedTextureSubImage1D(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void* data) noexcept
{
    SYSTEM_BODY_7(glCompressedTextureSubImage1D, texture, level, xoffset, width, format, imageSize, data);
}

void System::GLCompressedTextureSubImage2D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void* data) noexcept
{
    SYSTEM_BODY_9(glCompressedTextureSubImage2D, texture, level, xoffset, yoffset, width, height, format, imageSize, data);
}

void System::GLCompressedTextureSubImage3D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void* data) noexcept
{
    SYSTEM_BODY_11(glCompressedTextureSubImage3D, texture, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data);
}

void System::GLCopyTextureSubImage1D(GLuint texture, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width) noexcept
{
    SYSTEM_BODY_6(glCopyTextureSubImage1D, texture, level, xoffset, x, y, width);
}

void System::GLCopyTextureSubImage2D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) noexcept
{
    SYSTEM_BODY_8(glCopyTextureSubImage2D, texture, level, xoffset, yoffset, x, y, width, height);
}

void System::GLCopyTextureSubImage3D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) noexcept
{
    SYSTEM_BODY_9(glCopyTextureSubImage3D, texture, level, xoffset, yoffset, zoffset, x, y, width, height);
}

void System::GLTextureParameterf(GLuint texture, GLenum pname, GLfloat param) noexcept
{
    SYSTEM_BODY_3(glTextureParameterf, texture, pname, param);
}

void System::GLTextureParameterfv(GLuint texture, GLenum pname, const GLfloat* param) noexcept
{
    SYSTEM_BODY_3(glTextureParameterfv, texture, pname, param);
}

void System::GLTextureParameteri(GLuint texture, GLenum pname, GLint param) noexcept
{
    SYSTEM_BODY_3(glTextureParameteri, texture, pname, param);
}

void System::GLTextureParameterIiv(GLuint texture, GLenum pname, const GLint* params) noexcept
{
    SYSTEM_BODY_3(glTextureParameterIiv, texture, pname, params);
}

void System::GLTextureParameterIuiv(GLuint texture, GLenum pname, const GLuint* params) noexcept
{
    SYSTEM_BODY_3(glTextureParameterIuiv, texture, pname, params);
}

void System::GLTextureParameteriv(GLuint texture, GLenum pname, const GLint* param) noexcept
{
    SYSTEM_BODY_3(glTextureParameteriv, texture, pname, param);
}

void System::GLGenerateTextureMipmap(GLuint texture) noexcept
{
    SYSTEM_BODY_1(glGenerateTextureMipmap, texture);
}

void System::GLBindTextureUnit(GLuint unit, GLuint texture) noexcept
{
    SYSTEM_BODY_2(glBindTextureUnit, unit, texture);
}

void System::GLGetTextureImage(GLuint texture, GLint level, GLenum format, GLenum type, GLsizei bufSize, void* pixels) noexcept
{
    SYSTEM_BODY_6(glGetTextureImage, texture, level, format, type, bufSize, pixels);
}

void System::GLGetCompressedTextureImage(GLuint texture, GLint level, GLsizei bufSize, void* pixels) noexcept
{
    SYSTEM_BODY_4(glGetCompressedTextureImage, texture, level, bufSize, pixels);
}

void System::GLGetTextureLevelParameterfv(GLuint texture, GLint level, GLenum pname, GLfloat* params) noexcept
{
    SYSTEM_BODY_4(glGetTextureLevelParameterfv, texture, level, pname, params);
}

void System::GLGetTextureLevelParameteriv(GLuint texture, GLint level, GLenum pname, GLint* params) noexcept
{
    SYSTEM_BODY_4(glGetTextureLevelParameteriv, texture, level, pname, params);
}

void System::GLGetTextureParameterfv(GLuint texture, GLenum pname, GLfloat* params) noexcept
{
    SYSTEM_BODY_3(glGetTextureParameterfv, texture, pname, params);
}

void System::GLGetTextureParameterIiv(GLuint texture, GLenum pname, GLint* params) noexcept
{
    SYSTEM_BODY_3(glGetTextureParameterIiv, texture, pname, params);
}

void System::GLGetTextureParameterIuiv(GLuint texture, GLenum pname, GLuint* params) noexcept
{
    SYSTEM_BODY_3(glGetTextureParameterIuiv, texture, pname, params);
}

void System::GLGetTextureParameteriv(GLuint texture, GLenum pname, GLint* params) noexcept
{
    SYSTEM_BODY_3(glGetTextureParameteriv, texture, pname, params);
}

void System::GLCreateVertexArrays(GLsizei n, GLuint* arrays) noexcept
{
    SYSTEM_BODY_2(glCreateVertexArrays, n, arrays);
}

void System::GLDisableVertexArrayAttrib(GLuint vaobj, GLuint index) noexcept
{
    SYSTEM_BODY_2(glDisableVertexArrayAttrib, vaobj, index);
}

void System::GLEnableVertexArrayAttrib(GLuint vaobj, GLuint index) noexcept
{
    SYSTEM_BODY_2(glEnableVertexArrayAttrib, vaobj, index);
}

void System::GLVertexArrayElementBuffer(GLuint vaobj, GLuint buffer) noexcept
{
    SYSTEM_BODY_2(glVertexArrayElementBuffer, vaobj, buffer);
}

void System::GLVertexArrayVertexBuffer(GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride) noexcept
{
    SYSTEM_BODY_5(glVertexArrayVertexBuffer, vaobj, bindingindex, buffer, offset, stride);
}

void System::GLVertexArrayVertexBuffers(GLuint vaobj, GLuint first, GLsizei count, const GLuint* buffers, const GLintptr* offsets, const GLsizei* strides) noexcept
{
    SYSTEM_BODY_6(glVertexArrayVertexBuffers, vaobj, first, count, buffers, offsets, strides);
}

void System::GLVertexArrayAttribBinding(GLuint vaobj, GLuint attribindex, GLuint bindingindex) noexcept
{
    SYSTEM_BODY_3(glVertexArrayAttribBinding, vaobj, attribindex, bindingindex);
}

void System::GLVertexArrayAttribFormat(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset) noexcept
{
    SYSTEM_BODY_6(glVertexArrayAttribFormat, vaobj, attribindex, size, type, normalized, relativeoffset);
}

void System::GLVertexArrayAttribIFormat(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset) noexcept
{
    SYSTEM_BODY_5(glVertexArrayAttribIFormat, vaobj, attribindex, size, type, relativeoffset);
}

void System::GLVertexArrayAttribLFormat(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset) noexcept
{
    SYSTEM_BODY_5(glVertexArrayAttribLFormat, vaobj, attribindex, size, type, relativeoffset);
}

void System::GLVertexArrayBindingDivisor(GLuint vaobj, GLuint bindingindex, GLuint divisor) noexcept
{
    SYSTEM_BODY_3(glVertexArrayBindingDivisor, vaobj, bindingindex, divisor);
}

void System::GLGetVertexArrayiv(GLuint vaobj, GLenum pname, GLint* param) noexcept
{
    SYSTEM_BODY_3(glGetVertexArrayiv, vaobj, pname, param);
}

void System::GLGetVertexArrayIndexediv(GLuint vaobj, GLuint index, GLenum pname, GLint* param) noexcept
{
    SYSTEM_BODY_4(glGetVertexArrayIndexediv, vaobj, index, pname, param);
}

void System::GLGetVertexArrayIndexed64iv(GLuint vaobj, GLuint index, GLenum pname, GLint64* param) noexcept
{
    SYSTEM_BODY_4(glGetVertexArrayIndexed64iv, vaobj, index, pname, param);
}

void System::GLCreateSamplers(GLsizei n, GLuint* samplers) noexcept
{
    SYSTEM_BODY_2(glCreateSamplers, n, samplers);
}

void System::GLCreateProgramPipelines(GLsizei n, GLuint* pipelines) noexcept
{
    SYSTEM_BODY_2(glCreateProgramPipelines, n, pipelines);
}

void System::GLCreateQueries(GLenum target, GLsizei n, GLuint* ids) noexcept
{
    SYSTEM_BODY_3(glCreateQueries, target, n, ids);
}

void System::GLGetQueryBufferObjecti64v(GLuint id, GLuint buffer, GLenum pname, GLintptr offset) noexcept
{
    SYSTEM_BODY_4(glGetQueryBufferObjecti64v, id, buffer, pname, offset);
}

void System::GLGetQueryBufferObjectiv(GLuint id, GLuint buffer, GLenum pname, GLintptr offset) noexcept
{
    SYSTEM_BODY_4(glGetQueryBufferObjectiv, id, buffer, pname, offset);
}

void System::GLGetQueryBufferObjectui64v(GLuint id, GLuint buffer, GLenum pname, GLintptr offset) noexcept
{
    SYSTEM_BODY_4(glGetQueryBufferObjectui64v, id, buffer, pname, offset);
}

void System::GLGetQueryBufferObjectuiv(GLuint id, GLuint buffer, GLenum pname, GLintptr offset) noexcept
{
    SYSTEM_BODY_4(glGetQueryBufferObjectuiv, id, buffer, pname, offset);
}

void System::GLMemoryBarrierByRegion(GLbitfield barriers) noexcept
{
    SYSTEM_BODY_1(glMemoryBarrierByRegion, barriers);
}

void System::GLGetTextureSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLsizei bufSize, void* pixels) noexcept
{
    SYSTEM_BODY_12(glGetTextureSubImage, texture, level, xoffset, yoffset, zoffset, width, height, depth, format, type, bufSize, pixels);
}

void System::GLGetCompressedTextureSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei bufSize, void* pixels) noexcept
{
    SYSTEM_BODY_10(glGetCompressedTextureSubImage, texture, level, xoffset, yoffset, zoffset, width, height, depth, bufSize, pixels);
}

GLenum System::GLGetGraphicsResetStatus() noexcept
{
    SYSTEM_BODY_0_RESULT(glGetGraphicsResetStatus, GL_NO_ERROR);
}

void System::GLGetnCompressedTexImage(GLenum target, GLint lod, GLsizei bufSize, void* pixels) noexcept
{
    SYSTEM_BODY_4(glGetnCompressedTexImage, target, lod, bufSize, pixels);
}

void System::GLGetnTexImage(GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void* pixels) noexcept
{
    SYSTEM_BODY_6(glGetnTexImage, target, level, format, type, bufSize, pixels);
}

void System::GLGetnUniformdv(GLuint program, GLint location, GLsizei bufSize, GLdouble* params) noexcept
{
    SYSTEM_BODY_4(glGetnUniformdv, program, location, bufSize, params);
}

void System::GLGetnUniformfv(GLuint program, GLint location, GLsizei bufSize, GLfloat* params) noexcept
{
    SYSTEM_BODY_4(glGetnUniformfv, program, location, bufSize, params);
}

void System::GLGetnUniformiv(GLuint program, GLint location, GLsizei bufSize, GLint* params) noexcept
{
    SYSTEM_BODY_4(glGetnUniformiv, program, location, bufSize, params);
}

void System::GLGetnUniformuiv(GLuint program, GLint location, GLsizei bufSize, GLuint* params) noexcept
{
    SYSTEM_BODY_4(glGetnUniformuiv, program, location, bufSize, params);
}

void System::GLReadnPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void* data) noexcept
{
    SYSTEM_BODY_8(glReadnPixels, x, y, width, height, format, type, bufSize, data);
}

void System::GLTextureBarrier() noexcept
{
    SYSTEM_BODY_0(glTextureBarrier);
}
