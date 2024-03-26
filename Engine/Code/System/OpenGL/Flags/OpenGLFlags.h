/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/24 20:37)

#ifndef SYSTEM_OPENGL_OPENGL_FLAGS_H
#define SYSTEM_OPENGL_OPENGL_FLAGS_H

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

    enum class PixelStore
    {
        UnpackAlignment = GL_UNPACK_ALIGNMENT,
        PackAlignment = GL_PACK_ALIGNMENT,
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
        PixelPackBuffer = GL_PIXEL_PACK_BUFFER,
        ShaderStorageBuffer = GL_SHADER_STORAGE_BUFFER,
        UniformBuffer = GL_UNIFORM_BUFFER,
        CopyReadBuffer = GL_COPY_READ_BUFFER,
        CopyWriteBuffer = GL_COPY_WRITE_BUFFER,
        AtomicCounterBuffer = GL_ATOMIC_COUNTER_BUFFER,
        TransformFeedbackBuffer = GL_TRANSFORM_FEEDBACK_BUFFER,
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

    enum class PrimitiveType
    {
        Point = GL_POINTS,
        Lines = GL_LINES,
        LinesStrip = GL_LINE_STRIP,
        LinesAdjacency = GL_LINES_ADJACENCY,
        LinesStripAdjacency = GL_LINE_STRIP_ADJACENCY,
        Triangles = GL_TRIANGLES,
        TrianglesStrip = GL_TRIANGLE_STRIP,
        TrianglesFan = GL_TRIANGLE_FAN,
        TrianglesAdjacency = GL_TRIANGLES_ADJACENCY,
        TrianglesStripAdjacency = GL_TRIANGLE_STRIP_ADJACENCY,
    };

    enum class ColorAttachment
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

    enum class FrameBufferType
    {
        DrawFrameBuffer = GL_DRAW_FRAMEBUFFER,
        FrameBuffer = GL_FRAMEBUFFER,
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
        FloatMat2X3 = GL_FLOAT_MAT2x3,
        FloatMat2X4 = GL_FLOAT_MAT2x4,
        FloatMat3X2 = GL_FLOAT_MAT3x2,
        FloatMat3X4 = GL_FLOAT_MAT3x4,
        FloatMat4X2 = GL_FLOAT_MAT4x2,
        FloatMat4X3 = GL_FLOAT_MAT4x3,
        DoubleMat2 = GL_DOUBLE_MAT2,
        DoubleMat3 = GL_DOUBLE_MAT3,
        DoubleMat4 = GL_DOUBLE_MAT4,
        DoubleMat2X3 = GL_DOUBLE_MAT2x3,
        DoubleMat2X4 = GL_DOUBLE_MAT2x4,
        DoubleMat3X2 = GL_DOUBLE_MAT3x2,
        DoubleMat3X4 = GL_DOUBLE_MAT3x4,
        DoubleMat4X2 = GL_DOUBLE_MAT4x2,
        DoubleMat4X3 = GL_DOUBLE_MAT4x3,
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
        Sampler2DMultiSample = GL_SAMPLER_2D_MULTISAMPLE,
        Sampler2DMultiSampleArray = GL_SAMPLER_2D_MULTISAMPLE_ARRAY,
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
        IntSampler2DMultiSample = GL_INT_SAMPLER_2D_MULTISAMPLE,
        IntSampler2DMultiSampleArray = GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY,
        IntSamplerCubeMapArray = GL_INT_SAMPLER_CUBE_MAP_ARRAY,
        IntSamplerBuffer = GL_INT_SAMPLER_BUFFER,
        IntSampler2DRect = GL_INT_SAMPLER_2D_RECT,
        UnsignedIntSampler1D = GL_UNSIGNED_INT_SAMPLER_1D,
        UnsignedIntSampler2D = GL_UNSIGNED_INT_SAMPLER_2D,
        UnsignedIntSampler3D = GL_UNSIGNED_INT_SAMPLER_3D,
        UnsignedIntSamplerCube = GL_UNSIGNED_INT_SAMPLER_CUBE,
        UnsignedIntSampler1DArray = GL_UNSIGNED_INT_SAMPLER_1D_ARRAY,
        UnsignedIntSampler2DArray = GL_UNSIGNED_INT_SAMPLER_2D_ARRAY,
        UnsignedIntSampler2DMultiSample = GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE,
        UnsignedIntSampler2DMultiSampleArray = GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY,
        UnsignedIntSamplerCubeMapArray = GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY,
        UnsignedIntSamplerBuffer = GL_UNSIGNED_INT_SAMPLER_BUFFER,
        UnsignedIntSampler2DRect = GL_UNSIGNED_INT_SAMPLER_2D_RECT,
        Image1D = GL_IMAGE_1D,
        Image2D = GL_IMAGE_2D,
        Image3D = GL_IMAGE_3D,
        ImageCube = GL_IMAGE_CUBE,
        Image1DArray = GL_IMAGE_1D_ARRAY,
        Image2DArray = GL_IMAGE_2D_ARRAY,
        Image2DMultiSample = GL_IMAGE_2D_MULTISAMPLE,
        Image2DMultiSampleArray = GL_IMAGE_2D_MULTISAMPLE_ARRAY,
        ImageCubeMapArray = GL_IMAGE_CUBE_MAP_ARRAY,
        ImageBuffer = GL_IMAGE_BUFFER,
        Image2DRect = GL_IMAGE_2D_RECT,
        IntImage1D = GL_INT_IMAGE_1D,
        IntImage2D = GL_INT_IMAGE_2D,
        IntImage3D = GL_INT_IMAGE_3D,
        IntImageCube = GL_INT_IMAGE_CUBE,
        IntImage1DArray = GL_INT_IMAGE_1D_ARRAY,
        IntImage2DArray = GL_INT_IMAGE_2D_ARRAY,
        IntImage2DMultiSample = GL_INT_IMAGE_2D_MULTISAMPLE,
        IntImage2DMultiSampleArray = GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY,
        IntImageCubeMapArray = GL_INT_IMAGE_CUBE_MAP_ARRAY,
        IntImageBuffer = GL_INT_IMAGE_BUFFER,
        IntImage2DRect = GL_INT_IMAGE_2D_RECT,
        UnsignedIntImage1D = GL_UNSIGNED_INT_IMAGE_1D,
        UnsignedIntImage2D = GL_UNSIGNED_INT_IMAGE_2D,
        UnsignedIntImage3D = GL_UNSIGNED_INT_IMAGE_3D,
        UnsignedIntImageCube = GL_UNSIGNED_INT_IMAGE_CUBE,
        UnsignedIntImage1DArray = GL_UNSIGNED_INT_IMAGE_1D_ARRAY,
        UnsignedIntImage2DArray = GL_UNSIGNED_INT_IMAGE_2D_ARRAY,
        UnsignedIntImage2DMultiSample = GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE,
        UnsignedIntImage2DMultiSampleArray = GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY,
        UnsignedIntImageCubeMapArray = GL_UNSIGNED_INT_IMAGE_CUBE_MAP_ARRAY,
        UnsignedIntImageBuffer = GL_UNSIGNED_INT_IMAGE_BUFFER,
        UnsignedIntImage2DRect = GL_UNSIGNED_INT_IMAGE_2D_RECT,
        UnsignedIntAtomicCounter = GL_UNSIGNED_INT_ATOMIC_COUNTER,
    };
}

#endif  // SYSTEM_OPENGL_OPENGL_FLAGS_H
