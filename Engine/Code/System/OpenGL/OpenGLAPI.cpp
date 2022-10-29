///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/13 14:08)

#include "System/SystemExport.h"

#include "OpenGLAPI.h"
#include "Flags/GLExtensionsFlags.h"
#include "Flags/OpenGLFlags.h"
#include "Detail/GL10Extensions.h"
#include "Detail/GL11Extensions.h"
#include "Detail/GL12Extensions.h"
#include "Detail/GL13Extensions.h"
#include "Detail/GL14Extensions.h"
#include "Detail/GL15Extensions.h"
#include "Detail/GL20Extensions.h"
#include "Detail/GL30Extensions.h"
#include "Detail/GL31Extensions.h"
#include "Detail/GL32Extensions.h"
#include "Detail/GL33Extensions.h"
#include "Detail/GL40Extensions.h"
#include "Detail/GL42Extensions.h"
#include "Detail/GL43Extensions.h"
#include "System/Helper/EnumCast.h"

void System::ClearAllGLBufferBit() noexcept
{
    GLClear(EnumCastUnderlying(OpenGLClearMask::ColorBufferBit | OpenGLClearMask::DepthBufferBit | OpenGLClearMask::StencilBufferBit));
}

void System::SetGLViewport(OpenGLInt x, OpenGLInt y, OpenGLSize width, OpenGLSize height) noexcept
{
    GLViewport(x, y, width, height);
}

void System::SetupRenderStatus() noexcept
{
    GLClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    GLClearStencil(0);
    GLClearDepth(1.0);

    GLEnable(GL_DEPTH_TEST);
    GLFrontFace(GL_CCW);
    GLEnable(GL_CULL_FACE);
}

void System::SetGLDepthRange(OpenGLDouble nearDepthRange, OpenGLDouble farDepthRange) noexcept
{
    GLDepthRange(nearDepthRange, farDepthRange);
}

void System::SetGLClearColor(OpenGLFloat red, OpenGLFloat green, OpenGLFloat blue, OpenGLFloat alpha) noexcept
{
    GLClearColor(red, green, blue, alpha);
}

System::OpenGLInt System::GetGLInteger(OpenGLQuery name) noexcept
{
    OpenGLInt params{};
    GLGetIntegerv(EnumCastUnderlying(name), &params);

    return params;
}

System::OpenGLInt System::GetGLInteger(TextureTargetBinding name) noexcept
{
    OpenGLInt params{};
    GLGetIntegerv(EnumCastUnderlying(name), &params);

    return params;
}

void System::GetGLInteger(OpenGLQuery name, OpenGLInt* data) noexcept
{
    GLGetIntegerv(EnumCastUnderlying(name), data);
}

bool System::GetGLBoolean(OpenGLQuery name) noexcept
{
    OpenGLBoolean params{};
    GLGetBooleanv(EnumCastUnderlying(name), &params);

    return params != GL_FALSE;
}

System::OpenGLFloat System::GetGLFloat(OpenGLQuery name) noexcept
{
    OpenGLFloat params{};
    GLGetFloatv(EnumCastUnderlying(name), &params);

    return params;
}

System::OpenGLDouble System::GetGLDouble(OpenGLQuery name) noexcept
{
    OpenGLDouble params{};
    GLGetDoublev(EnumCastUnderlying(name), &params);

    return params;
}

void System::GetGLDouble(OpenGLQuery name, OpenGLDouble* data) noexcept
{
    GLGetDoublev(EnumCastUnderlying(name), data);
}

void System::EnableGLState(OpenGLEnable cap) noexcept
{
    GLEnable(EnumCastUnderlying(cap));
}

void System::EnableGLState(OpenGLEnable target, OpenGLUInt index) noexcept
{
    GLEnablei(EnumCastUnderlying(target), index);
}

void System::DisableGLState(OpenGLEnable cap) noexcept
{
    GLDisable(EnumCastUnderlying(cap));
}

void System::DisableGLState(OpenGLEnable target, OpenGLUInt index) noexcept
{
    GLDisablei(EnumCastUnderlying(target), index);
}

void System::SetGLBlendColor(OpenGLFloat red, OpenGLFloat green, OpenGLFloat blue, OpenGLFloat alpha) noexcept
{
    GLBlendColor(red, green, blue, alpha);
}

void System::SetGLColorMask(OpenGLBoolean red, OpenGLBoolean green, OpenGLBoolean blue, OpenGLBoolean alpha) noexcept
{
    GLColorMask(red, green, blue, alpha);
}

void System::SetGLSampleMask(OpenGLUInt maskNumber, OpenGLBitfield mask) noexcept
{
    GLSampleMaski(maskNumber, mask);
}

void System::SetGLBlendFuncSeparate(OpenGLEnum sourceFactorRGB, OpenGLEnum destinationFactorRGB, OpenGLEnum sourceFactorAlpha, OpenGLEnum destinationFfactorAlpha) noexcept
{
    GLBlendFuncSeparate(sourceFactorRGB, destinationFactorRGB, sourceFactorAlpha, destinationFfactorAlpha);
}

void System::SetGLBlendEquationSeparate(GLenum modeRGB, GLenum modeAlpha) noexcept
{
    GLBlendEquationSeparate(modeRGB, modeAlpha);
}

void System::SetGLBlendEquationSeparate(OpenGLUInt index, GLenum modeRGB, GLenum modeAlpha) noexcept
{
    GLBlendEquationSeparatei(index, modeRGB, modeAlpha);
}

void System::SetGLBlendFuncSeparate(OpenGLUInt index, OpenGLEnum sourceFactorRGB, OpenGLEnum destinationFactorRGB, OpenGLEnum sourceFactorAlpha, OpenGLEnum destinationFfactorAlpha) noexcept
{
    GLBlendFuncSeparatei(index, sourceFactorRGB, destinationFactorRGB, sourceFactorAlpha, destinationFfactorAlpha);
}

void System::SetGLColorMask(OpenGLUInt index, OpenGLBoolean red, OpenGLBoolean green, OpenGLBoolean blue, OpenGLBoolean alpha) noexcept
{
    GLColorMaski(index, red, green, blue, alpha);
}

void System::SetGLDepthFunc(DepthStencilStateMode depthStencilStateMode) noexcept
{
    GLDepthFunc(EnumCastUnderlying(depthStencilStateMode));
}

void System::SetGLDepthMask(DepthStencilStateWriteMask flag) noexcept
{
    GLDepthMask(EnumCastUnderlying<OpenGLBoolean>(flag));
}

void System::SetGLStencilFuncSeparate(RasterizerStateCullFace face, DepthStencilStateMode func, OpenGLInt ref, OpenGLUInt mask) noexcept
{
    GLStencilFuncSeparate(EnumCastUnderlying(face), EnumCastUnderlying(func), ref, mask);
}

void System::SetGLStencilMaskSeparate(RasterizerStateCullFace face, OpenGLUInt mask) noexcept
{
    GLStencilMaskSeparate(EnumCastUnderlying(face), mask);
}

void System::SetGLStencilOpSeparate(RasterizerStateCullFace face, DepthStencilStateOperation sfail, DepthStencilStateOperation dpfail, DepthStencilStateOperation dppass) noexcept
{
    GLStencilOpSeparate(EnumCastUnderlying(face), EnumCastUnderlying(sfail), EnumCastUnderlying(dpfail), EnumCastUnderlying(dppass));
}

void System::SetGLPolygonMode(RasterizerStateCullFace face, RasterizerStateFillMode mode) noexcept
{
    GLPolygonMode(EnumCastUnderlying(face), EnumCastUnderlying(mode));
}

void System::SetGLPolygonOffset(OpenGLFloat factor, OpenGLFloat units) noexcept
{
    GLPolygonOffset(factor, units);
}

void System::SetGLFrontFace(OpenGLFrontFace mode) noexcept
{
    GLFrontFace(EnumCastUnderlying(mode));
}

void System::SetGLCullFace(RasterizerStateCullFace mode) noexcept
{
    GLCullFace(EnumCastUnderlying(mode));
}

void System::GetGLGenSamplers(OpenGLSize count, OpenGLUInt* samplers) noexcept
{
    GLGenSamplers(count, samplers);
}

System::OpenGLUInt System::GetGLGenSamplers() noexcept
{
    OpenGLUInt sampler{};
    GetGLGenSamplers(1, &sampler);

    return sampler;
}

void System::SetGLDeleteSamplers(OpenGLSize count, const OpenGLUInt* samplers) noexcept
{
    GLDeleteSamplers(count, samplers);
}

void System::SetGLDeleteSamplers(OpenGLUInt samplers) noexcept
{
    GLDeleteSamplers(1, &samplers);
}

void System::SetGLSamplerParameter(OpenGLUInt sampler, OpenGLTextureName pname, OpenGLInt param) noexcept
{
    GLSamplerParameteri(sampler, EnumCastUnderlying(pname), param);
}

void System::SetGLSamplerParameter(OpenGLUInt sampler, OpenGLTextureName pname, SamplerFilter param) noexcept
{
    SetGLSamplerParameter(sampler, pname, EnumCastUnderlying(param));
}

void System::SetGLSamplerParameter(OpenGLUInt sampler, OpenGLTextureName pname, TextureSamplerCoordinate param) noexcept
{
    SetGLSamplerParameter(sampler, pname, EnumCastUnderlying(param));
}

void System::SetGLSamplerParameter(OpenGLUInt sampler, OpenGLTextureName pname, OpenGLFloat param) noexcept
{
    GLSamplerParameterf(sampler, EnumCastUnderlying(pname), param);
}

void System::SetGLSamplerParameter(OpenGLUInt sampler, OpenGLTextureName pname, const OpenGLFloat* param) noexcept
{
    GLSamplerParameterfv(sampler, EnumCastUnderlying(pname), param);
}

void System::GetGLGenBuffers(OpenGLSize n, OpenGLUInt* buffers) noexcept
{
    GLGenBuffers(n, buffers);
}

System::OpenGLUInt System::GetGLGenBuffers() noexcept
{
    OpenGLUInt buffers{};
    GetGLGenBuffers(1, &buffers);

    return buffers;
}

void System::SetGLDeleteBuffers(OpenGLSize n, const OpenGLUInt* buffers) noexcept
{
    GLDeleteBuffers(n, buffers);
}

void System::SetGLDeleteBuffers(OpenGLUInt buffers) noexcept
{
    SetGLDeleteBuffers(1, &buffers);
}

void System::SetGLBindBuffer(BindBuffer type, OpenGLUInt buffer) noexcept
{
    GLBindBuffer(EnumCastUnderlying(type), buffer);
}

void System::SetGLBufferData(BindBuffer target, OpenGLSizePtr size, const void* data, BufferUsage usage) noexcept
{
    GLBufferData(EnumCastUnderlying(target), size, data, EnumCastUnderlying(usage));
}

void System::SetGLBufferSubData(BindBuffer target, OpenGLIntPtr offset, OpenGLSizePtr size, const void* data) noexcept
{
    GLBufferSubData(EnumCastUnderlying(target), offset, size, data);
}

void System::SetGLGetBufferSubData(BindBuffer target, OpenGLIntPtr offset, OpenGLSizePtr size, void* data) noexcept
{
    GLGetBufferSubData(EnumCastUnderlying(target), offset, size, data);
}

void System::SetGLBindBufferBase(BindBuffer target, OpenGLUInt index, OpenGLUInt buffer) noexcept
{
    GLBindBufferBase(EnumCastUnderlying(target), index, buffer);
}

void System::SetGLBindBufferRange(BindBuffer target, OpenGLUInt index, OpenGLUInt buffer, OpenGLIntPtr offset, OpenGLSizePtr size) noexcept
{
    GLBindBufferRange(EnumCastUnderlying(target), index, buffer, offset, size);
}

void System::SetGLCopyBufferSubData(BindBuffer readTarget, BindBuffer writeTarget, OpenGLIntPtr readOffset, OpenGLIntPtr writeOffset, OpenGLSizePtr size) noexcept
{
    GLCopyBufferSubData(EnumCastUnderlying(readTarget), EnumCastUnderlying(writeTarget), readOffset, writeOffset, size);
}

void System::SetGLBindTexture(TextureTarget target, OpenGLUInt texture) noexcept
{
    GLBindTexture(EnumCastUnderlying(target), texture);
}

void System::SetGLPixelStore(PixelStore pname, OpenGLInt param) noexcept
{
    GLPixelStorei(EnumCastUnderlying(pname), param);
}

void System::SetGLTexParameter(TextureTarget target, TexParameter pname, OpenGLInt param) noexcept
{
    GLTexParameteri(EnumCastUnderlying(target), EnumCastUnderlying(pname), param);
}

void System::SetGLGetTexImage(TextureTarget target, OpenGLInt level, TextureExternalFormat format, OpenGLData type, void* pixels) noexcept
{
    GLGetTexImage(EnumCastUnderlying(target), level, EnumCastUnderlying(format), EnumCastUnderlying(type), pixels);
}

void System::SetGLGenerateMipmap(TextureTarget target) noexcept
{
    GLGenerateMipmap(EnumCastUnderlying(target));
}

System::OpenGLUInt System::GetGLGenTextures() noexcept
{
    OpenGLUInt textures{};
    GetGLGenTextures(1, &textures);

    return textures;
}

void System::GetGLGenTextures(OpenGLSize n, OpenGLUInt* textures) noexcept
{
    GLGenTextures(n, textures);
}

void System::SetGLDeleteTextures(OpenGLSize n, const OpenGLUInt* textures) noexcept
{
    GLDeleteTextures(n, textures);
}

void System::SetGLDeleteTextures(OpenGLUInt textures) noexcept
{
    SetGLDeleteTextures(1, &textures);
}

void System::SetGLTexSubImage1D(TextureTarget target, OpenGLInt level, OpenGLInt xoffset, OpenGLSize width, TextureExternalFormat format, OpenGLData type, const void* pixels) noexcept
{
    GLTexSubImage1D(EnumCastUnderlying(target), level, xoffset, width, EnumCastUnderlying(format), EnumCastUnderlying(type), pixels);
}

void System::SetGLTexStorage1D(TextureTarget target, OpenGLSize levels, TextureInternalFormat internalformat, OpenGLSize width) noexcept
{
    GLTexStorage1D(EnumCastUnderlying(target), levels, EnumCastUnderlying(internalformat), width);
}

void System::SetGLTexSubImage2D(TextureTarget target, OpenGLInt level, OpenGLInt xoffset, OpenGLInt yoffset, OpenGLSize width, OpenGLSize height, TextureExternalFormat format, OpenGLData type, const void* pixels) noexcept
{
    GLTexSubImage2D(EnumCastUnderlying(target), level, xoffset, yoffset, width, height, EnumCastUnderlying(format), EnumCastUnderlying(type), pixels);
}

void System::SetGLTexSubImage2D(TextureCubeMap target, OpenGLInt level, OpenGLInt xoffset, OpenGLInt yoffset, OpenGLSize width, OpenGLSize height, TextureExternalFormat format, OpenGLData type, const void* pixels) noexcept
{
    GLTexSubImage2D(EnumCastUnderlying(target), level, xoffset, yoffset, width, height, EnumCastUnderlying(format), EnumCastUnderlying(type), pixels);
}

void System::SetGLTexStorage2D(TextureTarget target, OpenGLSize levels, TextureInternalFormat internalformat, OpenGLSize width, OpenGLSize height) noexcept
{
    GLTexStorage2D(EnumCastUnderlying(target), levels, EnumCastUnderlying(internalformat), width, height);
}

void System::SetGLTexSubImage3D(TextureTarget target, OpenGLInt level, OpenGLInt xoffset, OpenGLInt yoffset, OpenGLInt zoffset, OpenGLSize width, OpenGLSize height, OpenGLSize depth, TextureExternalFormat format, OpenGLData type, const void* pixels) noexcept
{
    GLTexSubImage3D(EnumCastUnderlying(target), level, xoffset, yoffset, zoffset, width, height, depth, EnumCastUnderlying(format), EnumCastUnderlying(type), pixels);
}

void System::SetGLTexSubImage3D(TextureCubeMap target, OpenGLInt level, OpenGLInt xoffset, OpenGLInt yoffset, OpenGLInt zoffset, OpenGLSize width, OpenGLSize height, OpenGLSize depth, TextureExternalFormat format, OpenGLData type, const void* pixels) noexcept
{
    GLTexSubImage3D(EnumCastUnderlying(target), level, xoffset, yoffset, zoffset, width, height, depth, EnumCastUnderlying(format), EnumCastUnderlying(type), pixels);
}

void System::SetGLTexStorage3D(TextureTarget target, OpenGLSize levels, TextureInternalFormat internalformat, OpenGLSize width, OpenGLSize height, OpenGLSize depth) noexcept
{
    GLTexStorage3D(EnumCastUnderlying(target), levels, EnumCastUnderlying(internalformat), width, height, depth);
}

void System::GetGLGenFramebuffers(OpenGLSize n, OpenGLUInt* framebuffers) noexcept
{
    GLGenFramebuffers(n, framebuffers);
}

System::OpenGLUInt System::GetGLGenFramebuffers() noexcept
{
    OpenGLUInt framebuffers{};
    GetGLGenFramebuffers(1, &framebuffers);

    return framebuffers;
}

void System::SetGLDeleteFramebuffers(OpenGLSize n, const OpenGLUInt* framebuffers) noexcept
{
    GLDeleteFramebuffers(n, framebuffers);
}

void System::SetGLDeleteFramebuffers(OpenGLUInt framebuffers) noexcept
{
    SetGLDeleteFramebuffers(1, &framebuffers);
}

void System::SetGLBindFramebuffer(FrameBufferType target, OpenGLUInt framebuffer) noexcept
{
    GLBindFramebuffer(EnumCastUnderlying(target), framebuffer);
}

void System::SetGLFramebufferTexture2D(FrameBufferType target, ColorAttachent attachment, TextureTarget textarget, OpenGLUInt texture, OpenGLInt level) noexcept
{
    GLFramebufferTexture2D(EnumCastUnderlying(target), EnumCastUnderlying(attachment), EnumCastUnderlying(textarget), texture, level);
}

void System::SetGLDrawBuffers(OpenGLSize n, const OpenGLEnum* bufs) noexcept
{
    GLDrawBuffers(n, bufs);
}

void System::SetGLBindVertexArray(OpenGLUInt array) noexcept
{
    GLBindVertexArray(array);
}

void System::SetGLDeleteVertexArrays(OpenGLSize n, const OpenGLUInt* arrays) noexcept
{
    GLDeleteVertexArrays(n, arrays);
}

void System::SetGLDeleteVertexArrays(OpenGLUInt arrays) noexcept
{
    SetGLDeleteVertexArrays(1, &arrays);
}

void System::GetGLGenVertexArrays(OpenGLSize n, OpenGLUInt* arrays) noexcept
{
    GLGenVertexArrays(n, arrays);
}

System::OpenGLUInt System::GetGLGenVertexArrays() noexcept
{
    OpenGLUInt arrays{};
    GetGLGenVertexArrays(1, &arrays);

    return arrays;
}

void System::SetGLEnableVertexAttribArray(OpenGLUInt index) noexcept
{
    GLEnableVertexAttribArray(index);
}

void System::SetGLBindVertexBuffer(OpenGLUInt bindingindex, OpenGLUInt buffer, OpenGLIntPtr offset, OpenGLSize stride) noexcept
{
    GLBindVertexBuffer(bindingindex, buffer, offset, stride);
}

void System::SetGLVertexAttribFormat(OpenGLUInt attribindex, OpenGLInt size, OpenGLEnum type, OpenGLBoolean normalized, OpenGLUInt relativeoffset) noexcept
{
    GLVertexAttribFormat(attribindex, size, type, normalized, relativeoffset);
}

void System::SetGLVertexAttribBinding(OpenGLUInt attribindex, OpenGLUInt bindingindex) noexcept
{
    GLVertexAttribBinding(attribindex, bindingindex);
}
