///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.0 (2023/01/12 22:39)

#ifndef SYSTEM_OPENGL_OPENGL_FLAGS_H
#define SYSTEM_OPENGL_OPENGL_FLAGS_H

#include "System/Helper/EnumOperator.h"
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

        Viewport = GL_VIEWPORT,
        DepthRange = GL_DEPTH_RANGE,
    };

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

    enum class PixelStore
    {
        UnpackAlignment = GL_UNPACK_ALIGNMENT,
        PackAlignment = GL_PACK_ALIGNMENT,
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

    enum class ClientState
    {
        VertexArray = GL_VERTEX_ARRAY,
    };

    enum class OpenGLData
    {
        None = GL_ZERO,
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
        UnsignedInt24_8 = GL_UNSIGNED_INT_24_8,
        Int2_10_10_10Rev = GL_INT_2_10_10_10_REV,
        UnsignedInt2_10_10_10Rev = GL_UNSIGNED_INT_2_10_10_10_REV,
        UnsignedInt10F11F11FRev = GL_UNSIGNED_INT_10F_11F_11F_REV
    };

    enum class BindBuffer
    {
        ArrayBuffer = GL_ARRAY_BUFFER,
        ElementArrayBuffer = GL_ELEMENT_ARRAY_BUFFER,
        PixelUnpackBuffer = GL_PIXEL_UNPACK_BUFFER,
        PixePackBuffer = GL_PIXEL_PACK_BUFFER,
        ShaderStorageBuffer = GL_SHADER_STORAGE_BUFFER,
        UniformBuffer = GL_UNIFORM_BUFFER,
        CopyReadBuffer = GL_COPY_READ_BUFFER,
        CopyWriteBuffer = GL_COPY_WRITE_BUFFER,
        AtomicCounterBuffer = GL_ATOMIC_COUNTER_BUFFER,
        TransformFeedbackBuffer = GL_TRANSFORM_FEEDBACK_BUFFER,
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

    enum class BlendStateMode
    {
        Zero = GL_ZERO,
        One = GL_ONE,
        SourceColor = GL_SRC_COLOR,
        OneMinusSourceColor = GL_ONE_MINUS_SRC_COLOR,
        SourceAlpha = GL_SRC_ALPHA,
        OneMinusSourceAlpha = GL_ONE_MINUS_SRC_ALPHA,
        DestinationAlpha = GL_SRC_ALPHA,
        OneMinusDestinationAlpha = GL_ONE_MINUS_DST_ALPHA,
        DestinationColor = GL_DST_COLOR,
        OneMinusDestinationColor = GL_ONE_MINUS_DST_COLOR,
        SourceAlphaSaturate = GL_SRC_ALPHA_SATURATE,
        ConstantColor = GL_CONSTANT_COLOR,
        OneMinusConstantColor = GL_ONE_MINUS_CONSTANT_COLOR,
        Source1Color = GL_SRC1_COLOR,
        OneMinusSource1Color = GL_ONE_MINUS_SRC1_COLOR,
        Source1Alpha = GL_SRC1_ALPHA,
        OneMinusSource1Alpha = GL_ONE_MINUS_SRC1_ALPHA,
    };

    enum class BlendStateOperation
    {
        FuncAdd = GL_FUNC_ADD,
        FuncSubtract = GL_FUNC_SUBTRACT,
        FuncReverseSubtract = GL_FUNC_REVERSE_SUBTRACT,
        Min = GL_MIN,
        Max = GL_MAX
    };

    enum class DepthStencilStateMode
    {
        Never = GL_NEVER,
        Less = GL_LESS,
        Equal = GL_EQUAL,
        LessEqual = GL_LEQUAL,
        Greater = GL_GREATER,
        NotEqual = GL_NOTEQUAL,
        GreaterEqual = GL_GEQUAL,
        Always = GL_ALWAYS
    };

    enum class DepthStencilStateOperation
    {
        Keep = GL_KEEP,
        Zero = GL_ZERO,
        Replace = GL_REPLACE,
        Increment = GL_INCR,
        Decrement = GL_DECR,
        Invert = GL_INVERT
    };

    enum class DepthStencilStateWriteMask
    {
        False = GL_FALSE,
        True = GL_TRUE
    };

    enum class RasterizerStateFillMode
    {
        Fill = GL_FILL,
        Line = GL_LINE
    };

    enum class RasterizerStateCullFace
    {
        None = 0,
        Front = GL_FRONT,
        Back = GL_BACK,
        FrontAndBack = GL_FRONT_AND_BACK,
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
        Stream = GL_STREAM_DRAW,
    };

    enum class SamplerFilter
    {
        Nearest = GL_NEAREST,
        Linear = GL_LINEAR,
        NearestMipmapNearest = GL_NEAREST_MIPMAP_NEAREST,
        NearestMipmapLinear = GL_NEAREST_MIPMAP_LINEAR,
        LinearMipmapNearest = GL_LINEAR_MIPMAP_NEAREST,
        LinearMipmapLinear = GL_LINEAR_MIPMAP_LINEAR
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
        ClampEdge = GL_CLAMP_TO_EDGE,
        ClampBorder = GL_CLAMP_TO_BORDER,
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

        Stencil = GL_STENCIL_ATTACHMENT,
        DepthStencilAttachment = GL_DEPTH_STENCIL_ATTACHMENT,
        DepthAttachment = GL_DEPTH_ATTACHMENT,
        Back = GL_BACK,
    };

    enum class CheckFrambufferStatus
    {
        Null,
        Complete = GL_FRAMEBUFFER_COMPLETE,
        IncompleteAttachment = GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT,
        IncompleteMissingAttachment = GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT,
        IncompleteDrawBuffer = GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER,
        IncompleteReadBuffer = GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER,
        Unsupported = GL_FRAMEBUFFER_UNSUPPORTED,
    };

    enum class FrameBufferType
    {
        DrawFramebuffer = GL_DRAW_FRAMEBUFFER,
        Framebuffer = GL_FRAMEBUFFER,
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

    enum class OpenGLEnable
    {
        Blend = GL_BLEND,
        DepthTest = GL_DEPTH_TEST,
        StencilTest = GL_STENCIL_TEST,
        SampleCoverage = GL_SAMPLE_COVERAGE,
        CullFace = GL_CULL_FACE,
        PolygonOffsetFill = GL_POLYGON_OFFSET_FILL,
        PolygonOffsetLine = GL_POLYGON_OFFSET_LINE,
        PolygonOffsetPoint = GL_POLYGON_OFFSET_POINT,
    };

    enum class OpenGLFrontFace
    {
        CCW = GL_CCW,
        CW = GL_CW,
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

    enum class GLSLReflectionEnumType
    {
        None = 0,

        Float = GL_FLOAT,
        FloatVec2 = GL_FLOAT_VEC2,
        FloatVec3 = GL_FLOAT_VEC3,
        FloatVec4 = GL_FLOAT_VEC4,
        Double = GL_DOUBLE,
        DoubleVec2 = GL_DOUBLE_VEC2,
        DoubleVec3 = GL_DOUBLE_VEC3,
        DoubleVec4 = GL_DOUBLE_VEC4,
        Int = GL_INT,
        IntVec2 = GL_INT_VEC2,
        IntVec3 = GL_INT_VEC3,
        IntVec4 = GL_INT_VEC4,
        UnsignedInt = GL_UNSIGNED_INT,
        UnsignedIntVec2 = GL_UNSIGNED_INT_VEC2,
        UnsignedIntVec3 = GL_UNSIGNED_INT_VEC3,
        UnsignedIntVec4 = GL_UNSIGNED_INT_VEC4,
        Bool = GL_BOOL,
        BoolVec2 = GL_BOOL_VEC2,
        BoolVec3 = GL_BOOL_VEC3,
        BoolVec4 = GL_BOOL_VEC4,
        FloatMat2 = GL_FLOAT_MAT2,
        FloatMat3 = GL_FLOAT_MAT3,
        FloatMat4 = GL_FLOAT_MAT4,
        FloatMat2x3 = GL_FLOAT_MAT2x3,
        FloatMat2x4 = GL_FLOAT_MAT2x4,
        FloatMat3x2 = GL_FLOAT_MAT3x2,
        FloatMat3x4 = GL_FLOAT_MAT3x4,
        FloatMat4x2 = GL_FLOAT_MAT4x2,
        FloatMat4x3 = GL_FLOAT_MAT4x3,
        DoubleMat2 = GL_DOUBLE_MAT2,
        DoubleMat3 = GL_DOUBLE_MAT3,
        DoubleMat4 = GL_DOUBLE_MAT4,
        DoubleMat2x3 = GL_DOUBLE_MAT2x3,
        DoubleMat2x4 = GL_DOUBLE_MAT2x4,
        DoubleMat3x2 = GL_DOUBLE_MAT3x2,
        DoubleMat3x4 = GL_DOUBLE_MAT3x4,
        DoubleMat4x2 = GL_DOUBLE_MAT4x2,
        DoubleMat4x3 = GL_DOUBLE_MAT4x3,
        Sampler1D = GL_SAMPLER_1D,
        Sampler2D = GL_SAMPLER_2D,
        Sampler3D = GL_SAMPLER_3D,
        SamplerCube = GL_SAMPLER_CUBE,
        Sampler1DShadow = GL_SAMPLER_1D_SHADOW,
        Sampler2DShadow = GL_SAMPLER_2D_SHADOW,
        Sampler1DArray = GL_SAMPLER_1D_ARRAY,
        Sampler2DArray = GL_SAMPLER_2D_ARRAY,
        Sampler1DArrayShadow = GL_SAMPLER_1D_ARRAY_SHADOW,
        Sampler2DArrayShadow = GL_SAMPLER_2D_ARRAY_SHADOW,
        Sampler2DMultisample = GL_SAMPLER_2D_MULTISAMPLE,
        Sampler2DMultisampleArray = GL_SAMPLER_2D_MULTISAMPLE_ARRAY,
        SamplerCubeShadow = GL_SAMPLER_CUBE_SHADOW,
        SamplerCubeMapArray = GL_SAMPLER_CUBE_MAP_ARRAY,
        SamplerCubeMapArrayShadow = GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW,
        SamplerBuffer = GL_SAMPLER_BUFFER,
        Sampler2DRect = GL_SAMPLER_2D_RECT,
        Sampler2DRectShadow = GL_SAMPLER_2D_RECT_SHADOW,
        IntSampler1D = GL_INT_SAMPLER_1D,
        IntSampler2D = GL_INT_SAMPLER_2D,
        IntSampler3D = GL_INT_SAMPLER_3D,
        IntSamplerCube = GL_INT_SAMPLER_CUBE,
        IntSampler1DArray = GL_INT_SAMPLER_1D_ARRAY,
        IntSampler2DArray = GL_INT_SAMPLER_2D_ARRAY,
        IntSampler2DMultisample = GL_INT_SAMPLER_2D_MULTISAMPLE,
        IntSampler2DMultisampleArray = GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY,
        IntSamplerCubeMapArray = GL_INT_SAMPLER_CUBE_MAP_ARRAY,
        IntSamplerBuffer = GL_INT_SAMPLER_BUFFER,
        IntSampler2DRect = GL_INT_SAMPLER_2D_RECT,
        UnsignedIntSampler1D = GL_UNSIGNED_INT_SAMPLER_1D,
        UnsignedIntSampler2D = GL_UNSIGNED_INT_SAMPLER_2D,
        UnsignedIntSampler3D = GL_UNSIGNED_INT_SAMPLER_3D,
        UnsignedIntSamplerCube = GL_UNSIGNED_INT_SAMPLER_CUBE,
        UnsignedIntSampler1DArray = GL_UNSIGNED_INT_SAMPLER_1D_ARRAY,
        UnsignedIntSampler2DArray = GL_UNSIGNED_INT_SAMPLER_2D_ARRAY,
        UnsignedIntSampler2DMultisample = GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE,
        UnsignedIntSampler2DMultisampleArray = GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY,
        UnsignedIntSamplerCubeMapArray = GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY,
        UnsignedIntSamplerBuffer = GL_UNSIGNED_INT_SAMPLER_BUFFER,
        UnsignedIntSampler2DRect = GL_UNSIGNED_INT_SAMPLER_2D_RECT,
        Image1D = GL_IMAGE_1D,
        Image2D = GL_IMAGE_2D,
        Image3D = GL_IMAGE_3D,
        ImageCube = GL_IMAGE_CUBE,
        Image1DArray = GL_IMAGE_1D_ARRAY,
        Image2DArray = GL_IMAGE_2D_ARRAY,
        Image2DMultisample = GL_IMAGE_2D_MULTISAMPLE,
        Image2DMultisampleArray = GL_IMAGE_2D_MULTISAMPLE_ARRAY,
        ImageCubeMapArray = GL_IMAGE_CUBE_MAP_ARRAY,
        ImageBuffer = GL_IMAGE_BUFFER,
        Image2DRect = GL_IMAGE_2D_RECT,
        IntImage1D = GL_INT_IMAGE_1D,
        IntImage2D = GL_INT_IMAGE_2D,
        IntImage3D = GL_INT_IMAGE_3D,
        IntImageCube = GL_INT_IMAGE_CUBE,
        IntImage1DArray = GL_INT_IMAGE_1D_ARRAY,
        IntImage2DArray = GL_INT_IMAGE_2D_ARRAY,
        IntImage2DMultisample = GL_INT_IMAGE_2D_MULTISAMPLE,
        IntImage2DMultisampleArray = GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY,
        IntImageCubeMapArray = GL_INT_IMAGE_CUBE_MAP_ARRAY,
        IntImageBuffer = GL_INT_IMAGE_BUFFER,
        IntImage2DRect = GL_INT_IMAGE_2D_RECT,
        UnsignedIntImage1D = GL_UNSIGNED_INT_IMAGE_1D,
        UnsignedIntImage2D = GL_UNSIGNED_INT_IMAGE_2D,
        UnsignedIntImage3D = GL_UNSIGNED_INT_IMAGE_3D,
        UnsignedIntImageCube = GL_UNSIGNED_INT_IMAGE_CUBE,
        UnsignedIntImage1DArray = GL_UNSIGNED_INT_IMAGE_1D_ARRAY,
        UnsignedIntImage2DArray = GL_UNSIGNED_INT_IMAGE_2D_ARRAY,
        UnsignedIntImage2DMultisample = GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE,
        UnsignedIntImage2DMultisampleArray = GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY,
        UnsignedIntImageCubeMapArray = GL_UNSIGNED_INT_IMAGE_CUBE_MAP_ARRAY,
        UnsignedIntImageBuffer = GL_UNSIGNED_INT_IMAGE_BUFFER,
        UnsignedIntImage2DRect = GL_UNSIGNED_INT_IMAGE_2D_RECT,
        UnsignedIntAtomicCounter = GL_UNSIGNED_INT_ATOMIC_COUNTER,
    };

}

#endif  // SYSTEM_OPENGL_OPENGL_FLAGS_H
