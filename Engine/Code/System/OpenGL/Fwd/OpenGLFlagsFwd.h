/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.6 (2024/03/01 16:58)

#ifndef SYSTEM_OPENGL_OPENGL_FLAGS_FWD_H
#define SYSTEM_OPENGL_OPENGL_FLAGS_FWD_H

#include "System/Helper/UserMacro.h"

namespace System
{
    /// GLExtensions
    enum class ExistsOpenGLExtensions;
    enum class OpenGLErrorCode;
    enum class OpenGLSystemVersion;

    /// Glut
    enum class GlutMacro;
    enum class GlutExtension;
    enum class GlutOption;

    /// GlutKeyCodes
    enum class GlutKeyCodes;
    enum class GlutModifiersCodes;

    /// OpenGL
    enum class OpenGLClearMask;
    enum class OpenGLQuery;
    enum class PixelStore;
    enum class OpenGLData;
    enum class BindBuffer;
    enum class BlendStateMode;
    enum class BlendStateOperation;
    enum class DepthStencilStateMode;
    enum class DepthStencilStateOperation;
    enum class DepthStencilStateWriteMask;
    enum class RasterizerStateCullFace;
    enum class RasterizerStateFillMode;
    enum class BufferLocking;
    enum class BufferUsage;
    enum class SamplerFilter;
    enum class PrimitiveType;
    enum class ColorAttachment;
    enum class FrameBufferType;
    enum class OpenGLEnable;
    enum class OpenGLFrontFace;
    enum class GLSLReflectionEnumType;

    /// OpenGLProgram
    enum class ProgramStatus;
    enum class ProgramAttributes;
    enum class ProgramInterface;
    enum class ProgramInterfaceName;
    enum class ProgramProperties;

    /// OpenGLShader
    enum class ShaderType;
    enum class ShaderStatus;
    enum class ShaderAttributes;

    /// OpenGLTexture
    enum class TextureTarget;
    enum class TextureParameter;
    enum class TextureLevelParameter;
    enum class TextureInternalFormat;
    enum class TextureExternalFormat;
    enum class TextureTargetBinding;
    enum class TextureSamplerCoordinate;
    enum class TextureCubeMap;
    enum class TextureNumber;
    enum class OpenGLTextureName;

    /// Wgl
    enum class PixelFormatDescriptorFlags : uint32_t;
    enum class PixelTypes;
}

#endif  // SYSTEM_OPENGL_OPENGL_FLAGS_FWD_H