// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/29 11:00)

#ifndef RENDERING_RENDERERS_OPENGL_MAPPING_H
#define RENDERING_RENDERERS_OPENGL_MAPPING_H

#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "System/OpenGL/Using/OpenGLUsing.h"
#include "Rendering/Resources/VertexFormat.h"
#include "Rendering/Resources/Flags/BufferFlags.h"
#include "Rendering/SceneGraph/Flags/VisualFlags.h"
#include "Rendering/DataTypes/Flags/TextureFormat.h"
#include "Rendering/Shaders/Flags/ShaderFlags.h"
#include "Rendering/Shaders/Flags/AlphaStateFlags.h"
#include "Rendering/Shaders/Flags/DepthStateFlags.h"
#include "Rendering/Shaders/Flags/StencilStateFlags.h"

namespace Rendering
{
	using Enum = System::OpenGLEnum;
	using UInt = System::OpenGLUInt;
	using Int = System::OpenGLInt;
	
	RENDERING_DEFAULT_DECLARE extern Enum g_OpenGLAlphaSrcBlend[System::EnumCastUnderlying(AlphaStateFlags::SourceBlendMode::Quantity)];
	RENDERING_DEFAULT_DECLARE extern Enum g_OpenGLAlphaDstBlend[System::EnumCastUnderlying(AlphaStateFlags::DestinationBlendMode::Quantity)];
	RENDERING_DEFAULT_DECLARE extern Enum g_OpenGLAlphaCompare[System::EnumCastUnderlying(AlphaStateFlags::CompareMode::Quantity)];
	RENDERING_DEFAULT_DECLARE extern Enum g_OpenGLDepthCompare[System::EnumCastUnderlying(DepthStateFlags::CompareMode::Quantity)];
	RENDERING_DEFAULT_DECLARE extern Enum g_OpenGLStencilCompare[System::EnumCastUnderlying(StencilStateFlags::CompareMode::Quantity)];
	RENDERING_DEFAULT_DECLARE extern Enum g_OpenGLStencilOperation[System::EnumCastUnderlying(StencilStateFlags::OperationType::Quantity)];
	RENDERING_DEFAULT_DECLARE extern Int  g_OpenGLAttributeChannels[System::EnumCastUnderlying(VertexFormatFlags::AttributeType::Quantity)];
	RENDERING_DEFAULT_DECLARE extern UInt g_OpenGLAttributeType[System::EnumCastUnderlying(VertexFormatFlags::AttributeType::Quantity)];
	RENDERING_DEFAULT_DECLARE extern UInt g_OpenGLBufferLocking[System::EnumCastUnderlying(BufferLocking::Quantity)];
	RENDERING_DEFAULT_DECLARE extern UInt g_OpenGLBufferUsage[System::EnumCastUnderlying(BufferUsage::Quantity)];
	RENDERING_DEFAULT_DECLARE extern Int  g_OpenGLMinFilter[System::EnumCastUnderlying(ShaderFlags::SamplerFilter::Quantity)];
	RENDERING_DEFAULT_DECLARE extern UInt g_OpenGLTextureFormat[System::EnumCastUnderlying(TextureFormat::Quantity)];
	RENDERING_DEFAULT_DECLARE extern UInt g_OpenGLTextureInternalFormat[System::EnumCastUnderlying(TextureFormat::Quantity)];
	RENDERING_DEFAULT_DECLARE extern UInt g_OpenGLTextureTarget[System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity)];
	RENDERING_DEFAULT_DECLARE extern UInt g_OpenGLTextureTargetBinding[System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity)];
	RENDERING_DEFAULT_DECLARE extern UInt g_OpenGLTextureType[System::EnumCastUnderlying(TextureFormat::Quantity)];
	RENDERING_DEFAULT_DECLARE extern Int  g_OpenGLWrapMode[System::EnumCastUnderlying(ShaderFlags::SamplerCoordinate::Quantity)];
	RENDERING_DEFAULT_DECLARE extern Enum g_OpenGLPrimitiveType[System::EnumCastUnderlying(VisualPrimitiveType::MaxQuantity)];
}

#endif // RENDERING_RENDERERS_OPENGL_MAPPING_H
