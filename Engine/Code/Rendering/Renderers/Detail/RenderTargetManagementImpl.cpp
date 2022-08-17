///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/21 14:55)

#include "Rendering/RenderingExport.h"

#include "RenderTargetManagementImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Rendering/Renderers/PlatformRenderTarget.h"

using std::make_shared;

Rendering::RenderTargetManagementImpl::RenderTargetManagementImpl(const RendererSharedPtr& renderer)
    : renderer{ renderer }, renderTargets{}
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool Rendering::RenderTargetManagementImpl::IsValid() const noexcept
{
    if (renderer.lock())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

void Rendering::RenderTargetManagementImpl::Bind(const ConstDrawTargetSharedPtr& renderTarget)
{
    RENDERING_CLASS_IS_VALID_1;

    if (renderTargets.find(renderTarget) == renderTargets.end())
    {
        auto platformRenderTarget = make_shared<PlatformRenderTarget>(renderer.lock().get(), renderTarget.get());
        renderTargets.emplace(renderTarget, platformRenderTarget);
    }
}

void Rendering::RenderTargetManagementImpl::Unbind(const ConstDrawTargetSharedPtr& renderTarget)
{
    RENDERING_CLASS_IS_VALID_1;

    renderTargets.erase(renderTarget);
}

void Rendering::RenderTargetManagementImpl::Enable(const ConstDrawTargetSharedPtr& renderTarget)
{
    RENDERING_CLASS_IS_VALID_1;

    const auto iter = renderTargets.find(renderTarget);
    PlatformRenderTargetSharedPtr platformRenderTarget{};
    if (iter != renderTargets.end())
    {
        platformRenderTarget = iter->second;
    }
    else
    {
        platformRenderTarget = make_shared<PlatformRenderTarget>(renderer.lock().get(), renderTarget.get());
        renderTargets.emplace(renderTarget, platformRenderTarget);
    }

    platformRenderTarget->Enable(renderer.lock().get());
}

void Rendering::RenderTargetManagementImpl::Disable(const ConstDrawTargetSharedPtr& renderTarget)
{
    RENDERING_CLASS_IS_VALID_1;

    const auto iter = renderTargets.find(renderTarget);

    if (iter != renderTargets.end())
    {
        auto platformRenderTarget = iter->second;

        platformRenderTarget->Disable(renderer.lock().get());
    }
}

Rendering::ConstTexture2DSharedPtr Rendering::RenderTargetManagementImpl::ReadColor(int index, const ConstDrawTargetSharedPtr& renderTarget)
{
    RENDERING_CLASS_IS_VALID_1;

    const auto iter = renderTargets.find(renderTarget);
    if (iter != renderTargets.end())
    {
        auto platformRenderTarget = iter->second;
        return platformRenderTarget->ReadColor(index, renderer.lock().get());
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("找不到指定的渲染目标！"s));
    }
}

Rendering::RenderTargetManagementImpl::PlatformRenderTargetSharedPtr Rendering::RenderTargetManagementImpl::GetResource(const ConstDrawTargetSharedPtr& renderTarget)
{
    RENDERING_CLASS_IS_VALID_1;

    const auto iter = renderTargets.find(renderTarget);
    if (iter != renderTargets.end())
    {
        return iter->second;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("找不到指定的渲染目标！"s));
    }
}