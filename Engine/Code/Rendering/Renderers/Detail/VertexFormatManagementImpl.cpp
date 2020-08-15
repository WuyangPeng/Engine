// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/29 10:09)

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
	if(m_Renderer.lock())
        return true;
    else
        return false;
}
#endif // OPEN_CLASS_INVARIANT

void Rendering::VertexFormatManagementImpl
	::Bind (ConstVertexFormatSmartPointer vertexFormat)
{
	RENDERING_CLASS_IS_VALID_1;

    if (m_VertexFormats.find(vertexFormat) == m_VertexFormats.end())
    {
		auto ptr = m_Renderer.lock();
		if (ptr)
		{
			PlatformVertexFormatSharedPtr platformVertexForma{ make_shared<PlatformVertexFormat>(ptr.get(),vertexFormat.get()) };
			m_VertexFormats.insert({ vertexFormat, platformVertexForma });
		}		
    }
}

void Rendering::VertexFormatManagementImpl
	::Unbind (ConstVertexFormatSmartPointer vertexFormat)
{
	RENDERING_CLASS_IS_VALID_1;

	m_VertexFormats.erase(vertexFormat);
}
 
void Rendering::VertexFormatManagementImpl
	::Enable (ConstVertexFormatSmartPointer vertexFormat)
{
	RENDERING_CLASS_IS_VALID_1;

   const auto iter = m_VertexFormats.find(vertexFormat);
    PlatformVertexFormatSharedPtr platformVertexFormat;
    if (iter != m_VertexFormats.end())
    {
        platformVertexFormat = iter->second;
    }
    else
    {
        // 延迟构造。
		auto ptr = m_Renderer.lock();
		if (ptr)
		{
			platformVertexFormat = make_shared<PlatformVertexFormat>(ptr.get(), vertexFormat.get());
			m_VertexFormats.insert({ vertexFormat, platformVertexFormat });
		}
    }

	auto ptr = m_Renderer.lock();
	if (ptr)
	{
		platformVertexFormat->Enable(ptr.get());
	}
}

void Rendering::VertexFormatManagementImpl
	::Disable (ConstVertexFormatSmartPointer vertexFormat)
{
	RENDERING_CLASS_IS_VALID_1;

	const auto iter = m_VertexFormats.find(vertexFormat);
 
    if (iter != m_VertexFormats.end())
    {
        auto platformVertexFormat = iter->second;

		auto ptr = m_Renderer.lock();
		if (ptr)
		{
			platformVertexFormat->Disable(ptr.get());
		}
    }
}

Rendering::VertexFormatManagementImpl::PlatformVertexFormatSharedPtr Rendering::VertexFormatManagementImpl
	::GetResource (ConstVertexFormatSmartPointer vertexFormat)
{
	RENDERING_CLASS_IS_VALID_1;

const	auto iter = m_VertexFormats.find(vertexFormat);
    if (iter != m_VertexFormats.end())
    {
        return iter->second;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("找不到指定的顶点格式资源！"s));
    }
}

