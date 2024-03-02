/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.6 (2024/03/01 16:58)

#ifndef SYSTEM_OPENGL_OPENGL_FLAGS_FWD_H
#define SYSTEM_OPENGL_OPENGL_FLAGS_FWD_H

#include "System/Helper/UserMacro.h"

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
    enum class TextureParameter;
    enum class TextureLevelParameter;
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
    enum class ColorAttachment;
    enum class CheckFrameBufferStatus;
    enum class FrameBufferType;
    enum class AttributeUsage;
    enum class OpenGLEnable;
    enum class OpenGLFrontFace;
    enum class OpenGLTextureName;
    enum class GLSLReflectionEnumType;

    // OpenGLProgram
    enum class ProgramStatus;
    enum class ProgramAttributes;
    enum class ProgramInterface;
    enum class ProgramInterfaceName;
    enum class ProgramProperties;

    // OpenGLShader
    enum class ShaderType;
    enum class ShaderStatus;
    enum class ShaderAttributes;

    // Wgl
    enum class PixelFormatDescriptorFlags : uint32_t;
    enum class PixelTypes;
}

#endif  // SYSTEM_OPENGL_OPENGL_FLAGS_FWD_H