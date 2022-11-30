///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.4 (2022/11/19 18:30)

#ifndef SYSTEM_OPENGL_OPENGL_API_H
#define SYSTEM_OPENGL_OPENGL_API_H

#include "System/SystemDll.h"

#include "Fwd/OpenGLFlagsFwd.h"
#include "Using/OpenGLUsing.h"
#include "System/Helper/GLExtensionsMacro.h"

namespace System
{
    void SYSTEM_DEFAULT_DECLARE ClearAllGLBufferBit() noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLViewport(OpenGLInt x, OpenGLInt y, OpenGLSize width, OpenGLSize height) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetupRenderStatus() noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLDepthRange(OpenGLDouble nearDepthRange, OpenGLDouble farDepthRange) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLClearColor(OpenGLFloat red, OpenGLFloat green, OpenGLFloat blue, OpenGLFloat alpha) noexcept;

    NODISCARD OpenGLInt SYSTEM_DEFAULT_DECLARE GetGLInteger(OpenGLQuery name) noexcept;
    NODISCARD OpenGLInt SYSTEM_DEFAULT_DECLARE GetGLInteger(TextureTargetBinding name) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetGLBoolean(OpenGLQuery name) noexcept;
    NODISCARD OpenGLFloat SYSTEM_DEFAULT_DECLARE GetGLFloat(OpenGLQuery name) noexcept;
    NODISCARD OpenGLDouble SYSTEM_DEFAULT_DECLARE GetGLDouble(OpenGLQuery name) noexcept;

    void SYSTEM_DEFAULT_DECLARE GetGLInteger(OpenGLQuery name, OpenGLInt* data) noexcept;
    void SYSTEM_DEFAULT_DECLARE GetGLDouble(OpenGLQuery name, OpenGLDouble* data) noexcept;

    void SYSTEM_DEFAULT_DECLARE EnableGLState(OpenGLEnable cap) noexcept;
    void SYSTEM_DEFAULT_DECLARE DisableGLState(OpenGLEnable cap) noexcept;
    void SYSTEM_DEFAULT_DECLARE EnableGLState(OpenGLEnable target, OpenGLUInt index) noexcept;
    void SYSTEM_DEFAULT_DECLARE DisableGLState(OpenGLEnable target, OpenGLUInt index) noexcept;

    void SYSTEM_DEFAULT_DECLARE SetGLBlendColor(OpenGLFloat red, OpenGLFloat green, OpenGLFloat blue, OpenGLFloat alpha) noexcept;

    void SYSTEM_DEFAULT_DECLARE SetGLColorMask(OpenGLBoolean red, OpenGLBoolean green, OpenGLBoolean blue, OpenGLBoolean alpha) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLColorMask(OpenGLUInt index, OpenGLBoolean red, OpenGLBoolean green, OpenGLBoolean blue, OpenGLBoolean alpha) noexcept;

    void SYSTEM_DEFAULT_DECLARE SetGLSampleMask(OpenGLUInt maskNumber, OpenGLBitfield mask) noexcept;

    void SYSTEM_DEFAULT_DECLARE SetGLBlendFuncSeparate(OpenGLEnum sourceFactorRGB, OpenGLEnum destinationFactorRGB, OpenGLEnum sourceFactorAlpha, OpenGLEnum destinationFfactorAlpha) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLBlendFuncSeparate(OpenGLUInt index, OpenGLEnum sourceFactorRGB, OpenGLEnum destinationFactorRGB, OpenGLEnum sourceFactorAlpha, OpenGLEnum destinationFfactorAlpha) noexcept;

    void SYSTEM_DEFAULT_DECLARE SetGLBlendEquationSeparate(GLenum modeRGB, GLenum modeAlpha) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLBlendEquationSeparate(OpenGLUInt index, GLenum modeRGB, GLenum modeAlpha) noexcept;

    void SYSTEM_DEFAULT_DECLARE SetGLDepthFunc(DepthStencilStateMode depthStencilStateMode) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLDepthMask(DepthStencilStateWriteMask flag) noexcept;

    void SYSTEM_DEFAULT_DECLARE SetGLStencilFuncSeparate(RasterizerStateCullFace face, DepthStencilStateMode func, OpenGLInt ref, OpenGLUInt mask) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLStencilMaskSeparate(RasterizerStateCullFace face, OpenGLUInt mask) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLStencilOpSeparate(RasterizerStateCullFace face, DepthStencilStateOperation sfail, DepthStencilStateOperation dpfail, DepthStencilStateOperation dppass) noexcept;

    void SYSTEM_DEFAULT_DECLARE SetGLPolygonMode(RasterizerStateCullFace face, RasterizerStateFillMode mode) noexcept;

    void SYSTEM_DEFAULT_DECLARE SetGLPolygonOffset(OpenGLFloat factor, OpenGLFloat units) noexcept;

    void SYSTEM_DEFAULT_DECLARE SetGLFrontFace(OpenGLFrontFace mode) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLCullFace(RasterizerStateCullFace mode) noexcept;

    void SYSTEM_DEFAULT_DECLARE GetGLGenSamplers(OpenGLSize count, OpenGLUInt* samplers) noexcept;
    NODISCARD OpenGLUInt SYSTEM_DEFAULT_DECLARE GetGLGenSamplers() noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLDeleteSamplers(OpenGLSize count, const OpenGLUInt* samplers) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLDeleteSamplers(OpenGLUInt samplers) noexcept;

    void SYSTEM_DEFAULT_DECLARE SetGLSamplerParameter(OpenGLUInt sampler, OpenGLTextureName pname, OpenGLInt param) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLSamplerParameter(OpenGLUInt sampler, OpenGLTextureName pname, TextureSamplerCoordinate param) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLSamplerParameter(OpenGLUInt sampler, OpenGLTextureName pname, SamplerFilter param) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLSamplerParameter(OpenGLUInt sampler, OpenGLTextureName pname, OpenGLFloat param) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLSamplerParameter(OpenGLUInt sampler, OpenGLTextureName pname, const OpenGLFloat* param) noexcept;

    void SYSTEM_DEFAULT_DECLARE GetGLGenBuffers(OpenGLSize n, OpenGLUInt* buffers) noexcept;
    NODISCARD OpenGLUInt SYSTEM_DEFAULT_DECLARE GetGLGenBuffers() noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLDeleteBuffers(OpenGLSize n, const OpenGLUInt* buffers) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLDeleteBuffers(OpenGLUInt buffers) noexcept;

    void SYSTEM_DEFAULT_DECLARE SetGLBindBuffer(BindBuffer type, OpenGLUInt buffer) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLBufferData(BindBuffer target, OpenGLSizePtr size, const void* data, BufferUsage usage) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLBufferSubData(BindBuffer target, OpenGLIntPtr offset, OpenGLSizePtr size, const void* data) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLGetBufferSubData(BindBuffer target, OpenGLIntPtr offset, OpenGLSizePtr size, void* data) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLBindBufferBase(BindBuffer target, OpenGLUInt index, OpenGLUInt buffer) noexcept;

    void SYSTEM_DEFAULT_DECLARE SetGLBindBufferRange(BindBuffer target, OpenGLUInt index, OpenGLUInt buffer, OpenGLIntPtr offset, OpenGLSizePtr size) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLCopyBufferSubData(BindBuffer readTarget, BindBuffer writeTarget, OpenGLIntPtr readOffset, OpenGLIntPtr writeOffset, OpenGLSizePtr size) noexcept;

    void SYSTEM_DEFAULT_DECLARE SetGLBindTexture(TextureTarget target, OpenGLUInt texture) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLPixelStore(PixelStore pname, OpenGLInt param) noexcept;

    void SYSTEM_DEFAULT_DECLARE SetGLTexParameter(TextureTarget target, TextureParameter pname, OpenGLInt param) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLGetTexImage(TextureTarget target, OpenGLInt level, TextureExternalFormat format, OpenGLData type, void* pixels) noexcept;

    void SYSTEM_DEFAULT_DECLARE SetGLGenerateMipmap(TextureTarget target) noexcept;

    void SYSTEM_DEFAULT_DECLARE GetGLGenTextures(OpenGLSize n, OpenGLUInt* textures) noexcept;
    NODISCARD OpenGLUInt SYSTEM_DEFAULT_DECLARE GetGLGenTextures() noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLDeleteTextures(OpenGLSize n, const OpenGLUInt* textures) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLDeleteTextures(OpenGLUInt textures) noexcept;

    void SYSTEM_DEFAULT_DECLARE SetGLTexSubImage1D(TextureTarget target, OpenGLInt level, OpenGLInt xoffset, OpenGLSize width, TextureExternalFormat format, OpenGLData type, const void* pixels) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLTexStorage1D(TextureTarget target, OpenGLSize levels, TextureInternalFormat internalformat, OpenGLSize width) noexcept;

    void SYSTEM_DEFAULT_DECLARE SetGLTexSubImage2D(TextureTarget target, OpenGLInt level, OpenGLInt xoffset, OpenGLInt yoffset, OpenGLSize width, OpenGLSize height, TextureExternalFormat format, OpenGLData type, const void* pixels) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLTexSubImage2D(TextureCubeMap target, OpenGLInt level, OpenGLInt xoffset, OpenGLInt yoffset, OpenGLSize width, OpenGLSize height, TextureExternalFormat format, OpenGLData type, const void* pixels) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLTexStorage2D(TextureTarget target, OpenGLSize levels, TextureInternalFormat internalformat, OpenGLSize width, OpenGLSize height) noexcept;

    void SYSTEM_DEFAULT_DECLARE SetGLTexSubImage3D(TextureTarget target, OpenGLInt level, OpenGLInt xoffset, OpenGLInt yoffset, OpenGLInt zoffset, OpenGLSize width, OpenGLSize height, OpenGLSize depth, TextureExternalFormat format, OpenGLData type, const void* pixels) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLTexSubImage3D(TextureCubeMap target, OpenGLInt level, OpenGLInt xoffset, OpenGLInt yoffset, OpenGLInt zoffset, OpenGLSize width, OpenGLSize height, OpenGLSize depth, TextureExternalFormat format, OpenGLData type, const void* pixels) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLTexStorage3D(TextureTarget target, OpenGLSize levels, TextureInternalFormat internalformat, OpenGLSize width, OpenGLSize height, OpenGLSize depth) noexcept;

    void SYSTEM_DEFAULT_DECLARE GetGLGenFramebuffers(OpenGLSize n, OpenGLUInt* framebuffers) noexcept;
    NODISCARD OpenGLUInt SYSTEM_DEFAULT_DECLARE GetGLGenFramebuffers() noexcept;

    void SYSTEM_DEFAULT_DECLARE SetGLDeleteFramebuffers(OpenGLSize n, const OpenGLUInt* framebuffers) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLDeleteFramebuffers(OpenGLUInt framebuffers) noexcept;

    void SYSTEM_DEFAULT_DECLARE SetGLBindFramebuffer(FrameBufferType target, OpenGLUInt framebuffer) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLFramebufferTexture2D(FrameBufferType target, ColorAttachent attachment, TextureTarget textarget, OpenGLUInt texture, OpenGLInt level) noexcept;

    void SYSTEM_DEFAULT_DECLARE SetGLDrawBuffers(OpenGLSize n, const OpenGLEnum* bufs) noexcept;

    void SYSTEM_DEFAULT_DECLARE SetGLBindVertexArray(OpenGLUInt array) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLDeleteVertexArrays(OpenGLSize n, const OpenGLUInt* arrays) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLDeleteVertexArrays(OpenGLUInt arrays) noexcept;
    void SYSTEM_DEFAULT_DECLARE GetGLGenVertexArrays(OpenGLSize n, OpenGLUInt* arrays) noexcept;
    NODISCARD OpenGLUInt SYSTEM_DEFAULT_DECLARE GetGLGenVertexArrays() noexcept;

    void SYSTEM_DEFAULT_DECLARE SetGLEnableVertexAttribArray(OpenGLUInt index) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLBindVertexBuffer(OpenGLUInt bindingindex, OpenGLUInt buffer, OpenGLIntPtr offset, OpenGLSize stride) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLVertexAttribFormat(OpenGLUInt attribindex, OpenGLInt size, OpenGLEnum type, OpenGLBoolean normalized, OpenGLUInt relativeoffset) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLVertexAttribBinding(OpenGLUInt attribindex, OpenGLUInt bindingindex) noexcept;
}

#endif  // SYSTEM_OPENGL_OPENGL_API_H