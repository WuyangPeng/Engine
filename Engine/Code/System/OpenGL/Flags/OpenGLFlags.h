//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/25 13:12)

#ifndef SYSTEM_OPENGL_OPENGL_FLAGS_H
#define SYSTEM_OPENGL_OPENGL_FLAGS_H

#include "System/Helper/EnumMacro.h"

#include "System/Helper/Detail/OpenGL/GL11ExtensionsMacro.h"
#include "System/Helper/Detail/OpenGL/GL12ExtensionsMacro.h"
#include "System/Helper/Detail/OpenGL/GL13ExtensionsMacro.h"
#include "System/Helper/Detail/OpenGL/GL14ExtensionsMacro.h"
#include "System/Helper/Detail/OpenGL/GL15ExtensionsMacro.h"
#include "System/Helper/Detail/OpenGL/GL20ExtensionsMacro.h"
#include "System/Helper/Detail/OpenGL/GL21ExtensionsMacro.h"
#include "System/Helper/Detail/OpenGL/GL30ExtensionsMacro.h"
#include "System/Helper/Detail/OpenGL/GL32ExtensionsMacro.h"
#include "System/Helper/Detail/OpenGL/GLARBExtensionsMacro.h"
#include "System/Helper/Detail/OpenGL/GLARBImagingExtensionsMacro.h"
#include "System/Helper/Detail/OpenGL/GLEXTExtensionsMacro.h"
#include "System/Helper/GLExtensionsMacro.h"

namespace System
{
    enum class OpenGLClearMask
    {
        ColorBufferBit = GL_COLOR_BUFFER_BIT,
        DepthBufferBit = GL_DEPTH_BUFFER_BIT,
        StencilBufferBit = GL_STENCIL_BUFFER_BIT,
        AccumBufferBit = GL_ACCUM_BUFFER_BIT,
        None = 0,
    };

    enum class OpenGLQuery
    {
        AccumAlphaBits = GL_ACCUM_ALPHA_BITS,
        AccumBlueBits = GL_ACCUM_BLUE_BITS,
        AccumClearBits = GL_ACCUM_CLEAR_VALUE,
        AccumGreenBits = GL_ACCUM_GREEN_BITS,
        AccumRedBits = GL_ACCUM_RED_BITS,
        AlphaBias = GL_ALPHA_BIAS,
        AlphaBits = GL_ALPHA_BITS,
        AlphaScale = GL_ALPHA_SCALE,
        AlphaTest = GL_ALPHA_TEST,
        AlphaTestFunc = GL_ALPHA_TEST_FUNC,
        AlphaTestRef = GL_ALPHA_TEST_REF,
        AttribStackDepth = GL_ATTRIB_STACK_DEPTH,
        AutoNormal = GL_AUTO_NORMAL,
        AuxBuffers = GL_AUX_BUFFERS,
        Blend = GL_BLEND,
        BlendDst = GL_BLEND_DST,
        BlendSrc = GL_BLEND_SRC,
        BlueBias = GL_BLUE_BIAS,
        BlueBits = GL_BLUE_BITS,
        BlueScale = GL_BLUE_SCALE,
        ClientAttribStackDepth = GL_CLIENT_ATTRIB_STACK_DEPTH,
        ClipPlane0 = GL_CLIP_PLANE0,
        ClipPlane1 = GL_CLIP_PLANE1,
        ClipPlane2 = GL_CLIP_PLANE2,
        ClipPlane3 = GL_CLIP_PLANE3,
        ClipPlane4 = GL_CLIP_PLANE4,
        ClipPlane5 = GL_CLIP_PLANE5,
        ColorArray = GL_COLOR_ARRAY,
        ColorArraySize = GL_COLOR_ARRAY_SIZE,
        ColorArrayStride = GL_COLOR_ARRAY_STRIDE,
        ColorArrayType = GL_COLOR_ARRAY_TYPE,
        ColorClearValue = GL_COLOR_CLEAR_VALUE,
        ColorLogicOp = GL_COLOR_LOGIC_OP,
        ColorMateral = GL_COLOR_MATERIAL,
        ColorMateralFace = GL_COLOR_MATERIAL_FACE,
        ColorMateralParameter = GL_COLOR_MATERIAL_PARAMETER,
        ColorWriteMask = GL_COLOR_WRITEMASK,
        CullFace = GL_CULL_FACE,
        CullFaceMode = GL_CULL_FACE_MODE,
        CurrentColor = GL_CURRENT_COLOR,
        CurrentIndex = GL_CURRENT_INDEX,
        CurrentNormal = GL_CURRENT_NORMAL,
        CurrentRasterColor = GL_CURRENT_RASTER_COLOR,
        CurrentRasterDistance = GL_CURRENT_RASTER_DISTANCE,
        CurrentRasterIndex = GL_CURRENT_RASTER_INDEX,
        CurrentRasterPosition = GL_CURRENT_RASTER_POSITION,
        CurrentRasterPositionValid = GL_CURRENT_RASTER_POSITION_VALID,
        CurrentRasterTextureCoords = GL_CURRENT_RASTER_TEXTURE_COORDS,
        CurrentTextureCoords = GL_CURRENT_TEXTURE_COORDS,
        DepthBias = GL_DEPTH_BIAS,
        DepthBits = GL_DEPTH_BITS,
        DepthClearValue = GL_DEPTH_CLEAR_VALUE,
        DepthFunc = GL_DEPTH_FUNC,
        DepthRange = GL_DEPTH_RANGE,
        DepthScale = GL_DEPTH_SCALE,
        DepthTest = GL_DEPTH_TEST,
        DepthWritemask = GL_DEPTH_WRITEMASK,
        Dither = GL_DITHER,
        Doublebuffer = GL_DOUBLEBUFFER,
        Drawbuffer = GL_DRAW_BUFFER,
        EdgeFlag = GL_EDGE_FLAG,
        EdgeFlagArray = GL_EDGE_FLAG_ARRAY,
        EdgeFlagArrayStride = GL_EDGE_FLAG_ARRAY_STRIDE,
        Fog = GL_FOG,
        FogColor = GL_FOG_COLOR,
        FogDensity = GL_FOG_DENSITY,
        FogEnd = GL_FOG_END,
        FogHint = GL_FOG_HINT,
        FogIndex = GL_FOG_INDEX,
        FogMode = GL_FOG_MODE,
        FogStart = GL_FOG_START,
        FrontFace = GL_FRONT_FACE,
        GreenBias = GL_GREEN_BIAS,
        GreenBits = GL_GREEN_BITS,
        GreenScale = GL_GREEN_SCALE,
        IndexArray = GL_INDEX_ARRAY,
        IndexArrayStride = GL_INDEX_ARRAY_STRIDE,
        IndexArrayType = GL_INDEX_ARRAY_TYPE,
        IndexBits = GL_INDEX_BITS,
        IndexClearValue = GL_INDEX_CLEAR_VALUE,
        IndexLogicOp = GL_INDEX_LOGIC_OP,
        IndexMode = GL_INDEX_MODE,
        IndexOffset = GL_INDEX_OFFSET,
        IndexShift = GL_INDEX_SHIFT,
        IndexWritemask = GL_INDEX_WRITEMASK,
        Light0 = GL_LIGHT0,
        Light1 = GL_LIGHT1,
        Light2 = GL_LIGHT2,
        Light3 = GL_LIGHT3,
        Light4 = GL_LIGHT4,
        Light5 = GL_LIGHT5,
        Light6 = GL_LIGHT6,
        Light7 = GL_LIGHT7,
        Lighting = GL_LIGHTING,
        LightModelAmbient = GL_LIGHT_MODEL_AMBIENT,
        LightModelLocalViewer = GL_LIGHT_MODEL_LOCAL_VIEWER,
        LightModelTwoSide = GL_LIGHT_MODEL_TWO_SIDE,
        LineSmooth = GL_LINE_SMOOTH,
        LineSmoothHint = GL_LINE_SMOOTH_HINT,
        LineStipple = GL_LINE_STIPPLE,
        LineStipplePattern = GL_LINE_STIPPLE_PATTERN,
        LineStippleRepeat = GL_LINE_STIPPLE_REPEAT,
        LineWidth = GL_LINE_WIDTH,
        LineWidthGranularity = GL_LINE_WIDTH_GRANULARITY,
        LineWidthRange = GL_LINE_WIDTH_RANGE,
        ListBase = GL_LIST_BASE,
        ListIndex = GL_LIST_INDEX,
        ListMode = GL_LIST_MODE,
        LogicOp = GL_LOGIC_OP,
        LogicOpMode = GL_LOGIC_OP_MODE,
        Map1Color4 = GL_MAP1_COLOR_4,
        Map1GridDomain = GL_MAP1_GRID_DOMAIN,
        Map1GridSegments = GL_MAP1_GRID_SEGMENTS,
        Map1Index = GL_MAP1_INDEX,
        Map1Normal = GL_MAP1_NORMAL,
        Map1TextureCoord1 = GL_MAP1_TEXTURE_COORD_1,
        Map1TextureCoord2 = GL_MAP1_TEXTURE_COORD_2,
        Map1TextureCoord3 = GL_MAP1_TEXTURE_COORD_3,
        Map1TextureCoord4 = GL_MAP1_TEXTURE_COORD_4,
        Map1Vertex3 = GL_MAP1_VERTEX_3,
        Map1Vertex4 = GL_MAP1_VERTEX_4,
        Map2Color4 = GL_MAP2_COLOR_4,
        Map2GridDomain = GL_MAP2_GRID_DOMAIN,
        Map2GridSegments = GL_MAP2_GRID_SEGMENTS,
        Map2Index = GL_MAP2_INDEX,
        Map2Normal = GL_MAP2_NORMAL,
        Map2TextureCoord1 = GL_MAP2_TEXTURE_COORD_1,
        Map2TextureCoord2 = GL_MAP2_TEXTURE_COORD_2,
        Map2TextureCoord3 = GL_MAP2_TEXTURE_COORD_3,
        Map2TextureCoord4 = GL_MAP2_TEXTURE_COORD_4,
        Map2Vertex3 = GL_MAP2_VERTEX_3,
        Map2Vertex4 = GL_MAP2_VERTEX_4,
        MapColor = GL_MAP_COLOR,
        MapStencil = GL_MAP_STENCIL,
        MatrixMode = GL_MATRIX_MODE,
        MaxClientAttribStackDepth = GL_MAX_CLIENT_ATTRIB_STACK_DEPTH,
        MaxAttribStackDepth = GL_MAX_ATTRIB_STACK_DEPTH,
        MaxClipPlanes = GL_MAX_CLIP_PLANES,
        MaxEvalOrder = GL_MAX_EVAL_ORDER,
        MaxLights = GL_MAX_LIGHTS,
        MaxListNesting = GL_MAX_LIST_NESTING,
        MaxModelviewStackDepth = GL_MAX_MODELVIEW_STACK_DEPTH,
        MaxNameStackDepth = GL_MAX_NAME_STACK_DEPTH,
        MaxPixelMapTable = GL_MAX_PIXEL_MAP_TABLE,
        MaxProjectionStackDepth = GL_MAX_PROJECTION_STACK_DEPTH,
        MaxTextureSize = GL_MAX_TEXTURE_SIZE,
        MaxTextureStackDepth = GL_MAX_TEXTURE_STACK_DEPTH,
        MaxViewportDims = GL_MAX_VIEWPORT_DIMS,
        ModelviewMatrix = GL_MODELVIEW_MATRIX,
        ModelviewStackDepth = GL_MODELVIEW_STACK_DEPTH,
        NameStackDepth = GL_NAME_STACK_DEPTH,
        NormalArray = GL_NORMAL_ARRAY,
        NormalArrayStride = GL_NORMAL_ARRAY_STRIDE,
        NormalArrayType = GL_NORMAL_ARRAY_TYPE,
        Normalize = GL_NORMALIZE,
        PackAlignment = GL_PACK_ALIGNMENT,
        PackLsbFirst = GL_PACK_LSB_FIRST,
        PackRowLength = GL_PACK_ROW_LENGTH,
        PackSkipPixels = GL_PACK_SKIP_PIXELS,
        PackSkipRows = GL_PACK_SKIP_ROWS,
        PackSwapBytes = GL_PACK_SWAP_BYTES,
        PerspectiveCorrectionHint = GL_PERSPECTIVE_CORRECTION_HINT,
        PixelMapAToASize = GL_PIXEL_MAP_A_TO_A_SIZE,
        PixelMapBToBSize = GL_PIXEL_MAP_B_TO_B_SIZE,
        PixelMapGToGSize = GL_PIXEL_MAP_G_TO_G_SIZE,
        PixelMapIToASize = GL_PIXEL_MAP_I_TO_A_SIZE,
        PixelMapIToBSize = GL_PIXEL_MAP_I_TO_B_SIZE,
        PixelMapIToGSize = GL_PIXEL_MAP_I_TO_G_SIZE,
        PixelMapIToISize = GL_PIXEL_MAP_I_TO_I_SIZE,
        PixelMapIToRSize = GL_PIXEL_MAP_I_TO_R_SIZE,
        PixelMapRToRSize = GL_PIXEL_MAP_R_TO_R_SIZE,
        PixelMapSToSSize = GL_PIXEL_MAP_S_TO_S_SIZE,
        PointSize = GL_POINT_SIZE,
        PointSizeGranularity = GL_POINT_SIZE_GRANULARITY,
        PointSizeRange = GL_POINT_SIZE_RANGE,
        PointSmooth = GL_POINT_SMOOTH,
        PointSmoothHint = GL_POINT_SMOOTH_HINT,
        PolygonMode = GL_POLYGON_MODE,
        PolygonOffsetFactor = GL_POLYGON_OFFSET_FACTOR,
        PolygonOffsetUnits = GL_POLYGON_OFFSET_UNITS,
        PolygonOffsetFill = GL_POLYGON_OFFSET_FILL,
        PolygonOffsetLine = GL_POLYGON_OFFSET_LINE,
        PolygonOffsetPoint = GL_POLYGON_OFFSET_POINT,
        PolygonSmooth = GL_POLYGON_SMOOTH,
        PolygonSmoothHit = GL_POLYGON_SMOOTH_HINT,
        PolygonStipple = GL_POLYGON_STIPPLE,
        ProjectionMatrix = GL_PROJECTION_MATRIX,
        ProjectionStacjDepth = GL_PROJECTION_STACK_DEPTH,
        ReadBuffer = GL_READ_BUFFER,
        ReadBias = GL_RED_BIAS,
        ReadBits = GL_RED_BITS,
        ReadScale = GL_RED_SCALE,
        RenderMode = GL_RENDER_MODE,
        RGBAMode = GL_RGBA_MODE,
        ScissorBox = GL_SCISSOR_BOX,
        ScissorTest = GL_SCISSOR_TEST,
        ShadeModel = GL_SHADE_MODEL,
        StencilBits = GL_STENCIL_BITS,
        StencilClearValue = GL_STENCIL_CLEAR_VALUE,
        StencilFail = GL_STENCIL_FAIL,
        StencilFunc = GL_STENCIL_FUNC,
        StencilPassDepthFail = GL_STENCIL_PASS_DEPTH_FAIL,
        StencilPassDepthPass = GL_STENCIL_PASS_DEPTH_PASS,
        StencilRef = GL_STENCIL_REF,
        StencilTest = GL_STENCIL_TEST,
        StencilValueMask = GL_STENCIL_VALUE_MASK,
        StencilWritemask = GL_STENCIL_WRITEMASK,
        Stereo = GL_STEREO,
        SubpixelBits = GL_SUBPIXEL_BITS,
        Texture1D = GL_TEXTURE_1D,
        Texture2D = GL_TEXTURE_2D,
        TextureCoordArray = GL_TEXTURE_COORD_ARRAY,
        TextureCoordArraySize = GL_TEXTURE_COORD_ARRAY_SIZE,
        TextureCoordArrayStride = GL_TEXTURE_COORD_ARRAY_STRIDE,
        TextureCoordArrayType = GL_TEXTURE_COORD_ARRAY_TYPE,
        TextureEnvColor = GL_TEXTURE_ENV_COLOR,
        TextureEnvMode = GL_TEXTURE_ENV_MODE,
        TextureGenQ = GL_TEXTURE_GEN_Q,
        TextureGenR = GL_TEXTURE_GEN_R,
        TextureGenS = GL_TEXTURE_GEN_S,
        TextureGenT = GL_TEXTURE_GEN_T,
        TextureMatrix = GL_TEXTURE_MATRIX,
        TextureStackDepth = GL_TEXTURE_STACK_DEPTH,
        UnpackAlignment = GL_UNPACK_ALIGNMENT,
        UnpackLsbFirst = GL_UNPACK_LSB_FIRST,
        UnpackRowLength = GL_UNPACK_ROW_LENGTH,
        UnpackSkipPixels = GL_UNPACK_SKIP_PIXELS,
        UnpackSkipRows = GL_UNPACK_SKIP_ROWS,
        UnpackSwapBytes = GL_UNPACK_SWAP_BYTES,
        VetexArray = GL_VERTEX_ARRAY,
        VetexArraySize = GL_VERTEX_ARRAY_SIZE,
        VetexArrayStride = GL_VERTEX_ARRAY_STRIDE,
        VetexArrayType = GL_VERTEX_ARRAY_TYPE,
        Viewport = GL_VIEWPORT,
        ZoomX = GL_ZOOM_X,
        ZoomY = GL_ZOOM_Y,

        TextureBinding1D = GL_TEXTURE_BINDING_1D,
        TextureBinding2D = GL_TEXTURE_BINDING_2D,
        TextureBinding3D = GL_TEXTURE_BINDING_3D,
        TextureBindingCubeMap = GL_TEXTURE_BINDING_CUBE_MAP,
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
        ColorArray = GL_COLOR_ARRAY,
        EdgeFlagArray = GL_EDGE_FLAG_ARRAY,
        IndexArray = GL_INDEX_ARRAY,
        NormalArray = GL_NORMAL_ARRAY,
        TextureCoordArray = GL_TEXTURE_COORD_ARRAY,
        VertexArray = GL_VERTEX_ARRAY,
        SecondaryColorArray = GL_SECONDARY_COLOR_ARRAY,  // OpenGL 1.4
        MatrixIndexArray = GL_MATRIX_INDEX_ARRAY_ARB,  // ARB 16
        WeightArray = GL_WEIGHT_ARRAY_ARB,  // ARB 15
        FogCoordinateArray = GL_FOG_COORDINATE_ARRAY_EXT,  // EXT 149
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
        BitMap = GL_BITMAP,
        UnsignedShort565Rev = GL_UNSIGNED_SHORT_5_6_5_REV,
        UnsignedShort1555Rev = GL_UNSIGNED_SHORT_1_5_5_5_REV,
        UnsignedShort4444Rev = GL_UNSIGNED_SHORT_4_4_4_4_REV,
        HalfFloat = GL_HALF_FLOAT_ARB,
        UnsignedInt24_8 = GL_UNSIGNED_INT_24_8_EXT
    };

    enum class BindBuffer
    {
        ArrayBuffer = GL_ARRAY_BUFFER,
        ElementArrayBuffer = GL_ELEMENT_ARRAY_BUFFER,
        PixelUnpackBuffer = GL_PIXEL_UNPACK_BUFFER,  // OpenGL 2.1
    };

    enum class TextureInternalFormat
    {
        R5G6B5 = GL_RGB5,
        A1R5G5B5 = GL_RGB5_A1,
        A4R4G4B4 = GL_RGBA4,
        A8 = GL_ALPHA8,
        L8 = GL_LUMINANCE8,
        A8L8 = GL_LUMINANCE8_ALPHA8,
        R8G8B8 = GL_RGB8,
        A8R8G8B8 = GL_RGBA8,
        L16 = GL_LUMINANCE16,
        G16R16 = GL_RG16,
        A16B16G16R16 = GL_RGBA16,
        R16F = GL_R16F,
        G16R16F = GL_RG16F,
        A16B16G16R16F = GL_RGBA16F,
        R32F = GL_R32F,
        G32R32F = GL_RG32F,
        A32B32G32R32F = GL_RGBA32F,
        DXT1 = GL_COMPRESSED_RGBA_S3TC_DXT1_EXT,
        DXT3 = GL_COMPRESSED_RGBA_S3TC_DXT3_EXT,
        DXT5 = GL_COMPRESSED_RGBA_S3TC_DXT5_EXT,
        D24S8 = GL_DEPTH24_STENCIL8_EXT,
    };

    enum class TextureFormat
    {
        BGR = GL_BGR,
        RGBA = GL_RGBA,
        A = GL_ALPHA,
        L = GL_LUMINANCE,
        AL = GL_LUMINANCE_ALPHA,
        BGRA = GL_BGRA,
        RG = GL_RG,
        RED = GL_RED,
        DXT1 = GL_COMPRESSED_RGBA_S3TC_DXT1_EXT,
        DXT3 = GL_COMPRESSED_RGBA_S3TC_DXT3_EXT,
        DXT5 = GL_COMPRESSED_RGBA_S3TC_DXT5_EXT,
        D24S8 = GL_DEPTH_STENCIL_EXT
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
        HalfFloat = GL_HALF_FLOAT_ARB,
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
        HalfFloat = GL_HALF_FLOAT_ARB,
        Float = GL_FLOAT,
        None = GL_NONE,
        UnsignedInt = GL_UNSIGNED_INT_24_8_EXT
    };

    enum class TextureSamplerCoordinate
    {
        Clamp = GL_CLAMP,
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
        Color0 = GL_COLOR_ATTACHMENT0_EXT,
        Color1 = GL_COLOR_ATTACHMENT1_EXT,
        Color2 = GL_COLOR_ATTACHMENT2_EXT,
        Color3 = GL_COLOR_ATTACHMENT3_EXT,
        Color4 = GL_COLOR_ATTACHMENT4_EXT,
        Color5 = GL_COLOR_ATTACHMENT5_EXT,
        Color6 = GL_COLOR_ATTACHMENT6_EXT,
        Color7 = GL_COLOR_ATTACHMENT7_EXT,
        Color8 = GL_COLOR_ATTACHMENT8_EXT,
        Color9 = GL_COLOR_ATTACHMENT9_EXT,
        Color10 = GL_COLOR_ATTACHMENT10_EXT,
        Color11 = GL_COLOR_ATTACHMENT14_EXT,
        Color12 = GL_COLOR_ATTACHMENT15_EXT,
        Color13 = GL_COLOR_ATTACHMENT13_EXT,
        Color14 = GL_COLOR_ATTACHMENT14_EXT,
        Color15 = GL_COLOR_ATTACHMENT15_EXT,
        Depth = GL_DEPTH_ATTACHMENT_EXT,
        Stencil = GL_STENCIL_ATTACHMENT_EXT
    };

    enum class CheckFrambufferStatus
    {
        Complete = GL_FRAMEBUFFER_COMPLETE_EXT,
        IncompleteAttachment = GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENTS_EXT,
        IncompleteMissingAttachment = GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT_EXT,
        IncompleteDuplicateAttachment = GL_FRAMEBUFFER_INCOMPLETE_DUPLICATE_ATTACHMENT_EXT,
        IncompleteDimensions = GL_FRAMEBUFFER_INCOMPLETE_DIMENSIONS_EXT,
        IncompleteFormats = GL_FRAMEBUFFER_INCOMPLETE_FORMATS_EXT,
        IncompleteDrawBuffer = GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER_EXT,
        IncompleteReadBuffer = GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER_EXT,
        Unsupported = GL_FRAMEBUFFER_UNSUPPORTED_EXT,
    };

    enum class AttributeUsage
    {
        Position = 0,  // 属性 0
        BlendWeight = 1,  // 属性 1
        Normal = 2,  // 属性 2
        Color = 3,  // 属性 3-4
        FogCoord = 5,  // 属性 5
        Psize = 6,  // 属性 6
        BlendIndices = 7,  // 属性 7
        TextureCoord = 8,  // 属性 8-13
        Tangent = 14,  // 属性 14
        Binormal = 15,  // 属性 15

        Quantity
    };

    ENUM_ORABLE_OPERATOR_DEFINE(OpenGLClearMask);
}

#endif  // SYSTEM_OPENGL_OPENGL_FLAGS_H
