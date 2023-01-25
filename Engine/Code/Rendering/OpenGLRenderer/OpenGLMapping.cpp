///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/22 15:49)

#include "Rendering/RenderingExport.h"

#include "OpenGLMapping.h"


Rendering::Int Rendering::OpenGLConstant::GetOpenGLAttributeChannels(int index)
{
    static std::array<Enum, System::EnumCastUnderlying(VertexFormatFlags::AttributeType::Quantity)> result{
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
        4  // AttributeType::Short4
    };

    return result.at(index);
}

Rendering::UInt Rendering::OpenGLConstant::GetOpenGLAttributeType(int index)
{
    static std::array<Enum, System::EnumCastUnderlying(VertexFormatFlags::AttributeType::Quantity)> result{
        0,  // AttributeType::None (不支持的)
        static_cast<GLenum>(System::OpenGLAttribute::Float),  // AttributeType::Float1
        static_cast<GLenum>(System::OpenGLAttribute::Float),  // AttributeType::Float2
        static_cast<GLenum>(System::OpenGLAttribute::Float),  // AttributeType::Float3
        static_cast<GLenum>(System::OpenGLAttribute::Float),  // AttributeType::Float4
        0,  // AttributeType::Half1
        0,  // AttributeType::Half2
        0,  // AttributeType::Half3
        0,  // AttributeType::Half4
        static_cast<GLenum>(System::OpenGLAttribute::UByte),  // AttributeType::UByte4
        static_cast<GLenum>(System::OpenGLAttribute::Short),  // AttributeType::Short1
        static_cast<GLenum>(System::OpenGLAttribute::Short),  // AttributeType::Short2
        static_cast<GLenum>(System::OpenGLAttribute::Short)  // AttributeType::Short4
    };

    return result.at(index);
}

Rendering::UInt Rendering::OpenGLConstant::GetOpenGLBufferLocking(int index)
{
    static std::array<Enum, System::EnumCastUnderlying(BufferLocking::Quantity)> result{
        static_cast<GLenum>(System::BufferLocking::ReadOnly),  // GL_READ_ONLY,
        static_cast<GLenum>(System::BufferLocking::WriteOnly),  // GL_WRITE_ONLY,
        static_cast<GLenum>(System::BufferLocking::ReadWrite),  // GL_READ_WRITE,
    };

    return result.at(index);
}

Rendering::UInt Rendering::OpenGLConstant::GetOpenGLBufferUsage(int index)
{
    static std::array<Enum, System::EnumCastUnderlying(BufferUsage::Quantity)> result{
        static_cast<GLenum>(System::BufferUsage::Static),  // GL_STATIC_DRAW,
        static_cast<GLenum>(System::BufferUsage::Dynamic),  // GL_DYNAMIC_DRAW,
        static_cast<GLenum>(System::BufferUsage::Dynamic),  // GL_DYNAMIC_DRAW,
        static_cast<GLenum>(System::BufferUsage::Dynamic),  // GL_DYNAMIC_DRAW,
        static_cast<GLenum>(System::BufferUsage::Dynamic),  // GL_DYNAMIC_DRAW
    };

    return result.at(index);
}

Rendering::UInt Rendering::OpenGLConstant::GetOpenGLTextureFormat(int index)
{
    static std::array<Enum, System::EnumCastUnderlying(TextureFormat::Quantity)> result{
        0,
        static_cast<GLenum>(System::TextureFormat::BGR),  //GL_BGR,
        static_cast<GLenum>(System::TextureFormat::RGBA),  // GL_RGBA
        static_cast<GLenum>(System::TextureFormat::RGBA),  // GL_RGBA
        static_cast<GLenum>(System::TextureFormat::A),  // GL_ALPHA,
        0,  // GL_LUMINANCE,
        0,  // GL_LUMINANCE_ALPHA,
        static_cast<GLenum>(System::TextureFormat::BGR),  // GL_BGR,
        static_cast<GLenum>(System::TextureFormat::BGRA),  // GL_BGRA,
        static_cast<GLenum>(System::TextureFormat::RGBA),  // GL_RGBA
        0,  // GL_LUMINANCE,
        static_cast<GLenum>(System::TextureFormat::RG),  // GL_RG,
        static_cast<GLenum>(System::TextureFormat::RGBA),  // GL_RGBA
        static_cast<GLenum>(System::TextureFormat::RED),  // GL_RED,
        static_cast<GLenum>(System::TextureFormat::RG),  // GL_RG,
        static_cast<GLenum>(System::TextureFormat::RGBA),  // GL_RGBA
        static_cast<GLenum>(System::TextureFormat::RED),  // GL_RED,
        static_cast<GLenum>(System::TextureFormat::RG),  // GL_RG,
        static_cast<GLenum>(System::TextureFormat::RGBA),  // GL_RGBA
        0,  // GL_COMPRESSED_RGBA_S3TC_DXT1_EXT,
        0,  // GL_COMPRESSED_RGBA_S3TC_DXT3_EXT,
        0,  // GL_COMPRESSED_RGBA_S3TC_DXT5_EXT,
        0,  // GL_DEPTH_STENCIL_EXT
    };

    return result.at(index);
}

Rendering::UInt Rendering::OpenGLConstant::GetOpenGLTextureTarget(int index)
{
    static std::array<Enum, System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity)> result{
        0,
        static_cast<UInt>(System::TextureTarget::Texture1D),  // GL_TEXTURE_1D,
        static_cast<UInt>(System::TextureTarget::Texture2D),  // GL_TEXTURE_2D,
        static_cast<UInt>(System::TextureTarget::Texture3D),  // GL_TEXTURE_3D,
        static_cast<UInt>(System::TextureTarget::TextureCubeMap),  // GL_TEXTURE_CUBE_MAP,
    };

    return result.at(index);
}

Rendering::UInt Rendering::OpenGLConstant::GetOpenGLTextureTargetBinding(int index)
{
    static std::array<Enum, System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity)> result{
        0,
        static_cast<UInt>(System::TextureTargetBinding::Binding1D),  // GL_TEXTURE_BINDING_1D,
        static_cast<UInt>(System::TextureTargetBinding::Binding2D),  // GL_TEXTURE_BINDING_2D,
        static_cast<UInt>(System::TextureTargetBinding::Binding3D),  // GL_TEXTURE_BINDING_3D,
        static_cast<UInt>(System::TextureTargetBinding::BindingCube),  // GL_TEXTURE_BINDING_CUBE_MAP,
    };

    return result.at(index);
}

Rendering::UInt Rendering::OpenGLConstant::GetOpenGLTextureType(int index)
{
    static std::array<Enum, System::EnumCastUnderlying(TextureFormat::Quantity)> result{
        0,  // TextureFormat::None
        static_cast<GLenum>(System::TextureType::UnsignedShort565Rev),  // TextureFormat::R5G6B5
        static_cast<GLenum>(System::TextureType::UnsignedShort1555Rev),  // TextureFormat::A1R5G5B5
        static_cast<GLenum>(System::TextureType::UnsignedShort4444Rev),  // TextureFormat::A4R4G4B4
        static_cast<GLenum>(System::TextureType::UnsignedByte),  // TextureFormat::A8
        static_cast<GLenum>(System::TextureType::UnsignedByte),  // TextureFormat::L8
        static_cast<GLenum>(System::TextureType::UnsignedByte),  // TextureFormat::A8L8
        static_cast<GLenum>(System::TextureType::UnsignedByte),  // TextureFormat::R8G8B8
        static_cast<GLenum>(System::TextureType::UnsignedByte),  // TextureFormat::A8R8G8B8
        static_cast<GLenum>(System::TextureType::UnsignedByte),  // TextureFormat::A8B8G8R8
        static_cast<GLenum>(System::TextureType::UnsignedShort),  // TextureFormat::L16
        static_cast<GLenum>(System::TextureType::UnsignedShort),  // TextureFormat::G16R16
        static_cast<GLenum>(System::TextureType::UnsignedShort),  // TextureFormat::A16B16G16R16
        0,  // TextureFormat::R16F
        0,  // TextureFormat::G16R16F
        0,  // TextureFormat::A16B16G16R16F
        static_cast<GLenum>(System::TextureType::Float),  // TextureFormat::R32F
        static_cast<GLenum>(System::TextureType::Float),  // TextureFormat::G32R32F
        static_cast<GLenum>(System::TextureType::Float),  // TextureFormat::A32B32G32R32F
        static_cast<GLenum>(System::TextureType::None),  // TextureFormat::DXT1 (不需要)
        static_cast<GLenum>(System::TextureType::None),  // TextureFormat::DXT3 (不需要)
        static_cast<GLenum>(System::TextureType::None),  // TextureFormat::DXT5 (不需要)
        0  // TextureFormat::D24S8
    };

    return result.at(index);
}

Rendering::Int Rendering::OpenGLConstant::GetOpenGLWrapMode(int index)
{
    static std::array<Enum, System::EnumCastUnderlying(ShaderFlags::SamplerCoordinate::Quantity)> result{
        0,  // GL_CLAMP,
        0,  // GL_CLAMP,
        static_cast<GLenum>(System::TextureSamplerCoordinate::Repeat),  // GL_REPEAT,
        static_cast<GLenum>(System::TextureSamplerCoordinate::MirroredRepeat),  // GL_MIRRORED_REPEAT,
        static_cast<GLenum>(System::TextureSamplerCoordinate::ClampBorder),  // GL_CLAMP_TO_BORDER,
        static_cast<GLenum>(System::TextureSamplerCoordinate::ClampEdge),  // GL_CLAMP_TO_EDGE,
    };

    return result.at(index);
}

Rendering::Enum Rendering::OpenGLConstant::GetOpenGLPrimitiveType(int index)
{
    static std::array<Enum, System::EnumCastUnderlying(VisualPrimitiveType::MaxQuantity)> result{
        0,  // VisualPrimitiveType::None (未使用)
        static_cast<GLenum>(System::PrimitiveType::Point),  // VisualPrimitiveType::Polypoint
        static_cast<GLenum>(System::PrimitiveType::Lines),  // VisualPrimitiveType::PolysegmentsDisjoint
        static_cast<GLenum>(System::PrimitiveType::LinesStrip),  // VisualPrimitiveType::PolysegmentsContiguous
        0,  // VisualPrimitiveType::Triangles (未使用)
        static_cast<GLenum>(System::PrimitiveType::Triangles),  // VisualPrimitiveType::TriMesh
        static_cast<GLenum>(System::PrimitiveType::TrianglesStrip),  // VisualPrimitiveType::TriStrip
        static_cast<GLenum>(System::PrimitiveType::TrianglesFan)  // VisualPrimitiveType::TriFan
    };

    return result.at(index);
}
