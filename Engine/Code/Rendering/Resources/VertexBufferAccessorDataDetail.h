// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/19 13:49)

#ifndef RENDERING_RESOURCES_VERTEX_BUFFER_ACCESSOR_DATA_DETAIL_H
#define RENDERING_RESOURCES_VERTEX_BUFFER_ACCESSOR_DATA_DETAIL_H

#include "Rendering/RenderingExport.h" 

#include "VertexBufferAccessorData.h"
#include "VertexFormat.h"
#include "VertexBuffer.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

template <Rendering::VertexFormatFlags::AttributeUsage usage>
Rendering::VertexBufferAccessorData<usage>
	::VertexBufferAccessorData()
	:m_Data{ nullptr }, m_DataChannels{ 0 }
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

template <Rendering::VertexFormatFlags::AttributeUsage usage>
Rendering::VertexBufferAccessorData<usage>
	::VertexBufferAccessorData(const ConstVertexFormatSmartPointer& vertexformat,const ConstVertexBufferSmartPointer& vertexbuffer)
	:m_Data{ nullptr }, m_DataChannels{ 0 }
{
	Init(vertexformat, vertexbuffer);

	RENDERING_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <Rendering::VertexFormatFlags::AttributeUsage usage>
bool Rendering::VertexBufferAccessorData<usage>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIAN

template <Rendering::VertexFormatFlags::AttributeUsage usage>
void Rendering::VertexBufferAccessorData<usage>
	::Init( const ConstVertexFormatSmartPointer& vertexformat,const ConstVertexBufferSmartPointer& vertexbuffer,int number)
{
	RENDERING_CLASS_IS_VALID_9;
	
	auto baseType = VertexFormatFlags::AttributeType::None;

	auto index = vertexformat->GetIndex(usage, number);
	if (0 <= index)
	{
		m_Data = vertexbuffer->GetReadOnlyData(vertexformat->GetOffset(index));
		auto type = vertexformat->GetAttributeType(index);
		m_DataChannels = System::EnumCastUnderlying(type) - System::EnumCastUnderlying(baseType);
		if (4 < m_DataChannels)
		{
			m_DataChannels = 0;
		}
	}
	else
	{
		m_Data = nullptr;
		m_DataChannels = 0;
	}
}

template <>
void Rendering::VertexBufferAccessorData<Rendering::VertexFormatFlags::AttributeUsage::BlendIndices>
	::Init(const ConstVertexFormatSmartPointer& vertexformat,const ConstVertexBufferSmartPointer& vertexbuffer,int number)
{
	RENDERING_CLASS_IS_VALID_9;

	auto index = vertexformat->GetIndex(VertexFormatFlags::AttributeUsage::BlendIndices, number);
	if (0 <= index)
	{
		m_Data = vertexbuffer->GetReadOnlyData(vertexformat->GetOffset(index));
		m_DataChannels = 0;
	}
	else
	{
		m_Data = nullptr;
		m_DataChannels = 0;
	}
}

template <>
void Rendering::VertexBufferAccessorData<Rendering::VertexFormatFlags::AttributeUsage::BlendWeight>
	::Init(const ConstVertexFormatSmartPointer& vertexformat,const ConstVertexBufferSmartPointer& vertexbuffer,int number)
{
	RENDERING_CLASS_IS_VALID_9;

	auto index = vertexformat->GetIndex(VertexFormatFlags::AttributeUsage::BlendWeight, number);
	if (0 <= index)
	{
		m_Data = vertexbuffer->GetReadOnlyData(vertexformat->GetOffset(index));
		m_DataChannels = 0;
	}
	else
	{
		m_Data = nullptr;
		m_DataChannels = 0;
	}
}
 
template <Rendering::VertexFormatFlags::AttributeUsage usage>
const char* Rendering::VertexBufferAccessorData<usage>
	::GetData(int stride, int index) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_Data + index * stride;
}

template <Rendering::VertexFormatFlags::AttributeUsage usage>
bool Rendering::VertexBufferAccessorData<usage>
	::HasData() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_Data != nullptr;
}

template <Rendering::VertexFormatFlags::AttributeUsage usage>
int Rendering::VertexBufferAccessorData<usage>
	::GetDataChannels() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_DataChannels;
}

template <Rendering::VertexFormatFlags::AttributeUsage usage>
const float* Rendering::VertexBufferAccessorData<usage>
	::GetDataTuple(int stride, int index) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return reinterpret_cast<const float*>(m_Data + index * stride);
} 

#endif // RENDERING_RENDERERS_OPENGL_VERTEX_FORMAT_DATA_DETAIL_H



