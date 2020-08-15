// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/29 11:33)

#include "Rendering/RenderingExport.h" 

#include "OpenGLVertexFormatDataDetail.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26490)
template <>
void Rendering
	::OpenGLVertexFormatData<Rendering::VertexFormatFlags::AttributeUsage::Position>
	::Enable(int stride) noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	if (IsHas())
	{
		System::GlEnablePositionArray(m_Channels, m_Type, stride,reinterpret_cast<char*>(0) + m_Offset);
	}
}

template <>
void Rendering
	::OpenGLVertexFormatData<Rendering::VertexFormatFlags::AttributeUsage::Normal>
	::Enable(int stride) noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	if (IsHas())
	{
		System::GlEnableNormalArray(m_Channels, m_Type, stride,reinterpret_cast<char*>(0) + m_Offset);
	}
}

template <>
void Rendering
	::OpenGLVertexFormatData<Rendering::VertexFormatFlags::AttributeUsage::Tangent>
	::Enable(int stride) noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	if (IsHas())
	{
		System::GlEnableTangentArray(m_Channels, m_Type, stride,reinterpret_cast<char*>(0) + m_Offset);
	}
}

template <>
void Rendering
	::OpenGLVertexFormatData<Rendering::VertexFormatFlags::AttributeUsage::Binormal>
	::Enable(int stride) noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	if (IsHas())
	{
		System::GlEnableBinormalArray(m_Channels, m_Type, stride,reinterpret_cast<char*>(0) + m_Offset);
	}
}

template <>
void Rendering
	::OpenGLVertexFormatData<Rendering::VertexFormatFlags::AttributeUsage::BlendIndices>
	::Enable(int stride) noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	if (IsHas())
	{
		System::GlEnableBlendIndicesArray(m_Channels, m_Type, stride,reinterpret_cast<char*>(0) + m_Offset);
	}
}

template <>
void Rendering
	::OpenGLVertexFormatData<Rendering::VertexFormatFlags::AttributeUsage::BlendWeight>
	::Enable(int stride) noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	if (IsHas())
	{
		System::GlEnableBlendWeightArray(m_Channels, m_Type, stride,reinterpret_cast<char*>(0) + m_Offset);
	}
}

template <>
void Rendering
	::OpenGLVertexFormatData<Rendering::VertexFormatFlags::AttributeUsage::FogCoord>
	::Enable(int stride) noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	if (IsHas())
	{
		System::GlEnableFogCoordArray(m_Channels, m_Type, stride,reinterpret_cast<char*>(0) + m_Offset);
	}
}

template <>
void Rendering
	::OpenGLVertexFormatData<Rendering::VertexFormatFlags::AttributeUsage::Psize>
	::Enable(int stride) noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	if (IsHas())
	{
		System::GlEnablePSizeArray(m_Channels, m_Type, stride, reinterpret_cast<char*>(0) + m_Offset);
	}
}

template <>
void Rendering
	::OpenGLVertexFormatData<Rendering::VertexFormatFlags::AttributeUsage::Position>
	::Disable() noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	if (IsHas())
	{
		System::GlDisablePositionArray();
	}
}

template <>
void Rendering
	::OpenGLVertexFormatData<Rendering::VertexFormatFlags::AttributeUsage::Normal>
	::Disable() noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	if (IsHas())
	{
		System::GlDisableNormalArray();
	}
}

template <>
void Rendering
	::OpenGLVertexFormatData<Rendering::VertexFormatFlags::AttributeUsage::Tangent>
	::Disable() noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	if (IsHas())
	{
		System::GlDisableTangentArray();
	}
}

template <>
void Rendering
	::OpenGLVertexFormatData<Rendering::VertexFormatFlags::AttributeUsage::Binormal>
	::Disable() noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	if (IsHas())
	{
		System::GlDisableBinormalArray();
	}
}

template <>
void Rendering
	::OpenGLVertexFormatData<Rendering::VertexFormatFlags::AttributeUsage::BlendIndices>
	::Disable() noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	if (IsHas())
	{
		System::GlDisableBlendIndicesArray();
	}
}

template <>
void Rendering
	::OpenGLVertexFormatData<Rendering::VertexFormatFlags::AttributeUsage::BlendWeight>
	::Disable() noexcept
{ 
	RENDERING_CLASS_IS_VALID_CONST_9;

	if (IsHas())
	{
		System::GlDisableBlendWeightArray();
	}
}

template <>
void Rendering
	::OpenGLVertexFormatData<Rendering::VertexFormatFlags::AttributeUsage::FogCoord>
	::Disable() noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	if (IsHas())
	{
		System::GlDisableFogCoordArray();
	}
}

template <>
void Rendering
	::OpenGLVertexFormatData<Rendering::VertexFormatFlags::AttributeUsage::Psize>
	::Disable() noexcept
{ 
	RENDERING_CLASS_IS_VALID_CONST_9;

	if (IsHas())
	{
		System::GlDisablePSizeArray();
	}
}
#include STSTEM_WARNING_POP