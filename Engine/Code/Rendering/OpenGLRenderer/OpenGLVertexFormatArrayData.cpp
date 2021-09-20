// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/29 11:33)

#include "Rendering/RenderingExport.h" 

#include "OpenGLVertexFormatArrayDataDetail.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
 #include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26482)
#include SYSTEM_WARNING_DISABLE(26493)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26490)
#include SYSTEM_WARNING_DISABLE(26481)
template <>
void Rendering
	::OpenGLVertexFormatArrayData<Rendering::VertexFormatFlags::AttributeUsage::TextureCoord,Rendering::VertexFormatFlags::MaximumNumber::TextureCoordinateUnits>
	::Enable(int stride) noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	for (int unit = 0; unit < System::EnumCastUnderlying(Rendering::VertexFormatFlags::MaximumNumber::TextureCoordinateUnits);++unit)
	{
		if (m_Data[unit].IsHas())
            {
                    stride;
			//System::GLEnableTextureArray(unit,m_Data[unit].GetChannels(),m_Data[unit].GetType(), stride,reinterpret_cast<char*>(0) + m_Data[unit].GetOffset());	
		}
	}	
}

void Rendering
	::OpenGLVertexFormatArrayData<Rendering::VertexFormatFlags::AttributeUsage::Color,Rendering::VertexFormatFlags::MaximumNumber::ColorUnits>
	::Enable(int stride) noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_9;
    stride;
	if (m_Data[0].IsHas())
	{
		//System::GLEnableColorArray(m_Data[0].GetChannels(),m_Data[0].GetType(), stride,reinterpret_cast<char*>(0) + m_Data[0].GetOffset());
	}

	if (m_Data[1].IsHas())
	{
		//System::GlEnableSecondaryColorArray(m_Data[1].GetChannels(),m_Data[1].GetType(), stride,reinterpret_cast<char*>(0) + m_Data[1].GetOffset());
	}
}

template <>
void Rendering
	::OpenGLVertexFormatArrayData<Rendering::VertexFormatFlags::AttributeUsage::TextureCoord,Rendering::VertexFormatFlags::MaximumNumber::TextureCoordinateUnits>
	::Disable() noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	for (int unit = 0; unit < System::EnumCastUnderlying(Rendering::VertexFormatFlags::MaximumNumber::TextureCoordinateUnits);++unit)
	{
		if (m_Data[unit].IsHas())
		{
			//System::GLDisableTextureArray(unit);	
		}
	}	
}

void Rendering
	::OpenGLVertexFormatArrayData<Rendering::VertexFormatFlags::AttributeUsage::Color,Rendering::VertexFormatFlags::MaximumNumber::ColorUnits>
	::Disable() noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_9;
	static_assert(System::EnumCastUnderlying(Rendering::VertexFormatFlags::MaximumNumber::ColorUnits) <= 2,"");

	if (m_Data[0].IsHas())
	{
		//System::GLDisableColorArray();
	}

	if (m_Data[1].IsHas())
	{
		//System::GlDisableSecondaryColorArray();
	}
}
#include STSTEM_WARNING_POP