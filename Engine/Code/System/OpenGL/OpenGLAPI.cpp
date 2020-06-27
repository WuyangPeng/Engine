// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.0 (2020/01/02 15:48)

#include "System/SystemExport.h"

#include "OpenGLAPI.h" 
#include "Detail/GL11Extensions.h"
#include "Detail/GL12Extensions.h"
#include "Detail/GL13Extensions.h"
#include "Detail/GL14Extensions.h"
#include "Detail/GL15Extensions.h"
#include "Detail/GL20Extensions.h"
#include "Detail/GLARBExtensions.h" 
#include "Detail/GLEXTExtensions.h"  
#include "Flags/OpenGLFlags.h"
#include "Flags/GLExtensionsFlags.h"
#include "System/Helper/UnusedMacro.h"
#include "System/Helper/EnumCast.h"

void System
	::ClearAllGlBufferBit() noexcept
{
	glClear(EnumCastUnderlying(OpenGLClearMask::ColorBufferBit | OpenGLClearMask::DepthBufferBit | OpenGLClearMask::StencilBufferBit | OpenGLClearMask::AccumBufferBit));
}

void System
	::SetGlViewport(OpenGLInt x, OpenGLInt y, OpenGLSize width, OpenGLSize height) noexcept
{
	glViewport(x, y, width, height);
}

void System
	::SetupRenderStatus() noexcept
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	glClearStencil(0);
	glClearDepth(1.0);

	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glFrontFace(GL_CCW);
	glEnable(GL_CULL_FACE);
}

void System
	::GetGlIntegerv(OpenGLQuery name, OpenGLInt* params) noexcept
{
	glGetIntegerv(EnumCastUnderlying(name), params);
}

void System
	::GetGlBooleanv(OpenGLQuery name, OpenGLBoolean* params) noexcept
{
	glGetBooleanv(EnumCastUnderlying(name), params);
}

void System
	::GetGlFloatv(OpenGLQuery name, OpenGLFloat* params) noexcept
{
	glGetFloatv(EnumCastUnderlying(name), params);
}

void System
	::GetGlDoublev(OpenGLQuery name, OpenGLDouble* params) noexcept
{
	glGetDoublev(EnumCastUnderlying(name), params);
}

void System
	::SetGlBindTexture(TextureTarget target, OpenGLUInt texture) noexcept
{
	glBindTexture(EnumCastUnderlying(target), texture);
}

void System
	::GlEnablePositionArray(OpenGLInt size, OpenGLData type, OpenGLSize stride, const OpenGLVoid* pointer) noexcept
{
	glEnableClientState(EnumCastUnderlying(ClientState::VertexArray));
	glVertexPointer(size, EnumCastUnderlying(type), stride, pointer);
}

void System
	::GlEnableNormalArray(OpenGLInt size, OpenGLData type, OpenGLSize stride, const OpenGLVoid* pointer) noexcept
{
#ifdef SYSTEM_USE_OPENGL2_NORMAL_ATTRIBUTES

	glEnableVertexAttribArray(EnumCastUnderlying(AttributeUsage::Normal));
	glVertexAttribPointer(EnumCastUnderlying(AttributeUsage::Normal), size, EnumCastUnderlying(type), GL_FALSE, stride, pointer);

#else // !SYSTEM_USE_OPENGL2_NORMAL_ATTRIBUTES

	glEnableClientState(EnumCastUnderlying(ClientState::NormalArray));
	glNormalPointer(EnumCastUnderlying(type), stride, pointer);

	SYSTEM_UNUSED_ARG(size);

#endif // SYSTEM_USE_OPENGL2_NORMAL_ATTRIBUTES
}

void System
	::GlEnableTangentArray(OpenGLInt size, OpenGLData type, OpenGLSize stride, const OpenGLVoid* pointer) noexcept
{
	glEnableVertexAttribArray(EnumCastUnderlying(AttributeUsage::Tangent));
	glVertexAttribPointer(EnumCastUnderlying(AttributeUsage::Tangent), size, EnumCastUnderlying(type), GL_FALSE, stride, pointer);
}

void System
	::GlEnableBinormalArray(OpenGLInt size, OpenGLData type, OpenGLSize stride, const OpenGLVoid* pointer) noexcept
{
	glEnableVertexAttribArray(EnumCastUnderlying(AttributeUsage::Binormal));
	glVertexAttribPointer(EnumCastUnderlying(AttributeUsage::Binormal), size, EnumCastUnderlying(type), GL_FALSE, stride, pointer);
}

void  System
	::GlEnableTextureArray(int index, OpenGLInt size, OpenGLData type, OpenGLSize stride, const OpenGLVoid* pointer) noexcept
{
	glClientActiveTexture(EnumCastUnderlying(TextureNumber::Type0) + index);
	glEnableClientState(EnumCastUnderlying(ClientState::TextureCoordArray));
	glTexCoordPointer(size, EnumCastUnderlying(type), stride, pointer);
}

void System
	::GlEnableColorArray(OpenGLInt size, OpenGLData type, OpenGLSize stride, const OpenGLVoid* pointer) noexcept
{
	glEnableClientState(EnumCastUnderlying(ClientState::ColorArray));
	glColorPointer(size, EnumCastUnderlying(type), stride, pointer);
}

void  System
	::GlEnableSecondaryColorArray(OpenGLInt size, OpenGLData type, OpenGLSize stride, const OpenGLVoid* pointer) noexcept
{
	glEnableClientState(EnumCastUnderlying(ClientState::SecondaryColorArray));
	glSecondaryColorPointer(size, EnumCastUnderlying(type), stride, pointer);
}

void System
	::GlEnableBlendIndicesArray(OpenGLInt size, OpenGLData type, OpenGLSize stride, OpenGLVoid* pointer) noexcept
{
	if (IsExistsGlArbMatrixPalette() == ExistsOpenGLExtensions::Exists)
	{
		glEnableClientState(EnumCastUnderlying(ClientState::MatrixIndexArray));

		glMatrixIndexPointerARB(size, EnumCastUnderlying(type), stride, pointer);
	}
}

void System
	::GlEnableBlendWeightArray(OpenGLInt size, OpenGLData type, OpenGLSize stride, OpenGLVoid* pointer) noexcept
{
	if (IsExistsGlArbVertexBlend() == ExistsOpenGLExtensions::Exists)
	{
		glEnableClientState(EnumCastUnderlying(ClientState::WeightArray));

		glWeightPointerARB(size, EnumCastUnderlying(type), stride, pointer);
	}
}

void System
	::GlEnableFogCoordArray(OpenGLInt size, OpenGLData type, OpenGLSize stride, const OpenGLVoid* pointer) noexcept
{
	glEnableVertexAttribArray(EnumCastUnderlying(AttributeUsage::FogCoord));
	glVertexAttribPointer(EnumCastUnderlying(AttributeUsage::FogCoord), size, EnumCastUnderlying(type), GL_FALSE, stride, pointer);

	// OpenGL2之前的调用，这里没有能力指定信道的数目。
	// glEnableClientState(EnumCastUnderlying(ClientState::FogCoordinateArray));
	// glFogCoordPointerEXT(EnumCastUnderlying(type), stride,pointer);
}

void System
	::GlEnablePSizeArray(OpenGLInt size, OpenGLData type, OpenGLSize stride, const OpenGLVoid* pointer) noexcept
{
	glEnableVertexAttribArray(EnumCastUnderlying(AttributeUsage::Psize));
	glVertexAttribPointer(EnumCastUnderlying(AttributeUsage::Psize), size, EnumCastUnderlying(type), GL_FALSE, stride, pointer);
}

void System
	::GlDisablePositionArray() noexcept
{
	glDisableClientState(EnumCastUnderlying(ClientState::VertexArray));
}

void System
	::GlDisableNormalArray() noexcept
{
#ifdef SYSTEM_USE_OPENGL2_NORMAL_ATTRIBUTES
	glDisableVertexAttribArray(EnumCastUnderlying(AttributeUsage::Normal));
#else // !SYSTEM_USE_OPENGL2_NORMAL_ATTRIBUTES
	glDisableClientState(EnumCastUnderlying(ClientState::NormalArray));
#endif // SYSTEM_USE_OPENGL2_NORMAL_ATTRIBUTES
}

void System
	::GlDisableTangentArray() noexcept
{
	glDisableVertexAttribArray(EnumCastUnderlying(AttributeUsage::Tangent));
}

void System
	::GlDisableBinormalArray() noexcept
{
	glDisableVertexAttribArray(EnumCastUnderlying(AttributeUsage::Binormal));
}

void System
	::GlDisableTextureArray(int index) noexcept
{
	glClientActiveTexture(EnumCastUnderlying(TextureNumber::Type0) + index);
	glDisableClientState(EnumCastUnderlying(ClientState::TextureCoordArray));
}

void System
	::GlDisableColorArray() noexcept
{
	glDisableClientState(EnumCastUnderlying(ClientState::ColorArray));
}

void System
	::GlDisableSecondaryColorArray() noexcept
{
	glDisableClientState(EnumCastUnderlying(ClientState::SecondaryColorArray));
}

void System
	::GlDisableBlendIndicesArray() noexcept
{
	if (IsExistsGlArbMatrixPalette() == ExistsOpenGLExtensions::Exists)
	{
		glDisableClientState(EnumCastUnderlying(ClientState::MatrixIndexArray));
	}
}

void System
	::GlDisableBlendWeightArray() noexcept
{
	if (IsExistsGlArbVertexBlend() == ExistsOpenGLExtensions::Exists)
	{
		glDisableClientState(EnumCastUnderlying(ClientState::WeightArray));
	}
}

void System
	::GlDisableFogCoordArray() noexcept
{
	glDisableVertexAttribArray(EnumCastUnderlying(AttributeUsage::FogCoord));

	// OpenGL2之前的调用，这里没有能力指定信道的数目。
	// glDisableClientState(EnumCastUnderlying(ClientState::FogCoordinateArray));
}

void System
	::GlDisablePSizeArray() noexcept
{
	glDisableVertexAttribArray(EnumCastUnderlying(AttributeUsage::Psize));
}

System::OpenGLUInt System
	::GlBufferData(int numBytes, OpenGLUInt usage) noexcept
{
	OpenGLUInt buffer{ 0 };

	glGenBuffers(1, &buffer);
	glBindBuffer(EnumCastUnderlying(BindBuffer::ArrayBuffer), buffer);
	glBufferData(EnumCastUnderlying(BindBuffer::ArrayBuffer), numBytes, nullptr, usage);
	glBindBuffer(EnumCastUnderlying(BindBuffer::ArrayBuffer), 0);

	return buffer;
}

System::OpenGLUInt System
	::GlDeleteBuffers(OpenGLUInt buffer) noexcept
{
	glDeleteBuffers(1, &buffer);

	return buffer;
}

void  System
	::GlBindBuffer(OpenGLUInt buffer) noexcept
{
	glBindBuffer(EnumCastUnderlying(BindBuffer::ArrayBuffer), buffer);
}

System::OpenGLVoid* System
	::GetGlMapBuffer(OpenGLUInt buffer, OpenGLUInt usage) noexcept
{
	glBindBuffer(EnumCastUnderlying(BindBuffer::ArrayBuffer), buffer);

	auto videoMemory = glMapBuffer(EnumCastUnderlying(BindBuffer::ArrayBuffer), usage);

	glBindBuffer(EnumCastUnderlying(BindBuffer::ArrayBuffer), 0);

	return videoMemory;
}

void System
	::SetGlUnmapBuffer(OpenGLUInt buffer) noexcept
{
	glBindBuffer(EnumCastUnderlying(BindBuffer::ArrayBuffer), buffer);

	glUnmapBuffer(EnumCastUnderlying(BindBuffer::ArrayBuffer));

	glBindBuffer(EnumCastUnderlying(BindBuffer::ArrayBuffer), 0);
}

System::OpenGLUInt System
	::GlElementBufferData(int numBytes, OpenGLUInt usage) noexcept
{
	OpenGLUInt buffer{ 0 };

	glGenBuffers(1, &buffer);
	glBindBuffer(EnumCastUnderlying(BindBuffer::ElementArrayBuffer), buffer);
	glBufferData(EnumCastUnderlying(BindBuffer::ElementArrayBuffer), numBytes, nullptr, usage);
	glBindBuffer(EnumCastUnderlying(BindBuffer::ElementArrayBuffer), 0);

	return buffer;
}

System::OpenGLUInt System
	::GlDeleteElementBuffers(OpenGLUInt buffer) noexcept
{
	glDeleteBuffers(1, &buffer);

	return buffer;
}

void  System
	::GlBindElementBuffer(OpenGLUInt buffer) noexcept
{
	glBindBuffer(EnumCastUnderlying(BindBuffer::ElementArrayBuffer), buffer);
}

System::OpenGLVoid* System
	::GlMapElementBuffer(OpenGLUInt buffer, OpenGLUInt usage) noexcept
{
	glBindBuffer(EnumCastUnderlying(BindBuffer::ElementArrayBuffer), buffer);

	auto videoMemory = glMapBuffer(EnumCastUnderlying(BindBuffer::ElementArrayBuffer), usage);

	glBindBuffer(EnumCastUnderlying(BindBuffer::ElementArrayBuffer), 0);

	return videoMemory;
}

void System
	::GlUnmapElementBuffer(OpenGLUInt buffer) noexcept
{
	glBindBuffer(EnumCastUnderlying(BindBuffer::ElementArrayBuffer), buffer);

	glUnmapBuffer(EnumCastUnderlying(BindBuffer::ElementArrayBuffer));

	glBindBuffer(EnumCastUnderlying(BindBuffer::ElementArrayBuffer), 0);
}

System::OpenGLUInt System
	::GlPixelUnpackBufferData(int numBytes, OpenGLUInt usage) noexcept
{
	OpenGLUInt buffer{ 0 };

	glGenBuffers(1, &buffer);
	glBindBuffer(EnumCastUnderlying(BindBuffer::PixelUnpackBuffer), buffer);
	glBufferData(EnumCastUnderlying(BindBuffer::PixelUnpackBuffer), numBytes, nullptr, usage);
	glBindBuffer(EnumCastUnderlying(BindBuffer::PixelUnpackBuffer), 0);

	return buffer;
}

System::OpenGLUInt System
	::GlDeletePixelUnpackBuffers(OpenGLUInt buffer) noexcept
{
	glDeleteBuffers(1, &buffer);

	return buffer;
}

System::OpenGLVoid* System
	::GlMapPixelUnpackBuffer(OpenGLUInt buffer, OpenGLUInt usage) noexcept
{
	glBindBuffer(EnumCastUnderlying(BindBuffer::PixelUnpackBuffer), buffer);

	auto videoMemory = glMapBuffer(EnumCastUnderlying(BindBuffer::PixelUnpackBuffer), usage);

	glBindBuffer(EnumCastUnderlying(BindBuffer::PixelUnpackBuffer), 0);

	return videoMemory;
}

void System
	::GlBindPixelUnpackBuffer(OpenGLUInt buffer) noexcept
{
	glBindBuffer(EnumCastUnderlying(BindBuffer::PixelUnpackBuffer), buffer);
}

void System
	::GlUnmapPixelUnpackBuffer() noexcept
{
	glUnmapBuffer(EnumCastUnderlying(BindBuffer::PixelUnpackBuffer));
}

System::OpenGLUInt System
	::GlGenTextures() noexcept
{
	OpenGLUInt texture{ 0 };
	glGenTextures(1, &texture);

	return texture;
}

void System
	::GlTexImage1D(OpenGLUInt level, TextureInternalFormat internalformat, OpenGLSize width, TextureFormat format, OpenGLData type) noexcept
{
	glTexImage1D(EnumCastUnderlying(TextureTarget::Texture1D), level, EnumCastUnderlying(internalformat), width, 0, EnumCastUnderlying(format), EnumCastUnderlying(type), nullptr);
}

void System
	::GlTexSubImage1D(OpenGLUInt level, OpenGLSize width, TextureFormat format, OpenGLData type, const OpenGLVoid* pixels) noexcept
{
	glTexSubImage1D(EnumCastUnderlying(TextureTarget::Texture1D), level, 0, width, EnumCastUnderlying(format), EnumCastUnderlying(type), pixels);
}

void System
	::GlTexImage2D(OpenGLEnum target, OpenGLUInt level, TextureInternalFormat internalformat, OpenGLSize width, OpenGLSize height, TextureFormat format, OpenGLData type, const OpenGLVoid* pixels) noexcept
{
	glTexImage2D(target, level, EnumCastUnderlying(internalformat), width, height, 0, EnumCastUnderlying(format), EnumCastUnderlying(type), pixels);
}

void System
	::GlCompressedTexImage2D(OpenGLEnum target, OpenGLUInt level, TextureInternalFormat internalformat, OpenGLSize width, OpenGLSize height, OpenGLSize imageSize) noexcept
{
	glCompressedTexImage2D(target, level, EnumCastUnderlying(internalformat), width, height, 0, imageSize, nullptr);
}

void System
	::GetGlTexImage3D(OpenGLUInt level, TextureInternalFormat internalformat, OpenGLSize width, OpenGLSize height, OpenGLSize depth, TextureFormat format, OpenGLData type) noexcept
{
	glTexImage3D(EnumCastUnderlying(TextureTarget::Texture3D), level, EnumCastUnderlying(internalformat), width, height, depth, 0, EnumCastUnderlying(format), EnumCastUnderlying(type), nullptr);
}

void System
	::GlTexSubImage3D(OpenGLUInt level, OpenGLSize width, OpenGLSize height, OpenGLSize depth, TextureFormat format, OpenGLData type, const OpenGLVoid* pixels) noexcept
{
	glTexSubImage3D(EnumCastUnderlying(TextureTarget::Texture3D), level, 0, 0, 0, width, height, depth, EnumCastUnderlying(format), EnumCastUnderlying(type), pixels);
}

System::OpenGLUInt System
	::GlDeleteTextures(OpenGLUInt texture) noexcept
{
	glDeleteTextures(1, &texture);

	return texture;
}

void System
	::SetGlActiveTexture(OpenGLUInt texture) noexcept
{
	return glActiveTexture(texture);
}

void System
	::GlTexSubImage2D(OpenGLEnum target, OpenGLUInt level, OpenGLSize width, OpenGLSize height, TextureFormat format, OpenGLData type, const OpenGLVoid* pixels) noexcept
{
	glTexSubImage2D(target, level, 0, 0, width, height, EnumCastUnderlying(format), EnumCastUnderlying(type), pixels);
}

void System
	::GlCompressedTexSubImage2D(OpenGLEnum target, OpenGLUInt level, OpenGLSize width, OpenGLSize height, TextureInternalFormat internalformat, OpenGLSize imageSize, const OpenGLVoid* data) noexcept
{
	glCompressedTexSubImage2D(target, level, 0, 0, width, height, EnumCastUnderlying(internalformat), imageSize, data);
}

System::OpenGLUInt System
	::GlGenFramebuffers() noexcept
{
	OpenGLUInt frameBuffer{ 0 };
	glGenFramebuffersEXT(1, &frameBuffer);
	glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, frameBuffer);

	return frameBuffer;
}

System::OpenGLUInt System
	::GlDeleteFramebuffers(OpenGLUInt frameBuffer) noexcept
{
	glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, 0);
	glDeleteFramebuffersEXT(1, &frameBuffer);

	return frameBuffer;
}

void System
	::BindColorTexture(OpenGLUInt colorTextures, bool hasMipmaps) noexcept
{
	glBindTexture(EnumCastUnderlying(TextureTarget::Texture2D), colorTextures);
	if (hasMipmaps)
	{
		glTexParameteri(EnumCastUnderlying(TextureTarget::Texture2D), GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(EnumCastUnderlying(TextureTarget::Texture2D), GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	}
	else
	{
		glTexParameteri(EnumCastUnderlying(TextureTarget::Texture2D), GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(EnumCastUnderlying(TextureTarget::Texture2D), GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	}
}

void System
	::AttachTextureToFramebuffer(OpenGLUInt drawBuffers, OpenGLUInt colorTextures) noexcept
{
	glFramebufferTexture2DEXT(GL_FRAMEBUFFER_EXT, drawBuffers, EnumCastUnderlying(TextureTarget::Texture2D), colorTextures, 0);
}

System::CheckFrambufferStatus System
	::GlCheckFramebufferStatus() noexcept
{
	return UnderlyingCastEnum<CheckFrambufferStatus>(glCheckFramebufferStatusEXT(GL_FRAMEBUFFER_EXT));
}

void System
	::GlBindFramebuffer(OpenGLUInt frameBuffer) noexcept
{
	glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, frameBuffer);
}

void System
	::GetGlDrawBuffers(OpenGLSize n, const OpenGLEnum* bufs) noexcept
{
	glDrawBuffers(n, bufs);
}

void System
	::SetGlDepthRange(OpenGLDouble nearDepthRange, OpenGLDouble farDepthRange) noexcept
{
	glDepthRange(nearDepthRange, farDepthRange);
}

void System
	::SetGlGenerateMipmap(TextureTarget target, OpenGLUInt texture) noexcept
{
	glBindTexture(EnumCastUnderlying(target), texture);
	glGenerateMipmapEXT(EnumCastUnderlying(target));
}

void System
	::SetGlReadBuffer(OpenGLEnum mode) noexcept
{
	glReadBuffer(mode);
}

void System
	::GlReadPixels(OpenGLSize width, OpenGLSize height, TextureFormat format, OpenGLData type, OpenGLVoid* pixel) noexcept
{
	glReadPixels(0, 0, width, height, EnumCastUnderlying(format), EnumCastUnderlying(type), pixel);
}



