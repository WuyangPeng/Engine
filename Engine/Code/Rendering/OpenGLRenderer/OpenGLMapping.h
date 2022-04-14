// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/29 11:00)

#ifndef RENDERING_RENDERERS_OPENGL_MAPPING_H
#define RENDERING_RENDERERS_OPENGL_MAPPING_H

#include "Rendering/RenderingDll.h"

#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "System/OpenGL/Using/OpenGLUsing.h"
#include "Rendering/DataTypes/Flags/TextureFormat.h"
#include "Rendering/Resources/Flags/BufferFlags.h"
#include "Rendering/Resources/VertexFormat.h"
#include "Rendering/SceneGraph/Flags/VisualFlags.h"
#include "Rendering/Shaders/Flags/AlphaStateFlags.h"
#include "Rendering/Shaders/Flags/DepthStateFlags.h"
#include "Rendering/Shaders/Flags/ShaderFlags.h"
#include "Rendering/Shaders/Flags/StencilStateFlags.h"

namespace Rendering
{
    using Enum = System::OpenGLEnum;
    using UInt = System::OpenGLUInt;
    using Int = System::OpenGLInt;

    class RENDERING_DEFAULT_DECLARE OpenGLConstant
    {
    public:
        static Enum g_OpenGLAlphaSrcBlend[System::EnumCastUnderlying(AlphaStateFlags::SourceBlendMode::Quantity)];
        static Enum g_OpenGLAlphaDstBlend[System::EnumCastUnderlying(AlphaStateFlags::DestinationBlendMode::Quantity)];
        static Enum g_OpenGLAlphaCompare[System::EnumCastUnderlying(AlphaStateFlags::CompareMode::Quantity)];
        static Enum g_OpenGLDepthCompare[System::EnumCastUnderlying(DepthStateFlags::CompareMode::Quantity)];
        static Enum g_OpenGLStencilCompare[System::EnumCastUnderlying(StencilStateFlags::CompareMode::Quantity)];
        static Enum g_OpenGLStencilOperation[System::EnumCastUnderlying(StencilStateFlags::OperationType::Quantity)];
        static Int g_OpenGLAttributeChannels[System::EnumCastUnderlying(VertexFormatFlags::AttributeType::Quantity)];
        static UInt g_OpenGLAttributeType[System::EnumCastUnderlying(VertexFormatFlags::AttributeType::Quantity)];
        static UInt g_OpenGLBufferLocking[System::EnumCastUnderlying(BufferLocking::Quantity)];
        static UInt g_OpenGLBufferUsage[System::EnumCastUnderlying(BufferUsage::Quantity)];
        static Int g_OpenGLMinFilter[System::EnumCastUnderlying(ShaderFlags::SamplerFilter::Quantity)];
        static UInt g_OpenGLTextureFormat[System::EnumCastUnderlying(TextureFormat::Quantity)];
        static UInt g_OpenGLTextureInternalFormat[System::EnumCastUnderlying(TextureFormat::Quantity)];
        static UInt g_OpenGLTextureTarget[System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity)];
        static UInt g_OpenGLTextureTargetBinding[System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity)];
        static UInt g_OpenGLTextureType[System::EnumCastUnderlying(TextureFormat::Quantity)];
        static Int g_OpenGLWrapMode[System::EnumCastUnderlying(ShaderFlags::SamplerCoordinate::Quantity)];
        static Enum g_OpenGLPrimitiveType[System::EnumCastUnderlying(VisualPrimitiveType::MaxQuantity)];
    };
}

#endif  // RENDERING_RENDERERS_OPENGL_MAPPING_H
