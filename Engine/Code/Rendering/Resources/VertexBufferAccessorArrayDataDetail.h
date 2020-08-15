// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/19 13:47)

#ifndef RENDERING_RESOURCES_VERTEX_BUFFER_ACCESSOR_ARRAY_DATA_DETAIL_H
#define RENDERING_RESOURCES_VERTEX_BUFFER_ACCESSOR_ARRAY_DATA_DETAIL_H

#include "Rendering/RenderingExport.h" 

#include "VertexBufferAccessorArrayData.h"
#include "VertexFormat.h"
#include "VertexBuffer.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "System/Helper/PragmaWarning.h" 
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26482)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(6385)
template <Rendering::VertexFormatFlags::AttributeUsage usage,Rendering::VertexFormatFlags::MaximumNumber number>
Rendering::VertexBufferAccessorArrayData<usage, number>
	::VertexBufferAccessorArrayData()	 
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}


template <Rendering::VertexFormatFlags::AttributeUsage usage,Rendering::VertexFormatFlags::MaximumNumber number>
Rendering::VertexBufferAccessorArrayData<usage, number>
	::VertexBufferAccessorArrayData(const ConstVertexFormatSmartPointer& vertexformat, const ConstVertexBufferSmartPointer& vertexbuffer)
{
	Init(vertexformat, vertexbuffer);

	RENDERING_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <Rendering::VertexFormatFlags::AttributeUsage usage,Rendering::VertexFormatFlags::MaximumNumber number>
bool Rendering::VertexBufferAccessorArrayData<usage,number>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIAN

template <Rendering::VertexFormatFlags::AttributeUsage usage,Rendering::VertexFormatFlags::MaximumNumber number>
void Rendering::VertexBufferAccessorArrayData<usage,number>
	::Init( const ConstVertexFormatSmartPointer& vertexformat,const ConstVertexBufferSmartPointer& vertexbuffer )
{
	RENDERING_CLASS_IS_VALID_9;

	for (auto unit = 0; unit < System::EnumCastUnderlying(number); ++unit)
	{
		m_Data[unit].Init(vertexformat, vertexbuffer, unit);
	}
}
 
template <Rendering::VertexFormatFlags::AttributeUsage usage,Rendering::VertexFormatFlags::MaximumNumber number>
const char* Rendering::VertexBufferAccessorArrayData<usage, number>
	::GetData(int stride,int unit,  int index) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;
	RENDERING_ASSERTION_0(0 <= unit && unit < System::EnumCastUnderlying(number), "À˜“˝¥ÌŒÛ°£\n");

	return m_Data[unit].GetData(stride, index);
}

template <Rendering::VertexFormatFlags::AttributeUsage usage,Rendering::VertexFormatFlags::MaximumNumber number>
bool Rendering::VertexBufferAccessorArrayData<usage,number>
	::HasData(int unit) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;
	RENDERING_ASSERTION_0(0 <= unit && unit < System::EnumCastUnderlying(number), "À˜“˝¥ÌŒÛ°£\n");

	return m_Data[unit].HasData();
}

template <Rendering::VertexFormatFlags::AttributeUsage usage,Rendering::VertexFormatFlags::MaximumNumber number>
int Rendering::VertexBufferAccessorArrayData<usage,number>
	::GetDataChannels(int unit) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;
	RENDERING_ASSERTION_0(0 <= unit && unit < System::EnumCastUnderlying(number), "À˜“˝¥ÌŒÛ°£\n");

	return m_Data[unit].GetDataChannels();
}

template <Rendering::VertexFormatFlags::AttributeUsage usage,Rendering::VertexFormatFlags::MaximumNumber number>
const float* Rendering::VertexBufferAccessorArrayData<usage, number>
	::GetDataTuple(int stride, int unit, int index) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;
	RENDERING_ASSERTION_0(0 <= unit && unit < System::EnumCastUnderlying(number), "À˜“˝¥ÌŒÛ°£\n");

	return m_Data[unit].GetDataTuple(stride,index);
} 
#include STSTEM_WARNING_POP
#endif // RENDERING_RESOURCES_VERTEX_BUFFER_ACCESSOR_ARRAY_DATA_DETAIL_H



