//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/25 11:46)

#ifndef SYSTEM_OPENGL_OPENGL_FLAGS_FWD_H
#define SYSTEM_OPENGL_OPENGL_FLAGS_FWD_H

namespace System
{
    // GLExtensions
    enum class ExistsOpenGLExtensions;
    enum class OpenGLErrorCode;
    enum class OpenGLSystemVersion;

    // Glut
    enum class GlutMacro;

    // GlutKeyCodes
    enum class GlutKeyCodes;
    enum class GlutModifiersCodes;

    // OpenGL
    enum class OpenGLClearMask;
    enum class OpenGLQuery;
    enum class TextureTarget;
    enum class ClientState;
    enum class OpenGLData;
    enum class BindBuffer;
    enum class TextureInternalFormat;
    enum class TextureFormat;
    enum class SrcBlendMode;
    enum class DstBlendMode;
    enum class CompareMode;
    enum class OpenGLOperation;
    enum class OpenGLAttribute;
    enum class BufferLocking;
    enum class BufferUsage;
    enum class SamplerFilter;
    enum class TextureTargetBinding;
    enum class TextureType;
    enum class TextureSamplerCoordinate;
    enum class PrimitiveType;
    enum class TextureCubeMap;
    enum class TextureNumber;
    enum class ColorAttachent;
    enum class CheckFrambufferStatus;
    enum class AttributeUsage;
	
	// Wgl
	enum class PixelFormatDescriptorFlags : uint32_t;
	enum class PixelTypes;
}

#endif  // SYSTEM_OPENGL_OPENGL_FLAGS_FWD_H