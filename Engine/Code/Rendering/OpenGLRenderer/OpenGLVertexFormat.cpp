// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/29 11:32)

#include "Rendering/RenderingExport.h" 

#include "OpenGLVertexFormat.h"
#include "OpenGLMapping.h"

#include "OpenGLVertexFormatDataDetail.h"
#include "OpenGLVertexFormatArrayDataDetail.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "System/Helper/PragmaWarning.h" 
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26429)
 
Rendering::OpenGLVertexFormat ::OpenGLVertexFormat([[maybe_unused]] Renderer* renderer, const VertexFormat* vertexFormat)
    : ParentType{}, m_Stride(vertexFormat->GetStride()), m_Position(), m_Normal(), m_Tangent(), m_Binormal(),
	 m_TexCoord(),m_Color(),m_BlendIndices(),m_BlendWeight(),m_FogCoord(),m_PSize()
{
    Init(vertexFormat);

 

	RENDERING_SELF_CLASS_IS_VALID_1;
}

// private
void Rendering::OpenGLVertexFormat
    ::Init(const VertexFormat* vertexFormat)
{
	m_Position.Init(vertexFormat);
	m_Normal.Init(vertexFormat);
	m_Tangent.Init(vertexFormat);
	m_Binormal.Init(vertexFormat);

	m_TexCoord.Init(vertexFormat);
	m_Color.Init(vertexFormat);

	m_BlendIndices.Init(vertexFormat);
	m_BlendWeight.Init(vertexFormat);
	m_FogCoord.Init(vertexFormat);
	m_PSize.Init(vertexFormat);
}
 

#ifdef OPEN_CLASS_INVARIANT
bool Rendering::OpenGLVertexFormat
	::IsValid() const noexcept
{
	if(ParentType::IsValid() && 0 < m_Stride)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

void Rendering::OpenGLVertexFormat ::Enable([[maybe_unused]] Renderer* renderer) noexcept
{	
	// 数据指针允许使用顶点缓冲
	RENDERING_CLASS_IS_VALID_1;

	m_Position.Enable(m_Stride);
	m_Normal.Enable(m_Stride);
	m_Tangent.Enable(m_Stride);
	m_Binormal.Enable(m_Stride);

	m_TexCoord.Enable(m_Stride);
	m_Color.Enable(m_Stride);

	m_BlendIndices.Enable(m_Stride);
	m_BlendWeight.Enable(m_Stride);
	m_FogCoord.Enable(m_Stride);
	m_PSize.Enable(m_Stride);

 
}

void Rendering::OpenGLVertexFormat ::Disable([[maybe_unused]] Renderer* renderer) noexcept
{
	RENDERING_CLASS_IS_VALID_1;

	m_Position.Disable();
	m_Normal.Disable();
	m_Tangent.Disable();
	m_Binormal.Disable();

	m_TexCoord.Disable();
	m_Color.Disable();

	m_BlendIndices.Disable();
	m_BlendWeight.Disable();
	m_FogCoord.Disable();
	m_PSize.Disable();

 	
}
#include STSTEM_WARNING_POP
