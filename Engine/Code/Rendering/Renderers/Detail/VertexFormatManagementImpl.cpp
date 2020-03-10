// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/29 10:09)

#include "Rendering/RenderingExport.h"

#include "VertexFormatManagementImpl.h"
#include "Rendering/Renderers/PlatformVertexFormat.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

using std::make_shared;

Rendering::VertexFormatManagementImpl
	::VertexFormatManagementImpl(RendererPtr ptr)
	: m_Renderer{ ptr }, m_VertexFormats{}
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool Rendering::VertexFormatManagementImpl
	::IsValid() const noexcept
{
	if(m_Renderer != nullptr)
        return true;
    else
        return false;
}
#endif // OPEN_CLASS_INVARIANT

void Rendering::VertexFormatManagementImpl
	::Bind (VertexFormatConstPtr vertexFormat)
{
	RENDERING_CLASS_IS_VALID_1;

    if (m_VertexFormats.find(vertexFormat) == m_VertexFormats.end())
    {
		PlatformVertexFormatSharedPtr platformVertexForma{ make_shared<PlatformVertexFormat>(m_Renderer,vertexFormat) };
		m_VertexFormats.insert({ vertexFormat, platformVertexForma });
    }
}

void Rendering::VertexFormatManagementImpl
	::Unbind (VertexFormatConstPtr vertexFormat)
{
	RENDERING_CLASS_IS_VALID_1;

	m_VertexFormats.erase(vertexFormat);
}
 
void Rendering::VertexFormatManagementImpl
	::Enable (VertexFormatConstPtr vertexFormat)
{
	RENDERING_CLASS_IS_VALID_1;

    auto iter = m_VertexFormats.find(vertexFormat);
    PlatformVertexFormatSharedPtr platformVertexFormat;
    if (iter != m_VertexFormats.end())
    {
        platformVertexFormat = iter->second;
    }
    else
    {
        // �ӳٹ��졣
		platformVertexFormat = make_shared<PlatformVertexFormat>(m_Renderer, vertexFormat);
		m_VertexFormats.insert({ vertexFormat, platformVertexFormat });
    }

    platformVertexFormat->Enable(m_Renderer);
}

void Rendering::VertexFormatManagementImpl
	::Disable (VertexFormatConstPtr vertexFormat)
{
	RENDERING_CLASS_IS_VALID_1;

	auto iter = m_VertexFormats.find(vertexFormat);
 
    if (iter != m_VertexFormats.end())
    {
        auto platformVertexFormat = iter->second;

        platformVertexFormat->Disable(m_Renderer);
    }
}

Rendering::VertexFormatManagementImpl::PlatformVertexFormatSharedPtr Rendering::VertexFormatManagementImpl
	::GetResource (VertexFormatConstPtr vertexFormat)
{
	RENDERING_CLASS_IS_VALID_1;

	auto iter = m_VertexFormats.find(vertexFormat);
    if (iter != m_VertexFormats.end())
    {
        return iter->second;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("�Ҳ���ָ���Ķ����ʽ��Դ��"));
    }
}

