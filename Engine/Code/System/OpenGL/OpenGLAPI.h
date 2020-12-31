//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/25 13:17)

#ifndef SYSTEM_OPENGL_OPENGL_API_H
#define SYSTEM_OPENGL_OPENGL_API_H

#include "System/SystemDll.h"

#include "Fwd/OpenGLFlagsFwd.h"
#include "Using/OpenGLUsing.h"
#include "System/Helper/GLExtensionsMacro.h"

namespace System
{
    void SYSTEM_DEFAULT_DECLARE ClearAllGlBufferBit() noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGlViewport(OpenGLInt x, OpenGLInt y, OpenGLSize width, OpenGLSize height) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetupRenderStatus() noexcept;

    void SYSTEM_DEFAULT_DECLARE SetGlDepthRange(OpenGLDouble nearDepthRange, OpenGLDouble farDepthRange) noexcept;
    void SYSTEM_DEFAULT_DECLARE GetGlIntegerv(OpenGLQuery name, OpenGLInt* params) noexcept;
    void SYSTEM_DEFAULT_DECLARE GetGlBooleanv(OpenGLQuery name, OpenGLBoolean* params) noexcept;
    void SYSTEM_DEFAULT_DECLARE GetGlFloatv(OpenGLQuery name, OpenGLFloat* params) noexcept;
    void SYSTEM_DEFAULT_DECLARE GetGlDoublev(OpenGLQuery name, OpenGLDouble* params) noexcept;

    void SYSTEM_DEFAULT_DECLARE SetGlBindTexture(TextureTarget target, OpenGLUInt texture) noexcept;
    void SYSTEM_DEFAULT_DECLARE GlEnablePositionArray(OpenGLInt size, OpenGLData type, OpenGLSize stride, const OpenGLVoid* pointer) noexcept;
    void SYSTEM_DEFAULT_DECLARE GlEnableNormalArray(OpenGLInt size, OpenGLData type, OpenGLSize stride, const OpenGLVoid* pointer) noexcept;

    void SYSTEM_DEFAULT_DECLARE GlEnableTangentArray(OpenGLInt size, OpenGLData type, OpenGLSize stride, const OpenGLVoid* pointer) noexcept;

    void SYSTEM_DEFAULT_DECLARE GlEnableBinormalArray(OpenGLInt size, OpenGLData type, OpenGLSize stride, const OpenGLVoid* pointer) noexcept;

    void SYSTEM_DEFAULT_DECLARE GlEnableTextureArray(int index, OpenGLInt size, OpenGLData type, OpenGLSize stride, const OpenGLVoid* pointer) noexcept;

    void SYSTEM_DEFAULT_DECLARE GlEnableColorArray(OpenGLInt size, OpenGLData type, OpenGLSize stride, const OpenGLVoid* pointer) noexcept;

    void SYSTEM_DEFAULT_DECLARE GlEnableSecondaryColorArray(OpenGLInt size, OpenGLData type, OpenGLSize stride, const OpenGLVoid* pointer) noexcept;
    void SYSTEM_DEFAULT_DECLARE GlEnableBlendIndicesArray(OpenGLInt size, OpenGLData type, OpenGLSize stride, OpenGLVoid* pointer) noexcept;

    void SYSTEM_DEFAULT_DECLARE GlEnableBlendWeightArray(OpenGLInt size, OpenGLData type, OpenGLSize stride, OpenGLVoid* pointer) noexcept;

    void SYSTEM_DEFAULT_DECLARE GlEnableFogCoordArray(OpenGLInt size, OpenGLData type, OpenGLSize stride, const OpenGLVoid* pointer) noexcept;

    void SYSTEM_DEFAULT_DECLARE GlEnablePSizeArray(OpenGLInt size, OpenGLData type, OpenGLSize stride, const OpenGLVoid* pointer) noexcept;

    void SYSTEM_DEFAULT_DECLARE GlDisablePositionArray() noexcept;
    void SYSTEM_DEFAULT_DECLARE GlDisableNormalArray() noexcept;
    void SYSTEM_DEFAULT_DECLARE GlDisableTangentArray() noexcept;
    void SYSTEM_DEFAULT_DECLARE GlDisableBinormalArray() noexcept;
    void SYSTEM_DEFAULT_DECLARE GlDisableTextureArray(int index) noexcept;
    void SYSTEM_DEFAULT_DECLARE GlDisableColorArray() noexcept;
    void SYSTEM_DEFAULT_DECLARE GlDisableSecondaryColorArray() noexcept;
    void SYSTEM_DEFAULT_DECLARE GlDisableBlendIndicesArray() noexcept;
    void SYSTEM_DEFAULT_DECLARE GlDisableBlendWeightArray() noexcept;
    void SYSTEM_DEFAULT_DECLARE GlDisableFogCoordArray() noexcept;
    void SYSTEM_DEFAULT_DECLARE GlDisablePSizeArray() noexcept;

    [[nodiscard]] OpenGLUInt SYSTEM_DEFAULT_DECLARE GlBufferData(int numBytes, OpenGLUInt usage) noexcept;
    [[nodiscard]] OpenGLUInt SYSTEM_DEFAULT_DECLARE GlDeleteBuffers(OpenGLUInt buffer) noexcept;
    void SYSTEM_DEFAULT_DECLARE GlBindBuffer(OpenGLUInt buffer) noexcept;
    [[nodiscard]] SYSTEM_DEFAULT_DECLARE OpenGLVoid* GetGlMapBuffer(OpenGLUInt buffer, OpenGLUInt usage) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGlUnmapBuffer(OpenGLUInt buffer) noexcept;

    [[nodiscard]] OpenGLUInt SYSTEM_DEFAULT_DECLARE GlElementBufferData(int numBytes, OpenGLUInt usage) noexcept;
    [[nodiscard]] OpenGLUInt SYSTEM_DEFAULT_DECLARE GlDeleteElementBuffers(OpenGLUInt buffer) noexcept;
    void SYSTEM_DEFAULT_DECLARE GlBindElementBuffer(OpenGLUInt buffer) noexcept;
    [[nodiscard]] SYSTEM_DEFAULT_DECLARE OpenGLVoid* GlMapElementBuffer(OpenGLUInt buffer, OpenGLUInt usage) noexcept;
    void SYSTEM_DEFAULT_DECLARE GlUnmapElementBuffer(OpenGLUInt buffer) noexcept;

    [[nodiscard]] OpenGLUInt SYSTEM_DEFAULT_DECLARE GlPixelUnpackBufferData(int numBytes, OpenGLUInt usage) noexcept;
    [[nodiscard]] OpenGLUInt SYSTEM_DEFAULT_DECLARE GlDeletePixelUnpackBuffers(OpenGLUInt buffer) noexcept;
    [[nodiscard]] SYSTEM_DEFAULT_DECLARE OpenGLVoid* GlMapPixelUnpackBuffer(OpenGLUInt buffer, OpenGLUInt usage) noexcept;
    void SYSTEM_DEFAULT_DECLARE GlBindPixelUnpackBuffer(OpenGLUInt buffer) noexcept;
    void SYSTEM_DEFAULT_DECLARE GlUnmapPixelUnpackBuffer() noexcept;

    [[nodiscard]] OpenGLUInt SYSTEM_DEFAULT_DECLARE GlGenTextures() noexcept;

    void SYSTEM_DEFAULT_DECLARE GlTexImage1D(OpenGLUInt level, TextureInternalFormat internalformat, OpenGLSize width, TextureFormat format, OpenGLData type) noexcept;
    void SYSTEM_DEFAULT_DECLARE GlTexSubImage1D(OpenGLUInt level, OpenGLSize width, TextureFormat format, OpenGLData type, const OpenGLVoid* pixels = nullptr) noexcept;
    void SYSTEM_DEFAULT_DECLARE GlTexImage2D(OpenGLEnum target, OpenGLUInt level, TextureInternalFormat internalformat, OpenGLSize width,
                                             OpenGLSize height, TextureFormat format, OpenGLData type, const OpenGLVoid* pixels = nullptr) noexcept;
    void SYSTEM_DEFAULT_DECLARE GlCompressedTexImage2D(OpenGLEnum target, OpenGLUInt level, TextureInternalFormat internalformat,
                                                       OpenGLSize width, OpenGLSize height, OpenGLSize imageSize) noexcept;
    void SYSTEM_DEFAULT_DECLARE GetGlTexImage3D(OpenGLUInt level, TextureInternalFormat internalformat, OpenGLSize width, OpenGLSize height,
                                                OpenGLSize depth, TextureFormat format, OpenGLData type) noexcept;

    void SYSTEM_DEFAULT_DECLARE GlTexSubImage3D(OpenGLUInt level, OpenGLSize width, OpenGLSize height, OpenGLSize depth,
                                                TextureFormat format, OpenGLData type, const OpenGLVoid* pixels = nullptr) noexcept;

    void SYSTEM_DEFAULT_DECLARE GlTexSubImage2D(OpenGLEnum target, OpenGLUInt level, OpenGLSize width, OpenGLSize height,
                                                TextureFormat format, OpenGLData type, const OpenGLVoid* pixels = nullptr) noexcept;
    void SYSTEM_DEFAULT_DECLARE GlCompressedTexSubImage2D(OpenGLEnum target, OpenGLUInt level, OpenGLSize width, OpenGLSize height,
                                                          TextureInternalFormat internalformat, OpenGLSize imageSize, const OpenGLVoid* data = nullptr) noexcept;

    [[nodiscard]] OpenGLUInt SYSTEM_DEFAULT_DECLARE GlDeleteTextures(OpenGLUInt texture) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGlActiveTexture(OpenGLUInt texture) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGlGenerateMipmap(TextureTarget target, OpenGLUInt texture) noexcept;

    [[nodiscard]] OpenGLUInt SYSTEM_DEFAULT_DECLARE GlGenFramebuffers() noexcept;
    [[nodiscard]] OpenGLUInt SYSTEM_DEFAULT_DECLARE GlDeleteFramebuffers(OpenGLUInt frameBuffer) noexcept;
    void SYSTEM_DEFAULT_DECLARE BindColorTexture(OpenGLUInt colorTextures, bool hasMipmaps) noexcept;
    void SYSTEM_DEFAULT_DECLARE AttachTextureToFramebuffer(OpenGLUInt drawBuffers, OpenGLUInt colorTextures) noexcept;
    [[nodiscard]] CheckFrambufferStatus SYSTEM_DEFAULT_DECLARE GlCheckFramebufferStatus() noexcept;
    void SYSTEM_DEFAULT_DECLARE GlBindFramebuffer(OpenGLUInt frameBuffer) noexcept;
    void SYSTEM_DEFAULT_DECLARE GetGlDrawBuffers(OpenGLSize n, const OpenGLEnum* bufs) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGlReadBuffer(OpenGLEnum mode) noexcept;
    void SYSTEM_DEFAULT_DECLARE GlReadPixels(OpenGLSize width, OpenGLSize height, TextureFormat format, OpenGLData type, OpenGLVoid* pixel) noexcept;
}

#endif  // SYSTEM_OPENGL_OPENGL_API_H