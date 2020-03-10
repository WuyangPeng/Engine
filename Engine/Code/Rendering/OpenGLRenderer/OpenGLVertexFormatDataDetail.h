// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/29 11:19)

#ifndef RENDERING_RENDERERS_OPENGL_VERTEX_FORMAT_DATA_DETAIL_H
#define RENDERING_RENDERERS_OPENGL_VERTEX_FORMAT_DATA_DETAIL_H

#include "Rendering/RenderingExport.h" 

#include "OpenGLVertexFormatData.h"
#include "OpenGLMapping.h"
#include "System/OpenGL/OpenGLAPI.h"
#include "Rendering/Resources/VertexFormat.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

template <Rendering::VertexFormatFlags::AttributeUsage usage>
Rendering::OpenGLVertexFormatData<usage>
	::OpenGLVertexFormatData()
	:m_Has{ 0 }, m_Channels{ 0 },m_Type{ System::OpenGLData::None }, m_Offset{ 0 }
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <Rendering::VertexFormatFlags::AttributeUsage usage>
bool Rendering::OpenGLVertexFormatData<usage>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIAN

template <Rendering::VertexFormatFlags::AttributeUsage usage>
void Rendering::OpenGLVertexFormatData<usage>
	::Init( const VertexFormat* vertexFormat )
{
	RENDERING_CLASS_IS_VALID_9;

	int index = vertexFormat->GetIndex(usage);
	if (0 <= index)
	{
		m_Has = 1;
		VertexFormatFlags::AttributeType type = vertexFormat->GetAttributeType(index); 
		m_Channels = g_OpenGLAttributeChannels[System::EnumCastUnderlying(type)];
		m_Type = System::OpenGLData(g_OpenGLAttributeType[System::EnumCastUnderlying(type)]);
		m_Offset = vertexFormat->GetOffset(index);
	}
}

template <Rendering::VertexFormatFlags::AttributeUsage usage>
void Rendering::OpenGLVertexFormatData<usage>
	::Set( UInt has,UInt channels, DataType type,UInt offset )
{
	RENDERING_CLASS_IS_VALID_9;

	m_Has = has;
	m_Channels = channels;
	m_Type = type;
	m_Offset = offset;
}

template <Rendering::VertexFormatFlags::AttributeUsage usage>
bool Rendering::OpenGLVertexFormatData<usage>
	::IsHas() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_Has != 0;
}

template <Rendering::VertexFormatFlags::AttributeUsage usage>
System::OpenGLUInt Rendering::OpenGLVertexFormatData<usage>
	::GetChannels() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_Channels;
}

template <Rendering::VertexFormatFlags::AttributeUsage usage>
System::OpenGLData Rendering::OpenGLVertexFormatData<usage>
	::GetType() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_Type;
}

template <Rendering::VertexFormatFlags::AttributeUsage usage>
System::OpenGLUInt Rendering::OpenGLVertexFormatData<usage>
	::GetOffset() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_Offset;
}

template <>
RENDERING_DEFAULT_DECLARE void Rendering
	::OpenGLVertexFormatData<Rendering::VertexFormatFlags::AttributeUsage::Position>
	::Enable(int stride);

template <>
RENDERING_DEFAULT_DECLARE void Rendering
	::OpenGLVertexFormatData<Rendering::VertexFormatFlags::AttributeUsage::Normal>
	::Enable(int stride); 

template <>
RENDERING_DEFAULT_DECLARE void Rendering
	::OpenGLVertexFormatData<Rendering::VertexFormatFlags::AttributeUsage::Tangent>
	::Enable(int stride); 

template <>
RENDERING_DEFAULT_DECLARE void Rendering
	::OpenGLVertexFormatData<Rendering::VertexFormatFlags::AttributeUsage::Binormal>
	::Enable(int stride); 

template <>
RENDERING_DEFAULT_DECLARE void Rendering
	::OpenGLVertexFormatData<Rendering::VertexFormatFlags::AttributeUsage::BlendIndices>
	::Enable(int stride); 

template <>
RENDERING_DEFAULT_DECLARE void Rendering
	::OpenGLVertexFormatData<Rendering::VertexFormatFlags::AttributeUsage::BlendWeight>
	::Enable(int stride); 

template <>
RENDERING_DEFAULT_DECLARE void Rendering
	::OpenGLVertexFormatData<Rendering::VertexFormatFlags::AttributeUsage::FogCoord>
	::Enable(int stride); 

template <>
RENDERING_DEFAULT_DECLARE void Rendering
	::OpenGLVertexFormatData<Rendering::VertexFormatFlags::AttributeUsage::Psize>
	::Enable(int stride); 

template <>
RENDERING_DEFAULT_DECLARE void Rendering
	::OpenGLVertexFormatData<Rendering::VertexFormatFlags::AttributeUsage::Position>
	::Disable(); 

template <>
RENDERING_DEFAULT_DECLARE void Rendering
	::OpenGLVertexFormatData<Rendering::VertexFormatFlags::AttributeUsage::Normal>
	::Disable(); 

template <>
RENDERING_DEFAULT_DECLARE void Rendering
	::OpenGLVertexFormatData<Rendering::VertexFormatFlags::AttributeUsage::Tangent>
	::Disable(); 

template <>
RENDERING_DEFAULT_DECLARE void Rendering
	::OpenGLVertexFormatData<Rendering::VertexFormatFlags::AttributeUsage::Binormal>
	::Disable(); 

template <>
RENDERING_DEFAULT_DECLARE void Rendering
	::OpenGLVertexFormatData<Rendering::VertexFormatFlags::AttributeUsage::BlendIndices>
	::Disable();

template <>
RENDERING_DEFAULT_DECLARE void Rendering
	::OpenGLVertexFormatData<Rendering::VertexFormatFlags::AttributeUsage::BlendWeight>
	::Disable();

template <>
RENDERING_DEFAULT_DECLARE void Rendering
	::OpenGLVertexFormatData<Rendering::VertexFormatFlags::AttributeUsage::FogCoord>
	::Disable();

template <>
RENDERING_DEFAULT_DECLARE void Rendering
	::OpenGLVertexFormatData<Rendering::VertexFormatFlags::AttributeUsage::Psize>
	::Disable();

#endif // RENDERING_RENDERERS_OPENGL_VERTEX_FORMAT_DATA_DETAIL_H



