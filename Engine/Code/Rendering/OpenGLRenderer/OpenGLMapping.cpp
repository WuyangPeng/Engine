// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/29 11:23)

#include "Rendering/RenderingExport.h" 

#include "OpenGLMapping.h"
#include "System/OpenGL/OpenGLAPI.h"

Rendering::Enum Rendering
    ::g_OpenGLAlphaSrcBlend[System::EnumCastUnderlying(AlphaStateFlags::SourceBlendMode::Quantity)] =
{
	static_cast<GLenum>(System::SrcBlendMode::Zero), // GL_ZERO,                        
	static_cast<GLenum>(System::SrcBlendMode::One), // GL_ONE,                        
	static_cast<GLenum>(System::SrcBlendMode::DstColor), // GL_DST_COLOR,                   
	static_cast<GLenum>(System::SrcBlendMode::OneMinusDstColor), // GL_ONE_MINUS_DST_COLOR,        
	static_cast<GLenum>(System::SrcBlendMode::SrcAlpha), // GL_SRC_ALPHA,                  
	static_cast<GLenum>(System::SrcBlendMode::OneMinusSrcAlpha), // GL_ONE_MINUS_SRC_ALPHA,        
	static_cast<GLenum>(System::SrcBlendMode::DstAlpha), // GL_DST_ALPHA,                 
	static_cast<GLenum>(System::SrcBlendMode::OneMinusDstAlpha), // GL_ONE_MINUS_DST_ALPHA,       
	static_cast<GLenum>(System::SrcBlendMode::SrcAlphaSaturate), // GL_SRC_ALPHA_SATURATE,         
	static_cast<GLenum>(System::SrcBlendMode::ConstantColor), // GL_CONSTANT_COLOR,           
	static_cast<GLenum>(System::SrcBlendMode::OneMinusConstantColor), // GL_ONE_MINUS_CONSTANT_COLOR, 
	static_cast<GLenum>(System::SrcBlendMode::ConstantAlpha), // GL_CONSTANT_ALPHA
};

Rendering::Enum Rendering
    ::g_OpenGLAlphaDstBlend[System::EnumCastUnderlying(AlphaStateFlags::DestinationBlendMode::Quantity)] =
{
	static_cast<GLenum>(System::DstBlendMode::Zero), // GL_ZERO,
	static_cast<GLenum>(System::DstBlendMode::One), // GL_ONE,
	static_cast<GLenum>(System::DstBlendMode::SrcColor), // GL_SRC_COLOR,
	static_cast<GLenum>(System::DstBlendMode::OneMinusSrcColor), // GL_ONE_MINUS_SRC_COLOR,
	static_cast<GLenum>(System::DstBlendMode::SrcAlpha), // GL_SRC_ALPHA,
	static_cast<GLenum>(System::DstBlendMode::OneMinusSrcAlpha), // GL_ONE_MINUS_SRC_ALPHA,
	static_cast<GLenum>(System::DstBlendMode::DstAlpha), // GL_SRC_ALPHA,
	static_cast<GLenum>(System::DstBlendMode::OneMinusDstAlpha), // GL_ONE_MINUS_DST_ALPHA,
	static_cast<GLenum>(System::DstBlendMode::ConstantColor), // GL_CONSTANT_COLOR,
	static_cast<GLenum>(System::DstBlendMode::OneMinusConstantColor), // GL_ONE_MINUS_CONSTANT_COLOR,
	static_cast<GLenum>(System::DstBlendMode::ConstantAlpha), // GL_CONSTANT_ALPHA,
	static_cast<GLenum>(System::DstBlendMode::OneMinusConstantAlpha), // GL_ONE_MINUS_CONSTANT_ALPHA
};

Rendering::Enum Rendering
    ::g_OpenGLAlphaCompare[System::EnumCastUnderlying(AlphaStateFlags::CompareMode::Quantity)] =
{
	static_cast<GLenum>(System::CompareMode::Never), // GL_NEVER,
	static_cast<GLenum>(System::CompareMode::Less), // GL_LESS,
	static_cast<GLenum>(System::CompareMode::Equal), // GL_EQUAL,
	static_cast<GLenum>(System::CompareMode::LEqual), // GL_LEQUAL,
	static_cast<GLenum>(System::CompareMode::Greater), // GL_GREATER,
	static_cast<GLenum>(System::CompareMode::NotEqual), // GL_NOTEQUAL,
	static_cast<GLenum>(System::CompareMode::GEqual), // GL_GEQUAL,
	static_cast<GLenum>(System::CompareMode::Always), // GL_ALWAYS
};

Rendering::Enum Rendering
    ::g_OpenGLDepthCompare[System::EnumCastUnderlying(DepthStateFlags::CompareMode::Quantity)] =
{
	static_cast<GLenum>(System::CompareMode::Never), // GL_NEVER,
	static_cast<GLenum>(System::CompareMode::Less), // GL_LESS,
	static_cast<GLenum>(System::CompareMode::Equal), // GL_EQUAL,
	static_cast<GLenum>(System::CompareMode::LEqual), // GL_LEQUAL,
	static_cast<GLenum>(System::CompareMode::Greater), // GL_GREATER,
	static_cast<GLenum>(System::CompareMode::NotEqual), // GL_NOTEQUAL,
	static_cast<GLenum>(System::CompareMode::GEqual), // GL_GEQUAL,
	static_cast<GLenum>(System::CompareMode::Always), // GL_ALWAYS
};

Rendering::Enum Rendering
    ::g_OpenGLStencilCompare[System::EnumCastUnderlying(StencilStateFlags::CompareMode::Quantity)] =
{
	static_cast<GLenum>(System::CompareMode::Never), // GL_NEVER,
	static_cast<GLenum>(System::CompareMode::Less), // GL_LESS,
	static_cast<GLenum>(System::CompareMode::Equal), // GL_EQUAL,
	static_cast<GLenum>(System::CompareMode::LEqual), // GL_LEQUAL,
	static_cast<GLenum>(System::CompareMode::Greater), // GL_GREATER,
	static_cast<GLenum>(System::CompareMode::NotEqual), // GL_NOTEQUAL,
	static_cast<GLenum>(System::CompareMode::GEqual), // GL_GEQUAL,
	static_cast<GLenum>(System::CompareMode::Always), // GL_ALWAYS
};

Rendering::Enum Rendering
    ::g_OpenGLStencilOperation[System::EnumCastUnderlying(StencilStateFlags::OperationType::Quantity)] =
{
	static_cast<GLenum>(System::OpenGLOperation::Keep), // GL_KEEP,
	static_cast<GLenum>(System::OpenGLOperation::Zero), // GL_ZERO,
	static_cast<GLenum>(System::OpenGLOperation::Replace), // GL_REPLACE,
	static_cast<GLenum>(System::OpenGLOperation::Increment), // GL_INCR,
	static_cast<GLenum>(System::OpenGLOperation::Decrement), // GL_DECR,
	static_cast<GLenum>(System::OpenGLOperation::Invert), // GL_INVERT
};

Rendering::Int Rendering
    ::g_OpenGLAttributeChannels[System::EnumCastUnderlying(VertexFormatFlags::AttributeType::Quantity)] =
{
    0,  // AttributeType::None (不支持的)
    1,  // AttributeType::Float1
    2,  // AttributeType::Float2
    3,  // AttributeType::Float3
    4,  // AttributeType::Float4
    1,  // AttributeType::Half1
    2,  // AttributeType::Half2
    3,  // AttributeType::Half3
    4,  // AttributeType::Half4
    4,  // AttributeType::UByte4
    1,  // AttributeType::Short1
    2,  // AttributeType::Short2
    4   // AttributeType::Short4
};

Rendering::UInt Rendering
    ::g_OpenGLAttributeType[System::EnumCastUnderlying(VertexFormatFlags::AttributeType::Quantity)] =
{
    0, // AttributeType::None (不支持的)
	static_cast<GLenum>(System::OpenGLAttribute::Float), // AttributeType::Float1
	static_cast<GLenum>(System::OpenGLAttribute::Float), // AttributeType::Float2
	static_cast<GLenum>(System::OpenGLAttribute::Float), // AttributeType::Float3
	static_cast<GLenum>(System::OpenGLAttribute::Float), // AttributeType::Float4
	0, // AttributeType::Half1
	0, // AttributeType::Half2
	0, // AttributeType::Half3
	0, // AttributeType::Half4
	static_cast<GLenum>(System::OpenGLAttribute::UByte), // AttributeType::UByte4
	static_cast<GLenum>(System::OpenGLAttribute::Short), // AttributeType::Short1
	static_cast<GLenum>(System::OpenGLAttribute::Short), // AttributeType::Short2
	static_cast<GLenum>(System::OpenGLAttribute::Short) // AttributeType::Short4
};

Rendering::UInt Rendering
    ::g_OpenGLBufferLocking[System::EnumCastUnderlying(BufferLocking::Quantity)] =
{
	static_cast<GLenum>(System::BufferLocking::ReadOnly), // GL_READ_ONLY,
	static_cast<GLenum>(System::BufferLocking::WriteOnly), // GL_WRITE_ONLY,
	static_cast<GLenum>(System::BufferLocking::ReadWrite), // GL_READ_WRITE,
};

Rendering::UInt Rendering
    ::g_OpenGLBufferUsage[System::EnumCastUnderlying(BufferUsage::Quantity)] =
{
	static_cast<GLenum>(System::BufferUsage::Static), // GL_STATIC_DRAW,    
	static_cast<GLenum>(System::BufferUsage::Dynamic), // GL_DYNAMIC_DRAW,  
	static_cast<GLenum>(System::BufferUsage::Dynamic), // GL_DYNAMIC_DRAW,    
	static_cast<GLenum>(System::BufferUsage::Dynamic), // GL_DYNAMIC_DRAW,  
	static_cast<GLenum>(System::BufferUsage::Dynamic), // GL_DYNAMIC_DRAW   
};

Rendering::Int Rendering
    ::g_OpenGLMinFilter[System::EnumCastUnderlying(ShaderFlags::SamplerFilter::Quantity)] =
{
	0,
	static_cast<GLenum>(System::SamplerFilter::Nearest), // GL_NEAREST,          
	static_cast<GLenum>(System::SamplerFilter::Linear), // GL_LINEAR,           
	static_cast<GLenum>(System::SamplerFilter::NearestNearest), // GL_NEAREST_MIPMAP_NEAREST,  
	static_cast<GLenum>(System::SamplerFilter::NearesLinear), // GL_NEAREST_MIPMAP_LINEAR,    
	static_cast<GLenum>(System::SamplerFilter::LinearNeares), // GL_LINEAR_MIPMAP_NEAREST,   
	static_cast<GLenum>(System::SamplerFilter::LinearLinear), // GL_LINEAR_MIPMAP_LINEAR
};

Rendering::UInt Rendering
    ::g_OpenGLTextureInternalFormat[System::EnumCastUnderlying(TextureFormat::Quantity)] =
{
    0,  
	static_cast<GLenum>(System::TextureInternalFormat::R5G6B5), //GL_RGB5, 
	static_cast<GLenum>(System::TextureInternalFormat::A1R5G5B5), //GL_RGB5_A1,  
	static_cast<GLenum>(System::TextureInternalFormat::A4R4G4B4), //GL_RGBA4,
	0, //GL_ALPHA8,
	0, //GL_LUMINANCE8,   
	0, //GL_LUMINANCE8_ALPHA8, 
	static_cast<GLenum>(System::TextureInternalFormat::R8G8B8), //GL_RGB8,
	static_cast<GLenum>(System::TextureInternalFormat::A8R8G8B8), //GL_RGBA8,
	static_cast<GLenum>(System::TextureInternalFormat::A8R8G8B8), //GL_RGBA8,
	0, //GL_LUMINANCE16, 
	static_cast<GLenum>(System::TextureInternalFormat::G16R16), //GL_RG16,            
	static_cast<GLenum>(System::TextureInternalFormat::A16B16G16R16), //GL_RGBA16,            
	static_cast<GLenum>(System::TextureInternalFormat::R16F), //GL_R16F,                     
	static_cast<GLenum>(System::TextureInternalFormat::G16R16F), //GL_RG16F,                       
	static_cast<GLenum>(System::TextureInternalFormat::A16B16G16R16F), //GL_RGBA16F_ARB,                   
	static_cast<GLenum>(System::TextureInternalFormat::R32F), //GL_R32F,                       
	static_cast<GLenum>(System::TextureInternalFormat::G32R32F), //GL_RG32F,                       
	static_cast<GLenum>(System::TextureInternalFormat::A32B32G32R32F), //GL_RGBA32F_ARB,
	//static_cast<GLenum>(System::TextureInternalFormat::DXT1), //GL_COMPRESSED_RGBA_S3TC_DXT1_EXT,
	//static_cast<GLenum>(System::TextureInternalFormat::DXT3), //GL_COMPRESSED_RGBA_S3TC_DXT3_EXT,
	//static_cast<GLenum>(System::TextureInternalFormat::DXT5), //GL_COMPRESSED_RGBA_S3TC_DXT5_EXT,
	0, //GL_DEPTH24_STENCIL8_EXT 
};

Rendering::UInt Rendering
    ::g_OpenGLTextureFormat[System::EnumCastUnderlying(TextureFormat::Quantity)] =
{
    0,  
	static_cast<GLenum>(System::TextureFormat::BGR), //GL_BGR,
	static_cast<GLenum>(System::TextureFormat::RGBA), // GL_RGBA
	static_cast<GLenum>(System::TextureFormat::RGBA), // GL_RGBA
	static_cast<GLenum>(System::TextureFormat::A), // GL_ALPHA,
	0, // GL_LUMINANCE,
	0, // GL_LUMINANCE_ALPHA,
	static_cast<GLenum>(System::TextureFormat::BGR), // GL_BGR,
	static_cast<GLenum>(System::TextureFormat::BGRA), // GL_BGRA,
	static_cast<GLenum>(System::TextureFormat::RGBA), // GL_RGBA
	0, // GL_LUMINANCE,
	static_cast<GLenum>(System::TextureFormat::RG), // GL_RG,
	static_cast<GLenum>(System::TextureFormat::RGBA), // GL_RGBA
	static_cast<GLenum>(System::TextureFormat::RED), // GL_RED,
	static_cast<GLenum>(System::TextureFormat::RG), // GL_RG,
	static_cast<GLenum>(System::TextureFormat::RGBA), // GL_RGBA
	static_cast<GLenum>(System::TextureFormat::RED), // GL_RED,
	static_cast<GLenum>(System::TextureFormat::RG), // GL_RG,
	static_cast<GLenum>(System::TextureFormat::RGBA), // GL_RGBA
	//static_cast<GLenum>(System::TextureFormat::DXT1), // GL_COMPRESSED_RGBA_S3TC_DXT1_EXT,
	//static_cast<GLenum>(System::TextureFormat::DXT3), // GL_COMPRESSED_RGBA_S3TC_DXT3_EXT,
	//static_cast<GLenum>(System::TextureFormat::DXT5), // GL_COMPRESSED_RGBA_S3TC_DXT5_EXT,
	0, // GL_DEPTH_STENCIL_EXT
};

Rendering::UInt Rendering
    ::g_OpenGLTextureTarget[System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity)] =
{
    0,  
	static_cast<Rendering::UInt>(System::TextureTarget::Texture1D), // GL_TEXTURE_1D,
	static_cast<Rendering::UInt>(System::TextureTarget::Texture2D), // GL_TEXTURE_2D,
	static_cast<Rendering::UInt>(System::TextureTarget::Texture3D), // GL_TEXTURE_3D,
	static_cast<Rendering::UInt>(System::TextureTarget::TextureCubeMap), // GL_TEXTURE_CUBE_MAP,
};

Rendering::UInt Rendering
    ::g_OpenGLTextureTargetBinding[System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity)] =
{
    0,
	static_cast<GLenum>(System::TextureTargetBinding::Binding1D), // GL_TEXTURE_BINDING_1D,
	static_cast<GLenum>(System::TextureTargetBinding::Binding2D), // GL_TEXTURE_BINDING_2D,
	static_cast<GLenum>(System::TextureTargetBinding::Binding3D), // GL_TEXTURE_BINDING_3D,
	static_cast<GLenum>(System::TextureTargetBinding::BindingCube), // GL_TEXTURE_BINDING_CUBE_MAP,
};

Rendering::UInt Rendering
    ::g_OpenGLTextureType[System::EnumCastUnderlying(TextureFormat::Quantity)] =
{
    0, // TextureFormat::None
	static_cast<GLenum>(System::TextureType::UnsignedShort565Rev), // TextureFormat::R5G6B5
	static_cast<GLenum>(System::TextureType::UnsignedShort1555Rev), // TextureFormat::A1R5G5B5
	static_cast<GLenum>(System::TextureType::UnsignedShort4444Rev), // TextureFormat::A4R4G4B4
	static_cast<GLenum>(System::TextureType::UnsignedByte), // TextureFormat::A8
	static_cast<GLenum>(System::TextureType::UnsignedByte), // TextureFormat::L8
	static_cast<GLenum>(System::TextureType::UnsignedByte), // TextureFormat::A8L8
	static_cast<GLenum>(System::TextureType::UnsignedByte), // TextureFormat::R8G8B8
	static_cast<GLenum>(System::TextureType::UnsignedByte), // TextureFormat::A8R8G8B8
	static_cast<GLenum>(System::TextureType::UnsignedByte), // TextureFormat::A8B8G8R8
	static_cast<GLenum>(System::TextureType::UnsignedShort), // TextureFormat::L16
	static_cast<GLenum>(System::TextureType::UnsignedShort), // TextureFormat::G16R16
	static_cast<GLenum>(System::TextureType::UnsignedShort), // TextureFormat::A16B16G16R16
	0, // TextureFormat::R16F
	0, // TextureFormat::G16R16F
	0, // TextureFormat::A16B16G16R16F
	static_cast<GLenum>(System::TextureType::Float), // TextureFormat::R32F
	static_cast<GLenum>(System::TextureType::Float), // TextureFormat::G32R32F
	static_cast<GLenum>(System::TextureType::Float), // TextureFormat::A32B32G32R32F
	static_cast<GLenum>(System::TextureType::None), // TextureFormat::DXT1 (不需要)
	static_cast<GLenum>(System::TextureType::None), // TextureFormat::DXT3 (不需要)
	static_cast<GLenum>(System::TextureType::None), // TextureFormat::DXT5 (不需要)
	0 // TextureFormat::D24S8
};

Rendering::Int Rendering
    ::g_OpenGLWrapMode[System::EnumCastUnderlying(ShaderFlags::SamplerCoordinate::Quantity)] =
{
	0,// GL_CLAMP,
	0,// GL_CLAMP,
	static_cast<GLenum>(System::TextureSamplerCoordinate::Repeat),// GL_REPEAT,
	static_cast<GLenum>(System::TextureSamplerCoordinate::MirroredRepeat),// GL_MIRRORED_REPEAT,
	static_cast<GLenum>(System::TextureSamplerCoordinate::ClampBorder),// GL_CLAMP_TO_BORDER,
	static_cast<GLenum>(System::TextureSamplerCoordinate::ClampEdge),// GL_CLAMP_TO_EDGE,
};

Rendering::Enum Rendering
    ::g_OpenGLPrimitiveType[System::EnumCastUnderlying(VisualPrimitiveType::MaxQuantity)] 
{
    0,  // VisualPrimitiveType::None (未使用)
	static_cast<GLenum>(System::PrimitiveType::Point), // VisualPrimitiveType::Polypoint
	static_cast<GLenum>(System::PrimitiveType::Lines), // VisualPrimitiveType::PolysegmentsDisjoint
	static_cast<GLenum>(System::PrimitiveType::LinesStrip), // VisualPrimitiveType::PolysegmentsContiguous
    0, // VisualPrimitiveType::Triangles (未使用)
	static_cast<GLenum>(System::PrimitiveType::Triangles), // VisualPrimitiveType::TriMesh
	static_cast<GLenum>(System::PrimitiveType::TrianglesStrip), // VisualPrimitiveType::TriStrip
	static_cast<GLenum>(System::PrimitiveType::TrianglesFan) // VisualPrimitiveType::TriFan
};



