/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/02 23:09)

#include "System/SystemExport.h"

#include "GL45Extensions.h"
#include "System/Helper/Detail/OpenGL/GLPluginMacro.h"
#include "System/Helper/EnumCast.h"
#include "System/OpenGL/Flags/GLExtensionsFlags.h"
#include "System/OpenGL/OpenGLUtility.h"

/// OpenGL 4.5
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
    if (OpenGLSystemVersion::Version45 <= GetOpenGLVersion())
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

void System::GLGetTransformFeedbackIv(GLuint xfb, GLenum pName, GLint* param) noexcept
{
    SYSTEM_BODY_3(glGetTransformFeedbackiv, xfb, pName, param);
}

void System::GLGetTransformFeedbackIv(GLuint xfb, GLenum pName, GLuint index, GLint* param) noexcept
{
    SYSTEM_BODY_4(glGetTransformFeedbacki_v, xfb, pName, index, param);
}

void System::GLGetTransformFeedbackI64V(GLuint xfb, GLenum pName, GLuint index, GLint64* param) noexcept
{
    SYSTEM_BODY_4(glGetTransformFeedbacki64_v, xfb, pName, index, param);
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

void System::GLClearNamedBufferData(GLuint buffer, GLenum internalFormat, GLenum format, GLenum type, const void* data) noexcept
{
    SYSTEM_BODY_5(glClearNamedBufferData, buffer, internalFormat, format, type, data);
}

void System::GLClearNamedBufferSubData(GLuint buffer, GLenum internalFormat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void* data) noexcept
{
    SYSTEM_BODY_7(glClearNamedBufferSubData, buffer, internalFormat, offset, size, format, type, data);
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

void System::GLGetNamedBufferParameterIv(GLuint buffer, GLenum pName, GLint* params) noexcept
{
    SYSTEM_BODY_3(glGetNamedBufferParameteriv, buffer, pName, params);
}

void System::GLGetNamedBufferParameterI64v(GLuint buffer, GLenum pName, GLint64* params) noexcept
{
    SYSTEM_BODY_3(glGetNamedBufferParameteri64v, buffer, pName, params);
}

void System::GLGetNamedBufferPointerV(GLuint buffer, GLenum pName, void** params) noexcept
{
    SYSTEM_BODY_3(glGetNamedBufferPointerv, buffer, pName, params);
}

void System::GLGetNamedBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr size, void* data) noexcept
{
    SYSTEM_BODY_4(glGetNamedBufferSubData, buffer, offset, size, data);
}

void System::GLCreateFrameBuffers(GLsizei n, GLuint* frameBuffers) noexcept
{
    SYSTEM_BODY_2(glCreateFramebuffers, n, frameBuffers);
}

void System::GLNamedFrameBufferRenderBuffer(GLuint frameBuffer, GLenum attachment, GLenum renderBufferTarget, GLuint renderBuffer) noexcept
{
    SYSTEM_BODY_4(glNamedFramebufferRenderbuffer, frameBuffer, attachment, renderBufferTarget, renderBuffer);
}

void System::GLNamedFrameBufferParameterI(GLuint frameBuffer, GLenum pName, GLint param) noexcept
{
    SYSTEM_BODY_3(glNamedFramebufferParameteri, frameBuffer, pName, param);
}

void System::GLNamedFrameBufferTexture(GLuint frameBuffer, GLenum attachment, GLuint texture, GLint level) noexcept
{
    SYSTEM_BODY_4(glNamedFramebufferTexture, frameBuffer, attachment, texture, level);
}

void System::GLNamedFrameBufferTextureLayer(GLuint frameBuffer, GLenum attachment, GLuint texture, GLint level, GLint layer) noexcept
{
    SYSTEM_BODY_5(glNamedFramebufferTextureLayer, frameBuffer, attachment, texture, level, layer);
}

void System::GLNamedFrameBufferDrawBuffer(GLuint frameBuffer, GLenum buf) noexcept
{
    SYSTEM_BODY_2(glNamedFramebufferDrawBuffer, frameBuffer, buf);
}

void System::GLNamedFrameBufferDrawBuffers(GLuint frameBuffer, GLsizei n, const GLenum* buffers) noexcept
{
    SYSTEM_BODY_3(glNamedFramebufferDrawBuffers, frameBuffer, n, buffers);
}

void System::GLNamedFrameBufferReadBuffer(GLuint frameBuffer, GLenum src) noexcept
{
    SYSTEM_BODY_2(glNamedFramebufferReadBuffer, frameBuffer, src);
}

void System::GLInvalidateNamedFrameBufferData(GLuint frameBuffer, GLsizei numAttachments, const GLenum* attachments) noexcept
{
    SYSTEM_BODY_3(glInvalidateNamedFramebufferData, frameBuffer, numAttachments, attachments);
}

void System::GLInvalidateNamedFrameBufferSubData(GLuint frameBuffer, GLsizei numAttachments, const GLenum* attachments, GLint x, GLint y, GLsizei width, GLsizei height) noexcept
{
    SYSTEM_BODY_7(glInvalidateNamedFramebufferSubData, frameBuffer, numAttachments, attachments, x, y, width, height);
}

void System::GLClearNamedFrameBufferIv(GLuint frameBuffer, GLenum buffer, GLint drawBuffer, const GLint* value) noexcept
{
    SYSTEM_BODY_4(glClearNamedFramebufferiv, frameBuffer, buffer, drawBuffer, value);
}

void System::GLClearNamedFrameBufferUiv(GLuint frameBuffer, GLenum buffer, GLint drawBuffer, const GLuint* value) noexcept
{
    SYSTEM_BODY_4(glClearNamedFramebufferuiv, frameBuffer, buffer, drawBuffer, value);
}

void System::GLClearNamedFrameBufferFv(GLuint frameBuffer, GLenum buffer, GLint drawBuffer, const GLfloat* value) noexcept
{
    SYSTEM_BODY_4(glClearNamedFramebufferfv, frameBuffer, buffer, drawBuffer, value);
}

void System::GLClearNamedFrameBufferFi(GLuint frameBuffer, GLenum buffer, GLint drawBuffer, GLfloat depth, GLint stencil) noexcept
{
    SYSTEM_BODY_5(glClearNamedFramebufferfi, frameBuffer, buffer, drawBuffer, depth, stencil);
}

void System::GLBlitNamedFrameBuffer(GLuint readFrameBuffer, GLuint drawFrameBuffer, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter) noexcept
{
    SYSTEM_BODY_12(glBlitNamedFramebuffer, readFrameBuffer, drawFrameBuffer, srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);
}

GLenum System::GLCheckNamedFrameBufferStatus(GLuint frameBuffer, GLenum target) noexcept
{
    SYSTEM_BODY_2_RESULT(glCheckNamedFramebufferStatus, frameBuffer, target, 0);
}

void System::GLGetNamedFrameBufferParameterIv(GLuint frameBuffer, GLenum pName, GLint* param) noexcept
{
    SYSTEM_BODY_3(glGetNamedFramebufferParameteriv, frameBuffer, pName, param);
}

void System::GLGetNamedFrameBufferAttachmentParameterIv(GLuint frameBuffer, GLenum attachment, GLenum pName, GLint* params) noexcept
{
    SYSTEM_BODY_4(glGetNamedFramebufferAttachmentParameteriv, frameBuffer, attachment, pName, params);
}

void System::GLCreateRenderBuffers(GLsizei n, GLuint* renderBuffers) noexcept
{
    SYSTEM_BODY_2(glCreateRenderbuffers, n, renderBuffers);
}

void System::GLNamedRenderBufferStorage(GLuint renderBuffer, GLenum internalFormat, GLsizei width, GLsizei height) noexcept
{
    SYSTEM_BODY_4(glNamedRenderbufferStorage, renderBuffer, internalFormat, width, height);
}

void System::GLNamedRenderBufferStorageMultiSample(GLuint renderBuffer, GLsizei samples, GLenum internalFormat, GLsizei width, GLsizei height) noexcept
{
    SYSTEM_BODY_5(glNamedRenderbufferStorageMultisample, renderBuffer, samples, internalFormat, width, height);
}

void System::GLGetNamedRenderBufferParameterIv(GLuint renderBuffer, GLenum pName, GLint* params) noexcept
{
    SYSTEM_BODY_3(glGetNamedRenderbufferParameteriv, renderBuffer, pName, params);
}

void System::GLCreateTextures(GLenum target, GLsizei n, GLuint* textures) noexcept
{
    SYSTEM_BODY_3(glCreateTextures, target, n, textures);
}

void System::GLTextureBuffer(GLuint texture, GLenum internalFormat, GLuint buffer) noexcept
{
    SYSTEM_BODY_3(glTextureBuffer, texture, internalFormat, buffer);
}

void System::GLTextureBufferRange(GLuint texture, GLenum internalFormat, GLuint buffer, GLintptr offset, GLsizeiptr size) noexcept
{
    SYSTEM_BODY_5(glTextureBufferRange, texture, internalFormat, buffer, offset, size);
}

void System::GLTextureStorage1D(GLuint texture, GLsizei levels, GLenum internalFormat, GLsizei width) noexcept
{
    SYSTEM_BODY_4(glTextureStorage1D, texture, levels, internalFormat, width);
}

void System::GLTextureStorage2D(GLuint texture, GLsizei levels, GLenum internalFormat, GLsizei width, GLsizei height) noexcept
{
    SYSTEM_BODY_5(glTextureStorage2D, texture, levels, internalFormat, width, height);
}

void System::GLTextureStorage3D(GLuint texture, GLsizei levels, GLenum internalFormat, GLsizei width, GLsizei height, GLsizei depth) noexcept
{
    SYSTEM_BODY_6(glTextureStorage3D, texture, levels, internalFormat, width, height, depth);
}

void System::GLTextureStorage2DMultiSample(GLuint texture, GLsizei samples, GLenum internalFormat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations) noexcept
{
    SYSTEM_BODY_6(glTextureStorage2DMultisample, texture, samples, internalFormat, width, height, fixedSampleLocations);
}

void System::GLTextureStorage3DMultiSample(GLuint texture, GLsizei samples, GLenum internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations) noexcept
{
    SYSTEM_BODY_7(glTextureStorage3DMultisample, texture, samples, internalFormat, width, height, depth, fixedSampleLocations);
}

void System::GLTextureSubImage1D(GLuint texture, GLint level, GLint xOffset, GLsizei width, GLenum format, GLenum type, const void* pixels) noexcept
{
    SYSTEM_BODY_7(glTextureSubImage1D, texture, level, xOffset, width, format, type, pixels);
}

void System::GLTextureSubImage2D(GLuint texture, GLint level, GLint xOffset, GLint yOffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void* pixels) noexcept
{
    SYSTEM_BODY_9(glTextureSubImage2D, texture, level, xOffset, yOffset, width, height, format, type, pixels);
}

void System::GLTextureSubImage3D(GLuint texture, GLint level, GLint xOffset, GLint yOffset, GLint zOffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void* pixels) noexcept
{
    SYSTEM_BODY_11(glTextureSubImage3D, texture, level, xOffset, yOffset, zOffset, width, height, depth, format, type, pixels);
}

void System::GLCompressedTextureSubImage1D(GLuint texture, GLint level, GLint xOffset, GLsizei width, GLenum format, GLsizei imageSize, const void* data) noexcept
{
    SYSTEM_BODY_7(glCompressedTextureSubImage1D, texture, level, xOffset, width, format, imageSize, data);
}

void System::GLCompressedTextureSubImage2D(GLuint texture, GLint level, GLint xOffset, GLint yOffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void* data) noexcept
{
    SYSTEM_BODY_9(glCompressedTextureSubImage2D, texture, level, xOffset, yOffset, width, height, format, imageSize, data);
}

void System::GLCompressedTextureSubImage3D(GLuint texture, GLint level, GLint xOffset, GLint yOffset, GLint zOffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void* data) noexcept
{
    SYSTEM_BODY_11(glCompressedTextureSubImage3D, texture, level, xOffset, yOffset, zOffset, width, height, depth, format, imageSize, data);
}

void System::GLCopyTextureSubImage1D(GLuint texture, GLint level, GLint xOffset, GLint x, GLint y, GLsizei width) noexcept
{
    SYSTEM_BODY_6(glCopyTextureSubImage1D, texture, level, xOffset, x, y, width);
}

void System::GLCopyTextureSubImage2D(GLuint texture, GLint level, GLint xOffset, GLint yOffset, GLint x, GLint y, GLsizei width, GLsizei height) noexcept
{
    SYSTEM_BODY_8(glCopyTextureSubImage2D, texture, level, xOffset, yOffset, x, y, width, height);
}

void System::GLCopyTextureSubImage3D(GLuint texture, GLint level, GLint xOffset, GLint yOffset, GLint zOffset, GLint x, GLint y, GLsizei width, GLsizei height) noexcept
{
    SYSTEM_BODY_9(glCopyTextureSubImage3D, texture, level, xOffset, yOffset, zOffset, x, y, width, height);
}

void System::GLTextureParameterF(GLuint texture, GLenum pName, GLfloat param) noexcept
{
    SYSTEM_BODY_3(glTextureParameterf, texture, pName, param);
}

void System::GLTextureParameterFv(GLuint texture, GLenum pName, const GLfloat* param) noexcept
{
    SYSTEM_BODY_3(glTextureParameterfv, texture, pName, param);
}

void System::GLTextureParameterI(GLuint texture, GLenum pName, GLint param) noexcept
{
    SYSTEM_BODY_3(glTextureParameteri, texture, pName, param);
}

void System::GLTextureParameterIiv(GLuint texture, GLenum pName, const GLint* params) noexcept
{
    SYSTEM_BODY_3(glTextureParameterIiv, texture, pName, params);
}

void System::GLTextureParameterIUiv(GLuint texture, GLenum pName, const GLuint* params) noexcept
{
    SYSTEM_BODY_3(glTextureParameterIuiv, texture, pName, params);
}

void System::GLTextureParameterIv(GLuint texture, GLenum pName, const GLint* param) noexcept
{
    SYSTEM_BODY_3(glTextureParameteriv, texture, pName, param);
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

void System::GLGetTextureLevelParameterFv(GLuint texture, GLint level, GLenum pName, GLfloat* params) noexcept
{
    SYSTEM_BODY_4(glGetTextureLevelParameterfv, texture, level, pName, params);
}

void System::GLGetTextureLevelParameterIv(GLuint texture, GLint level, GLenum pName, GLint* params) noexcept
{
    SYSTEM_BODY_4(glGetTextureLevelParameteriv, texture, level, pName, params);
}

void System::GLGetTextureParameterFv(GLuint texture, GLenum pName, GLfloat* params) noexcept
{
    SYSTEM_BODY_3(glGetTextureParameterfv, texture, pName, params);
}

void System::GLGetTextureParameterIiv(GLuint texture, GLenum pName, GLint* params) noexcept
{
    SYSTEM_BODY_3(glGetTextureParameterIiv, texture, pName, params);
}

void System::GLGetTextureParameterIUiv(GLuint texture, GLenum pName, GLuint* params) noexcept
{
    SYSTEM_BODY_3(glGetTextureParameterIuiv, texture, pName, params);
}

void System::GLGetTextureParameterIv(GLuint texture, GLenum pName, GLint* params) noexcept
{
    SYSTEM_BODY_3(glGetTextureParameteriv, texture, pName, params);
}

void System::GLCreateVertexArrays(GLsizei n, GLuint* arrays) noexcept
{
    SYSTEM_BODY_2(glCreateVertexArrays, n, arrays);
}

void System::GLDisableVertexArrayAttrib(GLuint vaObj, GLuint index) noexcept
{
    SYSTEM_BODY_2(glDisableVertexArrayAttrib, vaObj, index);
}

void System::GLEnableVertexArrayAttrib(GLuint vaObj, GLuint index) noexcept
{
    SYSTEM_BODY_2(glEnableVertexArrayAttrib, vaObj, index);
}

void System::GLVertexArrayElementBuffer(GLuint vaObj, GLuint buffer) noexcept
{
    SYSTEM_BODY_2(glVertexArrayElementBuffer, vaObj, buffer);
}

void System::GLVertexArrayVertexBuffer(GLuint vaObj, GLuint bindingIndex, GLuint buffer, GLintptr offset, GLsizei stride) noexcept
{
    SYSTEM_BODY_5(glVertexArrayVertexBuffer, vaObj, bindingIndex, buffer, offset, stride);
}

void System::GLVertexArrayVertexBuffers(GLuint vaObj, GLuint first, GLsizei count, const GLuint* buffers, const GLintptr* offsets, const GLsizei* strides) noexcept
{
    SYSTEM_BODY_6(glVertexArrayVertexBuffers, vaObj, first, count, buffers, offsets, strides);
}

void System::GLVertexArrayAttribBinding(GLuint vaObj, GLuint attribIndex, GLuint bindingIndex) noexcept
{
    SYSTEM_BODY_3(glVertexArrayAttribBinding, vaObj, attribIndex, bindingIndex);
}

void System::GLVertexArrayAttribFormat(GLuint vaObj, GLuint attribIndex, GLint size, GLenum type, GLboolean normalized, GLuint relativeOffset) noexcept
{
    SYSTEM_BODY_6(glVertexArrayAttribFormat, vaObj, attribIndex, size, type, normalized, relativeOffset);
}

void System::GLVertexArrayAttribIFormat(GLuint vaObj, GLuint attribIndex, GLint size, GLenum type, GLuint relativeOffset) noexcept
{
    SYSTEM_BODY_5(glVertexArrayAttribIFormat, vaObj, attribIndex, size, type, relativeOffset);
}

void System::GLVertexArrayAttribLFormat(GLuint vaObj, GLuint attribIndex, GLint size, GLenum type, GLuint relativeOffset) noexcept
{
    SYSTEM_BODY_5(glVertexArrayAttribLFormat, vaObj, attribIndex, size, type, relativeOffset);
}

void System::GLVertexArrayBindingDivisor(GLuint vaObj, GLuint attribIndex, GLuint divisor) noexcept
{
    SYSTEM_BODY_3(glVertexArrayBindingDivisor, vaObj, attribIndex, divisor);
}

void System::GLGetVertexArrayIv(GLuint vaObj, GLenum pName, GLint* param) noexcept
{
    SYSTEM_BODY_3(glGetVertexArrayiv, vaObj, pName, param);
}

void System::GLGetVertexArrayIndexedIv(GLuint vaObj, GLuint index, GLenum pName, GLint* param) noexcept
{
    SYSTEM_BODY_4(glGetVertexArrayIndexediv, vaObj, index, pName, param);
}

void System::GLGetVertexArrayIndexed64Iv(GLuint vaObj, GLuint index, GLenum pName, GLint64* param) noexcept
{
    SYSTEM_BODY_4(glGetVertexArrayIndexed64iv, vaObj, index, pName, param);
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

void System::GLGetQueryBufferObjectI64V(GLuint id, GLuint buffer, GLenum pName, GLintptr offset) noexcept
{
    SYSTEM_BODY_4(glGetQueryBufferObjecti64v, id, buffer, pName, offset);
}

void System::GLGetQueryBufferObjectIv(GLuint id, GLuint buffer, GLenum pName, GLintptr offset) noexcept
{
    SYSTEM_BODY_4(glGetQueryBufferObjectiv, id, buffer, pName, offset);
}

void System::GLGetQueryBufferObjectUi64V(GLuint id, GLuint buffer, GLenum pName, GLintptr offset) noexcept
{
    SYSTEM_BODY_4(glGetQueryBufferObjectui64v, id, buffer, pName, offset);
}

void System::GLGetQueryBufferObjectUiv(GLuint id, GLuint buffer, GLenum pName, GLintptr offset) noexcept
{
    SYSTEM_BODY_4(glGetQueryBufferObjectuiv, id, buffer, pName, offset);
}

void System::GLMemoryBarrierByRegion(GLbitfield barriers) noexcept
{
    SYSTEM_BODY_1(glMemoryBarrierByRegion, barriers);
}

void System::GLGetTextureSubImage(GLuint texture, GLint level, GLint xOffset, GLint yOffset, GLint zOffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLsizei bufSize, void* pixels) noexcept
{
    SYSTEM_BODY_12(glGetTextureSubImage, texture, level, xOffset, yOffset, zOffset, width, height, depth, format, type, bufSize, pixels);
}

void System::GLGetCompressedTextureSubImage(GLuint texture, GLint level, GLint xOffset, GLint yOffset, GLint zOffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei bufSize, void* pixels) noexcept
{
    SYSTEM_BODY_10(glGetCompressedTextureSubImage, texture, level, xOffset, yOffset, zOffset, width, height, depth, bufSize, pixels);
}

GLenum System::GLGetGraphicsResetStatus() noexcept
{
    SYSTEM_BODY_0_RESULT(glGetGraphicsResetStatus, GL_NO_ERROR);
}

void System::GLGetNCompressedTexImage(GLenum target, GLint lod, GLsizei bufSize, void* pixels) noexcept
{
    SYSTEM_BODY_4(glGetnCompressedTexImage, target, lod, bufSize, pixels);
}

void System::GLGetNTexImage(GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void* pixels) noexcept
{
    SYSTEM_BODY_6(glGetnTexImage, target, level, format, type, bufSize, pixels);
}

void System::GLGetNUniformDv(GLuint program, GLint location, GLsizei bufSize, GLdouble* params) noexcept
{
    SYSTEM_BODY_4(glGetnUniformdv, program, location, bufSize, params);
}

void System::GLGetNUniformFv(GLuint program, GLint location, GLsizei bufSize, GLfloat* params) noexcept
{
    SYSTEM_BODY_4(glGetnUniformfv, program, location, bufSize, params);
}

void System::GLGetNUniformIv(GLuint program, GLint location, GLsizei bufSize, GLint* params) noexcept
{
    SYSTEM_BODY_4(glGetnUniformiv, program, location, bufSize, params);
}

void System::GLGetNUniformUiv(GLuint program, GLint location, GLsizei bufSize, GLuint* params) noexcept
{
    SYSTEM_BODY_4(glGetnUniformuiv, program, location, bufSize, params);
}

void System::GLReadNPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void* data) noexcept
{
    SYSTEM_BODY_8(glReadnPixels, x, y, width, height, format, type, bufSize, data);
}

void System::GLTextureBarrier() noexcept
{
    SYSTEM_BODY_0(glTextureBarrier);
}
