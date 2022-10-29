///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.3 (2022/10/06 21:36)

#include "Rendering/RenderingExport.h"

#include "GlobalStateImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/Base/RendererObjectBridge.h"
#include "Rendering/State/BlendState.h"
#include "Rendering/State/DepthStencilState.h"
#include "Rendering/State/RasterizerState.h"

Rendering::GlobalStateImpl::GlobalStateImpl(const std::string& blendStateName, const std::string& depthStencilStateName, const std::string& rasterizerStateName, const RendererObjectBridgeSharedPtr& rendererObjectBridge)
    : defaultBlendState{ BlendState::Create(blendStateName) },
      activeBlendState{ defaultBlendState },
      defaultDepthStencilState{ DepthStencilState::Create(depthStencilStateName) },
      activeDepthStencilState{ defaultDepthStencilState },
      defaultRasterizerState{ RasterizerState::Create(rasterizerStateName) },
      activeRasterizerState{ defaultRasterizerState },
      rendererObjectBridge{ rendererObjectBridge }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool Rendering::GlobalStateImpl::IsValid() const noexcept
{
    if (defaultBlendState != nullptr &&
        activeBlendState != nullptr &&
        defaultDepthStencilState != nullptr &&
        activeDepthStencilState != nullptr &&
        defaultRasterizerState != nullptr &&
        activeRasterizerState != nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

#endif  // OPEN_CLASS_INVARIANT

void Rendering::GlobalStateImpl::CreateDefaultGlobalState()
{
    RENDERING_CLASS_IS_VALID_1;

    SetActiveBlendState(defaultBlendState);
    SetActiveDepthStencilState(defaultDepthStencilState);
    SetActiveRasterizerState(defaultRasterizerState);
}

void Rendering::GlobalStateImpl::DestroyDefaultGlobalState()
{
    RENDERING_CLASS_IS_VALID_1;

    UnbindRendererObject(defaultBlendState);
    UnbindRendererObject(defaultDepthStencilState);
    UnbindRendererObject(defaultRasterizerState);
}

void Rendering::GlobalStateImpl::SetActiveBlendState(const BlendStateSharedPtr& state)
{
    RENDERING_CLASS_IS_VALID_1;

    if (!state)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("state指针为空。"s));
    }

    activeBlendState = state;
}

void Rendering::GlobalStateImpl::SetActiveDepthStencilState(const DepthStencilStateSharedPtr& state)
{
    RENDERING_CLASS_IS_VALID_1;

    if (!state)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("state指针为空。"s));
    }

    activeDepthStencilState = state;
}

void Rendering::GlobalStateImpl::SetActiveRasterizerState(const RasterizerStateSharedPtr& state)
{
    RENDERING_CLASS_IS_VALID_1;

    if (!state)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("state指针为空。"s));
    }

    activeRasterizerState = state;
}

Rendering::GlobalStateImpl::BlendStateSharedPtr Rendering::GlobalStateImpl::GetActiveBlendState() noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return activeBlendState;
}

Rendering::GlobalStateImpl::DepthStencilStateSharedPtr Rendering::GlobalStateImpl::GetActiveDepthStencilState() noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return activeDepthStencilState;
}

Rendering::GlobalStateImpl::RasterizerStateSharedPtr Rendering::GlobalStateImpl::GetActiveRasterizerState() noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return activeRasterizerState;
}

Rendering::GlobalStateImpl::BlendStateSharedPtr Rendering::GlobalStateImpl::GetDefaultBlendState() noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return defaultBlendState;
}

Rendering::GlobalStateImpl::DepthStencilStateSharedPtr Rendering::GlobalStateImpl::GetDefaultDepthStencilState() noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return defaultDepthStencilState;
}

Rendering::GlobalStateImpl::RasterizerStateSharedPtr Rendering::GlobalStateImpl::GetDefaultRasterizerState() noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return defaultRasterizerState;
}

Rendering::GlobalStateImpl::RendererObjectSharedPtr Rendering::GlobalStateImpl::BindRendererObject(RendererTypes rendererTypes, const GraphicsObjectSharedPtr& graphicsObject)
{
    RENDERING_CLASS_IS_VALID_9;

    auto sharedPtr = rendererObjectBridge.lock();
    if (!sharedPtr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("rendererObjectBridge已释放。"s));
    }

    return sharedPtr->BindRendererObject(rendererTypes, graphicsObject);
}

void Rendering::GlobalStateImpl::UnbindRendererObject(const GraphicsObjectSharedPtr& graphicsObject)
{
    RENDERING_CLASS_IS_VALID_9;

    auto sharedPtr = rendererObjectBridge.lock();
    if (!sharedPtr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("rendererObjectBridge已释放。"s));
    }

    return sharedPtr->UnbindRendererObject(graphicsObject);
}

Rendering::GlobalStateImpl::RendererObjectSharedPtr Rendering::GlobalStateImpl::GetRendererObject(const GraphicsObjectSharedPtr& graphicsObject)
{
    RENDERING_CLASS_IS_VALID_9;

    auto sharedPtr = rendererObjectBridge.lock();
    if (!sharedPtr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("rendererObjectBridge已释放。"s));
    }

    return sharedPtr->GetRendererObject(graphicsObject);
}

Rendering::GlobalStateImpl::ConstRendererObjectSharedPtr Rendering::GlobalStateImpl::GetRendererObject(const GraphicsObjectSharedPtr& graphicsObject) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto sharedPtr = rendererObjectBridge.lock();
    if (!sharedPtr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("rendererObjectBridge已释放。"s));
    }

    return sharedPtr->GetRendererObject(graphicsObject);
}
