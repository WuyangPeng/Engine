/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/24 11:18)

#ifndef SYSTEM_OPENGL_OPENGL_TEXTURE_FLAGS_H
#define SYSTEM_OPENGL_OPENGL_TEXTURE_FLAGS_H

#include "System/Helper/GLExtensionsMacro.h"

namespace System
{
    enum class TextureTarget
    {
        Texture1D = GL_TEXTURE_1D,
        Texture2D = GL_TEXTURE_2D,
        Texture3D = GL_TEXTURE_3D,
        TextureCubeMap = GL_TEXTURE_CUBE_MAP,
        Texture1DArray = GL_TEXTURE_1D_ARRAY,
        Texture2DArray = GL_TEXTURE_2D_ARRAY,
        TextureCubeMapArray = GL_TEXTURE_CUBE_MAP_ARRAY,
    };

    enum class TextureParameter
    {
        TextureBaseLevel = GL_TEXTURE_BASE_LEVEL,
        TextureMaxLevel = GL_TEXTURE_MAX_LEVEL,
    };

    enum class TextureLevelParameter
    {
        Width = GL_TEXTURE_WIDTH,
        Height = GL_TEXTURE_HEIGHT,
        Depth = GL_TEXTURE_DEPTH,
    };

    enum class TextureInternalFormat
    {
        None = 0,

        RGBA32F = GL_RGBA32F,
        RGBA32UI = GL_RGBA32UI,
        RGBA32I = GL_RGBA32I,
        RGB32F = GL_RGB32F,
        RGB32UI = GL_RGB32UI,
        RGB32I = GL_RGB32I,
        RGBA16F = GL_RGBA16F,
        RGBA16 = GL_RGBA16,
        RGBA16UI = GL_RGBA16UI,
        RGBA16SNorm = GL_RGBA16_SNORM,
        RGBA16I = GL_RGBA16I,
        RG32F = GL_RG32F,
        RG32UI = GL_RG32UI,
        RG32I = GL_RG32I,
        R11F_G11F_B10F = GL_R11F_G11F_B10F,
        RGBA8 = GL_RGBA8,
        RGBA8UI = GL_RGBA8UI,
        RGBA8SNorm = GL_RGBA8_SNORM,
        RGBA8I = GL_RGBA8I,
        RG16F = GL_RG16F,
        RG16 = GL_RG16,
        RG16UI = GL_RG16UI,
        R16SNorm = GL_R16_SNORM,
        R16I = GL_R16I,
        R32F = GL_R32F,
        R32UI = GL_R32UI,
        R32I = GL_R32I,
        RG8 = GL_RG8,
        RG8UI = GL_RG8UI,
        RG8SNorm = GL_RG8_SNORM,
        RG8I = GL_RG8I,
        R16F = GL_R16F,
        R16 = GL_R16,
        R16UI = GL_R16UI,
        R8 = GL_R8,
        R8UI = GL_R8UI,
        R8SNorm = GL_R8_SNORM,
        R8I = GL_R8I,
        RGB9E5 = GL_RGB9_E5,
        RGB565 = GL_RGB565,
        RGB5A1 = GL_RGB5_A1,
        RGB10A2 = GL_RGB10_A2,

        DepthComponent32F = GL_DEPTH_COMPONENT32F,
        Depth24Stencil8 = GL_DEPTH24_STENCIL8,
        DepthComponent16 = GL_DEPTH_COMPONENT16,
    };

    enum class TextureExternalFormat
    {
        Unknown = 0,
        RGBA = GL_RGBA,
        RGBAInteger = GL_RGBA_INTEGER,
        RGB = GL_RGB,
        RGBInteger = GL_RGB_INTEGER,
        RG = GL_RG,
        RGInteger = GL_RG_INTEGER,
        Red = GL_RED,
        RedInteger = GL_RED_INTEGER,
        DepthComponent = GL_DEPTH_COMPONENT,
        BGR = GL_BGR,
        BGRA = GL_BGRA
    };

    enum class TextureTargetBinding
    {
        Binding1D = GL_TEXTURE_BINDING_1D,
        Binding2D = GL_TEXTURE_BINDING_2D,
        Binding3D = GL_TEXTURE_BINDING_3D,
        BindingCube = GL_TEXTURE_BINDING_CUBE_MAP,
        Binding1DArray = GL_TEXTURE_BINDING_1D_ARRAY,
        Binding2DArray = GL_TEXTURE_BINDING_2D_ARRAY,
        BindingCubeArray = GL_TEXTURE_BINDING_CUBE_MAP_ARRAY,
    };

    enum class TextureSamplerCoordinate
    {
        Repeat = GL_REPEAT,
        MirroredRepeat = GL_MIRRORED_REPEAT,
        ClampEdge = GL_CLAMP_TO_EDGE,
        ClampBorder = GL_CLAMP_TO_BORDER,
    };

    enum class TextureCubeMap
    {
        PositiveX = GL_TEXTURE_CUBE_MAP_POSITIVE_X,
        NegativeX = GL_TEXTURE_CUBE_MAP_NEGATIVE_X,
        PositiveY = GL_TEXTURE_CUBE_MAP_POSITIVE_Y,
        NegativeY = GL_TEXTURE_CUBE_MAP_NEGATIVE_Y,
        PositiveZ = GL_TEXTURE_CUBE_MAP_POSITIVE_Z,
        NegativeZ = GL_TEXTURE_CUBE_MAP_NEGATIVE_Z,
    };

    enum class TextureNumber
    {
        Type0 = GL_TEXTURE0,
        Type1 = GL_TEXTURE1,
        Type2 = GL_TEXTURE2,
        Type3 = GL_TEXTURE3,
        Type4 = GL_TEXTURE4,
        Type5 = GL_TEXTURE5,
        Type6 = GL_TEXTURE6,
        Type7 = GL_TEXTURE7,
        Type8 = GL_TEXTURE8,
        Type9 = GL_TEXTURE9,
        Type10 = GL_TEXTURE10,
        Type11 = GL_TEXTURE11,
        Type12 = GL_TEXTURE12,
        Type13 = GL_TEXTURE13,
        Type14 = GL_TEXTURE14,
        Type15 = GL_TEXTURE15,
        Type16 = GL_TEXTURE16,
        Type17 = GL_TEXTURE17,
        Type18 = GL_TEXTURE18,
        Type19 = GL_TEXTURE19,
        Type20 = GL_TEXTURE20,
        Type21 = GL_TEXTURE21,
        Type22 = GL_TEXTURE22,
        Type23 = GL_TEXTURE23,
        Type24 = GL_TEXTURE24,
        Type25 = GL_TEXTURE25,
        Type26 = GL_TEXTURE26,
        Type27 = GL_TEXTURE27,
        Type28 = GL_TEXTURE28,
        Type29 = GL_TEXTURE29,
        Type30 = GL_TEXTURE30,
        Type31 = GL_TEXTURE31,
    };

    enum class OpenGLTextureName
    {
        WrapS = GL_TEXTURE_WRAP_S,
        WrapT = GL_TEXTURE_WRAP_T,
        WrapR = GL_TEXTURE_WRAP_R,
        MinLod = GL_TEXTURE_MIN_LOD,
        MaxLod = GL_TEXTURE_MAX_LOD,
        LodBias = GL_TEXTURE_LOD_BIAS,
        MinFilter = GL_TEXTURE_MIN_FILTER,
        MagFilter = GL_TEXTURE_MAG_FILTER,
        BorderColor = GL_TEXTURE_BORDER_COLOR,
    };

}

#endif  // SYSTEM_OPENGL_OPENGL_TEXTURE_FLAGS_H
