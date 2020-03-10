// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/29 11:18)

#ifndef RENDERING_RENDERERS_OPENGL_VERTEX_FORMAT_ARRAY_DATA_DETAIL_H
#define RENDERING_RENDERERS_OPENGL_VERTEX_FORMAT_ARRAY_DATA_DETAIL_H

#include "Rendering/RenderingExport.h" 

#include "OpenGLVertexFormatArrayData.h"
#include "OpenGLVertexFormatDataDetail.h"
#include "OpenGLMapping.h"
#include "System/OpenGL/OpenGLAPI.h"
#include "Rendering/Resources/VertexFormat.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

template <Rendering::VertexFormatFlags::AttributeUsage usage,Rendering::VertexFormatFlags::MaximumNumber number>
Rendering::OpenGLVertexFormatArrayData<usage,number>
	::OpenGLVertexFormatArrayData()
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <Rendering::VertexFormatFlags::AttributeUsage usage,Rendering::VertexFormatFlags::MaximumNumber number>
bool Rendering::OpenGLVertexFormatArrayData<usage,number>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIAN

template <Rendering::VertexFormatFlags::AttributeUsage usage,Rendering::VertexFormatFlags::MaximumNumber number>
void Rendering::OpenGLVertexFormatArrayData<usage,number>
	::Init( const VertexFormat* vertexFormat )
{
	RENDERING_CLASS_IS_VALID_9;

	for (auto unit = 0; unit < System::EnumCastUnderlying(number); ++unit)
	{
		auto index = vertexFormat->GetIndex(usage,unit);
		if (0 <= index)
		{ 
			UInt has = 1;
			VertexFormatFlags::AttributeType attributeType = vertexFormat->GetAttributeType(index);
			UInt channels = g_OpenGLAttributeChannels[System::EnumCastUnderlying(attributeType)];
			System::OpenGLData type = System::OpenGLData(g_OpenGLAttributeType[System::EnumCastUnderlying(attributeType)]);
			UInt offset = vertexFormat->GetOffset(index);

			m_Data[unit].Set(has,channels,type,offset);
		}
	}
}

template <Rendering::VertexFormatFlags::AttributeUsage usage,Rendering::VertexFormatFlags::MaximumNumber number>
bool Rendering::OpenGLVertexFormatArrayData<usage,number>
	::IsHas(int index) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;
	RENDERING_ASSERTION_0(0 <= index && index < System::EnumCastUnderlying(number),"索引无效！");

	return m_Data[index].IsHas();
}

template <Rendering::VertexFormatFlags::AttributeUsage usage,Rendering::VertexFormatFlags::MaximumNumber number>
System::OpenGLUInt Rendering::OpenGLVertexFormatArrayData<usage,number>
	::GetChannels(int index) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;
	RENDERING_ASSERTION_0(0 <= index && index < System::EnumCastUnderlying(number),"索引无效！");

	return m_Data[index].GetChannels();
}

template <Rendering::VertexFormatFlags::AttributeUsage usage,Rendering::VertexFormatFlags::MaximumNumber number>
System::OpenGLUInt Rendering::OpenGLVertexFormatArrayData<usage,number>
	::GetType(int index) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;
	RENDERING_ASSERTION_0(0 <= index && index < System::EnumCastUnderlying(number),"索引无效！");

	return System::OpenGLUInt(m_Data[index].GetType());
}

template <Rendering::VertexFormatFlags::AttributeUsage usage,Rendering::VertexFormatFlags::MaximumNumber number>
System::OpenGLUInt Rendering::OpenGLVertexFormatArrayData<usage,number>
	::GetOffset(int index) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;
	RENDERING_ASSERTION_0(0 <= index && index < System::EnumCastUnderlying(number),"索引无效！");

	return m_Data[index].GetOffset();
}

template <>
RENDERING_DEFAULT_DECLARE void Rendering
	::OpenGLVertexFormatArrayData<Rendering::VertexFormatFlags::AttributeUsage::TextureCoord,Rendering::VertexFormatFlags::MaximumNumber::TextureCoordinateUnits>
	::Enable(int stride);

template <>
RENDERING_DEFAULT_DECLARE void Rendering
	::OpenGLVertexFormatArrayData<Rendering::VertexFormatFlags::AttributeUsage::Color, Rendering::VertexFormatFlags::MaximumNumber::ColorUnits>
	::Enable(int stride);

template <>
RENDERING_DEFAULT_DECLARE void Rendering
	::OpenGLVertexFormatArrayData<Rendering::VertexFormatFlags::AttributeUsage::TextureCoord,Rendering::VertexFormatFlags::MaximumNumber::TextureCoordinateUnits>
	::Disable();

template <>
RENDERING_DEFAULT_DECLARE void Rendering
	::OpenGLVertexFormatArrayData<Rendering::VertexFormatFlags::AttributeUsage::Color,Rendering::VertexFormatFlags::MaximumNumber::ColorUnits>
	::Disable();

#endif // RENDERING_RENDERERS_OPENGL_VERTEX_FORMAT_ARRAY_DATA_DETAIL_H



