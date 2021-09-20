///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.1.6 (2021/06/28 20:40)

#ifndef SYSTEM_OPENGL_OPENGL_FLAGS_H
#define SYSTEM_OPENGL_OPENGL_FLAGS_H

#include "System/Helper/EnumMacro.h"
#include "System/Helper/GLExtensionsMacro.h"

namespace System
{
    enum class OpenGLClearMask
    {
        ColorBufferBit = GL_COLOR_BUFFER_BIT,
        DepthBufferBit = GL_DEPTH_BUFFER_BIT,
        StencilBufferBit = GL_STENCIL_BUFFER_BIT,
        None = 0,
    };

    enum class OpenGLQuery
    {
        NumExtensions = GL_NUM_EXTENSIONS,
        MajorVersion = GL_MAJOR_VERSION,
        MinorVersion = GL_MINOR_VERSION,

        VertexArray = GL_VERTEX_ARRAY,
    };

    enum class TextureTarget
    {
        Texture1D = GL_TEXTURE_1D,
        Texture2D = GL_TEXTURE_2D,
        Texture3D = GL_TEXTURE_3D,
        TextureCubeMap = GL_TEXTURE_CUBE_MAP,
    };

    enum class ClientState
    {
        VertexArray = GL_VERTEX_ARRAY,
    };

    enum class OpenGLData
    {
        None = 0,
        Short = GL_SHORT,
        Int = GL_INT,
        Float = GL_FLOAT,
        Double = GL_DOUBLE,
        Byte = GL_BYTE,
        UnsignedByte = GL_UNSIGNED_BYTE,
        UnsignedShort = GL_UNSIGNED_SHORT,
        UnsignedInt = GL_UNSIGNED_INT,
        UnsignedShort565Rev = GL_UNSIGNED_SHORT_5_6_5_REV,
        UnsignedShort1555Rev = GL_UNSIGNED_SHORT_1_5_5_5_REV,
        UnsignedShort4444Rev = GL_UNSIGNED_SHORT_4_4_4_4_REV,
        HalfFloat = GL_HALF_FLOAT,
        UnsignedInt24_8 = GL_UNSIGNED_INT_24_8
    };

    enum class BindBuffer
    {
        ArrayBuffer = GL_ARRAY_BUFFER,
        ElementArrayBuffer = GL_ELEMENT_ARRAY_BUFFER,
        PixelUnpackBuffer = GL_PIXEL_UNPACK_BUFFER,
    };

    enum class TextureInternalFormat
    {
        R5G6B5 = GL_RGB5,
        A1R5G5B5 = GL_RGB5_A1,
        A4R4G4B4 = GL_RGBA4,
        R8G8B8 = GL_RGB8,
        A8R8G8B8 = GL_RGBA8,
        G16R16 = GL_RG16,
        A16B16G16R16 = GL_RGBA16,
        R16F = GL_R16F,
        G16R16F = GL_RG16F,
        A16B16G16R16F = GL_RGBA16F,
        R32F = GL_R32F,
        G32R32F = GL_RG32F,
        A32B32G32R32F = GL_RGBA32F,
        D24S8 = GL_DEPTH24_STENCIL8,
    };

    enum class TextureFormat
    {
        BGR = GL_BGR,
        RGBA = GL_RGBA,
        A = GL_ALPHA,
        BGRA = GL_BGRA,
        RG = GL_RG,
        RED = GL_RED,
        D24S8 = GL_DEPTH_STENCIL
    };

    enum class SrcBlendMode
    {
        Zero = GL_ZERO,
        One = GL_ONE,
        DstColor = GL_DST_COLOR,
        OneMinusDstColor = GL_ONE_MINUS_DST_COLOR,
        SrcAlpha = GL_SRC_ALPHA,
        OneMinusSrcAlpha = GL_ONE_MINUS_SRC_ALPHA,
        DstAlpha = GL_DST_ALPHA,
        OneMinusDstAlpha = GL_ONE_MINUS_DST_ALPHA,
        SrcAlphaSaturate = GL_SRC_ALPHA_SATURATE,
        ConstantColor = GL_CONSTANT_COLOR,
        OneMinusConstantColor = GL_ONE_MINUS_CONSTANT_COLOR,
        ConstantAlpha = GL_CONSTANT_ALPHA,
        OneMinusConstantAlpha = GL_ONE_MINUS_CONSTANT_ALPHA
    };

    enum class DstBlendMode
    {
        Zero = GL_ZERO,
        One = GL_ONE,
        SrcColor = GL_SRC_COLOR,
        OneMinusSrcColor = GL_ONE_MINUS_SRC_COLOR,
        SrcAlpha = GL_SRC_ALPHA,
        OneMinusSrcAlpha = GL_ONE_MINUS_SRC_ALPHA,
        DstAlpha = GL_SRC_ALPHA,
        OneMinusDstAlpha = GL_ONE_MINUS_DST_ALPHA,
        ConstantColor = GL_CONSTANT_COLOR,
        OneMinusConstantColor = GL_ONE_MINUS_CONSTANT_COLOR,
        ConstantAlpha = GL_CONSTANT_ALPHA,
        OneMinusConstantAlpha = GL_ONE_MINUS_CONSTANT_ALPHA
    };

    enum class CompareMode
    {
        Never = GL_NEVER,
        Less = GL_LESS,
        Equal = GL_EQUAL,
        LEqual = GL_LEQUAL,
        Greater = GL_GREATER,
        NotEqual = GL_NOTEQUAL,
        GEqual = GL_GEQUAL,
        Always = GL_ALWAYS
    };

    enum class OpenGLOperation
    {
        Keep = GL_KEEP,
        Zero = GL_ZERO,
        Replace = GL_REPLACE,
        Increment = GL_INCR,
        Decrement = GL_DECR,
        Invert = GL_INVERT
    };

    enum class OpenGLAttribute
    {
        Float = GL_FLOAT,
        HalfFloat = GL_HALF_FLOAT,
        UByte = GL_UNSIGNED_BYTE,
        Short = GL_SHORT
    };

    enum class BufferLocking
    {
        ReadOnly = GL_READ_ONLY,
        WriteOnly = GL_WRITE_ONLY,
        ReadWrite = GL_READ_WRITE,
    };

    enum class BufferUsage
    {
        Static = GL_STATIC_DRAW,
        Dynamic = GL_DYNAMIC_DRAW,
    };

    enum class SamplerFilter
    {
        Nearest = GL_NEAREST,
        Linear = GL_LINEAR,
        NearestNearest = GL_NEAREST_MIPMAP_NEAREST,
        NearesLinear = GL_NEAREST_MIPMAP_LINEAR,
        LinearNeares = GL_LINEAR_MIPMAP_NEAREST,
        LinearLinear = GL_LINEAR_MIPMAP_LINEAR
    };

    enum class TextureTargetBinding
    {
        Binding1D = GL_TEXTURE_BINDING_1D,
        Binding2D = GL_TEXTURE_BINDING_2D,
        Binding3D = GL_TEXTURE_BINDING_3D,
        BindingCube = GL_TEXTURE_BINDING_CUBE_MAP,
    };

    enum class TextureType
    {
        UnsignedShort565Rev = GL_UNSIGNED_SHORT_5_6_5_REV,
        UnsignedShort1555Rev = GL_UNSIGNED_SHORT_1_5_5_5_REV,
        UnsignedShort4444Rev = GL_UNSIGNED_SHORT_4_4_4_4_REV,
        UnsignedByte = GL_UNSIGNED_BYTE,
        UnsignedShort = GL_UNSIGNED_SHORT,
        HalfFloat = GL_HALF_FLOAT,
        Float = GL_FLOAT,
        None = GL_NONE,
        UnsignedInt = GL_UNSIGNED_INT_24_8
    };

    enum class TextureSamplerCoordinate
    {
        Repeat = GL_REPEAT,
        MirroredRepeat = GL_MIRRORED_REPEAT,
        ClampBorder = GL_CLAMP_TO_BORDER,
        ClampEdge = GL_CLAMP_TO_EDGE,
    };

    enum class PrimitiveType
    {
        Point = GL_POINTS,
        Lines = GL_LINES,
        LinesStrip = GL_LINE_STRIP,
        Triangles = GL_TRIANGLES,
        TrianglesStrip = GL_TRIANGLE_STRIP,
        TrianglesFan = GL_TRIANGLE_FAN,
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

    enum class ColorAttachent
    {
        Color0 = GL_COLOR_ATTACHMENT0,
        Color1 = GL_COLOR_ATTACHMENT1,
        Color2 = GL_COLOR_ATTACHMENT2,
        Color3 = GL_COLOR_ATTACHMENT3,
        Color4 = GL_COLOR_ATTACHMENT4,
        Color5 = GL_COLOR_ATTACHMENT5,
        Color6 = GL_COLOR_ATTACHMENT6,
        Color7 = GL_COLOR_ATTACHMENT7,
        Color8 = GL_COLOR_ATTACHMENT8,
        Color9 = GL_COLOR_ATTACHMENT9,
        Color10 = GL_COLOR_ATTACHMENT10,
        Color11 = GL_COLOR_ATTACHMENT14,
        Color12 = GL_COLOR_ATTACHMENT15,
        Color13 = GL_COLOR_ATTACHMENT13,
        Color14 = GL_COLOR_ATTACHMENT14,
        Color15 = GL_COLOR_ATTACHMENT15,
        Depth = GL_DEPTH_ATTACHMENT,
        Stencil = GL_STENCIL_ATTACHMENT
    };

    enum class CheckFrambufferStatus
    {
        Complete = GL_FRAMEBUFFER_COMPLETE,
        IncompleteAttachment = GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT,
        IncompleteMissingAttachment = GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT,
        IncompleteDrawBuffer = GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER,
        IncompleteReadBuffer = GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER,
        Unsupported = GL_FRAMEBUFFER_UNSUPPORTED,
        Null,
    };

    enum class AttributeUsage
    {
        Position = 0,  // 属性 0
        BlendWeight = 1,  // 属性 1
        Normal = 2,  // 属性 2
        Color = 3,  // 属性 3 - 4
        FogCoord = 5,  // 属性 5
        Psize = 6,  // 属性 6
        BlendIndices = 7,  //  属性 7
        TextureCoord = 8,  //  属性 8 - 13
        Tangent = 14,  //  属性 14
        Binormal = 15,  //  属性 15

        Quantity
    };

    ENUM_ORABLE_OPERATOR_DEFINE(OpenGLClearMask);
}

#endif  // SYSTEM_OPENGL_OPENGL_FLAGS_H
