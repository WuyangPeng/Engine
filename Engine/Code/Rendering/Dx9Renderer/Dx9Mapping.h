// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/29 11:35)

#ifndef RENDERING_DX9_RENDERER_DX9_MAPPING_H
#define RENDERING_DX9_RENDERER_DX9_MAPPING_H

#include "Rendering/RenderingDll.h"

#include <Windows.h>
#include <d3d9types.h>

#include "Rendering/Shaders/Flags/ShaderFlags.h"
#include "Rendering/Shaders/Flags/AlphaStateFlags.h"
#include "Rendering/Shaders/Flags/StencilStateFlags.h"
#include "Rendering/Shaders/Flags/DepthStateFlags.h"
#include "Rendering/Resources/Flags/BufferFlags.h"
#include "Rendering/Resources/Flags/TextureFlags.h"
#include "Rendering/Resources/Flags/VertexFormatFlags.h"
#include "Rendering/SceneGraph/Flags/VisualFlags.h"
#include "Rendering/DataTypes/Flags/TextureFormat.h"
#include "System/Helper/EnumCast.h"

namespace Rendering
{
	extern BYTE gDX9AttributeType[System::EnumCastUnderlying(VertexFormatFlags::AttributeType::Quantity)];
	extern BYTE gDX9AttributeUsage[System::EnumCastUnderlying(VertexFormatFlags::AttributeUsage::Quantity)];
	extern DWORD gDX9BufferUsage[System::EnumCastUnderlying(BufferUsage::Quantity)];
	extern DWORD gDX9BufferLocking[System::EnumCastUnderlying(BufferLocking::Quantity)];
	extern D3DFORMAT gDX9TextureFormat[System::EnumCastUnderlying(TextureFormat::Quantity)];
	extern DWORD gDX9MinFilter[System::EnumCastUnderlying(ShaderFlags::SamplerFilter::Quantity)];
	extern DWORD gDX9MipFilter[System::EnumCastUnderlying(ShaderFlags::SamplerFilter::Quantity)];
	extern DWORD gDX9WrapMode[System::EnumCastUnderlying(ShaderFlags::SamplerCoordinate::Quantity)];
	extern DWORD gDX9AlphaSrcBlend[System::EnumCastUnderlying(AlphaStateFlags::SourceBlendMode::Quantity)];
	extern DWORD gDX9AlphaDstBlend[System::EnumCastUnderlying(AlphaStateFlags::DestinationBlendMode::Quantity)];
	extern DWORD gDX9AlphaCompare[System::EnumCastUnderlying(AlphaStateFlags::CompareMode::Quantity)];
	extern DWORD gDX9CullOrder[2];
	extern DWORD gDX9DepthCompare[System::EnumCastUnderlying(DepthStateFlags::CompareMode::Quantity)];
	extern DWORD gDX9StencilCompare[System::EnumCastUnderlying(StencilStateFlags::CompareMode::Quantity)];
	extern DWORD gDX9StencilOperation[System::EnumCastUnderlying(StencilStateFlags::OperationType::Quantity)];
	extern D3DPRIMITIVETYPE gDX9PrimitiveType[System::EnumCastUnderlying(VisualPrimitiveType::MaxQuantity)];
}

#endif // RENDERING_DX9_RENDERER_DX9_MAPPING_H
