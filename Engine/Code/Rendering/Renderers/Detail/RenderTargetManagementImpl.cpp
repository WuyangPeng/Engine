// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/29 10:08)

#include "Rendering/RenderingExport.h"

#include "RenderTargetManagementImpl.h"
#include "Rendering/Renderers/PlatformRenderTarget.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

using std::make_shared;

Rendering::RenderTargetManagementImpl
	::RenderTargetManagementImpl(RendererPtr ptr)
	: m_Renderer{ ptr }, m_RenderTargets{}
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool Rendering::RenderTargetManagementImpl
	::IsValid() const noexcept
{
	if(m_Renderer.lock())
        return true;
    else
        return false;
}
#endif // OPEN_CLASS_INVARIANT

void Rendering::RenderTargetManagementImpl
	::Bind (RenderTargetConstPtr renderTarget)
{
	RENDERING_CLASS_IS_VALID_1;

    if (m_RenderTargets.find(renderTarget) == m_RenderTargets.end())
    {
		PlatformRenderTargetSharedPtr platformRenderTarget{ make_shared<PlatformRenderTarget>(m_Renderer.lock().get(),renderTarget.get()) };
		m_RenderTargets.insert({ renderTarget, platformRenderTarget });
    }
}

void Rendering::RenderTargetManagementImpl
	::Unbind (RenderTargetConstPtr renderTarget)
{
	RENDERING_CLASS_IS_VALID_1;

	m_RenderTargets.erase(renderTarget);
}
 
void Rendering::RenderTargetManagementImpl
	::Enable (RenderTargetConstPtr renderTarget)
{
	RENDERING_CLASS_IS_VALID_1;

    const auto iter = m_RenderTargets.find(renderTarget);
    PlatformRenderTargetSharedPtr platformRenderTarget;
    if (iter != m_RenderTargets.end())
    {
        platformRenderTarget = iter->second;
    }
    else
    {
        platformRenderTarget = make_shared<PlatformRenderTarget>(m_Renderer.lock().get(),renderTarget.get());
		m_RenderTargets.insert({ renderTarget, platformRenderTarget });
    }

    platformRenderTarget->Enable(m_Renderer.lock().get());
}

void Rendering::RenderTargetManagementImpl
	::Disable (RenderTargetConstPtr renderTarget)
{
	RENDERING_CLASS_IS_VALID_1;

	const auto iter = m_RenderTargets.find(renderTarget);
 
    if (iter != m_RenderTargets.end())
    {
        auto platformRenderTarget = iter->second;

        platformRenderTarget->Disable(m_Renderer.lock().get());
    }
}

Rendering::ConstTexture2DSharedPtr  Rendering::RenderTargetManagementImpl
::ReadColor(int index,RenderTargetConstPtr renderTarget)
{
  	RENDERING_CLASS_IS_VALID_1;
    
	const auto iter = m_RenderTargets.find(renderTarget);
    if (iter != m_RenderTargets.end())
    {
		auto platformRenderTarget = iter->second;
        return platformRenderTarget->ReadColor(index, m_Renderer.lock().get());
    }
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("找不到指定的渲染目标！"s));
	}
}

Rendering::RenderTargetManagementImpl::PlatformRenderTargetSharedPtr Rendering::RenderTargetManagementImpl
	::GetResource (RenderTargetConstPtr renderTarget)
{
	RENDERING_CLASS_IS_VALID_1;

	const auto iter = m_RenderTargets.find(renderTarget);
    if (iter != m_RenderTargets.end())
    {
        return iter->second;
    }
    else
    {
		THROW_EXCEPTION(SYSTEM_TEXT("找不到指定的渲染目标！"s));
    }
}