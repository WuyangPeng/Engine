///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/13 11:31)

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
    enum class GlutExtension;
    enum class GlutOption;

    // GlutKeyCodes
    enum class GlutKeyCodes;
    enum class GlutModifiersCodes;

    // OpenGL
    enum class OpenGLClearMask;
    enum class OpenGLQuery;
    enum class TextureTarget;
    enum class TexParameter;
    enum class PixelStore;
    enum class ClientState;
    enum class OpenGLData;
    enum class BindBuffer;
    enum class TextureInternalFormat;
    enum class TextureExternalFormat;
    enum class TextureFormat;
    enum class BlendStateMode;
    enum class BlendStateOperation;
    enum class DepthStencilStateMode;
    enum class DepthStencilStateOperation;
    enum class DepthStencilStateWriteMask;
    enum class RasterizerStateCullFace;
    enum class RasterizerStateFillMode;
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
    enum class FrameBufferType;
    enum class AttributeUsage;
    enum class OpenGLEnable;
    enum class OpenGLFrontFace;
    enum class OpenGLTextureName;

    // Wgl
    enum class PixelFormatDescriptorFlags : uint32_t;
    enum class PixelTypes;
}

#endif  // SYSTEM_OPENGL_OPENGL_FLAGS_FWD_H