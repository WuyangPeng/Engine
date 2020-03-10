// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:36)

#ifndef SYSTEM_OPENGL_OPENGL_API_FWD_H
#define SYSTEM_OPENGL_OPENGL_API_FWD_H  

#include "OpenGLFlagsFwd.h"
#include "System/OpenGL/Using/OpenGLUsing.h"

namespace System
{
	void ClearAllGlBufferBit() noexcept;
	void SetGlViewport(OpenGLInt x, OpenGLInt y, OpenGLSize width, OpenGLSize height) noexcept;
	void SetupRenderStatus() noexcept;

	void SetGlDepthRange(OpenGLDouble nearDepthRange, OpenGLDouble farDepthRange) noexcept;
	void GetGlIntegerv(OpenGLQuery name, OpenGLInt* params) noexcept;
	void GetGlBooleanv(OpenGLQuery name, OpenGLBoolean* params) noexcept;
	void GetGlFloatv(OpenGLQuery name, OpenGLFloat* params) noexcept;
	void GetGlDoublev(OpenGLQuery name, OpenGLDouble* params) noexcept;

	void SetGlBindTexture(TextureTarget target, OpenGLUInt texture) noexcept;
	void GlEnablePositionArray(OpenGLInt size, OpenGLData type, OpenGLSize stride, const OpenGLVoid* pointer) noexcept;
	void GlEnableNormalArray(OpenGLInt size, OpenGLData type, OpenGLSize stride, const OpenGLVoid* pointer) noexcept;

	void GlEnableTangentArray(OpenGLInt size, OpenGLData type, OpenGLSize stride, const OpenGLVoid* pointer) noexcept;

	void GlEnableBinormalArray(OpenGLInt size, OpenGLData type, OpenGLSize stride, const OpenGLVoid* pointer) noexcept;

	void GlEnableTextureArray(int index, OpenGLInt size, OpenGLData type, OpenGLSize stride, const OpenGLVoid* pointer) noexcept;

	void GlEnableColorArray(OpenGLInt size, OpenGLData type, OpenGLSize stride, const OpenGLVoid* pointer) noexcept;

	void GlEnableSecondaryColorArray(OpenGLInt size, OpenGLData type, OpenGLSize stride, const OpenGLVoid* pointer) noexcept;
	void GlEnableBlendIndicesArray(OpenGLInt size, OpenGLData type, OpenGLSize stride, OpenGLVoid* pointer) noexcept;

	void GlEnableBlendWeightArray(OpenGLInt size, OpenGLData type, OpenGLSize stride, OpenGLVoid* pointer) noexcept;

	void GlEnableFogCoordArray(OpenGLInt size, OpenGLData type, OpenGLSize stride, const OpenGLVoid* pointer) noexcept;

	void GlEnablePSizeArray(OpenGLInt size, OpenGLData type, OpenGLSize stride, const OpenGLVoid* pointer) noexcept;

	void GlDisablePositionArray() noexcept;
	void GlDisableNormalArray() noexcept;
	void GlDisableTangentArray() noexcept;
	void GlDisableBinormalArray() noexcept;
	void GlDisableTextureArray(int index) noexcept;
	void GlDisableColorArray() noexcept;
	void GlDisableSecondaryColorArray() noexcept;
	void GlDisableBlendIndicesArray() noexcept;
	void GlDisableBlendWeightArray() noexcept;
	void GlDisableFogCoordArray() noexcept;
	void GlDisablePSizeArray() noexcept;

	OpenGLUInt GlBufferData(int numBytes, OpenGLUInt usage) noexcept;
	OpenGLUInt GlDeleteBuffers(OpenGLUInt buffer) noexcept;
	void GlBindBuffer(OpenGLUInt buffer) noexcept;
	OpenGLVoid* GetGlMapBuffer(OpenGLUInt buffer, OpenGLUInt usage) noexcept;
	void SetGlUnmapBuffer(OpenGLUInt buffer) noexcept;

	OpenGLUInt GlElementBufferData(int numBytes, OpenGLUInt usage) noexcept;
	OpenGLUInt GlDeleteElementBuffers(OpenGLUInt buffer) noexcept;
	void GlBindElementBuffer(OpenGLUInt buffer) noexcept;
	OpenGLVoid* GlMapElementBuffer(OpenGLUInt buffer, OpenGLUInt usage) noexcept;
	void GlUnmapElementBuffer(OpenGLUInt buffer) noexcept;

	OpenGLUInt GlPixelUnpackBufferData(int numBytes, OpenGLUInt usage) noexcept;
	OpenGLUInt GlDeletePixelUnpackBuffers(OpenGLUInt buffer) noexcept;
	OpenGLVoid* GlMapPixelUnpackBuffer(OpenGLUInt buffer, OpenGLUInt usage) noexcept;
	void GlBindPixelUnpackBuffer(OpenGLUInt buffer) noexcept;
	void GlUnmapPixelUnpackBuffer() noexcept;

	OpenGLUInt GlGenTextures() noexcept;

	void GlTexImage1D(OpenGLUInt level, TextureInternalFormat internalformat, OpenGLSize width, TextureFormat format, OpenGLData type) noexcept;
	void GlTexSubImage1D(OpenGLUInt level, OpenGLSize width, TextureFormat format, OpenGLData type, const OpenGLVoid* pixels = nullptr) noexcept;
	void GlTexImage2D(OpenGLEnum target, OpenGLUInt level, TextureInternalFormat internalformat, OpenGLSize width,
					  OpenGLSize height, TextureFormat format, OpenGLData type, const OpenGLVoid* pixels = nullptr) noexcept;
	void GlCompressedTexImage2D(OpenGLEnum target, OpenGLUInt level, TextureInternalFormat internalformat,
								OpenGLSize width, OpenGLSize height, OpenGLSize imageSize) noexcept;
	void GetGlTexImage3D(OpenGLUInt level, TextureInternalFormat internalformat, OpenGLSize width, OpenGLSize height,
						 OpenGLSize depth, TextureFormat format, OpenGLData type) noexcept;

	void GlTexSubImage3D(OpenGLUInt level, OpenGLSize width, OpenGLSize height, OpenGLSize depth,
						 TextureFormat format, OpenGLData type, const OpenGLVoid* pixels = nullptr) noexcept;

	void GlTexSubImage2D(OpenGLEnum target, OpenGLUInt level, OpenGLSize width, OpenGLSize height,
						 TextureFormat format, OpenGLData type, const OpenGLVoid* pixels = nullptr) noexcept;
	void GlCompressedTexSubImage2D(OpenGLEnum target, OpenGLUInt level, OpenGLSize width, OpenGLSize height,
								   TextureInternalFormat internalformat, OpenGLSize imageSize, const OpenGLVoid* data = nullptr) noexcept;

	OpenGLUInt GlDeleteTextures(OpenGLUInt texture) noexcept;
	void SetGlActiveTexture(OpenGLUInt texture) noexcept;
	void SetGlGenerateMipmap(TextureTarget target, OpenGLUInt texture) noexcept;

	OpenGLUInt GlGenFramebuffers() noexcept;
	OpenGLUInt GlDeleteFramebuffers(OpenGLUInt frameBuffer) noexcept;
	void BindColorTexture(OpenGLUInt colorTextures, bool hasMipmaps) noexcept;
	void AttachTextureToFramebuffer(OpenGLUInt drawBuffers, OpenGLUInt colorTextures) noexcept;
	CheckFrambufferStatus GlCheckFramebufferStatus() noexcept;
	void GlBindFramebuffer(OpenGLUInt frameBuffer) noexcept;
	void GetGlDrawBuffers(OpenGLSize n, const OpenGLEnum* bufs) noexcept;
	void SetGlReadBuffer(OpenGLEnum mode) noexcept;
	void GlReadPixels(OpenGLSize width, OpenGLSize height, TextureFormat format, OpenGLData type, OpenGLVoid* pixel) noexcept;
}

#endif // SYSTEM_OPENGL_OPENGL_API_FWD_H