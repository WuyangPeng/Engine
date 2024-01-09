/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/26 11:22)

#include "Rendering/RenderingExport.h"

#include "GlobalState.h"
#include "Detail/GlobalStateFactory.h"
#include "Detail/GlobalStateImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, GlobalState)

Rendering::GlobalState::GlobalState(RendererTypes rendererTypes, const std::string& blendStateName, const std::string& depthStencilStateName, const std::string& rasterizerStateName, const RendererObjectBridgeSharedPtr& rendererObjectBridge)
    : impl{ CoreTools::ImplCreateUseFactory::Default, rendererTypes, blendStateName, depthStencilStateName, rasterizerStateName, rendererObjectBridge }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, GlobalState)

void Rendering::GlobalState::CreateDefaultGlobalState()
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->CreateDefaultGlobalState();
}

void Rendering::GlobalState::DestroyDefaultGlobalState()
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->DestroyDefaultGlobalState();
}

void Rendering::GlobalState::SetActiveBlendState(const BlendStateSharedPtr& state)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetActiveBlendState(state);
}

void Rendering::GlobalState::SetActiveDepthStencilState(const DepthStencilStateSharedPtr& state)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetActiveDepthStencilState(state);
}

void Rendering::GlobalState::SetActiveRasterizerState(const RasterizerStateSharedPtr& state)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetActiveRasterizerState(state);
}

Rendering::GlobalState::BlendStateSharedPtr Rendering::GlobalState::GetActiveBlendState() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->GetActiveBlendState();
}

Rendering::GlobalState::DepthStencilStateSharedPtr Rendering::GlobalState::GetActiveDepthStencilState() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->GetActiveDepthStencilState();
}

Rendering::GlobalState::RasterizerStateSharedPtr Rendering::GlobalState::GetActiveRasterizerState() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->GetActiveRasterizerState();
}

Rendering::GlobalState::BlendStateSharedPtr Rendering::GlobalState::GetDefaultBlendState() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->GetDefaultBlendState();
}

Rendering::GlobalState::DepthStencilStateSharedPtr Rendering::GlobalState::GetDefaultDepthStencilState() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->GetDefaultDepthStencilState();
}

Rendering::GlobalState::RasterizerStateSharedPtr Rendering::GlobalState::GetDefaultRasterizerState() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->GetDefaultRasterizerState();
}

void Rendering::GlobalState::SetDefaultBlendState()
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetDefaultBlendState();
}

void Rendering::GlobalState::SetDefaultDepthStencilState()
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetDefaultDepthStencilState();
}

void Rendering::GlobalState::SetDefaultRasterizerState()
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetDefaultRasterizerState();
}
